//
//  Smallgon.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#include "Smallgon.h"
#include "GameConstants.h"
#include "Turnip.h"

bool Smallgon::possiblyFireAtPlayer() {
    int rand = randInt(1, (20 / getWorld()->getLevel()) + 5);
    if (rand == 1) {
        getWorld()->addActor(new Turnip(getWorld(), getX() - 14, getY()));
        getWorld()->playSound(SOUND_ALIEN_SHOOT);
        return true;
    }
    return false;
}
