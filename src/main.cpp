#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <raylib.h>
#include <raygui.h>
#include <ctime>
#include <string>

//----------------------------------------------------------------------------------
// Declaración de las funciones para el tiempo y fecha
//----------------------------------------------------------------------------------
struct Fecha{
    int dia;
    int mes;
    int año;
};

Fecha fecha_actual;

// Función para determinar si un año es bisiesto
bool esBisiesto(int año) {
    return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
}

// Función para obtener el número de días en un mes
int obtenerDiasEnMes(int mes, int año) {
    if (mes == 2) {
        return esBisiesto(año) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Función para avanzar un día
void avanzarDia(Fecha &fecha) {
    int diasEnMes = obtenerDiasEnMes(fecha.mes, fecha.año);

    fecha.dia++;
    if (fecha.dia > diasEnMes) {
        fecha.dia = 1;
        fecha.mes++;
        if (fecha.mes > 12) {
            fecha.mes = 1;
            fecha.año++;
        }
    }
}

// Función para retroceder un día
void retrocederDia(Fecha &fecha) {
    fecha.dia--;
    if (fecha.dia < 1) {
        fecha.mes--;
        if (fecha.mes < 1) {
            fecha.mes = 12;
            fecha.año--;
        }
        fecha.dia = obtenerDiasEnMes(fecha.mes, fecha.año);
    }
}

//------------------------------------------------------------------------------------
// Función principal
//------------------------------------------------------------------------------------
int main()
{
    // Inicialización
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    // Función para obtener la fecha en curso
    std::time_t tiempoActual = std::time(nullptr);

    // Definiendo el formato de la fecha
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&tiempoActual));

    // Obtener la fecha actual del sistema
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // Asignar la fecha actual al struct Fecha
    fecha_actual.dia = ltm->tm_mday;
    fecha_actual.mes = 1 + ltm->tm_mon;
    fecha_actual.año = 1900 + ltm->tm_year;

    InitWindow(screenWidth, screenHeight, "Task Tail 0.0.1");
    
    //------------------------------------------------------------------------------------
    // task-tail: inicialización de controles
    //----------------------------------------------------------------------------------
    bool diaSiguientePressed = false;
    bool diaAnteriorPressed = false;
    bool botonLimpiarPressed = false;
    bool botonGuardar000 = false;
    bool botonGuardar001 = false;
    bool botonGuardar002 = false;
    bool botonGuardar003 = false;
    bool botonGuardar004 = false;
    bool botonGuardar005 = false;
    bool botonGuardar006 = false;
    bool botonGuardar007 = false;
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

    // Cargando la tipografía
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

            // Dibujar la fecha actual
            DrawTextEx(scoreFont, ("Fecha: " + std::to_string(fecha_actual.dia) + "/" + std::to_string(fecha_actual.mes) + "/" + std::to_string(fecha_actual.año)).c_str(), (Vector2){20, 20}, 20, 2, BLACK);
        
            //----------------------------------------------------------------------------------
            // Botones con sus funcionalidades
            //----------------------------------------------------------------------------------
            diaSiguientePressed = GuiButton((Rectangle){ 672, 417, 120, 24 }, "Dia siguiente"); 
            if (diaSiguientePressed)
            {
                avanzarDia(fecha_actual);
            }
            diaAnteriorPressed = GuiButton((Rectangle){ 24, 417, 120, 24 }, "Dia anterior"); 
            if (diaAnteriorPressed)
            {
                retrocederDia(fecha_actual);
            }
            botonLimpiarPressed = GuiButton((Rectangle){150, 417, 120, 24}, "Limpiar");
            if (botonLimpiarPressed)
            {
                strcpy(cajaTexto000Text, "");
                strcpy(cajaTexto001Text, "");
                strcpy(cajaTexto002Text, "");
                strcpy(cajaTexto003Text, "");
                strcpy(cajaTexto004Text, "");
                strcpy(cajaTexto005Text, "");
                strcpy(cajaTexto006Text, "");
            }
            botonGuardar000 = GuiButton((Rectangle){510, 48, 120, 24}, "Guardar");
            if (botonGuardar000){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 7h --value " + std::string(cajaTexto000Text);
                std::system(escrituraCajaTexto.c_str());            
            }

            botonGuardar001 = GuiButton((Rectangle){510, 88, 120, 24}, "Guardar");
            if (botonGuardar001){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 8h --value " + std::string(cajaTexto001Text);
                std::system(escrituraCajaTexto.c_str());
            }

            botonGuardar002 = GuiButton((Rectangle){510, 128, 120, 24},"Guardar");
            if (botonGuardar002){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 9h --value " + std::string(cajaTexto002Text);
                std::system(escrituraCajaTexto.c_str());        
            }

            botonGuardar003 = GuiButton((Rectangle){510, 168, 120, 24},"Guardar");
            if (botonGuardar003){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 10h --value " + std::string(cajaTexto003Text);
                std::system(escrituraCajaTexto.c_str());        
            }

            botonGuardar004 = GuiButton((Rectangle){510, 208, 120, 24},"Guardar");
            if (botonGuardar004){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 11h --value " + std::string(cajaTexto004Text);
                std::system(escrituraCajaTexto.c_str());        
            }            

            botonGuardar005 = GuiButton((Rectangle){510, 248, 120, 24},"Guardar");
            if (botonGuardar005){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 12h --value " + std::string(cajaTexto005Text);
                std::system(escrituraCajaTexto.c_str());        
            }

            botonGuardar006 = GuiButton((Rectangle){510, 288, 120, 24},"Guardar");
            if (botonGuardar006){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 13h --value " + std::string(cajaTexto006Text);
                std::system(escrituraCajaTexto.c_str());        
            }        
            botonGuardar007 = GuiButton((Rectangle){510, 328, 120, 24}, "Guardar");
            if (botonGuardar007){
                std::string escrituraCajaTexto = "./src/escritura_de_datos --key 14h --value " + std::string(cajaTexto007Text);
                std::system(escrituraCajaTexto.c_str());
            }
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

