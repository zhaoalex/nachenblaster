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
    Alien(StudentWorld* world, int imageID, double startX, double startY, double health, double ramDamage, double deltaY, double speed, unsigned int scoreValue, bool usesFlightLength)
    : DamageableObject(world, imageID, startX, startY, 0, 1.5, 1, health) {
        world->recordAlienOnScreen();
        
        m_ramDamage = ramDamage;
        m_dy = deltaY;
        m_speed = speed;
        m_scoreValue = scoreValue;
        m_flightLength = (usesFlightLength) ? 0 : -1; // see declaration
    }
    virtual ~Alien() { getWorld()->recordAlienOffScreen(); }
    
    virtual void doSomething();
    virtual void sufferDamage(double amt, int cause);
    
    virtual bool isAlien() const { return true; } // override to return true for all aliens
protected:
    virtual void possiblyDropGoodie() = 0;
    virtual bool possiblyFireAtPlayer() = 0;
    
    void setDeltaY(double y) { m_dy = y; }
    void setSpeed(double speed) { m_speed = speed; }
    void setFlightLength(int length) { m_flightLength = length; }
private:
    bool damageCollidingPlayer();
    void die();
    
    double m_ramDamage;
    double m_dy;
    double m_speed;
    unsigned int m_scoreValue;
    
    int m_flightLength; // starting length 0 means it uses flight length (i.e. Smallgon/Smoregon); starting length -1 means it doesn't (Snagglegon) since length will never hit 0 and reset
};

#endif /* Alien_h */
