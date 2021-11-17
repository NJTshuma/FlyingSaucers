#include "Play.h"
#include "MainGame.h"
#include "Laser.h"
#include "Saucer.h"

const float SAUCER_SPEED_INCREMENT = 5.0f;
const Point2f SAUCER_START_POS{ 1500, 125 };
const int SAUCER_WAVE_SIZE = 5;

Saucer::Saucer( Point2f pos ) : GameObject(pos)
{
    m_pos = pos;
    m_type = OBJ_SAUCER;
}

Saucer::~Saucer()
{
}


void Saucer::Update( GameState& state )
{
    const int OFF_SCREEN_TEST = -50;

    if( !m_dead )
    {
        m_velocity.x = -SAUCER_SPEED_INCREMENT * state.difficulty;
        m_velocity.y = sin( m_pos.x / 100 ) * 3;

        if( m_pos.x < OFF_SCREEN_TEST )
            m_pos = SAUCER_START_POS;
    }
    else
    {
        m_velocity.x = -SAUCER_SPEED_INCREMENT * state.difficulty;
        m_velocity.y += 1;
        m_rot += 0.1f * state.difficulty;

        if( m_pos.y > DISPLAY_HEIGHT )
            m_active = false;
    }

    m_pos += m_velocity;
}


void Saucer::SpawnSaucers( GameState& state )
{
    for( int n = 0; n < state.difficulty + SAUCER_WAVE_SIZE; n++ )
    {
        new Saucer( { SAUCER_START_POS.x + ( n * 100 ), SAUCER_START_POS.y } );
    }
    state.difficulty++;
    Play::PlayAudio( "reward" );
}

void Saucer::Draw( GameState& ) const
{
    //Play::ColourSprite("Saucer", Play::cGreen);
    Play::DrawSpriteRotated(Play::GetSpriteId("Saucer"), m_pos, 0, m_rot, 1.0f);
}

bool Saucer::GetDead() const
{
    return m_dead;
}

void Saucer::SetDead()
{
    m_dead = true;
}