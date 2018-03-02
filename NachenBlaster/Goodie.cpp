//
//  Goodie.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#include "Goodie.h"
#include "NachenBlaster.h"
#include "StudentWorld.h"

void Goodie::doSomething() {
    if (!isAlive()) return;
    if (isOffScreenLR() || getY() < 0 || getY() >= VIEW_HEIGHT) {
        setDead();
        return;
    }
    if (didCollide()) return;
    moveTo(getX() - 0.75, getY() - 0.75);
    if (didCollide()) return;
}

/**
 * Handles collision of goodies with the player.
 * Returns true if goodie did collide with the player.
 */
bool Goodie::didCollide() {
    NachenBlaster* player = getWorld()->getCollidingPlayer(this);
    if (player != nullptr) { // if collided
        getWorld()->increaseScore(100);
        setDead();
        getWorld()->playSound(SOUND_GOODIE);
        grantPowerup(player);
        return true;
    }
    return false;
}
