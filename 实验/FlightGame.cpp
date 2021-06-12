#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

#include "raylib.h"
#include "raymath.h"

// WASD进行上下左右移动, P键暂停游戏, Esc键退出当前游戏, Enter键进入游戏, 空格键射击（按住持续射击）

#define WIDTH 1600.0f   //设置宽
#define HEIGHT 900.0f   //设置高
#define MAX_FPS 480.0f  //设置FPS最大值(别太高)

#define MAX_ENEMY 15  //设置敌人数目

#define MAX_BULLET 20  //设置飞机最大存在子弹数目

#define PLAYER_HEALTH 20            //设置普通模式下面飞机血量
#define PLAYER_SIZE 20.0f           //设置飞机大小
#define PLAYER_SPEED 3.0f           //设置飞机移动速度
#define PLAYER_ROTATION_SPEED 3.0f  //设置飞机转向速度
#define PLAYER_SHOOT_RATE 4         //设置飞机开火速度

class Bullet {
   public:
    Vector2 position;
    Color color;
    int attack;
    float radius;
    float speed;
    float rotation;
    bool active;
};

class Player {
   public:
    void initialize() {
        position = Vector2{WIDTH / 2, HEIGHT - height};
        rotation = 0.0f;
        score = 0;
        defeat = 0;
        health = PLAYER_HEALTH;
        color = MAROON;
        speed = PLAYER_SPEED * 240.0f / MAX_FPS;
        rSpeed = PLAYER_ROTATION_SPEED * 240.0f / MAX_FPS;
        height = (PLAYER_SIZE / 2) / tanf(20 * DEG2RAD);

        for (int i = 0; i < MAX_BULLET; ++i) {
            bullet[i].attack = 1;
            bullet[i].color = RED;
            bullet[i].radius = PLAYER_SIZE / 7;
        }
    }

    void move() {
        if (IsKeyDown(KEY_A)) {
            rotation -= rSpeed;
        }
        if (IsKeyDown(KEY_D)) {
            rotation += rSpeed;
        }
        if (IsKeyDown(KEY_W)) {
            position.x += speed * sin(rotation * DEG2RAD);
            position.y -= speed * cos(rotation * DEG2RAD);
        }
        if (IsKeyDown(KEY_S)) {
            position.x -= speed * sin(rotation * DEG2RAD);
            position.y += speed * cos(rotation * DEG2RAD);
        }

        if (position.x > WIDTH + height) {
            position.x = -height;
        } else if (position.x < -height) {
            position.x = WIDTH + height;
        }
        if (position.y > (HEIGHT + height)) {
            position.y = -height;
        } else if (position.y < -height) {
            position.y = HEIGHT + height;
        }
    }

    void shoot(Sound& shoot) {
        ++lag;

        if (IsKeyDown(KEY_SPACE) && lag > (MAX_FPS / PLAYER_SHOOT_RATE)) {
            PlaySound(shoot);
            for (int i = 0; i < MAX_BULLET; ++i) {
                if (!bullet[i].active) {
                    bullet[i].active = true;
                    bullet[i].position = Vector2{position.x + (float)sin(rotation * DEG2RAD) * (height / 2.5f),
                                                 position.y - (float)cos(rotation * DEG2RAD) * (height / 2.5f)};
                    bullet[i].speed = speed * 3.0f;
                    bullet[i].rotation = rotation;
                    break;
                }
            }
            lag = 0;
        }

        for (int i = 0; i < MAX_BULLET; ++i) {
            if (bullet[i].active) {
                bullet[i].position.x += bullet[i].speed * sin(bullet[i].rotation * DEG2RAD);
                bullet[i].position.y -= bullet[i].speed * cos(bullet[i].rotation * DEG2RAD);

                if (bullet[i].position.x > WIDTH) {
                    bullet[i].active = false;
                } else if (bullet[i].position.x < 0) {
                    bullet[i].active = false;
                }
                if (bullet[i].position.y > HEIGHT) {
                    bullet[i].active = false;
                } else if (bullet[i].position.y < 0) {
                    bullet[i].active = false;
                }
            }
        }
    }

