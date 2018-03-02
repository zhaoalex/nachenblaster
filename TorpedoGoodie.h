//
//  TorpedoGoodie.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef TorpedoGoodie_h
#define TorpedoGoodie_h

#include "Goodie.h"
#include "Actor.h"
#include "GameConstants.h"

class StudentWorld;
class NachenBlaster;

class TorpedoGoodie : public Goodie {
public:
    TorpedoGoodie(StudentWorld* world, double startX, double startY)
    : Goodie(world, IID_TORPEDO_GOODIE, startX, startY) {}
    virtual ~TorpedoGoodie() {}
    
    virtual void grantPowerup(NachenBlaster* player);
};

#endif /* TorpedoGoodie_h */

