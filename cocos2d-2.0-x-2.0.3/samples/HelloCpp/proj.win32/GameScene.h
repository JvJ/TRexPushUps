#pragma once

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
public:
	
	virtual bool init();

	static cocos2d::CCScene *scene();

	void menuCloseCallback(CCObject *pSender);

	
};

