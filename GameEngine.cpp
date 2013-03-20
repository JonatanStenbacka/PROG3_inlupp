#include "GameEngine.h"

GameEngine::~GameEngine(){
	fps = 30;
}

// Constructor that takes the max fps as a parameter
GameEngine::~GameEngine(int fps){

}

// Constructor that takes the max fps and the widht and hieght of the rendered window
GameEngine::~GameEngine(int fps, int width, int height){

}

// Set a new fps
void GameEngine::setFPS(int newFPS) {
	fps = newFPS;
}