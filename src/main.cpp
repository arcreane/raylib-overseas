/* Librairie SDL */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

/* Headers dezs différentes classes */
#include "RenderWindow.h"
#include "Entity.h"
#include "Whiteball.h"	
#include "Redball.h"	
#include "Blueball.h"	
#include "Tile.h"
#include "Hole.h"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	if (!(TTF_Init()))
		std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	return true;
}

bool SDLinit = init();

RenderWindow window("Overseas-Golf", 320, 480);

/* Rendu des textures */
SDL_Texture* ballTextureWhite = window.loadTexture("resources/gfx/ball.png");
SDL_Texture* ballTextureBlue = window.loadTexture("resources/gfx/blueball.png");
SDL_Texture* ballTextureRed = window.loadTexture("resources/gfx/redball.png");
SDL_Texture* holeTexture = window.loadTexture("resources/gfx/hole.png");
SDL_Texture* pointTexture = window.loadTexture("resources/gfx/point.png");
SDL_Texture* tileDarkTexture32 = window.loadTexture("resources/gfx/tile32_dark.png");
SDL_Texture* tileDarkTexture64 = window.loadTexture("resources/gfx/tile64_dark.png");
SDL_Texture* tileLightTexture32 = window.loadTexture("resources/gfx/tile32_light.png");
SDL_Texture* tileLightTexture64 = window.loadTexture("resources/gfx/tile64_light.png");
SDL_Texture* tileFlakeTexture32 = window.loadTexture("resources/gfx/tile32_flake.png");
SDL_Texture* tileFlakeGreyTexture32 = window.loadTexture("resources/gfx/tile32_flakegrey.png");
SDL_Texture* tileFlakeTexture64 = window.loadTexture("resources/gfx/tile64_flake.png");
SDL_Texture* tileSnowmanTexture32 = window.loadTexture("resources/gfx/tile32_snowman.png");
SDL_Texture* tileSnowmanGreyTexture32 = window.loadTexture("resources/gfx/tile32_snowmangrey.png");
SDL_Texture* tileSnowmanTexture64 = window.loadTexture("resources/gfx/tile64_snowman.png");
SDL_Texture* tileTreeTexture32 = window.loadTexture("resources/gfx/tile32_tree.png");
SDL_Texture* tileTreeGreyTexture32 = window.loadTexture("resources/gfx/tile32_treegrey.png");
SDL_Texture* ballShadowTexture = window.loadTexture("resources/gfx/ball_shadow.png");
SDL_Texture* bgTexture = window.loadTexture("resources/gfx/bg.png");
SDL_Texture* bgTextureSnow = window.loadTexture("resources/gfx/bgSnow.png");
SDL_Texture* uiBgTexture = window.loadTexture("resources/gfx/UI_bg.png");
SDL_Texture* levelTextBgTexture = window.loadTexture("resources/gfx/levelText_bg.png");
SDL_Texture* powerMeterTexture_FG = window.loadTexture("resources/gfx/powermeter_fg.png");
SDL_Texture* powerMeterTexture_BG = window.loadTexture("resources/gfx/powermeter_bg.png");
SDL_Texture* powerMeterTexture_overlay = window.loadTexture("resources/gfx/powermeter_overlay.png");

SDL_Texture* click2start = window.loadTexture("resources/gfx/click2start.png");
SDL_Texture* endscreenOverlayTexture = window.loadTexture("resources/gfx/end.png");
SDL_Texture* splashBgTexture = window.loadTexture("resources/gfx/splashbg.png");

