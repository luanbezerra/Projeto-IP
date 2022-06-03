#include"raylib.h"
#include<stdlib.h>
#include "sala.h"
#include "player.h"
#define PLAYER_HOR_SPD 200.0f

void controlaMonstro(Sala **sala, Renato renato){
    int delta = GetFrameTime();
 
    if(renato.currentRoom == 0){

        for(int i = 0; i < 5; i++){

            if((((*sala)[0].enemy[i].hitbox.x - renato.hitbox.x <= 148 && (*sala)[0].enemy[i].hitbox.x - renato.hitbox.x > 0) || 
                (renato.hitbox.x - (*sala)[0].enemy[i].hitbox.x <= 148 && renato.hitbox.x - (*sala)[0].enemy[i].hitbox.x > 0)) &&
                renato.hitbox.y - (*sala)[0].enemy[i].hitbox.y <= 28){

                if(renato.hitbox.x < (*sala)[0].enemy[i].hitbox.x) {
                    (*sala)[0].enemy[i].position.x -= PLAYER_HOR_SPD * delta;
                }

                if(renato.hitbox.x > (*sala)[0].enemy[i].hitbox.x) {
                    (*sala)[0].enemy[i].position.x += PLAYER_HOR_SPD * delta;
                }

                if(renato.hitbox.x < (*sala)[0].enemy[i+5].hitbox.x) {
                    (*sala)[0].enemy[i+5].position.x -= PLAYER_HOR_SPD * delta;
                }

                if(renato.hitbox.x > (*sala)[0].enemy[i+5].hitbox.x) {
                    (*sala)[0].enemy[i+5].position.x += PLAYER_HOR_SPD * delta;
                }

                if(renato.hitbox.x < (*sala)[0].enemy[i+10].hitbox.x) {
                    (*sala)[0].enemy[i+10].position.x -= PLAYER_HOR_SPD * delta;
                }

                if(renato.hitbox.x > (*sala)[0].enemy[i+10].hitbox.x) {
                    (*sala)[0].enemy[i+10].position.x += PLAYER_HOR_SPD * delta;
                }
            }
            (*sala)[0].enemy[i].hitbox.x = (*sala)[0].enemy[i].position.x;
            (*sala)[0].enemy[i].hitbox.y = (*sala)[0].enemy[i].position.y;
        }
    }

    else if(renato.currentRoom == 1){

        for(int i = 0; i < 10; i++){
            if(renato.position.x < (*sala)[1].enemy[i].position.x) {
                (*sala)[1].enemy[i].position.x -= PLAYER_HOR_SPD * delta;
            }

            if(renato.position.x > (*sala)[1].enemy[i].position.x) {
                (*sala)[1].enemy[i].position.x += PLAYER_HOR_SPD * delta;
            }

            if(renato.position.y < (*sala)[1].enemy[i].position.x) {
                (*sala)[1].enemy[i].position.x -= PLAYER_HOR_SPD * delta;
            }

            if(renato.position.y > (*sala)[1].enemy[i].position.x) {
                (*sala)[1].enemy[i].position.x += PLAYER_HOR_SPD * delta;
            }
        }
    }

    else if(renato.currentRoom == 2){
        for(int i = 0; i < 3; i++){
            if(renato.position.x < (*sala)[2].enemy[i].position.x) {
                (*sala)[2].enemy[i].position.x -= PLAYER_HOR_SPD * delta;
            }

            if(renato.position.x > (*sala)[2].enemy[i].position.x) {
                (*sala)[2].enemy[i].position.x += PLAYER_HOR_SPD * delta;
            }

            if(renato.position.y < (*sala)[2].enemy[i].position.x) {
                (*sala)[2].enemy[i].position.x -= PLAYER_HOR_SPD * delta;
            }

            if(renato.position.y > (*sala)[2].enemy[i].position.x) {
                (*sala)[2].enemy[i].position.x += PLAYER_HOR_SPD * delta;
            }
        }
    }
}

