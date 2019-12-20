#include"ClockLayer.h"

// ���������������
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

bool ClockLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();

	// ��ӷ��ذ�ť
	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("����", "", 24), CC_CALLBACK_1(ClockLayer::menuCallBack, this));
	menuItem->setPosition(Vec2(winSize.width * 0.9, winSize.height * 0.9));
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	// ���ͼƬ
	// 1��ʱ�ӱ���
	_background = Sprite::create("res/background.jpg");
	_background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	//_background->setScale(0.5);  // ��СͼƬ
	this->addChild(_background);
	// 2��ʱ���������
	_hour = Sprite::create("res/hour.png");
	_hour->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	_hour->setScale(0.5);  // ��С
	_hour->setAnchorPoint(Vec2(0.5, 0));  // ����ê��
	this->addChild(_hour, 1);  // ����1������2��3����ʾ�㼶֮��ĸ��ǹ�ϵ�������ﲻ��Ҳû������
	_minute = Sprite::create("res/minute.png");
	_minute->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	_minute->setScale(0.5);
	_minute->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(_minute, 2);
	_second = Sprite::create("res/second.png");
	_second->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	_second->setScale(0.5);
	_second->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(_second, 3);

	// ϵͳʱ��
	time_t timer;//time_t����long int ����
	struct tm *tm;
	timer = time(NULL);
	tm = localtime(&timer);
	CCLOG("ʱ = %d, �� = %d, �� = %d", tm->tm_hour, tm->tm_min, tm->tm_sec);
	mRotate = tm->tm_min * 6;
	sRotate = tm->tm_sec * 6;
	if (tm->tm_hour > 12) 
		hRotate = (tm->tm_hour - 12) * 5 * 6 + tm->tm_min / 12 * 6;
	else 
		hRotate = tm->tm_hour * 5 * 6 + tm->tm_min / 12 * 6;
	// ��̬��ʾ��ǰʱ��
	_hour->setRotation(hRotate);
	_minute->setRotation(mRotate);
	_second->setRotation(sRotate);

	// ��̬����ʱ��
	schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
	
	return true;
}


void ClockLayer::menuCallBack(Ref * pSender) {
	tsm->goOpenScene();
}


void ClockLayer::timeUpdate(float dt) {
	_second->setRotation(_second->getRotation() + 6);
	if (_second->getRotation() == 360) {
		_second->setRotation(0);
		_minute->setRotation(_minute->getRotation() + 6);
		if (int(_minute->getRotation()) % 72 == 0) {
			_hour->setRotation(_hour->getRotation() + 6);
			if (_hour->getRotation() == 360) {
				_hour->setRotation(0);
			}
		}
	}
}
