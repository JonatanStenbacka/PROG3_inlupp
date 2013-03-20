#include "GameEngine.h"

// Constructor that takes game fps and width/height for the main window
GameEngine::GameEngine(int fps, int width, int height) {
	setFPS(fps);
	
	// Set up SDL screen surface
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
	    std::cerr << "ERROR: Cannot initialize SDL!\n";
	    exit(-1);
	}
	
	setUpWindow(width, height);
	SDL_WM_SetCaption("Simple Window", "Simple Window");
}

// Simple destructor, we will probably need to adjust this later
GameEngine::~GameEngine(){
    // TODO: Make sure to unload all SDL stuff here!
}

// Engine main loop. When this is called, the game starts
void GameEngine::run() {
    quit = false;
    
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
        }

        // Update screen buffer
        SDL_Flip(screen);
    }
    
    SDL_Quit();
}

void GameEngine::setFPS(int newFPS) {
	// Check that FPS isn't too high. If it is, set to 60 (highest possible value with this engine)
	if (newFPS > 60)
		fps = 60;
	else
		fps = newFPS;
}

/* Set up screen (window) height and width.
 * Max window size is 800 width and 600 height, if the supplied values are higher than
 * this, then we force 800x600.
 * TODO: Right now this crashes and dies if the screen cannot be created. Be nicer?
 */
void GameEngine::setUpWindow(int width, int height) {
	// Check and set width
	if (width > 800)
		windowWidth = DEFAULT_WINDOW_WIDTH;
	else
		windowWidth = width;

	// Check and set height
	if (height > 600)
		windowHeight = DEFAULT_WINDOW_HEIGHT;
	else
		windowHeight = height;

	screen = SDL_SetVideoMode(windowWidth, windowHeight, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	
	if (screen == NULL) {
	    std:cerr << "ERROR: Cannot create screen!\n";
	    exit(-1);
	}
	
	// Set up screen
	Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_FillRect(screen, NULL, bgColor);
    SDL_Flip(screen);
}
