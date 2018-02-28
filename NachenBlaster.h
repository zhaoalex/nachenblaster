//
//  NachenBlaster.h
//  NachenBlaster
//
//  Created by Alex Zhao on 2/20/18.
//

#ifndef NachenBlaster_h
#define NachenBlaster_h

#include "DamageableObject.h"

class NachenBlaster : public DamageableObject {
public:
    NachenBlaster(StudentWorld* world)
    : DamageableObject(world, IID_NACHENBLASTER, 0, 128, 0, 1.0, 0, 50) {
        m_cabbages = 30;
        m_torpedoes = 0;
    }
    virtual ~NachenBlaster() {}
    
    virtual void doSomething();
    void incHealth(double amt);
    virtual void sufferDamage(double amt, int cause);
    
    void incTorpedoes(int amt) { m_torpedoes += amt; }
    int numTorpedoes() const { return m_torpedoes; }
    int numCabbages() const { return m_cabbages; }
    
private:
    int m_cabbages;
    int m_torpedoes;
};

#endif /* NachenBlaster_h */
