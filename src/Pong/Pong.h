#pragma once
#include "Game/Game.h"


const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

class Pong : public Game {
    public:
        Pong();
        ~Pong();

    private:
        std::unique_ptr<Scene> createGameplayScene();
};
