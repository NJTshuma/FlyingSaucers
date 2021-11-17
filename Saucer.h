#pragma once
#include "GameObject.h"

class Saucer : public GameObject
{
public:
    Saucer(Point2f pos);
    ~Saucer();

    void Update( GameState& state ) override;
    void Draw(GameState& state) const override;
    

    static void SpawnSaucers( GameState& state );

    bool GetDead() const;
    void SetDead();

private:
    float m_rot{ 0 };
    bool m_dead{ false };
};
