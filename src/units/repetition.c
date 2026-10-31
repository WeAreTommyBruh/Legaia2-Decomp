/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char c[8]; } V8_00174B18; typedef struct { char p[416]; V8_00174B18 v; } O_00174B18; extern V8_00174B18 D_004A31F8[2]; void func_00172B30(void *); void func_00174AB8(void *);
// MATCH func_00174B18
int repetition_00174b18(O_00174B18 *o) { func_00172B30(o); func_00174AB8(o); o->v = D_004A31F8[0]; return 0; }

void func_00172B30(void *); void func_00172C48(void *);
// MATCH func_001769C0
void repetition_001769c0(char *o) { func_00172B30(o); o += 912; func_00172B30(o); func_00172C48(o); }

typedef struct { char c[8]; } V8_001743C0;
typedef struct { char p[372]; int w; char p2[32]; V8_001743C0 a; V8_001743C0 b; } O_001743C0;
// MATCH func_001743C0
int repetition_001743c0(O_001743C0 *o) { o->w = o->w - 1; if (o->w <= 0) { o->w = 0; o->a = o->b; } return 0; }

extern long long D_004A12D8_00175ED8 __asm__("D_004A12D8"); typedef struct { char p[348]; int w; char p2[16]; short h; } O_00175ED8; int func_00172CC8(void *);
// MATCH func_00175ED8
int repetition_00175ed8(O_00175ED8 *o) { if (func_00172CC8(o) != 0 && (D_004A12D8_00175ED8 & 0x100010)) { o->w = 0; o->h = -2; } return o->h != -1; }

typedef struct { char pad[80]; short adj; short p2; void (*fn)(void *); } VT_1760f8_001760F8;
typedef struct { char pad[896]; VT_1760f8_001760F8 *vt; } O_1760f8_001760F8;
extern O_1760f8_001760F8 *D_004A6F50;
// MATCH func_001760F8
void repetition_001760f8(void) { O_1760f8_001760F8 *o = D_004A6F50; o->vt->fn((char *)o + o->vt->adj); }

typedef struct { char pad[376]; char sub[1]; char pad1[7]; int a384; int a388; char pad2[504]; char *a896; } S_00174300;
extern char D_0043DF80[], D_0043D818[], D_00343010[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_001E3F20(void *, int); void func_00164500(void *, int); void func_00172A60(void *, int); void func_00108B80_00174300(void *) __asm__("func_00108B80");
// MATCH func_00174300
void repetition_00174300(S_00174300 *s, int fl) { s->a896 = D_0043DF80; func_002971C0(18, 50); func_001621F8(s->a384, D_0043D818, 1251); func_001E3F20(D_00343010, s->a388); func_00164500(s->sub, 2); func_00172A60(s, 2); if (fl & 1) func_00108B80_00174300(s); }

typedef struct { char c[8]; } V8_174460_00174460;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_174460_00174460;
typedef struct { char p[408]; V8_174460_00174460 d; V8_174460_00174460 s; char p2[472]; VT_174460_00174460 *vt; } O_174460_00174460;
// MATCH func_00174460
int repetition_00174460(O_174460_00174460 *o) { if (o->vt->fn((char *)o + o->vt->adj)) o->d = o->s; return 0; }

typedef struct { char c[8]; } V8_174558_00174558;
typedef struct { char p[72]; short adj; short pad; void (*fn)(void *); } VT_174558_00174558;
typedef struct { char p[368]; short w; char p2[38]; V8_174558_00174558 b; char p3[472]; V8_174558_00174558 a; VT_174558_00174558 *vt; } O_174558_00174558;
extern V8_174558_00174558 D_004A31A8[2], D_004A31B0[2];
// MATCH func_00174558
int repetition_00174558(O_174558_00174558 *o) { o->w = 0; o->vt->fn((char *)o + o->vt->adj); o->a = D_004A31A8[0]; o->b = D_004A31B0[0]; return 0; }

typedef struct { char c[8]; } V8_00174BF0;
typedef struct { char p[340]; int w340; char q[64]; V8_00174BF0 v; } O_00174BF0;
extern unsigned long long D_004A12D8_00174BF0 __asm__("D_004A12D8"); extern char D_00336450[]; extern V8_00174BF0 D_004A3208[2];
void func_001749D8(O_00174BF0 *, char *); void func_00172C48_00174BF0(O_00174BF0 *) __asm__("func_00172C48");
// MATCH func_00174BF0
int repetition_00174bf0(O_00174BF0 *o) { func_001749D8(o, D_00336450); func_00172C48_00174BF0(o); o->w340 = 2; if (D_004A12D8_00174BF0 & 0x200040) o->v = D_004A3208[0]; return 0; }

typedef struct { char c[8]; } V8_00174EC8;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00174EC8 v; } O_00174EC8;
extern unsigned long long D_004A12D8_00174EC8 __asm__("D_004A12D8");
extern char D_00336478[]; extern V8_00174EC8 D_004A3230[2]; void func_001749D8_00174EC8(O_00174EC8 *, char *) __asm__("func_001749D8"); void func_00172C58(O_00174EC8 *);
// MATCH func_00174EC8
int repetition_00174ec8(O_00174EC8 *o) { func_001749D8_00174EC8(o, D_00336478); func_00172C58(o);  if (D_004A12D8_00174EC8 & 0x200040) { o->v = D_004A3230[0];  } return 0; }

