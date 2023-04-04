# C_GameEngine_with_Asteroids-game
A small game made of the enginge that i crated in C/C++ 

Description:

This is a game that takes place in space. As a player, your goal is to shoot down the asteroids that are flying towards you. If you get hit by an asteroid, you will die.
To help you, you can move using the A and D keys or the Left and Right arrow keys to avoid the asteroids. You can also shoot the asteroids with your pistol, which fires a shot when you press the mouse button.
If you get hit, you die and the game is over.

Instructions for building and testing the game:

Open an integrated terminal using the makefile, type "make" as the first command (this compiles the game), then type "./build/debug/play" to run the game.
Paths have been defined in the "constants.h" file, which has been covered in various file structure lectures. All resources can be found in the "resources" folder.
Here's an example of a path where I set an image to a texture: texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/beams.png").c_str()); 
