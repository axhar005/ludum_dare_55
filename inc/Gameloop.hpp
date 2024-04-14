#pragma once

#include "game.hpp"

typedef enum renderMode {
	START,
	RUN,
	ENDGAME,
	RESTART
} rendermode;

void GameLoop(Layer &layers, rendermode mode);

/*
#include "raylib.h"

int main() {
    // Initialisation de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib 2D Camera Example");

    // Configuration de la caméra 2D
    Camera2D camera = { 0 };
    camera.target = { 0.0f, 0.0f };          // Point que la caméra doit suivre
    camera.offset = { screenWidth/2.0f, screenHeight/2.0f };  // Décalage pour centrer la caméra sur l'écran
    camera.rotation = 0.0f;                  // Pas de rotation nécessaire en 2D général
    camera.zoom = 1.0f;                      // Niveau de zoom initial

    // Définition du joueur
    Vector2 playerPosition = { 50.0f, 50.0f };
    Vector2 playerVelocity = { 0.0f, 0.0f };
    float playerSpeed = 4.0f;
    float playerSize = 20.0f;

    SetTargetFPS(60); // Fréquence de rafraîchissement cible à 60 FPS
    // Boucle de jeu
    while (!WindowShouldClose()) {
        // Mettre à jour la position du joueur en fonction des entrées
        playerVelocity = { 0.0f, 0.0f };
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
*/