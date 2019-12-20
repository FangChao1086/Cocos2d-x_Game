#include"LoadLayer.h"

bool LoadLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();

	Label * label = Label::create("loading...", "fonts/Marker Felt.ttf", 34);
	label->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(label);

	scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
	
	return true;
}

void LoadLayer::onScheduleOnce(float dt) {
	tsm->goOpenScene();
}