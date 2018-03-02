//
//  Cabbage.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef Cabbage_h
#define Cabbage_h

#include "Projectile.h"
#include "GameConstants.h"

class Cabbage : public Projectile {
public:
    Cabbage(StudentWorld* world, double startX, double startY)
    : Projectile(world, IID_CABBAGE, startX, startY, 2, 8, true, 0, false) {}
    virtual ~Cabbage() {}
};

#endif /* Cabbage_h */
