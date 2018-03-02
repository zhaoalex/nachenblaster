//
//  Goodie.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#ifndef Goodie_h
#define Goodie_h

#include "Actor.h"

class StudentWorld;
class NachenBlaster;

class Goodie : public Actor {
public:
    Goodie(StudentWorld* world, int imageID, double startX, double startY)
    : Actor(world, imageID, startX, startY, 0, 0.5, 1) {}
    virtual ~Goodie() {}
    
    virtual void doSomething();
    
protected:
    virtual void grantPowerup(NachenBlaster* player) = 0;
    
private:
    bool handleCollide();
};

#endif /* Goodie_h */
