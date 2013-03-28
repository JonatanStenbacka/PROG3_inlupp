#include <string>
#include "GameEngine.h"

std::string gamename = "Testgame";

int main() {
	GameEngine engine;
	engine.setWindowTitle(gamename);
	engine.init();
	engine.run();

	return 0;
}
