module.exports = function(grunt) {

	/**
	 * Evergreen Website Gruntfile
	 *
	 * For telling the computer what to do to streamline redundant tasks
	 * when preparing files for Evergreen’s primary website.
	 *
	 * For more information on what this does and how to set it up, see
	 * smb://hurricane/communications/webteam/documentation/Grunt.docx
	 */
	
	// Project configuration.
	grunt.initConfig({
		pkg: grunt.file.readJSON('package.json'),
		
		/**
		 * Concatenate files.
		 */
		concat: {
			scripts: {
				options: {
					separator: ';',
				},
				src: ['js/src/events.js', 'js/src/scripts.js'],
				dest: 'js/build/scripts-dev.js',
			},
			illiad: {
				src: ['css/dist/styles.css', 'css/dist/custom-css/illiad.css'],
				dest: 'css/dist/custom-css/illiad-concat.css',
			}
		},
		
		/**
		 * Copy files from one directory to another.
		 */
		copy: {
			js_init_to_dist:{
				files: [
					{
						expand: true,
						flatten: true,  // Only copies the file, not the folder structure, too
						src: ['js/src/init/*'],
						dest: 'js/dist/init',
						filter: 'isFile',  // Make sure it's a file, not a directory or something else (I think)
					}
				],
			},
			to_local: {
			  files: [
				  {
					  cwd: 'css/dist/',
					  expand: true,
					  src: ['**'],
			      dest: '../../../devdesktop/drupal-7.53/sites/all/themes/wwwevergreen/css/dist/',
					},
				],
			},
		  to_banner_themes: {
			  files: [
				  {
					  expand: true,
					  flatten: true,  // Only copies the file, not the folder structure, too
			      src: ['css/src/_tools.scss'],
			      dest: '../../../banner-themes/css/src/',
			      filter: 'isFile',  // Make sure it's a file, not a directory or something else (I think)
		      },
		      
					/*{
						expand: true,
						cwd: 'css/dist/',
						src: 'styles.css',
						dest: '../www-drupal/themes/wwwevergreen/css/dist/',
						//rename: function(dest){
							//return dest + 'screen.css';
						//},
						filter: 'isFile',	 // Make sure it's a file, not a directory or something else (I think)
					},*/
					
					/*// includes files within path
					{expand: true, src: ['path/*'], dest: 'dest/', filter: 'isFile'},
					
					// includes files within path and its sub-directories
					{expand: true, src: ['path/**'], dest: 'dest/'},
					
					// makes all src relative to cwd
					{expand: true, cwd: 'path/', src: ['**'], dest: 'dest/'},
					
					// flattens results to a single level
					{expand: true, flatten: true, src: ['path/**'], dest: 'dest/', filter: 'isFile'},*/
		    ],
		  },
		},
		
		imagemin: {                          // Task
			dynamic: {                         // Another target
				options: {
					optimizationLevel: 7,
					progressive: true
				},
				files: [{
					expand: true,                  // Enable dynamic expansion
					cwd: 'images/src/',            // Src matches are relative to this path
					src: ['**/*.{png,jpg,gif}'],   // Actual patterns to match
					dest: 'images/build/'          // Destination path prefix
				}]
			}
	  },
		
		imageoptim: {
			optimizeDefaultSrc: {
				src: ['../../../evergreen-edu/imageoptim/src'],
			},
		},
		
		/**
		 * Give hints on fixing bugs in JavaScript.
		 */
		jshint: {
			Gruntfile: ['Gruntfile.js'],
			scripts: ['js/src/*.js']
		},
		
		/**
		 * Perfbudget
		 *
		 * Performance budgeting thanks to the magic of WebPageTest
		 * See: https://github.com/tkadlec/grunt-perfbudget
		 *
		 * grunt-perfbudget is a Grunt.js task for enforcing a performance budget
		 * (more on performance budgets:
		 * http://timkadlec.com/2013/01/setting-a-performance-budget/). It uses
		 * the wonderful webpagetest.org and the WebPagetest API Wrapper for
		 * NodeJS created by Marcel Duran.
		 *
		 * grunt-perfbudget uses either a public or private instance of
		 * WebPagetest to perform tests on a specified URL. It compares test
		 * results to budgets you specify. If the budget is met, the tasks
		 * successfully completes. If it the page exceeds your performance
		 * budgets, the task fails and informs you why.
		 */
		perfbudget: {
			default: {
				options: {
					url: 'http://wwwdev.evergreen.edu',
					key: 'A.71de0f32f82a2c13f3ed1f862acb6548',
					location: 'ec2-us-west-2:Firefox',  // Oregon - EC2
					budget: {
						visualComplete: '4000',
						SpeedIndex: '1500',
					}
				}
			}
		},
		
		/**
		 * CSS post-processors
		 *
		 * autoprefixer adds support for older browsers by adding vendor
		 * prefixes to Sass properties, based on data from caniuse.com.
		 */
		postcss: {
	    options: {
		    processors: [
					require('autoprefixer')(  // add vendor prefixes
						{
							browsers: [
								'> 0.2% in US',
							]
						}
					),
					
					/**
					 * postcss-reporter
					 *
					 * Prints out warning and error messages from other PostCSS plugins.
					 *
					 * This plugin should go last to report warnings from all previous
					 * plugins.
					 */ 
					require('postcss-reporter')(
						{
							clearMessages: true,
						}
					),
				]
			},
			default_styles: {
				src: 'css/dist/styles.css',
				dest: 'css/dist/styles.css'
			},
			print_styles: {
				src: 'css/dist/print.css',
				dest: 'css/dist/print.css'
			},
			custom_css: {  // process a whole folder
				expand: true,
				flatten: true,
				src: 'css/dist/custom-css/*.css', // -> src/css/file1.css, src/css/file2.css
				dest: 'css/dist/custom-css/' // -> dest/css/file1.css, dest/css/file2.css
			},
			dev_styles: {
				src: 'css/build/styles-dev.css',
				dest: 'css/build/styles-dev.css'
			},
			r25_styles: {
				src: 'r25/r25.css',
				dest: 'r25/build/r25.css'
			}
		},
		
		realFavicon: {
			favicons: {
				src: 'images/favicons/src',
				dest: 'images/favicons/dist',
				options: {
					iconsPath: '<?php print base_path() . path_to_theme() ?>/images/favicons/dist/',
					html: [ 'images/favicons/dist/sample-markup.html' ],
					design: {
						ios: {
							pictureAspect: 'backgroundAndMargin',
							backgroundColor: '#44693d',
							margin: '14%',
							assets: {
								ios6AndPriorIcons: false,
								ios7AndLaterIcons: false,
								precomposedIcons: false,
								declareOnlyDefaultIcon: true
							},
							appName: 'Evergreen'
						},
						desktopBrowser: {},
						windows: {
							pictureAspect: 'whiteSilhouette',
							backgroundColor: '#44693d',
							onConflict: 'override',
							assets: {
								windows80Ie10Tile: false,
								windows10Ie11EdgeTiles: {
									small: true,
									medium: true,
									big: true,
									rectangle: true
								}
							},
							appName: 'Evergreen'
						},
						androidChrome: {
							pictureAspect: 'shadow',
							themeColor: '#44693d',
							manifest: {
								name: 'Evergreen',
								display: 'browser',
								orientation: 'notSet',
								onConflict: 'override',
								declared: true
							},
							assets: {
								legacyIcon: true,
								lowResolutionIcons: false
							}
						},
						safariPinnedTab: {
							pictureAspect: 'silhouette',
							themeColor: '#44693d'
						}
					},
					settings: {
						compression: 5,
						scalingAlgorithm: 'Lanczos',
						errorOnImageTooSmall: false,
						readmeFile: true,
						htmlCodeFile: true,
						usePathAsIs: false
					}
				}
			}
		},

		/**
		 * Process Sass into CSS.
		 */
		sass: {
			build: {  // process specific files
				options: {
					style: 'compressed', 
					sourcemap: 'none'
				},
				files: [
					{'css/dist/styles.css': 'css/src/styles.scss'},  // 'destination': 'source'
					{'css/dist/print.css': 'css/src/print.scss'},
					{                               // process this whole folder
						expand: true,
						cwd: 'css/src/custom-css',  // source folder
						src: ['*.scss'],
						dest: 'css/dist/custom-css',  // destination folder
						ext: '.css'
					},
				]
			},
			dev: {  // process specific files
				options: {
					lineNumbers: true,
					style: 'expanded',
					sourcemap: 'none'
				},
				files: [
					{'css/build/styles-dev.css': 'css/src/styles.scss'},  // 'destination': 'source'
					{'css/build/print.css': 'css/src/print.scss'},
					/*{                               // process this whole folder
						expand: true,
						cwd: 'custom-css/',
						src: ['*.scss'],
						dest: 'custom-css/',
						ext: '.css'
					}*/
				]
			},
		},
		
		/**
		 * Sasslint
		 *
		 * Tests Sass to make sure it's written in a standardized way.
		 * Configuration of these tests is located in a hidden file, documented
		 * in an option below.
		 */
		sasslint: {
			options: {
				configFile: 'css/config/.sass-lint.yml',
				formatter: 'html',
				outputFile: 'css/config/report.html',
			},
			target: ['css/src/*.scss', 'css/src/smacss/**/*.scss', 'css/src/custom-css/**/*.scss'],
    },
		
		/**
		 * Create spritesheets out of SVG files in a folder.
		 */
		svgstore: {
			options: {
				prefix : 'icon-', // This will prefix each ID
				svg: { // will add and overide the the default xmlns="http://www.w3.org/2000/svg" attribute to the resulting SVG
					//viewBox : '0 0 100 100',
					//xmlns: 'http://www.w3.org/2000/svg'
				},
				inheritviewbox: true,
			},
			transporter: {
				/*files: {
					'' : [''],  // dest : src
				}*/
				src: ['images/src/icons/transporter/*.svg'],
				dest: 'images/build/transporter.svg',
			},
		},
		/*svgsprite: {
			options: {
				//cleanwith: 'svgo',	//SVG optimizer
			},
			transporter: {
				src: ['images/src/icons'],
				dest: 'images/build/icons',
				options: {
					sprite: 'transporter',  //filename
				}
			},
	  },*/
    
    /**
     * Compress JS by removing whitespace. Different from
     * minification in that it doesn't replace variable and
     * function names, which is easier to debug.
     */
		uglify: {
			scripts_to_dist: {
				src: 'js/build/scripts-dev.js',
				dest: 'js/dist/scripts.min.js'
			},
		},

		/**
		 * Watch directories and execute Grunt tasks when they change.
		 */
		watch: {
			gruntfile: {  // Validate Gruntfile.
				files: 'Gruntfile.js',
				tasks: ['jshint'],
			},
			tools: {  // Copy latest version of _tools to Banner theme
				files: '_tools.scss',
				tasks: ['copy:to_banner_themes']
			},
			css: {  // Autoprefix, then process Sass into CSS.
				files: ['css/src/styles.scss', 'css/src/print.scss', 'css/src/smacss/**/*.scss', 'css/src/custom-css/*.scss'],
				//tasks: ['sass', 'postcss', 'copy:to_drupal'],
				tasks: ['sass', 'postcss'],
			},
			js: {  // Concatenate and uglify JavaScript.
				files: ['js/src/**/*.js'],
				tasks: ['jshint', 'newer:concat', 'newer:uglify', 'copy:js_init_to_dist'],
			},
		},
    
	});

	// Load the plugins (alphabetical order).
	grunt.loadNpmTasks('grunt-contrib-concat');
	grunt.loadNpmTasks('grunt-contrib-copy');
	grunt.loadNpmTasks('grunt-contrib-imagemin');
	grunt.loadNpmTasks('grunt-contrib-jshint');
	grunt.loadNpmTasks('grunt-contrib-sass');
	grunt.loadNpmTasks('grunt-contrib-uglify');
	grunt.loadNpmTasks('grunt-contrib-watch');
	grunt.loadNpmTasks('grunt-imageoptim');
	grunt.loadNpmTasks('grunt-newer');
	grunt.loadNpmTasks('grunt-postcss');
	grunt.loadNpmTasks('grunt-perfbudget');
	grunt.loadNpmTasks('grunt-real-favicon');
	grunt.loadNpmTasks('grunt-sass-lint');
	grunt.loadNpmTasks('grunt-svgstore');
	/*grunt.loadNpmTasks('grunt-svg-sprite');*/

	// Default task(s) (in the order you want to run them).
	grunt.registerTask('default', ['sass', 'postcss', 'newer:concat', 'newer:uglify', 'copy']);
	grunt.registerTask('scripts', ['newer:concat', 'newer:uglify', 'copy:js_init_to_dist']);

};