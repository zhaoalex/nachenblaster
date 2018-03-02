//
//  Alien.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//  Copyright © 2018 David Smallberg. All rights reserved.
//

#include "Alien.h"
#include "NachenBlaster.h"
#include "Explosion.h"

void Alien::doSomething() {
    if (!isAlive()) return;
    if (isOffScreenLR()) {
        setDead();
        return;
    }
    
    // check for collision with player (projectile collision is handled by Projectile)
    if (damageCollidingPlayer()) return;
    
    // possibly change flight plan
    if (getY() >= VIEW_HEIGHT - 1 || getY() <= 0) {
        if (getY() >= VIEW_HEIGHT - 1) {
            setDeltaY(-1);
        } else if (getY() <= 0) {
            setDeltaY(1);
        }
        if (m_flightLength >= 0) { // only change flight length if it uses flight length
            m_flightLength = randInt(1, 32);
        }
    }
    if (m_flightLength == 0) { // aliens that don't use flight length will always skip this check
        setDeltaY(randInt(-1, 1));
        m_flightLength = randInt(1, 32);
    }
    
    // possibly fire at player
    if (getWorld()->playerInLineOfFire(this)) {
        if (possiblyFireAtPlayer()) return;
    }
    
    // move in travel direction
    moveTo(getX() + (-1 * m_speed), getY() + (m_dy * m_speed));
    m_flightLength--;
    
    // check collision once again
    if (damageCollidingPlayer()) return;
}


/**
 * Called when the alien suffers damage.
 * This only handles collisions with projectiles, as damageCollidingPlayer() will handle all collisions with NachenBlaster.
 */
void Alien::sufferDamage(double amt, int cause) {
    setHealth(getHealth() - amt);
    // only cause will be projectiles; no need to check
    if (getHealth() <= 0) {
        die();
    } else {
        getWorld()->playSound(SOUND_BLAST);
    }
}

/**
 * Check if the alien ship has collided with the player.
 * Leave this logic to Alien, as it is the one crashing into the player.
 * Leave projectile collision logic to Projectile for the same reason.
 */
bool Alien::damageCollidingPlayer() {
    NachenBlaster* player = getWorld()->getCollidingPlayer(this);
    if (player != nullptr) {
        player->sufferDamage(m_ramDamage, HIT_BY_SHIP);
        die();
        return true;
    }
    return false;
}

/**
 * Handles logic upon alien death.
 */
void Alien::die() {
    setDead();
    getWorld()->increaseScore(m_scoreValue);
    getWorld()->playSound(SOUND_DEATH);
    getWorld()->addActor(new Explosion(getWorld(), getX(), getY()));
    possiblyDropGoodie();
    getWorld()->recordAlienDestroyed();
}
