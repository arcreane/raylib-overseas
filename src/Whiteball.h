#include "Ball.h"

class Whiteball : public Ball {
    public:
        Whiteball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index);
        void update(double deltaTime, bool mouseDown, bool mousePressed, std::vector<Tile> tiles, std::vector<Hole> holes,Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx);

    private:
        Vector2f velocity;
        Vector2f target;
        Vector2f launchedVelocity;
        float velocity1D;
        float launchedVelocity1D;
        Vector2f initialMousePos;
        bool canMove = true;
        bool playedSwingFx = true;
        int index;
        int strokes = 0;
        int dirX = 1;
        int dirY = 1;
        bool win = false;
        float friction = 100;
        std::vector<Entity> points;
        std::vector<Entity> powerBar;
};