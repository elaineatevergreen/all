$(document).ready(function() {
            Galleria.loadTheme('/inc/js/galleria/themes/classic/galleria.classic.min.js');
            //Galleria.run('.galleria');
Galleria.configure({
    lightbox: true
});
$('.galleria').galleria({
    _toggleInfo: false,
    extend: function(options) {
        Galleria.get(0).$('info-link').click();
    }
});
} );