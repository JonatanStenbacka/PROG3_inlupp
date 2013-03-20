#include "GameEngine.h"

GameEngine::GameEngine() {
	fps = 30;
}

// Constructor that takes the max fps as a parameter
GameEngine::GameEngine(int fps) {
	setFPS(fps);
	setWindowSize(800, 600);
}

// Constructor that takes the max fps and the widht and hieght of the rendered window
GameEngine::GameEngine(int fps, int width, int height) {
	setFPS(fps);
	setWindowSize(width, height);
}

// Simple destructor, we will probably need to adjust this later
GameEngine::~GameEngine(){}

// Set a new fps
void GameEngine::setFPS(int newFPS) {
	// Check that FPS isn't too high. If it is, set to 60 (highest possible value with this engine)
	if (newFPS > 60)
		fps = 60;
	else
		fps = newFPS;
}

// Set window width and height
void GameEngine::setWindowSize(int w, int h) {

	/* Konsekventhet: I destruktorn har vi "int width" och
	 * "int height" som parametrar, men i denna funktion 
	 * s� har vi "int w", och "int h", trots att vi egentligen 
	 * syftar p� samma saker. S� hur ska vi ha det? :)
	 */

	/* Max window size is 800 width and 600 height, if the supplied values are higher than
	 * this, then we force 800x600
	 */

	// Check and set width
	if (width > 800) //Menar du m�jligen windowWidth?
		windowWidth = 800;
	else
		windowWidth = w;

	// Check and set height
	if (height > 600) //Samma som ovan, windowHeight?
		windowHeight = 600;
	else
		windowHeight = h;

	// REDRAW WINDOW HERE
}