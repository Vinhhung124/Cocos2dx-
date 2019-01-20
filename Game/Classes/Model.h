#pragma once
#include "cocos2d.h"
#include"ui\CocosGUI.h"
using namespace cocos2d;
class Model
{
public:
	Model();
	~Model();
	cocos2d::Vec2 GetLocation();
	virtual	void Init() = 0;
	virtual	void Update() = 0;

	cocos2d::Sprite* GetSprite();
	void SetSprite(cocos2d::Sprite* sprite);

	void SetAlive(bool alive);
	bool IsAlive();

	cocos2d::Vec2 GetPosition();
	void SetPosition(cocos2d::Vec2 pos);
	Rect GetRect();
protected:
	cocos2d::Sprite* mSprite;
	bool mIsAlive;
};

