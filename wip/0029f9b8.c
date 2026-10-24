// cflags: -fno-schedule-insns
#include "../src/common.h"
extern float D_004A0D7C, D_004A0D80, D_004A0D84;
typedef struct { char pad[104]; float a, b, c, d; } S_29f9b8;
// 8 words differ
// WIP func_0029F9B8
void clas_min_0029f9b8(S_29f9b8 *s, float x) { float v0 = x * D_004A0D7C; float v1 = x * D_004A0D80; float v2 = x * 0.0f; float v3 = x * D_004A0D84; s->b = v0; s->a = v1; s->c = v2; s->d = v3; }
