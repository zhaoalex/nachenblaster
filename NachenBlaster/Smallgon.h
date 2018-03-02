//
//  Smallgon.h
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#ifndef Smallgon_h
#define Smallgon_h

#include "Alien.h"

class Smallgon : public Alien {
public:
    Smallgon(StudentWorld* world, double startX, double startY)
    : Alien(world, IID_SMALLGON, startX, startY, 5 * (1 + (world->getLevel() - 1) * 0.1), 5, 0, 2.0, 250, true) {}
    virtual ~Smallgon() {}
    
protected:
    virtual void possiblyDropGoodie() {} // smallgons drop no goodies
    virtual bool possiblyFireAtPlayer();
};

#endif /* Smallgon_h */
