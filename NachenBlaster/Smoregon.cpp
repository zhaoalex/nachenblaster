//
//  Smoregon.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#include "Smoregon.h"
#include "GameConstants.h"
#include "RepairGoodie.h"
#include "TorpedoGoodie.h"
#include "Turnip.h"

void Smoregon::possiblyDropGoodie() {
    int rand = randInt(1, 6); // 1/3 chance to drop a goodie
    if (rand == 1) { // 50% chance it's repair goodie
        getWorld()->addActor(new RepairGoodie(getWorld(), getX(), getY()));
    } else if (rand == 2) { // 50% chance it's torpedo goodie
        getWorld()->addActor(new TorpedoGoodie(getWorld(), getX(), getY()));
    }
}

bool Smoregon::possiblyFireAtPlayer() {
    int rand = randInt(1, (20 / getWorld()->getLevel()) + 5);
    if (rand == 1) { // fire at player
        getWorld()->addActor(new Turnip(getWorld(), getX() - 14, getY()));
        getWorld()->playSound(SOUND_ALIEN_SHOOT);
        return true;
    } else if (rand == 2) { // ram into player
        setDeltaY(0);
        setFlightLength(VIEW_WIDTH);
        setSpeed(5.0);
        return false;
    }
    return false;
}
