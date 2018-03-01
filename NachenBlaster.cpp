//
//  NachenBlaster.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/20/18.
//

#include "NachenBlaster.h"
#include "StudentWorld.h"
#include "GameWorld.h"

#include "Cabbage.h"
#include "PlayerLaunchedTorpedo.h"

void NachenBlaster::doSomething() {
    if (!isAlive()) return;
    int ch;
    if (getWorld()->getKey(ch)) {
        switch (ch) {
            case KEY_PRESS_LEFT:
                if (getX() - 6 < 0) break; // can't move off screen
                moveTo(getX() - 6, getY());
                // TODO: check collision
                break;
            case KEY_PRESS_RIGHT:
                if (getX() + 6 >= VIEW_WIDTH) break;
                moveTo(getX() + 6, getY());
                // TODO: check collision
                break;
            case KEY_PRESS_DOWN:
                if (getY() - 6 < 0) break;
                moveTo(getX(), getY() - 6);
                // TODO: check collision
                break;
            case KEY_PRESS_UP:
                if (getY() + 6 >= VIEW_HEIGHT) break;
                moveTo(getX(), getY() + 6);
                // TODO: CHECK FOR COLLISION
                break;

            case KEY_PRESS_SPACE: // fire cabbage
                if (m_cabbages >= 5) {
                    getWorld()->addActor(new Cabbage(getWorld(), getX() + 12, getY()));
                    getWorld()->playSound(SOUND_PLAYER_SHOOT);
                    m_cabbages -= 5;
                }
                break;
            case KEY_PRESS_TAB: // fire torpedo
                if (m_torpedoes > 0) {
                    getWorld()->addActor(new PlayerLaunchedTorpedo(getWorld(), getX() + 12, getY()));
                    getWorld()->playSound(SOUND_TORPEDO);
                    m_torpedoes--;
                }
                break;
        }
    }
    
    // Receive one cabbage point per tick
    if (m_cabbages < 30) {
        m_cabbages++;
    }
}

void NachenBlaster::incHealth(double amt) {
    if (getHealth() + amt > 50) setHealth(50);
    else setHealth(getHealth() + amt);
}

void NachenBlaster::sufferDamage(double amt, int cause) {
    
}
