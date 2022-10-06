#include "ShotSecond.h"
#include "game.h"

namespace
{
	//���ɍs���X�s�[�h
	constexpr float kShotSpeedX = 8.0f;
	//�c�ɍs���X�s�[�h
	constexpr float kShotSpeedY = 0.0f;
	//j

}

void ShotSecond::start(Vec2 pos)
{
	ShotSecond::start(pos);

	m_vec.x = kShotSpeedX;
	m_vec.y = kShotSpeedY;
}

void ShotSecond::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;
	
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

