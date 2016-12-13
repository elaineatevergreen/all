/**
 * id - the element that triggers the event
 * action - indicates 'click' or 'submit' event
 * linkLabel - keyword for tracking events on this element
 * linkInteraction - boolean; does clicking this link not nullify a bounce
 */
function recordEvent(id, action, linkLabel, linkInteraction){
	var elementID = document.getElementById(id);  // The element ID trigger
	//var hitCallback;  // link or form
	var timeout = 1000; // Wait no more than 1 second
	
	console.log('elementID = ' + elementID.id);
	if(elementID){
		elementID.addEventListener(action, function(event){
			console.log('Event listener for ' + elementID + ' added.');
			// Prevent link from firing or form from submitting right away.
			event.preventDefault();
			
			setTimeout(resumeAction, timeout);
			var actionFired = false;
			
			// Resume link navigation or form submission after it's been sent to Google Analytics (or timed out)
			function resumeAction(){
				if(!actionFired){
					actionFired = true;
					if(action == 'click'){
						console.log('Navigation from ' + elementID.id + ' to ' + elementID + ' begun.');
						window.location.href = elementID;
					} else if(action == 'submit'){
						console.log('The form ' + elementID.id + ' is being submitted.');
						elementID.submit();
					} else {
						console.log('We can’t track the event “' + event + '”. Use “click” or “submit” instead.');
					}
				} else {
					console.log('The action ' + action + ' failed to fire.');
				}
			}
			
			// Send the event to Google Analytics.
			ga('send', 'event', 'link', 'click', linkLabel, null, linkInteraction, {
				hitCallback: resumeAction
			});
		});
	} else {
		console.log('No element found with ID “' + id + '.”');
	}
}

document.addEventListener('DOMContentLoaded', function(event){
	
	console.log('DOMContentLoaded!');
	
	// Track a click from a link with id="test-id".
	//recordEvent('test-id', 'click', 'function-test', false);
	// Track a submission from a form with id="test-form".
	//recordEvent('test-form', 'submit', 'function-test', false);
	
	// Record clicks
	//recordEvent('virtual-tour-link', 'click', 'Virtual Tour', false);
	// Record submissions
	
});

/**
 * Trying again with class names instead of IDs.
 */

/*function recordEvent(className, action, linkLabel, linkInteraction){
	var elementClass = document.getElementsByClassName(className);  // The element ID trigger
	//var hitCallback;  // link or form
	
	//console.log('elementClass = ' + elementClass);
	for(var i = 0; i < elementClass.length; i++){
		console.log(elementClass[i]);
	}
	
	// Add event listeners to all elements matching the provided classname.
	if(elementClass){
		for(var j = 0; j < elementClass.length; j++){
			elementClass[j].addEventListener(action, recordAction);
		}
	} else {
		console.log('No element found with class “' + className + '.”');
	}
}

function recordAction(event){
	var timeout = 1000; // Wait no more than 1 second
	console.log('Event listeners for ' + this + ' added.');
	// Prevent link from firing or form from submitting right away.
	event.preventDefault();
	
	setTimeout(resumeAction, timeout);
	var actionFired = false;
	
	// Resume link navigation or form submission after it's been sent to Google Analytics (or timed out).
	function resumeAction(){
		if(!actionFired){
			actionFired = true;
			if(action == 'click'){
				console.log('Navigation from ' + elementClass.className + ' to ' + elementClass + ' begun.');
				window.location.href = elementClass;
			} else if(action == 'submit'){
				console.log('The form ' + elementClass.className + ' is being submitted.');
				elementClass.submit();
			} else {
				console.log('We can’t track the event “' + event + '”. Use “click” or “submit” instead.');
			}
		} else {
			console.log('The action ' + action + ' failed to fire.');
		}
	}
	
	// Send the event to Google Analytics.
	ga('send', 'event', 'link', 'click', linkLabel, null, linkInteraction, {
		hitCallback: resumeAction
	});
}

document.addEventListener('DOMContentLoaded', function(event){
	
	console.log('DOMContentLoaded!');
	
	// Track a click from a link with id="test-id".
	//recordEvent('test-id', 'click', 'function-test', false);
	recordEvent('test-class', 'click', 'function-test', false);
	// Track a submission from a form with id="test-form".
	recordEvent('test-form', 'submit', 'function-test', false);
	
	// Record clicks
	recordEvent('virtual-tour-link', 'click', 'Virtual Tour', false);
	// Record submissions
	
});*/;//var rem = 16;  // value of 1 root em
//var bWidth = document.documentElement.clientWidth; // Browser width
//var illusRotationRange = 2;  // How far in either direction an illustration can rotate, in degrees
var imageRotationMax = 2;
var imageRotationMin = 0.5;

/**
 * DOM is fully loaded; images and other pieces may not yet be
 */
