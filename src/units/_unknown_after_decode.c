/* Functions of this report unit, matched by hand. */
#include "../common.h"
typedef int u128 __attribute__((mode(TI)));

typedef struct { char pad[72]; int a; char pad2[8]; int b; } S_001911F0;
// MATCH func_001911F0
int FUN_001911f0(S_001911F0 *s) { return !(s->b < s->a); }

typedef struct { int a, b; } T_00190E88;
// MATCH func_00190E88
int FUN_00190e88(char *s, int x) { T_00190E88 *t = (T_00190E88 *)(s + 0x50000); int n = t->b; int m = (n < x) ? n : x; t->b = n - m; return m; }

typedef struct { int a, b, c; } T_00190DA8;
// MATCH func_00190DA8
void FUN_00190da8(char *s) { T_00190DA8 *t = (T_00190DA8 *)(s + 0x50000); t->c = 0x50000; t->a = 0; t->b = 0; }

extern char D_003215D0[]; void func_00114358(void); void func_001917D0(void *);
// MATCH func_00192B88
int FUN_00192b88(void) { func_00114358(); func_001917D0(D_003215D0); return 1; }

extern char D_003215D0[]; void func_001919D8(void *);
// MATCH func_00192BE0
int FUN_00192be0(void) { func_001919D8(D_003215D0); return 1; }

extern char D_003215D0[]; typedef struct { long long a, b, c, d; } T_00192C08; void func_00191CE8(void *, void *);
// MATCH func_00192C08
int FUN_00192c08(int x, char *d) { T_00192C08 t; func_00191CE8(D_003215D0, &t); *(long long *)(d + 8) = t.a; *(long long *)(d + 16) = t.b; return 1; }

typedef struct { char p[12]; volatile int w; } O_00194A48;
// MATCH func_00194A48
void FUN_00194a48(O_00194A48 *o) { if (o->w > 0) o->w = o->w - 1; }

typedef struct { char *a, *b, *c, *d, *e, *f; } O_00192D80;
extern char D_002F0900[], D_002F1200[], D_002F2D00[], D_002F2D80[], D_002F1B00[], D_002F2400[];
// MATCH func_00192D80
void FUN_00192d80(O_00192D80 *o) { o->a = D_002F0900; o->b = D_002F1200; o->c = D_002F2D00; o->d = D_002F2D80; o->e = D_002F1B00; o->f = D_002F2400; }

void func_00192928(void *, void *, void *, void *, void *);
// MATCH func_001929C0
int FUN_001929c0(void *s) { int v[4]; func_00192928(s, v, v + 1, v + 2, v + 3); return v[1] + v[3]; }

typedef struct { char pad[16]; int a16; int a20; char pad1[40]; int a64; } S_192300_00192300;
int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_00192300
int FUN_00192300(S_192300_00192300 *s) { int x; func_002E58E0(s->a64); x = (s->a16 << 11) + s->a20; func_002E58C0(s->a64); return x; }

int func_001929A0(void *); int func_002C2C78(void *);
// MATCH func_00192AC8
int FUN_00192ac8(void *s) { int r = 0; if (func_001929A0(s) == 0) r = func_002C2C78(s) != 0; return r; }

typedef struct { unsigned w0, w4, w8; } O_00191698;
// MATCH func_00191698
unsigned FUN_00191698(O_00191698 *o, unsigned a) { unsigned v = ((o->w8 << 4) + o->w4 + 16) & 0xfffffff; if (a == v) return 0; return (a - o->w0) >> 11; }

typedef struct { char p[72]; int w72; } O_00192960;
typedef struct { long long a, b; int c, d; } Q_00192960;
extern char D_003215D0_00192960[] __asm__("D_003215D0"); void func_00192500(char *, Q_00192960 *);
// MATCH func_00192960
void FUN_00192960(O_00192960 *o, long long a, long long b, int c, int d) { Q_00192960 q; q.a = a; q.b = b; q.c = c - o->w72; q.d = d; func_00192500(D_003215D0_00192960, &q); }

typedef struct { int w0, w4, w8; char p0[12]; int w24; char p1[36]; int w64; char p2[4]; long long l72; int w80, w84; } O_00191E78;
int func_002E58A0_00191E78(int *) __asm__("func_002E58A0"); void func_00191EF0(O_00191E78 *);
// MATCH func_00191E78
int FUN_00191e78(O_00191E78 *o, int a, unsigned b, int c, int d, int e) { int t[8]; b &= 0xfffffff; b |= 0x20000000;
o->w0 = a;
o->w4 = b;
o->w24 = c << 11;
o->w80 = d;
o->w84 = e;
t[2] = 1;
t[1] = 1;
o->w8 = c; o->w64 = func_002E58A0_00191E78(t); func_00191EF0(o); o->l72 = 0; return 1; }

// MATCH func_001917A8
void FUN_001917a8(unsigned long *d, unsigned a, unsigned b, unsigned c) { *d = ((unsigned long)a << 32) | (((unsigned long)b << 32) >> 4) | (unsigned long)c; }

int func_002E58E0(int); void func_002E58C0_00192118(int) __asm__("func_002E58C0");
// MATCH func_00192118
void FUN_00192118(char *o, int n) { func_002E58E0(*(int *)(o + 64)); *(int *)(o + 20) = *(int *)(o + 20) + n; *(long long *)(o + 72) = n + *(long long *)(o + 72); func_002E58C0_00192118(*(int *)(o + 64)); }

