#pragma once

#include "ShotBase.h"

class ShotSecond : public ShotBase
{
public:
	ShotSecond() {}
	virtual ~ShotSecond() {}

	//ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();

};
