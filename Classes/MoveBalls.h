/*
 * MoveBalls.h
 *
 *  Created on: 2014-12-16
 *      Author: Administrator
 */

#ifndef MOVEBALLS_H_
#define MOVEBALLS_H_

#include "cocos2d.h"
#include "Ball.h"

USING_NS_CC;

class MoveBalls:public LayerColor {
public:
	virtual bool init();
	virtual void update(float dt);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void addBall(float x, float y);

	static cocos2d::Scene* createScene();

	CREATE_FUNC(MoveBalls);

private:
	Ball *ball;
	cocos2d::Size visibleSize;
	cocos2d::Vector<Ball*> balls;
};

#endif /* MOVEBALLS_H_ */
