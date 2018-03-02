//
//  Snagglegon.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 3/1/18.
//

#include "Snagglegon.h"
#include "ExtraLifeGoodie.h"
#include "AlienLaunchedTorpedo.h"

void Snagglegon::possiblyDropGoodie() {
    int rand = randInt(1, 6); // 1/6 chance to drop an extra life goodie
    if (rand == 1) {
        getWorld()->addActor(new ExtraLifeGoodie(getWorld(), getX(), getY()));
    }
}

bool Snagglegon::possiblyFireAtPlayer() {
    int rand = randInt(1, (15 / getWorld()->getLevel()) + 10);
    if (rand == 1) { // fire at player
        getWorld()->addActor(new AlienLaunchedTorpedo(getWorld(), getX() - 14, getY()));
        getWorld()->playSound(SOUND_TORPEDO);
        return true;
    }
    return false;
}
