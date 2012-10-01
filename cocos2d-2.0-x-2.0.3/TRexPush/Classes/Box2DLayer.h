//
//  Box2DLayer.h
//  TrexPush
//
//  Created by Nelson Andre on 12-10-01.
//
//

#pragma once

#include <iostream>

#include "Box2D/Box2D.h"
#include "cocos2d.h"

#define PTM_RATIO 32

using namespace cocos2d;



class Box2DLayer : public CCLayer
{
    b2World* world;
    
    
public: Box2DLayer();
    ~Box2DLayer();
    
    void initPhysics();
    void update(float dt);
    
    
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
    virtual void draw();
    
};
