#include "../common.h"
typedef struct { char c[8]; } V8_16C098;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28, w32, w36, w40, w44; char m48[8]; V8_16C098 v56; } O_16C098;
extern V8_16C098 D_004A2F30[]; extern char D_00343028[];
int minigame_001644a0(void *); void rsound_0010c2b0(char *, int, int, int, int, int, int);
// MATCH func_0016C098
O_16C098 *pachislot_0016c098(O_16C098 *o, int a) { o->w44 = 0; o->w40 = a; minigame_001644a0(o->m48); o->v56 = D_004A2F30[0]; o->w0 = 200; o->w4 = -24; o->w32 = 128; o->w8 = 440; o->w12 = -24; o->w16 = 3; o->w20 = 10; o->w24 = 0; o->w28 = 0; o->w36 = 128; rsound_0010c2b0(D_00343028, 139, 6, 0, 13, 0, 0); return o; }
