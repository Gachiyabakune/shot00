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

	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();

private:
	//���˕Ԃ�����
	int m_boundCount;
};