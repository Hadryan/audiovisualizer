# Audio Visualizer

**Application Summary**
------------------------

This application is an Audio Visualizer. The visualization is a collection of free-floating points that connect to one another via lines once encountering a certain distance from each other while bars scroll across the bottom of the screen. The speed as well as size of the points, the thickness of the lines that connect the points, and the rise and fall of the bars are in accordance with the sound (using features such as Perlin Noise).

**Application Usage**
------------------

In order to change the songs, add them to the "songs" folder included in the project. Song files must be in either .mp3 or .wav file formats.

In this code snippet, you will want to change "audioBeats.wav" to the name of the song file

    sound_player.loadSound("../../songs/audioBeats.wav");

**Significant Libraries/Addons Used**
-------------------------------------

* openFrameworks:- special default classes/add-ons used include:

    * ofSoundPlayer - to play various music files

    * ofGraphics - used to create visuals including the bars and points 
