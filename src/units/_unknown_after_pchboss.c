/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[36]; int w; } O_00219800; int func_00196FF8(void *);
// MATCH func_00219800
int FUN_00219800(O_00219800 *o) { if (func_00196FF8(o)) return 1; return (unsigned)(o->w - 1) < 2; }

typedef struct { char p[4976]; int w; } O_0021AE58; void func_00254990(int);
// MATCH func_0021AE58
void FUN_0021ae58(O_0021AE58 *o) { if (o->w >= 0) func_00254990(o->w); }

typedef struct { char p[4976]; int w; } O_0021AE78; void func_00254E38(int);
// MATCH func_0021AE78
void FUN_0021ae78(O_0021AE78 *o) { if (o->w >= 0) func_00254E38(o->w); }

// MATCH func_00219130
char *FUN_00219130(char *p) { while (*p != 10) p++; return p + 1; }

// MATCH func_00219168
void FUN_00219168(char *p) { while (*p != 10) p++; *p = 0; }

typedef struct { char p[4976]; int w; } O_0021A8F8; void func_00254990(int);
// MATCH func_0021A8F8
void FUN_0021a8f8(O_0021A8F8 *o) { if (o->w >= 0) func_00254990(o->w); o->w = -1; }

typedef struct { char p[4816]; unsigned w; } O_0021AE30;
// MATCH func_0021AE30
int FUN_0021ae30(O_0021AE30 *o, int a) { if (!(o->w & 0x40000000)) return 0; return a < 7; }

typedef struct { char p[5460]; float r, a, b; } O_0021AF40;
// MATCH func_0021AF40
void FUN_0021af40(O_0021AF40 *o) { float a = o->a; float b = o->b; if (a < b) o->r = b; else o->r = a; }

typedef struct { char p[5460]; float r, a, b; } O_0021B088;
// MATCH func_0021B088
void FUN_0021b088(O_0021B088 *o, float a, float b) { o->a = a; o->b = b; if (a < b) o->r = b; else o->r = a; }

typedef struct { char p[4900]; float f; } O_0021AFF0; float func_0021AF68(void *);
// MATCH func_0021AFF0
void FUN_0021aff0(O_0021AFF0 *o) { o->f = func_0021AF68(o); }

typedef struct { char p[604]; int w; } O_002194C0;
// MATCH func_002194C0
int FUN_002194c0(O_002194C0 *o) { int v = o->w; if (v != 0 && v != 10) return 0; return 1; }

typedef struct { char p[4812]; int w; } O_0021AEC0;
// MATCH func_0021AEC0
int FUN_0021aec0(O_0021AEC0 *o) { int v = o->w; if (v != 100 && (v ^ 0x65) != 0) return 0; return 1; }

extern float D_004A04B4; typedef struct { char p[16]; float a, b, c; } O_002197D0;
// MATCH func_002197D0
void FUN_002197d0(O_002197D0 *o, float x, float y, float z) { float a = x - D_004A04B4; float b = y - D_004A04B4; o->c = z; o->a = a; o->b = b; if (a < 0.0f) o->a = 0.0f; }

// MATCH func_002191A0
void FUN_002191a0(char *d, char *s) { if (s != 0) { while (*s != 10 && *s != 0) { *d++ = *s++; } } *d = 0; }

typedef struct { int n; int tbl[1]; } T_0021B5B8;
typedef struct { char p[152]; T_0021B5B8 *t; char p2[32]; short i; } O_0021B5B8;
// MATCH func_0021B5B8
unsigned FUN_0021b5b8(O_0021B5B8 *o) { T_0021B5B8 *p = o->t; int i; if (p == 0) return 0; i = o->i; if (i < 0) return 0; if ((unsigned)(p->n - 1) < (unsigned)i) return 0; return *(unsigned short *)((char *)p + *(int *)((char *)p + i * 4 + 4) + 2); }

typedef struct { char pad[4816]; unsigned a4816; char pad2[412]; long l5232; } S_21a938_0021A938;
// MATCH func_0021A938
int FUN_0021a938(S_21a938_0021A938 *s) { if ((s->a4816 & 0x20800) || (s->l5232 & 0x0010171c00000000L)) return 0; return 1; }

