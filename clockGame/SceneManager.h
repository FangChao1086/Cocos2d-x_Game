#ifndef __HelloWorld_SceneManager__
#define __HelloWorld_SceneManager__
#include<iostream>
#include"cocos2d.h"

USING_NS_CC;

class SceneManager {
public:
	Scene * loadScene;
	Scene * openScene;
	Scene * clockScene;

	void createLoadScene();
	void goOpenScene();
	void goClockScene();
};
#endif
