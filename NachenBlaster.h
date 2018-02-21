//
//  NachenBlaster.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/20/18.
//

#ifndef NachenBlaster_h
#define NachenBlaster_h

#include "Actor.h"

class NachenBlaster : public Actor {
public:
    NachenBlaster(StudentWorld* world)
    : Actor(world, IID_NACHENBLASTER, 0, 128) {
        m_health = 50;
        m_cabbage = 30;
        m_torpedoes = 0;
    }
    virtual ~NachenBlaster() {}
    
    virtual void doSomething();
private:
    int m_health;
    int m_cabbage;
    int m_torpedoes;
};

#endif /* NachenBlaster_h */
