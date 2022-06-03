#ifndef SALA
#define SALA
#include "raylib.h"
#include "player.h"

typedef struct {

    int vida;
    Vector2 position;
    Rectangle hitbox;
    float speed;
    int direcao; //direita = 1, esquerda = 2
    Texture2D texturaMonstross[8];

} Enemy;

typedef struct {
     
    Rectangle hitbox;
    Vector2 position;
    Texture2D textura[3];

} NPC;

typedef struct{

    int qtdHide;
    Rectangle *hideboxes; // hitboxes que nao sao printadas
    int qtdPlatforms;
    Rectangle *platforms; 
    int qtdEnemies;
    Enemy *enemy;
    Texture2D background;
    NPC *npc;
 
} Sala;

 
//npc

void createRoom(Sala **sala, Renato renato);

void controlaMonstro(Sala **sala, Renato renato);

#endif







