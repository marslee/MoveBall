/*
 * MoveBalls.cpp
 *
 *  Created on: 2014-12-16
 *      Author: Administrator
 */

#include "MoveBalls.h"


Scene* MoveBalls::createScene()
{
	auto s = Scene::create();
	auto l = MoveBalls::create();
	s->addChild(l);
	return s;
}

bool MoveBalls::init()
{
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();

    Vec2 origin= Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png",
    										"CloseSelected.png",
    										CC_CALLBACK_1(MoveBalls::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    for(int i = 0; i < 10; i++)
    {
    	addBall(origin.x + CCRANDOM_0_1()*200, origin.y + CCRANDOM_0_1()*200);
    }

    scheduleUpdate();

    return true;
}

void MoveBalls::update(float dt)
{
	//ball->move();
	for (auto it = balls.begin(); it != balls.end(); it++)
	{
		(*it)->move();
	}

}

void MoveBalls::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}

void MoveBalls::addBall(float x, float y)
{
    ball = Ball::create();
    ball->setPosition(x, y);
    ball->setScale(0.3, 0.3);
    addChild(ball);

    balls.pushBack(ball);
}
