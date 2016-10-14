$(document).ready(function(){
    $('#gallery-list').slick({
        accessibility: true,
        arrows: true,
        dots: true,
        infinite: false,
        mobileFirst: true,
        responsive: [
            {
                breakpoint: 1119,
                settings: {
                    slidesToShow: 2
                }
            }
        ]
    });
});