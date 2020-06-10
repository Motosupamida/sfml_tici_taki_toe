#include <iostream>

#include "Field.h"
#include "Game.h"
#include "Player.h"

int main()
{
    Game *session = new Game;
    session->play();
    delete session;
    return 0;
}
