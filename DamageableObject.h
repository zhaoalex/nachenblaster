//
//  DamageableObject.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//  Copyright © 2018 David Smallberg. All rights reserved.
//

#ifndef DamageableObject_h
#define DamageableObject_h

#include "Actor.h"

class StudentWorld;

class DamageableObject : public Actor {
public:
    DamageableObject(StudentWorld* world, int imageID, double startX, double startY, int dir, double size, int depth, double health)
    : Actor(world, imageID, startX, startY, dir, size, depth) {
        m_health = health;
    }
    virtual ~DamageableObject() {}
    
    virtual void doSomething() = 0;
    virtual void sufferDamage(double amt, int cause) = 0;
    
    void setHealth(double amt) { m_health = amt; }
    double getHealth() const { return m_health; }
private:
    double m_health;
};

#endif /* DamageableObject_h */
