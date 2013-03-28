#ifndef GAMEENGINE_H
#define GAMEENGINE_H

// If we are running something other than Windows, SDL is probably at SDL/SDL.h
#ifdef WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include <iostream>
#include <string>

class GameEngine {
	private:
		int fps;
		
		// Window-related
		int windowWidth, windowHeight;
		std::string windowTitle;
		
		// Misc variables for the engine
		bool initialized;
		bool running;
		static const int DEFAULT_FPS;
		static const int DEFAULT_WINDOW_WIDTH;
		static const int DEFAULT_WINDOW_HEIGHT;

		// SDL
		SDL_Surface *screen;
		SDL_Event event;

	public:
		GameEngine(int fps, int width, int height);
		GameEngine(int fps) : GameEngine(fps, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT){}
		GameEngine() : GameEngine(DEFAULT_FPS, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT){}
		~GameEngine();
		void init();
		void run();
		void stop();
		void setFPS(int newFPS);
		void setWindowSize(int width, int height);
		void setWindowTitle(const char*);
		void setWindowTitle(std::string title);
};

#endif
