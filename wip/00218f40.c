// cflags: -O1
#include "../src/common.h"
typedef struct { char p[48]; int w48, w52, w56, w60, w64, w68; short h72; } S; typedef struct { char p[72]; int w72; int w76; int w80, w84, w88, w92, w96; } D;
// 10 words differ
// WIP func_00218F40
void FUN_00218f40(D *d, S *s) { d->w88 = s->w60; d->w84 = s->w56; d->w80 = s->w48; d->w96 = s->w52; d->w92 = s->w64; d->w72 = s->w68; d->w76 = s->h72; }
