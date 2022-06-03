#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#include"player.h"
#include"sala.h"

#define G 600
#define PLAYER_JUMP_SPD 350.0f
#define PLAYER_HOR_SPD 200.0f
#define MONSTER_HOR_SPD 130.0f

int main(){
    
    bool collision = false;
    bool lastcollision = false;
    bool attackCollision = false;
    bool hideCollisionDamage = false;
    bool hideCollisionPortal = false;
    bool hideCollisionShield = false;
    bool doorcollision = false;
    bool flag = false;
    bool estudemCollision = false;
    bool umpratres = false;
    bool hideCollision = false;
    bool lastState = true;
    bool abriuAba = false;

    float timer = 0.0f;
    int flag2 = 1;
    int frame = 0; 
    float frameWidth = 0;
    float frameHeight = 0;
    int maxFrames = 0;
    int numShields = 1;
    int opcao = 4;
    int flagmenu = 0;

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Music musica1, musica2, musica3, musica4;
    Sound noMichael;

    //Criando os itens
    Renato renato;
    Sala *sala = (Sala *) calloc(3, sizeof(Sala));

    InitWindow(screenWidth, screenHeight, "Renato, O Heroi");
    InitAudioDevice();
  
    SetTargetFPS(60);

    //tras as informações de do player
    criaRenato(&renato);
    renato.isAttacking = false;

    //cria as salas

    // sala 1 ------------------------------------------------------------------------------------------
    
    sala[0].qtdPlatforms = 15;
    sala[0].qtdHide = 5;
    sala[0].qtdEnemies = 18;
    sala[0].platforms = (Rectangle *) calloc(sala[0].qtdPlatforms, sizeof(Rectangle));
    sala[0].hideboxes = (Rectangle *) calloc(sala[0].qtdHide, sizeof(Rectangle));
    sala[0].enemy = (Enemy *) calloc(sala[0].qtdEnemies, sizeof(Enemy));
    sala[0].npc = (NPC *) calloc(1, sizeof(NPC));

    sala[0].npc->position = (Vector2) {1650, 200};
    sala[0].npc->hitbox = (Rectangle) {1650, 200, 100, 170};

    //olho
    sala[0].enemy[0].hitbox = (Rectangle){474, 871, 15, 15}; 
    sala[0].enemy[1].hitbox = (Rectangle){519, 871, 15, 15};
    sala[0].enemy[2].hitbox = (Rectangle){559, 871, 15, 15};
    sala[0].enemy[3].hitbox = (Rectangle){602, 871, 15, 15};
    sala[0].enemy[4].hitbox = (Rectangle){650, 871, 15, 15};
    sala[0].enemy[0].position = (Vector2){474, 871};
    sala[0].enemy[1].position = (Vector2){519, 871};
    sala[0].enemy[2].position = (Vector2){559, 871};
    sala[0].enemy[3].position = (Vector2){602, 871};
    sala[0].enemy[4].position = (Vector2){650, 871};
    sala[0].enemy[0].direcao = 1;
    sala[0].enemy[1].direcao = 1;
    sala[0].enemy[2].direcao = 1;
    sala[0].enemy[3].direcao = 1;
    sala[0].enemy[4].direcao = 1;
    sala[0].enemy[0].vida = 1;
    sala[0].enemy[1].vida = 1;
    sala[0].enemy[2].vida = 1;
    sala[0].enemy[3].vida = 1;
    sala[0].enemy[4].vida = 1;

    //morcego
    sala[0].enemy[6].hitbox = (Rectangle){1104, 696, 15, 15};
    sala[0].enemy[7].hitbox = (Rectangle){1143, 696, 15, 15};
    sala[0].enemy[8].hitbox = (Rectangle){1187, 696, 15, 15};
    sala[0].enemy[6].position = (Vector2){1104, 696};
    sala[0].enemy[7].position = (Vector2){1143, 696};
    sala[0].enemy[8].position = (Vector2){1187, 696};
    sala[0].enemy[6].direcao = 1;
    sala[0].enemy[7].direcao = 1;
    sala[0].enemy[8].direcao = 1;
    sala[0].enemy[6].vida = 1;
    sala[0].enemy[7].vida = 1;
    sala[0].enemy[8].vida = 1;

    //cerebro
    sala[0].enemy[10].hitbox = (Rectangle){802, 455, 15, 15};
    sala[0].enemy[11].hitbox = (Rectangle){846, 455, 15, 15};
    sala[0].enemy[12].hitbox = (Rectangle){886, 455, 15, 15};
    sala[0].enemy[13].hitbox = (Rectangle){930, 455, 15, 15};
    sala[0].enemy[14].hitbox = (Rectangle){977, 455, 15, 15};
    sala[0].enemy[10].position = (Vector2){802, 455};
    sala[0].enemy[11].position = (Vector2){846, 455};
    sala[0].enemy[12].position = (Vector2){886, 455};
    sala[0].enemy[13].position = (Vector2){930, 455};
    sala[0].enemy[14].position = (Vector2){977, 455};
    sala[0].enemy[10].direcao = 1;
    sala[0].enemy[11].direcao = 1;
    sala[0].enemy[12].direcao = 1;
    sala[0].enemy[13].direcao = 1;
    sala[0].enemy[14].direcao = 1;
    sala[0].enemy[10].vida = 1;
    sala[0].enemy[11].vida = 1;
    sala[0].enemy[12].vida = 1;
    sala[0].enemy[13].vida = 1;
    sala[0].enemy[14].vida = 1;

    //fogo
    sala[0].enemy[15].hitbox = (Rectangle){32, 237, 15, 15};
    sala[0].enemy[16].hitbox = (Rectangle){77, 237, 15, 15};
    sala[0].enemy[17].hitbox = (Rectangle){117, 237, 15, 15};
    sala[0].enemy[15].position = (Vector2){32, 237};
    sala[0].enemy[16].position = (Vector2){77, 237};
    sala[0].enemy[17].position = (Vector2){117, 237};
    sala[0].enemy[15].direcao = 1;
    sala[0].enemy[16].direcao = 1;
    sala[0].enemy[17].direcao = 1;
    sala[0].enemy[15].vida = 1;
    sala[0].enemy[16].vida = 1;
    sala[0].enemy[17].vida = 1;

    sala[0].platforms[0] = (Rectangle){0, 930, 60, 150}; // piso 1
    sala[0].platforms[1] = (Rectangle){217, 930, 585, 150 }; // piso 2     435
    sala[0].platforms[2] = (Rectangle){135, 875, 64, 11 }; // plataforma 1
    sala[0].platforms[3] = (Rectangle){720, 865, 70, 11}; //plataforma 2
    sala[0].platforms[4] = (Rectangle){913, 799, 70, 11}; // 3
    sala[0].platforms[5] = (Rectangle){1011, 743, 138, 11}; // 4
    sala[0].platforms[6] = (Rectangle){1258, 666, 70, 11}; // 5
    sala[0].platforms[7] = (Rectangle){1348, 603, 70, 11}; // 6
    sala[0].platforms[8] = (Rectangle){1258, 536, 70, 11}; // 7
    sala[0].platforms[9] = (Rectangle){780, 480, 345, 11}; // 8
    sala[0].platforms[10] = (Rectangle){580, 411, 70, 11}; // 9
    sala[0].platforms[11] = (Rectangle){382, 329, 70, 11}; // 10
    sala[0].platforms[12] = (Rectangle){0, 262, 245, 11}; // 11
    sala[0].platforms[13] = (Rectangle){1706, 296, 213, 11}; // 12 
    sala[0].platforms[14] = (Rectangle){1615, 758, 305, 175}; //teste

    sala[0].hideboxes[0] = (Rectangle) {65, 1020, 152, 60};
    sala[0].hideboxes[1] = (Rectangle) {802, 1020, 1118, 60};
    sala[0].hideboxes[2] = (Rectangle) {0, 175, 38, 84};
    sala[0].hideboxes[3] = (Rectangle) {1882, 203, 38, 90};
    sala[0].hideboxes[4] = (Rectangle) {1882, 603, 38, 90};

    //sala 2 -----------------------------------------------------------------------------------------------------

    sala[1].qtdPlatforms = 1;
    sala[1].qtdHide = 3;
    sala[1].qtdEnemies = 11;
    sala[1].platforms = (Rectangle *) calloc(sala[1].qtdPlatforms, sizeof(Rectangle));
    sala[1].hideboxes = (Rectangle *) calloc(sala[1].qtdHide, sizeof(Rectangle));
    sala[1].npc = (NPC *) calloc(1, sizeof(NPC));
    sala[1].enemy = (Enemy *) calloc(sala[1].qtdEnemies, sizeof(Enemy));

    //marcondes
    sala[1].npc->position = (Vector2) {1725, 825};
    sala[1].npc->hitbox = (Rectangle) {1780, 870, 40, 60};

    sala[1].platforms[0] = (Rectangle){0, 930, 1920, 150}; // floor

    sala[1].hideboxes[0] = (Rectangle){1116, 1050, 335, 40}; // floor shield
    sala[1].hideboxes[1] = (Rectangle){1883, 768, 37, 162}; // door
    sala[1].hideboxes[2] = (Rectangle){1116, 606, 109, 324}; // shield fall

    //inimigos
    sala[1].enemy[0].hitbox = (Rectangle){348, 894, 16, 20};
    sala[1].enemy[1].hitbox = (Rectangle){411, 894, 16, 20};
    sala[1].enemy[2].hitbox = (Rectangle){482, 894, 16, 20};
    sala[1].enemy[3].hitbox = (Rectangle){539, 894, 16, 20};
    sala[1].enemy[4].hitbox = (Rectangle){595, 894, 16, 20};
    sala[1].enemy[5].hitbox = (Rectangle){654, 894, 16, 20};
    sala[1].enemy[6].hitbox = (Rectangle){713, 894, 16, 20};
    sala[1].enemy[7].hitbox = (Rectangle){774, 894, 16, 20};
    sala[1].enemy[8].hitbox = (Rectangle){834, 894, 16, 20};
    sala[1].enemy[9].hitbox = (Rectangle){896, 894, 16, 20};
    sala[1].enemy[10].hitbox = (Rectangle){1116, 180, 240, 240};
    sala[1].enemy[0].position = (Vector2){348, 894};
    sala[1].enemy[1].position = (Vector2){411, 894};
    sala[1].enemy[2].position = (Vector2){482, 894};
    sala[1].enemy[3].position = (Vector2){539, 894};
    sala[1].enemy[4].position = (Vector2){595, 894};
    sala[1].enemy[5].position = (Vector2){654, 894};
    sala[1].enemy[6].position = (Vector2){713, 894};
    sala[1].enemy[7].position = (Vector2){774, 894};
    sala[1].enemy[8].position = (Vector2){834, 894};
    sala[1].enemy[9].position = (Vector2){896, 894};
    sala[1].enemy[10].position = (Vector2){1116, 180};
    sala[1].enemy[0].vida = 1; 
    sala[1].enemy[1].vida = 1; 
    sala[1].enemy[2].vida = 1; 
    sala[1].enemy[3].vida = 1; 
    sala[1].enemy[4].vida = 1; 
    sala[1].enemy[5].vida = 1;
    sala[1].enemy[6].vida = 1;
    sala[1].enemy[7].vida = 1; 
    sala[1].enemy[8].vida = 1;
    sala[1].enemy[9].vida = 1;
    sala[1].enemy[10].vida = 1;

    //sala 3 -----------------------------------------------------------------------------------------

    sala[2].qtdPlatforms = 1;
    sala[2].qtdHide = 2;
    sala[2].qtdEnemies = 1;
    sala[2].enemy = (Enemy *) calloc(sala[2].qtdEnemies, sizeof(Enemy));
    sala[2].platforms = (Rectangle *) calloc(sala[2].qtdPlatforms, sizeof(Rectangle));
    sala[2].hideboxes = (Rectangle *) calloc(sala[2].qtdHide, sizeof(Rectangle));
    sala[2].npc = (NPC *) calloc(1, sizeof(NPC));

    sala[2].platforms[0] = (Rectangle){0, 809, 1920, 270};

    sala[2].hideboxes[0] = (Rectangle){334, 599, 679, 211};
    sala[2].hideboxes[1] = (Rectangle){760, 599, 577, 211};

    sala[2].npc->position = (Vector2){1420, 723};
    sala[2].npc->hitbox = (Rectangle){1420, 723, 72, 86};

    sala[2].enemy[0].position = (Vector2){1091, 677};
    sala[2].enemy[0].hitbox = (Rectangle){1091, 677, 324, 120};

    //loads ----------------------------------------------------------------------------------------

    renato.texturaRenato[0] = LoadTexture("./assets/player/idledireita.png");
    renato.texturaRenato[1] = LoadTexture("./assets/player/idleesquerda.png");
    renato.texturaRenato[2] = LoadTexture("./assets/player/movdireita.png");
    renato.texturaRenato[3] = LoadTexture("./assets/player/movesquerda.png");
    renato.texturaRenato[4] = LoadTexture("./assets/player/pulodireita.png");
    renato.texturaRenato[5] = LoadTexture("./assets/player/puloesquerda.png");
    renato.texturaRenato[6] = LoadTexture("./assets/player/ataquedireito.png");
    renato.texturaRenato[7] = LoadTexture("./assets/player/ataqueesquerdo.png");

    sala[0].background = LoadTexture("./assets/mapas/salaq.png");

    for(int i = 0; i < 5; i++){

        sala[0].enemy[i].texturaMonstross[0] = LoadTexture("./assets/monstros/EyeMonster.png");
        sala[0].enemy[i].texturaMonstross[1] = LoadTexture("./assets/monstros/EyeMonster.png"); 
        sala[0].enemy[i+10].texturaMonstross[4] = LoadTexture("./assets/monstros/FlyingBrain.png"); 
        sala[0].enemy[i+10].texturaMonstross[5] = LoadTexture("./assets/monstros/FlyingBrain.png"); 
    }

    for(int i = 6; i < 10; i++){
        sala[0].enemy[i].texturaMonstross[2] = LoadTexture("./assets/monstros/Bat_Fly.png"); 
        sala[0].enemy[i].texturaMonstross[3] = LoadTexture("./assets/monstros/Bat_Fly.png"); 
    }
    
    for(int i = 15; i < 18; i++){

        sala[0].enemy[i].texturaMonstross[6] = LoadTexture("./assets/monstros/Fire.png"); 
        sala[0].enemy[i].texturaMonstross[7] = LoadTexture("./assets/monstros/Fire.png"); 
    }
    sala[0].npc->textura[0] = LoadTexture("./assets/monstros/bruxa-Marcela.png");

    sala[1].background = LoadTexture("./assets/mapas/flamengoback.png");

    for(int i = 0; i < 10; i++){
        sala[1].enemy[i].texturaMonstross[0] = LoadTexture("./assets/monstros/flamenguito.png");
    }
    sala[1].enemy[10].texturaMonstross[0] = LoadTexture("./assets/monstros/shield.png");
    sala[1].npc->textura[0] = LoadTexture("./assets/monstros/marcondes.png");
    Texture2D sport = LoadTexture("./assets/mapas/87sport.png");

    sala[2].background = LoadTexture("./assets/mapas/faseacm.png");
    sala[2].enemy[0].texturaMonstross[0] = LoadTexture("./assets/monstros/estudemkkkk.png");
    sala[2].npc->textura[0] = LoadTexture("./assets/monstros/acmgiga.png"); 

    //backgrounds
    Texture2D falas[14];
    falas[0] = LoadTexture("./assets/falas/28.png");
    falas[1] = LoadTexture("./assets/falas/17.png");
    falas[2] = LoadTexture("./assets/falas/18.png");
    falas[3] = LoadTexture("./assets/falas/19.png");
    falas[4] = LoadTexture("./assets/falas/20.png");
    falas[5] = LoadTexture("./assets/falas/21.png");
    falas[6] = LoadTexture("./assets/falas/22.png");
    falas[7] = LoadTexture("./assets/falas/23.png");
    falas[8] = LoadTexture("./assets/falas/24.png");
    falas[9] = LoadTexture("./assets/falas/25.png");
    falas[10] = LoadTexture("./assets/falas/26.png");
    falas[11] = LoadTexture("./assets/falas/27.png");
    falas[12] = LoadTexture("./assets/falas/29.png");
    falas[13] = LoadTexture("./assets/falas/30.png");

    Texture2D menuPrincipal = LoadTexture("./assets/mapas/MENU.png");
    Texture2D comandos = LoadTexture("./assets/mapas/COMANDOS.png");
    Texture2D creditos = LoadTexture("./assets/mapas/CREDITOS.png");

    musica1 = LoadMusicStream("assets/musicas/sala1.mp3");
    musica2 = LoadMusicStream("assets/musicas/sala21.mp3");
    musica3 = LoadMusicStream("assets/musicas/sala22.mp3");
    musica4 = LoadMusicStream("assets/musicas/sala3.mp3");
    noMichael = LoadSound("assets/musicas/noGod.mp3");



    while(!WindowShouldClose()){

        float delta = GetFrameTime();

        // menu -----------------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_F1))
            opcao = 1;
        if(IsKeyPressed(KEY_F2))
            opcao = 2;
        if(IsKeyPressed(KEY_F3))
            opcao = 3;
        if(IsKeyPressed(KEY_F4))
            opcao = 4;

        BeginDrawing();

        if(!abriuAba){
            DrawTexture(menuPrincipal, 0, 0, WHITE);
        }
    
        switch (opcao)
        {
            case 1:
                flagmenu = 1;
                abriuAba = true;
                break;

            case 2:
                DrawTexture(comandos, 0, 0, WHITE);
                abriuAba = true;
                break;

            case 3:
                DrawTexture(creditos, 0, 0, WHITE);
                abriuAba = true;
                break;

            case 4:
                DrawTexture(menuPrincipal, 0, 0, WHITE);
                abriuAba = true;
                break;

            default:
                break;
        }

        // começar o jogo --------------------------------------------------------------------------------
        if(flagmenu == 1){

            if(renato.currentRoom == 0){
                DrawTexture(sala[0].background, 0, 0, WHITE);
                UpdateMusicStream(musica1);
                PlayMusicStream(musica1);
                SetMusicVolume(musica1, 0.2);
            }
            if(renato.currentRoom == 1){
                StopMusicStream(musica1);
                UpdateMusicStream(musica2);
                PlayMusicStream(musica2);
                SetMusicVolume(musica2, 0.2);
        
                DrawTexture(sala[1].background, 0, 0, WHITE);

                if(!flag){
                    flag = CheckCollisionRecs(renato.attack, sala[1].npc->hitbox);
                }
                if(flag){
                    if(flag && lastState){
                        flag2 = 25;
                        lastState = false;
                    }
                    DrawTexture(sport, 0, 0, WHITE);
                    StopMusicStream(musica2);
                    UpdateMusicStream(musica3);
                    PlayMusicStream(musica3);
                    SetMusicVolume(musica3, 0.2);
                }
            }
            if(renato.currentRoom == 2){
                StopMusicStream(musica3);
                UpdateMusicStream(musica4);
                PlayMusicStream(musica4);
                SetMusicVolume(musica4, 0.2);
            
                DrawTexture(sala[2].background, 0, 0, WHITE);
            }

                // movimentos -----------------------------------------------------------------------------------
                if(IsKeyUp(KEY_Z)){
                    renato.isAttacking = false;
                    renato.attack.height = 0;
                    renato.attack.width = 0;
                }

                if(IsKeyDown(KEY_UP) && renato.canJump){
                    renato.speedfall = -PLAYER_JUMP_SPD;
                    renato.canJump = false;
                } 
                
                if(IsKeyDown(KEY_LEFT)){

                    renato.position.x -= PLAYER_HOR_SPD * delta;
                    renato.direction = 1;
                    if(renato.canJump){

                        renato.currentTexture = renato.texturaRenato[3];
                        frameHeight = (float) (renato.texturaRenato[3].height / 10);
                        maxFrames = (renato.texturaRenato[3].height / (int) frameHeight);
                    }
                    if(!renato.canJump){
                        
                        renato.currentTexture = renato.texturaRenato[3];
                        frameHeight = (float) (renato.texturaRenato[3].height / 10);
                        maxFrames = (renato.texturaRenato[3].height / (int) frameHeight);
                    }
                }

                if(IsKeyDown(KEY_RIGHT)){
                    renato.position.x += PLAYER_HOR_SPD * delta;
                    renato.direction = 2;
                    if(renato.canJump){

                        renato.currentTexture = renato.texturaRenato[2];
                        frameHeight = (float) (renato.texturaRenato[2].height / 10);
                        maxFrames = (renato.texturaRenato[2].height / (int) frameHeight);

                    }
                    if(!renato.canJump){
                        renato.currentTexture = renato.texturaRenato[2];
                        frameHeight = (float) (renato.texturaRenato[2].height / 10);
                        maxFrames = (renato.texturaRenato[2].height / (int) frameHeight);
                    }
                }
                if(IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_LEFT)){

                    if(renato.canJump){
                        if(renato.direction == 2){
                            renato.currentTexture = renato.texturaRenato[0];
                            frameHeight = (float) (renato.texturaRenato[0].height / 8);
                            maxFrames = (renato.texturaRenato[0].height / (int) frameHeight);
                        }
                        if(renato.direction == 1){
                            renato.currentTexture = renato.texturaRenato[1];
                            frameHeight = (float) (renato.texturaRenato[1].height / 8);
                            maxFrames = (renato.texturaRenato[1].height / (int) frameHeight);
                        }

                    }
                    if(!renato.canJump){
                        if(renato.direction == 2){
                            renato.currentTexture = renato.texturaRenato[0];
                            frameHeight = (float) (renato.texturaRenato[0].height / 8);
                            maxFrames = (renato.texturaRenato[0].height / (int) frameHeight);
                        }
                        if(renato.direction == 1){
                            renato.currentTexture = renato.texturaRenato[1];
                            frameHeight = (float) (renato.texturaRenato[1].height / 8);
                            maxFrames = (renato.texturaRenato[1].height / (int) frameHeight);
                        }
                    }
                }
                if(IsKeyDown(KEY_Z) && !renato.isAttacking && renato.canJump && renato.direction == 2){
                    renato.attack.x = renato.hitbox.x;
                    renato.attack.y = renato.hitbox.y;
                    renato.attack.width = renato.hitbox.width + 20;
                    renato.attack.height = renato.hitbox.height;
                    renato.isAttacking = true;

                    renato.currentTexture = renato.texturaRenato[6];
                    frameHeight = (float) (renato.texturaRenato[6].height / 5);
                    maxFrames = (renato.texturaRenato[6].height / (int) frameHeight);
                }    
                if(IsKeyDown(KEY_Z) && !renato.isAttacking && renato.canJump && renato.direction == 1){
                    renato.attack.x = renato.hitbox.x - 20;
                    renato.attack.y = renato.hitbox.y;
                    renato.attack.width = renato.hitbox.width + 20;
                    renato.attack.height = renato.hitbox.height;
                    renato.isAttacking = true;

                    renato.currentTexture = renato.texturaRenato[7];
                    frameHeight = (float) (renato.texturaRenato[7].height / 5);
                    maxFrames = (renato.texturaRenato[7].height / (int) frameHeight);
                }
                
                //pisar ------------------------------------------------------------------------------
                int platCollision = 0;
                for(int i = 0; i < sala[renato.currentRoom].qtdPlatforms; i++){

                    Rectangle platform = sala[renato.currentRoom].platforms[i];
                    Vector2 *r = &(renato.position);

                    if(platform.x <= r->x &&
                    platform.x + platform.width >= r->x &&
                    platform.y >= r->y &&
                    platform.y < r->y + (renato.speedfall * delta))
                    {
                        platCollision = 1;
                        renato.speedfall = 0.0f;
                        r->y = platform.y;
                    }
                }

                if(!platCollision){

                    renato.position.y += renato.speedfall * delta;
                    renato.speedfall += G * delta;
                    renato.canJump = false;

                }
                else renato.canJump = true;

                //printar renato ---------------------------------------------------------------------------------------------------
                renato.hitbox.x = renato.position.x - (renato.currentTexture.width/4);
                renato.hitbox.y = renato.position.y - frameHeight;
                renato.hitbox.width = renato.currentTexture.width / 2;
                renato.hitbox.height = frameHeight;

                if(renato.direction == 1){
                    renato.attack.x = renato.hitbox.x - 20;   
                }
                else if(renato.direction == 2){
                    renato.attack.x = renato.hitbox.x;
                }
                renato.attack.y = renato.hitbox.y;

                timer += GetFrameTime();

                if (timer >= 0.9f){
                    timer = 0.0f;
                    frame += 1;
                }

                frame = frame % maxFrames;

                if(renato.currentRoom == 0){
                    
                    // checkar colisao pra levar dano ---------------------------------------------------------------------
                    for(int i = 0; i < 18; i++){

                        collision = CheckCollisionRecs(renato.hitbox, sala[0].enemy[i].hitbox);
                        if(collision && !lastcollision){
                            renato.vida--;
                            sala[0].enemy[i].position.x += 30;

                        }
                        attackCollision = CheckCollisionRecs(renato.attack, sala[0].enemy[i].hitbox);
                        if(attackCollision){
                            sala[0].enemy[i].vida--;
                        }
                    }

                    // cair
                    hideCollisionDamage = CheckCollisionRecs(renato.hitbox, sala[0].hideboxes[0]);
                    if(hideCollisionDamage){
                        renato.vida--;
                        renato.position = (Vector2){35, 850}; 
                    }
                    hideCollisionDamage = CheckCollisionRecs(renato.hitbox, sala[0].hideboxes[1]);
                    if(hideCollisionDamage){
                        renato.vida--;
                        renato.position = (Vector2){35, 850}; 
                    }

                    // portal
                    hideCollisionPortal = CheckCollisionRecs(renato.hitbox, sala[0].hideboxes[2]);
                    if(hideCollisionPortal){
                        renato.position = (Vector2){1735, 200};
                        sala[0].npc->position = (Vector2) {-1000, -1000};
                        sala[0].npc->hitbox = (Rectangle) {-1000, -1000, -1000, -1000};
                    }

                    // passa de fase
                    doorcollision = CheckCollisionRecs(renato.hitbox, sala[0].hideboxes[3]);
                    if(doorcollision){
                        renato.position = (Vector2){35, 850};
                        renato.currentRoom = 1;
                    }

                    // gambiarra
                    umpratres = CheckCollisionRecs(renato.hitbox, sala[0].hideboxes[4]);
                    if(umpratres){
                        renato.position = (Vector2) {35, 790};
                        renato.currentRoom = 2;
                    }

                    DrawTextureRec(renato.currentTexture, (Rectangle){0, frameHeight * frame, (float) renato.currentTexture.width, frameHeight}, (Vector2){renato.position.x - (renato.currentTexture.width / 2), renato.position.y - frameHeight}, WHITE);

                    //printar npc
                    frameWidth = (float) sala[0].npc->textura->width / 4;
                    maxFrames = sala[0].npc->textura->width / (int) frameWidth;
                    frameHeight = (float) sala[0].npc->textura->height / 4;

                    timer += GetFrameTime();

                    if (timer >= 0.7f){
                        timer = 0.0f;
                        frame += 1;
                    }
                            
                    frame = frame % maxFrames;

                //printar monstros
                    DrawTextureRec(sala[0].npc->textura[0], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, sala[0].npc->position, WHITE);
                    for(int i = 0; i < 5; i++){

                        if(sala[0].enemy[i].direcao == 1 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[0].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[0].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[0].height / 5;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[0], (Rectangle){frameWidth * frame, frameHeight * 2, frameWidth, frameHeight}, (Vector2){sala[0].enemy[i].position.x - 10, sala[0].enemy[i].position.y + 10}, WHITE);
                        }
                        else if(sala[0].enemy[i].direcao == 2  && sala[0].enemy[i].vida > 0){
                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[1].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[1].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[1].height / 5;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[1], (Rectangle){frameWidth * frame, frameHeight * 3, frameWidth, (float) sala[0].enemy[i].texturaMonstross[1].height}, (Vector2){sala[0].enemy[i].position.x - 10, sala[0].enemy[i].position.y - 10}, WHITE);
                        }
                    }

                    for(int i = 5; i < 10; i++){

                        if(sala[0].enemy[i].direcao == 1 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[2].width / 4;
                            maxFrames = sala[0].enemy[i].texturaMonstross[2].width / (int) frameWidth;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[2], (Rectangle){frameWidth * frame, 0, frameWidth, (float) sala[0].enemy[i].texturaMonstross[2].height}, (Vector2){sala[0].enemy[i].position.x - 20, sala[0].enemy[i].position.y - 25}, WHITE);
                        }
                        else if(sala[0].enemy[i].direcao == 2  && sala[0].enemy[i].vida > 0){
                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[3].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[3].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[3].height / 5;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[3], (Rectangle){frameWidth * frame, 0, frameWidth, (float) sala[0].enemy[i].texturaMonstross[3].height}, (Vector2){sala[0].enemy[i].position.x - 20, sala[0].enemy[i].position.y - 25}, WHITE);
                        }
                    }

                    for(int i = 10; i < 15; i++){

                        if(sala[0].enemy[i].direcao == 1 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[4].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[4].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[4].height / 4;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[4], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, (Vector2){sala[0].enemy[i].position.x - 7, sala[0].enemy[i].position.y - 7}, WHITE);
                        }
                        else if(sala[0].enemy[i].direcao == 2 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[5].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[5].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[5].height / 4;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[5], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, (Vector2){sala[0].enemy[i].position.x - 7, sala[0].enemy[i].position.y - 7}, WHITE);
                        }
                    }
                    
                    for(int i = 15; i < 18; i++){

                        if(sala[0].enemy[i].direcao == 1 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[6].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[6].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[6].height / 5;

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[6], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, (Vector2){sala[0].enemy[i].position.x - 5, sala[0].enemy[i].position.y - 10}, WHITE);
                        }
                        else if(sala[0].enemy[i].direcao == 2 && sala[0].enemy[i].vida > 0){

                            frameWidth = (float) sala[0].enemy[i].texturaMonstross[7].width / 8;
                            maxFrames = sala[0].enemy[i].texturaMonstross[7].width / (int) frameWidth;
                            frameHeight = (float) sala[0].enemy[i].texturaMonstross[7].height / 5; 

                            timer += GetFrameTime();

                            if (timer >= 0.7f){
                                timer = 0.0f;
                                frame += 1;
                            }
                            
                            frame = frame % maxFrames;

                            DrawTextureRec(sala[0].enemy[i].texturaMonstross[7], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, (Vector2){sala[0].enemy[i].position.x - 5, sala[0].enemy[i].position.y - 10}, WHITE);
                        }
                    }

                    //fazer os monstros seguirem 
                    for(int i = 0; i < 5; i++){

                        if(((sala[0].enemy[i].hitbox.x - renato.hitbox.x <= 148 && sala[0].enemy[i].hitbox.x - renato.hitbox.x > 0) || 
                            (renato.hitbox.x - sala[0].enemy[i].hitbox.x <= 148 && renato.hitbox.x - sala[0].enemy[i].hitbox.x > 0)) &&
                            renato.hitbox.y - sala[0].enemy[i].hitbox.y <= 28)
                            {

                                if(renato.hitbox.x < sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x -= MONSTER_HOR_SPD * delta;
                                }

                                if(renato.hitbox.x > sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x += MONSTER_HOR_SPD * delta;
                                }

                                sala[0].enemy[i].hitbox.x = sala[0].enemy[i].position.x;
                                sala[0].enemy[i].hitbox.y = sala[0].enemy[i].position.y;
                        }
                    }
                    for(int i = 5; i < 10; i++){
                        if(((sala[0].enemy[i].hitbox.x - renato.hitbox.x <= 66 && sala[0].enemy[i].hitbox.x - renato.hitbox.x > 0) || 
                            (renato.hitbox.x - sala[0].enemy[i].hitbox.x <= 66 && renato.hitbox.x - sala[0].enemy[i].hitbox.x > 0)) &&
                            renato.hitbox.y - sala[0].enemy[i].hitbox.y <= 28)
                            {
                                if(renato.hitbox.x < sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x -= MONSTER_HOR_SPD * delta;
                                }

                                if(renato.hitbox.x > sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x += MONSTER_HOR_SPD * delta;
                                }
                                sala[0].enemy[i].hitbox.x = sala[0].enemy[i].position.x;
                                sala[0].enemy[i].hitbox.y = sala[0].enemy[i].position.y;
                            }
                    }
                    for(int i = 10; i < 15; i++){
                        if(((sala[0].enemy[i].hitbox.x - renato.hitbox.x <= 148 && sala[0].enemy[i].hitbox.x - renato.hitbox.x > 0) || 
                            (renato.hitbox.x - sala[0].enemy[i].hitbox.x <= 148 && renato.hitbox.x - sala[0].enemy[i].hitbox.x > 0)) &&
                            renato.hitbox.y - sala[0].enemy[i].hitbox.y <= 28)
                            {
                                if(renato.hitbox.x < sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x -= MONSTER_HOR_SPD * delta;
                                }

                                if(renato.hitbox.x > sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x += MONSTER_HOR_SPD * delta;
                                }
                                sala[0].enemy[i].hitbox.x = sala[0].enemy[i].position.x;
                                sala[0].enemy[i].hitbox.y = sala[0].enemy[i].position.y;
                            }
                    }
                    for(int i = 15; i < 18; i++){
                        if(((sala[0].enemy[i].hitbox.x - renato.hitbox.x <= 148 && sala[0].enemy[i].hitbox.x - renato.hitbox.x > 0) || 
                            (renato.hitbox.x - sala[0].enemy[i].hitbox.x <= 148 && renato.hitbox.x - sala[0].enemy[i].hitbox.x > 0)) &&
                            renato.hitbox.y - sala[0].enemy[i].hitbox.y <= 28)
                            {
                                if(renato.hitbox.x < sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x -= MONSTER_HOR_SPD * delta;
                                }

                                if(renato.hitbox.x > sala[0].enemy[i].hitbox.x) {
                                    sala[0].enemy[i].position.x += MONSTER_HOR_SPD * delta;
                                }
                                sala[0].enemy[i].hitbox.x = sala[0].enemy[i].position.x;
                                sala[0].enemy[i].hitbox.y = sala[0].enemy[i].position.y;
                            }
                    }

                    //matar os bixos
                    for(int i = 0; i < 18; i++){

                        if(sala[0].enemy[i].vida <= 0){
                            sala[0].enemy[i].hitbox = (Rectangle) {0, 0, 0, 0};
                        }
                    }
                    //dialogos
                    if(flag2 == 1){
                        DrawTexture(falas[0], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_SPACE)){
                            flag2 = 0;
                        }
                    }

                    if(flag2 == 0){
                        DrawTexture(falas[1], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_ENTER)){
                            flag2 = 5;
                        }
                    }

                    if(flag2 == 5){
                        DrawTexture(falas[2], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_SPACE)){
                            flag2 = 15;
                        }
                    }
                    
                }

                //fase 2
                if(renato.currentRoom == 1){
                    for(int i = 0; i < 10; i++){

                        collision = CheckCollisionRecs(renato.hitbox, sala[renato.currentRoom].enemy[i].hitbox);
                        if(collision && !lastcollision){
                            renato.vida--;
                            sala[renato.currentRoom].enemy[i].position.x += 30;
                        }
                        attackCollision = CheckCollisionRecs(renato.attack, sala[renato.currentRoom].enemy[i].hitbox);
                        if(attackCollision){
                            sala[renato.currentRoom].enemy[i].vida--;
                        }
                    }

                    if(!hideCollisionShield){
                        hideCollisionShield = CheckCollisionRecs(renato.hitbox, sala[renato.currentRoom].hideboxes[2]);
                    }
                    if(hideCollisionShield && numShields == 1){
                        DrawTexture(sala[renato.currentRoom].enemy[10].texturaMonstross[0], sala[renato.currentRoom].enemy[10].position.x, sala[renato.currentRoom].enemy[10].position.y, WHITE);
                        sala[renato.currentRoom].enemy[10].position.y += 25;
                        sala[renato.currentRoom].enemy[10].hitbox.x = sala[renato.currentRoom].enemy[10].position.x;
                        sala[renato.currentRoom].enemy[10].hitbox.y = sala[renato.currentRoom].enemy[10].position.y;
                    }
                    hideCollisionDamage = CheckCollisionRecs(sala[renato.currentRoom].hideboxes[0], sala[renato.currentRoom].enemy[10].hitbox);
                    if(hideCollisionDamage){
                        numShields = 0;
                        sala[renato.currentRoom].enemy[10].hitbox = (Rectangle) {0, 0, 0, 0};
                    }
                    collision = CheckCollisionRecs(renato.hitbox, sala[renato.currentRoom].enemy[10].hitbox);
                    if(collision && !lastcollision){
                        renato.vida--;
                    }
                    doorcollision = CheckCollisionRecs(renato.hitbox, sala[1].hideboxes[1]);
                    if(doorcollision){
                        renato.currentRoom = 0;
                        renato.position = (Vector2){1882, 603};
                    }

                    DrawTextureRec(renato.currentTexture, (Rectangle){0, frameHeight * frame, (float) renato.currentTexture.width, frameHeight}, (Vector2){renato.position.x - (renato.currentTexture.width / 2), renato.position.y - frameHeight}, WHITE);

                    frameWidth = (float) sala[1].npc->textura->width / 8;
                    maxFrames = sala[1].npc->textura->width / (int) frameWidth;
                    frameHeight = (float) sala[1].npc->textura->height;

                    timer += GetFrameTime();

                    if(timer >= 0.5f){
                        timer = 0.0f;
                        frame += 1;
                    }

                    frame = frame % maxFrames;

                    DrawTextureRec(sala[1].npc->textura[0], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, sala[1].npc->position, WHITE);

                    for(int i = 0; i < 10; i++){

                        if(sala[1].enemy[i].vida > 0){

                            DrawTexture(sala[1].enemy[i].texturaMonstross[0], sala[1].enemy[i].position.x - 10, sala[1].enemy[i].position.y - 10, WHITE);

                        }
                    }
                    for(int i = 0; i < 10; i++){
                        if(((sala[1].enemy[i].hitbox.x - renato.hitbox.x <= 115 && sala[1].enemy[i].hitbox.x - renato.hitbox.x > 0) ||
                            (renato.hitbox.x - sala[1].enemy[i].hitbox.x <= 115 && renato.hitbox.x - sala[1].enemy[i].hitbox.x > 0)))
                            {
                                if(renato.hitbox.x < sala[1].enemy[i].hitbox.x) {
                                    sala[1].enemy[i].position.x -= MONSTER_HOR_SPD * delta;
                                }

                                if(renato.hitbox.x > sala[1].enemy[i].hitbox.x) {
                                    sala[1].enemy[i].position.x += MONSTER_HOR_SPD * delta;
                                }

                                sala[1].enemy[i].hitbox.x = sala[1].enemy[i].position.x;
                                sala[1].enemy[i].hitbox.y = sala[1].enemy[i].position.y;
                            }
                    }
                    for(int i = 0; i < 10; i++){

                        if(sala[1].enemy[i].vida <= 0){
                            sala[1].enemy[i].hitbox = (Rectangle) {0, 0, 0, 0};
                        }
                    }
                    if(flag2 == 15){
                        DrawTexture(falas[4], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_SPACE)){
                            flag2 = 20;
                        }
                    }
                    if(flag2 == 20){
                        DrawTexture(falas[5], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_ENTER)){
                            flag2 = 90;
                        }
                    }
                    if(flag2 == 25){
                        DrawTexture(falas[6], 0, 0, WHITE);
                        PlaySound(noMichael);
                        SetSoundVolume(noMichael, 0.5);
                        if(IsKeyPressed(KEY_SPACE)){
                            flag2 = 30;
                        }
                    }
                    if(flag2 == 30){
                        DrawTexture(falas[7], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_ENTER)){
                            flag2 = 35;
                        }
                    }
                    

                }
                if(renato.currentRoom == 2){

                    if(!hideCollision){
                        hideCollision = CheckCollisionRecs(renato.hitbox, sala[renato.currentRoom].hideboxes[0]);
                    }
                    if(hideCollision){

                        DrawTexture(sala[2].enemy[0].texturaMonstross[0], sala[2].enemy[0].hitbox.x, sala[2].enemy[0].hitbox.y, WHITE);
                        DrawTexture(sala[2].enemy[0].texturaMonstross[0], sala[2].enemy[0].hitbox.x, sala[2].enemy[0].hitbox.y + 45, WHITE);
                        DrawTexture(sala[2].enemy[0].texturaMonstross[0], sala[2].enemy[0].hitbox.x, sala[2].enemy[0].hitbox.y - 45, WHITE);
                        DrawTexture(sala[2].enemy[0].texturaMonstross[0], sala[2].enemy[0].hitbox.x, sala[2].enemy[0].hitbox.y + 90, WHITE);
                        if(flag2 != 45){
                            sala[2].enemy[0].position.x -= 2;
                            sala[2].enemy[0].hitbox.x = sala[2].enemy[0].position.x;
                        }

                    }

                    //missel em renato
                    estudemCollision = CheckCollisionRecs(renato.hitbox, sala[renato.currentRoom].enemy[0].hitbox);
                    if(estudemCollision){
                        flag2 = 50;
                    }

                    DrawTextureRec(renato.currentTexture, (Rectangle){0, frameHeight * frame, (float) renato.currentTexture.width, frameHeight}, (Vector2){renato.position.x - (renato.currentTexture.width / 2), renato.position.y - frameHeight}, WHITE);

                    frameWidth = (float) sala[2].npc->textura->width / 23;
                    maxFrames = sala[2].npc->textura->width / (int) frameWidth;
                    frameHeight = (float) sala[2].npc->textura->height;

                    timer += GetFrameTime();

                    if(timer >= 0.5f){
                        timer = 0.0f;
                        frame += 1;
                    }

                    frame = frame % maxFrames;
                    if(frame > 8){
                        frame = 0;
                    }

                    DrawTextureRec(sala[2].npc->textura[0], (Rectangle){frameWidth * frame, 0, frameWidth, frameHeight}, (Vector2) {sala[2].npc->position.x, sala[2].npc->position.y + 10}, WHITE); 

                    if(flag2 == 35){
                        DrawTexture(falas[8], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_SPACE)){
                            flag2 = 40;
                        }
                    }
                    if(flag2 == 40){
                        DrawTexture(falas[9], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_ENTER)){
                            flag2 = 90;
                        }
                    }

                    if(flag2 == 50){
                        DrawTexture(falas[11], 0, 0, WHITE);
                        if(IsKeyPressed(KEY_ENTER)){
                            flag2 = 55;
                        }
                    }
                    if(flag2 == 55){
                        DrawTexture(falas[13], 0, 0, WHITE);
                    }

                }

            if(renato.vida <= 0){
                    DrawTexture(falas[12], 0, 0, WHITE);
            }
            lastcollision = collision;
            
        }


        EndDrawing();
    
    }
    for(int i = 0; i < 10; i++){
        UnloadTexture(renato.texturaRenato[i]);
    }

    UnloadTexture(sala[0].background);
    UnloadTexture(sala[1].background);
    UnloadTexture(sala[2].background);

    for(int i = 0; i < 5; i++){
        UnloadTexture(sala[0].enemy[i].texturaMonstross[0]);
        UnloadTexture(sala[0].enemy[i].texturaMonstross[1]);
        UnloadTexture(sala[0].enemy[i+5].texturaMonstross[2]);
        UnloadTexture(sala[0].enemy[i+5].texturaMonstross[3]);
        UnloadTexture(sala[0].enemy[i+10].texturaMonstross[4]);
        UnloadTexture(sala[0].enemy[i+10].texturaMonstross[5]);
    }
    for(int i = 15; i < 18; i++){
        UnloadTexture(sala[0].enemy[i].texturaMonstross[6]);
        UnloadTexture(sala[0].enemy[i].texturaMonstross[7]);
    }

    UnloadTexture(sala[0].npc->textura[0]);
    UnloadTexture(sala[1].npc->textura[0]);
    UnloadTexture(sala[2].npc->textura[0]);
    
    for(int i = 0; i < 14; i++){
        UnloadTexture(falas[i]);
    }

    free(sala[0].npc);
    free(sala[0].enemy);
    free(sala[0].hideboxes);
    free(sala[0].platforms);
    free(sala[1].npc);
    free(sala[1].enemy);
    free(sala[1].hideboxes);
    free(sala[1].platforms);
    free(sala[2].npc);
    free(sala[2].enemy);
    free(sala[2].hideboxes);
    free(sala[2].platforms);

    free(sala);

    UnloadMusicStream(musica1);
    UnloadMusicStream(musica2);
    UnloadMusicStream(musica3);
    UnloadMusicStream(musica4);
    UnloadSound(noMichael);
   
    return 0;
}