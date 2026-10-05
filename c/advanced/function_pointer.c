#include <stdio.h>
#include <stdbool.h>

int sum(int a, int b){
  return a+b;
}

void something(int a[10], bool (*predicate)(int)){
  for(int i = 0; i < 10; i++){
    if(predicate(a[i])){
      printf("%d\n", a[i]);
    }
  } 
}

bool even(int a){
  if(a % 2 == 0){
    return true;
  }

  return false;
}

int main(int argc, char *argv[])
{

  int (*fp)(int, int) = sum;
  printf("%d\n", fp(5,5));

  int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
  something(a, even);

  return 0;
}
