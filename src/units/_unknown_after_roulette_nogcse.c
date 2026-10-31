/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char c[8]; } V8_00173008;
extern V8_00173008 D_004A3170[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173008_00173008;
typedef struct { char p[200]; float f200; } T2_173008_00173008;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173008_00173008 *w112; char p2[8]; int w124; char p3[188]; V8_00173008 v316; char p4[8]; VT_173008_00173008 *vt; } O_173008_00173008;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_00173008
int FUN_00173008(O_173008_00173008 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 2; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3170[0]; } return 0; }

typedef struct { char c[8]; } V8_001730F8;
extern V8_001730F8 D_004A3178[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_1730f8_001730F8;
typedef struct { char p[200]; float f200; } T2_1730f8_001730F8;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_1730f8_001730F8 *w112; char p2[8]; int w124; char p3[188]; V8_001730F8 v316; char p4[8]; VT_1730f8_001730F8 *vt; } O_1730f8_001730F8;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_001730F8
int FUN_001730f8(O_1730f8_001730F8 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 1; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3178[0]; } return 0; }

typedef struct { char c[8]; } V8_00172EB8;
extern V8_00172EB8 D_004A3160[3]; extern V8_00172EB8 D_004A3168[3];
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_172eb8_00172EB8;
typedef struct { char p[200]; float f200; } T2_172eb8_00172EB8;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_172eb8_00172EB8 *w112; char p2[8]; int w124; char p3[188]; V8_00172EB8 v316; char p4[8]; VT_172eb8_00172EB8 *vt; } O_172eb8_00172EB8;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int);
// MATCH func_00172EB8
int FUN_00172eb8(O_172eb8_00172EB8 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w88 == 1) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3160[0]; } else if (o->w88 == 2) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3168[0]; } } return 0; }

typedef struct { char c[8]; } V8_00173E20;
extern V8_00173E20 D_004A3170_00173E20[3] __asm__("D_004A3170");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173e20_00173E20;
typedef struct { char p[200]; float f200; } T2_173e20_00173E20;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173e20_00173E20 *w112; char p2[8]; int w124; char p3[188]; V8_00173E20 v316; char p4[8]; VT_173e20_00173E20 *vt; char p5[8]; int w344; int w348; int w352; } O_173e20_00173E20;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173E20
int FUN_00173e20(O_173e20_00173E20 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 2; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3170_00173E20[0]; } return 0; }

typedef struct { char c[8]; } V8_00173F38;
extern V8_00173F38 D_004A3178_00173F38[3] __asm__("D_004A3178");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173f38_00173F38;
typedef struct { char p[200]; float f200; } T2_173f38_00173F38;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173f38_00173F38 *w112; char p2[8]; int w124; char p3[188]; V8_00173F38 v316; char p4[8]; VT_173f38_00173F38 *vt; char p5[8]; int w344; int w348; int w352; } O_173f38_00173F38;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173F38
int FUN_00173f38(O_173f38_00173F38 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->w88 = 1; o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3178_00173F38[0]; } return 0; }

typedef struct { char c[8]; } V8_00173CA0;
extern V8_00173CA0 D_004A3160_00173CA0[3] __asm__("D_004A3160"); extern V8_00173CA0 D_004A3168_00173CA0[3] __asm__("D_004A3168");
typedef struct { char p[32]; short adj32; short pad32; void (*fn36)(void *); char p2[16]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173ca0_00173CA0;
typedef struct { char p[200]; float f200; } T2_173ca0_00173CA0;
typedef struct { char p0[88]; int w88; int w92; char p1[4]; float f100; float f104; int w108; T2_173ca0_00173CA0 *w112; char p2[8]; int w124; char p3[188]; V8_00173CA0 v316; char p4[8]; VT_173ca0_00173CA0 *vt; char p5[8]; int w344; int w348; int w352; } O_173ca0_00173CA0;
void func_00172C00(void *, int); void func_00172E40(void *); void func_00172BE8(void *, int); void func_00173BE0(void *);
// MATCH func_00173CA0
int FUN_00173ca0(O_173ca0_00173CA0 *o) { o->vt->fn60((char *)o + o->vt->adj56, 1); func_00172C00(o, 4); o->vt->fn36((char *)o + o->vt->adj32); o->w108 = 0; if (o->w92 == 0) { o->w112->f200 = 1.0f; if (o->w124 != 0) { func_00172E40(o); return 0; } } if (o->w92 > 0) { if (o->w344 != 0 && o->w352 != o->w348) { func_00173BE0(o); return 0; } if (o->w88 == 1) { o->vt->fn60((char *)o + o->vt->adj56, 2); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3160_00173CA0[0]; } else if (o->w88 == 2) { o->vt->fn60((char *)o + o->vt->adj56, 3); func_00172BE8(o, 516); o->f100 = o->f104; o->w112->f200 = o->f104; o->v316 = D_004A3168_00173CA0[0]; } } return 0; }
