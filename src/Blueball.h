#include "Ball.h"

class Blueball : public Ball {
    public:
        Blueball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index);
        void update(double deltaTime, bool mouseDown, bool mousePressed, std::vector<Tile> tiles, Hole hole, Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx);
    
    private:
        float friction = 0.0001;
};