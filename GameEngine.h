#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine {
	public:
		~GameEngine();
		~GameEngine(int fps);
		~GameEngine(int fps, int width, int height);
		void setFPS(int newFPS);

	private:
		int fps;
		int windowWidth, windowHeight;
};

#endif