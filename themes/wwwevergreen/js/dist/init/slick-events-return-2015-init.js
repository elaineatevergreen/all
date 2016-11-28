jQuery(document).ready(function($){
    $('#event-slideshow').slick({
        accessibility: true,
        adaptiveHeight: true,
        arrows: true,
        centerMode: true,
        centerPadding: '3em',
        dots: false,
        infinite: false,
        lazyLoad: 'ondemand',
        mobileFirst: true
    });
});