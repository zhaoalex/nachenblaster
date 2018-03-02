//
//  Projectile.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef Projectile_h
#define Projectile_h

#include "Actor.h"

class StudentWorld;
// class DamageableObject;

class Projectile : public Actor {
public:
    Projectile(StudentWorld* world, int imageID, double startX, double startY, double damageAmt, double deltaX, bool rotates, int dir, bool isPlayerEnemy)
    : Actor(world, imageID, startX, startY, dir, 0.5, 1) {
        m_damageAmt = damageAmt;
        m_deltaX = deltaX;
        m_rotates = rotates;
        m_playerEnemy = isPlayerEnemy;
    }
    virtual ~Projectile() {}
    
    virtual void doSomething();
    
private:
    bool didCollide();
    
    double m_damageAmt;
    double m_deltaX;
    bool m_rotates; // all rotating projectiles rotate by 20 degrees CCW
    bool m_playerEnemy;
};

#endif /* Projectile_h */
