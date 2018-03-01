//
//  Alien.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef Alien_h
#define Alien_h

#include "DamageableObject.h"

class StudentWorld;

class Alien : public DamageableObject {
public:
    Alien(StudentWorld* world, int imageID, double startX, double startY, double health)
    : DamageableObject(world, imageID, startX, startY, 0, 1.5, 1, health) {}
    virtual ~Alien() {}
    
    virtual void doSomething();
    virtual void sufferDamage(double amt, int cause);
    virtual bool isAlien() const { return true; } // override to return true for all aliens
};

#endif /* Alien_h */
