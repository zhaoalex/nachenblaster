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
    DamageableObject(StudentWorld* world, int imageID, double startX, double startY, int dir, double size, int depth, double hitPoints)
    : Actor(world, imageID, startX, startY, dir, size, depth) {
        m_hitPoints = hitPoints;
    }
    virtual ~DamageableObject() {}
    
    virtual void doSomething() = 0;
    
    double hitPoints() const { return m_hitPoints; }
private:
    double m_hitPoints;
};

#endif /* DamageableObject_h */
