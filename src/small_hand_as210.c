/* Small functions matched by hand. */
// compiler: 991111-01-as210
#include "common.h"

typedef struct { char c[8]; } V8_00175E80;
typedef struct { char p[408]; V8_00175E80 v; } O_00175E80;
extern V8_00175E80 D_00336530[];
// MATCH func_00175E80
void repetition_00175e80(O_00175E80 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336530[i]; }

typedef struct { char c[8]; } V8_00178700;
typedef struct { char p[476]; V8_00178700 v; } O_00178700;
extern V8_00178700 D_00336738[];
// MATCH func_00178700
void shuffle_00178700(O_00178700 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336738[i]; }

typedef struct { char c[8]; } V8_0016E4E0;
typedef struct { char p[104]; V8_0016E4E0 v; } O_0016E4E0;
extern V8_0016E4E0 D_00334E70[];
// MATCH func_0016E4E0
void darts_0016e4e0(O_0016E4E0 *o, unsigned i) { if (i >= 8) i = 0; o->v = D_00334E70[i]; }

typedef struct { char c[8]; } V8_00170910;
typedef struct { char p[136]; V8_00170910 v; } O_00170910;
extern V8_00170910 D_00335628[];
// MATCH func_00170910
void roulette_00170910(O_00170910 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_00335628[i]; }

typedef struct { char c[8]; } V8_00171980;
typedef struct { char p[44]; V8_00171980 v; } O_00171980;
extern V8_00171980 D_00335690[];
// MATCH func_00171980
void roulette_00171980(O_00171980 *o, unsigned i) { if (i >= 5) i = 0; o->v = D_00335690[i]; }

typedef struct { char c[8]; } V8_0025F778;
typedef struct { char p[412]; V8_0025F778 v; } O_0025F778;
extern V8_0025F778 D_00402450[];
// MATCH func_0025F778
void abeshi_0025f778(O_0025F778 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00402450[i]; }

typedef struct { char c[8]; } V8_00294D98;
typedef struct { char p[76]; V8_00294D98 v; } O_00294D98;
extern V8_00294D98 D_0041EF28[];
// MATCH func_00294D98
void battleslot_00294d98(O_00294D98 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_0041EF28[i]; }

typedef struct { char c[8]; } V8_00164990;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28, w32, w36; V8_00164990 v; } O_00164990;
extern V8_00164990 D_004A2CD0[];
// MATCH func_00164990
void pachislot_00164990(O_00164990 *o) { o->w32 = -1; o->w12 = 0; o->w20 = 0; o->w24 = 0; o->w8 = 0; o->v = D_004A2CD0[0]; }

typedef struct { char c[8]; } V8_001649E0;
typedef struct { char p[40]; V8_001649E0 v; } O_001649E0;
extern V8_001649E0 D_004A2CD8[];
// MATCH func_001649E0
void pachislot_001649e0(O_001649E0 *o) { o->v = D_004A2CD8[0]; }

typedef struct { char c[16]; } V16_0012AF88;
typedef struct { char p[48]; V16_0012AF88 v; } O_0012AF88;
// MATCH func_0012AF88
void battle_0012af88(O_0012AF88 *o, V16_0012AF88 *s) { o->v = *s; }

typedef struct { char c[16]; } V16_001DFEA0;
typedef struct { char p[128]; V16_001DFEA0 v; } O_001DFEA0;
// MATCH func_001DFEA0
void mizuki_001dfea0(O_001DFEA0 *o, V16_001DFEA0 *s) { o->v = *s; }

typedef struct { char c[16]; } V16_0012C918;
typedef struct { char p[128]; V16_0012C918 v; } O_0012C918;
extern O_0012C918 *D_003279A0[]; extern V16_0012C918 D_0055B3B0;
// MATCH func_0012C918
void battle_0012c918(int i) { D_0055B3B0 = D_003279A0[i]->v; }

typedef struct { char c[8]; } V8_0025E4D8;
typedef struct { int w0, w4, w8, w12, w16; char p[16]; V8_0025E4D8 v; } O_0025E4D8;
extern V8_0025E4D8 D_004A59B0[];
// MATCH func_0025E4D8
void FUN_0025e4d8(O_0025E4D8 *o, int x) { o->w8 = x; o->w16 = 0; o->v = D_004A59B0[0]; }
