#ifndef GAMEENGINE_H
#define GAMEENGINE_H

// If we are running something other than Windows, SDL is probably at SDL/SDL.h
#ifdef WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include <iostream>

class GameEngine {
	private:
		int fps;
		int windowWidth, windowHeight;
		bool quit;
		static const int DEFAULT_FPS;
		static const int DEFAULT_WINDOW_WIDTH;
		static const int DEFAULT_WINDOW_HEIGHT;

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
