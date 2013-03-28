#include "GameEngine.h"

// Constant default values for fps and window size
const int GameEngine::DEFAULT_FPS = 30;
const int GameEngine::DEFAULT_WINDOW_WIDTH = 800;
const int GameEngine::DEFAULT_WINDOW_HEIGHT = 600;

// Constructor that takes game fps and width/height for the main window
GameEngine::GameEngine(int fps, int width, int height) {
	std::cout << "Engine: setting up..." << std::endl;
	
	// The engine isn't running yet
	running = false;

	// Set FPS
	setFPS(fps);

	// Set up SDL screen surface
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cerr << "Engine: ERROR! Cannot initialize SDL! Exiting..." << std::endl;
		exit(-1);
	}

	setWindowSize(width, height);
	
	std::cout << "Engine: done setting up" << std::endl;
}

// Simple destructor, we will probably need to adjust this later
GameEngine::~GameEngine() {
    // TODO: Make sure to unload all SDL stuff here!
}

// Initializes the engine
void GameEngine::init() {
	initialized = true;
}

// Engine main loop. When this is called, the game starts
void GameEngine::run() {
	running = true;
	stop = false;
	
	// Set FPS-related variables
	const int tickInterval = 1000 / fps;
	Uint32 nextTick;
	int delay;

	while (!stop) {
		nextTick = SDL_GetTicks() + tickInterval;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				stop = true;
		}

		// Regulate FPS
		delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);

 		// Update screen buffer
		SDL_Flip(screen);
	}

	running = false;
	SDL_Quit();
	stopEngine();
}

// Stops the engine
void GameEngine::stopEngine() {
	initialized = false;
}

void GameEngine::setFPS(int newFPS) {
	// Check that FPS isn't too high. If it is, set to 60 (highest possible value with this engine)
	if (newFPS > 60) {
		std::cout << "Engine: WARNING! Too high fps set (" << newFPS << "), setting max fps (60)" << std::endl;
		fps = 60;

	} else if (newFPS < 1) {
		std::cout << "Engine: WARNING! Too low fps set (" << newFPS << "), defaulting to "
			<< DEFAULT_FPS << " instead" << std::endl;
		fps = DEFAULT_FPS;

	} else {
		std::cout << "Engine: setting fps to " << newFPS << std::endl;
		fps = newFPS;
	}
}

/* Set up screen (window) height and width.
 * Max window size is 800 width and 600 height, if the supplied values are higher than
 * this, then we force 800x600.
 * TODO: Right now this crashes and dies if the screen cannot be created. Be nicer?
 */
void GameEngine::setWindowSize(int width, int height) {
	if (running) {
		// The engine is currently running! Changing of size not permitted!
		std::cout << "Engine: WARNING! Tried to change screen size while engine was running" << std::endl;
		return;
	}

	// Check and set width
	if (width < 1) {
		std::cout << "Engine: WARNING! Too low width set (" << width << "), defaulting to "
			<< DEFAULT_WINDOW_WIDTH << " pixels instead" << std::endl;
		windowWidth = DEFAULT_WINDOW_WIDTH;

	} else {
		windowWidth = width;
	}

	// Check and set height
	if (height < 1) {
		std::cout << "Engine: WARNING! Too low height set (" << height << "), defaulting to "
			<< DEFAULT_WINDOW_HEIGHT << " pixels instead" << std::endl;
		windowHeight = DEFAULT_WINDOW_HEIGHT;

	} else {
		windowHeight = height;
	}

	screen = SDL_SetVideoMode(windowWidth, windowHeight, 32,
		SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);

	if (screen == NULL) {
		std::cerr << "Engine: ERROR! Cannot create screen!\n";
		exit(-1);
	}

	// Set up screen
	Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);
	SDL_FillRect(screen, NULL, bgColor);
	SDL_Flip(screen);
}

// Set the title of the windows (with const char* param)
void GameEngine::setWindowTitle(const char* title) {
	std::cout << "Engine: setting title to " << title << std::endl;
	SDL_WM_SetCaption(title, title);
}

// Set the title of the window (with string param)
void GameEngine::setWindowTitle(std::string title) {
	// Make use of the above method
	setWindowTitle(title.c_str());
}
