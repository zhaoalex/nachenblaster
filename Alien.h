//
//  Alien.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//

#ifndef Alien_h
#define Alien_h

#include "DamageableObject.h"
#include "StudentWorld.h"

class Alien : public DamageableObject {
public:
    Alien(StudentWorld* world, int imageID, double startX, double startY, double health, double damage, double deltaX, double deltaY, double speed, unsigned int scoreValue)
    : DamageableObject(world, imageID, startX, startY, 0, 1.5, 1, health) {
        world->recordAlienOnScreen();
        
        m_damage = damage;
        m_dx = deltaX;
        m_dy = deltaY;
        m_speed = speed;
        m_scoreValue = scoreValue;
    }
    virtual ~Alien() { getWorld()->recordAlienOffScreen(); }
    
    virtual void doSomething();
    virtual void sufferDamage(double amt, int cause);
    
    void setDeltaY(double dy); // TODO protected?
    void setSpeed(double speed);
    
    virtual bool damageCollidingPlayer(double amt);
    virtual void possiblyDropGoodie();
    
    virtual bool isAlien() const { return true; } // override to return true for all aliens
private:
    double m_damage;
    double m_dx;
    double m_dy;
    double m_speed;
    unsigned int m_scoreValue;
};

#endif /* Alien_h */
