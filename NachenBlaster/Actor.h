#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

// constants for sufferDamage in order to keep track of damage source
const int HIT_BY_SHIP = 0;
const int HIT_BY_PROJECTILE = 1;

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(StudentWorld* world, int imageID, double startX, double startY, int dir = 0, double size = 1.0, int depth = 0)
    : GraphObject(imageID, startX, startY, dir, size, depth) {
        m_world = world;
        m_living = true; // default to true
    }
    virtual ~Actor() {}
    
    virtual void doSomething() = 0;
    
    bool isAlive() const { return m_living; } // get state
    virtual bool isAlien() const { return false; } // default behavior is not alien; alien class will override this

protected:
    void setDead() { m_living = false; } // set dead

    // return true if off screen left or right
    bool isOffScreenLR() const { return (getX() < 0 || getX() >= VIEW_WIDTH); }
    
    StudentWorld* getWorld() const { return m_world; }
    
private:
    bool m_living; // true means living, false means dead; default true
    StudentWorld* m_world;
};

#endif // ACTOR_H_
