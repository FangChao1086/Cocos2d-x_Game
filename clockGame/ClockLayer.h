#ifndef __CLOCKLAYER__
#define __CLOCKLAYER__

#include<iostream>
#include"cocos2d.h"
#include"SceneManager.h"

USING_NS_CC;

class ClockLayer:public Layer {
public:
	CREATE_FUNC(ClockLayer);
	virtual bool init();

	void menuCallBack(Ref * pSender);
	void timeUpdate(float dt);

public:
	SceneManager * tsm;
	Sprite * _background;
	Sprite * _hour;
	Sprite * _minute;
	Sprite * _second;

	int hRotate = 0;
	int mRotate = 0;
	int sRotate = 0;
};

#endif