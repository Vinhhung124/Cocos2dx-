#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include"SpaceShip.h"
#include"Bullet.h"
#include<vector>
#include"Defines.h"
#include <iostream>
using namespace std;
using namespace cocos2d;
Vec2 mOldLocation;
SpaceShip *space;
Bullet *bullet;
vector<Rock*> listRock;
Rock *r;
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}


bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create(IMG_BACKGROUND);
	background->setPosition(SCREEN_W / 2, SCREEN_H / 2);
	background->setScale(1.5);
	addChild(background);


	space = new SpaceShip(this);
	space->Init();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, space->GetSprite());



	
	for (int i = 0; i < 10; i++)
	{
		Rock *rock = new Rock(this);
		rock->Init();
		listRock.push_back(rock);
		
	}

	scheduleUpdate();
	mScore = 0;
	mLabelScore = Label::createWithTTF(std::to_string(mScore), "fonts/arial.ttf",40);
	mLabelScore->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height *0.9));
	this->addChild(mLabelScore, 5);


    return true;
}

void HelloWorld::update(float delta)
{
	space->Update();
	for (int i = 0; i < listRock.size(); i++)
	{
		listRock.at(i)->Update();
	}

	mFrameCount++;
	if (mFrameCount % 4 == 0) {
		for (int i = 0; i < listRock.size(); i++) {
			if (!listRock.at(i)->IsAlive()) {
				listRock.at(i)->Init();
				listRock.at(i)->SetAlive(true);
		
			}
		}
	}
	for (int i = 0; i < listRock.size(); i++)
	{
		if (listRock.at(i)->IsAlive())
		{
			if (space->CheckColisionBulletWithRock(listRock.at(i)))
			{
				listRock.at(i)->SetAlive(false);
				mScore++;
				mLabelScore->setString(std::to_string(mScore));
			
				
				
			}
			
			
			if (space->CheckColisionWithRock(listRock.at(i)))
			{
				listRock.at(i)->SetAlive(false);
		
				CCLOG("Die");

			}
		}
	}
}
bool HelloWorld::onTouchBegan(Touch* touch, Event *event) {
	mOldLocation = touch->getLocation();
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event *event) {
	auto SpaceLocation = space->GetSprite()->getPosition();
	auto newTouch = touch->getLocation();
	space->GetSprite()->setPosition(Vec2(SpaceLocation.x - (mOldLocation.x - newTouch.x),
		                                 SpaceLocation.y - (mOldLocation.y - newTouch.y)));
	mOldLocation = newTouch;
}
void HelloWorld::onTouchEnded(Touch* touch, Event *event) {
	
}

