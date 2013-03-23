#include "GameEngine.h"

// Constant default values for fps and window size
const int GameEngine::DEFAULT_FPS = 30;
const int GameEngine::DEFAULT_WINDOW_WIDTH = 800;
const int GameEngine::DEFAULT_WINDOW_HEIGHT = 600;

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
GameEngine::~GameEngine() {
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
	if (newFPS > 60) {
		std::cout << "WARNING: Too high fps set (" << newFPS << "), setting max fps (60)" << std::endl;
		fps = 60;

	} else if (newFPS < 1) {
		std::cout << "WARNING: Too low fps set (" << newFPS << "), defaulting to "
			<< DEFAULT_FPS << " instead" << std::endl;
		fps = DEFAULT_FPS;

	} else {
		fps = newFPS;
	}
}

/* Set up screen (window) height and width.
 * Max window size is 800 width and 600 height, if the supplied values are higher than
 * this, then we force 800x600.
 * TODO: Right now this crashes and dies if the screen cannot be created. Be nicer?
 */
void GameEngine::setUpWindow(int width, int height) {
	// Check and set width
	if (width < 1) {
		std::cout << "WARNING: Too low width set (" << width << "), defaulting to "
			<< DEFAULT_WINDOW_WIDTH << " pixels instead" << std::endl;
		windowWidth = DEFAULT_WINDOW_WIDTH;

	} else {
		windowWidth = width;
	}

	// Check and set height
	if (height < 1) {
		std::cout << "WARNING: Too low height set (" << height << "), defaulting to "
			<< DEFAULT_WINDOW_HEIGHT << " pixels instead" << std::endl;
		windowHeight = DEFAULT_WINDOW_HEIGHT;

	} else {
		windowHeight = height;
	}

	screen = SDL_SetVideoMode(windowWidth, windowHeight, 16,
		SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);

	if (screen == NULL) {
		std::cerr << "ERROR: Cannot create screen!\n";
		exit(-1);
	}

	// Set up screen
	Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);
	SDL_FillRect(screen, NULL, bgColor);
	SDL_Flip(screen);
}
