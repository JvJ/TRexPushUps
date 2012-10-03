//
//  GameLayer.cpp
//  TrexPush
//
//  Created by Nelson Andre on 12-10-01.
//
//

#include "GameLayer.h"

CCScene* GameLayer::scene()
{
    CCScene * scene = NULL;
    do
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);
        
        // 'layer' is an autorelease object
        //HelloWorld *layer = HelloWorld::create();
        //CC_BREAK_IF(! layer);
        
        // add layer as a child to scene
        //scene->addChild(layer);
        
        GameLayer* gameLayer = new GameLayer();
		gameLayer->loadSVG("star.svg");
        scene->addChild(gameLayer, 1);
        
        gameLayer->addNewSpriteAtPosition(ccp(100,100));

    } while (0);
    
    // return the scene
    return scene;
}
