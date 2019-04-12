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
			
			- Issue: The dots' colors would change randomly and quickly rather than just when they were not linked.
			- Fix: Made a vector filled with boolean values that monitor the linking of each dot and changed color
			based on those values.

			- Issue: Initialization of offsets for the dots were resulting in errors in dot positioning and movement
			i.e the dots would flash or move in a linear manner
			- Fix: Utilized a method in openframeworks called ofRandom that would randomize point offset values

			