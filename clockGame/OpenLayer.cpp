#include"OpenLayer.h"

// 解决中文乱码问题
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

bool OpenLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();

	// label设置
	Label * label = Label::createWithSystemFont("时钟程序", "", 48);
	label->setPosition(Vec2(winSize.width / 2, winSize.height * 3 / 4));
	label->setColor(Color3B(255, 0, 0));
	this->addChild(label);

	// 添加按钮
	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("开始", "", 30),
													CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(winSize.width / 2, winSize.height * 0.3);

	MenuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("退出", "", 30),
		CC_CALLBACK_1(OpenLayer::menuCallBack, this));
	menuItem_2->setTag(102);
	menuItem_2->setPosition(winSize.width / 2, winSize.height * 0.15);

	auto menu = Menu::create(menuItem, menuItem_2, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return  true;
}

void OpenLayer::menuCallBack(Ref * pSender) {
	switch (((MenuItem *)pSender)->getTag()) {
	case 101:
		tsm->goClockScene();
		break;
	case 102:
		Director::getInstance()->end();
		exit(0);
		break;
	default:
		break;
	}
}