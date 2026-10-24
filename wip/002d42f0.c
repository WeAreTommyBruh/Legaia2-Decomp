#include "../src/common.h"
typedef struct { volatile unsigned w0; char p[20]; unsigned short h24; } Ch;
typedef struct { char p[8]; int w8; } Q;
Ch *func_002CFF20(int); Q *func_002CFF48(int);
// 8 words differ
// WIP func_002D42F0
void FUN_002d42f0(unsigned ch) { if (ch < 48) { Ch *p = func_002CFF20(ch); p->w0 |= 0x2000; if ((unsigned)(p->h24 - 1) < 127 && (p->w0 & 1)) { if (func_002CFF48(p->h24)->w8 != 0) { p->w0 |= 2; p->w0 &= ~0x70; } } p->w0 &= ~0x2000; } }
