#include<stdio.h>
#include<string.h>

//derived from the equation, scaled to fit integer values
//http://mathworld.wolfram.com/HeartCurve.html
//(x^2 + y^2 - 1)^3 - x^2 y^3 = 0
  
#define SQUARE(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))

static void render(const char *msg) {
  int len = strlen(msg);
  for (int y = 14; y > -14; y--) {
    char buf[64] = {0};
    char *ptr = buf;
    for (int x = -25; x < 25; x++) {
      double val = CUBE(SQUARE(0.05 * x) + SQUARE(0.1 * y) - 1) - (SQUARE(0.05 * x) * CUBE(0.1 * y));
      *ptr++ = val <= 0 ? msg[(x - 1) % len < 0 ? (x - 1) % len + len : (x - 1) % len] : '.';
    }
    printf("%s\n", buf);
  }
}

int main() {
  render("HelloWorld");
  return 0;
}
