#pragma once

const int DISPLAY_WIDTH = 1280;
const int DISPLAY_HEIGHT = 720;
const int DISPLAY_SCALE = 1;

const Point2f PLAYER_START_POS = { 640, 650 };
const int PLAYER_SPEED = 5;

class Laser;
class Saucer;

struct GameState
{
    float time{ 0 };
    int score{ 0 };
    int difficulty{ 1 };
    Point2f playerPos{ 0.0f, 0.0f };

};

bool HasCollided( Point2f pos1, Point2f pos2 );
