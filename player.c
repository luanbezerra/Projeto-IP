#include"player.h"
#include"raylib.h"

#define G 600
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f

void criaRenato(Renato *renato){

/*     renato->texturaRenato[0] = LoadTexture("./assets/player/idle.png"); //idle right
    renato->texturaRenato[1] = LoadTexture("./assets/player/Battlemage Run.png"); //running right
    renato->texturaRenato[2] = LoadTexture("./assets/player/Battlemage Run.png"); // running left
    renato->texturaRenato[3] = LoadTexture("./assets/player/Battlemage Jump Forward.png"); // jumping forward right
    renato->texturaRenato[4] = LoadTexture("./assets/player/Battlemage Jump Forward.png"); // jumping forward left
    renato->texturaRenato[5] = LoadTexture("./assets/player/attack.png"); // attacking right
    renato->texturaRenato[6] = LoadTexture("./assets/player/attack.png"); // attacking left
    renato->texturaRenato[7] = LoadTexture("./assets/player/Battlemage Run.png"); // jumping right
    renato->texturaRenato[8] = LoadTexture("./assets/player/Battlemage Jump Neutral.png"); // jumping left
    renato->texturaRenato[9] = LoadTexture("./assets/player/Death.png"); // dying
    renato->texturaRenato[10] = LoadTexture("./assets/player/Battlemage Idle.png"); // idle left
 */
    renato->vida = 6;
    renato->position.x = 35;
    renato->position.y = 850; //850
    renato->speedfall = 0;
    renato->canJump = false;
    renato->hitbox = (Rectangle) {renato->position.x, renato->position.y, 0, 0};
    renato->currentRoom = 0;
    renato->lastRoom = 0;
    renato->direction = 2;
 
}