    Vector2 position;
    float rotation;
    int health;
    int score;
    int defeat;
    int lag = 0;
    Color color;

    float speed;
    float rSpeed;
    float height;

    Bullet bullet[MAX_BULLET];
};

class Enemy {
   public:
    void initialize() {
        position.x = (float)GetRandomValue(0, WIDTH);
        position.y = (float)GetRandomValue(0, HEIGHT / 2);
        radius = (float)GetRandomValue(PLAYER_SIZE, PLAYER_SIZE * 4);
        speed = PLAYER_SPEED * PLAYER_SIZE / radius * 60 / MAX_FPS;
        health = radius / PLAYER_SIZE;
        survive = true;
        for (int i = 0; i < MAX_BULLET; ++i) {
            //bullet[i].active = false;
            bullet[i].attack = health;
            bullet[i].color = DARKGRAY;
            bullet[i].radius = radius / 7;
        }
    }

    void initializeU() {
        position.x = (float)GetRandomValue(0, WIDTH);
        position.y = (float)GetRandomValue(0, HEIGHT / 2);
        health = radius / PLAYER_SIZE;
        survive = true;
    }

    void move() {
        if (survive) {
            position.x += speed;
            position.y += speed;

            if (position.x > WIDTH + radius) {
                position.x = -radius;
            } else if (position.x < -radius) {
                position.x = WIDTH + radius;
            }
            if (position.y > (HEIGHT + radius)) {
                position.y = -radius;
            } else if (position.y < -radius) {
                position.y = HEIGHT + radius;
            }
        }
    }

    void shoot(Vector2& pPosition) {
        ++lag;
        if (survive && lag > (MAX_FPS * radius / 50)) {
            float rotation = 180 - atan((pPosition.x - position.x) / (pPosition.y - position.y)) * RAD2DEG;

            for (int i = 0; i < MAX_BULLET; ++i) {
                if (!bullet[i].active) {
                    bullet[i].active = true;
                    bullet[i].position = Vector2{position.x + (float)sin(rotation * DEG2RAD) * radius,
                                                 position.y - (float)cos(rotation * DEG2RAD) * radius};
                    bullet[i].speed = speed * 2.0f;
                    bullet[i].rotation = rotation;
                    break;
                }
            }

            lag = 0;
        }

        for (int i = 0; i < MAX_BULLET; ++i) {
            if (bullet[i].active) {
                bullet[i].position.x += bullet[i].speed * sin(bullet[i].rotation * DEG2RAD);
                bullet[i].position.y -= bullet[i].speed * cos(bullet[i].rotation * DEG2RAD);

                if (bullet[i].position.x > WIDTH) {
                    bullet[i].active = false;
                } else if (bullet[i].position.x < 0) {
                    bullet[i].active = false;
                }
                if (bullet[i].position.y > HEIGHT) {
                    bullet[i].active = false;
                } else if (bullet[i].position.y < 0) {
                    bullet[i].active = false;
                }
            }
        }
    }

    Vector2 position;
    float radius;
    float speed;
    bool survive;
    int health;
    int lag = 0;
    Bullet bullet[MAX_BULLET];
};

static Player player;
static Enemy enemy[MAX_ENEMY];
static Bullet bullet[MAX_BULLET];
static int framesCounter;
static bool gameOver;
static bool pause;
static int mode = 0;

static void Welcome();
static void InitGame(Music& background);
static void UpdateGame(Music& background, Sound& shoot, Sound& defeat);
static void UpdateGameU(Music& background, Sound& shoot, Sound& defeat);
static void DrawGame(Music& background, Sound& win, Sound& lose);
static void DrawGameU(Music& background, Sound& end);
static void UnloadGame(Music& background, Music& backgroundU, Sound& shoot, Sound& defeat, Sound& win, Sound& lose,
                       Sound& end);

