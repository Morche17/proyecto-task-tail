#include <raylib.h>
#include <raygui.h>

int main(void)
{
  bool buttonPressed = false;
  int counter = 0;
  
  // Una ventana básica con un texto normal
  InitWindow(800, 450, "Task Tail 0.0.1");

  while(!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);

      // Texto de relleno.
      DrawText("Congratulation. Now you are furry :3", 150, 200, 20, RAYWHITE);

      // Dibujar elementos de la interfaz de usuario
      buttonPressed = GuiButton((Rectangle){ 100, 100, 200, 50 }, "Presionar");
        if (buttonPressed)
          counter++;

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
