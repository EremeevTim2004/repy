#define RAYEXT_IMPLEMENTATION
#include <raylib-ext.hpp>

const Color BG_COLOR = WHITE;
const Color ACTIVE_COLOR = BLACK;
const Color BOARDER_COLOR = GREEN;

const int screenWidth = 1020;
const int screenHeight = 780;

const int SQUARE_SIZE = 20;

const int BOARD_W = screenWidth / SQUARE_SIZE;
const int BOARD_H = screenHeight / SQUARE_SIZE
;
bool board[BOARD_H][BOARD_W] = {0};

bool isValid(int x, int y){
    return (0 <= x && x <= BOARD_W) && (0 <= y && y <= BOARD_H);
}

int main()
{

    InitWindow(screenWidth, screenHeight, "GDSC: Creative Coding");
    SetTargetFPS(60);

    // Glider
    board[3][1] = 1;
    board[3][2] = 1;
    board[3][3] = 1;
    board[2][3] = 1;
    board[1][2] = 1;

    bool is_running = 0;
    float time_out = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(BG_COLOR);

            if (!is_running){
                int msx = GetMouseX() / SQUARE_SIZE;
                int msy = GetMouseY() / SQUARE_SIZE;

                if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    board[msy][msx] = 1;
                }
                
                if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
                    board[msy][msx] = 0;
                }
            }

            if(IsKeyPressed(KEY_SPACE)){
                is_running = !is_running;
            }

            for (int sy = 0; sy < BOARD_H; ++sy){
               for (int sx = 0; sx < BOARD_W; ++sx){
                    if (board[sy][sx]){
                        DrawRectangle(sx * SQUARE_SIZE, sy * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, ACTIVE_COLOR);
                    }
                }
             }

            for (int y = 0; y < screenHeight; y += SQUARE_SIZE){
                DrawLine(0, y, screenWidth, y, BOARDER_COLOR);
            }

            for (int x = 0; x < screenWidth; x += SQUARE_SIZE){
                DrawLine(x, 0, x, screenHeight, BOARDER_COLOR);
            }    
        }

        EndDrawing();

        if(time_out <= 0){
            time_out = 0.1;
        }
        
        else{
            time_out -= GetFrameTime();

            continue;
        }

        if (is_running){
            bool buf[BOARD_H][BOARD_W] = {0};

            for (int sy = 0; sy < BOARD_H;++sy){
                for (int sx = 0; sx < BOARD_W; ++sx){
                    int alive = 0;

                    for (int i = 0; i < 9; ++i){
                        int x = i % 3 + sx - 1;
                        int y = i / 3 + sy - 1;

                        if ((x != sx) || (y != sy) && isValid(x, y)){
                            alive += board[y][x];
                        }
                    }

                    if (board[sy][sx]){
                        buf[sy][sx] = (alive == 2 || alive == 3);
                    }
                    
                    else{
                        buf[sy][sx] = (alive == 3);
                    }
                }
            }

            memcpy(board, buf, sizeof(board));
        }    

    }
    CloseWindow();

    return 0;
}