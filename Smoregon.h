//
//  Smoregon.h
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#ifndef Smoregon_h
#define Smoregon_h

#include "Alien.h"

class Smoregon : public Alien {
public:
    Smoregon(StudentWorld* world, double startX, double startY)
    : Alien(world, IID_SMOREGON, startX, startY, 5 * (1 + (world->getLevel() - 1) * 0.1), 5, 0, 2.0, 250, true) {}
    virtual ~Smoregon() {}
    
    virtual void possiblyDropGoodie();
    virtual bool possiblyFireAtPlayer();
};

#endif /* Smoregon_h */
