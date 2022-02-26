#include <iostream>
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int menuX = 150;

    InitWindow(screenWidth, screenHeight, "Overseas. game");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image image = LoadImage("ressources/startbg1.png");  // Load image data into CPU memory (RAM)
    Texture2D textureMenu = LoadTextureFromImage(image);       // Image converted to texture, GPU memory (RAM -> VRAM)
    UnloadImage(image);                                    // Unload image data from CPU memory (RAM)
    image = LoadImage("ressources/level/lvl1.png");
    Texture2D textureGame = LoadTextureFromImage(image);
    UnloadImage(image);
    //---------------------------------------------------------------------------------------

    //Player
    Texture2D playerWalkingRight = LoadTexture("ressources/sprites/player/WalkR.v4.png");
    Texture2D playerWalkingLeft = LoadTexture("ressources/sprites/player/WalkL.v5.png");
    Texture2D playerIdle = LoadTexture("ressources/sprites/player/Idle.v2.png");
    Vector2 playerPosition = {200, 310};
    Vector2 playerHitBoxPosition = {240, 390};
    Vector2 playerSize = { 150, 280};

    //---------------------------------------------------------------------------------------

    //Elements

    //Door
    Vector2 doorHitBoxPosition = {950, 320};
    Vector2 doorSize = {200, 360};
    Rectangle doorRectangle = {950, 320, 200, 360};

    //Frames
    float frameWidth = (float)(playerWalkingRight.width / 6);
    int maxFrames = (int)(playerWalkingRight.width) / (int)(frameWidth);
    float frameWidthIdle = (float)(playerIdle.width / 4);
    int maxFramesIdle = (int)(playerIdle.width) / (int)(frameWidthIdle);

    float timer = 0.0f;
    int frame = 0;
    int frameIdle = 0;
    //---------------------------------------------------------------------------------------

    //Menu Rectangles
    Rectangle startRec = { menuX + 120, 260, 400, 50};
    Rectangle quitRec = {menuX + 120, 330, 150, 50};
    //---------------------------------------------------------------------------------------


    bool pressed = false;
    bool isInMenu = true;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update here
        Vector2 mousePoint = GetMousePosition();
        //Player Rectangle
        Rectangle playerRectangle = {playerHitBoxPosition.x, playerHitBoxPosition.y,
                                     playerSize.x, playerSize.y};

        if (playerPosition.x >= -40.0f ) {

            if (IsKeyDown(KEY_LEFT)) {
                playerPosition.x -= 0.1f;
                playerHitBoxPosition.x -= 0.1f;
            }
        }
        if ((playerPosition.x + 150.0f <=screenWidth-30)) {
            if (IsKeyDown(KEY_RIGHT)) {
                playerPosition.x += 0.1f;
                playerHitBoxPosition.x += 0.1f;
            }
        }

        if(isInMenu)
        {
            if(IsKeyPressed(KEY_Q)) isInMenu = false;
        }
        else
        {
            if(IsKeyPressed(KEY_W)) isInMenu = true;
        }

        // Draw here
        BeginDrawing();
        if(isInMenu)
        {
            ClearBackground(PURPLE);
            DrawTexture(textureMenu, 0, 0, WHITE);
            DrawText("Welcome in the GOTY", menuX, 70, 50, WHITE);
            DrawText("Start game", menuX + 120, 260, 50, WHITE);
            DrawText("Quit", menuX + 120, 330, 50, WHITE);

            if (CheckCollisionPointRec(mousePoint, startRec )){
                DrawText("Start game", menuX + 120, 260, 50, BLUE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    isInMenu = false;
                }
                else{
                    isInMenu = true;
                }
            }

            if (CheckCollisionPointRec(mousePoint, quitRec)){
                DrawText("Quit", menuX + 120, 330, 50, BLUE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    CloseWindow();
                }
            }
        }
        else
        {
            timer += GetFrameTime();

            if (timer >= 0.15f){
                timer = 0.0f;
                frame += 1;
                frameIdle += 1;
            }

            frame = frame % maxFrames;
            frameIdle = frameIdle % maxFramesIdle;

            Color txtcolor = WHITE;
            ClearBackground(RAYWHITE);
            DrawTexture(textureGame, 0, 0, WHITE);
            if (pressed) {
                DrawText("Tutoriel", 50, 80, 50, WHITE);
            }
            else{

            }
            //DrawRectangleV(doorHitBoxPosition, doorSize, GREEN);
            //DrawRectangleV(playerHitBoxPosition, playerSize, RED);
            if (IsKeyDown(KEY_RIGHT)){

                DrawTextureRec(
                        playerWalkingRight,
                        Rectangle{frameWidth * frame,0,
                                  frameWidth, (float)playerWalkingRight.height},
                        playerPosition,
                        RAYWHITE);
            }
            else if (IsKeyDown(KEY_LEFT)){
                DrawTextureRec(
                        playerWalkingLeft,
                        Rectangle{frameWidth * frame,0,
                                  frameWidth, (float)playerWalkingLeft.height},
                        playerPosition,
                        RAYWHITE);
            }
            else{
                DrawTextureRec(
                        playerIdle,
                        Rectangle{frameWidthIdle * frameIdle,0,
                                  frameWidthIdle, (float)playerIdle.height},
                        playerPosition,
                        RAYWHITE);
            }
            if (CheckCollisionRecs(playerRectangle, doorRectangle)) {
                DrawText("R", playerPosition.x, playerPosition.y, 50, WHITE);
                if (IsKeyPressed(KEY_R)){

                    pressed = !pressed;


                }
            }
        }

        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(textureMenu);       // Texture unloading
    UnloadTexture(textureGame);
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}