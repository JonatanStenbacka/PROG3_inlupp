#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

class GameEngine {
	private:
		int fps;
		int windowWidth, windowHeight;
		bool quit;
		const int DEFAULT_FPS = 30;
		const int DEFAULT_WINDOW_WIDTH = 800;
		const int DEFAULT_WINDOW_HEIGHT = 600;
		
		// SDL stuff
		SDL_Surface *screen;
		SDL_Event event;
		
	public:
		GameEngine(int fps, int width, int height);
		GameEngine(int fps) : GameEngine(fps, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT){}
		GameEngine() : GameEngine(DEFAULT_FPS, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT){}
		~GameEngine();
		void run();
		void setFPS(int newFPS);
		void setUpWindow(int width, int height);
};

#endif
