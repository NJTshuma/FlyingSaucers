#pragma once
#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(Point2f pos) :GameObject(pos) { m_pos = pos;};
	~Player() {};

	void Update(GameState& state) override;
	void Draw(GameState& state) const override;


private:

};