typedef struct { char p[56]; short adj; short pad; void (*fn)(void *, void *, int, int); } VT_00219EE8;
typedef struct { char p[2116]; VT_00219EE8 *vt; } G_00219EE8;
typedef struct { char p[172]; short h172; } O_00219EE8;
extern G_00219EE8 *D_004A1A3C_00219EE8 __asm__("D_004A1A3C"); int func_00127430(void); void func_00226B28(G_00219EE8 *, O_00219EE8 *, int, int);
// MATCH func_00219EE8
void FUN_00219ee8(O_00219EE8 *o, int x) { if (func_00127430() != 0) { G_00219EE8 *g = D_004A1A3C_00219EE8; g->vt->fn((char *)g + g->vt->adj, o, o->h172, x); func_00226B28(D_004A1A3C_00219EE8, o, o->h172, x); } }

typedef struct { char p[32]; float f32, f36, f40; char q[20]; float f64, f68, f72; } E_0021B550;
typedef struct { char p[4800]; E_0021B550 *w4800; } O_0021B550;
void func_00249108(O_0021B550 *); void func_00249390(void); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_002489F0(void); void func_002464A8(E_0021B550 *); void func_002491D8(void);
// MATCH func_0021B550
void FUN_0021b550(O_0021B550 *o) { func_00249108(o); func_00249390(); func_00249100(o->w4800->f32, o->w4800->f36, o->w4800->f40); func_00248E00(o->w4800->f64, o->w4800->f68, o->w4800->f72); func_002489F0(); func_002464A8(o->w4800); func_002491D8(); }

extern char D_00456C58[]; extern int D_003279A0_0021AEE0[] __asm__("D_003279A0"); void func_001118F8_0021AEE0(char *, ...) __asm__("func_001118F8");
// MATCH func_0021AEE0
int FUN_0021aee0(int *o) { int i = o[1203]; if (i < 0) i = 0; if (i >= 10) i = 0; if (D_003279A0_0021AEE0[i] == 0) { func_001118F8_0021AEE0(D_00456C58); i = 0; } return i; }

typedef struct { char p[48]; signed char f48; signed char f49; char p2[30]; } E5_0021AB90;
extern E5_0021AB90 D_003210E0[];
int func_0021AE30(void *, int);
// MATCH func_0021AB90
char FUN_0021ab90(char *o) { E5_0021AB90 *e; if (func_0021AE30(o, *(int *)(o + 4964)) == 0) return 0; e = &D_003210E0[*(int *)(o + 4964)]; return e->f48; }

