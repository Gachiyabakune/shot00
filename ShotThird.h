#pragma once

#include "ShotBase.h"

class ShotThird : public ShotBase
{
public:
	ShotThird()
	{
		m_boundCount = 0;
	}
	virtual ~ShotThird()
	{
	}

	//ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();

private:
	//跳ね返った回数
	int m_boundCount;
};