#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();

private:
    // member functions
    void introduceNewObjects();
    
    
    // member variables
    std::vector<Actor*> m_actors;
    int m_numDestroyed; // number of destroyed aliens
    int m_numRemaining; // number of aliens required to be destroyed in order to move to next level
    
};

#endif // STUDENTWORLD_H_
