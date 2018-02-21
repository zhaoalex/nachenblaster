#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

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
    
    bool isAlive() { return m_state; } // get state
    void setState(bool state) { m_state = state; } // set state
    
    StudentWorld* getWorld() { return m_world; }
private:
    bool m_state; // true means living, false means dead; default true
    StudentWorld* m_world;
};

#endif // ACTOR_H_
