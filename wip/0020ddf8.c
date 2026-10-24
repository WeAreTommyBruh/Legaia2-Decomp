#include "../src/common.h"
typedef struct { char p[96]; float f96; } R; typedef struct { char p[476]; R *w476; } Q; extern volatile int D_004A1444, D_004A140C; extern int D_004A45E8; extern float D_004A46D0, D_004A46D4; Q *func_0020BBD8(int); int func_0029F9B8(R *, float);
// 2 words differ
// WIP func_0020DDF8
void pchevent_0020ddf8(int on) { Q *p = func_0020BBD8(D_004A45E8); if (on) { if (D_004A1444 == 0 && (D_004A140C & 0xc) && p != 0 && p->w476 != 0) { func_0029F9B8(p->w476, D_004A46D0); p->w476->f96 = D_004A46D4; } } }