Mix_Chunk* chargeSfx = Mix_LoadWAV("resources/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("resources/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("resources/sfx/hole.mp3");


SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };
TTF_Font* font32 = TTF_OpenFont("resources/font/font.ttf", 32);
TTF_Font* font48 = TTF_OpenFont("resources/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("resources/font/font.ttf", 24);

/* 
--- Définition de  la balle utilisée ---

	Whiteball = balle classique
	Redball = balle qui s'écrase sur les murs
 	Blueball = balle qui glisse plus longtemps
*/

Whiteball ball = Whiteball(Vector2f(0, 0), ballTextureWhite, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0);
//Redball ball = Redball(Vector2f(0, 0), ballTextureRed, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0);
//Blueball ball = Blueball(Vector2f(0, 0), ballTextureBlue, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0);

Hole hole = Hole(Vector2f(0, 0), holeTexture);

std::vector<Tile> loadTiles(int level)
{
	std::vector<Tile> temp = {};
    // ajout d'obstacles pour chaque niveaux /GFX
	switch(level) 
	{
		case 0:
			temp.push_back(Tile(Vector2f(64*3, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*4, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*0, 64*3), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(64*1, 64*3), tileDarkTexture64));
		break;

		case 1:
			temp.push_back(Tile(Vector2f(64*2, 64*3), tileDarkTexture64));
		break;

		case 2:
			temp.push_back(Tile(Vector2f(32*4, 32*7), tileDarkTexture32));
		break;

		case 3:
			temp.push_back(Tile(Vector2f(32*4, 32*7), tileDarkTexture64));
			temp.push_back(Tile(Vector2f(32*3, 32*5), tileDarkTexture32));
			temp.push_back(Tile(Vector2f(32*6, 32*3), tileDarkTexture32));
		break;

		case 4:
			temp.push_back(Tile(Vector2f(32*3, 32*1), tileSnowmanTexture32)); 
			temp.push_back(Tile(Vector2f(32*1, 32*3), tileFlakeTexture32)); 
			temp.push_back(Tile(Vector2f(32*5, 32*3), tileFlakeTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*5), tileSnowmanTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*5), tileFlakeTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileSnowmanTexture32));
			temp.push_back(Tile(Vector2f(32*3, 32*10), tileSnowmanGreyTexture32));
			temp.push_back(Tile(Vector2f(32*5, 32*12), tileFlakeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileFlakeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*2, 32*7), tileSnowmanGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*2, 32*9), tileFlakeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*0, 32*9), tileTreeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*5, 32*8), tileTreeGreyTexture32));
			temp.push_back(Tile(Vector2f(32*4, 32*9), tileTreeGreyTexture32));  
			temp.push_back(Tile(Vector2f(32*5, 32*10), tileTreeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*6, 32*9), tileTreeGreyTexture32)); 
			temp.push_back(Tile(Vector2f(32*9, 32*10), tileSnowmanGreyTexture32));
			temp.push_back(Tile(Vector2f(32*9, 32*6), tileSnowmanGreyTexture32));
			temp.push_back(Tile(Vector2f(32*1, 32*14), tileSnowmanGreyTexture32));
			temp.push_back(Tile(Vector2f(32*7, 32*1), tileTreeTexture32));
			temp.push_back(Tile(Vector2f(32*8, 32*3), tileTreeGreyTexture32));
		break;
	}
	return temp;
}

int level = 0;
std::vector<Tile> tiles = loadTiles(level);

bool gameRunning = true;
bool mouseDown = false;
bool mousePressed = false;

bool swingPlayed = false;
bool secondSwingPlayed = false;


SDL_Event event;

int state = 0; //0 = title screen, 1 = game, 2 = end screen

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

void loadLevel(int level)
{
	if (level > 4)
	{
		state = 2;
		std::ofstream ofs ("scores.txt", std::ios::app);
		ofs << __DATE__ << " - " << __TIME__ << " : " << ball.getStrokes() << " coups.\n";
		ofs.close();
		return;
	}
	
	ball.setVelocity(0, 0);
	ball.setScale(1,1);
	ball.setWin(false);

	tiles = loadTiles(level);

	switch (level)
	{
		case 0:
			ball.setPos(24 + 32*4, 24 + 32*11);
			hole.setPos(24 + 32*4, 22 + 32*2);
		break;
		case 1:
			ball.setPos(24 + 32*4, 24 + 32*11);
			hole.setPos(24 + 32*4, 22 + 32*2);
		break;
		case 2:
			ball.setPos(8 + 32*7, 8 + 32*10);
			hole.setPos(8 + 32*2, 6 + 32*5);
		break;
		case 3:
			ball.setPos(24 + 32*4, 24 + 32*5);
			hole.setPos(24 + 32*4, 22 + 32*1);
		break;
		case 4:	
			ball.setPos(24 + 32*2, 24 + 32*12);
			hole.setPos(24 + 32*1, 22 + 32*1);
		break;
	}
}

