//
//  Star.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/20/18.
//

#ifndef Star_h
#define Star_h

#include "Actor.h"

class StudentWorld;

class Star : public Actor {
public:
    Star(StudentWorld* world, double startX, double startY, double size)
    : Actor(world, IID_STAR, startX, startY, 0, size, 3) {
        
    }
    virtual void doSomething();
private:
    
};

#endif /* Star_h */
