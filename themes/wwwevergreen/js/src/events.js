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
	recordEvent('virtual-tour-link', 'click', 'Virtual Tour', false);
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
	
});*/