int main() {
    InitWindow(WIDTH, HEIGHT, "Flight Game");
    InitAudioDevice();
    SetExitKey(KEY_NULL);

    Music background_music = LoadMusicStream("resources/background_music.ogg");
    Music background_music_u = LoadMusicStream("resources/background_music_u.ogg");
    Sound shoot_sound = LoadSound("resources/shoot_sound.ogg");
    Sound lose_sound = LoadSound("resources/lose_sound.ogg");
    Sound win_sound = LoadSound("resources/win_sound.ogg");
    Sound defeat_sound = LoadSound("resources/defeat_sound.ogg");
    Sound end_sound = LoadSound("resources/end_sound.ogg");

    InitGame(background_music);

    while (!WindowShouldClose()) {
        switch (mode) {
            case 0: {
                Welcome();
                if (IsKeyPressed(KEY_ONE)) {
                    mode = 1;
                    InitGame(background_music);
                } else if (IsKeyPressed(KEY_TWO)) {
                    mode = 2;
                    InitGame(background_music_u);
                } else if (IsKeyPressed(KEY_ESCAPE)) {
                    goto exit;
                }
                break;
            }

            case 1: {
                UpdateGame(background_music, shoot_sound, defeat_sound);
                DrawGame(background_music, win_sound, lose_sound);
                UpdateMusicStream(background_music);
                break;
            }

            case 2: {
                UpdateGameU(background_music_u, shoot_sound, defeat_sound);
                DrawGameU(background_music_u, end_sound);
                UpdateMusicStream(background_music_u);
                break;
            }

            default: {
                break;
            }
        }
    }

exit:
    UnloadGame(background_music, background_music_u, shoot_sound, defeat_sound, win_sound, lose_sound, end_sound);

    return 0;
}

static void Welcome() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("<<< FLIGHT GAME >>>", WIDTH / 2 - MeasureText("<<< FLIGHT GAME >>>", 70) / 2, HEIGHT / 2 - 100, 70,
             SKYBLUE);
    DrawText("> NORMAL MODE : ONE", WIDTH / 2 - MeasureText("> NORMAL MODE : ONE", 20) / 2, HEIGHT / 2, 25, DARKPURPLE);
    DrawText("> INFINITE MODE : TWO", WIDTH / 2 - MeasureText("> INFINITE MODE : TWO", 20) / 2, HEIGHT / 2 + 40, 25,
             DARKPURPLE);
    DrawText("> PRESS [ESC] TO EXIT", WIDTH / 2 - MeasureText("> PRESS [ESC] TO EXIT", 20) / 2, HEIGHT / 2 + 80, 25,
             DARKPURPLE);

    EndDrawing();
}

static void InitGame(Music& background) {
    SetTargetFPS(MAX_FPS);

    framesCounter = 0;
    pause = false;
    gameOver = false;

    for (int i = 0; i < MAX_ENEMY; ++i) {
        enemy[i].initialize();
    }
    player.initialize();

    PlayMusicStream(background);

    if (mode == 2) {
        player.color = ORANGE;
        player.health *= 10;
        player.speed *= 1.5f;
        player.rSpeed *= 1.2f;
    }
}

