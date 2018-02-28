#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(StudentWorld* world, int imageID, double startX, double startY, int dir = 0, double size = 1.0, int depth = 0)
    : GraphObject(imageID, startX, startY, dir, size, depth) {
        m_world = world;
        m_state = true; // default to true
    }
    virtual ~Actor() {}
    
    virtual void doSomething() = 0;
    
    bool isAlive() const { return m_state; } // get state
    void setDead() { m_state = false; } // set dead
    
    
    // TODO protected?
    bool isOffScreenLR() const { return (getX() < 0) || (getX() >= VIEW_WIDTH); } // return true if off screen left or right
    
    StudentWorld* getWorld() const { return m_world; }
private:
    bool m_state; // true means living, false means dead; default true
    StudentWorld* m_world;
};

/*
class Star : public Actor {
public:
    Star(StudentWorld* world, double startX, double startY, double size)
    : Actor(world, IID_STAR, startX, startY, 0, size, 3) {}
    virtual ~Star() {}
    
    virtual void doSomething();
private:
    
};

class NachenBlaster : public Actor {
public:
    NachenBlaster(StudentWorld* world)
    : Actor(world, IID_NACHENBLASTER, 0, 128) {
        m_health = 50;
        m_cabbage = 30;
        m_torpedoes = 0;
    }
    virtual ~NachenBlaster() {}
    
    virtual void doSomething();
private:
    int m_health;
    int m_cabbage;
    int m_torpedoes;
};
*/
#endif // ACTOR_H_
