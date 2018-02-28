#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <iostream>
#include <sstream>
#include "Actor.h"

#include "Star.h"
#include "NachenBlaster.h"



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

StudentWorld::~StudentWorld() { // free anything that hasn't been freed
    cleanUp();
}

/**
 * Constructs representation of the current level in your StudentWorld object and populating it
 * with initial objects (e.g., stars), using one or more data structures that you come up with.
 * Called when (a) game first starts, (b) player completes level, or (c) user loses a life (and hasn't lost)
 * @return GWSTATUS_COTINUE_GAME
 */
int StudentWorld::init()
{
    m_numRemaining = 6 + (4 * getLevel());
    m_numDestroyed = 0;
    
    // Place NachenBlaster
    m_actors.push_back(new NachenBlaster(this));
    
    // Place 30 stars
    for (int i = 0; i < 30; i++) {
        double startX = randInt(0, VIEW_WIDTH - 1);
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt(5, 50) * 0.01;
        m_actors.push_back(new Star(this, startX, startY, size));
    }
    return GWSTATUS_CONTINUE_GAME;
}

/**
 * Called after init() once every tick, and runs a single tick of the game
 * Responsible for telling every game actor to do something
 * Also disposes actors that need to disappear
 */
int StudentWorld::move()
{
    // decLives();
    // return GWSTATUS_PLAYER_DIED;
    
    // let each actor do something
    for (int i = 0; i < m_actors.size(); i++) { // could also use iterator
        if (m_actors[i]->isAlive()) {
            m_actors[i]->doSomething();
            // TODO if nachen blaster died, return
            // TODO if nachen blaster won, return
        }
    }
    
    // remove dead game objects
    vector<Actor*>::iterator it = m_actors.begin();
    while (it != m_actors.end()) {
        if (!(*it)->isAlive()) {
            delete *it;
            it = m_actors.erase(it);
        } else {
            it++;
        }
    }
    
    // update display text
    updateGameText();
    
    // possibly introduce new objects
    introduceNewObjects(); // TODO should this be at start of fcn?
    return GWSTATUS_CONTINUE_GAME;
}

/**
 * Called when player completes a level or loses a life.
 * Frees all actors currently in the game.
 */
void StudentWorld::cleanUp()
{
    std::vector<Actor*>::iterator it = m_actors.begin();
    while (it != m_actors.end()) {
        delete *it;
        it = m_actors.erase(it);
    }
}

/**
 * If at least one alien has collided with a, return a pointer to one of them;
 * otherwise return a null pointer.
 */
Actor* StudentWorld::getCollidingAlien(const Actor* a) const {
    // TODO
    return nullptr;
}

/**
 * If player collided with a, return a pointer to the player;
 * otherwise return a null pointer.
 */
NachenBlaster* StudentWorld::getCollidingPlayer(const Actor* a) const {
    // TODO
    return nullptr;
}

/**
 * Return true if player is in line of fire of a.
 */
bool StudentWorld::playerInLineOfFire(const Actor* a) const {
    // TODO
    return false;
}

/**
 * Adds a new actor to the world.
 */
void StudentWorld::addActor(Actor* a) {
    m_actors.push_back(a);
}

/**
 * Records that an alien was destroyed.
 */
void StudentWorld::recordAlienDestroyed() {
    m_numRemaining--;
    m_numDestroyed++;
}

// Private member functions

/**
 * Handles introduction of new objects every tick, i.e. stars and alien ships
 */
void StudentWorld::introduceNewObjects() {
    // 1/15 chance to introduce a star
    if (randInt(1, 15) == 1) {
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt(5, 50) * 0.01;
        m_actors.push_back(new Star(this, VIEW_WIDTH - 1, startY, size));
    }
    
    // Introduce any alien ships
    // TODO
    // int maxOnScreen = 4 + (0.5 * getLevel());
    
}

void StudentWorld::updateGameText() {
    ostringstream oss;
    oss.setf(ios::fixed);
    oss.precision(0);
    oss << "Lives: " << getLives() << " Health: " << "TEMP" << " Score: " << getScore()
        << " Level: " << getLevel() << " Cabbages: " << "TEMP" << " Torpedoes: " << "TEMP"; // TODO
    setGameStatText(oss.str());
}
