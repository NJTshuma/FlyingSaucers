#include "Play.h"
#include "MainGame.h"
#include "Laser.h"
#include "Saucer.h"

const int SAUCER_SCORE = 1000;
const int LASER_COST = 100;
const int LASER_SPEED = 20;

Laser::Laser( Point2f pos ) : GameObject(pos)
{
    m_pos = pos;
    m_velocity = { 0, -LASER_SPEED };
    m_type = OBJ_LASER;
    m_drawOrder = -1;
}

Laser::~Laser()
{
}

void Laser::Update(GameState& state)
{
    for( GameObject *g : s_vUpdateList)
    {
        if (g->GetType() == OBJ_SAUCER)
        {
            Saucer* s = static_cast <Saucer*> (g);
            if (s->GetDead() == false && HasCollided(m_pos, g->GetPosition()))
            {
                s->SetDead();
                state.score += SAUCER_SCORE;
                Play::PlayAudio("clang");
                m_active = false;
            }
        }
    }

    m_pos += m_velocity;

    if( m_active && m_pos.y < 0 )
    {
        m_active = false;

        if( state.score >= LASER_COST )
            state.score -= LASER_COST;
    }

    //Play::DrawSprite( Play::GetSpriteId( "Laser" ), m_pos, 0 );
}

/*void Laser::UpdateAll(GameState& state)
{
    for( Laser& l : state.lasers )
    {
        l.Update( state );
    }

    for( int n = 0; n < state.lasers.size(); n++ )
    {
        if( state.lasers[n].m_active == false )
            state.lasers.erase( state.lasers.begin() + n );
    }
}*/

void Laser::Draw(GameState& ) const
{
    Play::DrawSprite(Play::GetSpriteId("Laser"), m_pos, 0);
}