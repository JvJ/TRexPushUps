#ifndef TREXMAINSCENE_H
#define TREXMAINSCENE_H

#include "cocos2d.h"

#include <string>


enum TRexButtons{
	NEW_GAME,
	OPTIONS,
	NUM_BUTTONS
};



class TrexMainScene : public cocos2d::CCLayer
{
public:

	static const int BUTTON_SPACING = 30;

	static const char *tRexButtonTitles[];

	virtual bool init();

	static cocos2d::CCScene *scene();

	// Just copying this from the tutorial,
	// but it's probably still useful.
	void menuCloseCallback(CCObject *pSender);

	// this callback
	void switchSceneCallback(CCObject *pSender);

	// touch callback
	void ccTouchBegan(
		cocos2d::CCSet *pTouches,
		cocos2d::CCEvent *pEvent);

	// Implement the "static node()" method manually..
	// I'm not totally sure what this means
	CREATE_FUNC(TrexMainScene);
};

#endif