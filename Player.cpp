#include "Play.h"
#include "Player.h"
#include "Laser.h"
#include "Saucer.h"

void Player::Update(GameState& state)
{
	if (Play::KeyDown(VK_LEFT))
		m_pos.x -= PLAYER_SPEED;

	if (Play::KeyDown(VK_RIGHT))
		m_pos.x += PLAYER_SPEED;

	if (Play::KeyPressed(VK_SPACE))
	{
		new Laser({ m_pos.x,m_pos.y - 50 });
		Play::PlayAudio("laser");
	}

	if (GameObject::GetObjectCount(GameObject::OBJ_SAUCER) == 0)
		Saucer::SpawnSaucers(state);

	
	
}

void Player::Draw(GameState& state) const
{
	float yWobble = sin(state.time * PLAY_PI) * 3;
	Play::DrawSprite(Play::GetSpriteId("Rocket"), { m_pos.x, m_pos.y + yWobble }, (int)(2.0f * state.time));
}