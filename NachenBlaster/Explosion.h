//
//  Explosion.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef Explosion_h
#define Explosion_h

#include "Actor.h"

class StudentWorld;

class Explosion : public Actor {
public:
    Explosion(StudentWorld* world, double startX, double startY)
    : Actor(world, IID_EXPLOSION, startX, startY) { // + default params 0, 1, 0
        m_time = 0;
    }
    virtual ~Explosion() {}
    
    virtual void doSomething();
    
private:
    int m_time;
};

#endif /* Explosion_h */
