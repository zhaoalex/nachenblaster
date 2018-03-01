//
//  Turnip.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef Turnip_h
#define Turnip_h

#include "Projectile.h"
#include "GameConstants.h"

class Turnip : public Projectile {
public:
    Turnip(StudentWorld* world, double startX, double startY)
    : Projectile(world, IID_TURNIP, startX, startY, 2, -6, true, 20, true) {}
    virtual ~Turnip() {}
};

#endif /* Turnip_h */

