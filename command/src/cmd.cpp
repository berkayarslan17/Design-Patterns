#include <iostream>

#include "cmd.h"

GameActor::GameActor()
{
    std::cout << "GameActor object is created\n";
}

GameActor::~GameActor()
{
    std::cout << "GameActor object is destroyed\n";
}

void GameActor::jump()
{
    std::cout << "Character jumped\n";
}
