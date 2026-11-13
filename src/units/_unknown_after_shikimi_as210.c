/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

// MATCH func_002CACE8
void FUN_002cace8(void) { *(volatile int *)0x10003810 = 1; *(volatile int *)0x10003820 = 6; }

// MATCH func_002E7000
int FUN_002e7000(int c) { while (*(volatile unsigned *)0x1000f130 & 0x8000); *(volatile unsigned char *)0x1000f180 = c; return c; }

typedef struct { volatile unsigned w0; char p[20]; unsigned short h24; } Ch_002D42F0;
typedef struct { char p[8]; int w8; } Q_002D42F0;
void *func_002CFF20(int); Q_002D42F0 *func_002CFF48(int);
// MATCH func_002D42F0
void FUN_002d42f0(unsigned ch) { if (ch < 48) { Ch_002D42F0 *p = func_002CFF20(ch); p->w0 |= 0x2000; if ((unsigned)(p->h24 - 1) < 127 && (p->w0 & 1)) { if (func_002CFF48(((volatile Ch_002D42F0 *)p)->h24)->w8 != 0) { p->w0 |= 2; p->w0 &= ~0x70; } } p->w0 &= ~0x2000; } }

// MATCH func_002CADB8
int FUN_002cadb8(unsigned a, unsigned b, unsigned c) { unsigned v = a | (b << 1) | (c << 2); *(volatile unsigned *)0x10003820 = v; return v; }

// MATCH func_002C9368
int FUN_002c9368(unsigned long long *p, int n) { return (int)(*p >> (64 - n)); }

typedef struct { char p[60]; int w60; volatile unsigned w64; } Pp_002D04C0;
typedef struct { int w0; int w4; int w8; int w12; } Qq_002D04C0;
void *func_002CFF38(void); Qq_002D04C0 *func_002CFFC0(int, unsigned);
// MATCH func_002D04C0
int SndVoiceSetParam(int a, int b, int c, int d) { Pp_002D04C0 *p = func_002CFF38(); Qq_002D04C0 *q = func_002CFFC0(p->w60, p->w64); if (p->w64 >= 255) return -1; q->w0 = a; q->w4 = b; q->w8 = c; q->w12 = d; p->w64++; return p->w64; }

extern int D_00426440[]; extern volatile int D_00426394[]; extern volatile int D_00426370[]; extern volatile int D_00426368[]; extern char D_00427510[];
int func_002CBAE8(void); int func_002CB978(int); void func_002E8038(void *, int); void func_002CB108(void); void func_002E58C0(int);
int func_002E8928(void *, int, int, void *, int, int, int, void *, void *);
// MATCH func_002CC6D8
int FUN_002cc6d8(int a) { int *p = D_00426440; if (func_002CBAE8() == 6) return 0; if (func_002CB978(9) == 0) return 0; D_00426440[0] = a; func_002E8038(p, 4); D_00426394[0] = 4; D_00426370[0] = 1; if (func_002E8928(D_00427510, 5, 1, p, 4, 0, 0, (void *)func_002CB108, D_00426394) < 0) { D_00426394[0] = 0; D_00426370[0] = 0; func_002E58C0(D_00426368[0]); return 0; } return 1; }

unsigned func_002CADE8(void);
// MATCH func_002CAE38
int FUN_002cae38(int *o) { unsigned v = *(volatile unsigned *)0x10003840; if (func_002CADE8() >= 2) return 0; o[0] = *(volatile int *)0x10003900; o[1] = *(volatile int *)0x10003910; o[2] = *(volatile int *)0x10003920; o[3] = *(volatile int *)0x10003930; o[4] = *(volatile int *)0x10003940; o[5] = *(volatile int *)0x10003950; o[6] = *(volatile int *)0x10003960; o[7] = *(volatile int *)0x10003970; o[8] = *(volatile int *)0x10003870; o[9] = *(volatile int *)0x10003880; o[10] = *(volatile int *)0x10003800; ((short *)o)[22] = *(volatile int *)0x100038d0; ((short *)o)[23] = *(volatile int *)0x10003890; ((short *)o)[24] = *(volatile int *)0x10003830; ((short *)o)[25] = *(volatile int *)0x10003860; ((char *)o)[52] = *(volatile int *)0x10003820; ((char *)o)[53] = v; ((char *)o)[54] = v >> 8; ((char *)o)[55] = *(volatile int *)0x10003850; return 1; }

