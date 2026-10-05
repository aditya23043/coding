#define KEY 'X'
#define CLEARTEXT 'A'

#include <stdio.h>

void printc(char c, char *text);

int main(int argc, char *argv[]) {

  char cleartext, ciphertext, key, newcleartext;

  cleartext = CLEARTEXT;
  printc(cleartext, "cleartext");

  key = KEY;
  printc(key, "key");

  ciphertext = cleartext ^ key; // XOR
  printc(ciphertext, "ciphertext");

  newcleartext = ciphertext ^ key; // XOR
  printc(newcleartext, "newcleartext");

  return 0;
}

void printc(char c, char *text) { printf("%s = '%c' (0x%x)\n", text, c, c); }
