#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;
class NachenBlaster;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    Actor* getCollidingAlien(const Actor* a) const;
    NachenBlaster* getCollidingPlayer(const Actor* a) const;
    bool playerInLineOfFire(const Actor* a) const;
    
    void addActor(Actor* a);
    void recordAlienDestroyed();

private:
    // member functions
    void introduceNewObjects();
    void updateGameText();
    
    // member variables
    std::vector<Actor*> m_actors;
    int m_numDestroyed; // number of destroyed aliens
    int m_numRemaining; // number of aliens required to be destroyed in order to move to next level
    
    NachenBlaster* m_player;
};

#endif // STUDENTWORLD_H_
