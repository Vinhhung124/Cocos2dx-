#include "sc2.h"
#include"cocos2d.h"
#include"ui\CocosGUI.h"


using namespace std;
USING_NS_CC;
Sprite *icon;
Scene* sc2::createScene()
{
	auto scene = Scene::create();
	auto layer = sc2::create();
	scene->addChild(layer);
	return scene;
}
bool sc2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	static auto bg = Sprite::create("bgg.jpg");
	bg->setPosition(screenSize.width / 2, screenSize.height / 2);
	bg->setScale(0.5);
	addChild(bg);
	//Creat label with TTF
	auto myLabel = Label::createWithTTF("Hello World!", "fonts/Marker Felt.ttf", 24);
	myLabel->setPosition(screenSize.width / 2, screenSize.height - 50);
	addChild(myLabel);
	//myLabel->enableOutline(Color4B::BLUE, 2); // Set outline
	myLabel->enableGlow(Color4B::RED); //Set 1 color
	icon = Sprite::create("heart.png");
	icon->setPosition(Vec2(0, 0));
	addChild(icon);

	// Creat animaion 
	auto beeMC = Sprite::create();
	beeMC->setPosition(screenSize.width / 2, 100);
	addChild(beeMC);
	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("bee1.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee2.png", Rect(0, 0, 150, 150)));
	animFrames.pushBack(SpriteFrame::create("bee3.png", Rect(0, 0, 150, 150)));
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	beeMC->runAction(RepeatForever::create(animate));
	auto move = MoveTo::create(2, Vec2(100, 100));
	
	auto move1 = MoveBy::create(2, Vec2(300, 400));
	auto squence = Sequence::create(move, move1, nullptr);
	//beeMC->runAction(squence);
	
	//Creat Particle Effect with Practice2dx
	auto emo = ParticleSystemQuad::create("particles/menu.plist");
	addChild(emo);

	//Particle Effect available
	/*
	auto e = ParticleFireworks::create();
	auto e = ParticleFire::create();
	auto e = ParticleSun::create();
	auto e = ParticleGalaxy::create();
	auto e = ParticleFlower::create();
	auto e = ParticleMeteor::create();
	auto e = ParticleSpiral::create();
	auto e = ParticleSmoke::create();
	auto e = ParticleExplosion::create();
	auto e = ParticleSnow::create();
	auto e = ParticleRain::create();
	addChild(e);
	*/

	// OnTouch
	//Tao su kien xu li 1 diem cham tren man hinh
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(sc2::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(sc2::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(sc2::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	
	return true;
}
bool sc2::onTouchBegan(Touch* touch, Event *event) {
	Vec2 touchLocation = touch->getLocation(); // Toa do cham tren man hinh
	//icon->setPosition(touchLocation);
	auto moveTo = MoveTo::create(2, touchLocation);
	icon->runAction(moveTo);
	return true;
}
void sc2::onTouchMoved(Touch* touch, Event *event) {
	Vec2 touchLocation = touch->getLocation(); 
	icon->setPosition(touchLocation);
}
void sc2::onTouchEnded(Touch* touch, Event *event) {
	icon->setPosition(Vec2(0, 0));
}