const char* getStrokeText()
{
	int stroke = ball.getStrokes();
	std::string s = std::to_string(stroke);
	s = "COUP: " + s;
	return s.c_str();
}

const char* getLevelText()
{
	std::string s = std::to_string(level+1);
	s = "TROU: " + s;
	return s.c_str();
}

void update()
{
	
	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

	mousePressed = false;
	//Get our controls and events
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = true;
				mousePressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = false;
			}
			break;
		}
	}

	if (state == 1)
	{
		ball.update(deltaTime, mouseDown, mousePressed, tiles, hole, chargeSfx, swingSfx, holeSfx);
		if (ball.getScale().x < -1)
 		{
        	level++;
			loadLevel(level);
    	}
	}
}

void graphics()
{
	window.clear();
    // FX différent pour le niveau final
	if (level==4)
	{
		window.render(0, 0, bgTextureSnow);
	}
	else
	{
		window.render(0, 0, bgTexture);
	}
	window.render(hole);
	if (!ball.isWin())
	{
		window.render(ball.getPos().x, ball.getPos().y + 4, ballShadowTexture);
	}
	for (Entity& e : ball.getPoints())
	{
		window.render(e);
	}
	window.render(ball);

	for (Tile& t : tiles)
	{ 
		window.render(t);
	}

	for (Entity& e : ball.getPowerBar())
	{
		window.render(e);
	}
	window.render(ball.getPowerBar().at(0).getPos().x, ball.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
		
	if (state != 2)
	{
		window.render(640/4 - 132/2, 480 - 32, levelTextBgTexture);
		window.renderCenter(-160, 240 - 16 + 3, getLevelText(), font24, black);
		window.renderCenter(-160, 240 - 16, getLevelText(), font24, white);

		window.render(320/2 - 98, 0, uiBgTexture);
		window.renderCenter(-160, -240 + 16 + 3, getStrokeText(), font24, black);
		window.renderCenter(-160, -240 + 16, getStrokeText(), font24, white);
	}
	else
	{
		window.render(0, 0, endscreenOverlayTexture);
		window.renderCenter(0, 3 - 32, "YOU COMPLETED THE COURSE!", font48, black);
		window.renderCenter(0, -32, "YOU COMPLETED THE COURSE!", font48, white);
		window.renderCenter(0, 3 + 32, getStrokeText(), font32, black);
		window.renderCenter(0, 32, getStrokeText(), font32, white);
	}
	window.display();
}

void titleScreen()
{
	if (SDL_GetTicks() < 2000)
	{
		if (!swingPlayed)
		{
			Mix_PlayChannel(-1, swingSfx, 0);
			swingPlayed = true;
		}
		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			}
		}

		window.clear();
		window.render(0, 0, bgTexture);
		window.render(0, 0, splashBgTexture);
		window.renderCenter(-150, 0 + 3, "OVERSEAS.", font32, black);
		window.renderCenter(-150, 0, "OVERSEAS.", font32, white);
		window.display();
	}
	else
	{
		if (!secondSwingPlayed)
		{
			Mix_PlayChannel(-1, swingSfx, 0);
			secondSwingPlayed = true;
		}
		lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					Mix_PlayChannel(-1, holeSfx, 0);
					state = 1;
				}
				break;
			}
		}
		window.clear();
		window.render(0, 0, bgTexture);
		//window.render(320 - 160, 240 - 100 - 50 + 4*SDL_sin(SDL_GetTicks()*(3.14/1500)), logoTexture);
		window.render(0, 0, click2start);
		window.renderCenter(-150, 240 - 48 + 3 - 16*5, "LEFT CLICK TO START", font24, black);
		window.renderCenter(-150, 240 - 48 - 16*5, "LEFT CLICK TO START", font24, white);
		window.display();
	}
}
void game()
{
	if (state == 0)
	{
		titleScreen();
	}
	else
	{
		update();
		graphics();
	}
}
int main(int argc, char* args[])
{
	loadLevel(level);
	while (gameRunning)
	{
		game();
	}

	window.cleanUp();
	TTF_CloseFont(font32);
	TTF_CloseFont(font24);
	SDL_Quit();
	TTF_Quit();
	return 0;
}