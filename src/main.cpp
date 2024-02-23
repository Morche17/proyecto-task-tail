#include <cstdio>
#include <cstdlib>
#include <raylib.h>
#include <raygui.h>
#include <ctime>
#include <string>
// #include "almacenamiento.cpp"

// #define MAX_INPUT_CHARS 256

//----------------------------------------------------------------------------------
// Declaración de las funciones de los controles
//----------------------------------------------------------------------------------


// void escritura_texto_en_archivo(const char *texto)
// {
//   FILE *archivo = fopen("datos.txt", "w");
//   if (archivo == NULL) {
//       printf("Error al abrir el archivo para escritura.\n");
//       return;
//   }

//   fprintf(archivo, "%s\n", texto);

//   fclose(archivo);
// }

//------------------------------------------------------------------------------------
int main()
{
    // Inicialización
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    // char texto[MAX_INPUT_CHARS+1] = {0};

    // Función para obtener la fecha en curso
    std::time_t tiempoActual = std::time(nullptr);

    // Definiendo el formato de la fecha
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&tiempoActual));

    InitWindow(screenWidth, screenHeight, "Task Tail 0.0.1");

    // task-tail: inicialización de controles
    //----------------------------------------------------------------------------------
    bool diaSiguientePressed = false;
    bool diaAnteriorPressed = false;
    bool botonGuardarPressed = false;
    bool cajaTexto000EditMode = false;
    char cajaTexto000Text[128] = " ";
    bool cajaTexto001EditMode = false;
    char cajaTexto001Text[128] = " ";
    bool cajaTexto002EditMode = false;
    char cajaTexto002Text[128] = " ";
    bool cajaTexto003EditMode = false;
    char cajaTexto003Text[128] = " ";
    bool cajaTexto004EditMode = false;
    char cajaTexto004Text[128] = " ";
    bool cajaTexto005EditMode = false;
    char cajaTexto005Text[128] = " ";
    bool cajaTexto006EditMode = false;
    char cajaTexto006Text[128] = " ";
    bool cajaTexto007EditMode = false;
    char cajaTexto007Text[128] = " ";
  
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Font scoreFont = LoadFont("Fonts/Score.TTF");

    while (!WindowShouldClose())    // La ventana detecta botón de cerrar o botón ESC
    {
        // Actualización
        //----------------------------------------------------------------------------------
        // TODO: Implementación de lógica de actualización requerida
        //----------------------------------------------------------------------------------

        // Dibujar
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: dibujo de controles
            //----------------------------------------------------------------------------------
            diaSiguientePressed = GuiButton((Rectangle){ 672, 417, 120, 24 }, "Dia siguiente"); 
            if (diaSiguientePressed)
            {
              puts("Botón presionado");
            }
            diaAnteriorPressed = GuiButton((Rectangle){ 24, 417, 120, 24 }, "Dia anterior"); 
            if (diaAnteriorPressed)
            {
              puts("Botón presionado");
            }
            botonGuardarPressed = GuiButton((Rectangle){150, 417, 120, 24}, "Guardar");
            if (botonGuardarPressed)
            {
              std::string escrituraCajaTexto000 = "./src/escritura_de_datos -k " + std::string(buffer) + " -v " + std::string(cajaTexto000Text);
              std::system(escrituraCajaTexto000.c_str());
            }
            
            if (GuiTextBox((Rectangle){ 72, 48, 432, 24 }, cajaTexto000Text, 128, cajaTexto000EditMode)) cajaTexto000EditMode = !cajaTexto000EditMode;
            if (GuiTextBox((Rectangle){ 72, 88, 432, 24 }, cajaTexto001Text, 128, cajaTexto001EditMode)) cajaTexto001EditMode = !cajaTexto001EditMode;
            if (GuiTextBox((Rectangle){ 72, 128, 432, 24 }, cajaTexto002Text, 128, cajaTexto002EditMode)) cajaTexto002EditMode = !cajaTexto002EditMode;
            if (GuiTextBox((Rectangle){ 72, 168, 432, 24 }, cajaTexto003Text, 128, cajaTexto003EditMode)) cajaTexto003EditMode = !cajaTexto003EditMode;
            if (GuiTextBox((Rectangle){ 72, 208, 432, 24 }, cajaTexto004Text, 128, cajaTexto004EditMode)) cajaTexto004EditMode = !cajaTexto004EditMode;
            if (GuiTextBox((Rectangle){ 72, 248, 432, 24 }, cajaTexto005Text, 128, cajaTexto005EditMode)) cajaTexto005EditMode = !cajaTexto005EditMode;
            if (GuiTextBox((Rectangle){ 72, 288, 432, 24 }, cajaTexto006Text, 128, cajaTexto006EditMode)) cajaTexto006EditMode = !cajaTexto006EditMode;
            GuiLabel((Rectangle){ 24, 48, 48, 24 }, "7:00 -");
            GuiLabel((Rectangle){ 24, 88, 48, 24 }, "8:00 -");
            GuiLabel((Rectangle){ 24, 128, 48, 24 }, "9:00 -");
            GuiLabel((Rectangle){ 24, 168, 48, 24 }, "10:00 -");
            GuiLabel((Rectangle){ 24, 208, 48, 24 }, "11:00 -");
            GuiLabel((Rectangle){ 24, 248, 48, 24 }, "12:00 -");
            GuiLabel((Rectangle){ 24, 288, 48, 24 }, "13:00 -");
            if (GuiTextBox((Rectangle){ 72, 328, 432, 24 }, cajaTexto007Text, 128, cajaTexto007EditMode)) cajaTexto007EditMode = !cajaTexto007EditMode;
            GuiLabel((Rectangle){ 24, 328, 48, 24 }, "14:00 -");
            // GuiLabel((Rectangle){ 680, 15, 80, 24 }, buffer);
            DrawTextEx(scoreFont, buffer, (Vector2){600.f, 15.f}, 18.f, 1.f, BLACK);
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadFont(scoreFont);
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Cierre de ventana
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Definiciones de las funciones de los controles Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

