#include "LogoScene.h"
#include"cocos2d.h"
#include"HelloWorldScene.h"
USING_NS_CC;
Scene* LogoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	
	
	scene->addChild(layer);
	return scene;
}
bool LogoScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	static auto logo = Sprite::create("mySprite.png");
	logo->setPosition(screenSize.width / 2, screenSize.height / 2);
	logo->setScale(0.6);
	addChild(logo);
	auto moveTo = MoveTo::create(2, Vec2(200,200));
	logo->runAction(moveTo);
	//logo->setPosition(50, 200 ); 
	//logo->setRotation(45);
	//logo->setRotationX(20);
	//logo->setColor(Color3B(0, 0, 255));
	/*logo->setOpacity(100);
	logo->setAnchorPoint(Vec2(0, 0));*/
	//auto rotateTo = RotateTo::create(5.0f, 180.0f); // (Thoi gian,Goc)
	//logo->runAction(rotateTo);
	//auto rotateBy = RotateBy::create(2.0f, 40.0f); // (Thoi gian,Goc)
	//logo->runAction(rotateBy);
	/*auto scale = ScaleTo::create(2.0f, 3.0f);
	logo->runAction(scale);*/
	/*auto scale1 = ScaleTo::create(2.0f, 3.0f,3.0f);
	logo->runAction(scale1);*/
	/*auto scale = ScaleBy::create(2.0f, 3.0f);
	logo->runAction(scale);*/
	/*auto moveTo = MoveTo::create(2, Vec2(200,200));
	logo->runAction(moveTo);*/
	//auto moveBy = MoveBy::create(2, Vec2(50, 50));
	//logo->runAction(moveBy);
	/*auto FadeIn = FadeIn::create(1.0f);
	logo->runAction(FadeIn);*/
	/*auto FadeOut = FadeOut::create(5.0f);
	logo->runAction(FadeOut);*/
	/*auto tintTo = TintTo::create(2.0f, 120.0f, 232.0f, 254.0f);
	logo->runAction(tintTo);*/
	
	/*auto moveTo = MoveTo::create(2, Vec2(400, 240));
	auto callbackHide = CallFunc::create([]() {
    logo->setVisible(false);
	});
	auto sequence = Sequence::create(moveTo, callbackHide, nullptr);
	logo->runAction(sequence);
	
	*/
	//addChild(logo);
	/*auto moveBy = MoveBy::create(4, Vec2(200, 100));
	auto rotateBy = RotateBy::create(4, 360);
	auto spawn = Spawn::create(moveBy, rotateBy, nullptr);
	logo->runAction(spawn);*/
	//auto fadeOut = FadeOut::create(2);
	//auto fadeIn = FadeIn::create(2);
	//auto move = MoveBy::create(3, Vec2(400, 100));
	//auto rotate = RotateBy::create(3, 360);
	//auto spawn_move_rotate = Spawn::create(move, rotate, nullptr);
	//auto sequence_spawn = Sequence::create(spawn_move_rotate, fadeOut,
	//	fadeIn, nullptr);
	//logo->runAction(sequence_spawn);
	///*auto heroSprite = Sprite::create("mySprite.png");
	/*auto enemySprite = Sprite::create("mySprite.png");
	enemySprite->setPosition(100, 100);
	addChild(enemySprite);
	auto hero = Sprite::create("fire_controller_normal.png");
	addChild(hero);
	auto moveBy = MoveBy::create(10, Vec2(400, 100));
	hero->runAction(moveBy);
	enemySprite->runAction(moveBy->clone());*/
	return true;
}