int func_002EDC50(void); void func_002EDC98(void); void func_002C2D58(int, int *); void func_002C6E50(char *); void func_002C6E20(char *, int);
// MATCH func_002C3BF0
void FUN_002c3bf0(char *o, int a, unsigned b) { int st[8]; int r; st[0] = 2; func_002C2D58(*(int *)(o + 2136), st); func_002C6E50(o); *(volatile int *)0x10002000 = 0; func_002C6E50(o); r = func_002EDC50(); *(volatile unsigned *)0x1000b410 = b & 0x0fffffff; *(volatile int *)0x1000b420 = 4; *(volatile int *)0x1000b400 = 257; if (r != 0) func_002EDC98(); func_002C6E20(o, a); func_002C6E50(o); st[0] = 3; func_002C2D58(*(int *)(o + 2136), st); }

extern volatile int D_00426394_002CC858[] __asm__("D_00426394"); extern volatile int D_00426370_002CC858[] __asm__("D_00426370"); extern volatile int D_00426368_002CC858[] __asm__("D_00426368"); extern char D_00427510_002CC858[] __asm__("D_00427510");
int func_002CBAE8(void); int func_002CB978(int); int func_002E8928_002CC858(char *, int, int, int, int, int, int, void *, int *) __asm__("func_002E8928"); void func_002E58C0(int); void func_002CB108(void);
// MATCH func_002CC858
int FUN_002cc858(void) { if (func_002CBAE8() == 6) return 0; if (func_002CB978(11) == 0) return 0; D_00426394_002CC858[0] = 6; D_00426370_002CC858[0] = 1; if (func_002E8928_002CC858(D_00427510_002CC858, 7, 1, 0, 0, 0, 0, func_002CB108, D_00426394_002CC858) < 0) { D_00426394_002CC858[0] = 0; D_00426370_002CC858[0] = 0; func_002E58C0(D_00426368_002CC858[0]); return 0; } return 1; }

extern volatile int D_00426394_002CC7A8[] __asm__("D_00426394"); extern volatile int D_00426370_002CC7A8[] __asm__("D_00426370"); extern volatile int D_00426368_002CC7A8[] __asm__("D_00426368"); extern char D_00427510_002CC7A8[] __asm__("D_00427510");
int func_002CBAE8(void); int func_002CB978(int); int func_002E8928_002CC7A8(char *, int, int, int, int, int, int, void *, int *) __asm__("func_002E8928"); void func_002E58C0(int); void func_002CB108(void);
// MATCH func_002CC7A8
int FUN_002cc7a8(void) { if (func_002CBAE8() == 6) return 0; if (func_002CB978(10) == 0) return 0; D_00426394_002CC7A8[0] = 5; D_00426370_002CC7A8[0] = 1; if (func_002E8928_002CC7A8(D_00427510_002CC7A8, 6, 1, 0, 0, 0, 0, func_002CB108, D_00426394_002CC7A8) < 0) { D_00426394_002CC7A8[0] = 0; D_00426370_002CC7A8[0] = 0; func_002E58C0(D_00426368_002CC7A8[0]); return 0; } return 1; }

extern volatile int D_00426354[], D_00426394_002CB478[] __asm__("D_00426394"), D_00426360[], D_00426368_002CB478[] __asm__("D_00426368"), D_0042636C[];
void func_002E58C0(int); int func_002E58B0(int); int func_002EDC50(void); void func_002E7D30(int); void func_002EDC98(void);
// MATCH func_002CB478
void FUN_002cb478(void) { int r; if (D_00426354[0]) { D_00426394_002CB478[0] = -1; func_002E58C0(D_00426360[0]); } func_002E58B0(D_00426368_002CB478[0]); func_002E58B0(D_0042636C[0]); func_002E58B0(D_00426360[0]); r = func_002EDC50(); func_002E7D30(0x80000012); if (r) func_002EDC98(); }

int func_002C7318(int, int);
// MATCH func_002C7850
void FUN_002c7850(int o) { int v; int t; *(int *)(o + 0x164) = func_002C7318(o, 4); *(int *)(o + 0x168) = func_002C7318(o, 4); *(int *)(o + 0x16c) = func_002C7318(o, 4); *(int *)(o + 0x170) = func_002C7318(o, 4); v = func_002C7318(o, 2); *(volatile unsigned *)0x10002010 = (*(volatile unsigned *)0x10002010 & 0xfffcffff) | (v << 16); t = func_002C7318(o, 2); *(int *)(o + 0x174) = t; if (*(int *)(o + 0xd4) == 0) *(int *)(o + 0xd4) = t; *(int *)(o + 0x178) = func_002C7318(o, 1); *(int *)(o + 0x17c) = func_002C7318(o, 1); *(int *)(o + 0x180) = func_002C7318(o, 1); v = func_002C7318(o, 1); *(volatile unsigned *)0x10002010 = (*(volatile unsigned *)0x10002010 & 0xffbfffff) | (v << 22); v = func_002C7318(o, 1); *(volatile unsigned *)0x10002010 = (*(volatile unsigned *)0x10002010 & 0xffdfffff) | (v << 21); v = func_002C7318(o, 1); *(volatile unsigned *)0x10002010 = (*(volatile unsigned *)0x10002010 & 0xffefffff) | (v << 20); *(int *)(o + 0x184) = func_002C7318(o, 1); func_002C7318(o, 1); *(int *)(o + 0x188) = func_002C7318(o, 1); if (func_002C7318(o, 1) != 0) { func_002C7318(o, 1); func_002C7318(o, 3); func_002C7318(o, 1); func_002C7318(o, 7); func_002C7318(o, 8); } }


