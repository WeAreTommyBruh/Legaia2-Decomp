#include "../common.h"
extern char D_00454010[];
void rouge_00133528(void *, char *, int);
typedef struct { int w0, w4, w8, w12; void *p16; float f20, f24; int w28, w32, w36, w40, w44, w48, w52; char c56, c57, c58, c59; int w60, w64; float f68, f72; } O_201C;
// MATCH func_00201C48
void sprite_00201c48(O_201C *o) { if (o->p16 != 0) rouge_00133528(o->p16, D_00454010, 64); o->p16 = 0; o->w12 = 0; o->f20 = 1.0f; o->f24 = 1.0f; o->w28 = 0; o->w32 = 0; o->w4 = 0; o->w8 = 0; o->w44 = 0; o->w48 = 0; o->w52 = 0; o->c56 = 127; o->c57 = 127; o->c58 = 127; o->w60 = 0; o->w64 = 0; o->c59 = 127; o->f68 = 1.0f; o->f72 = 1.0f; o->w0 = 0; }