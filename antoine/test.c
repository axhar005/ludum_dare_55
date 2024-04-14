/*******************************************************************************************
*
*   raylib [core] example - 2D Camera platformer
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.0
*
*   Example contributed by arvyy (@arvyy) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2024 arvyy (@arvyy)
*
********************************************************************************************/

#include <raylib.h>
#include <raymath.h>

#include "raylib.h"

int main() {
    // Initialisation de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib 2D Camera Example");

    // Configuration de la caméra 2D
    Camera2D camera = { 0 };
    camera.target = (Vector2) { 0.0f, 0.0f };          // Point que la caméra doit suivre
    camera.offset = (Vector2) { screenWidth/2.0f, screenHeight/2.0f };  // Décalage pour centrer la caméra sur l'écran
    camera.rotation = 0.0f;                  // Pas de rotation nécessaire en 2D général
    camera.zoom = 1.0f;                      // Niveau de zoom initial

    // Définition du joueur
    Vector2 playerPosition = (Vector2){ 50.0f, 50.0f };
    Vector2 playerVelocity = (Vector2){ 0.0f, 0.0f };
    float playerSpeed = 4.0f;
    float playerSize = 20.0f;
    Image image = LoadImage("cat.png");
    Texture2D  texture = LoadTextureFromImage(image);
    UnloadImage(image);
    SetTargetFPS(60); // Fréquence de rafraîchissement cible à 60 FPS
    // Boucle de jeu
    while (!WindowShouldClose()) {
        // Mettre à jour la position du joueur en fonction des entrées
        playerVelocity = (Vector2){ 0.0f, 0.0f };
        if (IsKeyDown(KEY_RIGHT)) playerVelocity.x += playerSpeed;
        if (IsKeyDown(KEY_LEFT)) playerVelocity.x -= playerSpeed;
        if (IsKeyDown(KEY_UP)) playerVelocity.y -= playerSpeed;
        if (IsKeyDown(KEY_DOWN)) playerVelocity.y += playerSpeed;
        
        playerPosition.x += playerVelocity.x;
        playerPosition.y += playerVelocity.y;

        // Mettre à jour la caméra pour suivre le joueur
        camera.target = playerPosition;

        // Commencer à dessiner
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                DrawTextureV(texture, (Vector2){10, 10}, WHITE);
                DrawTextureV(texture, (Vector2){10, 30}, WHITE);
                DrawTextureV(texture, (Vector2){10, 40}, WHITE);
                DrawCircleV(playerPosition, playerSize, RED); // Dessine le joueur
                DrawGrid(20, 10.0f); // Dessine une grille pour le référencement visuel
            EndMode2D();
            DrawText("Camera is following the player!", 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Libération des ressources et fermeture de Raylib
    CloseWindow();

    return 0;
}