typedef struct { char c[8]; } V8_00175190;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175190 v; } O_00175190;
extern unsigned long long D_004A12D8_00175190 __asm__("D_004A12D8");
extern char D_003364A0[]; extern V8_00175190 D_004A3258[2]; void func_001749D8_00175190(O_00175190 *, char *) __asm__("func_001749D8"); void func_00172C48_00175190(O_00175190 *) __asm__("func_00172C48");
// MATCH func_00175190
int repetition_00175190(O_00175190 *o) { func_001749D8_00175190(o, D_003364A0); func_00172C48_00175190(o); o->w344 = 1; if (D_004A12D8_00175190 & 0x200040) { o->v = D_004A3258[0];  } return 0; }

typedef struct { char c[8]; } V8_00175640;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175640 v; } O_00175640;
extern unsigned long long D_004A12D8_00175640 __asm__("D_004A12D8");
extern char D_003364D8[]; extern V8_00175640 D_004A3290[2]; void func_001749D8_00175640(O_00175640 *, char *) __asm__("func_001749D8"); void func_00172C58_00175640(O_00175640 *) __asm__("func_00172C58");
// MATCH func_00175640
int repetition_00175640(O_00175640 *o) { func_001749D8_00175640(o, D_003364D8); func_00172C58_00175640(o);  if (D_004A12D8_00175640 & 0x200040) { o->v = D_004A3290[0];  } return 0; }

typedef struct { char c[8]; } V8_00175A98;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175A98 v; } O_00175A98;
extern unsigned long long D_004A12D8_00175A98 __asm__("D_004A12D8");
extern char D_00336510[]; extern V8_00175A98 D_004A32C8[2]; void func_001749D8_00175A98(O_00175A98 *, char *) __asm__("func_001749D8"); 
// MATCH func_00175A98
int repetition_00175a98(O_00175A98 *o) { func_001749D8_00175A98(o, D_00336510);  if (D_004A12D8_00175A98 & 0x200040) { o->v = D_004A32C8[0]; o->w372 = 0; } return 0; }

typedef struct { char c[8]; } V8_00174C60;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174C60 v; } O_00174C60;
extern unsigned long long D_004A12D8_00174C60 __asm__("D_004A12D8");
extern char D_00336458[]; extern V8_00174C60 D_004A3210[2]; void func_001749D8_00174C60(O_00174C60 *, char *) __asm__("func_001749D8");
// MATCH func_00174C60
int repetition_00174c60(O_00174C60 *o) { func_001749D8_00174C60(o, D_00336458); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (D_004A12D8_00174C60 & 0x200040) o->v = D_004A3210[0]; return 0; }