jQuery(document).ready(function($){

	/**
	 * Simple Accordion
	 *
	 * Simple accordion without all the jQuery UI problems.
	 */
	var allPanels = $('.accordion > dd').hide();  //Hide all accordion panels, but...
	//console.log("Panels hidden.");
	var defaultPanel = $(".is-expanded").parent().next().show();  //Show default accordion panel
	$('.accordion > dt > a').click(function(event) {
	  event.preventDefault();
	  allPanels.slideUp();
	  if($(this).hasClass("is-expanded")){
	      allPanels.prev().children("a").removeClass("is-expanded");
	  } else {
	      allPanels.prev().children("a").removeClass("is-expanded");
	      $(this).addClass("is-expanded").parent().next().slideDown();
	  }
	  return false;
	});

	/**
	 * Fluid Media
	 * 
	 * Fluid multimedia with default embed codes (makes things easy for content owners)
	 * Adapted from Chris Coyier’s Fluid Width Video script
	 * See: http://css-tricks.com/NetMag/FluidWidthVideo/demo.php
	 */
	function fluidMedia(media){
	  media.each(function(){
		  //Get the width of the containing element
	    $dataWidth = $(this).parent().width();
	    $(this)
	      //jQuery .data does not work on object/embed elements
	      .attr('data-width', $dataWidth)  //Set the target width
	      .attr('data-aspectRatio', this.height / this.width);  //Set the video's aspect ratio
	    fluidMediaResize(media);
	  });
	}
	function fluidMediaResize(media){
	  media.each(function(){
	    var $el = $(this);
	    $el  //Set the height and width of the element
				.attr('data-width', $(this).parent().width())
				.width($el.attr('data-width'))
				.height($el.attr('data-width') * $el.attr('data-aspectRatio'));
	  });
	}
	
	/**
	 * Lazy Loading
	 * 
	 * Don’t load embedded YouTube content until user clicks on it.
	 */
	$(".lazy-load").click(function(e){
		e.preventDefault();  //Disable the link
		var src = $(this).attr("href").split("="),  //Get the unique video ID from the URL
	      width = $(this).width(),  //Get the dimensions of the current block for a seamless replacement
	      height = $(this).height(),
	      embededMedia = $("<iframe width='" + width + "' height='" + height + "' src='//www.youtube-nocookie.com/embed/" + src[1] + "?autohide=1&autoplay=1&rel=0' frameborder='0' allowfullscreen></iframe>");
	      //autohide hides the player controls, autoplay allows one-click video access, rel disables related content
		$(this).replaceWith(embededMedia);  //Replace the link with the video
	  $allVideos = $("iframe[src*='//player.vimeo'], iframe[src*='//www.youtube'], object, embed");  //Get all videos again (with new video added in)
	  fluidMedia(embededMedia);  //Make it fluid for responsiveness!
	});

	/**
	 * Random Rotation
	 * 
	 * Randomly rotate illustrations within a range.
	 */
	$("img[class|='image'], img[class|='illus']").each(function(index){
	  //var degN = Math.random() * (illusRotationRange * 2) - illusRotationRange;
	  var degN = Math.random() * (imageRotationMax - imageRotationMin) + imageRotationMin;  // Rotate within a range
	  if(Math.random() < 0.5) degN = degN * -1;  // Randomly rotate in the opposite direction
	  //console.log(index + ": " + degN + " degrees");
	  $(this).css("transform", "rotate(" + degN + "deg)");
	});
	
	/**
   * Run the fluidMedia function on all embeded content
   */
  window.$allVideos = $("iframe[src*='//player.vimeo'], iframe[src*='//www.youtube'], object, embed");  //Get all videos
  fluidMedia($allVideos);
	
	/**
	 * Window Resizing
	 */
	$(window).resize(function(){
		//setTertiaryNav();
		//Maintain aspect ratio during screen resizing
		fluidMediaResize($allVideos);
	});
});

/**
 * All content, including images, are fully loaded.
 */
// jQuery-free!
window.onload = function loadAfter() {
	/**
	 * New, jQuery-free image rotation (in progress)
	 */
	
	//console.log(document.getElementsByClassName(/^image.*/));
	/*function rotateImages(){
		var allImages = document.getElementsByClassName("image").getElementsByClassName("image-full");
		
		for(var i = 1; i < allImages.length; i++){
			console.log(i);
		}
		
	  return;
	}
	
	rotateImages();*/
	
	/**
	 * Blur-up Backgrounds
	 * 
	 * Start with a tiny background, blurred, then load up full background and transition to it.
	 * Adapted from Emil Björklund's script.
	 * See: https://css-tricks.com/the-blur-up-technique-for-loading-background-images/
	 */
	/*var win, doc, bgTiny, bg, enhancedClass;
	
	// Quit early if older browser (e.g. IE 8).
	if (!('addEventListener' in window)) {
		return;
	}
	
	win = window;
	doc = win.document;
	bgTiny = document.getElementById('main-background-img');
	//bgTiny.src = "";
	bg = doc.querySelector('.main-background2');
	enhancedClass = 'main-background2-enhanced';
	
	// Strip the "tiny" (-t) suffix from the filename
	var bgLarge = (function(){
		if(bgTiny.src.match(/-t\./)){
			return bgTiny.src.replace(/-t./, '.');
		} else {
			return;
		}
	}());
	
	// After the image transitions from blurry to sharp, turn off will-change to save processing power
	function blurOff(){
		bgTiny.style.willChange = 'auto';
	}
	
	// Assign an onLoad handler to the dummy image *before* assigning the src
	bgTiny.onload = function () {
		bgTiny.style.willChange = 'filter';
		bgTiny.addEventListener('transitioned', blurOff());
		if (bg.classList)  // Add the "enhanced" class to the element
			bg.classList.add(enhancedClass);
		else  // IE 9
			bg.className += ' ' + enhancedClass;
	};
  
	// Finally, trigger the whole preloading chain by giving the dummy
	// image its source.
	if (bgLarge) {
		bgTiny.src = bgLarge;
	}*/
};