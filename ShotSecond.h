#pragma once

#include "ShotBase.h"

class ShotSecond : public ShotBase
{
public:
	ShotSecond() {}
	virtual ~ShotSecond() {}

	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();

};
