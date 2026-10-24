#include "../src/common.h"
typedef struct { char pad[224]; float a224, a228, a232, a236, a240, a244, a248; int pad2; int a256; } S_1d8368;
// 12 words differ
// WIP func_001D8368
void nayuki_001d8368(S_1d8368 *s, float x) { if (x > -1.0f) { s->a228 = x; s->a236 = 0.0f; s->a232 = x; s->a244 = 0.0f; s->a240 = 0.0f; s->a248 = 0.0f; s->a224 = x; s->a256 = 1; } }
