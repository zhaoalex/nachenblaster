//
//  AlienLaunchedTorpedo.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef AlienLaunchedTorpedo_h
#define AlienLaunchedTorpedo_h

#include "Projectile.h"
#include "GameConstants.h"

class AlienLaunchedTorpedo : public Projectile {
public:
    AlienLaunchedTorpedo(StudentWorld* world, double startX, double startY)
    : Projectile(world, IID_TORPEDO, startX, startY, 8, -8, false, 180, true) {}
    virtual ~AlienLaunchedTorpedo() {}
};


#endif /* AlienLaunchedTorpedo_h */
