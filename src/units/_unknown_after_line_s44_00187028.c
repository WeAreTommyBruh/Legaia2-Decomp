// cflags: -fno-schedule-insns2
#include "../common.h"
extern float D_004A015C; extern char D_00337B80[]; void func_002287F0(char *, char *, int);
typedef struct { int w0; float f4; float w8; float f12; } V16_7028;
// MATCH func_00187028
void FUN_00187028(char *o) { V16_7028 *b = (V16_7028 *)(o + 288); float d = D_004A015C; *(float *)(o + 288) = 0; b->f12 = 1.0f; b->f4 = d; *(float *)(o + 2100) = 0; *(float *)(o + 2092) = 0; b->w8 = 0; func_002287F0(o, D_00337B80, 40); }
