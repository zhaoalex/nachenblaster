//
//  Snagglegon.h
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#ifndef Snagglegon_h
#define Snagglegon_h

#include "Alien.h"

class Snagglegon : public Alien {
public:
    // Snagglegons don't use flight length, so start at -1; this way it'll never hit 0
    Snagglegon(StudentWorld* world, double startX, double startY)
    : Alien(world, IID_SNAGGLEGON, startX, startY, 10 * (1 + (world->getLevel() - 1) * 0.1), 15, -1, 1.75, 1000, false) {}
    virtual ~Snagglegon() {}
    
    virtual void possiblyDropGoodie();
    virtual bool possiblyFireAtPlayer();
};

#endif /* Snagglegon_h */
