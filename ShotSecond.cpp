#include "ShotSecond.h"
#include "game.h"

namespace
{
	//横に行くスピード
	constexpr float kShotSpeedX = 8.0f;
	//縦に行くスピード
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

