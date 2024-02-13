#include <raylib.h>

int main(void)
{

  // Una ventana básica con un texto normal
  InitWindow(800, 450, "Task Tail 0.0.1");

  while(!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BLACK);

      // Texto de relleno.
      DrawText("Congratulation. Now you are furry :3", 150, 200, 20, RAYWHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
