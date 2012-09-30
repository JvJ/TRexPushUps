#include "TrexMainScene.h"
#include <vector>
#include <iostream>

USING_NS_CC;

using namespace std;

const char* tRexButtonTitles[NUM_BUTTONS]={
	"New Game",
	"Options"
};

// The static scene
CCScene* TrexMainScene::scene(){

	// These are so-called auto-release objects
	auto *scene = CCScene::create();
	auto *layer = TrexMainScene::create();

	// Add the initial layer
	scene->addChild(layer);

	return scene;
}

// initialize the instance
bool TrexMainScene::init(){

	// Super init
	if (!CCLayer::init() ){
		return false;
	}

	// Visual size and coordinates
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	// Menu items added
	//auto *pCloseItem = CCMenuItemImage::create(
	//	"CloseNormal.png",
	//	"CloseSelected.png",
	//	this,
	//	menu_selector(TrexMainScene::menuCloseCallback));
    
	auto *lbl = CCLabelTTF::create("FACK", "Arial", 24.0);
	auto *pCloseItem = CCMenuItemLabel::create(lbl, this, menu_selector(TrexMainScene::menuCloseCallback));

	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2,
			origin.y + pCloseItem->getContentSize().height/2));

	// Create the menu, which is apparently also autorelease
    
	CCMenu *pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	// Now to create the BG
	CCSprite *pSprite = CCSprite::create("HelloWorld.png");

	pSprite->setPosition(
		ccp(visibleSize.width/2 + origin.x,
			visibleSize.height/2 + origin.y));

    auto *rotateAction = CCRotateBy::create(1.0f, 30.0f);
    
    auto *repeateAction = CCRepeatForever::create(rotateAction);
    
	// add that spriterizer
	this->addChild(pSprite, 0);

    //rotate that sprite
    pSprite->runAction(repeateAction);
    
	this->setTouchEnabled(true);

	return true;
}

void TrexMainScene::menuCloseCallback(CCObject *pSender){

	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void TrexMainScene::switchSceneCallback(CCObject *pSender){

	//CCDirector::sharedDirector()->replaceScene(CCScene::create());
	CCDirector::sharedDirector()->end();
}

void TrexMainScene::ccTouchBegan(CCSet *pTouches, CCEvent *pEvent){

	CCTouch *touch = (CCTouch *)(* pTouches->begin());
	CCPoint pos = touch->getLocation();

	CCLog("TOUCH ME HERE: (%f, %f)", pos.x, pos.y);
}