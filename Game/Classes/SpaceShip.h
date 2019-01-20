#pragma once
#include "cocos2d.h"
#include "SpaceShip.h"
#include "Model.h"
#include <vector>
#include"Bullet.h"
using namespace cocos2d;
using namespace std;
class SpaceShip : public Model
{
public:
	SpaceShip(cocos2d::Scene *scene);
	~SpaceShip();
	virtual	void Init();
	virtual	void Update();
	bool CheckColisionWithRock(Rock *rock);

	bool CheckColisionBulletWithRock(Rock *rock);

private:
	vector<Bullet*> listBullet;
	int mIndexBullet;
	int mFrameBullet;
};