extern char D_0049D460_2C0338[] __asm__("D_0049D460"), D_0049D490_2C0338[] __asm__("D_0049D490"), D_0049D4A0_2C0338[] __asm__("D_0049D4A0"), D_0049D4B0_2C0338[] __asm__("D_0049D4B0"), D_0049D4C0_2C0338[] __asm__("D_0049D4C0"), D_0049D4D0_2C0338[] __asm__("D_0049D4D0"), D_0049D4E0_2C0338[] __asm__("D_0049D4E0"), D_0049D4F0_2C0338[] __asm__("D_0049D4F0"), D_0049D500_2C0338[] __asm__("D_0049D500"), D_0049D510_2C0338[] __asm__("D_0049D510"), D_0049D528_2C0338[] __asm__("D_0049D528"), D_0049D540_2C0338[] __asm__("D_0049D540"), D_0049D570_2C0338[] __asm__("D_0049D570"), D_0049D5A0_2C0338[] __asm__("D_0049D5A0"), D_0049D5C8_2C0338[] __asm__("D_0049D5C8");
#define R_2C0338(a) (*(volatile unsigned *)(a))
void func_002E7940_2C0338(char *, ...) __asm__("func_002E7940");
#define FAIL(m) { func_002E7940_2C0338(m); func_002E7940_2C0338(D_0049D490_2C0338, R_2C0338(0x10009000)); func_002E7940_2C0338(D_0049D4A0_2C0338, R_2C0338(0x10009030)); func_002E7940_2C0338(D_0049D4B0_2C0338, R_2C0338(0x10009010)); func_002E7940_2C0338(D_0049D4C0_2C0338, R_2C0338(0x10009020)); func_002E7940_2C0338(D_0049D4D0_2C0338, R_2C0338(0x1000a000)); func_002E7940_2C0338(D_0049D4E0_2C0338, R_2C0338(0x1000a030)); func_002E7940_2C0338(D_0049D4F0_2C0338, R_2C0338(0x1000a010)); func_002E7940_2C0338(D_0049D500_2C0338, R_2C0338(0x1000a020)); func_002E7940_2C0338(D_0049D510_2C0338, R_2C0338(0x10003c00)); func_002E7940_2C0338(D_0049D528_2C0338, R_2C0338(0x10003020)); return -1; }
// MATCH func_002C0338
int sceGsSyncPath(int mode) {
  unsigned i = 0;
  int r;
  unsigned t;
  if (mode == 0) {
    while ((R_2C0338(0x10009000) & 0x100) != 0) { if (0x1000000 < i++) FAIL(D_0049D460_2C0338) }
    while ((R_2C0338(0x1000a000) & 0x100) != 0) { if (0x1000000 < i++) FAIL(D_0049D540_2C0338) }
    while ((R_2C0338(0x10003c00) & 0x1f000003) != 0) { if (0x1000000 < i++) FAIL(D_0049D570_2C0338) }
    __asm__ volatile("cfc2 %0, $29" : "=r"(t));
    while ((t & 0x100) != 0) { if (0x1000000 < i++) FAIL(D_0049D5A0_2C0338) __asm__ volatile("cfc2 %0, $29" : "=r"(t)); }
    while ((R_2C0338(0x10003020) & 0xc00) != 0) { if (0x1000000 < i++) FAIL(D_0049D5C8_2C0338) }
    return 0;
  }
  r = (int)(R_2C0338(0x10009000) & 0x100); if (r != 0) r = 1;
  if ((R_2C0338(0x1000a000) & 0x100) != 0) r |= 2;
  if ((R_2C0338(0x10003c00) & 0x1f000003) != 0) r |= 4;
  __asm__ volatile("cfc2 %0, $29" : "=r"(t));
  if ((t & 0x100) != 0) r |= 8;
  if ((R_2C0338(0x10003020) & 0xc00) != 0) r |= 16;
  return r;
}
#undef R_2C0338
#undef FAIL
