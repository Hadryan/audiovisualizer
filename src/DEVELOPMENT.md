**Audio Visualizer**
	- **Development - Rough Checkpoints:**
			1. Week 1 Code Review: Add .jpg backgroud image and .wav sound files. Working implementation of at
			least one component of the visualizer i.e. floating dots animation in the foreground.
			2. Week 2 Code Review: Implementation of background bars that rise and fall based on audio frequency.
			More visually pleasing interface, brightness and bar colors vary based on audio frequency. Overall, nicer application. 

	- **Development Process** 
			- Issue: Unable to draw circles to represent the dots in the foreground animation.
			- Fix: Had to use new library and its methods. Specifically, the ofDrawCircle method from the Graphics 
			library to assist in creating circles.
			
			- Issue: The dots' brightness would change randomly and quickly rather than just when they were not linked and based on
			audio frequency.
			- Fix: Made a variable and updated it based on max bar height being reached in order to keep track of and change brightness
			based on that condition.

			- Issue: Setting the initial offsets for the dots were resulting in errors in dot positioning and movement
			in which the dots would flash or move in a linear manner
			- Fix: Utilized a method in openframeworks called ofRandom that would randomize point offset values

			-Issue: Had difficulty using the ofSoundStream to get frequencies for the stream. The intention was to have this 
			get the audio of the system rather than for an individual song's audio in a file.
			-Fix: Switched entirely to start using ofSoundPlayer and made the decision to just work with a single
			song for now.

			-Issue: Changes to the dotSpeed variable were not causing the dots to actually change speed 
			-Fix: Implemented and used a speed multiplier variable and while updating, multiplied it with the offsets
			values for the x and y coordinates of the dots.