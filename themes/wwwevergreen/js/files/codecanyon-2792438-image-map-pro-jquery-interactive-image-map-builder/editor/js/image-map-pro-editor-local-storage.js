;(function ( $, window, document, undefined ) {
    var supported = false;

    $.editor_storage_get_saves = function(cb) {
        // localStorage.editor_saves = '[]';
        if (localStorage.editor_saves) {
            cb(JSON.parse(localStorage.editor_saves));
        } else {
            cb(new Array());
        }
    }
    $.editor_storage_store_save = function(save, cb) {
        if (!localStorage.editor_saves) {
            localStorage.editor_saves = '[]';
        }

        var currentSaves = JSON.parse(localStorage.editor_saves);
        var updated = false;
        for (var i=0; i<currentSaves.length; i++) {
            if (currentSaves[i].id == save.id) {
                updated = true;
                currentSaves[i] = save;
            }
        }
        if (!updated) {
            currentSaves.push(save);
        }

        localStorage.editor_saves = JSON.stringify(currentSaves);

        cb();
    }
    $.editor_storage_delete_save = function(index, cb) {
        if (!localStorage.editor_saves) {
            localStorage.editor_saves = '[]';
        }

        var currentSaves = JSON.parse(localStorage.editor_saves);
        currentSaves.splice(index, 1);

        localStorage.editor_saves = JSON.stringify(currentSaves);

        cb();
    }
    $.editor_storage_get_last_save = function(cb) {
        if (localStorage.last_save) {
            cb(JSON.parse(localStorage.last_save));
        } else {
            cb(false);
        }
    }
    $.editor_storage_set_last_save = function(save, cb) {
        localStorage.last_save = JSON.stringify(save);
        cb();
    }

    $(document).ready(function() {
        // Support check
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
    });
})( jQuery, window, document );
