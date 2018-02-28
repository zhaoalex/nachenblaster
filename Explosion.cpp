//
//  Explosion.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/27/18.
//

#include "Explosion.h"

void Explosion::doSomething() {
    if (m_time == 4) {
        setDead(); // set dead after 4 ticks
    }
    setSize(getSize() * 1.5);
    m_time++;
}
