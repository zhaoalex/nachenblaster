#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetDir)
: GameWorld(assetDir)
{
}

/**
 * Constructs representation of the current level in your StudentWorld object and populating it
 * with initial objects (e.g., stars), using one or more data structures that you come up with.
 * Called when (a) game first starts, (b) player completes level, or (c) user loses a life (and hasn't lost)
 * @return GWSTATUS_COTINUE_GAME
 */
int StudentWorld::init()
{
    return GWSTATUS_CONTINUE_GAME;
}

/**
 * Called after init() once every tick, and runs a single tick of the game
 * Responsible for telling every game actor to do something
 * Also disposes actors that need to disappear
 */
int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    decLives();
    return GWSTATUS_PLAYER_DIED;
}

/**
 * Called when player completes a level or loses a life.
 * Frees all actors currently in the game.
 */
void StudentWorld::cleanUp()
{
}
