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

typedef unsigned long u_long; typedef int u128 __attribute__((mode(TI)));
typedef struct { u_long NLOOP:15; u_long EOP:1; u_long pad16:16; u_long id:14; u_long PRE:1; u_long PRIM:11; u_long FLG:2; u_long NREG:4; u_long REGS0:4; u_long REGS1:4; u_long REGS2:4; u_long REGS3:4; u_long REGS4:4; u_long REGS5:4; u_long REGS6:4; u_long REGS7:4; u_long REGS8:4; u_long REGS9:4; u_long REGS10:4; u_long REGS11:4; u_long REGS12:4; u_long REGS13:4; u_long REGS14:4; u_long REGS15:4; } __attribute__((aligned(16))) GifTag_2C0838;
typedef struct { unsigned w0, w1, w2, w3; GifTag_2C0838 giftag0; long bitbltbuf, bitbltbufaddr, trxpos, trxposaddr, trxreg, trxregaddr, finish, finishaddr, trxdir, trxdiraddr; } StoreImage_2C0838;
// MATCH func_002C0838
int FUN_002c0838(StoreImage_2C0838 *sp, short vram_addr, int vram_width, short psm, short x, int y, short w, short h) {
  long ty = (long)(y << 16);
  *(u128 *)&sp->giftag0 = 0;
  sp->w1 = 0x6008000;
  sp->w0 = 0;
  sp->finish = 0;
  sp->w2 = 0x13000000;
  sp->w3 = 0x50000006;
  sp->giftag0.NLOOP = 5; sp->giftag0.EOP = 1; sp->giftag0.NREG = 1; sp->giftag0.REGS0 = 0xe;
  sp->bitbltbuf = (long)(vram_width << 16) | (long)vram_addr | (long)psm << 24;
  sp->bitbltbufaddr = 0x50;
  sp->trxpos = ty | (long)x;
  sp->trxposaddr = 0x51;
  sp->trxreg = (long)w | (long)h << 32;
  sp->trxregaddr = 0x52;
  sp->finishaddr = 0x61;
  sp->trxdir = 1;
  sp->trxdiraddr = 0x53;
  __asm__ volatile ("sync");
  return 7;
}

typedef struct { u_long NLOOP:15; u_long EOP:1; u_long pad16:16; u_long id:14; u_long PRE:1; u_long PRIM:11; u_long FLG:2; u_long NREG:4; u_long REGS0:4; u_long REGS1:4; u_long REGS2:4; u_long REGS3:4; u_long REGS4:4; u_long REGS5:4; u_long REGS6:4; u_long REGS7:4; u_long REGS8:4; u_long REGS9:4; u_long REGS10:4; u_long REGS11:4; u_long REGS12:4; u_long REGS13:4; u_long REGS14:4; u_long REGS15:4; } __attribute__((aligned(16))) GifTag_2C0650;
typedef struct { GifTag_2C0650 giftag0; long bitbltbuf; long bitbltbufaddr; long trxpos; long trxposaddr; long trxreg; long trxregaddr; long trxdir; long trxdiraddr; GifTag_2C0650 giftag1; } LoadImage_2C0650;
void func_002E7940(char *, ...); extern char D_0049D5F0[];
// MATCH func_002C0650
int sceGsSetDefLoadImage(LoadImage_2C0650 *lp, short vram_addr, short vram_width, short psm, short x, short y, short w, short h) {
  int nloop = 0;
  switch (psm) {
  case 0: case 0x30: nloop = w * h >> 2; break;
  case 1: case 0x31: nloop = w * h * 3 >> 4; break;
  case 2: case 10: case 0x32: case 0x3a: nloop = w * h >> 3; break;
  case 0x13: case 0x1b: nloop = w * h >> 4; break;
  case 0x14: case 0x24: case 0x2c: nloop = w * h >> 5; break;
  }
  if (nloop >= 0x8000) { func_002E7940(D_0049D5F0); return 0; }
  *(u128 *)&lp->giftag1 = 0;
  *(u128 *)&lp->giftag0 = 0;
  lp->giftag1.NLOOP = nloop;
  lp->trxdir = 0;
  lp->giftag0.NLOOP = 4;
  lp->giftag1.EOP = 1;
  lp->giftag0.NREG = 1;
  lp->giftag0.REGS0 = 0xe;
  lp->bitbltbuf = (long)vram_addr << 32 | (long)vram_width << 48 | (long)psm << 56;
  lp->bitbltbufaddr = 0x50;
  lp->trxpos = (long)x << 32 | (long)y << 48;
  lp->trxposaddr = 0x51;
  lp->trxreg = (long)w | (long)h << 32;
  lp->trxregaddr = 0x52;
  lp->trxdiraddr = 0x53;
  lp->giftag1.FLG = 2;
  __asm__ volatile ("sync");
  return 6;
}

extern char D_0049D3E8_2BF8B0[] __asm__("D_0049D3E8");
long func_002E9950_2BF8B0(char *, int) __asm__("func_002E9950"); long func_002E9F90_2BF8B0(long, char *, int) __asm__("func_002E9F90"); void func_002E9BD8_2BF8B0(long) __asm__("func_002E9BD8"); long func_002DB920_2BF8B0(char *) __asm__("func_002DB920");
// MATCH func_002BF8B0
long FUN_002bf8b0(void) {
  char buf[256];
  char c;
  unsigned i;
  long fd;
  long v;
  char *p;
  fd = func_002E9950_2BF8B0(D_0049D3E8_2BF8B0, 1);
  if (fd < 0) return -1;
  i = 0;
  p = buf;
  for (; i < 0x100; i++) { func_002E9F90_2BF8B0(fd, p, 1); c = *p; p++; if (c == 0) break; }
  func_002E9BD8_2BF8B0(fd);
  v = func_002DB920_2BF8B0(&buf[i - 9]);
  return 0x1315670 < v;
}

typedef struct { long key; long m; int v; int u; } Ent_2C2008;
typedef struct { char pad[0x44]; Ent_2C2008 *tab; int n; } Cache_2C2008;
typedef struct { char pad[0x40]; Cache_2C2008 *c; } Obj_2C2008;
typedef struct { unsigned long v, m; } E_2C2008; extern E_2C2008 D_004260E0_2C2008[] __asm__("D_004260E0");
unsigned long func_002C1A68_2C2008(unsigned, long) __asm__("func_002C1A68");
// MATCH func_002C2008
int FUN_002c2008(Obj_2C2008 *o, unsigned i, long x, int v1, int v2) {
  register int r __asm__("$17") = 0;
  Cache_2C2008 *c = o->c;
  Ent_2C2008 *tab = c->tab;
  long key = func_002C1A68_2C2008(i, x);
  int idx = 0;
  int n = c->n;
  if (n > 0) {
    for (idx = 0; idx < n; idx++) {
      if (key == tab[idx].key) { r = tab[idx].v; break; }
    }
  }
  if (idx < 64) {
    Ent_2C2008 *e;
    e = &tab[idx];
    e->key = key;
    c->n = n + 1;
    e->u = v2;
    e->v = v1;
    e->m = D_004260E0_2C2008[i].m;
  }
  return r;
}

// MATCH func_002C1228
void FUN_002c1228(char *p, short x, short y, short z) {
  unsigned long d = *(unsigned long *)(p + 0x30);
  long ly = (long)y - ((unsigned long)(long)(int)((int)((d >> 48) & 0x7ff) + 1) >> 1);
  long lx = (long)x - ((unsigned long)(long)(int)((int)((d >> 16) & 0x7ff) + 1) >> 1);
  long x16 = lx * 16;
  register long y16 __asm__("$2") = ly * 16;
  unsigned long v;
  if (z != 0) v = (y16 + 8) << 32; else v = ly << 36;
  *(unsigned long *)(p + 0x20) = x16 | v;
}

unsigned long *func_002BF838_2C16B8(void) __asm__("func_002BF838");
// MATCH func_002C16B8
short FUN_002c16b8(short a, short w, short h) {
  unsigned long *p = func_002BF838_2C16B8();
  int pw = (w + 63) / 64;
  int ph;
  if ((a & 2) != 0) ph = (h + 63) / 64; else ph = (h + 31) / 32;
  if ((*p & 0xffff0000ffffUL) == 1) return pw * ph;
  return pw * ph * 2;
}

typedef unsigned long u_long_2C1780;
#define UL u_long_2C1780
typedef struct { UL testa; long testaaddr; UL prim; long primaddr; UL rgbaq; long rgbaqaddr; UL xyz2a; long xyz2aaddr; UL xyz2b; long xyz2baddr; UL testb; long testbaddr; } Clear_2C1780;
// MATCH func_002C1780
int FUN_002c1780(Clear_2C1780 *cp, short ztest, short x, short y, short w, short h, unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned z) {
  cp->testaaddr = 0x47;
  cp->testa = (UL)1 << 16 | (UL)1 << 17;
  cp->primaddr = 0;
  cp->prim = 6;
  cp->rgbaqaddr = 1;
  cp->rgbaq = (UL)r | (UL)g << 8 | (UL)b << 16 | (UL)a << 24 | (UL)0x3f800000 << 32;
  cp->xyz2a = (UL)(x << 4) | (UL)(y << 4) << 16 | (UL)z << 32;
  cp->xyz2aaddr = 5;
  cp->xyz2baddr = 5;
  cp->xyz2b = (UL)((x + w) << 4) | (UL)((y + h) << 4) << 16 | (UL)z << 32;
  cp->testbaddr = 0x47;
  if (ztest != 0) cp->testb = (UL)1 << 16 | (UL)(ztest & 3) << 17;
  else cp->testb = (UL)1 << 16 | (UL)1 << 17;
  __asm__ volatile("sync");
  return 6;
}
#undef UL

typedef unsigned long u_long_2C1888;
#define UL u_long_2C1888
typedef struct { UL b0:1; UL pad:63; } Bit_2C1888;
typedef struct { UL frame; long frameaddr; UL zbuf; long zbufaddr; UL xyoffset; long xyoffsetaddr; UL scissor; long scissoraddr; Bit_2C1888 prmodecont; long prmodecontaddr; Bit_2C1888 colclamp; long colclampaddr; Bit_2C1888 dthe; long dtheaddr; UL test; long testaddr; } DrawEnv_2C1888;
short func_002C16B8_2C1888(short, short, short) __asm__("func_002C16B8");
// MATCH func_002C1888
int FUN_002c1888(DrawEnv_2C1888 *d, short psm, short w, short h, short ztest, short zpsm) {
  d->frameaddr = 0x4d;
  d->frame = (UL)((w >> 6) & 0x3f) << 16 | (UL)(psm & 0xf) << 24;
  d->zbufaddr = 0x4f;
  if (ztest == 0) d->zbuf = (UL)func_002C16B8_2C1888(psm, w, h) | (UL)(zpsm & 0xf) << 24 | (UL)1 << 32;
  else d->zbuf = (UL)func_002C16B8_2C1888(psm, w, h) | (UL)(zpsm & 0xf) << 24;
  d->xyoffsetaddr = 0x19;
  d->xyoffset = ((UL)2048 - (short)(w >> 1)) << 4 | ((UL)2048 - (short)(h >> 1)) << 36;
  d->scissoraddr = 0x41;
  d->scissor = (UL)(w - 1) << 16 | (UL)(h - 1) << 48;
  d->prmodecontaddr = 0x1a;
  d->prmodecont.b0 = 1;
  d->colclampaddr = 0x46;
  d->colclamp.b0 = 1;
  d->dtheaddr = 0x45;
  if (psm & 2) d->dthe.b0 = 1; else d->dthe.b0 = 0;
  d->testaddr = 0x48;
  if (ztest != 0) d->test = (UL)1 << 16 | (UL)(ztest & 3) << 17;
  else d->test = (UL)1 << 16 | (UL)1 << 17;
  __asm__ volatile("sync");
  return 8;
}
#undef UL

typedef unsigned long u_long_2BFCD8;
#define UL u_long_2BFCD8
typedef struct { UL b0:1; UL pad:63; } Bit_2BFCD8;
typedef struct { UL frame; long frameaddr; UL zbuf; long zbufaddr; UL xyoffset; long xyoffsetaddr; UL scissor; long scissoraddr; Bit_2BFCD8 prmodecont; long prmodecontaddr; Bit_2BFCD8 colclamp; long colclampaddr; Bit_2BFCD8 dthe; long dtheaddr; UL test; long testaddr; } DrawEnv_2BFCD8;
short func_002C16B8_2BFCD8(short, short, short) __asm__("func_002C16B8");
// MATCH func_002BFCD8
int FUN_002bfcd8(DrawEnv_2BFCD8 *d, short psm, short w, short h, short ztest, short zpsm) {
  d->frameaddr = 0x4c;
  d->frame = (UL)(((w + 63) >> 6) & 0x3f) << 16 | (UL)(psm & 0xf) << 24;
  d->zbufaddr = 0x4e;
  if (ztest == 0) d->zbuf = (UL)func_002C16B8_2BFCD8(psm, w, h) | (UL)(zpsm & 0xf) << 24 | (UL)1 << 32;
  else d->zbuf = (UL)func_002C16B8_2BFCD8(psm, w, h) | (UL)(zpsm & 0xf) << 24;
  d->xyoffsetaddr = 0x18;
  d->xyoffset = ((UL)2048 - (short)(w >> 1)) << 4 | ((UL)2048 - (short)(h >> 1)) << 36;
  d->scissoraddr = 0x40;
  d->scissor = (UL)(w - 1) << 16 | (UL)(h - 1) << 48;
  d->prmodecontaddr = 0x1a;
  d->prmodecont.b0 = 1;
  d->colclampaddr = 0x46;
  d->colclamp.b0 = 1;
  d->dtheaddr = 0x45;
  if (psm & 2) d->dthe.b0 = 1; else d->dthe.b0 = 0;
  d->testaddr = 0x47;
  if (ztest != 0) d->test = (UL)1 << 16 | (UL)(ztest & 3) << 17;
  else d->test = (UL)1 << 16 | (UL)1 << 17;
  __asm__ volatile("sync");
  return 8;
}
#undef UL

typedef struct { int (*fn)(); int arg; } H_2C2D58;
typedef struct { char pad[12]; H_2C2D58 tab[1]; } C_2C2D58;
typedef struct { char pad[0x40]; C_2C2D58 *c; } O_2C2D58;
// MATCH func_002C2D58
int FUN_002c2d58(O_2C2D58 *o, int *msg) {
  int r = 0;
  if (o != 0) { C_2C2D58 *c = o->c; if (c != 0) { int (*fn)() = c->tab[*msg].fn; if (fn != 0) r = fn(o, msg, c->tab[*msg].arg); } }
  return r;
}

typedef struct { unsigned base; unsigned size; unsigned cur; } Heap_2C2EA8;
void func_002C35C8(void *, char *);
extern char D_0049D988[];
// MATCH func_002C2EA8
unsigned FUN_002c2ea8(void *mp, Heap_2C2EA8 *h, unsigned size, unsigned align) {
  unsigned p = (h->cur + align - 1) / align * align;
  if (h->base + h->size >= p + size) h->cur = p + size;
  else { func_002C35C8(mp, D_0049D988); p = 0; }
  return p;
}

void func_002C35C8(void *, char *);
void func_002C86F0(char *, int, int);
void func_002C8800(char *, int, int, int);
extern char D_0049DA08[];
// MATCH func_002C33D8
void FUN_002c33d8(char *o) {
  int n = *(int *)(o + 0x118);
  if (*(int *)(o + 0x120) != 0) func_002C35C8(o, D_0049DA08);
  else if (*(int *)(o + 0x174) == 3) func_002C86F0(o, *(int *)(o + 0x1bc), n - 1);
  else func_002C8800(o, *(int *)(o + 0x1cc), *(int *)(o + 0x1dc), n - 1);
  *(int *)(o + 0x120) = 0;
}

void func_002C35C8(void *, char *);
unsigned func_002C7318_2C3CD0(void *, int) __asm__("func_002C7318");
void func_002C5C38(int);
extern char D_0049DA50[];
extern char D_0049DA78[];
// MATCH func_002C3CD0
void FUN_002c3cd0(char *o) {
  unsigned v, w, t, x, b, c, s;
  *(int *)(o + 0x848) = 1;
  func_002C5C38(0);
  v = func_002C7318_2C3CD0(o, 0x1c);
  x = v >> 1 & 0xfff;
  s = v >> 17 & 3;
  b = v >> 13 & 3;
  c = v >> 15 & 3;
  *(unsigned *)(o + 0x140) = s;
  if (s != 1) func_002C35C8(o, D_0049DA50);
  *(unsigned *)(o + 0x13c) = v >> 19 & 1;
  t = v >> 20;
  w = func_002C7318_2C3CD0(o, 0x10) >> 8;
  if (t != 0x48 && t != 0x58 && t != 0x44) func_002C35C8(o, D_0049DA78);
  *(unsigned *)(o + 0x124) = c << 12 | *(unsigned *)(o + 0x124) & 0xfff;
  *(unsigned *)(o + 0x128) = b << 12 | *(unsigned *)(o + 0x128) & 0xfff;
  *(unsigned *)(o + 0x134) += x * 0x40000;
  *(unsigned *)(o + 0x138) += w * 0x400;
}

