#include "DxLib.h"
#include "SceneMain.h"
#include "ShotSecond.h"
#include "ShotNormal.h"

namespace
{
	//�V���b�g�̔��ˊԊu
	const int kShotInterval = 16;
}
SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& pShot : m_ShotVt)
	{
		if (!pShot) continue;
		delete pShot;
		pShot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();

	std::vector<ShotBase*>::iterator it = m_ShotVt.begin();
	while (it != m_ShotVt.end())
	{
		auto& pShot = (*it);

		if (!pShot)
		{
			it++;
			continue;
		}
		pShot->update();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;

			//vector�̗v�f�폜
			it = m_ShotVt.erase(it);
			continue;
		}
		it++;
	}
#if false
	for (auto& pShot : m_ShotVt)
	{
		if (!pShot) continue;
		pShot->update();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;

			//vector�̗v�f�폜

		}
	}
#endif
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_ShotVt)
	{
		if (!pShot)continue;
		pShot->draw();
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�e�̐�:%d", m_ShotVt.size());
}

bool SceneMain::creatShot(Vec2 pos)
{
	ShotNormal* pShot = new ShotNormal;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_ShotVt.push_back(pShot);

	return true;
}

bool SceneMain::creatShotSecond(Vec2 pos)
{
	ShotSecond* pShot = new ShotSecond;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_ShotVt.push_back(pShot);

	return true;
}