typedef struct { char c[8]; } V8_00174CF0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174CF0 v; } O_00174CF0;
extern unsigned long long D_004A12D8_00174CF0 __asm__("D_004A12D8");
extern char D_00336460[]; extern V8_00174CF0 D_004A3218[2]; void func_001749D8_00174CF0(O_00174CF0 *, char *) __asm__("func_001749D8");
// MATCH func_00174CF0
int repetition_00174cf0(O_00174CF0 *o) { func_001749D8_00174CF0(o, D_00336460); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; if (D_004A12D8_00174CF0 & 0x200040) o->v = D_004A3218[0]; return 0; }

typedef struct { char c[8]; } V8_00174D80;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174D80 v; } O_00174D80;
extern unsigned long long D_004A12D8_00174D80 __asm__("D_004A12D8");
extern char D_00336468[]; extern V8_00174D80 D_004A3220[2]; void func_001749D8_00174D80(O_00174D80 *, char *) __asm__("func_001749D8");
// MATCH func_00174D80
int repetition_00174d80(O_00174D80 *o) { func_001749D8_00174D80(o, D_00336468); o->w356 = 2; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 16; else o->w352 = 17; if (D_004A12D8_00174D80 & 0x200040) o->v = D_004A3220[0]; return 0; }

typedef struct { char c[8]; } V8_00174F30;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174F30 v; } O_00174F30;
extern unsigned long long D_004A12D8_00174F30 __asm__("D_004A12D8");
extern char D_00336480[]; extern V8_00174F30 D_004A3238[2]; void func_001749D8_00174F30(O_00174F30 *, char *) __asm__("func_001749D8");
// MATCH func_00174F30
int repetition_00174f30(O_00174F30 *o) { func_001749D8_00174F30(o, D_00336480); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (D_004A12D8_00174F30 & 0x200040) o->v = D_004A3238[0]; return 0; }

typedef struct { char c[8]; } V8_00174FC0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174FC0 v; } O_00174FC0;
extern unsigned long long D_004A12D8_00174FC0 __asm__("D_004A12D8");
extern char D_00336488[]; extern V8_00174FC0 D_004A3240[2]; void func_001749D8_00174FC0(O_00174FC0 *, char *) __asm__("func_001749D8");
// MATCH func_00174FC0
int repetition_00174fc0(O_00174FC0 *o) { func_001749D8_00174FC0(o, D_00336488); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (D_004A12D8_00174FC0 & 0x200040) o->v = D_004A3240[0]; return 0; }

typedef struct { char c[8]; } V8_00175048;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175048 v; } O_00175048;
extern unsigned long long D_004A12D8_00175048 __asm__("D_004A12D8");
extern char D_00336490[]; extern V8_00175048 D_004A3248[2]; void func_001749D8_00175048(O_00175048 *, char *) __asm__("func_001749D8");
// MATCH func_00175048
int repetition_00175048(O_00175048 *o) { func_001749D8_00175048(o, D_00336490); o->w356 = 0; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 64; else o->w352 = 66; if (D_004A12D8_00175048 & 0x200040) o->v = D_004A3248[0]; return 0; }