static void UpdateGame(Music& background, Sound& shoot, Sound& defeat) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        StopMusicStream(background);
        mode = 0;
    }

    if (!gameOver) {
        if (IsKeyPressed(KEY_P)) {
            pause = !pause;
            if (pause) {
                PauseMusicStream(background);
            } else {
                ResumeMusicStream(background);
            }
        }

        if (!pause) {
            ++framesCounter;

            //玩家--移动
            player.move();

            //玩家--射击
            player.shoot(shoot);

            //玩家&&敌人--碰撞系统
            Vector2 place = {player.position.x + sin(player.rotation * DEG2RAD) * (player.height / 2.5f),
                             player.position.y - cos(player.rotation * DEG2RAD) * (player.height / 2.5f)};
            for (int i = 0; i < MAX_ENEMY; i++) {
                if (enemy[i].survive &&
                    CheckCollisionCircles({place.x, place.y}, PLAYER_SIZE / 3, enemy[i].position, enemy[i].radius)) {
                    player.health -= enemy[i].health;
                    ++player.defeat;
                    enemy[i].survive = false;
                    PlaySound(defeat);
                }
            }

            //玩家&&子弹--碰撞系统
            for (int i = 0; i < MAX_ENEMY; ++i) {
                for (int j = 0; j < MAX_BULLET; ++j) {
                    if (enemy[i].bullet[j].active &&
                        CheckCollisionCircles({ place.x, place.y }, PLAYER_SIZE / 3, enemy[i].bullet[j].position,
                            enemy[i].bullet[j].radius)) {
                        player.health -= enemy[i].bullet[j].attack;
                        enemy[i].bullet[j].active = false;
                    }
                }
            }

            if (player.health <= 0) {
                gameOver = true;
            }

            //敌人&&子弹--碰撞系统
            for (int i = 0; i < MAX_BULLET; ++i) {
                if (player.bullet[i].active) {
                    place = {player.bullet[i].position.x, player.bullet[i].position.y};
                    for (int j = 0; j < MAX_ENEMY; ++j) {
                        if (enemy[j].survive && CheckCollisionCircles({place.x, place.y}, player.bullet[i].radius,
                                                                      enemy[j].position, enemy[j].radius)) {
                            --enemy[j].health;
                            ++player.score;
                            if (enemy[j].health <= 0) {
                                enemy[j].survive = false;
                                ++player.defeat;
                                PlaySound(defeat);
                            }
                            player.bullet[i].active = false;
                            break;
                        }
                    }
                }
            }

            //敌人--移动--射击
            for (int i = 0; i < MAX_ENEMY; i++) {
                enemy[i].move();
                enemy[i].shoot(player.position);
            }

            if (player.defeat == MAX_ENEMY) {
                gameOver = true;
            }
        }
    } else {
        if (IsKeyPressed(KEY_ENTER)) {
            InitGame(background);
            gameOver = false;
        }
    }
}

static void UpdateGameU(Music& background, Sound& shoot, Sound& defeat) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        StopMusicStream(background);
        mode = 0;
    }

    if (!gameOver) {
        if (IsKeyPressed(KEY_P)) {
            pause = !pause;
            if (pause) {
                PauseMusicStream(background);
            } else {
                ResumeMusicStream(background);
            }
        }

        if (!pause) {
            ++framesCounter;

            //玩家--移动
            player.move();

            //玩家--射击
            player.shoot(shoot);

            //玩家&&敌人--碰撞系统
            Vector2 place = {player.position.x + sin(player.rotation * DEG2RAD) * (player.height / 2.5f),
                             player.position.y - cos(player.rotation * DEG2RAD) * (player.height / 2.5f)};
            for (int i = 0; i < MAX_ENEMY; i++) {
                if (CheckCollisionCircles({place.x, place.y}, PLAYER_SIZE / 3, enemy[i].position, enemy[i].radius)) {
                    player.health -= enemy[i].health;
                    ++player.defeat;
                    enemy[i].initializeU();
                    PlaySound(defeat);
                }
            }

            //玩家&&子弹--碰撞系统
            for (int i = 0; i < MAX_ENEMY; ++i) {
                for (int j = 0; j < MAX_BULLET; ++j) {
                    if (enemy[i].bullet[j].active &&
                        CheckCollisionCircles({place.x, place.y}, PLAYER_SIZE / 3, enemy[i].bullet[j].position,
                                              enemy[i].bullet[j].radius)) {
                        player.health -= enemy[i].bullet[j].attack;
                        enemy[i].bullet[j].active = false;
                    }
                }
            }

            if (player.health <= 0) {
                gameOver = true;
            }

            //敌人&&子弹--碰撞系统
            for (int i = 0; i < MAX_BULLET; ++i) {
                if (player.bullet[i].active) {
                    place = {player.bullet[i].position.x, player.bullet[i].position.y};
                    for (int j = 0; j < MAX_ENEMY; ++j) {
                        if (CheckCollisionCircles({place.x, place.y}, player.bullet[i].radius, enemy[j].position,
                                                  enemy[j].radius)) {
                            --enemy[j].health;
                            ++player.score;
                            if (enemy[j].health <= 0) {
                                enemy[j].initializeU();
                                ++player.defeat;
                                PlaySound(defeat);
                            }
                            player.bullet[i].active = false;
                            break;
                        }
                    }
                }
            }

            //敌人--移动--射击
            for (int i = 0; i < MAX_ENEMY; i++) {
                enemy[i].move();
                enemy[i].shoot(player.position);
            }
        }
    } else {
        if (IsKeyPressed(KEY_ENTER)) {
            InitGame(background);
            gameOver = false;
        }
    }
}