int func_002E58E0(int); void func_002E58C0_00192350(int) __asm__("func_002E58C0");
// MATCH func_00192350
void FUN_00192350(int *o) { func_002E58E0(o[16]); o[5] = (o[5] + 2047) / 2048 * 2048; func_002E58C0_00192350(o[16]); }

void func_00191740(int); void func_002E58B0_00192268(int) __asm__("func_002E58B0");
// MATCH func_00192268
int FUN_00192268(int *o) { func_00191740(5); *(volatile int *)0x1000b420 = 0; *(volatile int *)0x1000b410 = 0; *(volatile int *)0x1000b430 = 0; func_002E58B0_00192268(o[16]); return 1; }

int func_002E58E0_192168(int) __asm__("func_002E58E0"); int func_002E58C0_192168(int) __asm__("func_002E58C0"); void func_00191740_192168(int) __asm__("func_00191740"); void func_001916D8_192168(int) __asm__("func_001916D8");
// MATCH func_00192168
int FUN_00192168(int *o) { func_002E58E0_192168(o[16]); o[17] = 0; func_00191740_192168(5); o[7] = *(volatile unsigned *)0x1000b410; o[8] = *(volatile unsigned *)0x1000b430; o[9] = *(volatile unsigned *)0x1000b420; o[10] = *(volatile unsigned *)0x1000b400; while (*(volatile unsigned *)0x10002010 & 0xf0) ; func_001916D8_192168(0); o[11] = *(volatile unsigned *)0x1000b010; o[12] = *(volatile unsigned *)0x1000b020; o[13] = *(volatile unsigned *)0x1000b000; o[14] = *(volatile unsigned *)0x10002020; o[15] = *(volatile unsigned *)0x10002010; func_002E58C0_192168(o[16]); return 1; }

void func_002CF4B0(void *, int); void func_002CF830(void *, int); void func_002CF610(void *, int); void func_002CF668(void *, int);
void func_00192E58(void *, int, int, int, int, int, int, int); void func_002CF6F0(void *, u128); void func_002CF8C8(void *, int, int);
void func_002CF708(void *); void func_002CF6C0(void *); void func_002CF458_001946E8(void *) __asm__("func_002CF458");
// MATCH func_001946E8
void FUN_001946e8(void *o) { u128 b; func_002CF4B0(o, 0); func_002CF830(o, 0x150007fc); func_002CF610(o, 0); func_002CF830(o, 0x11000000); func_002CF668(o, 0); func_00192E58(&b, 14, 1, 0, 0, 0, 1, 0); func_002CF6F0(o, b); func_002CF8C8(o, 0x61, 0); func_002CF708(o); func_002CF6C0(o); func_002CF830(o, 0x11000000); func_002CF458_001946E8(o); }

void func_002CF508(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
// MATCH func_00194808
void FUN_00194808(int *o, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) { func_002CF508(o, a & 0xfffffff, d / e, 0, (b << 24) | ((d << 16) | (c | 0x4000)), 0); }

void func_00192B80(void); void func_00192B88(void); void func_00192BB8(void); void func_00192BE0(void); void func_00192C08(void);
void func_002C2918(); int func_002C2D30(int, int, void (*)(void), int);
void func_001925F0(int); int func_00191E78(int, int, int, int, int, int);
// MATCH func_001925F8
int FUN_001925f8(int a, int b, int c, int d, int e, int f, int g, int h) { func_002C2918(a, b, c); func_002C2D30(a, 0, func_00192B80, 0); func_002C2D30(a, 1, func_00192B88, 0); func_002C2D30(a, 2, func_00192BB8, 0); func_002C2D30(a, 3, func_00192BE0, 0); func_002C2D30(a, 5, func_00192C08, 0); func_001925F0(a); func_00191E78(a + 0x48, d, e, f, g, h); return 1; }

extern int D_004A163C; extern char D_005AB300[];
int func_001915A0(int, int, int); void func_00191618(int); void func_002D5350(void);
int func_002D5380(int *); void func_002D5430(int);
void *memset(void *, int, unsigned);
// MATCH func_00190EB0
int FUN_00190eb0(int *o, int a, int b, int c) { int buf[4]; int d; int e; d = D_004A163C; o[15] = b; o[18] = c; o[0] = 0; o[11] = 0; o[13] = 0; o[14] = 0; o[16] = 0; o[21] = 0; o[19] = 0; o[20] = 0; o[17] = d; e = d + c; D_004A163C = e; o[12] = a; o[22] = e; D_004A163C = e + 0x800; memset(D_005AB300, 0, 0x800); func_001915A0(o[22], (int)D_005AB300, 0x800); func_002D5350(); buf[0] = 0; buf[1] = 0x10400; buf[3] = c; buf[2] = o[17]; func_002D5380(buf); buf[1] = 0x10400; buf[3] = c; buf[0] = 1; buf[2] = o[17] + 0x200; func_002D5380(buf); func_002D5430(8); func_00191618(0x3fff); return 1; }

int func_001949D0_1949E0() __asm__("func_001949D0");
// MATCH func_001949E0
int FUN_001949e0(char *o) { int n; int r; if (func_001949D0_1949E0() == 0) { n = *(int *)(o + 0x10); r = *(volatile int *)(o + 4) + (((*(volatile int *)(o + 8) - *(int *)(o + 0xc)) + n) % n) * 0x4ce40; } else r = 0; return r; }

