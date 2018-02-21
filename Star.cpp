//
//  Star.cpp
//  NachenBlaster
//
//  Created by Alex Zhao on 2/20/18.
//

#include "Star.h"
#include "GraphObject.h"

void Star::doSomething() {
    if (getX() <= -1) {
        setState(false);
    } else {
        moveTo(getX() - 1, getY());
    }
}
