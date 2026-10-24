#include "../src/common.h"
typedef struct { volatile unsigned w0; int w4; int w8; } Ch;
Ch *func_002CFF20(int);
// 9 words differ
// WIP func_002D4768
int FUN_002d4768(unsigned ch, int idx, int mode) { int r = -1; if (ch < 48 && idx >= 0 && idx < 16) { Ch *p = func_002CFF20(ch); p->w0 |= 0x2000; if ((p->w0 & 1) && mode == 0) { unsigned v = *(unsigned char *)(p->w8 + idx * 16 + 18); if (v != 0xff) r = v; } p->w0 &= ~0x2000; } return r; }
