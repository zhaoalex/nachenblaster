//
//  Alien.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/28/18.
//  Copyright © 2018 David Smallberg. All rights reserved.
//

#include "Alien.h"

void Alien::doSomething() {
    if (!isAlive()) return;
    if (isOffScreenLR()) {
        setDead();
        return;
    }
    
    
}



void Alien::sufferDamage(double amt, int cause) {
    
}
