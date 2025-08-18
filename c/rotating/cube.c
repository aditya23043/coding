#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float A, B, C;

float cubeWidth = 10;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundAsciiCode = ' ';
float incrementSpeed = 0.6;
int distanceFromCamera = 60;
float k1 = 40;

float x, y, z;
float recip_z;
int xp, yp;
int idx;

/* ROTATION MATRIX: https://en.wikipedia.org/wiki/Rotation_matrix */

float calculateX(int i, int j, int k) {
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float calculateY(int i, int j, int k) {
  return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
         j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
         i * cos(B) * sin(C);
}

float calculateZ(int i, int j, int k) {
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculate_for_surface(float cubeX, float cubeY, float cubeZ, char ch) {
  x = calculateX(cubeX, cubeY, cubeZ);
  y = calculateY(cubeX, cubeY, cubeZ);
  z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCamera;

  recip_z = (1 / z);
  xp = (int)(width / 2 + k1 * recip_z * x * 2);
  yp = (int)(height / 2 + k1 * recip_z * y);

  idx = xp + yp * width;
  if (idx >= 0 && idx < width * height) {
    if (recip_z > zBuffer[idx]) {
      zBuffer[idx] = recip_z;
      buffer[idx] = ch;
    }
  }
}

int main(int argc, char **argv) {

  printf("\x1b[2J");
  while (1) {
    memset(buffer, backgroundAsciiCode, width * height);
    memset(zBuffer, 0, width * height);
    for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
      for (float cubeY = -cubeWidth; cubeY < cubeWidth;
           cubeY += incrementSpeed) {
        calculate_for_surface(cubeX, cubeY, -cubeWidth, '#');
      }
    }
    printf("\x1b[H");
    for (int k = 0; k < width * height; k++) {
      putchar(k % width ? buffer[k] : 10);
    }

    A += 0.05;
    B += 0.05;

    usleep(1000);
  }

  return 0;
}
