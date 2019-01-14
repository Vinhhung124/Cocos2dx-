#pragma once


#include "cocos2d.h"
using namespace cocos2d;


class sc2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	bool sc2::onTouchBegan(Touch* touch, Event *event);
	void sc2::onTouchMoved(Touch* touch, Event *event);
	void sc2::onTouchEnded(Touch* touch, Event *event);
	virtual bool init();
	CREATE_FUNC(sc2);

	//cmt
};
