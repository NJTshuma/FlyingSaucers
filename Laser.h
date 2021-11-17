#pragma once
#include "GameObject.h"

class Laser : public GameObject
{
public:
    Laser( Point2f pos );
    ~Laser();
    void Update( GameState& state ) override;
    void Draw(GameState& state) const override;
    //static void UpdateAll( GameState& gState );
        
private:
    //bool m_active{ true };
    //Point2f m_pos{ 0, 0 };
    //Vector2f m_velocity{ 0, 0 };
    //Type m_type{ OBJ_LASER };
};

