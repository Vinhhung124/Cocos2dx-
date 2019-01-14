#pragma once


#include "cocos2d.h"
using namespace cocos2d;

class sc1 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	void PlayGameClick(cocos2d::Ref* pSender);
	virtual bool init();
	CREATE_FUNC(sc1);
	//cmt
};
