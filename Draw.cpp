#include "header.h"

/**
    \brief Программа управления графикой.
    Заполняет массив X из MAX_POINTS идущих подряд точек (с постоянным шагом).
    Затем в зависимости от вида уравнения, поступившего на вход, рисует нужный график.
*/
void DrawMain(struct equation Eq)
{
    float X[MAX_POINTS] = {};

    double a = Eq.a;
    double b = Eq.b;
    double c = Eq.c;
    int nRoots = Eq.nRoots;

    float x = -SCREEN_WIDTH / 2;

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
                    DrawParabola(a, b, c, X, Eq);
                else
                    DrawLinear(b, c, X, Eq);
            }    
            break;

        case TWO_ROOTS :
            DrawParabola(a, b, c, X, Eq);
            break;
        
        case COMPLEX_ROOTS : 
            DrawParabola(a, b, c, X, Eq);
            break;
        
        default :
            ;
    }
}

/**
    \brief Функция, отвечающая за отрисовку точек.
    \param X
    \param Y
    Функция рисует график отрезками между i и i+1 точками в массивах координат.
*/
void DrawGraph(float X[], float Y[], struct equation Eq)
{
    assert(X && Y);

    // отключение вывода информации от raylib в терминал
    SetTraceLogLevel(LOG_NONE);     

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "");

    Camera2D camera = { 0 };
    camera.target = (Vector2){ 0.0f, 0.0f };      
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f }; 
    camera.rotation = 0.0f;                       
    camera.zoom = 1.0f;

    while (!WindowShouldClose())    
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);

            DrawAxes(); 
            DrawRectangle(SCREEN_WIDTH / 2 - 375.0f, SCREEN_HEIGHT / 2 - 160.0f, 350, 100, WHITE);
            DrawLegend(SCREEN_WIDTH / 2 - 350.0f, SCREEN_HEIGHT / 2 - 150.0f, "a = %lg, b = %lg, c = %lg", Eq.a, Eq.b, Eq.c);
            DrawLegend(SCREEN_WIDTH / 2 - 350.0f, SCREEN_HEIGHT / 2 - 120.0f, "x1_Re = %lg, x1_Im = %lg", Eq.x1_Re, Eq.x1_Im);
            DrawLegend(SCREEN_WIDTH / 2 - 350.0f, SCREEN_HEIGHT / 2 - 90.0f, "x2_Re = %lg, x2_Im = %lg", Eq.x2_Re, Eq.x2_Im);

                           
            for (int i = 0; i < MAX_POINTS - 1; i++)
                {
                    DrawLineEx({X[i], Y[i]}, {X[i + 1], Y[i + 1]}, LINE_THICKNESS, BLUE);
                }
            
            EndMode2D();

            EndDrawing();  
        }
    CloseWindow();
    printf(PURPLE_CNSL "-----------------------------------------" NO_COLOR "\n");
}        

/**
    \brief Отрисовка осей координат.
*/
void DrawAxes(void)
{
    const float STEP = 20;
    const float MARK_SIZE = 14;

    for (float x = -SCREEN_WIDTH / 2; x < SCREEN_WIDTH / 2; x = x + STEP)
        DrawLineEx({x, MARK_SIZE / 2}, {x, -MARK_SIZE / 2}, AX_THICKNESS, BLACK);
    for (float y = -SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT / 2; y = y + STEP)
        DrawLineEx({-MARK_SIZE / 2, y}, {MARK_SIZE / 2, y}, AX_THICKNESS, BLACK);    

    DrawLineEx({-SCREEN_WIDTH / 2, 0.0f}, {SCREEN_WIDTH / 2, 0.0f}, AX_THICKNESS, BLACK);  
    DrawTriangle({SCREEN_WIDTH / 2, 0.0f}, {SCREEN_WIDTH / 2 - 10.0f, -10.0f}, {SCREEN_WIDTH / 2 - 10.0f, 10.0f}, BLACK);
    DrawText("X", SCREEN_WIDTH / 2 - 30.0f, -30.0f, 30.0f, BLACK);

    DrawLineEx({0.0f, -SCREEN_HEIGHT / 2}, {0, SCREEN_HEIGHT / 2}, AX_THICKNESS, BLACK); 
    DrawTriangle({0.0f, -SCREEN_HEIGHT / 2}, {-10.0f, -SCREEN_HEIGHT / 2 + 10.0f}, {10.0f, -SCREEN_HEIGHT / 2 + 10.0f}, BLACK);
    DrawText("Y", -30.0f, -SCREEN_HEIGHT / 2 + 10.0f, 30.0f, BLACK);

    DrawText("0", -30.0f, -30.0f, 30.0f, BLACK);   
}

/**
    \brief Функция рисует график линейной функции.
    Смещения координат в формуле на X_ZERO и Y_ZERO нужно для того, чтобы график рисовался в центре экрана,
    В библиотеке raylib.h начало координат находится в верхнем левом углу окна по умолчанию.
*/
void DrawLinear(double b, double c, float X[], struct equation Eq)
{
    assert(X);

    float Y[MAX_POINTS] = {};

    for (int i = 0; i < MAX_POINTS - 1; i++)
    {
        Y[i] = (float) (-(b * X[i] + c));
    }

    DrawGraph(X, Y, Eq); 
}

/**
    \brief Функция рисует график параболы.
    Смещения координат в формуле на X_ZERO и Y_ZERO нужно для того, чтобы график рисовался в центре экрана,
    В библиотеке raylib.h начало координат находится в верхнем левом углу окна по умолчанию.
    
*/
void DrawParabola(double a, double b, double c, float X[], struct equation Eq)
{
    assert(X);

    float Y[MAX_POINTS] = {};

    for (int i = 0; i < MAX_POINTS - 1; i++)
    {
        Y[i] = (float) (-(a * X[i] * X[i] + b * X[i] + c));
    }
    
    DrawGraph(X, Y, Eq);
}

void DrawLegend(int x, int y, const char *fmt, ...)
{
    char buf[MAX_STR] = {};

    va_list args = {};

    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);

    DrawText(buf, x, y, 20.0f, BLACK);
}

//void DrawLegend(struct equation Eq)
//{
//    char buf_1[MAX_STR] = {};
//    char buf_2[MAX_STR] = {};
//    const char *fmt_1 = "a = %lg, b = %lg, c = %lg, D = %lg, nRoots = %d";
//    const char *fmt_1 = "x1_Re = %lg, x1_Im = %lg, x2_Re = %lg, x2_Im = %lg";
//
//    va_list args_1 = {};
//    va_list args_2 = {};
//
//    va_start(args_1, fmt_1);
//    va_start(args_2, fmt_2);
//    vsprintf(buf_1, fmt_1, args_1);
//    vsprintf(buf_2, fmt_2, args_2);
//    va_end(args_1);
//    va_end(args_2);
//
//    (const char *) buf_1;
//    (const char *) buf_2;
//
//    DrawText(buf_1, SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 20.0f, PURPLE);
//}

