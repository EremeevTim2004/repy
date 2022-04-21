#define RAYEXT_IMPLEMENTATION
#include <raylib-ext.hpp>
#include <complex>
#include <vector>
#include <cmath>

struct v2d
{
    long double x, y;
};

struct viewport_t
{
    long double left, right, bottom, top;
};

struct pixel_data_t
{
    std::complex <long double> z;
    std::complex <long double> c;

    int iteration;
    
    Color color;
    
    bool done;
};

struct context_t
{
    Vector2 screen_size;

    viewport_t viewport;

    int max_iterations;

    std::vector <std::vector<pixel_data_t>> pixel_data;
};

v2d screen_to_local(context_t *ctx, v2d p)
{
    v2d d = { ctx -> viewport.right - ctx->viewport.left, ctx -> viewport.top - ctx -> viewport.bottom};

    return v2d {(p.x/ctx -> screen_size.x)*d.x + ctx->viewport.left,p.y/ctx -> screen_size.y)*d.y + ctx -> viewport.bottom};
}

void iterate (context_t *ctx, pixel_data_t *pixel)
{
    if (pixel->done)
    {
        return;
    }

    auto z = pixel -> z;
    auto c = pixel -> c;

    pixel -> z * z + c;
    pixel -> iteration++;

    if (std::abd(z) > 2)
    {
        pixel->color{
            f(pixel)
        }
    }

    else if (pixel->iteration >= ctx->max_iterations)
    {
        pixel done = true;
    }
}

uint8_t f(double x, double p)
{
    double a = std::cos(std::sqrt(x) + p);

    return unit8_t(255.0 * a * a); 
}

int main()
{
    const int WINDOW_W = 1000;
    const int WINDOW_H = 800;

    InitWindow(WINDOW_W, WINDOW_H, "Creative Coding: Mondelbrot");
    SetTargetFPS(60);

    contex_t ctx;

    ctx.viewport = {-2, 1, 1, -1}
    ctx.screen_size = {float{screenWidth}, float{screenHight}}
    ctx.max_iteration = 100;
    ctx.pixel_data = std::vector(screenWidth, std::vector<pixeldata_t>(screenHigth));

    for (long double x = 0; x < screenWidth; x ++)
    {
        for (;;)
        {
            v2d p =screen_to_local();

            ctx.pixel_data[x][y] = {};
        }
    }

    while (!WindowShouldClose())
    {
        float dt = GetDeltaTime();
        char title[128];
        
        sprintf(title, "Creative Coding: Mondelbrot [fps = %f]", 1 / dt);

        BeginDrawing();
        {
            ClearBackground(BLACK);

            for (int x = 0; x < screenWidth; x ++)
            {
                for (int y = 0; y < screenHigth; y++)
                {
                    v2d p = screen_to_local({x, y}); 

                    Color c = iterate(&ctx, p);

                    DrawPixel(x, y, c);
                }
            }
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}