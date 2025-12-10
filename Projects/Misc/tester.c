#include<stdio.h>

void f(int *p) {
  int b = 2;
  p = &b;
  printf("%d ", *p);
}

int main() {
  int a = 1;
  int *p = &a;
  f(p);
  printf("%d ", *p);
}
