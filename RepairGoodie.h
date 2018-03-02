//
//  RepairGoodie.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef RepairGoodie_h
#define RepairGoodie_h

#include "Goodie.h"
#include "Actor.h"
#include "GameConstants.h"

class StudentWorld;
class NachenBlaster;

class RepairGoodie : public Goodie {
public:
    RepairGoodie(StudentWorld* world, double startX, double startY)
    : Goodie(world, IID_REPAIR_GOODIE, startX, startY) {}
    virtual ~RepairGoodie() {}
    
    virtual void grantPowerup(NachenBlaster* player);
};

#endif /* RepairGoodie_h */

