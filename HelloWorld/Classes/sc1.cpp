#include "sc1.h"
#include"cocos2d.h"
USING_NS_CC;
Scene* sc1::createScene()
{
	auto scene = Scene::create();
	auto layer = sc1::create();
	scene->addChild(layer);
	return scene;
}
bool sc1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	auto logo = Sprite::create("LogoGL.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	addChild(logo);
	return true;
}