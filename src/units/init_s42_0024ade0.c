// compiler: 990721
#include "../common.h"
// MATCH func_0024ADE0
void init_0024ade0(char *dst, char *src, int w, int h) { int x, y; for (y = 0; y < h; y += 2) { x = 0; if (x < w) { char *p = src + y * w; do { dst[(y / 2) * w / 2 + x / 2] = *p; p += 2; x += 2; } while (x < w); } } }
