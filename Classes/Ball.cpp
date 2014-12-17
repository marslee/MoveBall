/*
 * Ball.cpp
 *
 *  Created on: 2014-12-16
 *      Author: Administrator
 */

#include "Ball.h"


bool Ball::init()
{
	if(!Sprite::initWithFile("Ball.png"))
	{
		return false;
	}

	speedX = CCRANDOM_0_1()*10 - 5;
	speedY = CCRANDOM_0_1()*10 - 5;

	return true;
}

void Ball::move()
{
	setPosition(getPositionX() + speedX, getPositionY() + speedY);
	if(getPositionX() < 0)
	{
		speedX = fabsf(speedX);
	}
	if(getPositionX() > Director::getInstance()->getVisibleSize().width)
	{
		speedX = -fabsf(speedX);
	}
	if(getPositionY() < 0)
	{
		speedY = fabsf(speedY);
	}
	if(getPositionY() > Director::getInstance()->getVisibleSize().height)
	{
		speedY = -fabsf(speedY);
	}
}