typedef struct { char p[48]; signed char f48; signed char f49; char p2[30]; } E5_0021ACE0;
extern E5_0021ACE0 D_003210E0_0021ACE0[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021ACE0
char FUN_0021ace0(char *o) { E5_0021ACE0 *e; if (func_0021AE30(o, *(int *)(o + 4964)) == 0) return 0; e = &D_003210E0_0021ACE0[*(int *)(o + 4964)]; return e->f49; }

typedef struct { char p[48]; signed char f48; signed char f49; char p2[30]; } E5_0021AC30;
extern E5_0021AC30 D_003210E0_0021AC30[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021AC30
void FUN_0021ac30(char *o, int v) { E5_0021AC30 *e; if (func_0021AE30(o, *(int *)(o + 4964)) != 0) { e = &D_003210E0_0021AC30[*(int *)(o + 4964)]; e->f48 = v; } }

typedef struct { char p[48]; signed char f48; signed char f49; char p2[30]; } E5_0021AD80;
extern E5_0021AD80 D_003210E0_0021AD80[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021AD80
void FUN_0021ad80(char *o, int v) { E5_0021AD80 *e; if (func_0021AE30(o, *(int *)(o + 4964)) != 0) { e = &D_003210E0_0021AD80[*(int *)(o + 4964)]; e->f49 = v; } }

int func_00219600(void *, int);
// MATCH func_00219778
int FUN_00219778(int *o, int v) { o[154] = 0; o[151] = 0; o[3] = 0; o[5] = 0; o[4] = 0; o[153] = 0; o[84] = -1; o[155] = -1; o[152] = -1; o[7] = v; func_00219600(o, v); return o[0]; }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021AA20;
extern E6_0021AA20 D_003210E0_0021AA20[] __asm__("D_003210E0");
// MATCH func_0021AA20
void FUN_0021aa20(char *o, int v) { E6_0021AA20 *e; if ((*(unsigned *)(o + 0x12d0) & 0x40000000) != 0 && *(int *)(o + 0x1364) < 7) { e = &D_003210E0_0021AA20[*(int *)(o + 0x1364)]; e->c43 = v; } }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021ABE0;
extern E6_0021ABE0 D_003210E0_0021ABE0[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021ABE0
short FUN_0021abe0(char *o) { E6_0021ABE0 *e; if (func_0021AE30(o, *(int *)(o + 4964)) == 0) return 0; e = &D_003210E0_0021ABE0[*(int *)(o + 4964)]; return e->s2; }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021AD30;
extern E6_0021AD30 D_003210E0_0021AD30[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021AD30
short FUN_0021ad30(char *o) { E6_0021AD30 *e; if (func_0021AE30(o, *(int *)(o + 4964)) == 0) return 0; e = &D_003210E0_0021AD30[*(int *)(o + 4964)]; return e->s46; }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021AC88;
extern E6_0021AC88 D_003210E0_0021AC88[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021AC88
void FUN_0021ac88(char *o, int v) { E6_0021AC88 *e; if (func_0021AE30(o, *(int *)(o + 4964)) != 0) { e = &D_003210E0_0021AC88[*(int *)(o + 4964)]; e->s2 = v; } }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021ADD8;
extern E6_0021ADD8 D_003210E0_0021ADD8[] __asm__("D_003210E0");
int func_0021AE30(void *, int);
// MATCH func_0021ADD8
void FUN_0021add8(char *o, int v) { E6_0021ADD8 *e; if (func_0021AE30(o, *(int *)(o + 4964)) != 0) { e = &D_003210E0_0021ADD8[*(int *)(o + 4964)]; e->s46 = v; } }

extern int D_004A1A20_0021A280 __asm__("D_004A1A20");
// MATCH func_0021A280
void FUN_0021a280(int a, int b, int c, int d) { char *base; char *e; base = (char *) ((a * 5472) + D_004A1A20_0021A280); e = (char *) ((b * 156) + (*((int *) (base + 5456)))); do { *((int *) e) = d; *((int *) (e + 4)) = c; *((int *) (e + 76)) = 0; *((int *) (e + 80)) = 0; *((int *) (e + 88)) = 0; } while (0); }

typedef struct { char p0[2]; short s2; char p4[39]; signed char c43; char p44[2]; short s46; signed char f48; signed char f49; char p50[30]; } E6_0021A9E0;
extern E6_0021A9E0 D_003210E0_0021A9E0[] __asm__("D_003210E0");
// MATCH func_0021A9E0
int FUN_0021a9e0(char *o) { E6_0021A9E0 *e; if ((*(unsigned *)(o + 4816) & 0x40000000) == 0) return 0; if (*(int *)(o + 4964) >= 7) return 0; e = &D_003210E0_0021A9E0[*(int *)(o + 4964)]; return e->c43; }

extern int D_004A129C_0021B378 __asm__("D_004A129C"); float func_0015FB58_0021B378(float, int) __asm__("func_0015FB58"); inline float inline_fn_21b378_0021B378(float arg0) { return arg0; }
// MATCH func_0021B378
void FUN_0021b378(int param_1) { int iVar1; float fVar2; float fVar3; float fVar4; float fVar5; float fVar6; iVar1 = *((int *) (param_1 + 0x12c0)); if (((*((short *) (iVar1 + 0xbc))) == 0) && (((int) (*((float *) (iVar1 + 0xc4)))) == 1)) { fVar6 = -(*((float *) (iVar1 + 0x44))); fVar5 = (*((float *) (iVar1 + 0x80))) - (*((float *) (iVar1 + 0x20))); fVar4 = (*((float *) (iVar1 + 0x88))) - (*((float *) (iVar1 + 0x28))); fVar2 = (float) inline_fn_21b378_0021B378(func_0015FB58_0021B378(fVar6, 1)); fVar3 = (float) func_0015FB58_0021B378(fVar6, 0); *((float *) (param_1 + 0x149c)) = (fVar5 * fVar2) - (fVar4 * fVar3); fVar2 = (float) func_0015FB58_0021B378(fVar6, 1); fVar3 = (float) func_0015FB58_0021B378(fVar6, 0); *((float *) (param_1 + 0x14a4)) = (fVar4 * fVar2) + (fVar5 * fVar3); } D_004A129C_0021B378 = 1; }

extern int D_00456C68[];
void func_00249108_0021B468(void) __asm__("func_00249108"); void func_00249390(void); void func_002489F0(void); void func_002491D8(void);
void func_00249100(float, float, float); void func_00248E00(float, float, float);
void func_002464A8_0021B468(int) __asm__("func_002464A8"); void func_0018F080_0021B468(char *, char *, char *) __asm__("func_0018F080"); void func_0018F020_0021B468(char *, char *, char *) __asm__("func_0018F020");
int func_001118F8_0021B468(void *) __asm__("func_001118F8");
// MATCH func_0021B468
int FUN_0021b468(int o) { float fa; float fb; char buf[16]; int e; fb = *(float *)(*(int *)(o + 0x12c0) + 0x80); fa = *(float *)(*(int *)(o + 0x12c0) + 0x88); func_00249108_0021B468(); func_00249390(); e = *(int *)(o + 0x12c0); func_00249100(*(float *)(e + 0x20), *(float *)(e + 0x24), *(float *)(e + 0x28)); e = *(int *)(o + 0x12c0); func_00248E00(*(float *)(e + 0x40), *(float *)(e + 0x44), *(float *)(e + 0x48)); func_002489F0(); func_002464A8_0021B468(*(int *)(o + 0x12c0)); func_0018F080_0021B468(buf, (char *)(*(int *)(o + 0x12c0) + 0x80), (char *)(*(int *)(o + 0x12c0) + 0x20)); e = *(int *)(o + 0x12c0); *(float *)(e + 0x20) = fb - (*(float *)(e + 0x80) - *(float *)(e + 0x20)); *(float *)(e + 0x28) = fa - (*(float *)(e + 0x88) - *(float *)(e + 0x28)); func_0018F020_0021B468((char *)(e + 0x80), (char *)(e + 0x20), buf); func_002491D8(); return func_001118F8_0021B468(D_00456C68); }

// cflags: -fno-gcse
typedef struct { int a0, a4, a8, a12, a16, a20, a24; int a28; int a32; } T36_00218ba8_00218BA8_218BA8;
extern T36_00218ba8_00218BA8_218BA8 D_003C7EF0_218BA8[] __asm__("D_003C7EF0"); void func_00216D28_218BA8(void) __asm__("func_00216D28"); void func_00229390_218BA8(char *, int, int) __asm__("func_00229390");
// MATCH func_00218BA8
void FUN_00218ba8(char *o) { int k; int y; int x; int u1, u2, u3, u4, u5, u6, u7; T36_00218ba8_00218BA8_218BA8 *e; func_00216D28_218BA8(); k = -1; x = *(int *)(o + 1780); if (x == 0x1a) k = 0; if (x == 32) { *(float *)(o + 1028) = 512.0f; k = 1; } x = *(int *)(o + 1780); y = x++; x--; if (y == 33) { *(float *)(o + 1028) = 512.0f; k = 2; } if (y == 34) { *(float *)(o + 1028) = 512.0f; k = 3; } if (x == 35) { *(float *)(o + 1028) = 512.0f; k = 4; } if (k >= 0) { e = &D_003C7EF0_218BA8[k]; u1 = e->a0; u2 = e->a4; *(int *)(o + 60) = u1; *(int *)(o + 64) = u2; u3 = e->a24; u4 = e->a8; *(int *)(o + 2064) = u3; *(int *)(o + 68) = u4; u5 = e->a12; *(int *)(o + 2076) = u5; u6 = e->a16; *(int *)(o + 2080) = u6; u7 = e->a20; *(int *)(o + 2084) = u7; if (e->a28 != 0) func_00229390_218BA8(o, e->a28, e->a32); } }