static void DrawGame(Music& background, Sound& win, Sound& lose) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    //玩家
    Vector2 v1 = {player.position.x + sinf(player.rotation * DEG2RAD) * (player.height),
                  player.position.y - cosf(player.rotation * DEG2RAD) * (player.height)};
    Vector2 v2 = {player.position.x - cosf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2),
                  player.position.y - sinf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2)};
    Vector2 v3 = {player.position.x + cosf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2),
                  player.position.y + sinf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2)};
    DrawTriangle(v1, v2, v3, player.color);

    //玩家--子弹
    for (int i = 0; i < MAX_BULLET; ++i) {
        if (player.bullet[i].active == true) {
            DrawCircleV(player.bullet[i].position, player.bullet[i].radius, player.bullet[i].color);
        }
    }

    //敌人
    for (int i = 0; i < MAX_ENEMY; i++) {
        if (enemy[i].survive) {
            DrawCircleV(enemy[i].position, enemy[i].radius, GRAY);
        } else {
            DrawCircleV(enemy[i].position, enemy[i].radius, Fade(LIGHTGRAY, 0.3f));
        }
        //敌人--子弹
        for (int j = 0; j < MAX_BULLET; ++j) {
            if (enemy[i].bullet[j].active == true) {
                DrawCircleV(enemy[i].bullet[j].position, enemy[i].bullet[j].radius, enemy[i].bullet[j].color);
            }
        }
    }

    //信息
    DrawText(TextFormat("TIME: %.02f", (float)framesCounter / MAX_FPS), 10, 10, 10, BLACK);
    DrawText(TextFormat("FPS: %.02f", (float)GetFPS()), MeasureText("TIME: %000000000.02f", 10), 10, 10, BLACK);

    DrawText(TextFormat("HEALTH: %d", player.health), WIDTH - 120, 10, 15, BLACK);
    DrawText(TextFormat("SPEED: %.02f", player.speed), WIDTH - 120, 30, 15, BLACK);
    DrawText(TextFormat("SCORE: %d", player.score), WIDTH - 120, 50, 15, BLACK);

    //胜利||失败
    if (gameOver && player.defeat == MAX_ENEMY) {
        DrawText("--- YOU WIN ---", WIDTH / 2 - MeasureText("--- YOU WIN ---", 50) / 2, HEIGHT / 2 - 60, 50, RED);
        DrawText("PRESS [ENTER] TO PLAY AGAIN", WIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2,
                 HEIGHT / 2, 20, BLACK);

        if (IsMusicPlaying(background)) StopMusicStream(background);
        if (!pause) {
            PlaySound(win);
            pause = !pause;
        }
    } else if (gameOver) {
        DrawText("--- YOU LOSE ---", WIDTH / 2 - MeasureText("--- YOU LOSE ---", 50) / 2, HEIGHT / 2 - 60, 50, RED);
        DrawText("PRESS [ENTER] TO PLAY AGAIN", WIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2,
                 HEIGHT / 2, 20, BLACK);

        if (IsMusicPlaying(background)) StopMusicStream(background);
        if (!pause) {
            PlaySound(lose);
            pause = !pause;
        }
    }

    //暂停
    if (pause && !gameOver) {
        DrawText("--- PAUSED ---", WIDTH / 2 - MeasureText("--- PAUSED ---", 50) / 2, HEIGHT / 2 - 60, 50, BLACK);
    }

    EndDrawing();
}