void createRoom(Sala **sala, Renato renato){

    //&---------------- SALA 1 --------------------------------------

        (*sala)[0].qtdPlatforms = 14;
        (*sala)[0].qtdHide = 4;
        (*sala)[0].qtdEnemies = 18;
        (*sala)[0].platforms = (Rectangle *) calloc((*sala)->qtdPlatforms, sizeof(Rectangle));
        (*sala)[0].hideboxes = (Rectangle *) calloc((*sala)->qtdHide, sizeof(Rectangle));
        (*sala)[0].enemy = (Enemy *) calloc((*sala)->qtdEnemies, sizeof(Enemy));
        (*sala)[0].npc = (NPC *) calloc(1, sizeof(NPC));

        (*sala)[0].npc->position = (Vector2) {1772, 760};
        (*sala)[0].npc->hitbox = (Rectangle) {1772, 760, 100, 170};

        //olho
        (*sala)[0].enemy[0].hitbox = (Rectangle){474, 871, 15, 15}; 
        (*sala)[0].enemy[1].hitbox = (Rectangle){519, 871, 15, 15};
        (*sala)[0].enemy[2].hitbox = (Rectangle){559, 871, 15, 15};
        (*sala)[0].enemy[3].hitbox = (Rectangle){602, 871, 15, 15};
        (*sala)[0].enemy[4].hitbox = (Rectangle){650, 871, 15, 15};
        (*sala)[0].enemy[0].position = (Vector2){474, 871};
        (*sala)[0].enemy[1].position = (Vector2){519, 871};
        (*sala)[0].enemy[2].position = (Vector2){559, 871};
        (*sala)[0].enemy[3].position = (Vector2){602, 871};
        (*sala)[0].enemy[4].position = (Vector2){650, 871};

        //morcego
        (*sala)[0].enemy[5].hitbox = (Rectangle){1059, 696, 15, 15};
        (*sala)[0].enemy[6].hitbox = (Rectangle){1104, 696, 15, 15};
        (*sala)[0].enemy[7].hitbox = (Rectangle){1143, 696, 15, 15};
        (*sala)[0].enemy[8].hitbox = (Rectangle){1187, 696, 15, 15};
        (*sala)[0].enemy[9].hitbox = (Rectangle){1236, 696, 15, 15};
        (*sala)[0].enemy[5].position = (Vector2){1059, 696};
        (*sala)[0].enemy[6].position = (Vector2){1104, 696};
        (*sala)[0].enemy[7].position = (Vector2){1143, 696};
        (*sala)[0].enemy[8].position = (Vector2){1187, 696};
        (*sala)[0].enemy[9].position = (Vector2){1236, 696};

        //cerebro
        (*sala)[0].enemy[10].hitbox = (Rectangle){802, 455, 15, 15};
        (*sala)[0].enemy[11].hitbox = (Rectangle){846, 455, 15, 15};
        (*sala)[0].enemy[12].hitbox = (Rectangle){886, 455, 15, 15};
        (*sala)[0].enemy[13].hitbox = (Rectangle){930, 455, 15, 15};
        (*sala)[0].enemy[14].hitbox = (Rectangle){977, 455, 15, 15};
        (*sala)[0].enemy[10].position = (Vector2){802, 455};
        (*sala)[0].enemy[11].position = (Vector2){846, 455};
        (*sala)[0].enemy[12].position = (Vector2){886, 455};
        (*sala)[0].enemy[13].position = (Vector2){930, 455};
        (*sala)[0].enemy[14].position = (Vector2){977, 455};

        //fogo
        (*sala)[0].enemy[15].hitbox = (Rectangle){32, 237, 15, 15};
        (*sala)[0].enemy[16].hitbox = (Rectangle){77, 237, 15, 15};
        (*sala)[0].enemy[17].hitbox = (Rectangle){117, 237, 15, 15};
        (*sala)[0].enemy[15].position = (Vector2){32, 237};
        (*sala)[0].enemy[16].position = (Vector2){77, 237};
        (*sala)[0].enemy[17].position = (Vector2){117, 237};
 

        (*sala)[0].platforms[0] = (Rectangle){0, 930, 57, 150}; // piso 1
        (*sala)[0].platforms[1] = (Rectangle){223, 930, 435, 150 }; // piso 2
        (*sala)[0].platforms[2] = (Rectangle){112, 866, 54, 11 }; // plataforma 1
        (*sala)[0].platforms[3] = (Rectangle){698, 866, 54, 11}; //plataforma 2
        (*sala)[0].platforms[4] = (Rectangle){889, 791, 54, 11}; // 3
        (*sala)[0].platforms[5] = (Rectangle){984, 736, 113, 11}; // 4
        (*sala)[0].platforms[6] = (Rectangle){1235, 659, 54, 11}; // 5
        (*sala)[0].platforms[7] = (Rectangle){1330, 595, 54, 11}; // 6
        (*sala)[0].platforms[8] = (Rectangle){1235, 529, 54, 11}; // 7
        (*sala)[0].platforms[9] = (Rectangle){745, 474, 353, 11}; // 8
        (*sala)[0].platforms[10] = (Rectangle){554, 405, 54, 11}; // 9
        (*sala)[0].platforms[11] = (Rectangle){363, 323, 54, 11}; // 10
        (*sala)[0].platforms[12] = (Rectangle){0, 255, 223, 11}; // 11
        (*sala)[0].platforms[13] = (Rectangle){1772, 293, 150, 11}; // 12 

        (*sala)[0].hideboxes[0] = (Rectangle){57, 1007, 164, 75}; // 1
        (*sala)[0].hideboxes[1] = (Rectangle){658, 1007, 1262, 75}; // 2
        (*sala)[0].hideboxes[2] = (Rectangle){0, 142, 32, 113}; // 3
        (*sala)[0].hideboxes[3] = (Rectangle){1889, 142, 31, 151}; // 4


    //^---------------- SALA 2 --------------------------------------


        
        (*sala)[1].qtdPlatforms = 1;
        (*sala)[1].qtdHide = 2;
        (*sala)[1].qtdEnemies = 10;
        (*sala)[1].background = LoadTexture("Faculdade/arq.png");
        (*sala)[1].platforms = (Rectangle *) calloc((*sala)->qtdPlatforms, sizeof(Rectangle));
        (*sala)[1].hideboxes = (Rectangle *) calloc((*sala)->qtdHide, sizeof(Rectangle));
        (*sala)[1].npc = (NPC *) calloc(1, sizeof(NPC));

        (*sala)[1].npc->position = (Vector2) {1772, 760};
        (*sala)[1].npc->hitbox = (Rectangle) {1772, 760, 100, 170};

        (*sala)[1].platforms[0] = (Rectangle){0, 930, 1920, 150}; // floor

        (*sala)[1].hideboxes[0] = (Rectangle){1069, 1056, 324, 21}; // floor shield
        (*sala)[1].hideboxes[1] = (Rectangle){1883, 768, 37, 162}; // door

        (*sala)[1].enemy[0].hitbox = (Rectangle){348, 894, 15, 15};
        (*sala)[1].enemy[1].hitbox = (Rectangle){411, 894, 15, 15};
        (*sala)[1].enemy[2].hitbox = (Rectangle){482, 894, 15, 15};
        (*sala)[1].enemy[3].hitbox = (Rectangle){539, 894, 15, 15};
        (*sala)[1].enemy[4].hitbox = (Rectangle){595, 894, 15, 15};
        (*sala)[1].enemy[5].hitbox = (Rectangle){654, 894, 15, 15};
        (*sala)[1].enemy[6].hitbox = (Rectangle){713, 894, 15, 15};
        (*sala)[1].enemy[7].hitbox = (Rectangle){774, 894, 15, 15};
        (*sala)[1].enemy[8].hitbox = (Rectangle){834, 894, 15, 15};
        (*sala)[1].enemy[9].hitbox = (Rectangle){896, 894, 15, 15};
        (*sala)[1].enemy[0].position = (Vector2){348, 894};
        (*sala)[1].enemy[1].position = (Vector2){411, 894};
        (*sala)[1].enemy[2].position = (Vector2){482, 894};
        (*sala)[1].enemy[3].position = (Vector2){539, 894};
        (*sala)[1].enemy[4].position = (Vector2){595, 894};
        (*sala)[1].enemy[5].position = (Vector2){654, 894};
        (*sala)[1].enemy[6].position = (Vector2){713, 894};
        (*sala)[1].enemy[7].position = (Vector2){774, 894};
        (*sala)[1].enemy[8].position = (Vector2){834, 894};
        (*sala)[1].enemy[9].position = (Vector2){896, 894};

    

    //TODO---------------- SALA 3 --------------------------------------


        (*sala)[2].qtdPlatforms = 1;
        (*sala)[2].qtdHide = 2; 
        (*sala)[2].qtdEnemies = 3;
        (*sala)[2].background = LoadTexture("sadasdasdas");
        (*sala)[2].platforms = (Rectangle *) calloc((*sala)->qtdPlatforms, sizeof(Rectangle));
        (*sala)[2].hideboxes = (Rectangle *) calloc((*sala)->qtdHide, sizeof(Rectangle));
        (*sala)[2].npc = (NPC *) calloc(1, sizeof(NPC));

        (*sala)[2].npc->position = (Vector2) {1772, 760};
        (*sala)[2].npc->hitbox = (Rectangle) {1772, 760, 100, 170};

        (*sala)[2].platforms[0] = (Rectangle){0, 930, 1920, 150};

        (*sala)[2].hideboxes[0] = (Rectangle){341, 408, 679, 523};
        (*sala)[2].hideboxes[1] = (Rectangle){1021, 606, 324, 324};
    

}