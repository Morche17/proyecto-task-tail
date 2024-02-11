#include <raylib.h>

int main(void)
{

  // Una ventana básica con un texto normal
  InitWindow(800, 450, "Task Tail 0.0.1");

  while(!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(RAYWHITE);

      // Texto de relleno.
      DrawText("Aquí comienza la creación del zorro tareas cola digital.", 190, 200, 20, BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