static void DrawGameU(Music& background, Sound& end) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    //玩家
    Vector2 v1 = {player.position.x + sinf(player.rotation * DEG2RAD) * (player.height),
                  player.position.y - cosf(player.rotation * DEG2RAD) * (player.height)};
    Vector2 v2 = {player.position.x - cosf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2),
                  player.position.y - sinf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2)};
    Vector2 v3 = {player.position.x + cosf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2),
                  player.position.y + sinf(player.rotation * DEG2RAD) * (PLAYER_SIZE / 2)};
    DrawTriangle(v1, v2, v3, player.color);

    //玩家--子弹
    for (int i = 0; i < MAX_BULLET; ++i) {
        if (player.bullet[i].active == true) {
            DrawCircleV(player.bullet[i].position, player.bullet[i].radius, player.bullet[i].color);
        }
    }

    //敌人
    for (int i = 0; i < MAX_ENEMY; i++) {
        DrawCircleV(enemy[i].position, enemy[i].radius, GRAY);

        //敌人--子弹
        for (int j = 0; j < MAX_BULLET; ++j) {
            if (enemy[i].bullet[j].active == true) {
                DrawCircleV(enemy[i].bullet[j].position, enemy[i].bullet[j].radius, enemy[i].bullet[j].color);
            }
        }
    }

    //信息
    DrawText(TextFormat("TIME: %.02f", (float)framesCounter / MAX_FPS), 10, 10, 10, BLACK);
    DrawText(TextFormat("FPS: %.02f", (float)GetFPS()), MeasureText("TIME: %000000000.02f", 10), 10, 10, BLACK);

    DrawText(TextFormat("HEALTH: %d", player.health), WIDTH - 120, 10, 15, BLACK);
    DrawText(TextFormat("SPEED: %.02f", player.speed), WIDTH - 120, 30, 15, BLACK);
    DrawText(TextFormat("SCORE: %d", player.score), WIDTH - 120, 50, 15, BLACK);
    DrawText(TextFormat("DEFEAT: %d", player.defeat), WIDTH - 120, 70, 15, BLACK);

    //结束
    if (gameOver) {
        DrawText("--- WELL DONE ---", WIDTH / 2 - MeasureText("--- WELL DONE ---", 50) / 2, HEIGHT / 2 - 60, 50,
                 ORANGE);
        DrawText("PRESS [ENTER] TO PLAY AGAIN", WIDTH / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2,
                 HEIGHT / 2, 20, BLACK);

        if (IsMusicPlaying(background)) StopMusicStream(background);
        if (!pause) {
            PlaySound(end);
            pause = !pause;
        }
    }
    //暂停
    if (pause && !gameOver) {
        DrawText("--- PAUSED ---", WIDTH / 2 - MeasureText("--- PAUSED ---", 50) / 2, HEIGHT / 2 - 60, 50, BLACK);
    }

    EndDrawing();
}

static void UnloadGame(Music& background, Music& backgroundU, Sound& shoot, Sound& defeat, Sound& win, Sound& lose,
                       Sound& end) {
    UnloadMusicStream(background);
    UnloadMusicStream(backgroundU);
    UnloadSound(shoot);
    UnloadSound(lose);
    UnloadSound(win);
    UnloadSound(end);
    UnloadSound(defeat);

    CloseAudioDevice();
    CloseWindow();
}