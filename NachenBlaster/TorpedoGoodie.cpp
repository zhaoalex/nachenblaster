//
//  TorpedoGoodie.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#include "TorpedoGoodie.h"
#include "NachenBlaster.h"
#include "StudentWorld.h"

void TorpedoGoodie::grantPowerup(NachenBlaster *player) {
    player->incTorpedoes(5);
}
