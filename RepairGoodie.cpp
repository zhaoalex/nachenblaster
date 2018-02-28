//
//  RepairGoodie.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#include "RepairGoodie.h"
#include "NachenBlaster.h"
#include "StudentWorld.h"

void RepairGoodie::grantPowerup(NachenBlaster *player) {
    player->incHealth(10);
}
