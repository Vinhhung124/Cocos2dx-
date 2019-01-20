#include "Model.h"
#include "Bullet.h"
#include "Defines.h"
#include "cocos2d.h"
using namespace cocos2d;


Bullet::Bullet(cocos2d::Scene * scene) : Model()
{

	mSprite = cocos2d::Sprite::create(IMG_BULLET);
	this->SetSprite(mSprite);
	scene->addChild(mSprite);
	

}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	SetAlive(false);
}

void Bullet::Update()
{
	if (IsAlive()) {
		mSprite->setPosition(cocos2d::Vec2(GetLocation().x, GetLocation().y + 10));
		if (GetLocation().y >= SCREEN_H + mSprite->getContentSize().height/2) {
			SetAlive(false);
		}
	}

	
}

void Bullet::SetStep(int step)
{
	this->mStep = step;
}

int Bullet::GetStep()
{
	return this->mStep;
}


void Bullet::UpdateLocation(cocos2d::Vec2 location)
{
	mSprite->setPosition(location);
}