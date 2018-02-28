//
//  Projectile.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef Projectile_h
#define Projectile_h

#include "Actor.h"

class StudentWorld;

class Projectile : public Actor {
public:
    Projectile(StudentWorld* world, int imageID, double startX, double startY, double damageAmt, double deltaX, bool rotates, int imageDir)
    : Actor(world, imageID, startX, startY, 0, 0.5, 1) {}
    virtual ~Projectile() {}
    
    virtual void doSomething() = 0;
};

#endif /* Projectile_h */