int func_002C7F50(int *, int);
int func_002C7DF0(int *);
void func_002C2DA8(char *);
void func_002C3360(char *);
int func_002C7550(int *);
void func_002C7EC0(int *, int, int);
// MATCH func_002C3200
int FUN_002c3200(char *mp, int a, int b) {
  int *d = *(int **)(mp + 0x40);
  int more = 0;
  int r;
  d[0x48] = 0;
  if (b == -1 || a < b) more = 1;
  if (d[2] == 0) { *(int *)(mp + 8) = 0; d[2] = 1; }
  if (func_002C7F50(d, 0) != 0 && more) func_002C7DF0(d);
  d[0x48] = 1;
  if (func_002C7550(d) == 0) { func_002C3360(mp); d[0] = 1; return 0; }
  { int m = 2; if (d[0x35] != 1) m = 1; if (d[0x5d] != m) return -1; }
  { int ok = 0; if (func_002C7F50(d, 1) != 0) ok = 1; r = 0; if (ok && more) { if (func_002C7DF0(d) != 0) r = 1; } }
  func_002C7EC0(d, d[0x46], d[1]);
  d[0x48] = 0;
  *(int *)(mp + 8) = d[0x46] - d[0x2b];
  d[0x46]++;
  d[1]++;
  if (!more) func_002C2DA8(mp);
  return r;
}

typedef struct { char d[0x1c]; } Ent_2C4C68;
typedef struct { char p0[4]; int w4; char p8[0x20]; void (*fa[4])(void *); void (*fb[4])(void *); Ent_2C4C68 ea[4]; Ent_2C4C68 eb[4]; int addr; int n; int full; int fld; int done; int err; } Slot_2C4C68;
typedef struct { char p[0x590]; Slot_2C4C68 s[3]; } Mp_2C4C68;
void func_002C35C8(void *, char *);
void func_002C5B78(int, int, int);
void func_002C5BD8(int, int);
extern char D_0049DBD8[];
// MATCH func_002C4C68
void FUN_002c4c68(Mp_2C4C68 *o, int i) {
  int j;
  if (o->s[i].done != 0) {
    for (j = 0; j < o->s[i].n; j++) {
      o->s[i].fa[j](&o->s[i].ea[j]);
      o->s[i].fb[j](&o->s[i].eb[j]);
    }
  }
  if (o->s[i].full != 0 && o->s[i].err != 0) func_002C35C8(o, D_0049DBD8);
  if (o->s[i].full != 0) func_002C5BD8(o->s[i].addr, o->s[i].w4);
  else if (o->s[i].err != 0) func_002C5BD8(o->s[i].addr, *(int *)((char *)o + 0x81c));
  else func_002C5B78(o->s[i].addr, *(int *)((char *)o + 0x81c), o->s[i].w4);
}

typedef struct { short interlace; short omode; short ffmode; short version; int hflag; int hid; } GParam_2BF6A8;
GParam_2BF6A8 *func_002BF838_2BF6A8(void) __asm__("func_002BF838");
void SetGsCrt_2BF6A8(int, int, int) __asm__("SetGsCrt");
unsigned long GsPutIMR_2BF6A8(unsigned long) __asm__("GsPutIMR");
void RemoveIntcHandler_2BF6A8(int, int) __asm__("RemoveIntcHandler");
void func_002E6380_2BF6A8(int) __asm__("func_002E6380");
// MATCH func_002BF6A8
void FUN_002bf6a8(short mode, short inter, short omode, short ffmode) {
  GParam_2BF6A8 *gp;
  switch (mode) {
  case 0:
    gp = func_002BF838_2BF6A8();
    *(volatile unsigned long *)0x12001000 = 0x200;
    gp->interlace = inter;
    gp->omode = omode;
    gp->version = *(volatile unsigned long *)0x12001000 >> 16 & 0xff;
    GsPutIMR_2BF6A8(0xff00);
    gp->ffmode = ffmode != 0;
    if (gp->hflag != 0) {
      func_002E6380_2BF6A8(2);
      RemoveIntcHandler_2BF6A8(2, gp->hid);
      gp->hflag = 0;
      gp->hid = 0;
    }
    SetGsCrt_2BF6A8(inter & 1, omode & 0xff, ffmode & 1);
    break;
  case 1:
    *(volatile unsigned long *)0x12001000 = 0x100;
    break;
  case 5:
    gp = func_002BF838_2BF6A8();
    gp->ffmode = ffmode != 0;
    gp->interlace = inter;
    gp->omode = omode;
    gp->version = *(volatile unsigned long *)0x12001000 >> 16 & 0xff;
    SetGsCrt_2BF6A8(inter & 1, omode & 0xff, ffmode & 1);
    break;
  }
}

