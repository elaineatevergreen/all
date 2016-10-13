;(function ( $, window, document, undefined ) {
    var editor = undefined;
    var settings = undefined;
    var saves = undefined;
    var didLaunch = false;

    var default_settings = {
        id: Math.round(Math.random() * 10000) + 1,
        editor: {
            previewMode: 0,
            selected_hotspot: -1,
            tool: 'spot'
        },
        general: {
            name: 'Untitled',
            width: 1050,
            height: 700,
            responsive: 1,
            sticky_tooltips: 0,
            constrain_tooltips: 1,
            image_url: 'img/2.jpg',
            tooltip_animation: 'grow',
            pageload_animation: 'none'
        }, spots: [
            // type (spot, rect, ellipse, poly), x, y, width, height, points(arr)
            // default styles, mouseover styles
        ]
    };
    var default_spot_settings = {
        id: 'spot-0',
        type: 'spot',
        x: 0,
        y: 0,
        width: 44,
        height: 44,
        actions: {
            mouseover: 'show-tooltip',
            click: 'no-action',
            link: '#',
            open_link_in_new_window: 1
        },
        default_style: {
            opacity: 1,
            border_radius: 50,
            background_color: '#000000',
            background_opacity: 0.4,
            border_width: 0,
            border_style: 'solid',
            border_color: '#ffffff',
            border_opacity: 1,

            // poly-specific
            fill: '#000000',
            fill_opacity: 0.4,
            stroke_color: '#ffffff',
            stroke_opacity: 0.75,
            stroke_width: 0,
            stroke_dasharray: '10 10',
            stroke_linecap: 'round',

            // spot-specific
            use_icon: 0,
            icon_type: 'library', // or 'custom'
            icon_svg_path: '',
            icon_svg_viewbox: '',
            icon_fill: '#ffffff',
            icon_url: '',
            icon_is_pin: 0,
            icon_shadow: 0
        },
        mouseover_style: {
            opacity: 1,
            border_radius: 50,
            background_color: '#ffffff',
            background_opacity: 0.4,
            border_width: 0,
            border_style: 'solid',
            border_color: '#ffffff',
            border_opacity: 1,

            // poly-specific
            fill: '#ffffff',
            fill_opacity: 0.4,
            stroke_color: '#ffffff',
            stroke_opacity: 0.75,
            stroke_width: 0,
            stroke_dasharray: '10 10',
            stroke_linecap: 'round'
        },
        tooltip_style: {
            border_radius: 5,
            padding: 20,
            background_color: '#000000',
            background_opacity: 0.9,
            position: 'top',
            width: 300,
            height: 200,
            auto_width: 0,
            auto_height: 1
        },
        text_style: {
            title_color: '#ffffff',
            title_font_size: 18,
            title_font_family: 'sans-serif',
            title_font_weight: 700,
            title_line_height: 24,
            text_color: '#aaaaaa',
            text_font_size: 12,
            text_font_family: 'serif',
            text_font_weight: 300,
            text_line_height: 16
        },
        tooltip_content: {
            title: 'Lorem Ipsum',
            text: 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.'
        },
        points: []
    }

    $.image_map_pro_default_spot_settings = function() {
        return default_spot_settings;
    }

    $.image_map_pro_init_editor = function(initSettings) {
        editor = new Editor();
        editor.init(initSettings);
    }

    $.image_map_pro_editor_current_settings = function() {
        return settings;
    }

    $.image_map_pro_user_uploaded_image = function() {
        // tour
        editor.tourSteps['upload image']();
    }

    function Editor() {
        this.generalSettingsForm = new Form(this);
        this.hotspotSettingsForm = new Form(this);

        // undo/redo
        this.actionStack = new Array();
        this.actionIndex = 0;

        // canvas
        this.canvasImage = new Image();
        this.canvasWidth = 0;
        this.canvasHeight = 0;
        this.canvas = undefined;

        this.ix = 0; // in pixels, canvas space
        this.iy = 0;
        this.x = 0;
        this.y = 0;
        this.dx = 0; // in percentage, canvas space
        this.dy = 0;

        this.drawRectWidth = 0;
        this.drawRectHeight = 0;

        this.transformX = 0;
        this.transformY = 0;
        this.transformWidth = 0;
        this.transformHeight = 0;

        this.eventSpotId = undefined;
        this.redrawEl = undefined;
        this.redrawSvgEl = undefined;
        this.redrawPolygonEl = undefined;

        this.tempControlPoint = undefined;
        this.tempControlPointLine = undefined;
        this.tempControlPointIndex = undefined;

        this.controlPointInsertionPointX = 0;
        this.controlPointInsertionPointY = 0;

        this.translatedPointIndex = 0;
        this.translatedPoint = undefined;

        this.translatedPointX = 0;
        this.translatedPointY = 0;

        this.polyPoints = new Array();

        // flags
        this.startedSelecting = false;
        this.startedMoving = false;
        this.startedTransforming = false;
        this.transformDirection = 0;

        this.startedDrawingSpot = false;

        this.startedDrawingRect = false;
        this.createdDrawingRect = false;

        this.startedDrawingOval = false;
        this.createdDrawingOval = false;

        this.startedDrawingPoly = false;
        this.drawingPoly = false;
        this.finishedDrawingPoly = false;
        this.mouseDownWhileDrawingPoly = false;

        this.startedTranslatingControlPoint = false;
        this.translatingControlPoint = false;

        this.didDeleteControlPoint = false;

        this.shouldDeselectSpot = false;

        // vars
        this.selectedSpot = undefined;
        this.eventSpot = undefined;

        // tour
        this.tour = undefined;
        this.tourSteps = {};
    }
    Editor.prototype.init = function(initSettings) {
        // Hide the cancel buttons for the create/load modals
        // on first load
        if (!didLaunch) {
            $('[data-toggle="tooltip"]').tooltip();
            $('#button-new-widget-cancel').hide();
            $('#button-modal-saves-cancel').hide();
        }

        var self = this;

        // events & other
        self.events();
        self.loadIconLibrary();
        self.initSettingsTabs();

        // Init popovers
        $('[data-toggle="popover"]').popover();
        // If settings were passed with initialization, use them and don't look for saves
        if (initSettings) {
            settings = initSettings;

            // tour
            self.initTour();

            // launch
            self.launch();
        } else {
            // load saves
            $.editor_storage_get_saves(function(res) {
                saves = res;

                $('#saved-widgets-container').html('');
                $('#saved-widgets-controls-container').html('');

                var shouldLaunch = false;
                if (saves.length > 0) {
                    // print saves
                    for (var i=0; i<saves.length; i++) {
                        $('#saved-widgets-container').append('<a href="#" class="list-group-item widget-load" data-index="'+ i +'">'+ saves[i].general.name +'</div>');
                        $('#saved-widgets-controls-container').append('<div class="saved-widgets-controls"><button class="pull-right btn btn-default widget-delete-button" data-index="'+ i +'">Delete</button></div>');
                    }

                    // does last save exist?
                    $.editor_storage_get_last_save(function(lastSave) {
                        if (lastSave) {
                            // tour
                            self.initTour();

                            settings = lastSave;
                            self.launch();
                        } else {
                            // display saves modal
                            $('#modal-saves').modal();
                        }
                    });
                } else {
                    // If the editor didn't launch yet, display create instance modal
                    if (!didLaunch) {
                        $('#modal-new-widget').modal();

                        // tour
                        self.initTour();

                        // reset tour
                        self.tour.resumeFromStep('pick name and create');
                    }
                }
            });
        }
    };
    Editor.prototype.initTour = function() {
        var self = this;

        // tour
        self.tour = new WebcraftGuidedTour($('#hm-editor-wrap'));

        self.tourSteps['pick name and create'] = self.tour.addStep('pick name and create', 'bottom', 'Create Your First Image Map', '<p>Hey! This is a quick guided tour to get you familiar with this Editor.</p><p>Let\'s start by creating your first image map! Enter a name a click <strong>Create</strong>.</p>', function() {
            var x = $('#button-new-widget-create').offset().left + $('#button-new-widget-create').outerWidth()/2;
            var y = $('#button-new-widget-create').offset().top + $('#button-new-widget-create').outerHeight() + 30;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        if ($.image_map_pro_add_tour_step_after) {
            $.image_map_pro_add_tour_step_after('pick name and create', self);
        }
        self.tourSteps['choose poly tool'] = self.tour.addStep('choose poly tool', 'right', 'Create a Poly', '<p>This is the <strong>Toolbar</strong>, where you choose what kind of shape to create.</p><p>Let\'s start by choosing the <strong>Poly</strong> tool.</p>', function() {
            var x = $('#hm-toolbar-button-poly').offset().left + $('#hm-toolbar-button-poly').outerWidth() + 30;
            var y = $('#hm-toolbar-button-poly').offset().top + $('#hm-toolbar-button-poly').outerHeight()/2;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['draw a poly'] = self.tour.addStep('draw a poly', 'top', 'Create a Poly', '<p>Now, let\'s draw a polygon!</p> <p>The image is your <strong>Canvas</strong>. To draw a polygon, <strong>Left-Click</strong> anywhere in the canvas to place a point. </p><p><strong>You will be able to move the points after you finish creating the poly.</strong></p><p><strong>Click the first point</strong> to close the shape!</p>', function() {
            var x = $('#hm-editor-canvas-background').offset().left + $('#hm-editor-canvas-background').outerWidth()/2;
            var y = $('#hm-editor-canvas-background').offset().top + 200;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['choose spot tool'] = self.tour.addStep('choose spot tool', 'right', 'Create a Spot', '<p>Now choose the <strong>Spot</strong> tool, to create a spot shape.</p>', function() {
            var x = $('#hm-toolbar-button-spot').offset().left + $('#hm-toolbar-button-spot').outerWidth() + 30;
            var y = $('#hm-toolbar-button-spot').offset().top + $('#hm-toolbar-button-spot').outerHeight()/2;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['draw a spot'] = self.tour.addStep('draw a spot', 'top', 'Create a Spot', '<p><strong>Left-Click</strong> anywhere in the canvas to create a spot!', function() {
            var x = $('#hm-editor-canvas-background').offset().left + $('#hm-editor-canvas-background').outerWidth()/2;
            var y = $('#hm-editor-canvas-background').offset().top + 200;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['go to preview mode'] = self.tour.addStep('go to preview mode', 'bottom', 'Preview Mode', '<p>Now let\'s go to Preview Mode to see how the image map will look like!</p><p>Click the <strong>Preview Mode</strong> button.', function() {
            var x = $('#button-preview-mode').offset().left + $('#button-preview-mode').outerWidth()/2 - 50;
            var y = $('#button-preview-mode').offset().top + $('#button-preview-mode').outerHeight() + 10;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['set icon for the spot'] = self.tour.addStep('set icon for the spot', 'left', 'Set an Icon', '<p>The unique feature of the Spot shapes is that they can be icons and they will always preserve their size and center position.</p><p>Click the <strong>Use Icon</strong> checkbox, then the <strong>Choose Icon</strong> button and select an icon.</p>', function() {
            var x = $('#checkbox-spot-default-use-icon').offset().left - 50;
            var y = $('#checkbox-spot-default-use-icon').offset().top + $('#checkbox-spot-default-use-icon').outerHeight()/2;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            if (x <= 0 || y <= 0) {
                x = $('#hm-editor-sidebar-right-wrap').offset().left - 20;
                y = 640;
            }

            return { x: x, y: y };
        });
        self.tourSteps['select the poly'] = self.tour.addStep('select the poly', 'left', 'Select the Poly', '<p>Now let\'s set some styles for the Poly shape!</p><p>Click the <strong>poly-1</strong> shape from the list to select it.</p>', function() {
            var x = $('#hotspot-list-group').offset().left - 20;
            var y = $('#hotspot-list-group').offset().top + $('#hotspot-list-group').outerHeight()/2;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['set styles for the poly'] = self.tour.addStep('set styles for the poly', 'left', 'Style the Poly shape', '<p>There are lots of settings to customize the look of the shapes! <p>You can set different styles for <strong>Default</strong> and <strong>Mouseover</strong> state of the shape. Try changing some settings!</p><p>Press <strong>Next</strong> to continue.</p>', function() {
            var x = $('#hm-tab-default-style').offset().left - 50;
            var y = $('#hm-tab-default-style').offset().top;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            if (x <= 0 || y <= 0) {
                x = $('#hm-editor-sidebar-right-wrap').offset().left - 20;
                y = 640;
            }

            return { x: x, y: y };
        });
        var textForSaveStep = '<p>Don\'t forget to save your work! This editor uses Local Storage to save your image maps, which means no web server or database is required.</p><p>Press the <strong>Save</strong> button and refresh the page!</p>';

        if ($.image_map_pro_text_for_save_step) {
            textForSaveStep = $.image_map_pro_text_for_save_step();
        }

        self.tourSteps['save'] = self.tour.addStep('save', 'bottom', 'Save', textForSaveStep, function() {
            var x = $('#button-save').offset().left + $('#button-save').outerWidth()/2 + 10;
            var y = $('#button-save').offset().top + $('#button-save').outerHeight() + 10;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        self.tourSteps['load'] = self.tour.addStep('load', 'bottom', 'Load', '<p>You can also load image maps that you saved previously.</p> <p>Press the <strong>Load</strong> button and click on the current project to load it!</p>', function() {
            var x = $('#button-load').offset().left + $('#button-load').outerWidth()/2 + 10;
            var y = $('#button-load').offset().top + $('#button-load').outerHeight() + 10;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });
        var shouldAddGenerateCodeStep = true;

        if ($.image_map_pro_should_add_generate_code_step) {
            shouldAddGenerateCodeStep = $.image_map_pro_should_add_generate_code_step();
        }

        if (shouldAddGenerateCodeStep) {
            self.tourSteps['generate code'] = self.tour.addStep('generate code', 'bottom', 'When you are done...', '<p>Installing the image in your website is as easy as installing any other jQuery plugin.</p><p>Press the <strong>Generate Code</strong> button to see the instructions!</p><p>Press <strong>Close</strong> at the bottom of the dialog window to continue.</p>', function() {
                var x = $('#button-generate-code').offset().left + $('#button-generate-code').outerWidth()/2 + 10;
                var y = $('#button-generate-code').offset().top + $('#button-generate-code').outerHeight() + 10;

                x -= $('.bootstrap-wrapper').offset().left;
                y -= $('.bootstrap-wrapper').offset().top;

                return { x: x, y: y };
            });
        }

        self.tourSteps['final'] = self.tour.addStep('final', '', 'Done!', '<p>Thank you for taking this guided tour!</p><p>You should now be familiar with the basics of this plugin. Have fun creating your image maps!</p>', function() {
            var x = $(window).width()/2;
            var y = $(window).height()/2;

            x -= $('.bootstrap-wrapper').offset().left;
            y -= $('.bootstrap-wrapper').offset().top;

            return { x: x, y: y };
        });

        // Tour
        self.tourSteps['save']();

        /*
        Tour Steps:
        - pick name and create
        - choose poly tool
        - draw a poly
        - choose spot tool
        - draw a spot
        - go to preview mode
        - set icon for the spot
        - select the poly
        - set styles for the poly
        - resize window
        - save
        - generate code
        - final
        */

        self.tour.init();
    };
    Editor.prototype.resumeTour = function() {
        var self = this;

        // Resume tour
        if (saves.length == 0) {
            return;
        }

        if ($.image_map_pro_resume_tour) {
            if ($.image_map_pro_resume_tour(self)) {
                return;
            }
        }

        var step = '';
        // Is there a polygon created? If not, resume from step 'draw a poly'
        var polyCreated = false;

        for (var i=0; i<settings.spots.length; i++) {
            if (settings.spots[i].type == 'poly') {
                polyCreated = true;
            }
        }
        if (!polyCreated) {
            if (settings.editor.tool != 'poly') {
                // ---> Is the poly tool selected? If not, resume from step 'choose poly tool'
                self.tour.resumeFromStep('choose poly tool');
                return;
            } else {
                self.tour.resumeFromStep('draw a poly');
                return;
            }
        }


        // Is there a spot created? If not, resume from step 'draw a spot'
        var spotCreated = false;
        var spot = undefined;
        for (var i=0; i<settings.spots.length; i++) {
            if (settings.spots[i].type == 'spot') {
                spotCreated = true;
                spot = settings.spots[i];
            }
        }
        if (!spotCreated) {
            if (settings.editor.tool != 'spot') {
                // ---> Is the spot tool selected? If not, resume from step 'choose spot tool'
                self.tour.resumeFromStep('choose spot tool');
                return;
            } else {
                self.tour.resumeFromStep('draw a spot');
                return;
            }
        }

        // Are we in preview mode? If not, resume from step 'go to preview mode'
        if (parseInt(settings.editor.previewMode, 10) == 0) {
            self.tour.resumeFromStep('go to preview mode');
            return;
        }

        // Does the spot have an icon? If not, resume from step 'set icon for the spot'
        if (parseInt(spot.default_style.use_icon, 10) == 0) {
            self.tour.resumeFromStep('set icon for the spot');
            return;
        }

        // Is the poly selected? If not, resume from step 'select the poly'
        if (self.selectedSpot && self.selectedSpot.type != 'poly') {
            self.tour.resumeFromStep('select the poly');
            return;
        }
    };
    Editor.prototype.launch = function() {
        var self = this;

        // Resume tour
        this.resumeTour();

        // Make sure spot coordinates are numbers
        for (var i=0; i<settings.spots.length; i++) {
            var s = settings.spots[i];

            s.x = parseFloat(s.x);
            s.y = parseFloat(s.y);
            s.width = parseFloat(s.width);
            s.height = parseFloat(s.height);

            s.default_style.stroke_width = parseInt(s.default_style.stroke_width);
            s.mouseover_style.stroke_width = parseInt(s.mouseover_style.stroke_width);

            if (s.type == 'poly') {
                if (s.points) {
                    for (var j=0; j<s.points.length; j++) {
                        s.points[j].x = parseFloat(s.points[j].x);
                        s.points[j].y = parseFloat(s.points[j].y);
                    }
                }

                if (s.vs) {
                    for (var j=0; j<s.vs.length; j++) {
                        for (var k=0; k<s.vs[j].length; k++) {
                            s.vs[j][0] = parseFloat(s.vs[j][0]);
                            s.vs[j][1] = parseFloat(s.vs[j][1]);
                        }
                    }
                }
            }
        }
        settings.general.width = parseInt(settings.general.width);
        settings.general.height = parseInt(settings.general.height);

        // If there is an image URL entered, show the loader and start redraw
        if (settings.general.image_url && settings.general.image_url.length > 0) {
            self.canvasImage.src = settings.general.image_url;

            loadImage(self.canvasImage, function() {
                // Image is loading
                // Show loader
                // if (parseInt(settings.editor.previewMode, 10) == 0) {
                    $('#hm-editor-image-loader').show();
                    $('#hm-editor-canvas').hide();
                // }
                // Hide popover
                $('[data-toggle="popover"]').popover('hide');
            }, function() {
                // Image has loaded
                // init canvas events
                self.canvas_events();

                // Hide loader
                // if (parseInt(settings.editor.previewMode, 10) == 0) {
                    $('#hm-editor-image-loader').hide();
                    $('#hm-editor-canvas').show();
                // }

                settings.general.width = self.canvasImage.naturalWidth;
                settings.general.height = self.canvasImage.naturalHeight;

                self.generalSettingsForm.loadSettings();

                self.canvas_events();
                self.redraw();
                self.selectSpot(settings.editor.selected_hotspot);
            });

            // Tips
            this.showTip('begin', 'Start by choosing a shape tool from the left. You can draw spots, rectangles, ellipses and polygons. Make sure you are in <strong>Edit Mode</strong>!')
        } else {
            // If there isn't, and tour has ended, show popup to enter URL
            if ($.image_map_pro_editor_has_no_image && this.tour.ended) {
                $.image_map_pro_editor_has_no_image();
            }

            // And hide canvas
            $('#hm-editor-canvas').hide();
        }

        // Variables
        didLaunch = true;

        this.selectedSpot = undefined;
        this.actionIndex = -1;
        this.actionStack = new Array();
        this.addAction();
        this.canvas = $('#hm-editor-canvas');

        // Editor mode
        if (parseInt(settings.editor.previewMode, 10) == 1) {
            $('#hm-editor-image-loader').hide();
            $('#button-preview-mode').addClass('active');
            $('#button-edit-mode').removeClass('active');
        } else {
            $('#button-edit-mode').addClass('active');
            $('#button-preview-mode').removeClass('active');
        }

        // Tool
        $('.hm-toolbar-button').removeClass('active');
        if (settings.editor.tool == 'spot') {
            $('#hm-toolbar-button-spot').addClass('active');
        }
        if (settings.editor.tool == 'rect') {
            $('#hm-toolbar-button-rect').addClass('active');
        }
        if (settings.editor.tool == 'oval') {
            $('#hm-toolbar-button-oval').addClass('active');
        }
        if (settings.editor.tool == 'poly') {
            $('#hm-toolbar-button-poly').addClass('active');
        }

        // Init general settings form
        // setting name, sub-group, data type, form element ID
        this.generalSettingsForm.addField('name', undefined, 'text', '#input-name');
        this.generalSettingsForm.addField('width', undefined, 'int', '#input-width');
        this.generalSettingsForm.addField('height', undefined, 'int', '#input-height');
        this.generalSettingsForm.addField('responsive', undefined, 'checkbox', '#checkbox-responsive');
        this.generalSettingsForm.addField('sticky_tooltips', undefined, 'checkbox', '#checkbox-sticky-tooltips');
        this.generalSettingsForm.addField('constrain_tooltips', undefined, 'checkbox', '#checkbox-constrain-tooltips');
        this.generalSettingsForm.addField('tooltip_animation', undefined, 'select', '#select-tooltip-animation');
        this.generalSettingsForm.addField('pageload_animation', undefined, 'select', '#select-pageload-animation');
        this.generalSettingsForm.addField('image_url', undefined, 'text', '#input-image-url');

        if ($.plugin_editor_add_fields) {
            $.plugin_editor_add_fields(this.generalSettingsForm);
        }

        this.generalSettingsForm.init(settings.general);

        // Init hotspot settings form

        // general
        this.hotspotSettingsForm.addField('x', undefined, 'float', '#input-spot-x');
        this.hotspotSettingsForm.addField('y', undefined, 'float', '#input-spot-y');
        this.hotspotSettingsForm.addField('width', undefined, 'float', '#input-spot-width');
        this.hotspotSettingsForm.addField('height', undefined, 'float', '#input-spot-height');

        // actions
        this.hotspotSettingsForm.addField('mouseover', 'actions', 'select', '#select-spot-mouseover-action');
        this.hotspotSettingsForm.addField('click', 'actions', 'select', '#select-spot-click-action');
        this.hotspotSettingsForm.addField('link', 'actions', 'text', '#input-spot-link');
        this.hotspotSettingsForm.addField('open_link_in_new_window', 'actions', 'checkbox', '#checkbox-open-link-in-new-window');

        // default styles
        this.hotspotSettingsForm.addField('opacity', 'default_style', 'float', '#input-spot-default-opacity');
        this.hotspotSettingsForm.addField('border_radius', 'default_style', 'int', '#input-spot-default-border-radius');
        this.hotspotSettingsForm.addField('background_color', 'default_style', 'text', '#input-spot-default-background-color');
        this.hotspotSettingsForm.addField('background_opacity', 'default_style', 'float', '#input-spot-default-background-opacity');
        this.hotspotSettingsForm.addField('border_width', 'default_style', 'int', '#input-spot-default-border-width');
        this.hotspotSettingsForm.addField('border_style', 'default_style', 'select', '#select-spot-default-border-style');
        this.hotspotSettingsForm.addField('border_color', 'default_style', 'text', '#input-spot-default-border-color');
        this.hotspotSettingsForm.addField('border_opacity', 'default_style', 'float', '#input-spot-default-border-opacity');

        this.hotspotSettingsForm.addField('use_icon', 'default_style', 'checkbox', '#checkbox-spot-default-use-icon');
        this.hotspotSettingsForm.addField('icon_type', 'default_style', 'button group', [ '#button-spot-from-library', '#button-spot-custom-url' ]);
        this.hotspotSettingsForm.addField('icon_url', 'default_style', 'text', '#input-spot-default-icon-url');
        this.hotspotSettingsForm.addField('icon_fill', 'default_style', 'text', '#input-spot-icon-fill');
        this.hotspotSettingsForm.addField('icon_is_pin', 'default_style', 'checkbox', '#checkbox-spot-default-icon-is-pin');
        this.hotspotSettingsForm.addField('icon_shadow', 'default_style', 'checkbox', '#checkbox-spot-default-icon-shadow');

        this.hotspotSettingsForm.addField('fill', 'default_style', 'text', '#input-spot-default-fill');
        this.hotspotSettingsForm.addField('fill_opacity', 'default_style', 'float', '#input-spot-default-fill-opacity');
        this.hotspotSettingsForm.addField('stroke_color', 'default_style', 'text', '#input-spot-default-stroke-color');
        this.hotspotSettingsForm.addField('stroke_opacity', 'default_style', 'float', '#input-spot-default-stroke-opacity');
        this.hotspotSettingsForm.addField('stroke_width', 'default_style', 'int', '#input-spot-default-stroke-width');
        this.hotspotSettingsForm.addField('stroke_dasharray', 'default_style', 'text', '#input-spot-default-stroke-dasharray');
        this.hotspotSettingsForm.addField('stroke_linecap', 'default_style', 'select', '#select-spot-default-stroke-linecap');

        // mouseover styles
        this.hotspotSettingsForm.addField('opacity', 'mouseover_style', 'float', '#input-spot-mouseover-opacity');
        this.hotspotSettingsForm.addField('border_radius', 'mouseover_style', 'int', '#input-spot-mouseover-border-radius');
        this.hotspotSettingsForm.addField('background_color', 'mouseover_style', 'text', '#input-spot-mouseover-background-color');
        this.hotspotSettingsForm.addField('background_opacity', 'mouseover_style', 'float', '#input-spot-mouseover-background-opacity');
        this.hotspotSettingsForm.addField('border_width', 'mouseover_style', 'int', '#input-spot-mouseover-border-width');
        this.hotspotSettingsForm.addField('border_style', 'mouseover_style', 'select', '#select-spot-mouseover-border-style');
        this.hotspotSettingsForm.addField('border_color', 'mouseover_style', 'text', '#input-spot-mouseover-border-color');
        this.hotspotSettingsForm.addField('border_opacity', 'mouseover_style', 'float', '#input-spot-mouseover-border-opacity');

        this.hotspotSettingsForm.addField('fill', 'mouseover_style', 'text', '#input-spot-mouseover-fill');
        this.hotspotSettingsForm.addField('fill_opacity', 'mouseover_style', 'float', '#input-spot-mouseover-fill-opacity');
        this.hotspotSettingsForm.addField('stroke_color', 'mouseover_style', 'text', '#input-spot-mouseover-stroke-color');
        this.hotspotSettingsForm.addField('stroke_opacity', 'mouseover_style', 'float', '#input-spot-mouseover-stroke-opacity');
        this.hotspotSettingsForm.addField('stroke_width', 'mouseover_style', 'int', '#input-spot-mouseover-stroke-width');
        this.hotspotSettingsForm.addField('stroke_dasharray', 'mouseover_style', 'text', '#input-spot-mouseover-stroke-dasharray');
        this.hotspotSettingsForm.addField('stroke_linecap', 'mouseover_style', 'select', '#select-spot-mouseover-stroke-linecap');

        // tooltip styles
        this.hotspotSettingsForm.addField('padding', 'tooltip_style', 'int', '#input-spot-tooltip-padding');
        this.hotspotSettingsForm.addField('border_radius', 'tooltip_style', 'int', '#input-spot-tooltip-border-radius');
        this.hotspotSettingsForm.addField('background_color', 'tooltip_style', 'text', '#input-spot-tooltip-background-color');
        this.hotspotSettingsForm.addField('background_opacity', 'tooltip_style', 'float', '#input-spot-tooltip-background-opacity');
        this.hotspotSettingsForm.addField('position', 'tooltip_style', 'select', '#select-spot-tooltip-position');
        this.hotspotSettingsForm.addField('width', 'tooltip_style', 'int', '#input-spot-tooltip-width');
        this.hotspotSettingsForm.addField('height', 'tooltip_style', 'int', '#input-spot-tooltip-height');
        this.hotspotSettingsForm.addField('auto_width', 'tooltip_style', 'checkbox', '#checkbox-spot-auto-tooltip-width');
        this.hotspotSettingsForm.addField('auto_height', 'tooltip_style', 'checkbox', '#checkbox-spot-auto-tooltip-height');

        // text styles
        this.hotspotSettingsForm.addField('title_color', 'text_style', 'text', '#input-spot-title-color');
        this.hotspotSettingsForm.addField('title_font_size', 'text_style', 'int', '#input-spot-title-font-size');
        this.hotspotSettingsForm.addField('title_font_family', 'text_style', 'text', '#input-spot-title-font-family');
        this.hotspotSettingsForm.addField('title_font_weight', 'text_style', 'int', '#input-spot-title-font-weight');
        this.hotspotSettingsForm.addField('title_line_height', 'text_style', 'int', '#input-spot-title-line-height');
        this.hotspotSettingsForm.addField('text_color', 'text_style', 'text', '#input-spot-text-color');
        this.hotspotSettingsForm.addField('text_font_size', 'text_style', 'int', '#input-spot-text-font-size');
        this.hotspotSettingsForm.addField('text_font_family', 'text_style', 'text', '#input-spot-text-font-family');
        this.hotspotSettingsForm.addField('text_font_weight', 'text_style', 'int', '#input-spot-text-font-weight');
        this.hotspotSettingsForm.addField('text_line_height', 'text_style', 'int', '#input-spot-text-line-height');

        // tooltip content
        this.hotspotSettingsForm.addField('title', 'tooltip_content', 'text', '#input-spot-title');
        this.hotspotSettingsForm.addField('text', 'tooltip_content', 'text', '#textarea-spot-text');
    }
    Editor.prototype.redraw = function() {
        var self = this;

        // Calculate canvas dimentions
        var canvasBackgroundWidth = $('#hm-editor-canvas-background').width() - 80;
        var canvasBackgroundHeight = $('#hm-editor-canvas-background').height() - 80;

        if (settings.general.width > canvasBackgroundWidth || settings.general.height > canvasBackgroundHeight) {
            // Canvas needs to be resized to fit the editor's background
            var imageRatio = settings.general.width / settings.general.height;
            var backgroundRatio = canvasBackgroundWidth / canvasBackgroundHeight;

            if (imageRatio <= backgroundRatio) {
                // Fit to height
                self.canvasWidth = canvasBackgroundHeight * imageRatio;
                self.canvasHeight = $('#hm-editor-canvas-background').height() - 80;
            } else {
                // Fit to width
                self.canvasWidth = $('#hm-editor-canvas-background').width() - 80;
                self.canvasHeight = canvasBackgroundWidth/imageRatio;
            }
        } else {
            // Canvas does not need to be resized
            self.canvasWidth = settings.general.width;
            self.canvasHeight = settings.general.height;
        }

        // Fit canvas to editor
        $('#hm-editor-canvas').css({
            width: self.canvasWidth,
            height: self.canvasHeight
        });

        if (parseInt(settings.editor.previewMode, 10) == 0) {
            // Edit mode
            // Redraw editor
            $('#hm-editor-canvas').html($.image_map_pro_editor_content());

            $('#hm-editor-image').css({
                width: self.canvasWidth,
                height: self.canvasHeight
            });
        } else {
            // Preview mode
            // Redraw plugin
            $('#hm-editor-canvas').imageMapPro(settings);
        }

        // Hotspots list
        var html = '';
        for (var i=settings.spots.length-1; i>=0; i--) {
            var placement = 'top';
            if (i == settings.spots.length-1) placement = 'bottom';
            html += '<a href="#" class="list-group-item hotspot-list-group-item" data-id="'+ settings.spots[i].id +'" data-open-spot="'+ settings.spots[i].id +'">'+ settings.spots[i].id;
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-delete" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Delete Hotspot"><span class="glyphicon glyphicon-trash"></span></div>';
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-duplicate" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Duplicate Hotspot"><span class="glyphicon glyphicon-duplicate"></span></div>';
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-paste" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Paste Style"><span class="glyphicon glyphicon-paste"></span></div>';
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-copy" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Copy Style"><span class="glyphicon glyphicon-copy"></span></div>';
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-move-down" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Move Down"><span class="glyphicon glyphicon-arrow-down"></span></div>';
            html += '   <div class="btn btn-default btn-sm hm-spot-control-button" id="hm-spot-button-move-up" data-placement="'+ placement +'" data-toggle="tooltip" data-original-title="Move Up"><span class="glyphicon glyphicon-arrow-up"></span></div>';
            html += '</a>';
        }
        $('#hotspot-list-group').html(html);
        $('.hm-spot-control-button[data-toggle="tooltip"]').tooltip();

        // Spot selection
        self.redrawSpotSelection();

        // Redraw hotspot settings form
        if (self.selectedSpot) {
            $('#hotspot-settings-wrap').show();
            self.hotspotSettingsForm.init(self.selectedSpot);

            if (self.selectedSpot.type == 'spot') {
                $('#input-spot-width').siblings('.input-group-addon').html('px');
                $('#input-spot-height').siblings('.input-group-addon').html('px');
                $('.hm-settings-group-spot-icon').show();
                $('.hm-settings-group-svg').hide();
                $('.hm-settings-group-element-styles').show();
                $('.hm-settings-group-border-radius').show();
            }
            if (self.selectedSpot.type == 'rect') {
                $('#input-spot-width').siblings('.input-group-addon').html('%');
                $('#input-spot-height').siblings('.input-group-addon').html('%');
                $('.hm-settings-group-spot-icon').hide();
                $('.hm-settings-group-svg').hide();
                $('.hm-settings-group-element-styles').show();
                $('.hm-settings-group-border-radius').show();
            }
            if (self.selectedSpot.type == 'oval') {
                $('#input-spot-width').siblings('.input-group-addon').html('%');
                $('#input-spot-height').siblings('.input-group-addon').html('%');
                $('.hm-settings-group-spot-icon').hide();
                $('.hm-settings-group-svg').hide();
                $('.hm-settings-group-element-styles').show();
                $('.hm-settings-group-border-radius').hide();
            }
            if (self.selectedSpot.type == 'poly') {
                $('#input-spot-width').siblings('.input-group-addon').html('%');
                $('#input-spot-height').siblings('.input-group-addon').html('%');
                $('.hm-settings-group-spot-icon').hide();
                $('.hm-settings-group-svg').show();
                $('.hm-settings-group-element-styles').hide();
                $('.hm-settings-group-border-radius').hide();
            }
            if (self.selectedSpot.tooltip_style.auto_width == 0) {
                $('#input-spot-tooltip-width').removeAttr('disabled');
            } else {
                $('#input-spot-tooltip-width').attr('disabled', 'disabled');
            }
            if (self.selectedSpot.tooltip_style.auto_height == 0) {
                $('#input-spot-tooltip-height').removeAttr('disabled');
            } else {
                $('#input-spot-tooltip-height').attr('disabled', 'disabled');
            }
            if (parseInt(self.selectedSpot.default_style.use_icon, 10) == 1) {
                $('#hm-settings-group-spot-icon-wrap').show();
            } else {
                $('#hm-settings-group-spot-icon-wrap').hide();
            }
            if (self.selectedSpot.default_style.icon_type == 'library') {
                $('#hm-settings-group-spot-icon-library').show();
            } else {
                $('#hm-settings-group-spot-icon-library').hide();
            }
            if (self.selectedSpot.default_style.icon_type == 'custom') {
                $('#hm-settings-group-spot-icon-custom').show();
            } else {
                $('#hm-settings-group-spot-icon-custom').hide();
            }
        } else {
            $('#hotspot-settings-wrap').hide();
        }

        // Undo/Redo
        self.updateActionButtons();
        // });
    }
    Editor.prototype.redrawSpotSelection = function() {
        var self = this;

        // deselect
        $('.hotspot-list-group-item').removeClass('active');
        $('.hm-hotspot').removeClass('selected');

        // select
        if (settings.editor.selected_hotspot != -1) {
            // set a reference to the selected spot
            var i = self.getIndexOfSpotWithId(settings.editor.selected_hotspot);
            // No such spot found
            if (i == undefined) {
                settings.editor.selected_hotspot = -1;
                return;
            }

            $('.hotspot-list-group-item[data-id="'+ settings.editor.selected_hotspot +'"]').addClass('active');
            $('.hm-hotspot[data-id="'+ settings.editor.selected_hotspot +'"]').addClass('selected');

            self.selectedSpot = settings.spots[i];

            // Save a reference to the SVG if it's a poly for quick redraw
            if (self.selectedSpot.type == 'poly') {
                self.tempControlPoint = $('.hm-editor-poly[data-id="'+ settings.editor.selected_hotspot +'"]').find('.hm-editor-poly-svg-temp-control-point');
                self.tempControlPointLine = $('.hm-editor-poly[data-id="'+ settings.editor.selected_hotspot +'"]').find('.hm-editor-poly-svg-temp-control-point-line');
            }
        } else {
            self.selectedSpot = undefined;
        }
    }
    Editor.prototype.settingsUpdated = function(id) {
        var self = this;

        if (settings.general.image_url.length > 0 && id == 'input-image-url') {
            self.canvasImage.src = settings.general.image_url;

            loadImage(self.canvasImage, function() {
                // Image is loading
                // Show loader
                if (parseInt(settings.editor.previewMode, 10) == 0) {
                    $('#hm-editor-image-loader').show();
                    $('#hm-editor-canvas').hide();
                }
                // Hide popover
                $('[data-toggle="popover"]').popover('hide');
            }, function() {
                // Image has loaded
                // init canvas events
                self.canvas_events();

                // Hide loader
                if (parseInt(settings.editor.previewMode, 10) == 0) {
                    $('#hm-editor-image-loader').hide();
                    $('#hm-editor-canvas').show();
                }

                settings.general.width = self.canvasImage.naturalWidth;
                settings.general.height = self.canvasImage.naturalHeight;

                self.generalSettingsForm.loadSettings();
                self.redraw();
            });
        }

        self.addAction();
        self.redraw();
    }
    Editor.prototype.events = function() {
        var self = this;
        var showLoadModalAfterCreateCancel = true;

        // Create new
        $(document).off('keyup', '#input-widget-name');
        $(document).on('keyup', '#input-widget-name', function(e) {
            if (e.keyCode == 13) {
                $('#button-new-widget-create').click();
            }
        });

        // Save/Load
        $(document).off('click', '#button-saves-create-new');
        $(document).on('click', '#button-saves-create-new', function() {
            $('#modal-saves').modal('hide');
            $('#modal-new-widget').modal('show');

            $('#button-new-widget-cancel').show();
            showLoadModalAfterCreateCancel = true;

            // tour
            if (!self.tour.ended) {
                self.tour.resumeFromStep('pick name and create');
            }
        });

        $(document).off('click', '#button-new-widget-create');
        $(document).on('click', '#button-new-widget-create', function() {
            var button = $(this);

            // Validate
            var inputs = $('#modal-new-widget input');
            for (var i=0; i<inputs.length; i++) {
                if ($(inputs[i]).val().length == 0) {
                    $(inputs[i]).closest('.form-group').addClass('has-error');
                    return;
                } else {
                    $(inputs[i]).closest('.form-group').removeClass('has-error');
                }
            }

            // Create
            if ($.image_map_pro_modify_default_settings) {
                $.image_map_pro_modify_default_settings(default_settings);
            }
            settings = $.extend(true, {}, default_settings);

            settings.id = Math.round(Math.random() * 10000) + 1;
            settings.general.name = $('#input-widget-name').val();

            button.attr('disabled', 'disabled');
            button.html('Creating...');

            $.editor_storage_store_save(settings, function() {
                $.editor_storage_set_last_save(settings, function() {
                    button.removeAttr('disabled');
                    button.html('Create');

                    // Launch editor
                    $('#modal-new-widget').modal('hide');
                    self.launch();
                });
            });

            // tour
            self.tourSteps['pick name and create']();
        });

        $(document).off('click', '#button-new-widget-cancel');
        $(document).on('click', '#button-new-widget-cancel', function() {
            $('#modal-new-widget').modal('hide');

            if (showLoadModalAfterCreateCancel) {
                $('#modal-saves').modal('show');
            }
        });

        $(document).off('click', '.widget-load');
        $(document).on('click', '.widget-load', function() {
            var button = $(this);

            settings = saves[$(this).data('index')];
            $(this).addClass('active');

            $.editor_storage_set_last_save(settings, function() {
                button.removeClass('active');
                self.launch();
                $('#modal-saves').modal('hide');
            });

            self.tourSteps['load']();
        });

        var saveToDeleteId = 0;
        $(document).off('click', '.widget-delete-button');
        $(document).on('click', '.widget-delete-button', function() {
            $('#modal-saves').modal('hide');
            $('#modal-confirm-delete-widget').modal('show');
            saveToDeleteId = $(this).data('index');
        });

        $(document).off('click', '#button-confirm-delete-widget');
        $(document).on('click', '#button-confirm-delete-widget', function() {
            $(this).attr('disabled', 'disabled');
            $(this).html('Deleting...');

            var button = $(this);
            $.editor_storage_delete_save(saveToDeleteId, function() {
                $('#modal-confirm-delete-widget').modal('hide');

                button.removeAttr('disabled');
                button.html('Delete');

                if (didLaunch) {
                    $('#modal-saves').modal('show');
                }

                self.init();
            });
        });

        $(document).off('click', '#button-cancel-delete-widget');
        $(document).on('click', '#button-cancel-delete-widget', function() {
            $('#modal-saves').modal('show');
            $('#modal-confirm-delete-widget').modal('hide');
        });

        // Toolbar buttons
        $(document).off('click', '#button-save');
        $(document).on('click', '#button-save', function() {
            $(this).attr('disabled', 'disabled');
            $(this).html('Saving...');

            var button = $(this);
            $.editor_storage_store_save(settings, function() {
                $.editor_storage_set_last_save(settings, function() {
                    button.html('<span class="glyphicon glyphicon-ok"></span> Saved');
                    button.removeAttr('disabled');
                });
            });
        });

        $(document).off('click', '#button-load');
        $(document).on('click', '#button-load', function() {
            $('#button-modal-saves-cancel').show();

            var button = $(this);
            button.attr('disabled', 'disabled');
            button.html('Loading...');
            $.editor_storage_get_saves(function(res) {
                button.html('<span class="glyphicon glyphicon-hdd"></span> Load');
                button.removeAttr('disabled');

                saves = res;

                $('#saved-widgets-container').html('');
                $('#saved-widgets-controls-container').html('');

                if (saves.length > 0) {
                    // print saves
                    for (var i=0; i<saves.length; i++) {
                        $('#saved-widgets-container').append('<a href="#" class="bg-primary list-group-item widget-load" data-index="'+ i +'">'+ saves[i].general.name +'</div>');
                        $('#saved-widgets-controls-container').append('<div class="saved-widgets-controls"><button class="pull-right btn btn-default widget-delete-button" data-index="'+ i +'">Delete</button></div>');
                    }
                }

                $('#modal-saves').modal();
            });
        });

        $(document).off('click', '#button-new');
        $(document).on('click', '#button-new', function() {
            $('#modal-new-widget').modal('show');
            $('#button-new-widget-cancel').show();

            showLoadModalAfterCreateCancel = false;
        });

        $(document).off('click', '#button-generate-code');
        $(document).on('click', '#button-generate-code', function() {
            $('#modal-generate-code').modal();
            $('#textarea-generated-code').val('$("#image-map-pro-container").imageMapPro('+ JSON.stringify(settings) +');');
            $('#generated-code-image-url').html(settings.general.image_url);
        });

        $(document).off('click', '#button-undo');
        $(document).on('click', '#button-undo', function() {
            self.undo();
        });

        $(document).off('click', '#button-redo');
        $(document).on('click', '#button-redo', function() {
            self.redo();
        });

        $(document).off('click', '#button-preview-mode');
        $(document).on('click', '#button-preview-mode', function() {
            settings.editor.previewMode = 1;
            self.redraw();

            $('#button-preview-mode').addClass('active');
            $('#button-edit-mode').removeClass('active');

            // Tour
            self.tourSteps['go to preview mode']();
        });

        $(document).off('click', '#button-edit-mode');
        $(document).on('click', '#button-edit-mode', function() {
            settings.editor.previewMode = 0;
            self.redraw();

            $('#button-preview-mode').removeClass('active');
            $('#button-edit-mode').addClass('active');
        });

        // Forms
        $('.hm-editor-sidebar-header').off('click');
        $('.hm-editor-sidebar-header').on('click', function() {
            $(this).closest('.hm-editor-sidebar-tab').toggleClass('hm-sidebar-tab-collapsed');
        });

        var targetHotspot = undefined;
        var copiedStyles = undefined;
        $(document).off('click', '.hotspot-list-group-item');
        $(document).on('click', '.hotspot-list-group-item', function(e) {
            targetHotspot = $(this).data('id');

            if ($(e.target).attr('id') == 'hm-spot-button-move-up' || $(e.target).closest('#hm-spot-button-move-up').length > 0) {
                var i = self.getIndexOfSpotWithId(targetHotspot);

                if (i < settings.spots.length - 1) {
                    var a = settings.spots[i + 1];
                    settings.spots[i + 1] = settings.spots[i];
                    settings.spots[i] = a;

                    self.redraw();
                    self.addAction();
                }
                return;
            }
            if ($(e.target).attr('id') == 'hm-spot-button-move-down' || $(e.target).closest('#hm-spot-button-move-down').length > 0) {
                var i = self.getIndexOfSpotWithId(targetHotspot);

                if (i > 0) {
                    var a = settings.spots[i - 1];
                    settings.spots[i - 1] = settings.spots[i];
                    settings.spots[i] = a;

                    self.redraw();
                    self.addAction();
                }

                return;
            }
            if ($(e.target).attr('id') == 'hm-spot-button-copy' || $(e.target).closest('#hm-spot-button-copy').length > 0) {
                var i = self.getIndexOfSpotWithId(targetHotspot);
                copiedStyles = {
                    default_style: $.extend(true, {}, settings.spots[i].default_style),
                    mouseover_style: $.extend(true, {}, settings.spots[i].mouseover_style),
                    tooltip_style: $.extend(true, {}, settings.spots[i].tooltip_style),
                    text_style: $.extend(true, {}, settings.spots[i].text_style)
                }
                return;
            }
            if ($(e.target).attr('id') == 'hm-spot-button-paste' || $(e.target).closest('#hm-spot-button-paste').length > 0) {
                var i = self.getIndexOfSpotWithId(targetHotspot);
                settings.spots[i].default_style = $.extend(true, {}, copiedStyles.default_style);
                settings.spots[i].mouseover_style = $.extend(true, {}, copiedStyles.mouseover_style);
                settings.spots[i].tooltip_style = $.extend(true, {}, copiedStyles.tooltip_style);
                settings.spots[i].text_style = $.extend(true, {}, copiedStyles.text_style);

                self.redraw();
                self.addAction();
                return;
            }
            if ($(e.target).attr('id') == 'hm-spot-button-duplicate' || $(e.target).closest('#hm-spot-button-duplicate').length > 0) {
                var i = self.getIndexOfSpotWithId(targetHotspot);
                var s = $.extend(true, {}, settings.spots[i]);

                if (s.type == 'spot') s.id = self.createIdForSpot();
                if (s.type == 'rect') s.id = self.createIdForRect();
                if (s.type == 'oval') s.id = self.createIdForOval();
                if (s.type == 'poly') s.id = self.createIdForPoly();

                settings.spots.push(s);

                self.redraw();
                self.addAction();
                return;
            }
            if ($(e.target).attr('id') == 'hm-spot-button-delete' || $(e.target).closest('#hm-spot-button-delete').length > 0) {
                $('#modal-confirm-delete-hotspot').modal();
                return;
            }

            self.deselectSpot();
            self.selectSpot($(this).data('id'));
            self.redraw();
            self.addAction();

            // Tour
            if ($(this).data('id') == 'poly-1') {
                self.tourSteps['select the poly']();
            }

            return false;
        });

        $(document).off('mouseover', '.hotspot-list-group-item');
        $(document).on('mouseover', '.hotspot-list-group-item', function(e) {
            if (!$(this).hasClass('hm-mouseover')) {
                $('.hm-mouseover').removeClass('hm-mouseover');
                $(this).addClass('hm-mouseover');

                $.image_map_pro_highlight_spot(self.getIndexOfSpotWithId($(this).data('id')));
            }
        });

        $(document).off('click', '#button-confirm-delete-hotspot');
        $(document).on('click', '#button-confirm-delete-hotspot', function(e) {
            // Delete the hotspot with this id
            var i = self.getIndexOfSpotWithId(targetHotspot);

            // If the deleted spot was selected, deselect it
            if (settings.editor.selected_hotspot == settings.spots[i].id) {
                self.deselectSpot();
            }

            settings.spots.splice(i, 1);

            self.redraw();
            self.addAction();
        });

        $('.hm-toolbar-button').off('click');
        $('.hm-toolbar-button').on('click', function() {
            $('.hm-toolbar-button').removeClass('active');
            $(this).addClass('active');
            settings.editor.tool = $(this).data('tool');

            // Tour
            if ($(this).data('tool') == 'poly') {
                self.tourSteps['choose poly tool']();
            }
            if ($(this).data('tool') == 'spot') {
                self.tourSteps['choose spot tool']();
            }

            // Tips
            if ($(this).data('tool') == 'spot') self.showTip('spot tool', '<strong>Left-Click</strong> on the image to create a Spot shape.');
            if ($(this).data('tool') == 'rect') self.showTip('rect tool', '<strong>Left-Click and drag</strong> on the image to create a Rect shape.');
            if ($(this).data('tool') == 'oval') self.showTip('rect tool', '<strong>Left-Click and drag</strong> on the image to create a Rect shape.');
            if ($(this).data('tool') == 'poly') self.showTip('poly tool', '<strong>Left-Click</strong> on the image to start drawing a Poly shape, and continue clicking to place control points.');

            return false;
        });

        $('[data-toggle="tab"]').on('click', function() {
            $(this).toggleClass('hm-settings-tab-expanded');
            $($(this).data('target')).toggle();
        });

        $(document).off('click', '#button-spot-choose-icon');
        $(document).on('click', '#button-spot-choose-icon', function() {
            $('#modal-choose-icon').modal('show');
        });

        $(document).off('click', '.hm-spot-icon');
        $(document).on('click', '.hm-spot-icon', function() {
            $('#modal-choose-icon').modal('hide');
            self.selectedSpot.default_style.icon_svg_path = $(this).data('path');
            self.selectedSpot.default_style.icon_svg_viewbox = $(this).data('viewbox');
            self.redraw();
            self.addAction();

            // Tour
            self.tourSteps['set icon for the spot']();
        });

        // Tour
        $(document).off('click', '#modal-generate-code button');
        $(document).on('click', '#modal-generate-code button', function() {
            self.tourSteps['generate code']();
        });

        // Tips
        $('#hm-tip-close-button').on('click', function() {
            $('.hm-tips-visible').removeClass('hm-tips-visible');
        });
    }
    Editor.prototype.canvas_events = function() {
        var self = this;

        $(window).off('resize.hm-redraw');
        $(window).on('resize.hm-redraw', function() {
            self.redraw();
        });

        $(document).off('mousedown', '#hm-editor-canvas-background');
        $(document).on('mousedown', '#hm-editor-canvas-background', function(e) {
            self.handleMouseDown(e);
        });
        $(document).off('mousemove', '#hm-editor-wrap');
        $(document).on('mousemove', '#hm-editor-wrap', function(e) {
            self.handleMouseMove(e);
        });
        $(document).off('mouseup', '#hm-editor-wrap');
        $(document).on('mouseup', '#hm-editor-wrap', function(e) {
            self.handleMouseUp(e);
        });
        $(document).off('keyup');
        $(document).on('keyup', function(e) {
            // Abort drawing poly
            if (e.keyCode == 27 && self.drawingPoly) {
                self.drawingPoly = false;
                self.startedDrawingPoly = false;
                self.mouseDownWhileDrawingPoly = false;
                $('#temp-poly').remove();
            }
        });
        // Disable the context menu when deleting control point
        $('body').on('contextmenu', function(e) {
            if (self.didDeleteControlPoint) {
                self.didDeleteControlPoint = false;
                return false;
            }
        });
    }
    Editor.prototype.addAction = function() {
        var self = this;
        if (self.actionIndex < self.actionStack.length - 1) {
            self.actionStack.splice(self.actionIndex + 1, self.actionStack.length);
        }

        self.actionStack.push($.extend(true, {}, settings));
        self.actionIndex++;

        if (self.actionStack.length > 100) {
            self.actionStack.splice(0, 1);
            self.actionIndex--;
        }

        self.updateActionButtons();
        $('#button-save').html('<span class="glyphicon glyphicon-hdd"></span> Save');
    }
    Editor.prototype.updateActionButtons = function() {
        var self = this;

        if (self.actionStack.length > 1 && self.actionIndex > 0) {
            $('#button-undo').removeAttr('disabled');
        } else {
            $('#button-undo').attr('disabled', 'disabled');
        }

        if (self.actionStack.length > 0 && self.actionIndex < self.actionStack.length - 1) {
            $('#button-redo').removeAttr('disabled');
        } else {
            $('#button-redo').attr('disabled', 'disabled');
        }
    }
    Editor.prototype.undo = function() {
        var self = this;
        if (self.actionIndex > 0) {
            self.actionIndex--;
        }

        settings = $.extend(true, {}, self.actionStack[self.actionIndex]);

        self.redraw();
        self.generalSettingsForm.loadSettings();
    }
    Editor.prototype.redo = function() {
        var self = this;
        if (self.actionIndex < self.actionStack.length - 1) {
            self.actionIndex++;
        }

        settings = $.extend(true, {}, self.actionStack[self.actionIndex]);

        self.redraw();
        self.generalSettingsForm.loadSettings();
    }
    Editor.prototype.loadIconLibrary = function() {
        var self = this;

        var html = '';
        for (var i=0; i<$.webcraft_icon_library.length; i++) {
            html += '<div class="hm-spot-icon" data-path="'+ $.webcraft_icon_library[i][1] +'" data-viewbox="'+ $.webcraft_icon_library[i][0] +'">';
            html += '   <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" version="1.1" viewBox="'+ $.webcraft_icon_library[i][0] +'" xml:space="preserve" width="40px" height="40px">';
            html += '       <path style="fill:#000000" d="'+ $.webcraft_icon_library[i][1] +'"></path>';
            html += '   </svg>';
            html += '</div>';
        }

        $('#hm-spot-icons-container').html(html);
    }
    Editor.prototype.initSettingsTabs = function() {
        $('[data-expanded-by-default="false"]').each(function() {
            $(this).toggleClass('hm-settings-tab-expanded');
            $($(this).data('target')).toggle();
        });
    }

    Editor.prototype.handleMouseDown = function(e) {
        var self = this;

        // === If preview mode, return
        if (parseInt(settings.editor.previewMode, 10) == 1) return;

        // === If a modal is open, ignore
        if ($('body').hasClass('modal-open')) return;

        var point = screenToCanvasSpace(e.pageX, e.pageY, self.canvas);
        self.ix = point.x;
        self.iy = point.y;

        // === Drawing a poly?
        if (self.drawingPoly) {
            // close the loop
            if ($(e.target).is('circle') && $(e.target).data('index') == 0) {
                self.drawingPoly = false;
                self.finishedDrawingPoly = true;
                return;
            }

            // or create a new point
            self.placePointForTempPoly(self.ix, self.iy);
            self.redrawTempPoly();
            self.mouseDownWhileDrawingPoly = true;

            // Tips
            self.showTip('drawing poly', '<strong>Left-Click</strong> on the first point to close the shape. Press <strong>ESC</strong> to cancel drawing.');

            return;
        }

        // === Did user click on a control point?
        if (self.selectedSpot && self.selectedSpot.type == 'poly' && $(e.target).hasClass('hm-poly-control-point')) {
            $(e.target).addClass('active');

            self.translatedPointIndex = $(e.target).data('index');

            if (e.button == 2) {
                // Remove the control point
                self.selectedSpot.points.splice(self.translatedPointIndex, 1);
                self.updateBoundingBoxForPolygonSpot(self.selectedSpot);
                self.redraw();
                self.addAction();
                self.didDeleteControlPoint = true;
                return;
            }

            self.translatingControlPoint = true;

            self.translatedPointX = self.selectedSpot.points[self.translatedPointIndex].x;
            self.translatedPointY = self.selectedSpot.points[self.translatedPointIndex].y;

            // Cache
            self.translatedPoint = $(e.target);
            self.redrawPolygonEl = $(e.target).closest('.hm-hotspot').find('.hm-editor-poly-svg polygon');

            return;
        }

        // === Did user click on a poly line?
        if (self.selectedSpot && self.selectedSpot.type == 'poly' && $(e.target).hasClass('hm-editor-poly-svg-temp-control-point')) {
            self.selectedSpot.points.splice(self.tempControlPointIndex + 1, 0, { x: self.controlPointInsertionPointX, y: self.controlPointInsertionPointY });
            self.redraw();

            // Same code as from the "click on control point action"
            var point = $('.hm-hotspot[data-id="'+ self.selectedSpot.id +'"]').find('.hm-poly-control-point[data-index="'+ (self.tempControlPointIndex+1) +'"]');
            point.addClass('active');

            self.translatedPointIndex = point.data('index');
            self.translatingControlPoint = true;

            self.translatedPointX = self.selectedSpot.points[self.translatedPointIndex].x;
            self.translatedPointY = self.selectedSpot.points[self.translatedPointIndex].y;

            // Cache
            self.translatedPoint = point;
            self.redrawPolygonEl = point.closest('.hm-hotspot').find('.hm-editor-poly-svg polygon');

            return;
        }

        // === Did the event happen on a transform box?
        if ($(e.target).hasClass('hm-selection-translate-box')) {
            self.startedTransforming = true;
            self.transformDirection = $(e.target).data('transform-direction');
            self.redrawEl = $(e.target).closest('.hm-hotspot');

            if (self.selectedSpot.type == 'poly') {
                // Reference for quick redrawing
                self.redrawSvgEl = self.redrawEl.find('.hm-editor-poly-svg');
                self.redrawPolygonEl = self.redrawSvgEl.find('polygon');

                // Save the original coordinates of the poly's points
                self.polyPoints = new Array();
                for (var i=0; i<self.selectedSpot.points.length; i++) {
                    self.polyPoints.push({
                        x: self.selectedSpot.points[i].x,
                        y: self.selectedSpot.points[i].y
                    });
                }
            }

            return;
        }



        // === Did user try to select a polygon?
        for (var i=settings.spots.length - 1; i>=0; i--) {
            if (settings.spots[i].type != 'poly') continue;

            if (self.shouldSelectPoly(settings.spots[i].id)) {
                self.eventSpotId = settings.spots[i].id;
                self.startedSelecting = true;
                return;
            }
        }

        // === Did the event happen on a spot?
        if ($(e.target).hasClass('hm-hotspot') || $(e.target).closest('.hm-hotspot').length > 0) {
            // Make sure it's not a polygon
            if (!$(e.target).hasClass('hm-editor-poly') && $(e.target).closest('.hm-editor-poly').length == 0) {
                self.eventSpotId = $(e.target).data('id') || $(e.target).closest('.hm-hotspot').data('id');
                self.startedSelecting = true;
                return;
            }
        }

        // === Create spots

        // === If the event is outside canvas, ignore
        if (e.pageX > self.canvas.offset().left && e.pageX < self.canvasWidth + self.canvas.offset().left && e.pageY > self.canvas.offset().top && e.pageY < self.canvasHeight + self.canvas.offset().top) {
            // Spot tool
            if (settings.editor.tool == 'spot') {
                self.startedDrawingSpot = true;
                return;
            }

            // Rect tool
            if (settings.editor.tool == 'rect') {
                self.startedDrawingRect = true;
                return;
            }

            // Ellipse tool
            if (settings.editor.tool == 'oval') {
                self.startedDrawingOval = true;
                return;
            }

            // Poly tool
            if (settings.editor.tool == 'poly') {
                self.startedDrawingPoly = true;

                // deselect and redraw
                self.deselectSpot();
                self.redraw();

                // create a temp array of points
                self.polyPoints = new Array();

                // create a temp poly
                $('#hm-editor-hotspots-container').append('<svg id="temp-poly" width="'+ self.canvasWidth +'px" height="'+ self.canvasHeight +'px" viewBox="0 0 '+ self.canvasWidth +' '+ self.canvasHeight +'" version="1.1" xmlns="http://www.w3.org/2000/svg"></svg>')

                // place the first point
                self.placePointForTempPoly(self.ix, self.iy);
                self.redrawTempPoly();
                self.mouseDownWhileDrawingPoly = true;

                self.drawingPoly = true;
                return;
            }
        }

        // If nothing else, deselect spot
        self.deselectSpot();
        self.redraw();
        self.addAction();
    }
    Editor.prototype.handleMouseMove = function(e) {
        var self = this;

        // === If preview mode, return
        if (parseInt(settings.editor.previewMode, 10) == 1) return;

        var point = screenToCanvasSpace(e.pageX, e.pageY, self.canvas);

        self.x = point.x;
        self.y = point.y;

        self.dx = ((self.x - self.ix)/self.canvasWidth) * 100;
        self.dy = ((self.y - self.iy)/self.canvasHeight) * 100;

        self.dx = Math.round(self.dx * 10) / 10;
        self.dy = Math.round(self.dy * 10) / 10;

        // Select
        if (self.startedSelecting) {
            self.selectSpot(self.eventSpotId);
            self.redrawEl = $('.hm-hotspot[data-id="'+ self.eventSpotId +'"]');

            // Manually select the spot
            self.redrawSpotSelection();

            self.startedMoving = true;
        }

        // Move
        if (self.startedMoving) {
            var c = limitToCanvas(self.selectedSpot.x + self.dx, self.selectedSpot.y + self.dy);


            if (self.selectedSpot.type == 'rect' || self.selectedSpot.type == 'oval' || self.selectedSpot.type == 'poly') {
                if (c.x + self.selectedSpot.width > 100) {
                    c.x = 100 - self.selectedSpot.width;
                }
                if (c.y + self.selectedSpot.height > 100) {
                    c.y = 100 - self.selectedSpot.height;
                }
            }

            self.redrawEl.css({
                left: c.x + '%',
                top: c.y + '%'
            });

            return;
        }

        // Transform
        if (self.startedTransforming) {
            var c, d;

            if (self.transformDirection == 1) {
                c = { x: self.selectedSpot.x + self.dx, y: self.selectedSpot.y + self.dy };
                d = { x: self.selectedSpot.width - self.dx, y: self.selectedSpot.height - self.dy };
            }
            if (self.transformDirection == 2) {
                c = { x: self.selectedSpot.x, y: self.selectedSpot.y + self.dy };
                d = { x: self.selectedSpot.width, y: self.selectedSpot.height - self.dy };
            }
            if (self.transformDirection == 3) {
                c = { x: self.selectedSpot.x, y: self.selectedSpot.y + self.dy };
                d = { x: self.selectedSpot.width + self.dx, y: self.selectedSpot.height - self.dy };
            }
            if (self.transformDirection == 4) {
                c = { x: self.selectedSpot.x, y: self.selectedSpot.y };
                d = { x: self.selectedSpot.width + self.dx, y: self.selectedSpot.height };
            }
            if (self.transformDirection == 5) {
                c = { x: self.selectedSpot.x, y: self.selectedSpot.y };
                d = { x: self.selectedSpot.width + self.dx, y: self.selectedSpot.height + self.dy };
            }
            if (self.transformDirection == 6) {
                c = { x: self.selectedSpot.x, y: self.selectedSpot.y };
                d = { x: self.selectedSpot.width, y: self.selectedSpot.height + self.dy };
            }
            if (self.transformDirection == 7) {
                c = { x: self.selectedSpot.x + self.dx, y: self.selectedSpot.y };
                d = { x: self.selectedSpot.width - self.dx, y: self.selectedSpot.height + self.dy };
            }
            if (self.transformDirection == 8) {
                c = { x: self.selectedSpot.x + self.dx, y: self.selectedSpot.y };
                d = { x: self.selectedSpot.width - self.dx, y: self.selectedSpot.height };
            }

            // Canvas bounds
            if (c.x < 0) {
                d.x = self.selectedSpot.x + self.selectedSpot.width;
                c.x = 0;
            }
            if (c.y < 0) {
                c.y = 0;
                d.y = self.selectedSpot.y + self.selectedSpot.height;
            }
            if (d.x + c.x > 100) d.x = 100 - c.x;
            if (d.y + c.y > 100) d.y = 100 - c.y;

            // Negative width/height
            if (c.x > self.selectedSpot.x + self.selectedSpot.width) c.x = self.selectedSpot.x + self.selectedSpot.width;
            if (c.y > self.selectedSpot.y + self.selectedSpot.height) c.y = self.selectedSpot.y + self.selectedSpot.height;
            if (d.x < 0) d.x = 0;
            if (d.y < 0) d.y = 0;

            self.transformX = c.x;
            self.transformY = c.y;
            self.transformWidth = d.x;
            self.transformHeight = d.y;

            self.redrawEl.css({
                left: c.x + '%',
                top: c.y + '%',
                width: d.x + '%',
                height: d.y + '%'
            });

            // Update the SVG viewbox property
            if (self.selectedSpot.type == 'poly') {
                var shapeWidthPx = settings.general.width * (d.x/100);
                var shapeHeightPx = settings.general.height * (d.y/100);
                self.redrawSvgEl[0].setAttribute('viewBox', '0 0 ' + shapeWidthPx + ' ' + shapeHeightPx);

                // Redraw the shape
                var coords = '';
                for (var j=0; j<self.selectedSpot.points.length; j++) {
                    var p = self.selectedSpot.points[j];
                    var x = self.selectedSpot.default_style.stroke_width + (p.x/100) * (shapeWidthPx - self.selectedSpot.default_style.stroke_width*2);
                    var y = self.selectedSpot.default_style.stroke_width + (p.y/100) * (shapeHeightPx - self.selectedSpot.default_style.stroke_width*2);
                    coords += x +','+ y +' ';
                }

                self.redrawPolygonEl.attr('points', coords);
            }


            return;
        }

        // Draw rect
        if (self.startedDrawingRect) {
            var point = screenToCanvasSpace(e.pageX, e.pageY, self.canvas);

            if (!self.createdDrawingRect) {
                self.createdDrawingRect = true;

                // create a rect
                self.eventSpot = self.createRect();

                // set position
                self.eventSpot.x = (self.x/self.canvasWidth)*100;
                self.eventSpot.y = (self.y/self.canvasHeight)*100;

                self.eventSpot.x = Math.round(self.eventSpot.x * 10)/10;
                self.eventSpot.y = Math.round(self.eventSpot.y * 10)/10;

                // redraw once
                self.redraw();

                self.redrawEl = $('.hm-hotspot[data-id="'+ self.eventSpot.id +'"]');
            }

            // fast redraw rect
            var d = { x: self.dx, y: self.dy };

            if (self.eventSpot.x + d.x > 100) {
                d.x = 100 - self.eventSpot.x;
            }
            if (self.eventSpot.y + d.y > 100) {
                d.y = 100 - self.eventSpot.y;
            }

            self.drawRectWidth = d.x;
            self.drawRectHeight = d.y;

            self.redrawEl.css({
                width: d.x + '%',
                height: d.y + '%'
            });

            return;
        }

        // Draw oval
        if (self.startedDrawingOval) {
            var point = screenToCanvasSpace(e.pageX, e.pageY, self.canvas);

            if (!self.createdDrawingOval) {
                self.createdDrawingOval = true;

                // create a rect
                self.eventSpot = self.createOval();

                // set position
                self.eventSpot.x = (self.x/self.canvasWidth)*100;
                self.eventSpot.y = (self.y/self.canvasHeight)*100;

                self.eventSpot.x = Math.round(self.eventSpot.x * 10)/10;
                self.eventSpot.y = Math.round(self.eventSpot.y * 10)/10;

                // redraw once
                self.redraw();

                self.redrawEl = $('.hm-hotspot[data-id="'+ self.eventSpot.id +'"]');
            }

            // fast redraw rect
            var d = { x: self.dx, y: self.dy };

            if (self.eventSpot.x + d.x > 100) {
                d.x = 100 - self.eventSpot.x;
            }
            if (self.eventSpot.y + d.y > 100) {
                d.y = 100 - self.eventSpot.y;
            }

            self.drawRectWidth = d.x;
            self.drawRectHeight = d.y;

            self.redrawEl.css({
                width: d.x + '%',
                height: d.y + '%'
            });

            return;
        }

        // Draw poly
        if (self.mouseDownWhileDrawingPoly) {
            self.polyPoints[self.polyPoints.length - 1].x = self.x;
            self.polyPoints[self.polyPoints.length - 1].y = self.y;

            self.redrawTempPoly();

            return;
        }

        // Move control point
        if (self.translatingControlPoint) {
            // Scale up the SVG and redraw the points
            if (!self.startedTranslatingControlPoint) {
                self.startedTranslatingControlPoint = true;

                // Hide transform boxes
                $(e.target).closest('.hm-hotspot').find('.hm-selection').hide();

                // Scale up the hotspot
                $(e.target).closest('.hm-hotspot').css({
                    left: 0,
                    top: 0,
                    width: '100%',
                    height: '100%'
                });

                // Change the SVG viewbox
                $(e.target).closest('.hm-hotspot').find('.hm-editor-poly-svg')[0].setAttribute('viewBox', '0 0 ' + settings.general.width + ' ' + settings.general.height);

                // Redraw the control points
                for (var i=0; i<self.selectedSpot.points.length; i++) {
                    $('.hm-hotspot[data-id="'+ self.selectedSpot.id +'"]').find('.hm-poly-control-point[data-index="'+ i +'"]').css({
                        left: relLocalToRelCanvasSpace(self.selectedSpot.points[i], self.selectedSpot).x + '%',
                        top: relLocalToRelCanvasSpace(self.selectedSpot.points[i], self.selectedSpot).y + '%'
                    });
                }
            }

            // Limit to canvas bounds
            if (relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).x + self.dx < 0) {
                self.dx = -relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).x;
            }
            if (relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).x + self.dx > 100) {
                self.dx = 100 - relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).x;
            }
            if (relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).y + self.dy < 0) {
                self.dy = -relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).y;
            }
            if (relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).y + self.dy > 100) {
                self.dy = 100 - relLocalToRelCanvasSpace({x: self.translatedPointX, y: self.translatedPointY}, self.selectedSpot).y;
            }

            // convert self.dx from canvas rel. to poly rel.
            var dx = self.dx / (((self.selectedSpot.width/100)*self.canvasWidth)/self.canvasWidth);
            var dy = self.dy / (((self.selectedSpot.height/100)*self.canvasHeight)/self.canvasHeight);

            // Update the coordinates of the translated point
            self.selectedSpot.points[self.translatedPointIndex].x = self.translatedPointX + dx;
            self.selectedSpot.points[self.translatedPointIndex].y = self.translatedPointY + dy;

            // Redraw the control point
            self.translatedPoint.css({
                left: relLocalToRelCanvasSpace(self.selectedSpot.points[self.translatedPointIndex], self.selectedSpot).x + '%',
                top: relLocalToRelCanvasSpace(self.selectedSpot.points[self.translatedPointIndex], self.selectedSpot).y + '%',
            });

            // Redraw the polygon shape
            var coords = '';
            for (var j=0; j<self.selectedSpot.points.length; j++) {
                var p = relLocalToRelCanvasSpace(self.selectedSpot.points[j], self.selectedSpot);
                var x = self.selectedSpot.default_style.stroke_width + (p.x/100) * (settings.general.width - self.selectedSpot.default_style.stroke_width*2);
                var y = self.selectedSpot.default_style.stroke_width + (p.y/100) * (settings.general.height - self.selectedSpot.default_style.stroke_width*2);
                // var x = (p.x/100) * (settings.general.width);
                // var y = (p.y/100) * (settings.general.height);
                coords += x +','+ y +' ';
            }

            self.redrawPolygonEl.attr('points', coords);

            return;
        }

        // Place temporary control point
        if (self.selectedSpot && self.selectedSpot.type == 'poly') {
            self.redrawSelectedPolyTempPoint();
            return;
        }
    }
    Editor.prototype.handleMouseUp = function(e) {
        var self = this;

        // === If preview mode, return
        if (parseInt(settings.editor.previewMode, 10) == 1) return;

        if (self.startedDrawingSpot) {
            // Draw spot
            var s = self.createSpot();
            s.x = (self.ix/self.canvasWidth)*100;
            s.y = (self.iy/self.canvasHeight)*100;

            s.x = Math.round(s.x * 10)/10;
            s.y = Math.round(s.y * 10)/10;

            self.selectSpot(s.id);
            self.redraw();
            self.addAction();
        } else if (self.startedDrawingRect && self.createdDrawingRect) {
            // Draw rect
            var o = limitToCanvas(self.dx, self.dy);
            self.eventSpot.width = Math.round(self.drawRectWidth * 10)/10;
            self.eventSpot.height = Math.round(self.drawRectHeight * 10)/10;

            self.selectSpot(self.eventSpot.id);
            self.redraw();
            self.addAction();

            // Tips
            self.showTip('create rect', '<strong>Left-Click and drag</strong> the Rect shape to <strong>move</strong> it around, or drag any of the control points to <strong>resize</strong> it.');
        } else if (self.startedDrawingOval && self.createdDrawingOval) {
            // Draw oval
            var o = limitToCanvas(self.dx, self.dy);
            self.eventSpot.width = Math.round(self.drawRectWidth * 10)/10;
            self.eventSpot.height = Math.round(self.drawRectHeight * 10)/10;

            self.selectSpot(self.eventSpot.id);
            self.redraw();
            self.addAction();

            // Tips
            self.showTip('create rect', '<strong>Left-Click and drag</strong> the Ellipse shape to <strong>move</strong> it around, or drag any of the control points to <strong>resize</strong> it.');
        } else if (self.finishedDrawingPoly) {
            // Finish drawing poly

            // Delete temp poly
            $('#temp-poly').remove();

            // Create the final poly
            // Dimentions are created in the createPoly() function
            var p = self.createPoly(self.polyPoints);

            // Select it
            self.selectSpot(p.id);

            // Redraw
            self.addAction();
            self.redraw();

        } else if (self.startedMoving) {
            // Move
            var o = limitToCanvas(self.selectedSpot.x + self.dx, self.selectedSpot.y + self.dy);

            if (self.selectedSpot.type == 'rect' || self.selectedSpot.type == 'oval' || self.selectedSpot.type == 'poly') {
                if (o.x + self.selectedSpot.width > 100) {
                    o.x = 100 - self.selectedSpot.width;
                }
                if (o.y + self.selectedSpot.height > 100) {
                    o.y = 100 - self.selectedSpot.height;
                }
            }

            self.selectedSpot.x = Math.round(o.x * 10)/10;
            self.selectedSpot.y = Math.round(o.y * 10)/10;

            self.redraw();
            self.addAction();

        } else if (self.startedTransforming) {
            // Transform
            self.selectedSpot.x = Math.round(self.transformX * 10)/10;
            self.selectedSpot.y = Math.round(self.transformY * 10)/10;
            self.selectedSpot.width = Math.round(self.transformWidth * 10)/10;
            self.selectedSpot.height = Math.round(self.transformHeight * 10)/10;

            self.redraw();
            self.addAction();

        } else if (self.translatingControlPoint) {
            var dx = self.dx / (((self.selectedSpot.width/100)*self.canvasWidth)/self.canvasWidth);
            var dy = self.dy / (((self.selectedSpot.height/100)*self.canvasHeight)/self.canvasHeight);

            // Update the bounding box of the poly
            self.updateBoundingBoxForPolygonSpot(self.selectedSpot);

            self.redraw();
            self.addAction();
        } else if (self.startedSelecting) {
            // Select
            if (self.selectedSpot && self.selectedSpot.id != self.eventSpotId) {
                self.deselectSpot();
            }
            self.selectSpot(self.eventSpotId);

            self.redraw();
            self.addAction();
        } else if (self.shouldDeselectSpot) {
            self.deselectSpot();
            self.redraw();
            self.addAction();
        }

        // Reset flags
        self.startedSelecting = false;
        self.startedMoving = false;
        self.startedTransforming = false;
        self.transformDirection = 0;

        self.startedDrawingSpot = false;

        self.startedDrawingRect = false;
        self.createdDrawingRect = false;

        self.startedDrawingOval = false;
        self.createdDrawingOval = false;

        self.startedDrawingPoly = false;
        self.finishedDrawingPoly = false;
        self.mouseDownWhileDrawingPoly = false;

        self.translatingControlPoint = false;
        self.startedTranslatingControlPoint = false;

        self.shouldDeselectSpot = false;
    }

    Editor.prototype.getIndexOfSpotWithId = function(id) {
        for (var i=0; i<settings.spots.length; i++) {
            if (settings.spots[i].id == id) {
                return i;
            }
        }
    }
    Editor.prototype.selectSpot = function(id) {
        settings.editor.selected_hotspot = id;
    }
    Editor.prototype.deselectSpot = function() {
        settings.editor.selected_hotspot = -1;
    }

    Editor.prototype.createIdForSpot = function() {
        return 'spot-' + Math.floor(Math.random() * 9999);
    }
    Editor.prototype.createIdForRect = function() {
        return 'rect-' +  + Math.floor(Math.random() * 9999);
    }
    Editor.prototype.createIdForOval = function() {
        return 'oval-' +  + Math.floor(Math.random() * 9999);
    }
    Editor.prototype.createIdForPoly = function() {
        return 'poly-' +  + Math.floor(Math.random() * 9999);
    }

    Editor.prototype.createSpot = function() {
        var self = this;

        var s = $.extend(true, {}, default_spot_settings);
        s.type = 'spot';
        s.id = self.createIdForSpot();

        settings.spots.push(s);

        // Tour
        self.tourSteps['draw a spot']();

        // Tip
        self.showTip('spot tool', '<strong>Left-Click and drag</strong> the Spot shape to <strong>move</strong> it.');

        return s;
    }
    Editor.prototype.createRect = function() {
        var self = this;

        var s = $.extend(true, {}, default_spot_settings);
        s.type = 'rect';
        s.default_style.border_radius = 10;
        s.mouseover_style.border_radius = 10;
        s.id = self.createIdForRect();

        settings.spots.push(s);

        return s;
    }
    Editor.prototype.createOval = function() {
        var self = this;

        var s = $.extend(true, {}, default_spot_settings);
        s.type = 'oval';
        s.id = self.createIdForOval();

        settings.spots.push(s);

        return s;
    }
    Editor.prototype.createPoly = function() {
        var self = this;

        var s = $.extend(true, {}, default_spot_settings);
        s.type = 'poly';
        s.id = self.createIdForPoly();

        // Set dimentions
        var minX=99999, minY=99999, maxX=0, maxY=0;
        for (var i=0; i<self.polyPoints.length; i++) {
            var p = self.polyPoints[i];

            if (p.x < minX) minX = p.x;
            if (p.x > maxX) maxX = p.x;
            if (p.y < minY) minY = p.y;
            if (p.y > maxY) maxY = p.y;
        }

        var pixelWidth = maxX - minX;
        var pixelHeight = maxY - minY;

        // percentage, relative to the canvas width/height
        s.x = (minX/self.canvasWidth)*100;
        s.y = (minY/self.canvasHeight)*100;
        s.width = (pixelWidth/self.canvasWidth)*100;
        s.height = (pixelHeight/self.canvasHeight)*100;

        for (var i=0; i<self.polyPoints.length; i++) {
            // coordinates are in percentage, relative to the current pixel dimentions of the hotspot box
            s.points.push({
                x: ((self.polyPoints[i].x - minX)/pixelWidth)*100,
                y: ((self.polyPoints[i].y - minY)/pixelHeight)*100
            });
        }

        settings.spots.push(s);

        // Tour
        self.tourSteps['draw a poly']();

        // Tips
        self.showTip('created poly', '<strong>Left-Click and drag</strong> a control point to move it, or <strong>Left-Click on an edge</strong> (and drag) to create a new control point. <strong>Right-Click</strong> on a control point to remove it.');

        return s;
    }

    Editor.prototype.shouldSelectPoly = function(id) {
        var self = this;
        var s;

        for (var i=0; i<settings.spots.length; i++) {
            if (settings.spots[i].id == id) {
                s = settings.spots[i];
            }
        }

        // Coordinates in hotspot pixel space
        var x = self.ix - (s.x/100)*self.canvasWidth;
        var y = self.iy - (s.y/100)*self.canvasHeight;

        // Spot dimentions in pixels
        var spotWidth = (s.width/100)*self.canvasWidth;
        var spotHeight = (s.height/100)*self.canvasHeight;

        // Convert to hotspot percentage space
        x = (x / spotWidth) * 100;
        y = (y / spotHeight) * 100;

        var testPoly = new Array();
        for (var i=0; i<s.points.length; i++) {
            testPoly.push([s.points[i].x, s.points[i].y]);
        }

        if (isPointInsidePolygon({ x: x, y: y }, testPoly)) {
            return true;
        } else {
            return false;
        }
    }
    Editor.prototype.placePointForTempPoly = function(x, y) {
        var self = this;

        self.polyPoints.push({
            x: x,
            y: y
        });
    }
    Editor.prototype.redrawTempPoly = function() {
        var self = this;

        // Draw polygon
        var html = '<polygon points="'
        for (var i=0; i<self.polyPoints.length; i++) {
            html += self.polyPoints[i].x + ',' + self.polyPoints[i].y + ' ';
        }
        html += '" />';

        // Draw points

        for (var i=0; i<self.polyPoints.length; i++) {
            html += '<circle cx="'+ self.polyPoints[i].x +'" cy="'+ self.polyPoints[i].y +'" r="4" data-index="'+ i +'" />';
        }

        // Insert HTML
        $('#temp-poly').html(html);
    }
    Editor.prototype.redrawSelectedPolyTempPoint = function() {
        var self = this;

        // Convert canvas space pixel coordinates to percentage space polygon space
        var polygonPixelWidth = (self.selectedSpot.width/100)*self.canvasWidth;
        var polygonPixelHeight = (self.selectedSpot.height/100)*self.canvasHeight;
        var xPolygonPixelSpace = self.x - ((self.selectedSpot.x/100) * self.canvasWidth);
        var yPolygonPixelSpace = self.y - ((self.selectedSpot.y/100) * self.canvasHeight);
        var xPolygonPerSpace = (xPolygonPixelSpace/polygonPixelWidth) * 100;
        var yPolygonPerSpace = (yPolygonPixelSpace/polygonPixelHeight) * 100;

        var p;
        if (p = self.shouldShowTempControlPoint(xPolygonPerSpace, yPolygonPerSpace, self.selectedSpot.points)) {
            // Show
            self.tempControlPoint.show();
            self.tempControlPointLine.show();

            self.tempControlPoint.css({
                left: p.x + '%',
                top: p.y + '%'
            });

            self.controlPointInsertionPointX = p.x;
            self.controlPointInsertionPointY = p.y;
        } else {
            // Hide
            self.tempControlPoint.hide();
            self.tempControlPointLine.hide();
        }
    }
    Editor.prototype.shouldShowTempControlPoint = function(x, y, points) {
        var self = this;
        var p1 = { x: x, y: y };

        // Test for each line
        for (var i=0; i<points.length; i++) {
            var p2 = { x: points[i].x, y: points[i].y };
            var p3 = undefined;

            if (points[i+1]) {
                p3 = { x: points[i+1].x, y: points[i+1].y };
            } else {
                p3 = { x: points[0].x, y: points[0].y };
            }

            var t = pointLineSegmentParameter([p1.x, p1.y], [p2.x, p2.y], [p3.x, p3.y]);
            var d = distanceFromLineToPoint(p2.x, p2.y, p3.x, p3.y, p1.x, p1.y);

            var x10 = p3.x - p2.x;
            var y10 = p3.y - p2.y;

            if (Math.abs(t - 0.5) < 0.45 && d < 5) {
                self.tempControlPointIndex = i;
                return { x: p2.x + t * x10, y: p2.y + t * y10};
            }
        }

        return false;
    }
    Editor.prototype.updateBoundingBoxForPolygonSpot = function(s) {
        var minX=99999, minY=99999, maxX=-99999, maxY=-99999;
        for (var i=0; i<s.points.length; i++) {
            var p = s.points[i];

            if (p.x < minX) minX = p.x;
            if (p.x > maxX) maxX = p.x;
            if (p.y < minY) minY = p.y;
            if (p.y > maxY) maxY = p.y;
        }

        // Calculate new bounding box
        var o = relLocalToRelCanvasSpace({ x: minX, y: minY }, s);
        var o2 = relLocalToRelCanvasSpace({ x: maxX, y: maxY }, s);

        // Update the coordinates of the points
        for (var i=0; i<s.points.length; i++) {
            var p = s.points[i];

            // to canvas space
            var p1 = relLocalToRelCanvasSpace(p, s);
            // to local space
            var p2 = relCanvasToRelLocalSpace(p1, { x: o.x, y: o.y, width: o2.x - o.x, height: o2.y - o.y });
            // debugger;
            p.x = p2.x;
            p.y = p2.y;
        }

        // Set new values
        s.x = o.x;
        s.y = o.y;
        s.width = o2.x - o.x;
        s.height = o2.y - o.y;

        // debugger;
    }

    Editor.prototype.showTip = function(name, text) {
        try {
            var storage = window['localStorage'],
            x = '__storage_test__';
            storage.setItem(x, x);
            storage.removeItem(x);
            supported = true;
        }
        catch(e) {
            console.log('Local storage is NOT supported!');
            supported = false;
        }

        // If the guided tour
        if (this.tour && !this.tour.ended) return;

        if (supported && localStorage[name] == 1) {
            return;
        } else {
            localStorage[name] = 1;
        }

        // Show
        $('#hm-editor-tips-container').addClass('hm-tips-visible');
        $('#hm-tip-content').html(text);
    }

    function Form(parent) {
        this.parent = parent;
        this.fields = new Array();
        this.settings = undefined;
    }
    Form.prototype.addField = function(name, group, type, id) {
        this.fields.push({
            name: name,
            group: group,
            type: type,
            id: id
        });
    }
    Form.prototype.init = function(settings) {
        var self = this;

        self.settings = settings;

        self.loadSettings();

        // set events
        for (var i=0; i<self.fields.length; i++) {
            if (self.fields[i].type == 'button group') {
                for (var j=0; j<self.fields[i].id.length; j++) {
                    $(document).off('click', self.fields[i].id[j]);
                    $(document).on('click', self.fields[i].id[j], function() {
                        $(this).siblings().removeClass('active');
                        $(this).addClass('active');

                        self.updateSettings();
                        self.parent.settingsUpdated($(this).attr('id'));
                    });
                }
                continue;
            }

            $(document).off('change', self.fields[i].id);
            $(document).on('change', self.fields[i].id, function() {
                self.updateSettings();
                self.parent.settingsUpdated($(this).attr('id'));
            });
        }
    }
    Form.prototype.loadSettings = function() {
        for (var i=0; i<this.fields.length; i++) {
            var field = this.fields[i];
            var val = 0;

            if (field.group) {
                val = this.settings[field.group][field.name];
            } else {
                val = this.settings[field.name];
            }

            if (field.type == 'int') {
                $(field.id).val(parseInt(val, 10));
            }
            if (field.type == 'float') {
                $(field.id).val(parseFloat(val));
            }
            if (field.type == 'text' || field.type == 'select') {
                $(field.id).val(val);
            }
            if (field.type == 'checkbox') {
                if (parseInt(val, 10) == 1) {
                    $(field.id).get(0).checked = true;
                } else {
                    $(field.id).get(0).checked = false;
                }
            }
            if (field.type == 'button group') {
                for (var j=0; j<field.id.length; j++) {
                    if ($(field.id[j]).data('val') == val) {
                        $(field.id[j]).addClass('active');
                    } else {
                        $(field.id[j]).removeClass('active');
                    }
                }
            }
        }
    }
    Form.prototype.updateSettings = function() {
        for (var i=0; i<this.fields.length; i++) {
            var field = this.fields[i];
            var val = 0;

            if (field.type == 'int') {
                val = parseInt($(field.id).val(), 10);
            }
            if (field.type == 'float') {
                val = parseFloat($(field.id).val());
            }
            if (field.type == 'text' || field.type == 'select') {
                val = $(field.id).val();
            }
            if (field.type == 'checkbox') {
                if ($(field.id).get(0).checked) {
                    val = 1;
                } else {
                    val = 0;
                }
            }
            if (field.type == 'button group') {
                for (var j=0; j<field.id.length; j++) {
                    if ($(field.id[j]).hasClass('active')) {
                        val = $(field.id[j]).data('val');
                    }
                }
            }

            if (field.group) {
                this.settings[field.group][field.name] = val;
            } else {
                this.settings[field.name] = val;
            }
        }
    }

    function loadImage(image, cbLoading, cbComplete) {
        if (!image.complete || image.naturalWidth === undefined || image.naturalHeight === undefined) {
            cbLoading();
            $(image).on('load', function() {
                $(image).off('load');
                cbComplete();
            });
        } else {
            cbComplete();
        }
    }

    function abs_to_rel(val, min, max) {
        return ((min + max) / val) * 100;
    }
    function rel_to_abs(val, min, max) {
        return ((min + max) * val) * 100;
    }
    function screenToCanvasSpace(x, y, canvas) {
        return {
            x: Math.round((x - canvas.offset().left)*10)/10,
            y: Math.round((y - canvas.offset().top)*10)/10
        }
    }
    function relLocalToRelCanvasSpace(p, localSpace) {
        return {
            x: (localSpace.width)*(p.x / 100) + localSpace.x,
            y: (localSpace.height)*(p.y / 100) + localSpace.y
        }
    }
    function relCanvasToRelLocalSpace(p, localSpace) {
        return {
            x: ((p.x - localSpace.x)/(localSpace.width))*100,
            y: ((p.y - localSpace.y)/(localSpace.height))*100
        }
    }

    function limitToCanvas(x, y) {
        if (x < 0) x = 0;
        if (x > 100) x = 100;
        if (y < 0) y = 0;
        if (y > 100) y = 100;

        return {
            x: Math.round(x*10)/10,
            y: Math.round(y*10)/10
        }
    }
    function isPointInsidePolygon(point, vs) {
        // ray-casting algorithm based on
        // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html

        var x = point.x, y = point.y;

        var inside = false;
        for (var i = 0, j = vs.length - 1; i < vs.length; j = i++) {
            var xi = vs[i][0], yi = vs[i][1];
            var xj = vs[j][0], yj = vs[j][1];

            var intersect = ((yi > y) != (yj > y))
            && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
            if (intersect) inside = !inside;
        }

        return inside;
    }
    function distanceFromLineToPoint(lx1, ly1, lx2, ly2, px, py) {
        return Math.abs((ly2 - ly1)*px - (lx2 - lx1)*py + lx2*ly1 - ly2*lx1)/(Math.sqrt(Math.pow(ly2 - ly1, 2) + Math.pow(lx2 - lx1, 2)));
    }
    function pointLineSegmentParameter(p2, p0, p1) { // p0, p1 - line
        var x10 = p1[0] - p0[0], y10 = p1[1] - p0[1],
        x20 = p2[0] - p0[0], y20 = p2[1] - p0[1];
        return (x20 * x10 + y20 * y10) / (x10 * x10 + y10 * y10);
    }

})( jQuery, window, document );