typedef struct { char c[8]; } V8_00175200;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175200 v; } O_00175200;
extern unsigned long long D_004A12D8_00175200 __asm__("D_004A12D8");
extern char D_003364A8[]; extern V8_00175200 D_004A3260[2]; void func_001749D8_00175200(O_00175200 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175200
int repetition_00175200(O_00175200 *o) { func_001749D8_00175200(o, D_003364A8); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (func_00172958() == 4 && func_00172978() == 2) o->v = D_004A3260[0]; return 0; }

typedef struct { char c[8]; } V8_00175370;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175370 v; } O_00175370;
extern unsigned long long D_004A12D8_00175370 __asm__("D_004A12D8");
extern char D_003364B8[]; extern V8_00175370 D_004A3260_00175370[2] __asm__("D_004A3260"); void func_001749D8_00175370(O_00175370 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175370
int repetition_00175370(O_00175370 *o) { func_001749D8_00175370(o, D_003364B8); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (func_00172958() == 4 && func_00172978() == 2) o->v = D_004A3260_00175370[0]; return 0; }

typedef struct { char c[8]; } V8_001754D8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001754D8 v; } O_001754D8;
extern unsigned long long D_004A12D8_001754D8 __asm__("D_004A12D8");
extern char D_003364C8[]; extern V8_001754D8 D_004A3270[2]; void func_001749D8_001754D8(O_001754D8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001754D8
int repetition_001754d8(O_001754D8 *o) { func_001749D8_001754D8(o, D_003364C8); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; { int r = func_00172958(); if (r == 4 && func_00172978() == r) o->v = D_004A3270[0]; } return 0; }

typedef struct { char c[8]; } V8_001756A8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001756A8 v; } O_001756A8;
extern unsigned long long D_004A12D8_001756A8 __asm__("D_004A12D8");
extern char D_003364E0[]; extern V8_001756A8 D_004A3298[2]; void func_001749D8_001756A8(O_001756A8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001756A8
int repetition_001756a8(O_001756A8 *o) { func_001749D8_001756A8(o, D_003364E0); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (func_00172958() == 2 && func_00172978() == 0) o->v = D_004A3298[0]; return 0; }

typedef struct { char c[8]; } V8_001757F0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001757F0 v; } O_001757F0;
extern unsigned long long D_004A12D8_001757F0 __asm__("D_004A12D8");
extern char D_003364F0[]; extern V8_001757F0 D_004A3298_001757F0[2] __asm__("D_004A3298"); void func_001749D8_001757F0(O_001757F0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001757F0
int repetition_001757f0(O_001757F0 *o) { func_001749D8_001757F0(o, D_003364F0); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (func_00172958() == 2 && func_00172978() == 0) o->v = D_004A3298_001757F0[0]; return 0; }

typedef struct { char c[8]; } V8_00175940;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175940 v; char pp[0]; } O_00175940;
extern unsigned long long D_004A12D8_00175940 __asm__("D_004A12D8");
extern char D_00336500[]; extern V8_00175940 D_004A32A8[2];  void func_001749D8_00175940(O_00175940 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175940
int repetition_00175940(O_00175940 *o) { func_001749D8_00175940(o, D_00336500); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (func_00172958() == 0 && func_00172978() == 0) o->v = D_004A32A8[0]; return 0; }

typedef struct { char c[8]; } V8_00175888;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175888 v; char pp[0]; } O_00175888;
extern unsigned long long D_004A12D8_00175888 __asm__("D_004A12D8");
extern char D_003364F8[]; extern V8_00175888 D_004A32B0[2]; extern V8_00175888 D_004A32B8[2];  void func_001749D8_00175888(O_00175888 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175888
int repetition_00175888(O_00175888 *o) { func_001749D8_00175888(o, D_003364F8); o->w356 = 0; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 64; else o->w352 = 66; if (func_00172958() != 0) o->v = D_004A32B0[0]; if (func_00172958() == 0 && func_00172978() == 2) o->v = D_004A32B8[0]; return 0; }

typedef struct { char c[8]; } V8_00175740;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175740 v; char pp[0]; } O_00175740;
extern unsigned long long D_004A12D8_00175740 __asm__("D_004A12D8");
extern char D_003364E8[]; extern V8_00175740 D_004A32A0[2]; extern V8_00175740 D_004A32A8_00175740[2] __asm__("D_004A32A8");  void func_001749D8_00175740(O_00175740 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175740
int repetition_00175740(O_00175740 *o) { func_001749D8_00175740(o, D_003364E8); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (func_00172978() != 0) o->v = D_004A32A0[0]; if (func_00172958() == 0 && func_00172978() == 0) o->v = D_004A32A8_00175740[0]; return 0; }

typedef struct { char c[8]; } V8_00174B60;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00174B60 v; char pp[0]; } O_00174B60;
extern unsigned long long D_004A12D8_00174B60 __asm__("D_004A12D8");
extern char D_00336448[]; extern V8_00174B60 D_004A3200[2];  void func_001749D8_00174B60(O_00174B60 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00174B60
int repetition_00174b60(O_00174B60 *o) { func_001749D8_00174B60(o, D_00336448); if (o->w372++ & 0x20) o->w336 = 0; else o->w336 = 1; if (D_004A12D8_00174B60 & 0x200040) { o->w336 = 0; o->w340 = 2; o->w344 = 0; o->v = D_004A3200[0]; } return 0; }

typedef struct { char c[8]; } V8_00174E10;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174E10 v, v2; } O_00174E10;
extern unsigned long long D_004A12D8_00174E10 __asm__("D_004A12D8");
extern char D_00336470[]; extern V8_00174E10 D_004A31C8[2]; extern V8_00174E10 D_004A3228[2];  void func_001749D8_00174E10(O_00174E10 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98(O_00174E10 *);
// MATCH func_00174E10
int repetition_00174e10(O_00174E10 *o) { func_001749D8_00174E10(o, D_00336470); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 256; else o->w352 = 258; if (D_004A12D8_00174E10 & 0x200040) { func_00172D98(o); o->v = D_004A31C8[0]; o->v2 = D_004A3228[0]; o->w352 = 0; } return 0; }

typedef struct { char c[8]; } V8_001750D8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001750D8 v, v2; } O_001750D8;
extern unsigned long long D_004A12D8_001750D8 __asm__("D_004A12D8");
extern char D_00336498[]; extern V8_001750D8 D_004A31C8_001750D8[2] __asm__("D_004A31C8"); extern V8_001750D8 D_004A3250[2];  void func_001749D8_001750D8(O_001750D8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001750D8(O_001750D8 *) __asm__("func_00172D98");
// MATCH func_001750D8
int repetition_001750d8(O_001750D8 *o) { func_001749D8_001750D8(o, D_00336498); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 4; else o->w352 = 5; if (D_004A12D8_001750D8 & 0x200040) { func_00172D98_001750D8(o); o->v = D_004A31C8_001750D8[0]; o->v2 = D_004A3250[0]; o->w352 = 0; } return 0; }

typedef struct { char c[8]; } V8_00175578;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175578 v, v2; } O_00175578;
extern unsigned long long D_004A12D8_00175578 __asm__("D_004A12D8");
extern char D_003364D0[]; extern V8_00175578 D_004A31C8_00175578[2] __asm__("D_004A31C8"); extern V8_00175578 D_004A3288[2];  void func_001749D8_00175578(O_00175578 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_00175578(O_00175578 *) __asm__("func_00172D98");
// MATCH func_00175578
int repetition_00175578(O_00175578 *o) { func_001749D8_00175578(o, D_003364D0); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 256; else o->w352 = 258; { int r = func_00172958(); if (r == 2 && func_00172978() == r) { func_00172D98_00175578(o); o->v = D_004A31C8_00175578[0]; o->v2 = D_004A3288[0]; o->w352 = 0; } } return 0; }

typedef struct { char c[8]; } V8_001759D0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001759D0 v, v2; } O_001759D0;
extern unsigned long long D_004A12D8_001759D0 __asm__("D_004A12D8");
extern char D_00336508[]; extern V8_001759D0 D_004A31C8_001759D0[2] __asm__("D_004A31C8"); extern V8_001759D0 D_004A32C0[2];  void func_001749D8_001759D0(O_001759D0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001759D0(O_001759D0 *) __asm__("func_00172D98");
// MATCH func_001759D0
int repetition_001759d0(O_001759D0 *o) { func_001749D8_001759D0(o, D_00336508); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 4; else o->w352 = 5; { int r = func_00172958(); if (r == 2 && func_00172978() == r) { func_00172D98_001759D0(o); o->v = D_004A31C8_001759D0[0]; o->v2 = D_004A32C0[0]; o->w352 = 0; } } return 0; }

typedef struct { char c[8]; } V8_001752A0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001752A0 v, v2; } O_001752A0;
extern unsigned long long D_004A12D8_001752A0 __asm__("D_004A12D8");
extern char D_003364B0[]; extern V8_001752A0 D_004A3268[2]; extern V8_001752A0 D_004A3270_001752A0[2] __asm__("D_004A3270");  void func_001749D8_001752A0(O_001752A0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001752A0(O_001752A0 *) __asm__("func_00172D98");
// MATCH func_001752A0
int repetition_001752a0(O_001752A0 *o) { func_001749D8_001752A0(o, D_003364B0); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; if (func_00172958() != 4) o->v = D_004A3268[0]; { int r = func_00172958(); if (r == 4 && func_00172978() == r) o->v = D_004A3270_001752A0[0]; } return 0; }

typedef struct { char c[8]; } V8_00175410;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175410 v, v2; } O_00175410;
extern unsigned long long D_004A12D8_00175410 __asm__("D_004A12D8");
extern char D_003364C0[]; extern V8_00175410 D_004A3278[2]; extern V8_00175410 D_004A3280[2];  void func_001749D8_00175410(O_00175410 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_00175410(O_00175410 *) __asm__("func_00172D98");
// MATCH func_00175410
int repetition_00175410(O_00175410 *o) { func_001749D8_00175410(o, D_003364C0); o->w356 = 2; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 16; else o->w352 = 17; if (func_00172978() != 4) o->v = D_004A3278[0]; if (func_00172958() == 2 && func_00172978() == 4) o->v = D_004A3280[0]; return 0; }

typedef struct { char c[8]; } V8_001743F0;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_001743F0;
typedef struct { char p[408]; V8_001743F0 v, v2; char q[456]; float f880, f884; char r[8]; VT_001743F0 *vt; } O_001743F0;
extern char D_0041EFB0_001743F0[] __asm__("D_0041EFB0"); void func_001545A8(char *, char *, char *, float);
// MATCH func_001743F0
int repetition_001743f0(O_001743F0 *o) { o->f880 += o->f884; if (o->f880 >= 1.0f) { o->f880 = 1.0f; o->v = o->v2; } func_001545A8(D_0041EFB0_001743F0, (char *)o + 432, (char *)o + 656, o->f880); return 0; }

typedef struct { char c[8]; } V8_001744B0;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_001744B0;
typedef struct { char p[408]; V8_001744B0 v, v2; char q[456]; float f880, f884; char r[8]; VT_001744B0 *vt; } O_001744B0;
extern char D_0041EFB0_001744B0[] __asm__("D_0041EFB0"); void func_001545A8(char *, char *, char *, float);
// MATCH func_001744B0
int repetition_001744b0(O_001744B0 *o) { o->f880 += o->f884; if (o->f880 >= 1.0f) o->f880 = 1.0f; if (o->f880 == 1.0f) { if (o->vt->fn((char *)o + o->vt->adj)) o->v = o->v2; } func_001545A8(D_0041EFB0_001744B0, (char *)o + 432, (char *)o + 656, o->f880); return 0; }

typedef struct { char c[8]; } V8_00175C48;
typedef struct { char p[340]; int w340, w344, w348; char p2[56]; V8_00175C48 v; V8_00175C48 v2; char q[464]; V8_00175C48 v3; } O_00175C48;
extern unsigned long long D_004A12D8_00175C48 __asm__("D_004A12D8"); extern char D_00336520[]; extern V8_00175C48 D_004A32D8[2], D_004A31C8_00175C48[2] __asm__("D_004A31C8"), D_004A32E0[2]; void func_001749D8_00175C48(O_00175C48 *, char *) __asm__("func_001749D8"); void func_00172C30(O_00175C48 *); void func_00172CA0(O_00175C48 *);
// MATCH func_00175C48
int repetition_00175c48(O_00175C48 *o) { func_001749D8_00175C48(o, D_00336520); if (D_004A12D8_00175C48 & 0x200040) { o->w348 = 1; o->w340 = 0; o->w344 = 0; func_00172C30(o); func_00172CA0(o); o->v3 = D_004A32D8[0]; o->v = D_004A31C8_00175C48[0]; o->v2 = D_004A32E0[0]; } return 0; }

typedef struct { char c[8]; } V8_00174780;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00174780;
typedef struct { char p[408]; V8_00174780 v; char q[480]; VT_00174780 *vt; } O_00174780;
extern V8_00174780 D_004A31C8_00174780[2] __asm__("D_004A31C8"); extern char D_00343028_00174780[] __asm__("D_00343028"); void func_00172CA0_00174780(O_00174780 *) __asm__("func_00172CA0"); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00174780
int repetition_00174780(O_00174780 *o) { func_00172CA0_00174780(o); o->v = D_004A31C8_00174780[0]; o->vt->fn((char *)o + o->vt->adj); func_0010C2B0(D_00343028_00174780, 142, 6, 0, 6, 0, 0); return 2; }

typedef struct { char c[8]; } V8_00176A48;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00176A48;
typedef struct { char p[408]; V8_00176A48 v; char q[480]; VT_00176A48 *vt; } O_00176A48;
extern V8_00176A48 D_004A31C8_00176A48[2] __asm__("D_004A31C8"); extern char D_00343028_00176A48[] __asm__("D_00343028"); void func_00172CA0_00176A48(void *) __asm__("func_00172CA0"); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00176A48
int repetition_00176a48(O_00176A48 *o) { func_00172CA0_00176A48(o); func_00172CA0_00176A48((char *)o + 912); o->v = D_004A31C8_00176A48[0]; o->vt->fn((char *)o + o->vt->adj); func_0010C2B0(D_00343028_00176A48, 142, 6, 0, 6, 0, 0); return 2; }

extern char D_003361A4[], D_00336030[]; void func_00176608(void *); void func_00163780(int, int, char *); int func_00172CF0(void *); void func_00163A38(int, int, int, int, char *);
// MATCH func_00176FC8
void repetition_00176fc8(char *o) { func_00176608(o); func_00163780(480, 16, D_003361A4); func_00163A38(448, 22, func_00172CF0(o + 912), 3, D_00336030); }

extern char D_00336198[], D_00336030_00176608[] __asm__("D_00336030"), D_003360A8[]; void func_00163780(int, int, char *); int func_00172CF0(void *); void func_00163A38(int, int, int, int, char *); void func_001633E8(int, int, char *);
// MATCH func_00176608
void repetition_00176608(char *o) { func_00163780(160, 16, D_00336198); func_00163A38(128, 22, func_00172CF0(o), 3, D_00336030_00176608); func_001633E8(256, 36, D_00336198 - 12); func_00163A38(328, 36, *(int *)(o + 364), 3, D_003360A8); }

extern char D_0043D818_00177348[] __asm__("D_0043D818"); void *func_00162130_00177348(int, char *, int) __asm__("func_00162130"); void *func_001768F0(void *, int, int, int, int);
// MATCH func_00177348
void *repetition_00177348(int a, int b, int c, int d) { int e = 1; if (d) e = d; return func_001768F0(func_00162130_00177348(1280, D_0043D818_00177348, 2838), a, b, c, e); }

extern long long D_004A12D8_00174970 __asm__("D_004A12D8"); extern char D_004A31E8[]; typedef struct { char c[8]; } V8_00174970; int func_001646E8(char *);
// MATCH func_00174970
int repetition_00174970(char *o) { *(int *)(o + 404) = 0; if (func_001646E8(o + 376) == 0 || (D_004A12D8_00174970 & 0x200040)) *(V8_00174970 *)(o + 408) = *(V8_00174970 *)D_004A31E8; return 0; }

typedef struct { char c[8]; } V8_00176AC8;
extern V8_00176AC8 D_004A31D0[3];
int func_00172CF0(void *); void func_00174050(void *); void func_00172CB0(void *); void func_00172CF8(void *); void func_00175ED8(void);
// MATCH func_00176AC8
int repetition_00176ac8(char *o) {
    int idx, d, dl, r;
    long e;
    int (*fn)(void *);
    if (*(short *)(o + 368) >= 500) {
        if (func_00172CF0(o) >= func_00172CF0(o + 912)) func_00174050(o + 912);
    }
    idx = *(short *)(o + 890);
    if (idx > 0) {
        long *vt = *(long **)(o + *(short *)(o + 892));
        e = vt[idx - 1];
        fn = (int (*)(void *))(e >> 32);
    } else fn = *(int (**)(void *))(o + 892);
    dl = *(short *)(o + 888);
    d = idx > 0 ? (short)e + dl : dl;
    r = fn(o + d);
    if (r != 0) {
        func_00172CB0(o);
        func_00172CB0(o + 912);
        *(V8_00176AC8 *)(o + 408) = D_004A31D0[0];
        if (*(short *)(o + 890) == -1 && *(int *)(o + 892) == (int)func_00175ED8) {
            func_00172CF8(o);
            func_00172CF8(o + 912);
        }
    }
    return 0;
}
