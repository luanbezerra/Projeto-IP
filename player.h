#ifndef PLAYER
#define PLAYER

#include "raylib.h"

typedef struct{

    Vector2 position;
    int vida;
    float speedfall;
    bool canJump;
    Rectangle hitbox;
    Texture2D texturaRenato[10];
    int action;
    int currentRoom;
    int lastRoom;
    Texture2D currentTexture;
    Rectangle attack;
    bool isAttacking;
    int direction; //1 = esquerda; 2 = direita

} Renato;

void criaRenato(Renato *renato); 


#endif

