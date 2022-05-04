#define RAYEXT_IMPLEMENTATION
#include <raylib-ext.hpp>
#include <vector>
 
const int screenWidth = 640;
const int screenHeight = 640;
 
const int board_w = 8;
const int board_h = 8;
 
const int cell_size = screenWidth / board_w;
 
int board[board_w][board_h] = {
    { 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1 },
};
 
Image wall_image = LoadImage("./textures")

struct player_t
{
    Vector2 pos;

    float rotation;
    float speed;
    float fov;
    
    int rays_count;
};
 
struct hit_t
{
    Vector2 pos;

    struct { int x, y; } cell_pos;

    bool is_horizontal;
};
 
bool correct_cell(int x, int y)
{
    return (x >= 0 && x < board_w) && (y >= 0 && y < board_h);
}
 
hit_t cast_ray(Vector2 pos, float dir)
{
    while (dir > PI)  
    {
        dir -= 2 * PI;
    }

    while (dir < -PI) dir += 2 * PI;
 
    int cell_x = pos.x / cell_size;
    int cell_y = pos.y / cell_size;
 
    hit_t hit_data_v, hit_data_h;
 
    // Vertical hit
    for (int k = 0; ; ++k)
    {
        int shift;
        int k_dir;
        
        if (dir > -PI / 2 && dir < PI / 2)
        {
            shift = 1;
            k_dir = 1;
        }

        else
        {
            shift = 0;
            k_dir = -1;
        }
 
        float dx = (cell_x + shift + k * k_dir) * cell_size - pos.x;
        float dy = dx * tan(dir);

        Vector2 d = { dx, dy };
        Vector2 hit = d + pos;
 
        int cell_hit_x = int(hit.x / cell_size) + shift - 1;
        int cell_hit_y = int(hit.y / cell_size);
 
        hit_data_v.pos = hit;
        hit_data_v.cell_pos = { cell_hit_x, cell_hit_y };
        hit_data_v.is_horizontal = false;
 
        if (!correct_cell(cell_hit_x, cell_hit_y))
        {
            break;
        }

        if (board[cell_hit_x][cell_hit_y] != 0)
        {
            break;
        }
    }
 
    // Horizontal hit
    for (int k = 0; ; ++k)
    {
        int shift;
        int k_dir;
        
        if (dir > -PI && dir < 0)
        {
            shift = 0;
            k_dir = -1;
        }

        else
        {
            shift = 1;
            k_dir = 1;
        }
 
        float dy = (cell_y + shift + k * k_dir) * cell_size - pos.y;
        float dx = dy / tan(dir);

        Vector2 d = { dx, dy };
        Vector2 hit = d + pos;
 
        int cell_hit_x = int(hit.x / cell_size);
        int cell_hit_y = int(hit.y / cell_size) + shift - 1;
 
        hit_data_h.pos = hit;
        hit_data_h.cell_pos = { cell_hit_x, cell_hit_y };
        hit_data_h.is_horizontal = true;
 
        if (!correct_cell(cell_hit_x, cell_hit_y))
        {
            break;
        }

        if (board[cell_hit_x][cell_hit_y] != 0)
        {
            break;
        }
    }
 
    if (Vector2Length(hit_data_h.pos - pos) < Vector2Length(hit_data_v.pos - pos))
    {
        return hit_data_h;
    }
    
    else {
        return hit_data_v;
    }
}
 
int main()
{
    InitWindow(screenWidth * 2, screenHeight, "GDSC: Creative Coding");
    SetTargetFPS(60);
 
    player_t player;

    player.pos = { screenWidth / 2, screenHeight / 2 };
    player.speed = 100;
    player.rotation = 0;
    player.fov = 60;
    player.rays_count = 240;

    float delta_angle = player.fov / player.rays_count;
 
    while (!WindowShouldClose())
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

        Vector2 mp = {GetMouseX() - player.pos.x, GetMouseY() - player.pos.y};

        player.rotation = Vector2Angle({ 1, 0 }, mp);
 
        BeginDrawing();
        {
            ClearBackground(PURPLE);
 
            DrawRectangle(screenWidth, screenHeight / 2, screenWidth, screenHeight / 2, GREEN);
 
            for (int row = 0; row < board_h; ++row)
            {
                for (int col = 0; col < board_w; ++col)
                {
                    if (board[col][row] == 1)
                    {
                        DrawRectangle(col * cell_size, row * cell_size, cell_size, cell_size, BLACK);
                    }
                }
            }
 
            for (int x = cell_size; x < screenWidth; x += cell_size)
            {
                DrawLine(x, 0, x, screenHeight, GRAY);
            }
            
            for (int y = cell_size; y < screenHeight; y += cell_size)
            {
                DrawLine(0, y, screenWidth, y, GRAY);
            }
 
            DrawCircleV(player.pos, 14, RED);
 
            DrawLineEx(player.pos, player.pos + Vector2Rotate({ 1,0 }, player.rotation) * 25, 5, BLUE);
 
            std::vector<hit_t> hits;
            for (float angle = -player.fov / 2; angle < player.fov / 2; angle += delta_angle) {
                hit_t hit = cast_ray(player.pos, player.rotation + angle * DEG2RAD);
                DrawLineEx(player.pos, hit.pos, 2, BLUE);
                hits.push_back(hit);
            }
 
            float rect_x = 0;
            for (hit_t& hit : hits)
            {
                Vector2 hit_delta = hit.pos - player.pos;
                float dist = hit_delta.x * cos(player.rotation) + hit_delta.y * sin(player.rotation);
 
                float rect_h = (cell_size * screenHeight) / dist;
                float rect_w = (screenWidth / player.fov) * delta_angle;
                float rect_y = (screenHeight - rect_h) / 2;
 
                Vector2 pos_in_cell = {hit.pos.x - hit.cell_pos.x * cell_size, hit.pos.y - hit.cell_pos.y * cell_size,};
                
                Vector2 column = pos_in_cell / cell_size * wall_image.width;

                int col = column.x;

                if (hit.is_horizontal)
                {
                    col = column.y;
                }

                for (int i = 0; i < wall_image.higth; i++)
                {
                    Color* color_data = (Color*)wall_image.data;

                    Color.pixel = color_data[i * wall_image.width + col]
                }

                // DrawRectangle(screenWidth + rect_x, (screenHeight - rect_h) / 2, rect_w + 1, rect_h, hit_color);
                


                rect_x += rect_w;
            }
        }

        EndDrawing();
    }

    CloseWindow();
 
    return 0;
}