#include "Model.h"
#include "Rock.h"
#include "Defines.h"
#include "cocos2d.h"

Rock::Rock(cocos2d::Scene * scene) : Model()
{
	mSprite = cocos2d::Sprite::create(IMG_ROCK);
	this->SetSprite(mSprite);
	this->SetAlive(false);
	scene->addChild(mSprite);
	auto step = cocos2d::random(ROCK_MIN_STEP, ROCK_MAX_STEP);
	this->SetStep(step);
}

Rock::~Rock()
{
}

void Rock::Init()
{
	auto posX = cocos2d::random(this->GetSprite()->getContentSize().width / 2, SCREEN_W - this->GetSprite()->getContentSize().width / 2);
	auto posY =SCREEN_H + this->GetSprite()->getContentSize().height / 2 ;
	this->SetPosition(cocos2d::Vec2(posX,posY));
}

void Rock::Update()
{
	if (this->IsAlive())
	{
		mSprite->setPosition(this->GetPosition() - cocos2d::Vec2(0, this->GetStep()));
	if (GetPosition().y <= -mSprite->getContentSize().height / 2)
	{
			SetAlive(false);
		}
	}
}

void Rock::SetStep(int step)
{
	this->mStep = step;
}

int Rock::GetStep()
{
	return this->mStep;
}
