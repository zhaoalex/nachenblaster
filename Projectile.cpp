//
//  Projectile.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#include "Projectile.h"
#include "StudentWorld.h"
#include "DamageableObject.h"
#include "NachenBlaster.h"

void Projectile::doSomething() {
    if (!isAlive()) return;
    if (isOffScreenLR()) {
        setDead();
        return;
    }
    // check collide the first time
    if (didCollide()) return;
    
    // update position
    moveTo(getX() + m_deltaX, getY());
    if (m_rotates) setDirection(getDirection() + 20); // projectiles that rotate always rotate 20 degrees CCW
    
    // after move, check collide again
    if (didCollide()) return;
}

bool Projectile::didCollide() {
    /*if (m_playerEnemy) { // if player is enemy
        NachenBlaster* player = getWorld()->getCollidingPlayer(this);
        if (player != nullptr) {
            player->sufferDamage(m_damageAmt, 1);
        } else {
            return;
        }
    } else { // if alien is enemy
        DamageableObject* alien = getWorld()->getCollidingAlien(this);
        if (alien != nullptr) {
            alien->sufferDamage(m_damageAmt, 1);
        } else {
            return;
        }
    }*/
    
    /*DamageableObject* actor;
    if (m_playerEnemy) { // if player is enemy
        actor = getWorld()->getCollidingPlayer(this);
        // actor = player;
    } else { // if alien is enemy
        actor = getWorld()->getCollidingAlien(this);
    }
    if (actor != nullptr) {
        
    }*/
    
    // is enemy is player, call player collide; is enemy is alien, call alien collide
    DamageableObject* actor = (m_playerEnemy) ? getWorld()->getCollidingPlayer(this) : getWorld()->getCollidingAlien(this);
    if (actor != nullptr) {
        actor->sufferDamage(m_damageAmt, HIT_BY_PROJECTILE);
        setDead();
        return true;
    }
    return false;
}
