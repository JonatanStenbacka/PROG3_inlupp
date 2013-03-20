#include "GameEngine.h"

int main(int argc, char *argv[]) {
    GameEngine *engine = new GameEngine();
    engine->run();
    delete engine;
    return 0;
}
