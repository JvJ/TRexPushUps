#include "GameScene.h"


USING_NS_CC;


CCScene *GameScene::scene(){

	auto *scene = CCScene::create();
	auto *layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init(){

	// Super init
	if (!CCLayer::init()){
		return false;
	}

	// Visual size and coordinates
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	return true;
}