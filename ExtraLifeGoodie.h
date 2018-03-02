//
//  ExtraLifeGoodie.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef ExtraLifeGoodie_h
#define ExtraLifeGoodie_h

#include "Goodie.h"
#include "Actor.h"
#include "GameConstants.h"

class StudentWorld;
class NachenBlaster;

class ExtraLifeGoodie : public Goodie {
public:
    ExtraLifeGoodie(StudentWorld* world, double startX, double startY)
    : Goodie(world, IID_LIFE_GOODIE, startX, startY) {}
    virtual ~ExtraLifeGoodie() {}
    
    virtual void grantPowerup(NachenBlaster* player);
};

#endif /* ExtraLifeGoodie_h */