typedef struct { unsigned long v, m; } E_2C1AF0; extern E_2C1AF0 D_004260E0_2C1AF0[] __asm__("D_004260E0");
// MATCH func_002C1AF0
int FUN_002c1af0(unsigned *idx, unsigned *val, unsigned long key) {
  int found = 0;
  unsigned i;
  unsigned long m, v, mk, b;
  for (i = 0; i < 10 && !found; i++) {
    m = D_004260E0_2C1AF0[i].m;
    switch (m) {
    case 0xffffffffffUL:
      mk = key & 0xffffff0000UL;
      if (mk == D_004260E0_2C1AF0[i].v) { *idx = i; *val = key & 0xffff; found = 1; }
      break;
    case 0xffff000000UL:
      v = D_004260E0_2C1AF0[i].v;
      switch (v) {
      case 0xbd20000000UL: mk = key & 0xffe0000000UL; b = 0x1f; break;
      case 0xbd80000000UL: case 0xbd88000000UL: case 0xbd90000000UL: case 0xbda0000000UL: mk = key & 0xfff8000000UL; b = 7; break;
      default: mk = key & 0xffff000000UL; b = 0; break;
      }
      if (mk == v) { *idx = i; *val = (key >> 24) & b; found = 1; }
      break;
    case 0xff00000000UL:
      v = D_004260E0_2C1AF0[i].v;
      if (v == 0xe000000000UL) { mk = key & 0xf000000000UL; b = 0xf; }
      else if (v == 0xc000000000UL) { mk = key & 0xe000000000UL; b = 0x1f; }
      else { mk = key & m; b = 0; }
      if (mk == v) { *idx = i; *val = (key >> 32) & b; found = 1; }
      break;
    }
  }
  return found;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
int func_002C7318_2C7660(char *, int) __asm__("func_002C7318");
void func_002C7A40(char *);
void func_002C7728(char *);
void func_002C7A88(char *, int);
// MATCH func_002C7660
void FUN_002c7660(char *o) {
  int t = func_002C7318_2C7660(o, 10);
  W(o, 0x150) = func_002C7318_2C7660(o, 3);
  func_002C7318_2C7660(o, 0x10);
  if ((unsigned)(W(o, 0x150) - 2) < 2) {
    W(o, 0x154) = func_002C7318_2C7660(o, 1);
    W(o, 0x158) = func_002C7318_2C7660(o, 3);
  }
  if (W(o, 0x150) == 3) {
    W(o, 0x15c) = func_002C7318_2C7660(o, 1);
    W(o, 0x160) = func_002C7318_2C7660(o, 3);
  }
  func_002C7A40(o);
  func_002C7728(o);
  func_002C7A88(o, t);
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
void func_002C35C8(void *, char *);
int func_002C6118(char *);
extern char D_0049DDA8[];
extern char D_0049DDC8[];
// MATCH func_002C7DF0
int FUN_002c7df0(char *o) {
  char *b;
  int r;
  if (W(o, 0x174) == 3 && W(o, 0x120) != 0) { func_002C35C8(o, D_0049DDA8); W(o, 0x120) = 0; }
  switch (W(o, 0x174)) {
  case 3: b = *(char **)(o + 0x1c0); break;
  case 1: b = *(char **)(o + 0x1d0); break;
  case 2: b = *(char **)(o + 0x1e0); break;
  default: b = *(char **)(o + 0x1c0); func_002C35C8(o, D_0049DDC8); break;
  }
  r = func_002C6118(o);
  if (r != 0) W(b, 0x28) = 1;
  return r;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
// MATCH func_002C7A88
void FUN_002c7a88(char *o, int tr) {
  int wrap = 0;
  int d = 0;
  if (W(o, 0x150) != 3 && tr != 0) {
    if (tr < 0) wrap = W(o, 0x854) == 0;
    W(o, 0x854) = 0;
    d = tr;
  }
  W(o, 0x1ac) = W(o, 0x84c) + tr;
  if (wrap && d >= tr) W(o, 0x1ac) += 0x400;
  { int m = W(o, 0x850); if (m < W(o, 0x1ac)) m = W(o, 0x1ac); W(o, 0x850) = m; }
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
int func_002C6350(char *, int);
void func_002C6E50(char *);
int func_002C5C60(char *);
void func_002C4C68(char *, int);
void func_002C35C8(void *, char *);
extern char D_0049DC48[];
// MATCH func_002C6118
int FUN_002c6118(char *o) {
  int n;
  int r;
  W(o, 0x810) = 0;
  n = W(o, 300) * W(o, 0x130);
  W(o, 0x814) = 0;
  if (W(o, 0x174) != 3) n >>= 1;
  do r = func_002C6350(o, n); while (r == 1 || r == 3);
  func_002C6E50(o);
  if (func_002C5C60(o) == 0) r = 2;
  while (*(volatile unsigned *)0x1000d400 >> 8 & 1);
  if (r == 0) func_002C4C68(o, W(o, 0x810) == 0);
  if ((unsigned)(r - 1) < 2) func_002C35C8(o, D_0049DC48);
  return r == 0;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
typedef struct { int type; int pad; long a; long b; } Msg_2C7550;
void func_002C7468(char *);
unsigned func_002C7318_2C7550(char *, int) __asm__("func_002C7318");
void func_002C3740(char *);
void func_002C7660(char *);
void func_002C7B00(char *);
int func_002C2D58_2C7550(int, Msg_2C7550 *) __asm__("func_002C2D58");
// MATCH func_002C7550
int FUN_002c7550(char *o) {
  unsigned c;
  Msg_2C7550 m;
  for (;;) {
    func_002C7468(o);
    c = func_002C7318_2C7550(o, 0x20);
    switch (c) {
    case 0x1b3:
      func_002C3740(o);
      break;
    case 0x1b7:
      return 0;
    case 0x1b8:
      func_002C7B00(o);
      break;
    case 0x100:
      func_002C7660(o);
      m.type = 5;
      m.a = -1;
      m.b = -1;
      func_002C2D58_2C7550(W(o, 0x858), &m);
      *(long *)(o + 0x828) = m.a;
      *(long *)(o + 0x830) = m.b;
      return W(o, 0x150);
    }
  }
}

// MATCH func_002C6AA8
void FUN_002c6aa8(int *pmv, unsigned r_size, int motion_code, int motion_r, int full_pel) {
  int lim = 16 << r_size;
  int vec = full_pel ? *pmv >> 1 : *pmv;
  if (motion_code > 0) {
    vec += ((motion_code - 1) << r_size) + motion_r + 1;
    if (vec >= lim) vec -= lim + lim;
  } else if (motion_code < 0) {
    vec -= ((-motion_code - 1) << r_size) + motion_r + 1;
    if (vec < -lim) vec += lim + lim;
  }
  *pmv = full_pel ? vec << 1 : vec;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
void func_002C3590(void *, char *, unsigned);
void func_002C7228(char *, int);
unsigned func_002C7120(char *, int);
void func_002C35C8(void *, char *);
void func_002C7468(char *);
int func_002C74E8(char *);
int func_002C6008(char *);
extern char D_0049DC90[];
extern char D_0049DC68[];
// MATCH func_002C6220
int FUN_002c6220(char *o, int unused, int *mb, int *inc, int *blk) {
  int slice, n;
  unsigned code;
  W(o, 0x11c) = 0;
  func_002C7468(o);
  code = func_002C7120(o, 0x20);
  if (code - 0x101 >= 0xaf) { func_002C3590(o, D_0049DC68, code); return 2; }
  func_002C7228(o, 0x20);
  slice = func_002C74E8(o);
  *inc = n = func_002C6008(o);
  if (W(o, 0x11c) != 0) { func_002C35C8(o, D_0049DC90); return 1; }
  *mb = (slice * 0x80 + (code & 0xff) - 1) * W(o, 300) + n - 1;
  *inc = 1;
  W(o, 0x1b0) = 1;
  blk[5] = 0; blk[4] = 0; blk[1] = 0; blk[0] = 0; blk[7] = 0; blk[6] = 0; blk[3] = 0; blk[2] = 0;
  return 0;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
typedef struct { char p[0x10]; int a; int p14; long b; long c; } Mp_2C86F0;
void func_002C8560(char *, char *, int *, long *, long *);
int func_002C8208_2C86F0(char *, char *) __asm__("func_002C8208");
void func_002C82A8(char *, char *);
void func_002C90A8(char *);
void func_002C8538(char *);
extern unsigned D_004262A8[];
// MATCH func_002C86F0
void FUN_002c86f0(char *o, char *pic) {
  Mp_2C86F0 *m = *(Mp_2C86F0 **)(o + 0x858);
  func_002C8560(o, pic, &m->a, &m->b, &m->c);
  W(o, 0x80) = (*(Mp_2C86F0 **)(o + 0x858))->a;
  *(unsigned long *)(o + 0x88) = D_004262A8[(int)((*(Mp_2C86F0 **)(o + 0x858))->c >> 5) & 0xf];
  W(o, 0xcc) = W(pic, 0x5c);
  W(o, 0xd0) = W(pic, 0x60);
  W(o, 0xb4) = W(pic, 0x44);
  W(o, 0xb8) = W(pic, 0x48);
  W(o, 0xbc) = W(pic, 0x4c);
  W(o, 0xc0) = W(pic, 0x50);
  W(o, 0xc4) = W(pic, 0x54);
  W(o, 0xc8) = W(pic, 0x58);
  if (func_002C8208_2C86F0(o, pic) != 0 && W(pic, 0x28) == 1) {
    if (W(o, 0xb0) != 0) func_002C90A8(o);
    else func_002C82A8(o, pic);
    func_002C8538(o);
  }
}

typedef struct { char d[0x13c]; int err; } Slot_2C6540;
typedef struct { char p0[0x150]; int ptype; char p154[0x20]; int pstruct; char p178[0x38]; int x1b0; char p1b4[0x3dc]; Slot_2C6540 s[2]; int cur; } Mp_2C6540;
void func_002C35C8(void *, char *);
extern char D_0049DCD0[];
// MATCH func_002C6540
int FUN_002c6540(Mp_2C6540 *o, int *pmv, int *mvfs, int *dmv, int *cbp) {
  int r = 1;
  o->s[o->cur].err = 1;
  o->x1b0 = 1;
  if (o->ptype == 2) { pmv[0] = pmv[1] = pmv[4] = pmv[5] = 0; }
  if (o->pstruct == 3) *mvfs = 2;
  else { *mvfs = 1; dmv[0] = dmv[1] = o->pstruct == 2; }
  if (o->ptype == 1) { func_002C35C8(o, D_0049DCD0); r = 0; }
  *cbp &= ~1;
  return r;
}

#define W(o, n) (*(int *)((char *)(o) + (n)))
#define H_2C5E80(x) ((x) > 0 ? ((x) + 1) >> 1 : (x) >> 1)
#define T_2C5E80(x) ((x) * 3 + ((x) > 0 ? 1 : 0)) >> 1
// MATCH func_002C5E80
void FUN_002c5e80(char *o, int *dmv, int *mv, int dx, int dy) {
  if (W(o, 0x174) == 3) {
    if (W(o, 0x178) != 0) {
      dmv[0] = H_2C5E80(dx) + mv[0];
      dmv[1] = H_2C5E80(dy) + mv[1] - 1;
      dmv[2] = (T_2C5E80(dx)) + mv[0];
      dmv[3] = (T_2C5E80(dy)) + mv[1] + 1;
    } else {
      dmv[0] = (T_2C5E80(dx)) + mv[0];
      dmv[1] = (T_2C5E80(dy)) + mv[1] - 1;
      dmv[2] = H_2C5E80(dx) + mv[0];
      dmv[3] = H_2C5E80(dy) + mv[1] + 1;
    }
  } else {
    dmv[0] = H_2C5E80(dx) + mv[0];
    dmv[1] = H_2C5E80(dy) + mv[1];
    if (W(o, 0x174) == 1) dmv[1] = dmv[1] - 1;
    else dmv[1] = dmv[1] + 1;
  }
}

typedef struct { unsigned long buf; int p8; unsigned char *ptr; unsigned bits; int p14; long p18; unsigned char *start; unsigned char *end; } Bs_2C9388;
// MATCH func_002C9388
void FUN_002c9388(Bs_2C9388 *bs, int n) {
  bs->buf <<= n;
  bs->bits -= n;
  while (bs->bits < 57) {
    bs->buf |= (unsigned long)*bs->ptr++ << (56 - bs->bits);
    if (bs->ptr >= bs->end) bs->ptr = bs->start;
    bs->bits += 8;
  }
  bs->p18 += n;
}

typedef struct { unsigned long buf; unsigned base; unsigned ptr; unsigned bits; int p14; long pos; unsigned start; unsigned end; int size; } Bs_2C94B8;
void func_002C9388_2C94B8(Bs_2C94B8 *, int) __asm__("func_002C9388");
// MATCH func_002C94B8
void FUN_002c94b8(Bs_2C94B8 *bs, int byte) {
  unsigned p;
  long pos = (long)(byte << 3) + bs->pos;
  bs->buf = 0;
  bs->bits = 0;
  bs->pos = pos;
  p = bs->base + (int)(pos >> 3);
  bs->ptr = p;
  if (p >= bs->end) bs->ptr = p - bs->size;
  func_002C9388_2C94B8(bs, 0);
}

typedef struct { int p0; int buf; int addr; int id; int c; int d; int e; } Port_2C9798;
typedef struct { int cmd; int p4; int p8; int result; int unit; } Rpc_2C9798;
extern Port_2C9798 D_0062B3D0_2C9798[2][4] __asm__("D_0062B3D0");
extern Rpc_2C9798 D_0062B5C0_2C9798 __asm__("D_0062B5C0");
extern char D_0062B380_2C9798[] __asm__("D_0062B380");
int func_002E8928_2C9798(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002C9798
int FUN_002c9798(void) {
  int i;
  for (i = 0; i < 4; i++) {
    D_0062B3D0_2C9798[0][i].c = 0;
    D_0062B3D0_2C9798[0][i].e = 0;
    D_0062B3D0_2C9798[0][i].d = 0;
    D_0062B3D0_2C9798[1][i].c = 0;
    D_0062B3D0_2C9798[1][i].e = 0;
    D_0062B3D0_2C9798[1][i].d = 0;
  }
  D_0062B5C0_2C9798.cmd = 16;
  D_0062B5C0_2C9798.unit = 0;
  if (func_002E8928_2C9798(D_0062B380_2C9798, 1, 0, &D_0062B5C0_2C9798, 128, &D_0062B5C0_2C9798, 128, 0, 0) < 0) return 0;
  return D_0062B5C0_2C9798.result;
}

typedef struct { char p[36]; int serve; } Client_2C9658;
extern Client_2C9658 D_0062B380_2C9658[2] __asm__("D_0062B380");
extern int D_004262F8[];
extern int D_004262FC[];
extern char D_0049DE78[];
extern char D_0049DEA0[];
int sceSifBindRpc_2C9658(Client_2C9658 *, unsigned, int) __asm__("func_002E8758");
int func_002CA808(void);
int func_002C9798_2C9658(int) __asm__("func_002C9798");
void func_002E7940(char *, ...);
// MATCH func_002C9658
int FUN_002c9658(int mode) {
  int i, v;
  D_004262F8[0] = 1;
  for (;;) {
    sceSifBindRpc_2C9658(&D_0062B380_2C9658[0], 0x80000100, 0);
    if (D_0062B380_2C9658[0].serve != 0) break;
    i = 0x10000;
    while (i-- != 0);
  }
  for (;;) {
    sceSifBindRpc_2C9658(&D_0062B380_2C9658[1], 0x80000101, 0);
    if (D_0062B380_2C9658[1].serve != 0) break;
    i = 0x10000;
    while (i-- != 0);
  }
  v = func_002CA808();
  if (v >> 8 != 4) {
    if (D_004262FC[0] != 0) {
      func_002E7940(D_0049DE78);
      func_002E7940(D_0049DEA0, 4, 0, v >> 8, v & 0xff);
    }
    return 0;
  }
  return func_002C9798_2C9658(mode);
}

typedef struct { int p0; int buf; int addr; int id; int open; int d; int e; } Port_2C9E28;
extern Port_2C9E28 D_0062B3D0_2C9E28[2][4] __asm__("D_0062B3D0");
typedef struct { unsigned char a, b, c, d; } Act_2C9E28;
typedef struct { char p0[0x30]; Act_2C9E28 act[8]; char p50[0x14]; unsigned char cnt; char p65[5]; unsigned char nact; unsigned char ncomb; char p6c[6]; unsigned char ok; } Pad_2C9E28;
Pad_2C9E28 *func_002C9B58_2C9E28(int, int) __asm__("func_002C9B58");
// MATCH func_002C9E28
int FUN_002c9e28(int port, int slot, int actno, int term) {
  Pad_2C9E28 *p;
  if (D_0062B3D0_2C9E28[port][slot].open == 0) return 0;
  p = func_002C9B58_2C9E28(port, slot);
  if (p->ok != 1) return 0;
  if (p->cnt < 2) return 0;
  if (actno >= p->nact) return 0;
  if (actno == -1) return p->nact;
  switch (term) {
  case 1: return p->act[actno].a;
  case 2: return p->act[actno].b;
  case 3: return p->act[actno].c;
  case 4: return p->act[actno].d;
  }
  return 0;
}

typedef struct { int p0; int buf; int addr; int id; int open; int d; int e; } Port_2C9F48;
extern Port_2C9F48 D_0062B3D0_2C9F48[2][4] __asm__("D_0062B3D0");
typedef struct { unsigned char a, b, c, d; } Comb_2C9F48;
typedef struct { char p0[0x40]; Comb_2C9F48 comb[4]; char p50[0x14]; unsigned char cnt; char p65[5]; unsigned char nact; unsigned char ncomb; char p6c[6]; unsigned char ok; } Pad_2C9F48;
Pad_2C9F48 *func_002C9B58_2C9F48(int, int) __asm__("func_002C9B58");
// MATCH func_002C9F48
int FUN_002c9f48(int port, int slot, int listno, int offs) {
  Pad_2C9F48 *p;
  if (D_0062B3D0_2C9F48[port][slot].open == 0) return 0;
  p = func_002C9B58_2C9F48(port, slot);
  if (p->ok != 1) return 0;
  if (p->cnt < 2) return 0;
  if (listno == -1) return p->ncomb;
  if (listno >= p->ncomb) return 0;
  switch (offs) {
  case -1: return p->comb[listno].a;
  case 0: return p->comb[listno].b;
  case 1: return p->comb[listno].c;
  case 2: return p->comb[listno].d;
  }
  return 0;
}

typedef struct { int p0; int buf; int addr; int id; int open; int d; int e; } Port_2CA068;
extern Port_2CA068 D_0062B3D0_2CA068[2][4] __asm__("D_0062B3D0");
typedef struct { char p0[0x50]; unsigned short modes[10]; unsigned char cnt; unsigned char id; char p66[2]; unsigned char nmodes; unsigned char curmode; char p6a[7]; unsigned char stat; unsigned char ok; } Pad_2CA068;
Pad_2CA068 *func_002C9B58_2CA068(int, int) __asm__("func_002C9B58");
// MATCH func_002CA068
int FUN_002ca068(int port, int slot, int term, int offs) {
  Pad_2CA068 *p;
  if (D_0062B3D0_2CA068[port][slot].open == 0) return 0;
  p = func_002C9B58_2CA068(port, slot);
  if (p->ok != 1) return 0;
  if (p->stat == 2) return 0;
  switch (term) {
  case 1:
    if (p->id != 0xf3) return p->id >> 4;
    return 0;
  case 2:
    if (p->cnt == 1) return 0;
    return p->modes[p->curmode];
  case 3:
    if (p->cnt == 1) return 0;
    return p->curmode;
  case 4:
    if (p->cnt == 1) return 0;
    if (offs == -1) return p->nmodes;
    if (offs >= p->nmodes) return 0;
    return p->modes[offs];
  }
  return 0;
}

typedef struct { char p0[4]; int pc; char p8[0x1e]; unsigned short vol; unsigned short mode; unsigned short pan; } Trk_2D3108;
char *func_002CFFA0_2D3108(void) __asm__("func_002CFFA0");
// MATCH func_002D3108
void FUN_002d3108(Trk_2D3108 *t) {
  char *g = func_002CFFA0_2D3108();
  switch (t->mode) {
  case 1:
    t->pan = *(unsigned char *)(*(char **)(g + 0x10) + 2);
    break;
  case 0:
    t->vol = *(unsigned char *)(*(char **)(g + 0x10) + 2);
    t->pan = 0;
    break;
  case 2:
    t->pan = *(unsigned char *)(*(char **)(g + 0x10) + 2);
    break;
  }
  t->pc += 3;
}

typedef struct { char p0[4]; int pc; char *base; char pc_[4]; int tick; char p14[10]; unsigned short tempo; unsigned short reso; } Trk_2D2290;
char *func_002CFF38_2D2290(void) __asm__("func_002CFF38");
// MATCH func_002D2290
void FUN_002d2290(Trk_2D2290 *t) {
  unsigned char *p = (unsigned char *)t->base + t->pc;
  char *g = func_002CFF38_2D2290();
  t->tempo = p[2] | p[3] << 8;
  t->tick = (int)(t->reso * t->tempo * 0x1000) / *(unsigned short *)(g + 0x3a) / 60;
  t->pc += 4;
}

typedef struct { volatile unsigned flags; int w4; char p8[0xc]; int w14; char p18[0xe]; unsigned short vol; char p28[0x24]; unsigned short id; char p4e[2]; unsigned char ch; unsigned char cur; char p52[6]; } Vc_2D21C0;
Vc_2D21C0 *func_002CFF08_2D21C0(int) __asm__("func_002CFF08");
// MATCH func_002D21C0
void FUN_002d21c0(Vc_2D21C0 *v) {
  Vc_2D21C0 *p = func_002CFF08_2D21C0(0);
  int i;
  if (v->flags & 4) { v->w14 = 0; v->flags &= ~0x1008; }
  else { v->w4 = 0x110; v->flags &= ~2; }
  v->flags |= 0x40;
  for (i = 0; i < 48; i++) {
    if (p->ch == v->id && p->cur == 1) { p->flags &= ~0x10; p->vol = 0x40; }
    p++;
  }
  v->cur = v->ch;
}

char *func_002CFF38_2D3A98(void) __asm__("func_002CFF38");
char *func_002CFFB0_2D3A98(void) __asm__("func_002CFFB0");
// MATCH func_002D3A98
int FUN_002d3a98(int mode) {
  int r = -1;
  char *a = func_002CFF38_2D3A98();
  char *b = func_002CFFB0_2D3A98();
  if (mode != 0) {
    if (mode == 1) {
      while (*(volatile int *)(b + 0x1c0) != *(volatile int *)(a + 0x48));
      r = 1;
    }
  } else r = *(volatile int *)(b + 0x1c0) == *(volatile int *)(a + 0x48);
  return r;
}

typedef struct { char p[36]; int serve; } Client_2D3810;
extern Client_2D3810 D_00631A80_2D3810 __asm__("D_00631A80");
void FlushCache_2D3810(int) __asm__("FlushCache");
void func_002E80E8(int);
int sceSifBindRpc_2D3810(Client_2D3810 *, unsigned, int) __asm__("func_002E8758");
// MATCH func_002D3810
int FUN_002d3810(void) {
  int i;
  FlushCache_2D3810(0);
  func_002E80E8(0);
  do {
    if (sceSifBindRpc_2D3810(&D_00631A80_2D3810, 0x736e646e, 0) < 0) return -1;
    for (i = 10000; i > 0; i--);
  } while (D_00631A80_2D3810.serve == 0);
  return 0;
}

typedef struct { unsigned char *p0; unsigned char *p4; unsigned char *p8; } G_2D2130;
G_2D2130 *func_002CFFA0_2D2130(void) __asm__("func_002CFFA0");
// MATCH func_002D2130
int FUN_002d2130(int a, int b) {
  G_2D2130 *g = func_002CFFA0_2D2130();
  int v;
  unsigned char *e;
  g->p4 += a * 16;
  e = g->p8 + b * 16;
  v = e[20] + g->p4[12] - 128;
  v += g->p0[2];
  g->p4 -= a * 16;
  if (v > 127) v = 127;
  if (v < 0) v = 0;
  return v;
}

typedef struct { unsigned flags; unsigned age; char p8[0x49]; unsigned char state; char p52[6]; } Vc_2D1900;
Vc_2D1900 *func_002CFF08_2D1900(int) __asm__("func_002CFF08");
char *func_002CFF38_2D1900(void) __asm__("func_002CFF38");
// MATCH func_002D1900
int FUN_002d1900(void) {
  int best = -1;
  int min = -1;
  char *g = func_002CFF38_2D1900();
  int i, v;
  Vc_2D1900 *p;
  for (i = 0; i < 48; i++) {
    v = *(unsigned *)(g + 0x30) % 48;
    p = func_002CFF08_2D1900(v);
    if (!(p->flags & 0x100) && p->state == 0) return v;
    (*(unsigned *)(g + 0x30))++;
  }
  for (i = 0; i < 48; i++) {
    v = *(unsigned *)(g + 0x30) % 48;
    p = func_002CFF08_2D1900(v);
    if (!(p->flags & 0x100) && p->state == 1 && p->age < min) { best = v; min = p->age; }
    (*(unsigned *)(g + 0x30))++;
  }
  return best;
}

typedef struct { int bank; unsigned size; int type; } Bank_2D3B98;
typedef struct { char p0[0xc]; int magic; int o10; int o14; int o18; int o1c; int o20; int o24; char p28[8]; int p30; char p34[4]; int p38; int p3c; int p40; int p44; char p48[0x34]; unsigned x7c; } Hdr_2D3B98;
Bank_2D3B98 *func_002CFF48_2D3B98(int) __asm__("func_002CFF48");
// MATCH func_002D3B98
int SndBankRegister(Hdr_2D3B98 *h, unsigned size) {
  int r = -1;
  int i;
  Bank_2D3B98 *b = func_002CFF48_2D3B98(1);
  if (h->magic != 0x64685353) return -1;
  for (i = 1; i < 128; i++) {
    if (b->type == 0) {
      if (h->x7c == 0xffffffff) { b->type = 3; b->size = size >> 3; }
      else { b->type = 4; b->size = size >> 4; }
      b->bank = (int)h;
      r = i;
      h->p30 = h->o10 + (int)h;
      h->p38 = h->o18 + (int)h;
      h->p3c = h->o1c + (int)h;
      h->p40 = h->o20 + (int)h;
      h->p44 = h->o24 + (int)h;
      break;
    }
    b++;
  }
  return r;
}

typedef struct { volatile unsigned flags; unsigned age; char p8[0x48]; unsigned char ch; unsigned char state; char p52[6]; } Vc_2D4B20;
typedef struct { volatile unsigned flags; } Trk_2D4B20;
Vc_2D4B20 *func_002CFF08_2D4B20(int) __asm__("func_002CFF08");
Trk_2D4B20 *func_002CFF20_2D4B20(unsigned) __asm__("func_002CFF20");
char *func_002CFF38_2D4B20(void) __asm__("func_002CFF38");
int SndVoiceSetParam_2D4B20(int, int, int, int) __asm__("SndVoiceSetParam");
// MATCH func_002D4B20
void FUN_002d4b20(unsigned arg) {
  unsigned ch = arg & 0x7fff;
  if (ch < 48) {
    Trk_2D4B20 *t = func_002CFF20_2D4B20(ch);
    t->flags |= 0x2000;
    if (t->flags & 4) {
      Vc_2D4B20 *p = func_002CFF08_2D4B20(0);
      int i = 0;
      char *g = func_002CFF38_2D4B20();
      t->flags &= ~0x88;
      t->flags |= 0x40;
      for (; i < 48; i++) {
        if (p->state == 2 && p->ch == ch) {
          if (arg & 0x8000) SndVoiceSetParam_2D4B20(2, i, 0, 0);
          *(unsigned long *)(g + 0x28) |= 1L << i;
        }
        p++;
      }
    }
    t->flags &= ~0x2000;
  }
}

typedef struct { volatile unsigned flags; char p4[0x4c]; unsigned char ch; unsigned char state; char p52[2]; unsigned char bank; unsigned char b55; unsigned char b56; char p57; } Vc_2D3C90;
typedef struct { volatile unsigned flags; char p4[0x50]; } Trk_2D3C90;
char *func_002CFF48_2D3C90(unsigned) __asm__("func_002CFF48");
Vc_2D3C90 *func_002CFF08_2D3C90(int) __asm__("func_002CFF08");
Trk_2D3C90 *func_002CFF20_2D3C90(int) __asm__("func_002CFF20");
char *func_002CFF38_2D3C90(void) __asm__("func_002CFF38");
void *memset_2D3C90(void *, int, unsigned) __asm__("func_002DC804");
// MATCH func_002D3C90
int FUN_002d3c90(unsigned bank) {
  int r = -1;
  if (bank - 1 < 127) {
    char *b = func_002CFF48_2D3C90(bank);
    if (*(int *)(b + 8) != 0) {
      int i;
      Vc_2D3C90 *p = func_002CFF08_2D3C90(0);
      for (i = 0; i < 48; i++) {
        if (p->bank == bank && p->ch < 48 && p->state != 3) {
          Trk_2D3C90 *t = func_002CFF20_2D3C90(p->ch);
          char *g = func_002CFF38_2D3C90();
          unsigned f = t->flags;
          *(unsigned long *)(g + 0x28) |= 1L << i;
          t->flags = f | 0x2000;
          memset_2D3C90((char *)t + 4, 0, 0x50);
          t->flags = 0;
          p->flags |= 0x100;
          memset_2D3C90((char *)p + 4, 0, 0x54);
          p->ch = 0xff;
          p->b56 = 0xff;
          p->b55 = 0xff;
          p->bank = 0xff;
          p->flags = 0;
        }
        p++;
      }
    }
    memset_2D3C90(b, 0, 12);
    r = 0;
  }
  return r;
}

typedef struct { volatile unsigned flags; char p4[0x14]; unsigned short bank; } Trk_2D4818;
Trk_2D4818 *func_002CFF20_2D4818(unsigned) __asm__("func_002CFF20");
char **func_002CFF48_2D4818(int) __asm__("func_002CFF48");
// MATCH func_002D4818
int FUN_002d4818(unsigned ch, int vol) {
  int r = -1;
  if (ch < 48 && vol >= 0 && vol < 128) {
    Trk_2D4818 *t = func_002CFF20_2D4818(ch);
    t->flags |= 0x2000;
    if ((t->flags & 5) == 1) {
      char *h = *func_002CFF48_2D4818(t->bank);
      unsigned short *tab = (unsigned short *)(h + *(int *)(h + 0x10));
      int i = 0;
      if (*tab + 1 != 0) {
        unsigned short *p = tab + 1;
        do {
          i++;
          *((char *)tab + *p + 2) = vol;
          p++;
        } while (i < *tab + 1);
      }
      r = 0;
    }
    t->flags &= ~0x2000;
  }
  return r;
}

typedef struct { volatile unsigned flags; char p4[0x4a]; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_2D2BB0;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; volatile unsigned short trk; } Trk_2D2BB0;
typedef struct { char p[10]; unsigned char pb; unsigned char sus; char q[4]; } Ch_2D2BB0;
typedef struct { char p[16]; Ch_2D2BB0 ch[16]; } Hd_2D2BB0;
typedef struct { char p0[8]; Hd_2D2BB0 *chtab; char pc[4]; unsigned char *ev; } Sq_2D2BB0;
Vc_2D2BB0 *func_002CFF08_2D2BB0(int) __asm__("func_002CFF08");
char *func_002CFF38_2D2BB0(void) __asm__("func_002CFF38");
Sq_2D2BB0 *func_002CFFA0_2D2BB0(void) __asm__("func_002CFFA0");
// MATCH func_002D2BB0
void FUN_002d2bb0(Trk_2D2BB0 *t) {
  Vc_2D2BB0 *p = func_002CFF08_2D2BB0(0);
  char *g = func_002CFF38_2D2BB0();
  Sq_2D2BB0 *s = func_002CFFA0_2D2BB0();
  int i;
  s->chtab->ch[t->trk].sus = s->ev[1];
  if (s->ev[1] == 0) {
    unsigned short trk = *(unsigned short *)&t->trk;
    for (i = 0; i < 48; i++) {
      if (p->trk == trk && p->key == t->key && p->ch == t->ch && (p->flags & 4)) {
        if (s->chtab->ch[t->trk].sus == 0) *(unsigned long *)(g + 0x28) |= 1L << i;
        else p->flags |= 8;
      }
      p++;
    }
  }
  t->pc += 3;
}

typedef struct { volatile unsigned flags; char p4[0x20]; short note; unsigned short vol; unsigned short pan; unsigned short pitch; char p2c[0x22]; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_2D32C8;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_2D32C8;
typedef struct { char p[10]; unsigned char pb; unsigned char sus; char q[4]; } Ch_2D32C8;
typedef struct { char p[16]; Ch_2D32C8 ch[16]; } Hd_2D32C8;
typedef struct { char p0[8]; Hd_2D32C8 *chtab; char pc[4]; unsigned char *ev; } Sq_2D32C8;
Vc_2D32C8 *func_002CFF08_2D32C8(int) __asm__("func_002CFF08");
Sq_2D32C8 *func_002CFFA0_2D32C8(void) __asm__("func_002CFFA0");
int SndVoiceSetPitch_2D32C8(int, int, int, int, int, int, int) __asm__("SndVoiceSetPitch");
// MATCH func_002D32C8
void FUN_002d32c8(Trk_2D32C8 *t) {
  Vc_2D32C8 *p = func_002CFF08_2D32C8(0);
  Sq_2D32C8 *s = func_002CFFA0_2D32C8();
  int i;
  s->chtab->ch[t->trk].pb = s->ev[1];
  for (i = 0; i < 48; i++) {
    if (p->trk == t->trk && p->key == t->key && p->ch == t->ch && p->state == 1) {
      p->vol = s->ev[1];
      SndVoiceSetPitch_2D32C8(i, p->pitch, p->prio, p->note, s->chtab->ch[t->trk].pb, p->pan, 0x1000);
    }
    p++;
  }
  t->pc += 2;
}

typedef struct { volatile unsigned flags; char p4[0xe]; unsigned short x12; unsigned short x14; char p16[0x16]; unsigned short note; char p2e[0x16]; float x44; char p48[4]; short x4c; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_002D23B0;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_002D23B0;
typedef struct { char p[9]; unsigned char vol; unsigned char pb; unsigned char sus; unsigned char x1c; char q[3]; } Ch_002D23B0;
typedef struct { char p[16]; Ch_002D23B0 ch[16]; } Hd_002D23B0;
typedef struct { char p0[8]; Hd_002D23B0 *chtab; char pc[4]; unsigned char *ev; } Sq_002D23B0;
Vc_002D23B0 *func_002CFF08_002D23B0(int) __asm__("func_002CFF08");
char *func_002CFF38_002D23B0(void) __asm__("func_002CFF38");
Sq_002D23B0 *func_002CFFA0_002D23B0(void) __asm__("func_002CFFA0");
// MATCH func_002D23B0
void FUN_002d23b0(Trk_002D23B0 *t) {
  Vc_002D23B0 *p = func_002CFF08_002D23B0(0);
  Sq_002D23B0 *s = func_002CFFA0_002D23B0();
  int i;
  if (t->flags & 8) {
    for (i = 0; i < 48; i++) {
      if (p->state == 2) {
        unsigned char *e = s->ev;
        if (p->note == e[3] && p->prio == e[4] && p->key == t->key && p->ch == t->ch) { p->x12 = e[2]; p->flags |= 0x10; }
      }
      p++;
    }
    t->pc += 5;
  } else {
    s->chtab->ch[t->trk].vol = s->ev[2];
    for (i = 0; i < 48; i++) {
      if (p->trk == t->trk && p->key == t->key && p->ch == t->ch && p->state == 1) { p->x12 = s->ev[2]; p->flags |= 0x10; }
      p++;
    }
    t->pc += 3;
  }
}

typedef struct { volatile unsigned flags; char p4[0xe]; unsigned short x12; unsigned short x14; char p16[0x16]; unsigned short note; char p2e[0x16]; float x44; char p48[4]; short x4c; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_002D2688;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_002D2688;
typedef struct { char p[9]; unsigned char vol; unsigned char pb; unsigned char sus; unsigned char x1c; char q[3]; } Ch_002D2688;
typedef struct { char p[16]; Ch_002D2688 ch[16]; } Hd_002D2688;
typedef struct { char p0[8]; Hd_002D2688 *chtab; char pc[4]; unsigned char *ev; } Sq_002D2688;
Vc_002D2688 *func_002CFF08_002D2688(int) __asm__("func_002CFF08");
char *func_002CFF38_002D2688(void) __asm__("func_002CFF38");
Sq_002D2688 *func_002CFFA0_002D2688(void) __asm__("func_002CFFA0");
// MATCH func_002D2688
void FUN_002d2688(Trk_002D2688 *t) {
  Vc_002D2688 *p = func_002CFF08_002D2688(0);
  char *g = func_002CFF38_002D2688();
  Sq_002D2688 *s = func_002CFFA0_002D2688();
  int i;
  for (i = 0; i < 48; i++) {
    if (p->state == 2 && p->key == t->key) {
      unsigned char *e = s->ev;
      if (p->note == e[4] && p->prio == e[5] && p->ch == t->ch) {
        int n;
        p->flags |= 0x20;
        n = *(unsigned short *)(g + 0x3a) * e[2] / 15;
        p->x4c = n;
        if (e[3] & 0x80) p->x44 = (float)(signed char)e[3] / (float)(short)n;
        else p->x44 = (float)e[3] / (float)(short)n;
      }
    }
    p++;
  }
  t->pc += 6;
}

typedef struct { volatile unsigned flags; int pc; unsigned char *base; int pos; char p10[0x12]; unsigned short loop; unsigned short val; } Trk_2D2CC8;
char *func_002CFFA0_2D2CC8(void) __asm__("func_002CFFA0");
// MATCH func_002D2CC8
void FUN_002d2cc8(Trk_2D2CC8 *t) {
  unsigned char *e = *(unsigned char **)(func_002CFFA0_2D2CC8() + 0x10);
  unsigned char *base = t->base;
  t->flags |= 0x80;
  if (e[4] != 0) {
    if (t->loop == e[4]) {
      t->loop = 0;
      t->flags &= ~0x80;
    } else {
      t->pos = e[3] * 256 + e[2];
      t->val = base[t->pos];
      t->loop++;
    }
  } else {
    t->pos = e[3] * 256 + e[2];
    t->val = base[t->pos];
  }
  t->pc += 5;
}

typedef struct { short p0; unsigned short reso; unsigned short tempo; char p6[6]; int magic; } Seq_2D3DF0;
typedef struct { volatile unsigned flags; int pc; Seq_2D3DF0 *base; int pos; int tick; int time; short bank; char p1a[4]; unsigned short tempo; unsigned short reso; char p22[0x1e]; int v40; int v44; int v48; short id; char p4e[6]; } Trk_2D3DF0;
Trk_2D3DF0 *func_002CFF20_2D3DF0(int) __asm__("func_002CFF20");
char *func_002CFF38_2D3DF0(void) __asm__("func_002CFF38");
char *func_002CFF48_2D3DF0(unsigned) __asm__("func_002CFF48");
// MATCH func_002D3DF0
int FUN_002d3df0(unsigned bank, Seq_2D3DF0 *seq) {
  register int r __asm__("$19") = -1;
  if (bank < 128) {
    Trk_2D3DF0 *t = func_002CFF20_2D3DF0(0);
    char *g = func_002CFF38_2D3DF0();
    char *b = func_002CFF48_2D3DF0(bank);
    int i;
    if (seq->magic == 0x71735353 && *(int *)(b + 8) != 0) {
      for (i = 0; i < 48; i++) {
        t->flags |= 0x2000;
        if ((t->flags & 0xf) == 0) {
          t->id = i;
          t->bank = bank;
          t->base = seq;
          t->reso = seq->reso;
          t->flags |= 1;
          t->tempo = seq->tempo;
          t->pc = 0x110;
          t->v40 = 0x1000;
          t->v44 = 0x1000;
          t->v48 = 0x1000;
          t->tick = (int)(t->reso * t->tempo * 0x1000) / *(unsigned short *)(g + 0x3a) / 60;
          r = i;
        }
        t->flags &= ~0x2000;
        if (r != -1) return r;
        t++;
      }
    }
  }
  return r;
}

typedef struct { volatile unsigned flags; unsigned age; char p8[0x24]; unsigned short note; char p2e[0x20]; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_2D1DB8;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_2D1DB8;
Vc_2D1DB8 *func_002CFF08_2D1DB8(int) __asm__("func_002CFF08");
char *func_002CFF38_2D1DB8(void) __asm__("func_002CFF38");
char *func_002CFFA0_2D1DB8(void) __asm__("func_002CFFA0");
// MATCH func_002D1DB8
int FUN_002d1db8(Trk_2D1DB8 *t) {
  register int i __asm__("$5");
  Vc_2D1DB8 *p = func_002CFF08_2D1DB8(0);
  char *g = func_002CFF38_2D1DB8();
  unsigned char *e = *(unsigned char **)(func_002CFFA0_2D1DB8() + 0x10);
  for (i = 0; i < 48; i++) {
    if (p->prio == e[1] && p->trk == t->trk && p->ch == t->ch && p->state == 1 && p->key == t->key) {
      if (!(p->flags & 4) || (p->flags & 8)) p->flags &= ~8;
      *(unsigned long *)(g + 0x28) |= 1L << i;
    }
    p++;
  }
  t->pc += 3;
  return 0;
}

typedef struct { volatile unsigned flags; unsigned age; char p8[0x48]; unsigned char ch; unsigned char state; char p52[2]; unsigned char bank; unsigned char b55; unsigned char b56; char p57; } Vc_2D4E08;
Vc_2D4E08 *func_002CFF08_2D4E08(int) __asm__("func_002CFF08");
int SndVoiceSetParam_2D4E08(int, int, int, int) __asm__("SndVoiceSetParam");
char *func_002CFF38_2D4E08(void) __asm__("func_002CFF38");
void *memset_2D4E08(void *, int, unsigned) __asm__("func_002DC804");
// MATCH func_002D4E08
int FUN_002d4e08(int mode) {
  unsigned min = -1;
  char *g = func_002CFF38_2D4E08();
  Vc_2D4E08 *v;
  int i, end, st;
  int best = -1;
  switch (mode) {
  case 0: st = 0; end = 48; break;
  case 1: st = 0; end = 24; break;
  case 2: st = 24; end = 48; break;
  default: return -1;
  }
  v = func_002CFF08_2D4E08(st);
  for (i = st; i < end; i++) {
    if (v->state == 0) {
      best = i;
      v->flags |= 0x100;
      v->flags &= ~0x100;
      v->state = 3;
      goto found;
    }
    if (v->age < min && v->state != 3) { min = v->age; best = i; }
    v++;
  }
  if (best == -1) return -1;
  v = func_002CFF08_2D4E08(best);
  v->flags |= 0x100;
  SndVoiceSetParam_2D4E08(2, best, 0, 0);
  *(unsigned long *)(g + 0x28) |= 1L << best;
  memset_2D4E08((char *)v + 4, 0, 0x54);
  v->state = 3;
  v->flags = 0;
  v->ch = 0xff;
  v->b56 = 0xff;
  v->b55 = 0xff;
  v->bank = 0xff;
found:
  *(unsigned long *)(g + 0x10) &= ~(1L << best);
  return best;
}

typedef struct { unsigned flags; unsigned age; char p8[0x49]; unsigned char state; unsigned char prio; unsigned char id; unsigned char key; char p55[3]; } Vc_2D1A38;
Vc_2D1A38 *func_002CFF08_2D1A38(int) __asm__("func_002CFF08");
char *func_002CFF38_2D1A38(void) __asm__("func_002CFF38");
// MATCH func_002D1A38
int FUN_002d1a38(unsigned id, int prio, unsigned key) {
  int best1 = -1;
  int min2 = -1;
  int i, v;
  Vc_2D1A38 *p;
  int best2 = -1;
  int min1 = -1;
  char *g = func_002CFF38_2D1A38();
  if (id != 0) {
    for (i = 0; i < 48; i++) {
      v = *(unsigned *)(g + 0x30) % 48;
      p = func_002CFF08_2D1A38(v);
      if (!(p->flags & 0x100) && p->state == 2 && p->id == id && p->key == key) return v;
      (*(unsigned *)(g + 0x30))++;
    }
  }
  for (i = 0; i < 48; i++) {
    v = *(unsigned *)(g + 0x30) % 48;
    p = func_002CFF08_2D1A38(v);
    if (!(p->flags & 0x100) && p->state == 0) return v;
    (*(unsigned *)(g + 0x30))++;
  }
  for (i = 0; i < 48; i++) {
    v = *(unsigned *)(g + 0x30) % 48;
    p = func_002CFF08_2D1A38(v);
    if (!(p->flags & 0x100)) {
      if (p->state == 1) {
        if (p->age < min2) { best1 = v;
 min2 = p->age;
 }
      } else if (p->state == 2) {
        if (p->prio <= prio && p->age < min1) { best2 = v;
 min1 = p->age;
 }
      }
    }
    (*(unsigned *)(g + 0x30))++;
  }
  if (best1 == -1 && best2 != -1) return best2;
  return best1;
}

typedef struct { char p0[0x16]; unsigned short a16, a18, a1a, a1c, a1e, a20, a22; char p24[0xa]; unsigned short a2e; } Vc_2D1F90;
typedef struct { char p0[0x44]; int v44; int v48; } Tk_2D1F90;
typedef struct { char p0[0x38]; unsigned short mono; } Gl_2D1F90;
Vc_2D1F90 *func_002CFF08_2D1F90(void) __asm__("func_002CFF08");
Gl_2D1F90 *func_002CFF38_2D1F90(void) __asm__("func_002CFF38");
long func_002D73E8_2D1F90(long, long) __asm__("func_002D73E8");
int SndVoiceSetParam_2D1F90(int, int, int, int) __asm__("SndVoiceSetParam");
// MATCH func_002D1F90
int FUN_002d1f90(int ch, Tk_2D1F90 *t) {
  Vc_2D1F90 *v = func_002CFF08_2D1F90();
  Gl_2D1F90 *g = func_002CFF38_2D1F90();
  long m;
  long n;
  unsigned short pan;
  short l, r;
  n = func_002D73E8_2D1F90(func_002D73E8_2D1F90(v->a16, v->a22), func_002D73E8_2D1F90(v->a1c, v->a1a));
  m = func_002D73E8_2D1F90(n, func_002D73E8_2D1F90(v->a18, v->a1e));
  pan = v->a20;
  l = func_002D73E8_2D1F90(func_002D73E8_2D1F90(m, pan >> 8), t->v44) >> 46;
  r = func_002D73E8_2D1F90(func_002D73E8_2D1F90(m, pan & 0xff), t->v48) >> 46;
  if (g->mono == 1) {
    l = l < 0 ? -l : l;
    r = r < 0 ? -r : r;
    if (r < l) r = l; else l = r;
  }
  l = (l & 0xffff) >> 1;
  r = (r & 0xffff) >> 1;
  if (v->a2e != 0) {
    l = v->a2e << 8 | l >> 7;
    r = v->a2e << 8 | r >> 7;
  }
  SndVoiceSetParam_2D1F90(1, ch, l, r);
  return 0;
}

typedef struct { char p[14]; unsigned char x; char q; } Ch_2D1580;
typedef struct { unsigned char b0; char p[15]; Ch_2D1580 ch[16]; } Hd_2D1580;
typedef struct { char p0[0x40]; Hd_2D1580 *x40; } Bk_2D1580;
typedef struct { volatile unsigned flags; int pc; Hd_2D1580 *base; char pc_[0xc]; unsigned short bank; char p1a[0x16]; int x30; int x34; int x38; int x3c; char p40[0xc]; unsigned short x4c; } Tk_2D1580;
typedef struct { char p0[0x16]; unsigned short x16; char p18[6]; unsigned short x1e; char p20[0x2f]; unsigned char b4f; unsigned char b50; unsigned char b51; char p52[6]; } Vc_2D1580;
int func_002CFF78_2D1580(int) __asm__("func_002CFF78");
Bk_2D1580 **func_002CFF48_2D1580(int) __asm__("func_002CFF48");
Vc_2D1580 *func_002CFF08_2D1580(int) __asm__("func_002CFF08");
int func_002D1F90_2D1580(int, Tk_2D1580 *) __asm__("func_002D1F90");
// MATCH func_002D1580
int FUN_002d1580(Tk_2D1580 *t) {
  int st = 0;
  Hd_2D1580 *e;
  Vc_2D1580 *p;
  int i;
  if ((t->flags & 5) == 4) {
    int v = func_002CFF78_2D1580(t->bank);
    if (v & 0x80) {
      t->x30 = 0xffff;
      st = 1;
      t->x34 = v & 0x7f;
    }
  } else if ((t->flags & 5) == 1 && (t->flags & 0x200)) {
    t->flags &= ~0x200;
    st = 2;
  }
  switch (st) {
  case 1:
    e = (*func_002CFF48_2D1580(t->bank))->x40;
    e->b0 = t->x34;
    break;
  case 2:
    e = t->base;
    if (t->x30 == 0xffff) e->b0 = t->x34;
    if (t->x38 != 0) {
      for (i = 0; i < 16; i++) {
        if ((t->x38 >> i) & 1) e->ch[i].x = t->x3c;
      }
    }
    break;
  default:
    return -1;
  }
  p = func_002CFF08_2D1580(0);
  for (i = 0; i < 48; i++) {
    unsigned char c = p->b51;
    if (c != 0 && c != 3 && p->b50 == t->x4c) {
      p->x1e = e->b0;
      if (c == 1) p->x16 = e->ch[p->b4f].x;
      func_002D1F90_2D1580(i, t);
    }
    p++;
  }
  return 0;
}

typedef struct { volatile unsigned flags; char p4[8]; unsigned short x0c; char p0e[0x12]; unsigned short x20; char p22[0xa]; unsigned short x2c; char p2e[2]; unsigned short x30; char p32[0xa]; unsigned short x3c; unsigned short x3e; unsigned short x40; unsigned short x42; char p44[0xa]; unsigned char b4e; unsigned char b4f; unsigned char b50; unsigned char b51; char p52[2]; unsigned char b54; char p55[3]; } Vc_2D2990;
typedef struct { volatile unsigned flags; int pc; char p8[0x10]; unsigned short bank; char p1a[0x32]; unsigned short x4c; unsigned short x4e; } Tk_2D2990;
typedef struct { char p[4]; unsigned char x14; char q[11]; } Ch_2D2990;
typedef struct { char p[16]; Ch_2D2990 ch[16]; } Hd_2D2990;
typedef struct { char p0[8]; Hd_2D2990 *chtab; char pc[4]; unsigned char *ev; } Sq_2D2990;
typedef struct { char p0[0x38]; unsigned short mono; unsigned short x3a; } Gl_2D2990;
extern Vc_2D2990 D_0062D540[];
extern unsigned short D_00427EB0[];
Vc_2D2990 *func_002CFF08_2D2990(int) __asm__("func_002CFF08");
Gl_2D2990 *func_002CFF38_2D2990(void) __asm__("func_002CFF38");
Sq_2D2990 *func_002CFFA0_2D2990(void) __asm__("func_002CFFA0");
int func_002D2130_2D2990(int, int) __asm__("func_002D2130");
void func_002D1F90_2D2990(int, Tk_2D2990 *) __asm__("func_002D1F90");
// MATCH func_002D2990
void FUN_002d2990(Tk_2D2990 *t) {
  Vc_2D2990 *p = func_002CFF08_2D2990(0);
  Gl_2D2990 *g = func_002CFF38_2D2990();
  Sq_2D2990 *s = func_002CFFA0_2D2990();
  int i;
  if (t->flags & 8) {
    if (g->mono != 1) {
      for (i = 0; i < 48; i++) {
        if (p->b51 == 2 && p->b54 == t->bank) {
          unsigned char *e = s->ev;
          if (p->x2c == e[4] && p->b4e == e[5] && p->b50 == t->x4c) {
            int v;
            p->flags |= 0x80;
            p->x3c = e[3];
            p->x3e = p->x30;
            v = (int)((e[2] << 2) * g->x3a) / 60;
            p->x40 = v;
            p->x42 = v;
          }
        }
        p++;
      }
    }
    t->pc += 6;
  } else {
    s->chtab->ch[t->x4e].x14 = s->ev[2];
    if (g->mono != 1) {
      i = 0; do {
        if (p->b4f == t->x4e && p->b54 == t->bank && p->b50 == t->x4c && p->b51 == 1) {
          int r;
          p->x30 = s->ev[2];
          r = func_002D2130_2D2990(D_0062D540[i].x0c, t->x4e);
          p->x20 = D_00427EB0[r >> 2];
          func_002D1F90_2D2990(i, t);
        }
        i++; p++;
      } while (i < 48);
    }
    t->pc += 3;
  }
}

typedef struct { volatile unsigned flags; char p4[0xe]; unsigned short x12; unsigned short x14; char p16[4]; unsigned short x1a; char p1c[6]; unsigned short x22; char p24[8]; unsigned short note; char p2e[6]; unsigned short x34; unsigned short x36; unsigned short x38; unsigned short x3a; char p3c[8]; float x44; char p48[4]; short x4c; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_002D27D8;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_002D27D8;
typedef struct { char p[3]; unsigned char x13; char p4[5]; unsigned char vol; unsigned char pb; unsigned char sus; unsigned char x1c; char q[3]; } Ch_002D27D8;
typedef struct { char p[16]; Ch_002D27D8 ch[16]; } Hd_002D27D8;
typedef struct { char p0[8]; Hd_002D27D8 *chtab; char pc[4]; unsigned char *ev; } Sq_002D27D8;
Vc_002D27D8 *func_002CFF08_002D27D8(int) __asm__("func_002CFF08");
char *func_002CFF38_002D27D8(void) __asm__("func_002CFF38");
Sq_002D27D8 *func_002CFFA0_002D27D8(void) __asm__("func_002CFFA0");
void func_002D1F90_002D27D8(int, Trk_002D27D8 *) __asm__("func_002D1F90");
// MATCH func_002D27D8
void FUN_002d27d8(Trk_002D27D8 *t) {
  Vc_002D27D8 *p = func_002CFF08_002D27D8(0);
  char *g = func_002CFF38_002D27D8();
  Sq_002D27D8 *s = func_002CFFA0_002D27D8();
  int i;
  if (t->flags & 8) {
    for (i = 0; i < 48; i++) {
      if (p->state == 2 && p->key == t->key) {
        unsigned char *e = s->ev;
        if (p->note == e[4] && p->prio == e[5] && p->ch == t->ch) {
          int v;
          p->flags |= 0x40;
          p->x34 = e[3];
          p->x36 = p->x1a;
          v = (int)((e[2] << 2) * *(unsigned short *)(g + 0x3a)) / 60;
          p->x38 = v;
          p->x3a = v;
        }
      }
      p++;
    }
    t->pc += 6;
  } else {
    s->chtab->ch[t->trk].x13 = s->ev[2];
    for (i = 0; i < 48; i++) {
      if (p->state == 1 && p->trk == t->trk && p->key == t->key && p->ch == t->ch) {
        p->x22 = s->ev[2];
        func_002D1F90_002D27D8(i, t);
      }
      p++;
    }
    t->pc += 3;
  }
}

typedef struct { char p[2]; unsigned char n; char q[13]; } Ch_2D1760;
typedef struct { unsigned char b0; char p[15]; Ch_2D1760 ch[16]; } Hd_2D1760;
typedef struct { char p0[0xc]; int magic; unsigned x10; char p14[0x1c]; unsigned short *x30; char p34[0xc]; char *x40; unsigned short *x44; } Bk_2D1760;
typedef struct { volatile unsigned flags; int pc; Hd_2D1760 *base; char pc_[0xc]; unsigned short bank; char p1a[0x32]; unsigned short x4c; unsigned short x4e; unsigned char b50; unsigned char b51; } Tk_2D1760;
typedef struct { char *s0; char *s4; void *base; Bk_2D1760 *hdr; unsigned char *ev; } Sq_2D1760;
Sq_2D1760 *func_002CFFA0_2D1760(void) __asm__("func_002CFFA0");
Bk_2D1760 **func_002CFF48_2D1760(int) __asm__("func_002CFF48");
// MATCH func_002D1760
int FUN_002d1760(Tk_2D1760 *t) {
  Sq_2D1760 *s = func_002CFFA0_2D1760();
  Bk_2D1760 *b;
  Hd_2D1760 *base;
  unsigned char c;
  unsigned short *tab;
  int r;
  if ((unsigned)(((volatile Tk_2D1760 *)t)->bank - 1) >= 127) return -1;
  b = *func_002CFF48_2D1760(t->bank);
  if (b == 0) return -1;
  base = t->base;
  if (base == 0 || (s->hdr = b, b->magic != 0x64685353)) return -1;
  s->ev = (unsigned char *)base + t->pc;
  c = *s->ev;
  if (c & 0x80) {
    t->b50 = c;
    t->b51 = c;
  } else {
    t->pc--;
    t->b50 = t->b51;
    s->ev = (unsigned char *)base + t->pc;
  }
  r = 1;
  if (t->flags & 4) {
    Bk_2D1760 *h;
    unsigned char *e;
    char *p;
    t->x4e = t->x4c;
    e = s->ev;
    h = s->hdr;
    tab = h->x44;
    p = (char *)tab + tab[e[3] + 1];
    s->base = h->x40;
    s->s0 = p;
    s->s4 = p + 8;
  } else {
    Bk_2D1760 *h;
    int k;
    int n;
    char *p;
    s->base = base;
    h = s->hdr;
    tab = h->x30;
    t->x4e = t->b50 & 0xf;
    n = base->ch[t->x4e].n;
    p = (char *)tab + tab[n + 1];
    s->s0 = p;
    s->s4 = p + 8;
    if (t->b50 < 160) {
      if (tab[n + 1] != 0xffff && !(tab[0] < n)) {
        if (h->x10 != 0xffffffff) goto out;
      }
      r = 0;
      t->pc += 3;
    }
  }
out:
  return r;
}

typedef struct { char p[9]; unsigned char vol; char q[6]; } Ch_2D4398;
typedef struct { char p[0xc]; int magic; Ch_2D4398 ch[16]; } Hd_2D4398;
typedef struct { volatile unsigned flags; int pc; Hd_2D4398 *base; char pc_[0xc]; unsigned short bank; char p1a[8]; unsigned short x22; } Tk_2D4398;
typedef struct { void *bank; int size; int type; } Ent_2D4398;
typedef struct { volatile unsigned flags; char p4[0xe]; unsigned short x12; char p14[0x12]; unsigned short x26; char p28[0x28]; unsigned char b50; unsigned char b51; char p52[6]; } Vc_2D4398;
typedef struct { char p0[0x28]; unsigned long x28; } Gl_2D4398;
Tk_2D4398 *func_002CFF20_2D4398(unsigned) __asm__("func_002CFF20");
Ent_2D4398 *func_002CFF48_2D4398(int) __asm__("func_002CFF48");
Vc_2D4398 *func_002CFF08_2D4398(int) __asm__("func_002CFF08");
Gl_2D4398 *func_002CFF38_2D4398(void) __asm__("func_002CFF38");
int SndVoiceSetParam_2D4398(int, int, int, int) __asm__("SndVoiceSetParam");
// MATCH func_002D4398
void FUN_002d4398(unsigned ch, int mode) {
  Tk_2D4398 *t;
  Vc_2D4398 *p;
  Gl_2D4398 *g;
  int i, m;
  if (ch >= 48) return;
  t = func_002CFF20_2D4398(ch);
  t->flags |= 0x2000;
  if ((unsigned short)(t->bank - 1) < 127 && (t->flags & 1) && func_002CFF48_2D4398(t->bank)->type != 0) {
    p = func_002CFF08_2D4398(0);
    g = func_002CFF38_2D4398();
    if (mode >= 0) {
      if (mode < 2) {
        t->flags &= ~0x22;
        t->pc = 272;
        m = mode;
        t->x22 = 0;
        t->flags |= 0x10;
      } else {
        if (mode >= 4) goto out;
        if (!(t->flags & 2)) {
          if (!(t->flags & 0x50)) {
            t->flags |= 2;
            t->flags &= ~0x20;
          }
          goto out;
        }
        t->flags &= ~2;
        m = mode - 2;
        t->flags |= 0x20;
      }
      for (i = 0; i < 48; i++) {
        if (p->b50 == ch && p->b51 == 1) {
          p->flags |= 0x100;
          p->x12 = 0;
          p->x26 = 64;
          p->flags &= ~0x10;
          p->flags &= ~0x100;
          g->x28 |= 1L << i;
          if (m == 1) SndVoiceSetParam_2D4398(2, i, 0, 0);
        }
        p++;
      }
      {
        Hd_2D4398 *b = t->base;
        if (b->magic == 0x71735353) {
          for (i = 15; i >= 0; i--) b->ch[i].vol = 0;
        }
      }
    }
  }
out:
  t->flags &= ~0x2000;
}

typedef struct { volatile unsigned flags; char p4[0xe]; unsigned short x12; unsigned short x14; char p16[0x16]; unsigned short note; char p2e[0x20]; unsigned char prio; unsigned char trk; unsigned char ch; unsigned char state; char p52[2]; unsigned char key; char p55[3]; } Vc_002D2510;
typedef struct { unsigned flags; int pc; char p8[0x10]; unsigned short key; char p1a[0x32]; unsigned short ch; unsigned short trk; } Trk_002D2510;
typedef struct { char p[9]; unsigned char vol; unsigned char pb; unsigned char sus; unsigned char x1c; char q[3]; } Ch_002D2510;
typedef struct { char p[16]; Ch_002D2510 ch[16]; } Hd_002D2510;
typedef struct { char p0[8]; Hd_002D2510 *chtab; char pc[4]; unsigned char *ev; } Sq_002D2510;
Vc_002D2510 *func_002CFF08_002D2510(int) __asm__("func_002CFF08");
char *func_002CFF38_002D2510(void) __asm__("func_002CFF38");
Sq_002D2510 *func_002CFFA0_002D2510(void) __asm__("func_002CFFA0");
// MATCH func_002D2510
void FUN_002d2510(Trk_002D2510 *t) {
  Vc_002D2510 *p = func_002CFF08_002D2510(0);
  Sq_002D2510 *s = func_002CFFA0_002D2510();
  unsigned char *e = s->ev;
  int v = 240 / (int)(60 - e[2] * 58 / 127);
  int i;
  if (t->flags & 8) {
    for (i = 0; i < 48; i++) {
      if (p->trk == t->trk && p->note == s->ev[3] && p->prio == s->ev[4] && p->key == t->key && p->ch == t->ch && p->state == 2) p->x14 = v;
      p++;
    }
    t->pc += 5;
  } else {
    int pc;
    s->chtab->ch[t->trk].x1c = v;
    for (i = 0; i < 48; i++) {
      if (p->trk == t->trk && p->key == t->key && p->ch == t->ch && p->state == 1) p->x14 = v;
      p++;
    }
    t->pc += 3;
  }
}

typedef struct { volatile unsigned flags; int pc; unsigned char *base; int pos; int tick; unsigned time; char p18[6]; unsigned short tempo; unsigned short reso; } Trk_2D4608;
Trk_2D4608 *func_002CFF20_2D4608(unsigned) __asm__("func_002CFF20");
char *func_002CFF38_2D4608(void) __asm__("func_002CFF38");
// MATCH func_002D4608
void FUN_002d4608(unsigned ch, int tempo) {
  if (ch < 48 && tempo >= 0 && tempo < 960) {
    Trk_2D4608 *t = func_002CFF20_2D4608(ch);
    char *g = func_002CFF38_2D4608();
    t->flags |= 0x2000;
    t->tempo = tempo;
    t->tick = (t->reso * t->tempo << 12) / *(unsigned short *)(g + 0x3a) / 60;
    t->flags &= ~0x2000;
  }
}

typedef struct { volatile unsigned flags; int p4; unsigned age; char pc[0x44]; unsigned char ch; unsigned char state; char p52[2]; unsigned char bank; unsigned char b55; unsigned char b56; char p57; } Vc_2D3430;
typedef struct { volatile unsigned flags; char p4[0x50]; } Trk_2D3430;
Vc_2D3430 *func_002CFF08_2D3430(int) __asm__("func_002CFF08");
Trk_2D3430 *func_002CFF20_2D3430(int) __asm__("func_002CFF20");
int (*func_002CFFB0_2D3430(void))[24] __asm__("func_002CFFB0");
void *memset_2D3430(void *, int, unsigned) __asm__("func_002DC804");
// MATCH func_002D3430
void FUN_002d3430(Trk_2D3430 *t) { int (*ref)[24] = func_002CFFB0_2D3430(); Vc_2D3430 *v = func_002CFF08_2D3430(0); int i; for (i = 0; i < 48; i++) { if (!(v->flags & 0x100)) { if (*(int *)((char *)ref + ((i / 24) * 96 + (i % 24) * 4)) < 2 && v->state != 3 && v->age > 1) { memset_2D3430(v, 0, 0x58); v->ch = 0xff; v->b56 = 0xff; v->b55 = 0xff; v->bank = 0xff; } if (v->state != 0) v->age++; } v++; } for (i = 0; i < 48; i++) { if (!(t->flags & 0x2000) && (t->flags & 0x44) == 0x44) { int k; v = func_002CFF08_2D3430(0); for (k = 0; k < 48; k++) { unsigned char c = v->ch; v++; if (c == i) goto next; } memset_2D3430(func_002CFF20_2D3430(i), 0, 0x54); } next: t++; } }

// compiler: 991111-01-as210
#define R(a) (*(volatile unsigned *)(a))
extern unsigned *D_00427DE0_2CEA70[] __asm__("D_00427DE0"); extern int D_0049E360_2CEA70[] __asm__("D_0049E360");
void func_002CEA10_2CEA70(char *, int) __asm__("func_002CEA10"); int func_002CEB50_2CEA70(char *) __asm__("func_002CEB50");
// MATCH func_002CEA70
unsigned FUN_002cea70(int p) { unsigned c; unsigned *q; unsigned **pp; int *t; int i; char buf[32]; c = R(0x1000e000) & 1; for (i = 0; i < 10; i++) { if (D_0049E360_2CEA70[i]) { D_00427DE0_2CEA70[i][0] = 0; D_00427DE0_2CEA70[i][12] = 0; D_00427DE0_2CEA70[i][4] = 0; D_00427DE0_2CEA70[i][20] = 0; D_00427DE0_2CEA70[i][16] = 0; D_00427DE0_2CEA70[i][32] = 0; } } R(0x1000e010) = 0xff1f; R(0x1000e010) = R(0x1000e010) & 0xff1f0000; func_002CEA10_2CEA70(buf, 20); func_002CEB50_2CEA70(buf); if (p == 1) R(0x1000e000) = R(0x1000e000) | 1; return c; }


#undef W
#undef L
#define W(o, n) (*(int *)((char *)(o) + (n)))
#define L(o, n) (*(long *)((char *)(o) + (n)))
void *func_002DC804_2C2918(void *, int, unsigned) __asm__("func_002DC804");
void func_002C35C8_2C2918(void *, void *) __asm__("func_002C35C8");
void func_002C2E70_2C2918(void *, void *, unsigned) __asm__("func_002C2E70");
int func_002C2EA8_2C2918(void *, void *, int, int) __asm__("func_002C2EA8");
void func_002C3458_2C2918(void *) __asm__("func_002C3458");
void func_002C2C88_2C2918(void *) __asm__("func_002C2C88");
int func_002C2CD8_2C2918(void *) __asm__("func_002C2CD8");
void func_002C2E88_2C2918(void *) __asm__("func_002C2E88");
void func_002C3ED0_2C2918(void) __asm__("func_002C3ED0");
void func_002C3EE0_2C2918(void) __asm__("func_002C3EE0");
extern char D_0049D960_2C2918[] __asm__("D_0049D960");
// MATCH func_002C2918
int FUN_002c2918(int *mp, char *buf, unsigned size) { char *m; char *h; unsigned n; func_002DC804_2C2918(buf, 0, size); m = (char *)((unsigned)(buf + 3) / 4 * 4); n = size - (m - buf); if (n < 0x10c0) { func_002C35C8_2C2918(m, D_0049D960_2C2918); return 0; } h = m + 0x108; mp[16] = (int)m; func_002C2E70_2C2918(h, m + 0x10c0, n - 0x10c0); mp[0] = 0; mp[1] = 0; mp[2] = 0; L(mp, 16) = -1; L(mp, 24) = -1; L(mp, 32) = 0; L(mp, 40) = -1; L(mp, 48) = -1; L(mp, 56) = 0; W(m, 0xb4) = 0; W(m, 0xb8) = 0; W(m, 0xbc) = 0; W(m, 0xc0) = 0; W(m, 0xc4) = 0; W(m, 0xc8) = 0; W(m, 0xcc) = 0; W(m, 0xd0) = 0; W(m, 0xd4) = 0; W(m, 0xd8) = 0; W(m, 0xdc) = 0; W(m, 0xe0) = 0; W(m, 0xe4) = 0; W(m, 0xe8) = 0; W(m, 0xf8) = 0; W(m, 0xc) = 0; W(m, 0x14) = 0; W(m, 0x2c) = 0; W(m, 0x34) = 0; W(m, 0x3c) = 0; L(m, 0xf0) = -1; W(m, 0x1c) = (int)func_002C3ED0_2C2918; W(m, 0x24) = (int)func_002C3EE0_2C2918; W(m, 0x44) = func_002C2EA8_2C2918(m, h, 0x600, 8); W(m, 0x48) = 0; W(m, 0xfc) = 0; W(m, 0x100) = 0; W(m, 0x104) = 0; W(m, 0x70) = 0; L(m, 0x78) = 0; W(m, 0x80) = -1; L(m, 0x88) = 0; W(m, 0x90) = 0; W(m, 0xac) = 0; W(m, 0x94) = -1; W(m, 0x98) = -1; W(m, 0x9c) = -1; W(m, 0x858) = (int)mp; W(m, 0xb0) = 1; func_002C3458_2C2918(m); func_002C2C88_2C2918(mp); func_002C2CD8_2C2918(mp); W(m, 0x1b8) = (int)(m + 0x1e8); W(m, 0x1bc) = (int)(m + 0x250); W(m, 0x1c4) = (int)(m + 0x2b8); W(m, 0x1c8) = (int)(m + 0x320); W(m, 0x1cc) = (int)(m + 0x388); W(m, 0x1d4) = (int)(m + 0x3f0); W(m, 0x1d8) = (int)(m + 0x458); W(m, 0x1dc) = (int)(m + 0x4c0); W(m, 0x1e4) = (int)(m + 0x528); func_002C2E88_2C2918(h); W(m, 0x850) = -1; W(m, 0x84c) = 0; W(m, 0x81c) = 0x70003600; W(m, 0x854) = 0; }


typedef struct { int lsn; int sec; void *buf; char mode[3]; char pad; void *b0; void *b1; } P_2CC580;
extern P_2CC580 D_00426440_2CC580 __asm__("D_00426440"); extern volatile int D_00426394_2CC580[] __asm__("D_00426394"); extern volatile int D_00426370_2CC580[] __asm__("D_00426370"); extern volatile int D_00426368_2CC580[] __asm__("D_00426368"); extern char D_00427510_2CC580[] __asm__("D_00427510");
extern int D_00426374[], D_00426350[]; extern char D_00427440[], D_00427500[], D_0049E180[];
int func_002CBAE8_2CC580(void) __asm__("func_002CBAE8"); int func_002CB978_2CC580(int) __asm__("func_002CB978"); void func_002E8038_2CC580(void *, int) __asm__("func_002E8038"); void func_002CB108_2CC580(void) __asm__("func_002CB108"); void func_002E58C0_2CC580(int) __asm__("func_002E58C0"); void func_002E7940_2CC580(char *) __asm__("func_002E7940");
int func_002E8928_2CC580(void *, int, int, void *, int, int, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CC580
int FUN_002cc580(int lsn, int sec, void *buf, char *mode) {
  P_2CC580 *p = &D_00426440_2CC580;
  if ((D_00426374[0] & 1) == 0 && func_002CBAE8_2CC580() == 6) return 0;
  if (func_002CB978_2CC580(5) == 0) return 0;
  p->lsn = lsn; p->sec = sec; p->buf = buf;
  p->mode[0] = mode[0]; p->mode[1] = mode[1]; p->mode[2] = mode[2];
  p->b0 = D_00427440; p->b1 = D_00427500;
  func_002E8038_2CC580(p, 24);
  D_00426394_2CC580[0] = 1; D_00426370_2CC580[0] = 1;
  if (func_002E8928_2CC580(D_00427510_2CC580, 13, 1, p, 24, 0, 0, (void *)func_002CB108_2CC580, (void *)D_00426394_2CC580) < 0) { D_00426394_2CC580[0] = 0; D_00426370_2CC580[0] = 0; func_002E58C0_2CC580(D_00426368_2CC580[0]); return 0; }
  if (D_00426350[0] > 0) func_002E7940_2CC580(D_0049E180);
  return 1;
}

typedef struct { int a, b, c, d; char mode[3]; } P_2CCF20;
extern P_2CCF20 D_00426440_2CCF20 __asm__("D_00426440"); extern volatile int D_00426368_2CCF20[] __asm__("D_00426368"); extern char D_00427510_2CCF20[] __asm__("D_00427510");
extern int D_00426350[]; extern char D_0049E280[], D_0049E298[], D_0049E2B0[]; extern int D_004263C0[];
int func_002CB978_2CCF20(int) __asm__("func_002CB978"); void func_002E8038_2CCF20(void *, int) __asm__("func_002E8038"); void func_002E58C0_2CCF20(int) __asm__("func_002E58C0"); void func_002E7940_2CCF20(char *) __asm__("func_002E7940");
int func_002E8928_2CCF20(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CCF20
int FUN_002ccf20(int a, int b, int c, int d, char *mode) {
  P_2CCF20 *p = &D_00426440_2CCF20;
  int r;
  if (func_002CB978_2CCF20(15) == 0) return 0;
  if (D_00426350[0] > 0) func_002E7940_2CCF20(D_0049E280);
  p->a = a; p->b = b; p->c = c; p->d = d;
  if (mode != 0) { p->mode[0] = mode[0]; p->mode[1] = mode[1]; p->mode[2] = mode[2]; }
  if (D_00426350[0] > 0) func_002E7940_2CCF20(D_0049E298);
  func_002E8038_2CCF20(p, 20);
  if (func_002E8928_2CCF20(D_00427510_2CCF20, 9, 0, p, 20, D_004263C0, 4, 0, 0) < 0) { func_002E58C0_2CCF20(D_00426368_2CCF20[0]); return 0; }
  if (D_00426350[0] > 0) func_002E7940_2CCF20(D_0049E2B0);
  r = *(int *)((unsigned)D_004263C0 | 0x20000000);
  func_002E58C0_2CCF20(D_00426368_2CCF20[0]);
  return r;
}

typedef struct { char p[36]; int server; char q[0x50]; } Cl_2CD088;
typedef struct { int count, max, init, wait, attr, option; } Se_2CD088;
extern int D_00427DCC[]; extern Cl_2CD088 D_0062B900; extern char D_0062B980[]; extern int D_0062CEC0[];
extern char D_0049E2C0[], D_0049E2D8[], D_0049E300[];
int func_002E58A0_2CD088(Se_2CD088 *) __asm__("func_002E58A0"); void func_002E58E0_2CD088(int) __asm__("func_002E58E0"); void func_002E58C0_2CD088(int) __asm__("func_002E58C0");
void func_002CDAC8_2CD088(int, int, int) __asm__("func_002CDAC8"); void func_002E80E8_2CD088(int) __asm__("func_002E80E8"); void func_002E7940_2CD088(char *) __asm__("func_002E7940");
int func_002E8758_2CD088(Cl_2CD088 *, unsigned, int) __asm__("func_002E8758");
int func_002E8928_2CD088(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CD088
int FUN_002cd088(void) {
  Se_2CD088 s;
  int r, i;
  if (D_00427DCC[0] < 0) { s.option = 0; s.init = 1; s.max = 1; D_00427DCC[0] = func_002E58A0_2CD088(&s); }
  func_002CDAC8_2CD088(0, 0, 0);
  func_002E58E0_2CD088(D_00427DCC[0]);
  func_002E80E8_2CD088(0);
  for (;;) {
    if (func_002E8758_2CD088(&D_0062B900, 0x80000400, 0) < 0) { func_002E7940_2CD088(D_0049E2C0); for (;;) ; }
    if (D_0062B900.server != 0) break;
    i = 0x100000;
    do { i--; } while (i != 0);
  }
  r = func_002E8928_2CD088(&D_0062B900, 254, 0, D_0062B980, 48, D_0062CEC0, 12, 0, 0);
  func_002E58C0_2CD088(D_00427DCC[0]);
  if (r < 0) { D_0062B900.server = 0; return r - 100; }
  if (D_0062CEC0[1] < 522) { func_002E7940_2CD088(D_0049E2D8); D_0062B900.server = 0; return -120; }
  if (D_0062CEC0[2] < 526) { func_002E7940_2CD088(D_0049E300); D_0062B900.server = 0; return -121; }
  return D_0062CEC0[0];
}

typedef struct { int lsn; int sec; void *buf; unsigned char mode[3]; char pad; void *b0; void *b1; } P_2CC3A0;
extern P_2CC3A0 D_00426440_2CC3A0 __asm__("D_00426440"); extern volatile int D_00426394_2CC3A0[] __asm__("D_00426394"); extern volatile int D_00426370_2CC3A0[] __asm__("D_00426370"); extern volatile int D_00426368_2CC3A0[] __asm__("D_00426368"); extern char D_00427510_2CC3A0[] __asm__("D_00427510");
extern volatile int D_00426374_2CC3A0[] __asm__("D_00426374"); extern int D_00426350_2CC3A0[] __asm__("D_00426350"); extern char D_00427440_2CC3A0[] __asm__("D_00427440"); extern int D_00427500_2CC3A0[] __asm__("D_00427500"); extern char D_0049E158[], D_0049E170[];
int func_002CBAE8_2CC3A0(void) __asm__("func_002CBAE8"); int func_002CB978_2CC3A0(int) __asm__("func_002CB978"); void func_002E8038_2CC3A0(void *, int) __asm__("func_002E8038"); void func_002CB340_2CC3A0(void) __asm__("func_002CB340"); void func_002E58C0_2CC3A0(int) __asm__("func_002E58C0"); void func_002E7940_2CC3A0(char *) __asm__("func_002E7940");
int func_002E8928_2CC3A0(void *, int, int, void *, int, int, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CC3A0
int FUN_002cc3a0(int lsn, int sec, void *buf, unsigned char *mode) {
  P_2CC3A0 *p = &D_00426440_2CC3A0;
  int n;
  if ((D_00426374_2CC3A0[0] & 1) == 0 && func_002CBAE8_2CC3A0() == 6) return 0;
  if (func_002CB978_2CC3A0(4) == 0) return 0;
  p->lsn = lsn; p->sec = sec; p->buf = buf;
  p->mode[0] = mode[0]; p->mode[1] = mode[1]; p->mode[2] = mode[2];
  p->b0 = D_00427440_2CC3A0; p->b1 = D_00427500_2CC3A0;
  switch (mode[2]) {
  case 1: n = sec * 2328; break;
  case 2: n = sec * 2340; break;
  case 0: default: n = sec << 11; break;
  }
  D_00427500_2CC3A0[0] = 0;
  if ((D_00426374_2CC3A0[0] & 2) == 0) func_002E8038_2CC3A0(buf, n);
  func_002E8038_2CC3A0(D_00427440_2CC3A0, 144);
  func_002E8038_2CC3A0(p, 24);
  func_002E8038_2CC3A0(D_00427500_2CC3A0, 4);
  if (D_00426350_2CC3A0[0] > 0) func_002E7940_2CC3A0(D_0049E158);
  D_00426394_2CC3A0[0] = 1; D_00426370_2CC3A0[0] = 1;
  if (func_002E8928_2CC3A0(D_00427510_2CC3A0, 1, 1, p, 24, 0, 0, (void *)func_002CB340_2CC3A0, D_00427440_2CC3A0) < 0) { D_00426394_2CC3A0[0] = 0; D_00426370_2CC3A0[0] = 0; func_002E58C0_2CC3A0(D_00426368_2CC3A0[0]); return 0; }
  if (D_00426350_2CC3A0[0] > 0) func_002E7940_2CC3A0(D_0049E170);
  return 1;
}

extern int D_00426350_2CCCA8[] __asm__("D_00426350"), D_00427DB0[]; extern char D_0049E1A0[], D_0049E1D0[], D_0049E218[], D_0062B8D8[];
void func_002E7940_2CCCA8(char *, ...) __asm__("func_002E7940"); void func_002E8038_2CCCA8(void *, int) __asm__("func_002E8038");
unsigned func_002CCF20_2CCCA8(int, unsigned, char *, int, char *) __asm__("func_002CCF20"); void func_002CB040_2CCCA8(int) __asm__("func_002CB040");
// MATCH func_002CCCA8
unsigned sceCdStRead(unsigned sectors, char *buf, unsigned mode, unsigned *err) {
  unsigned r, i, n, e, last;
  if (D_00426350_2CCCA8[0] > 0) func_002E7940_2CCCA8(D_0049E1A0, sectors);
  if (D_00427DB0[0] == 0) return 0;
  last = 0;
  i = 0;
  func_002E8038_2CCCA8(buf, sectors << 11);
  if (mode != 0) {
    do {
      unsigned x = func_002CCF20_2CCCA8(0, sectors - i, buf + (i << 11), 2, D_0062B8D8);
      n = x & 0xffff;
      e = x >> 16;
      i += n;
      if (e != 0) {
        last = e;
        if (D_00426350_2CCCA8[0] > 0) func_002E7940_2CCCA8(D_0049E1D0, i, n, sectors, e);
      } else if (n == 0) func_002CB040_2CCCA8(8);
    } while (i != sectors && (e == 0 || n != 0));
    if (D_00426350_2CCCA8[0] > 0) func_002E7940_2CCCA8(D_0049E218);
    *err = last;
  } else {
    unsigned y = func_002CCF20_2CCCA8(0, sectors, buf, 2, D_0062B8D8);
    e = y >> 16;
    i = y & 0xffff;
    *err = e;
  }
  return i;
}

typedef struct { char p[36]; int server; char q[0x50]; } Cl_2CD8D8;
typedef struct { int cmd; int w4, w8; int n12; int w16; int n20; char *p24; int w28; char data[16]; } Q_2CD8D8;
extern int D_00427DCC_2CD8D8[] __asm__("D_00427DCC"), D_00427DC8[]; extern Cl_2CD8D8 D_0062B900_2CD8D8 __asm__("D_0062B900"); extern Q_2CD8D8 D_0062B980_2CD8D8 __asm__("D_0062B980"); extern int D_0062CEC0_2CD8D8[] __asm__("D_0062CEC0");
int func_002E58F0_2CD8D8(int) __asm__("func_002E58F0"); void func_002E58C0_2CD8D8(int) __asm__("func_002E58C0"); void func_002E5B20_2CD8D8(int) __asm__("func_002E5B20");
int func_002E8928_2CD8D8(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CD8D8
int FUN_002cd8d8(int cmd, char *buf, int size) {
  Q_2CD8D8 *q;
  unsigned i;
  int r, k;
  if (func_002E58F0_2CD8D8(D_00427DCC_2CD8D8[0]) < 0) return -200;
  if (D_0062B900_2CD8D8.server == 0) { func_002E58C0_2CD8D8(D_00427DCC_2CD8D8[0]); return -100; }
  D_0062B980_2CD8D8.cmd = cmd;
  if (size < 17) { D_0062B980_2CD8D8.n20 = size; D_0062B980_2CD8D8.n12 = 0; D_0062B980_2CD8D8.p24 = 0; }
  else { { char *a = buf - 16; k = ((unsigned)(buf - 1) & 0xfffffff0) - (unsigned)a; } D_0062B980_2CD8D8.n12 = size - k; D_0062B980_2CD8D8.n20 = k; D_0062B980_2CD8D8.p24 = buf + k; }
  for (i = 0; i < D_0062B980_2CD8D8.n20; i++) D_0062B980_2CD8D8.data[i] = buf[i];
  func_002E5B20_2CD8D8(0);
  r = func_002E8928_2CD8D8(&D_0062B900_2CD8D8, 6, 1, &D_0062B980_2CD8D8, 48, D_0062CEC0_2CD8D8, 4, 0, 0);
  if (r == 0) D_00427DC8[0] = 6;
  else func_002E58C0_2CD8D8(D_00427DCC_2CD8D8[0]);
  return r;
}

typedef struct { char p[36]; int server; char q[0x50]; } Cl_2CE3D0;
typedef struct { char c[64]; } B64_2CE3D0;
typedef struct { int a; int b; unsigned mode; int w12; B64_2CE3D0 *p16; char name[1024]; } Q_2CE3D0;
extern int D_00427DCC_2CE3D0[] __asm__("D_00427DCC"), D_00427DC8_2CE3D0[] __asm__("D_00427DC8"); extern Cl_2CE3D0 D_0062B900_2CE3D0 __asm__("D_0062B900"); extern Q_2CE3D0 D_0062B9B0; extern B64_2CE3D0 D_0062B940; extern int D_0062CEC0_2CE3D0[] __asm__("D_0062CEC0");
int func_002E58F0_2CE3D0(int) __asm__("func_002E58F0"); void func_002E58C0_2CE3D0(int) __asm__("func_002E58C0"); void func_002E5B20_2CE3D0(int) __asm__("func_002E5B20");
char *func_002DD928_2CE3D0(char *, char *, int) __asm__("func_002DD928");
int func_002E8928_2CE3D0(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CE3D0
int FUN_002ce3d0(int a, int b, char *name, B64_2CE3D0 *blk, unsigned mode) {
  int r;
  Q_2CE3D0 *q;
  if (func_002E58F0_2CE3D0(D_00427DCC_2CE3D0[0]) < 0) return -200;
  if (D_0062B900_2CE3D0.server == 0) { func_002E58C0_2CE3D0(D_00427DCC_2CE3D0[0]); return -100; }
  if (name == 0 || name[0] == 0) { func_002E58C0_2CE3D0(D_00427DCC_2CE3D0[0]); return -210; }
  mode &= 7;
  q = &D_0062B9B0;
  q->a = a;
  q->b = b;
  q->mode = mode;
  D_0062B940 = *blk;
  q->p16 = &D_0062B940;
  func_002DD928_2CE3D0(q->name, name, 1023);
  q->name[1023] = 0;
  func_002E5B20_2CE3D0(0);
  r = func_002E8928_2CE3D0(&D_0062B900_2CE3D0, 14, 1, q, 1044, D_0062CEC0_2CE3D0, 4, 0, 0);
  if (r == 0) D_00427DC8_2CE3D0[0] = 14;
  else func_002E58C0_2CE3D0(D_00427DCC_2CE3D0[0]);
  return r;
}

typedef struct { char p[36]; int server; char q[0x50]; } Cl_2CDC00;
typedef struct { int cmd; int a; int b; int n12; int n16; int n20; int w24; char *p28; } Q_2CDC00;
extern int D_00427DCC_2CDC00[] __asm__("D_00427DCC"), D_00427DC8_2CDC00[] __asm__("D_00427DC8"); extern Cl_2CDC00 D_0062B900_2CDC00 __asm__("D_0062B900"); extern Q_2CDC00 D_0062B980_2CDC00 __asm__("D_0062B980"); extern int D_0062CEC0_2CDC00[] __asm__("D_0062CEC0");
extern char D_0062BE00[]; extern int D_0062B928[], D_0062B92C[], D_0062B930[];
int func_002E58F0_2CDC00(int) __asm__("func_002E58F0"); void func_002E58C0_2CDC00(int) __asm__("func_002E58C0"); void func_002E8038_2CDC00(void *, int) __asm__("func_002E8038"); void func_002CDBA8_2CDC00(void) __asm__("func_002CDBA8");
int func_002E8928_2CDC00(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CDC00
int FUN_002cdc00(int a, int b, int x, int y, int z) {
  int r;
  if (func_002E58F0_2CDC00(D_00427DCC_2CDC00[0]) < 0) return -200;
  if (D_0062B900_2CDC00.server == 0) { func_002E58C0_2CDC00(D_00427DCC_2CDC00[0]); return -100; }
  D_0062B980_2CDC00.a = a;
  D_0062B980_2CDC00.b = b;
  D_0062B980_2CDC00.p28 = D_0062BE00;
  if (x) D_0062B980_2CDC00.n20 = 1; else D_0062B980_2CDC00.n20 = 0;
  if (y) D_0062B980_2CDC00.n16 = 1; else D_0062B980_2CDC00.n16 = 0;
  if (z) D_0062B980_2CDC00.n12 = 1; else D_0062B980_2CDC00.n12 = 0;
  D_0062B928[0] = x; D_0062B92C[0] = y; D_0062B930[0] = z;
  func_002E8038_2CDC00(D_0062BE00, 192);
  r = func_002E8928_2CDC00(&D_0062B900_2CDC00, 1, 1, &D_0062B980_2CDC00, 48, D_0062CEC0_2CDC00, 4, (void *)func_002CDBA8_2CDC00, D_0062BE00);
  if (r == 0) D_00427DC8_2CDC00[0] = 1;
  else func_002E58C0_2CDC00(D_00427DCC_2CDC00[0]);
  return r;
}

extern int *D_0062B928_2CDBA8[] __asm__("D_0062B928"), *D_0062B92C_2CDBA8[] __asm__("D_0062B92C"), *D_0062B930_2CDBA8[] __asm__("D_0062B930");
// MATCH func_002CDBA8
void FUN_002cdba8(int *p) {
  p = (int *)((unsigned)p | 0x20000000);
  if (D_0062B928_2CDBA8[0]) *D_0062B928_2CDBA8[0] = p[0];
  if (D_0062B92C_2CDBA8[0]) *D_0062B92C_2CDBA8[0] = p[1];
  if (D_0062B930_2CDBA8[0]) *D_0062B930_2CDBA8[0] = p[36];
}

typedef struct { int count, max, init, wait, attr, option; } Se_2CB3E0;
extern volatile int D_00426368_2CB3E0[] __asm__("D_00426368"), D_0042636C_2CB3E0[] __asm__("D_0042636C"), D_00426360_2CB3E0[] __asm__("D_00426360"), D_00426370_2CB3E0[] __asm__("D_00426370");
int func_002E58A0_2CB3E0(Se_2CB3E0 *) __asm__("func_002E58A0");
// MATCH func_002CB3E0
void FUN_002cb3e0(void) {
  Se_2CB3E0 s;
  if (D_00426368_2CB3E0[0] == -1 || D_0042636C_2CB3E0[0] == -1) {
    s.option = 0; s.init = 1; s.max = 1;
    D_00426368_2CB3E0[0] = func_002E58A0_2CB3E0(&s);
    D_0042636C_2CB3E0[0] = func_002E58A0_2CB3E0(&s);
    s.init = 0;
    D_00426360_2CB3E0[0] = func_002E58A0_2CB3E0(&s);
    D_00426370_2CB3E0[0] = 0;
  }
}

extern volatile int D_00426394_2CB1A8[] __asm__("D_00426394"), D_00426398_2CB1A8[] __asm__("D_00426398"), D_00426360_2CB1A8[] __asm__("D_00426360"), D_00426370_2CB1A8[] __asm__("D_00426370"), D_00426354_2CB1A8[] __asm__("D_00426354");
extern int D_00426350_2CB1A8[] __asm__("D_00426350"); extern volatile int D_0062B64C[]; extern void (*D_0062B640_2CB1A8[])(int) __asm__("D_0062B640"); extern char D_0049DFA8[];
void func_002E58E0_2CB1A8(int) __asm__("func_002E58E0"); void func_002E56E0(void); void func_002E7940_2CB1A8(char *, ...) __asm__("func_002E7940");
// MATCH func_002CB1A8
void FUN_002cb1a8(void) {
  for (;;) {
    func_002E58E0_2CB1A8(D_00426360_2CB1A8[0]);
    if (D_00426394_2CB1A8[0] == -1) {
      D_00426370_2CB1A8[0] = 0; D_00426394_2CB1A8[0] = 0; D_00426354_2CB1A8[0] = 0; D_0062B64C[0] = 0;
      func_002E56E0();
    }
    if (D_00426350_2CB1A8[0] > 0) func_002E7940_2CB1A8(D_0049DFA8, D_0062B640_2CB1A8[0], D_00426398_2CB1A8[0]);
    if (D_0062B640_2CB1A8[0] != 0 && D_00426398_2CB1A8[0] != 0) D_0062B640_2CB1A8[0](D_00426398_2CB1A8[0]);
    D_00426370_2CB1A8[0] = 0;
  }
}

typedef struct { char p[36]; int server; char q[0x18]; } Cl_2CB978;
extern volatile int D_00426368_2CB978[] __asm__("D_00426368"); extern int D_00426350_2CB978[] __asm__("D_00426350"), D_0042635C[], D_00426378[], D_0062B650_2CB978[] __asm__("D_0062B650"); extern char D_0062B658_2CB978[] __asm__("D_0062B658");
extern Cl_2CB978 D_00427510_2CB978 __asm__("D_00427510"); extern char D_0049E040[], D_0049E068[];
void func_002E7940_2CB978(char *, ...) __asm__("func_002E7940"); void func_002CB3E0_2CB978(void) __asm__("func_002CB3E0"); int func_002E58F0_2CB978(int) __asm__("func_002E58F0"); void func_002E58C0_2CB978(int) __asm__("func_002E58C0");
void func_002E57A0_2CB978(int, void *) __asm__("func_002E57A0"); int func_002CBB80(int); void func_002E80E8_2CB978(int) __asm__("func_002E80E8");
int func_002E8758_2CB978(Cl_2CB978 *, unsigned, int) __asm__("func_002E8758");
// MATCH func_002CB978
int FUN_002cb978(int a) {
  int i;
  func_002CB3E0_2CB978();
  i = func_002E58F0_2CB978(D_00426368_2CB978[0]);
  if (D_00426368_2CB978[0] != i) {
    if (D_00426350_2CB978[0] > 0) func_002E7940_2CB978(D_0049E040, a, D_0042635C[0]);
    return 0;
  }
  D_0042635C[0] = a;
  func_002E57A0_2CB978(D_0062B650_2CB978[0], D_0062B658_2CB978);
  if (func_002CBB80(1) != 0) { func_002E58C0_2CB978(D_00426368_2CB978[0]); return 0; }
  func_002E80E8_2CB978(0);
  if (D_00426378[0] < 0) {
    for (;;) {
      if (func_002E8758_2CB978(&D_00427510_2CB978, 0x80000595, 0) < 0) {
        if (D_00426350_2CB978[0] > 0) func_002E7940_2CB978(D_0049E068);
        i = 0x100000;
        do { i--; } while (i != -1);
        continue;
      }
      if (D_00427510_2CB978.server != 0) break;
      i = 0x100000;
      do { i--; } while (i != -1);
    }
    D_00426378[0] = 0;
  }
  return 1;
}

typedef struct { char p[36]; int server; char q[0x18]; } Cl_2CBC90;
extern volatile int D_0042636C_2CBC90[] __asm__("D_0042636C"); extern int D_00426350_2CBC90[] __asm__("D_00426350"), D_00426358[], D_00426388[], D_0062B650_2CBC90[] __asm__("D_0062B650"); extern char D_0062B658_2CBC90[] __asm__("D_0062B658");
extern Cl_2CBC90 D_00427D88_2CBC90 __asm__("D_00427D88"); extern char D_0049E0A0[], D_0049E0C8[];
void func_002E7940_2CBC90(char *, ...) __asm__("func_002E7940"); void func_002CB3E0_2CBC90(void) __asm__("func_002CB3E0"); int func_002E58F0_2CBC90(int) __asm__("func_002E58F0"); void func_002E58C0_2CBC90(int) __asm__("func_002E58C0");
void func_002E57A0_2CBC90(int, void *) __asm__("func_002E57A0"); int func_002CBC20(int); void func_002E80E8_2CBC90(int) __asm__("func_002E80E8");
int func_002E8758_2CBC90(Cl_2CBC90 *, unsigned, int) __asm__("func_002E8758");
// MATCH func_002CBC90
int FUN_002cbc90(int a) {
  int i;
  func_002CB3E0_2CBC90();
  i = func_002E58F0_2CBC90(D_0042636C_2CBC90[0]);
  if (D_0042636C_2CBC90[0] != i) {
    if (D_00426350_2CBC90[0] > 0) func_002E7940_2CBC90(D_0049E0A0, a, D_00426358[0]);
    return 0;
  }
  D_00426358[0] = a;
  func_002E57A0_2CBC90(D_0062B650_2CBC90[0], D_0062B658_2CBC90);
  if (func_002CBC20(1) != 0) { func_002E58C0_2CBC90(D_0042636C_2CBC90[0]); return 0; }
  func_002E80E8_2CBC90(0);
  if (D_00426388[0] < 0) {
    for (;;) {
      if (func_002E8758_2CBC90(&D_00427D88_2CBC90, 0x80000593, 0) < 0) {
        if (D_00426350_2CBC90[0] > 0) func_002E7940_2CBC90(D_0049E0C8);
        i = 0x100000;
        do { i--; } while (i != -1);
        continue;
      }
      if (D_00427D88_2CBC90.server != 0) break;
      i = 0x100000;
      do { i--; } while (i != -1);
    }
    D_00426388[0] = 0;
  }
  return 1;
}


#define R(a) (*(volatile unsigned *)(a))
// MATCH func_002CFC00
unsigned FUN_002cfc00(int mode) {
  unsigned r = 0;
  int v;
  switch (mode) {
  case 0:
    do { v = R(0x10002010); } while (v < 0);
    r = 0;
    break;
  case 1:
    r = R(0x10002010) >> 31;
    break;
  }
  return r;
}

typedef struct { char p[36]; int server; char q[0x18]; } Cl_2CB640;
typedef struct { unsigned lsn; unsigned size; char name[16]; char date[8]; char flag[4]; } F_2CB640;
typedef struct { char c[36]; } F36_2CB640;
typedef struct { char p[36]; char name[256]; void *self; int arg; } Q_2CB640;
extern volatile int D_00426368_2CB640[] __asm__("D_00426368"); extern int D_00426350_2CB640[] __asm__("D_00426350"), D_0042635C_2CB640[] __asm__("D_0042635C"), D_00426380_2CB640[] __asm__("D_00426380"), D_0062B650_2CB640[] __asm__("D_0062B650");
extern char D_0062B658_2CB640[] __asm__("D_0062B658"); extern Cl_2CB640 D_0062B840; extern Q_2CB640 D_0062B6C0; extern int D_0062B800[];
extern char D_0049DFD0[], D_0049DFF0[], D_0049E008[], D_0049E018[], D_0049E028[];
void func_002E7940_2CB640(char *, ...) __asm__("func_002E7940"); void func_002CB3E0_2CB640(void) __asm__("func_002CB3E0"); int func_002E58F0_2CB640(int) __asm__("func_002E58F0"); void func_002E58C0_2CB640(int) __asm__("func_002E58C0");
void func_002E57A0_2CB640(int, void *) __asm__("func_002E57A0"); int func_002CBB80_2CB640(int) __asm__("func_002CBB80"); void func_002E80E8_2CB640(int) __asm__("func_002E80E8"); void func_002E8038_2CB640(void *, int) __asm__("func_002E8038");
int func_002E8758_2CB640(Cl_2CB640 *, unsigned, int) __asm__("func_002E8758");
int func_002E8928_2CB640(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928");
// MATCH func_002CB640
int FUN_002cb640(F_2CB640 *file, char *name, int arg) {
  int i, j, r;
  Q_2CB640 *q;
  func_002CB3E0_2CB640();
  i = func_002E58F0_2CB640(D_00426368_2CB640[0]);
  if (D_00426368_2CB640[0] != i) return 0;
  D_0042635C_2CB640[0] = 1;
  func_002E57A0_2CB640(D_0062B650_2CB640[0], D_0062B658_2CB640);
  if (func_002CBB80_2CB640(1) != 0) { func_002E58C0_2CB640(D_00426368_2CB640[0]); return 0; }
  func_002E80E8_2CB640(0);
  if (D_00426380_2CB640[0] < 0) {
    for (;;) {
      if (func_002E8758_2CB640(&D_0062B840, 0x80000597, 0) < 0) {
        if (D_00426350_2CB640[0] > 0) func_002E7940_2CB640(D_0049DFD0);
        j = 0x100000;
        do { j--; } while (j != -1);
        continue;
      }
      if (D_0062B840.server != 0) { D_00426380_2CB640[0] = 0; break; }
      j = 0x100000;
      do { j--; } while (j != -1);
    }
  }
  D_0062B6C0.name[0] = name[0];
  i = 0;
  if (D_0062B6C0.name[0] != 0) {
    do {
      i++;
      if (i >= 256) break;
    } while ((D_0062B6C0.name[i] = name[i]) != 0);
  }
  if (i == 256) D_0062B6C0.name[255] = 0;
  if (D_00426350_2CB640[0] > 0) func_002E7940_2CB640(D_0049DFF0, D_0062B6C0.name);
  q = &D_0062B6C0;
  q->arg = arg;
  q->self = q;
  func_002E8038_2CB640(q, 300);
  if (func_002E8928_2CB640(&D_0062B840, 0, 0, q, 300, D_0062B800, 4, 0, 0) < 0) { func_002E58C0_2CB640(D_00426368_2CB640[0]); return 0; }
  *(F36_2CB640 *)file = *(F36_2CB640 *)((unsigned)q | 0x20000000);
  if (D_00426350_2CB640[0] > 0) {
    func_002E7940_2CB640(D_0049E008, file->name);
    if (D_00426350_2CB640[0] > 0) {
      func_002E7940_2CB640(D_0049E018, file->size);
      if (D_00426350_2CB640[0] > 0) func_002E7940_2CB640(D_0049E028, file->lsn);
    }
  }
  r = *(int *)((unsigned)D_0062B800 | 0x20000000);
  func_002E58C0_2CB640(D_00426368_2CB640[0]);
  return r;
}


int func_002C7318_2C6B30(void *, int) __asm__("func_002C7318");
void func_002C6CD0_2C6B30(void *, int *, int *, int, int, int, int, int) __asm__("func_002C6CD0");
// MATCH func_002C6B30
void FUN_002c6b30(void *d, int PMV[2][2][2], int *dmvector, int mvfs[2][2], int s, int motion_vector_count, int mv_format, int h_r_size, int v_r_size, int dmv, int mvscale) {
  if (motion_vector_count == 1) {
    if (mv_format == 0 && !dmv) {
      mvfs[1][s] = mvfs[0][s] = func_002C7318_2C6B30(d, 1);
    }
    func_002C6CD0_2C6B30(d, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
    PMV[1][s][0] = PMV[0][s][0];
    PMV[1][s][1] = PMV[0][s][1];
  } else {
    mvfs[0][s] = func_002C7318_2C6B30(d, 1);
    func_002C6CD0_2C6B30(d, PMV[0][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
    mvfs[1][s] = func_002C7318_2C6B30(d, 1);
    func_002C6CD0_2C6B30(d, PMV[1][s], dmvector, h_r_size, v_r_size, dmv, mvscale, 0);
  }
}

typedef struct { char p[16]; unsigned char *ev; } Sq_2D3190;
typedef struct { volatile unsigned flags; int pc; int w8; int w12; char p10[0x12]; unsigned short h34, h36, h38, h40, h42, h44; char p2e[0x22]; unsigned char b50; } Tk_2D3190;
Sq_2D3190 *func_002CFFA0_2D3190(void) __asm__("func_002CFFA0");
// MATCH func_002D3190
void FUN_002d3190(Tk_2D3190 *t) {
  Sq_2D3190 *s = func_002CFFA0_2D3190();
  switch (s->ev[2]) {
  case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
  case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
    t->h44 = s->ev[2];
    t->h40 = 2;
    break;
  case 0x14:
    t->h36 = t->b50;
    t->w12 = t->pc;
    t->h40 = 0;
    t->h42 = 0;
    break;
  case 0x1e:
    if (t->h38 == 127) {
      t->flags |= 0x80;
    } else if (t->h34 >= t->h38) {
      t->w12 = 0;
      t->flags &= ~0x80;
      t->h34 = 0;
    } else {
      t->h34++;
      t->flags |= 0x80;
    }
    t->h40 = 0;
    break;
  case 0x10:
    t->h40 = 1;
    break;
  case 0x7f:
    t->h40 = 2;
    t->h44 = 255;
    break;
  }
  t->pc += 3;
}

extern volatile int D_00426394_2CB108[] __asm__("D_00426394"), D_00426370_2CB108[] __asm__("D_00426370"); extern volatile int D_00426398[], D_00426368_2CB108[] __asm__("D_00426368"), D_00426360_2CB108[] __asm__("D_00426360"); extern volatile int D_00426354_2CB108[] __asm__("D_00426354"); extern int D_0062B640[];
volatile unsigned int func_002E58D0_2CB108(int) __asm__("func_002E58D0");
// MATCH func_002CB108
void FUN_002cb108(int *p) {
  int z;
  D_00426394_2CB108[0] = p[0];
  D_00426398[0] = D_00426394_2CB108[0];
  if (D_00426394_2CB108[0] == 11) { D_00426394_2CB108[0] = 0; D_00426370_2CB108[0] = 0; return; }
  z = 0;
  func_002E58D0_2CB108(D_00426368_2CB108[0]);
  if (D_00426354_2CB108[0] != z && D_0062B640[0] != 0) func_002E58D0_2CB108(D_00426360_2CB108[0]);
  else D_00426370_2CB108[0] = z;
  D_00426394_2CB108[0] = z;
}

typedef struct { int attr; void *entry; void *stack; int size; void *gp; int prio; } Th_2CB268;
extern int D_00426354_2CB268[] __asm__("D_00426354"); extern int D_0062B650[]; extern char D_0062B658[]; extern Th_2CB268 D_0062B688; extern int _gp_2CB268[] __asm__("D_004A7C70");
int func_002E5790(void); volatile int func_002E57A0(int, void *); int func_002E56A0(Th_2CB268 *); void func_002E56C0(int, int); void func_002E5730(int, int); void func_002CB1A8_2CB268(void) __asm__("func_002CB1A8");
// MATCH func_002CB268
int FUN_002cb268(int prio, void *stack, int size) {
  int r = 1;
  if (D_00426354_2CB268[0] == 0) {
    D_0062B650[0] = func_002E5790();
    func_002E57A0(D_0062B650[0], D_0062B658);
    {
    Th_2CB268 *t = &D_0062B688;
    t->size = size; t->gp = _gp_2CB268; t->entry = (void *)func_002CB1A8_2CB268; t->stack = stack; t->prio = prio;
    D_00426354_2CB268[0] = func_002E56A0(t);
    }
    func_002E56C0(D_00426354_2CB268[0], 0);
  } else {
    func_002E5730(D_00426354_2CB268[0], prio);
    r = 0;
  }
  return r;
}

typedef struct 
{
  unsigned flags;
  int pc;
  char *base;
  int pos;
  int tick;
  unsigned time;
  char p18[6];
  unsigned short tempo;
} Trk_2D33D8;
// MATCH func_002D33D8
void FUN_002d33d8(Trk_2D33D8 *t)
{
  unsigned v = 0;
  char *b = t->base;
  unsigned char c;
  do
  {
    c = b[t->pc++];
    v = v << 7;
    v = v | (c & 0x7f);
  }
  while (c & 0x80);
  if (t->tempo != 0)
  {
    t->time += v * 0x1000;
  }
}

#define R(a) (*(volatile unsigned *)(a))
extern u128 D_004260B0_2BF848[2] __asm__("D_004260B0");
// MATCH func_002BF848
void FUN_002bf848(void) { register unsigned t __asm__("$4") = 0; R(0x10003c10) = 1; R(0x10003c20) = 2; __asm__ volatile("sync"); __asm__ volatile("cfc2 %0, $28" : "+r"(t)); t = t | 0x200; __asm__ volatile("ctc2 %0, $28" : : "r"(t));  __asm__ volatile("sync.p"); *(volatile u128 *)0x10005000 = D_004260B0_2BF848[0]; *(volatile u128 *)0x10005000 = D_004260B0_2BF848[1]; R(0x10003000) = 1; }

// MATCH func_002E7120
int FUN_002e7120(double d) { long e; unsigned long u; { union { double d; unsigned long u; } x; x.d = d; u = x.u; } e = (u << 1) >> 53; e -= 0x433; if (e < -0x35) return 0; if (0xc < e) return 9999; u = (u << 12) >> 12; u |= 0x10000000000000UL; if (e < 0) { e = -e; u = u >> (int)(e - 2); if ((u & 3) == 3) u = (u >> 2) + 1; else u = u >> 2; } else u = u << (int)e; return (int)u; }

