#pragma once

#include<vector>
#include "player.h"
#include "ShotBase.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();

	//弾の生成
	bool creatShot(Vec2 pos);

	bool creatShotSecond(Vec2 pos);

	bool creatShotThird(Vec2 pos);
	
//private:
//	// ショットの最大数
//	static constexpr int kShotMax = 64;

private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// ショット
	std::vector<ShotBase*> m_ShotVt;
	//ShotNormal m_shot[kShotMax];
};