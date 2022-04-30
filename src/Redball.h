#include "Ball.h"

/* sous-classe de ball dont certains arttibuts de la méthode update ont été changés (plus "aimanté" aux murs) */
class Redball : public Ball {
    public:
        Redball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index);
        void update(double deltaTime, bool mouseDown, bool mousePressed, std::vector<Tile> tiles, Hole hole, Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx);
    
    private:
        float friction = 0.001;
};
