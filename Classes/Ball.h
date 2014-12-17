/*
 * Ball.h
 *
 *  Created on: 2014-12-16
 *      Author: Administrator
 */

#ifndef BALL_H_
#define BALL_H_

#include "cocos2d.h"

USING_NS_CC;

class Ball : public Sprite{
public:
	virtual bool init();
	void move();
	CREATE_FUNC(Ball);
private:
	float speedX;
	float speedY;
};

#endif /* BALL_H_ */
