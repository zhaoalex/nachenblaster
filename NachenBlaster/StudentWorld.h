#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;
class NachenBlaster;
class DamageableObject;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    DamageableObject* getCollidingAlien(const Actor* a) const;
    NachenBlaster* getCollidingPlayer(const Actor* a) const;
    bool playerInLineOfFire(const Actor* a) const;
    
    // adds a new actor to the world
    void addActor(Actor* a) { m_actors.push_back(a); }
    
    // records alien on screen; called in alien constructor
    void recordAlienOnScreen() { m_numAliensOnScreen++; }
    // records alien off screen; called in alien destructor
    void recordAlienOffScreen() { m_numAliensOnScreen--; }
    
    // records alien destroyed (aka health 0)
    void recordAlienDestroyed() { m_numRemaining--; }
    
private:
    // member functions
    void removeDeadGameObjects();
    void tryIntroduceNewObjects();
    void updateGameText();
    
    // member variables
    std::vector<Actor*> m_actors;
    int m_numRemaining; // number of aliens left to be destroyed in order to move to next level
    NachenBlaster* m_player;
    int m_numAliensOnScreen;
};

#endif // STUDENTWORLD_H_
