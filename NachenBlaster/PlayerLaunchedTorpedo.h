//
//  PlayerLaunchedTorpedo.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef PlayerLaunchedTorpedo_h
#define PlayerLaunchedTorpedo_h

#include "Projectile.h"
#include "GameConstants.h"

class PlayerLaunchedTorpedo : public Projectile {
public:
    PlayerLaunchedTorpedo(StudentWorld* world, double startX, double startY)
    : Projectile(world, IID_TORPEDO, startX, startY, 8, 8, false, 0, false) {}
    virtual ~PlayerLaunchedTorpedo() {}
};

#endif /* PlayerLaunchedTorpedo_h */
