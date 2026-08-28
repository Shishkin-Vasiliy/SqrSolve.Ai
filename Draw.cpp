#include "header.h"

void DrawPoints(float X[], float Y[])
{
    assert(X && Y);

    // отключение вывода информации от raylib в терминал
    SetTraceLogLevel(LOG_NONE);     

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "");

    while (!WindowShouldClose())    
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawAxes();                

            for (int i = 0; i < MAX_POINTS - 1; i++)
                {
                    DrawLineEx({X[i], Y[i]}, {X[i + 1], Y[i + 1]}, LINE_THICKNESS, BLACK);
                }

            EndDrawing();  
        }
    CloseWindow();
    printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR "\n");
}        

void DrawAxes(void)
{
    const float STEP = 20;
    const float MARK_SIZE = 14;

    // разметка осей
    for (float x = 0; x < SCREEN_WIDTH; x = x + STEP)
        DrawLineEx({x, Y_ZERO + MARK_SIZE / 2}, {x, Y_ZERO - MARK_SIZE / 2}, AX_THICKNESS, BLACK);
    for (float y = 0; y < SCREEN_HEIGHT; y = y + STEP)
        DrawLineEx({X_ZERO - MARK_SIZE / 2, y}, {X_ZERO + MARK_SIZE / 2, y}, AX_THICKNESS, BLACK);    

    // оси
    DrawLineEx({0, Y_ZERO}, {SCREEN_WIDTH, Y_ZERO}, AX_THICKNESS, BLACK);  
    DrawTriangle({SCREEN_WIDTH, Y_ZERO}, {SCREEN_WIDTH - 10, Y_ZERO - 10}, {SCREEN_WIDTH - 10, Y_ZERO + 10}, BLACK);
    DrawText("X", SCREEN_WIDTH - 30, Y_ZERO - 30, 30, BLACK);

    DrawLineEx({X_ZERO, 0}, {X_ZERO, SCREEN_HEIGHT}, AX_THICKNESS, BLACK); 
    DrawTriangle({X_ZERO, SCREEN_HEIGHT}, {X_ZERO - 10, SCREEN_HEIGHT - 10}, {X_ZERO + 10, SCREEN_HEIGHT - 10}, BLACK);
    DrawText("Y", X_ZERO - 50, SCREEN_HEIGHT - 30, 30, BLACK);

    // начало отсчета
    DrawText("0", X_ZERO - 30, Y_ZERO - 30, 30, BLACK);   
}

void DrawLinear(double b, double c, float X[])
{
    assert(X);

    float Y[MAX_POINTS] = {};

    for (int i = 0; i < MAX_POINTS - 1; i++)
    {
        Y[i] = (float) (b * (X[i] - X_ZERO) + c + Y_ZERO);
    }

    DrawPoints(X, Y); 
}

void DrawParabola(double a, double b, double c, float X[])
{
    assert(X);

    float Y[MAX_POINTS] = {};

    for (int i = 0; i < MAX_POINTS - 1; i++)
    {
        Y[i] = (float) (a * (X[i] - X_ZERO) * (X[i] - X_ZERO) + b * (X[i] - X_ZERO) + c + Y_ZERO);
    }
    
    DrawPoints(X, Y);
}

void DrawMain(struct equation Eq)
{
    float X[MAX_POINTS] = {};

    double a = Eq.a;
    double b = Eq.b;
    double c = Eq.c;
    int nRoots = Eq.nRoots;

    float x = 0.0;

    for (int i = 0; i < MAX_POINTS; i++, x++)
    {
        X[i] = x;
    }

    switch(nRoots)
    {
        case INF_ROOTS :
            break;

        case ONE_ROOT :
            {
                if (Cmp(a, 0.0, PRECISION) != 0)
                    DrawParabola(a, b, c, X);
                else
                    DrawLinear(b, c, X);
            }    
            break;

        case TWO_ROOTS :
            DrawParabola(a, b, c, X);
            break;
        
        case COMPLEX_ROOTS : 
            DrawParabola(a, b, c, X);
            break;
        
        default :
            ;
    }
}
