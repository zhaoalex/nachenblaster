#include <string>
#include <iostream>
#include <sstream>

#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"

#include "NachenBlaster.h"
#include "Star.h"

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
    
    // Place NachenBlaster
    m_player = new NachenBlaster(this);
    m_actors.push_back(m_player);
    
    // Place 30 stars
    for (int i = 0; i < 30; i++) {
        double startX = randInt(0, VIEW_WIDTH - 1);
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt(5, 50) * 0.01;
        m_actors.push_back(new Star(this, startX, startY, size));
    }
    
    
    
    m_player->incTorpedoes(100); // TODO
    
    
    
    return GWSTATUS_CONTINUE_GAME;
}

/**
 * Called after init() once every tick, and runs a single tick of the game
 * Responsible for telling every game actor to do something
 * Also disposes actors that need to disappear
 */
int StudentWorld::move()
{
    // let each actor do something
    for (int i = 0; i < m_actors.size(); i++) {
        if (m_actors[i]->isAlive()) {
            m_actors[i]->doSomething();
            if (!m_player->isAlive()) { // if nachenblaster died during this tick
                decLives();
                return GWSTATUS_PLAYER_DIED;
            }
            // TODO if nachen blaster won, return
        }
    }
    
    // remove dead game objects
    removeDeadGameObjects();
    
    // update display text
    updateGameText();
    
    // possibly introduce new objects
    tryIntroduceNewObjects();
    
    // player hasn't finished the level and hasn't died, so continue the game
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
 * If at least one alien has collided with actor a, return a pointer to one of them;
 * otherwise return a null pointer.
 */
DamageableObject* StudentWorld::getCollidingAlien(const Actor* a) const {
    // TODO
    return nullptr;
}

/**
 * If player collided with actor a, return a pointer to the player;
 * otherwise return a null pointer.
 */
NachenBlaster* StudentWorld::getCollidingPlayer(const Actor* a) const {
    double dist = sqrt(pow(m_player->getX() - a->getX(), 2) + pow(m_player->getY() - a->getY(), 2)); // euclidian distance
    if (dist < (0.75 * (m_player->getRadius() + a->getRadius()))) return m_player;
    else return nullptr;
}

/**
 * Return true if player is in line of fire of a.
 */
bool StudentWorld::playerInLineOfFire(const Actor* a) const {
    // TODO
    return false;
}

// Private member functions

/**
 * Removes all game objects that were marked dead during this tick.
 */
void StudentWorld::removeDeadGameObjects() {
    vector<Actor*>::iterator it = m_actors.begin();
    while (it != m_actors.end()) {
        if (!(*it)->isAlive()) {
            delete *it;
            it = m_actors.erase(it);
        } else {
            it++;
        }
    }
}

/**
 * Handles introduction of new objects every tick, i.e. stars and alien ships
 */
void StudentWorld::tryIntroduceNewObjects() {
    // 1/15 chance to introduce a star
    if (randInt(1, 15) == 1) {
        double startY = randInt(0, VIEW_HEIGHT - 1);
        double size = randInt(5, 50) * 0.01;
        m_actors.push_back(new Star(this, VIEW_WIDTH - 1, startY, size));
    }
    
    // Introduce any alien ships
    // TODO
    int maxOnScreen = 4 + (0.5 * getLevel());
    int min = (m_numRemaining <= maxOnScreen) ? m_numRemaining : maxOnScreen; // min(m_numRemaining, maxOnScreen)
    int currentShipsOnScreen = 0; // TODO
    
    // if true, we must introduce a new alien
    if (currentShipsOnScreen < min) {
        int s1 = 60;
        int s2 = 20 + (getLevel() * 5);
        int s3 = 5 + (getLevel() * 10);
        int rand = randInt(1, s1 + s2 + s3);
        if (rand <= s1) { // && rand >= 1; Smallgon
            //TODO
        } else if (rand > s1 && rand <= s2) { // Smoregon
            
        } else { // rand > s2 (&& rand <= s3); Snagglegon
            
        }
    }
}

/**
 * Updates the game text at the top of the window every tick
 */
void StudentWorld::updateGameText() {
    ostringstream oss;
    oss.setf(ios::fixed);
    oss.precision(0);
    oss << "Lives: " << getLives() << "  Health: " << (m_player->getHealth() / 50.0 * 100)
        << "%  Score: " << getScore() << "  Level: " << getLevel()
        << "  Cabbages: " << (m_player->numCabbages() / 30.0 * 100) << "%  Torpedoes: " << m_player->numTorpedoes();
    setGameStatText(oss.str());
}
