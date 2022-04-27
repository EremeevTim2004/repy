#include <iostream>
#include <raylib-ext.hpp>

// for consts values
const int screenWidth = 640;
const int screenHeight = 640;

const int board_w = 8;
const int board_h = 8;

const int cell_size = screenWidth / board_w;

// function for map making
int board[BOARD_W][BOARD_H] = {
    { 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1 },
};

//struct
struct player_t
{
    Vector2 pos;

    float rotation;
    float speed;
};

struct hit_t
{
    Vector2 pos;

    struct {int x, y} cell_pos;
};

bool correct_cell(int x, int y)
{
    return(x >= 0 && x < board_w) && (y >=) 0 && 
}

//Vertical hit
hit_t cast_ray(Vector2 pos, float dir)
{
    while (dir > PI)
    {
        dir -= 2 * PI;
    }

    while (dir < -PI)
    {
        dir += 2 * PI;
    }

    int cell_x = pos.x / cell_size;
    int cell_y = pos.y / cell_size;

    for (int k = 0; ; k ++)
    {
        int shift;
        int k_dir;

        if (dir > -PI / 2 && dir < PI / 2)
        {
            shift = 1;

            k_dir = 1
        }

        else{
            shift = 0;

            k_dir = -1;
        }

        float dx = (cell_x + shift + k * k_dir) * cell_size - pos.x;
        float dy = dx * tan(dir);

        Vector2 d = {dx, dy};
        Vector2 hit = d + pos;

        int cell_hit_x = int(hit.x / cell_size) + shift - 1;
        int cell_hit_y = int(hit.x / cell_size);

        hit_data_v.pos = hit;
        hit_data_v.cell_pos = {cell_hit_x, cell_hit_y};

        if (!correct_cell(cell_hit_x, cell_hit_y))
        {
            break;
        }

        if (board[cell_hit_x][cell_hit_y] != 0)
        {
            break;
        }
    }

    return hit_data;
}

// Horizon hit


int main()
{
    IntWindow(screenWidth, screenHeight, "GDSC: Creative Coding");
    SetTargetFPS(60);

    player_t player;
    player.pos = {};
    player.speed = 100;
    player.

    while(!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_W))
        {
            player.pos.y -= player.speed * dt;
        }

        if (IsKeyDown(KEY_S))
        {
            player.pos.y += player.speed * dt;
        }

        if (IsKeyDown(KEY_A))
        {
            player.pos.x -= player.speed * dt;
        }

        if (IsKeyDown(KEY_D))
        {
            player.pos.x += player.speed * dt;
        }

        Vector2 mp = { GetMouseX() - player.pos.x, GetMousY - player.pos.y};

        player.rotation = Vector2Angle({1, 0}, mp);

        BeginDrawing();
        {
            CleanBackground(WHITE);

            for (int row = 0; row < board_h; row ++)
            {
                for (int col = 0; col < board_w; col ++)
                {
                    if (board[col][row] == 1)
                    {
                        DrawRectangle(col * cell_size, row * cell_size, cell_size, cell_size, BLACK);
                    }
                }

                for (int x = cell_size; x < screenWidth; x += cell_size)
                {
                    DrawLine();
                }

                for (int y = cell_size; y < screenHeight; y += cell_size)
                {
                    DrawLine();
                }

                DrawingCircleV(player.pos, 15, RED);

                DrawLineEx(player.pos, player.pos + Vector2Rotate({1, 0}, player.rotation) * 10, 5, BLUE);

                hit_t = cast_ray(player.pos, player.rotation);

                DrawLineEx(player.pos, hit.pos, 2 , GREEN)
            }
        }
    }

    return 0;
}