//
//  ExtraLifeGoodie.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#include "ExtraLifeGoodie.h"
#include "NachenBlaster.h"
#include "StudentWorld.h"

void ExtraLifeGoodie::grantPowerup(NachenBlaster *player) {
    getWorld()->incLives();
}
