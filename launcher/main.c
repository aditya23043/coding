#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_INPUT_CHARS 9

#define WIDTH 800
#define HEIGHT 450

int main(int argc, char *argv[]) {

  InitWindow(WIDTH, HEIGHT, "CLauncher");

  char input[MAX_INPUT_CHARS + 1] = "\0";
  int letter_count = 0;

  bool mouse_on_text = false;

  Rectangle text_box = {WIDTH / 2.0f - 100, 180, 225, 50};

  int frames_counter = 0;
  SetTargetFPS(144);

  while (!WindowShouldClose()) {

    if (CheckCollisionPointRec(GetMousePosition(), text_box)) {
      mouse_on_text = true;
    } else {
      mouse_on_text = false;
    }

    if (mouse_on_text) {
      SetMouseCursor(MOUSE_CURSOR_IBEAM);

      int key = GetCharPressed();
      printf("%c", key);
    } else {
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    BeginDrawing();

    ClearBackground(BLACK);
    DrawRectangleRec(text_box, GRAY);

    EndDrawing();
  }

  return 0;
}
