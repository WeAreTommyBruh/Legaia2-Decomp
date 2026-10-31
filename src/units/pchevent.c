/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A48B8;
// MATCH func_0020BD40
void pchevent_0020bd40(int a) { D_004A48B8 = a != 0; }

extern int D_004A1444, D_004A140C, D_004A46B8;
// MATCH func_0020D2B8
void pchevent_0020d2b8(int a) { if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) D_004A46B8 = 0; }

extern int D_004A45E4, D_004A4960; void func_0020B978(int, int);
// MATCH func_0020F0E0
int pchevent_0020f0e0(int a) { if (a & 8) { func_0020B978(D_004A45E4, D_004A4960); return -1; } return 0; }

// MATCH func_0020BCC0
char *pchevent_0020bcc0(char *s) { char *p = s; while (*p != 0) { unsigned char c = *p; if ((unsigned char)(c - 97) < 26) *p = c - 32; p++; } return s; }

extern char D_00454D80[]; extern int D_004A45E4_002105E8 __asm__("D_004A45E4"), D_004A46A8, D_004A46AC, D_004A6B14, D_004A4648, D_004A4660, D_004A4614, D_004A4664, D_004A4668, D_004A466C, D_004A4624, D_004A4628, D_004A4670_2105E8 __asm__("D_004A4670"), D_004A4674_2105E8 __asm__("D_004A4674"), D_004A4678; void *func_00162130(int, void *, int); int func_0020B508(void *, int);
// MATCH func_002105E8
void pchevent_002105e8(void) { D_004A45E4_002105E8 = func_0020B508(func_00162130(20, D_00454D80, 2687), 8); D_004A46A8 = 0; D_004A46AC = 0; D_004A6B14 = 0; D_004A4648 = 0; D_004A4660 = 0; D_004A4614 = 0; D_004A4664 = 0; D_004A4668 = 0; D_004A466C = 0; D_004A4624 = 0; D_004A4628 = 0; D_004A4670_2105E8 = 0; D_004A4674_2105E8 = 0; D_004A4678 = 0; }

extern int D_004A45E4_0020FE28 __asm__("D_004A45E4"), D_004A4960_0020FE28 __asm__("D_004A4960"); extern char D_00455318[]; int func_002DCE40_0020FE28(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FE28
int pchevent_0020fe28(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FE28(buf, D_00455318); func_0020B858(D_004A45E4_0020FE28, buf); D_004A4960_0020FE28++; } return 0; }

extern int D_004A45E4_0020FCE8 __asm__("D_004A45E4"), D_004A4960_0020FCE8 __asm__("D_004A4960"), D_004A4690, D_004A4694; extern char D_004552D8[]; int func_002DCE40_0020FCE8(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FCE8
int pchevent_0020fce8(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FCE8(buf, D_004552D8, D_004A4690, D_004A4694); func_0020B858(D_004A45E4_0020FCE8, buf); D_004A4960_0020FCE8++; } return 0; }

extern int D_004A45E4_0020FD38 __asm__("D_004A45E4"), D_004A4960_0020FD38 __asm__("D_004A4960"), D_004A4698, D_004A469C; extern char D_004552F0[]; int func_002DCE40_0020FD38(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FD38
int pchevent_0020fd38(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FD38(buf, D_004552F0, D_004A4698, D_004A469C); func_0020B858(D_004A45E4_0020FD38, buf); D_004A4960_0020FD38++; } return 0; }

extern int D_004A45E4_0020FFD0 __asm__("D_004A45E4"), D_004A4960_0020FFD0 __asm__("D_004A4960"), D_004A46AC_0020FFD0 __asm__("D_004A46AC"); extern char D_00455358[]; int func_002DCE40_0020FFD0(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FFD0
int pchevent_0020ffd0(int f) { char buf[512]; if (f & 8) { if (D_004A46AC_0020FFD0 != 0) { func_002DCE40_0020FFD0(buf, D_00455358); func_0020B858(D_004A45E4_0020FFD0, buf); D_004A4960_0020FFD0++; } } return 0; }

extern int D_004A45E4_0020FE70 __asm__("D_004A45E4"), D_004A4960_0020FE70 __asm__("D_004A4960"); int func_002DCE40_0020FE70(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FE70 __asm__("D_004A46AC"), D_004A46BC, D_004A46C0; extern char D_00455328[]; int func_002129C8(int, int *, int *, int, int);
// MATCH func_0020FE70
int pchevent_0020fe70(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FE70 != 0 && D_004A46BC >= 0 && D_004A46C0 >= 0) { if (func_002129C8(D_004A46AC_0020FE70, &x, &y, D_004A46BC, D_004A46C0) != 0) { func_002DCE40_0020FE70(buf, D_00455328, x); func_0020B858(D_004A45E4_0020FE70, buf); D_004A4960_0020FE70++; } } } return 0; }

extern int D_004A45E4_0020FEE8 __asm__("D_004A45E4"), D_004A4960_0020FEE8 __asm__("D_004A4960"); int func_002DCE40_0020FEE8(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FEE8 __asm__("D_004A46AC"), D_004A46BC_0020FEE8 __asm__("D_004A46BC"), D_004A46C0_0020FEE8 __asm__("D_004A46C0"); extern char D_00455338[]; int func_002129C8(int, int *, int *, int, int);
// MATCH func_0020FEE8
int pchevent_0020fee8(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FEE8 != 0 && D_004A46BC_0020FEE8 >= 0 && D_004A46C0_0020FEE8 >= 0) { if (func_002129C8(D_004A46AC_0020FEE8, &x, &y, D_004A46BC_0020FEE8, D_004A46C0_0020FEE8) != 0) { func_002DCE40_0020FEE8(buf, D_00455338, x); func_0020B858(D_004A45E4_0020FEE8, buf); D_004A4960_0020FEE8++; } } } return 0; }

extern int D_004A45E4_0020FF60 __asm__("D_004A45E4"), D_004A4960_0020FF60 __asm__("D_004A4960"); int func_002DCE40_0020FF60(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FF60 __asm__("D_004A46AC"), D_004A46C4; extern char D_00455348[]; int func_00212A48(int, int *, int *, int);
// MATCH func_0020FF60
int pchevent_0020ff60(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FF60 != 0 && D_004A46C4 >= 0) { if (func_00212A48(D_004A46AC_0020FF60, &x, &y, D_004A46C4) != 0) { func_002DCE40_0020FF60(buf, D_00455348, x); func_0020B858(D_004A45E4_0020FF60, buf); D_004A4960_0020FF60++; } } } return 0; }

extern int D_004A45E4_0020FC68 __asm__("D_004A45E4"), D_004A4960_0020FC68 __asm__("D_004A4960"); int func_002DCE40_0020FC68(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020FC68 __asm__("D_004A4614"), D_004A4618, D_004A4658; extern char D_004552C8[], D_004A48D8[], D_004A4790[]; char *func_00160C70(int, char *, int);
// MATCH func_0020FC68
int pchevent_0020fc68(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020FC68 > 0 && D_004A4618 >= 0) s = func_00160C70(D_004A4658, D_004A48D8, D_004A4618); else s = D_004A4790; func_002DCE40_0020FC68(buf, D_004552C8, s); func_0020B858(D_004A45E4_0020FC68, buf); D_004A4960_0020FC68++; } return 0; }

extern int D_004A45E4_0020F370 __asm__("D_004A45E4"), D_004A4960_0020F370 __asm__("D_004A4960"); int func_002DCE40_0020F370(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A45E8; extern int *D_004A6F78, *D_004A4668_0020F370 __asm__("D_004A4668"); extern char D_00455188[];
typedef struct { char p[500]; int w500; } Q_0020F370;
Q_0020F370 *func_0020BBD8(int);
// MATCH func_0020F370
int pchevent_0020f370(int f) { char buf[512]; if (f & 8) { if (D_004A45E8 >= 0) { Q_0020F370 *p = func_0020BBD8(D_004A45E8); if (p != 0) { func_002DCE40_0020F370(buf, D_00455188, D_004A6F78[D_004A45E8], D_004A4668_0020F370[p->w500 + 1]); func_0020B858(D_004A45E4_0020F370, buf); D_004A4960_0020F370++; } } } return 0; }

extern int D_004A45E4_0020F588 __asm__("D_004A45E4"), D_004A4960_0020F588 __asm__("D_004A4960"); int func_002DCE40_0020F588(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A45E8_0020F588 __asm__("D_004A45E8"); extern int *D_004A6F78_0020F588 __asm__("D_004A6F78"); extern float D_004A0450; extern char D_004551B8[];
typedef struct { char p[68]; float f68; } R_0020F588;
typedef struct { R_0020F588 *w0; } Q_0020F588;
Q_0020F588 *func_0020BBD8_0020F588(int) __asm__("func_0020BBD8");
// MATCH func_0020F588
int pchevent_0020f588(int f) { char buf[512]; Q_0020F588 *p; if (f & 8) { if (D_004A45E8_0020F588 >= 0) { p = func_0020BBD8_0020F588(D_004A45E8_0020F588); if (p != 0) { func_002DCE40_0020F588(buf, D_004551B8, D_004A6F78_0020F588[D_004A45E8_0020F588], (double)(p->w0->f68 * 180.0f / D_004A0450)); func_0020B858(D_004A45E4_0020F588, buf); D_004A4960_0020F588++; } } } return 0; }

typedef struct { char p[8]; int w8; } M_0020C3C0;
extern M_0020C3C0 *D_004A45E4_0020C3C0 __asm__("D_004A45E4"); extern int D_004A1444_0020C3C0 __asm__("D_004A1444"), D_004A140C_0020C3C0 __asm__("D_004A140C"); int func_0020B660(M_0020C3C0 *);
// MATCH func_0020C3C0
int pchevent_0020c3c0(int on) { if (on) { if (D_004A1444_0020C3C0 == 0) { if (D_004A140C_0020C3C0 & 8) { if (D_004A45E4_0020C3C0 != 0) { if (D_004A45E4_0020C3C0->w8 > 0) func_0020B660(D_004A45E4_0020C3C0); } } } } return 0; }

typedef struct { char p[8]; int w8; } M_0020C330;
extern M_0020C330 *D_004A45E4_0020C330 __asm__("D_004A45E4"); extern int D_004A1444_0020C330 __asm__("D_004A1444"), D_004A140C_0020C330 __asm__("D_004A140C"), D_004A1430, D_004A1434, D_004A4604; extern char D_00454FF8[], D_00455008[]; int func_00239568(char *, int, int, int); int func_0020BA70(M_0020C330 *, char *);
// MATCH func_0020C330
int pchevent_0020c330(int on) { if (D_004A45E4_0020C330 != 0) func_00239568(D_00454FF8, D_004A1430 + 16, D_004A1434 + 6, D_004A45E4_0020C330->w8); if (on) { if (D_004A1444_0020C330 == 0 && (D_004A140C_0020C330 & 8) && D_004A45E4_0020C330 != 0 && D_004A45E4_0020C330->w8 > 0) { func_0020BA70(D_004A45E4_0020C330, D_00455008); D_004A4604 = 0; } } return 0; }

extern int D_004A4624_0020C5C8 __asm__("D_004A4624"), D_004A1444_0020C5C8 __asm__("D_004A1444"), D_004A140C_0020C5C8 __asm__("D_004A140C"); extern char D_0041EFB0_0020C5C8[] __asm__("D_0041EFB0"); int func_0012EE30(int, char *, float, float);
// MATCH func_0020C5C8
int pchevent_0020c5c8(int on) { if (on && D_004A1444_0020C5C8 == 0 && (D_004A140C_0020C5C8 & 8) && D_004A4624_0020C5C8 != 0) func_0012EE30(D_004A4624_0020C5C8, D_0041EFB0_0020C5C8, 120.0f, 1.0f); return 0; }

typedef struct { char p[24]; unsigned w24; } R_0020C2A8;
typedef struct { R_0020C2A8 *w0; } Q_0020C2A8;
extern int D_004A1444_0020C2A8 __asm__("D_004A1444"), D_004A140C_0020C2A8 __asm__("D_004A140C"), D_004A45E8_0020C2A8 __asm__("D_004A45E8"), D_004A45F4; Q_0020C2A8 *func_0020BBD8_0020C2A8(int) __asm__("func_0020BBD8");
// MATCH func_0020C2A8
int pchevent_0020c2a8(int on) { Q_0020C2A8 *p; R_0020C2A8 *q; if (on) { if (D_004A1444_0020C2A8 == 0 && (D_004A140C_0020C2A8 & 8)) { if (D_004A45E8_0020C2A8 >= 0) { p = func_0020BBD8_0020C2A8(D_004A45E8_0020C2A8); if (p != 0) { q = p->w0; if (q != 0) { if (D_004A45F4 != 0) q->w24 |= 0x10000000; else q->w24 &= ~0x10000000; } } } } } return 0; }

typedef struct { char p[209]; char b209; } R_0020C180;
typedef struct { R_0020C180 *w0; } Q_0020C180;
extern int D_004A45E8_0020C180 __asm__("D_004A45E8"); extern float D_004A4600; Q_0020C180 *func_0020BBD8_0020C180(int) __asm__("func_0020BBD8");
// MATCH func_0020C180
int pchevent_0020c180(void) { if (D_004A45E8_0020C180 >= 0) { Q_0020C180 *p = func_0020BBD8_0020C180(D_004A45E8_0020C180); if (p != 0) { R_0020C180 *q = p->w0; if (q != 0) q->b209 = (int)(D_004A4600 * 128.0f); } } return 0; }

typedef struct { char p[64]; float f64, f68, f72; } R_0020C048;
typedef struct { R_0020C048 *w0; } Q_0020C048;
extern int D_004A45E8_0020C048 __asm__("D_004A45E8"); extern float D_004A0410; extern float D_003C0F10[]; Q_0020C048 *func_0020BBD8_0020C048(int) __asm__("func_0020BBD8");
// MATCH func_0020C048
int pchevent_0020c048(void) { if (D_004A45E8_0020C048 >= 0) { Q_0020C048 *p = func_0020BBD8_0020C048(D_004A45E8_0020C048); if (p != 0) { R_0020C048 *q = p->w0; q->f64 = D_003C0F10[0] * D_004A0410 / 180.0f; q->f68 = D_003C0F10[1] * D_004A0410 / 180.0f; q->f72 = D_003C0F10[2] * D_004A0410 / 180.0f; } } return 0; }

typedef struct { char p[12]; float f12; } R_0020C0D8;
typedef struct { char p[464]; R_0020C0D8 *w464; } Q_0020C0D8;
extern int D_004A45E8_0020C0D8 __asm__("D_004A45E8"); extern float D_004A45F8, D_004A0414; Q_0020C0D8 *func_0020BBD8_0020C0D8(int) __asm__("func_0020BBD8");
// MATCH func_0020C0D8
int pchevent_0020c0d8(void) { if (D_004A45E8_0020C0D8 >= 0) { Q_0020C0D8 *p = func_0020BBD8_0020C0D8(D_004A45E8_0020C0D8); if (p != 0) { R_0020C0D8 *q = p->w464; if (q != 0) q->f12 = D_004A45F8 * D_004A0414 / 180.0f; } } return 0; }

extern volatile int D_004A1444_0020D2E0 __asm__("D_004A1444"), D_004A140C_0020D2E0 __asm__("D_004A140C"); extern int D_004A46AC_0020D2E0 __asm__("D_004A46AC"), D_004A45E8_x; extern int D_004A46BC_0020D2E0 __asm__("D_004A46BC"); int func_002128C8(int, int); int func_00212C18(int, int, int);
// MATCH func_0020D2E0
void pchevent_0020d2e0(int on) { int i, n; if (on) { if (D_004A1444_0020D2E0 == 0 && (D_004A140C_0020D2E0 & 8) && D_004A46AC_0020D2E0 != 0 && D_004A46BC_0020D2E0 >= 0) { n = func_002128C8(D_004A46AC_0020D2E0, D_004A46BC_0020D2E0); for (i = 0; i < n; i++) func_00212C18(D_004A46AC_0020D2E0, D_004A46BC_0020D2E0, i); } } }

extern int D_004A45E4_0020F970 __asm__("D_004A45E4"), D_004A4960_0020F970 __asm__("D_004A4960"); int func_002DCE40_0020F970(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020F970 __asm__("D_004A4614"), D_004A4618_0020F970 __asm__("D_004A4618"), D_004A4658_0020F970 __asm__("D_004A4658"); extern char D_00455260[], D_004A48D8_0020F970[] __asm__("D_004A48D8"), D_004A4790_0020F970[] __asm__("D_004A4790"); extern float D_003C0F20[]; char *func_00160C70(int, char *, int);
// MATCH func_0020F970
int pchevent_0020f970(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020F970 > 0 && D_004A4618_0020F970 >= 0) s = func_00160C70(D_004A4658_0020F970, D_004A48D8_0020F970, D_004A4618_0020F970); else s = D_004A4790_0020F970; func_002DCE40_0020F970(buf, D_00455260, s, (double)D_003C0F20[0], (double)D_003C0F20[1], (double)D_003C0F20[2]); func_0020B858(D_004A45E4_0020F970, buf); D_004A4960_0020F970++; } return 0; }

extern int D_004A45E4_0020FB88 __asm__("D_004A45E4"), D_004A4960_0020FB88 __asm__("D_004A4960"); int func_002DCE40_0020FB88(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020FB88 __asm__("D_004A4614"), D_004A4618_0020FB88 __asm__("D_004A4618"), D_004A4658_0020FB88 __asm__("D_004A4658"); extern char D_004552A8[], D_004A48D8_0020FB88[] __asm__("D_004A48D8"), D_004A4790_0020FB88[] __asm__("D_004A4790"); extern float D_003C0F30[]; char *func_00160C70(int, char *, int);
// MATCH func_0020FB88
int pchevent_0020fb88(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020FB88 > 0 && D_004A4618_0020FB88 >= 0) s = func_00160C70(D_004A4658_0020FB88, D_004A48D8_0020FB88, D_004A4618_0020FB88); else s = D_004A4790_0020FB88; func_002DCE40_0020FB88(buf, D_004552A8, s, (double)D_003C0F30[0], (double)D_003C0F30[1], (double)D_003C0F30[2]); func_0020B858(D_004A45E4_0020FB88, buf); D_004A4960_0020FB88++; } return 0; }

extern int D_004A1444_00210188 __asm__("D_004A1444"); extern int D_004A49DC, D_004A49D8, D_004A49E0, D_004A49D0; extern int D_00329640[];
// MATCH func_00210188
void pchevent_00210188(int on) { if (on && D_004A1444_00210188 == 0) D_00329640[D_004A49D0] = D_004A49D8 | (D_004A49DC << 8) | (D_004A49E0 << 16); }

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B508;
extern char D_00455618[], D_00454D80_0020B508[] __asm__("D_00454D80"); int *func_00162130_0020B508(int, char *, int) __asm__("func_00162130");
// MATCH func_0020B508
O_0020B508 *pchevent_0020b508(O_0020B508 *o, int n) { int *p, *q; int i; o->vt = D_00455618; o->w4 = n; o->w0 = n; o->w8 = 0; if (n == 0) o->w12 = 0; else { p = func_00162130_0020B508(n * 4, D_00454D80_0020B508, 105); o->w12 = p; if (p != 0) { q = p; i = o->w4; q = p; if (i > 0) { do { *q++ = 0; i--; } while (i != 0); } } } return o; }

extern int D_004A140C_0020E3F8 __asm__("D_004A140C"); extern float D_004A13F4, D_004A13F8; extern float D_003C0F30_0020E3F8[] __asm__("D_003C0F30");
// MATCH func_0020E3F8
void pchevent_0020e3f8(void) { float a = 0, b = 0, c = 0; if (D_004A140C_0020E3F8 & 2) { a = D_004A13F4; b = D_004A13F8; } else if (D_004A140C_0020E3F8 & 1) c = D_004A13F4; D_003C0F30_0020E3F8[0] += b; D_003C0F30_0020E3F8[1] += a; D_003C0F30_0020E3F8[2] += c; }

extern char D_00454D80_0020B858[] __asm__("D_00454D80"); int func_002DD5E0_0020B858(char *) __asm__("func_002DD5E0"); void *func_00162130_0020B858(int, char *, int) __asm__("func_00162130"); void func_002DD4CC_0020B858(void *, char *) __asm__("func_002DD4CC"); void func_0020B760(int *, int);
// MATCH func_0020B858
int pchevent_0020b858(int *o, char *s) { char *p; if (o[3] == 0) return 0; if (o[2] >= o[1]) { func_0020B760(o, (o[1] << 1) | 1); if (o[2] >= o[1]) return 0; } p = func_00162130_0020B858(func_002DD5E0_0020B858(s) + 1, D_00454D80_0020B858, 173); ((char **)o[3])[o[2]] = p; func_002DD4CC_0020B858(p, s); return ++o[2]; }

extern int D_004A45E4_0020FD88 __asm__("D_004A45E4");
extern int D_004A4960_0020FD88 __asm__("D_004A4960");
int func_002DCE40_0020FD88(void *, void *, ...) __asm__("func_002DCE40");
int func_0020B858_0020FD88(int, void *) __asm__("func_0020B858");
extern int D_004A46AC_0020FD88 __asm__("D_004A46AC");
extern int D_004A46BC_0020FD88 __asm__("D_004A46BC");
extern char D_00455308[];
extern char D_00455318_0020FD88[] __asm__("D_00455318");
int func_00212968(int, void *, void *, void *, int);
// MATCH func_0020FD88
int pchevent_0020fd88(int f)
{
  char buf[512];
  int a;
  int b;
  int c;
  if (f & 8)
  {
    if ((D_004A46AC_0020FD88 != 0) && (D_004A46BC_0020FD88 >= 0))
    {
 do { c = -1; } while (0);
      if (func_00212968(D_004A46AC_0020FD88, &a, &b, &c, D_004A46BC_0020FD88))
      {
        func_002DCE40_0020FD88(buf, D_00455308, a);
        func_0020B858_0020FD88(D_004A45E4_0020FD88, buf);
        D_004A4960_0020FD88++;
        func_002DCE40_0020FD88(buf, D_00455318_0020FD88);
        func_0020B858_0020FD88(D_004A45E4_0020FD88, buf);
        D_004A4960_0020FD88++;
      }
    }
  }
  return 0;
}

typedef struct { char p[96]; float f96; } R_0020DDF8;
typedef struct { char p[476]; R_0020DDF8 *w476; } Q_0020DDF8;
extern volatile int D_004A1444_0020DDF8 __asm__("D_004A1444"), D_004A140C_0020DDF8 __asm__("D_004A140C"); extern int D_004A45E8_0020DDF8 __asm__("D_004A45E8"); extern float D_004A46D0, D_004A46D4; Q_0020DDF8 *func_0020BBD8_0020DDF8(int) __asm__("func_0020BBD8"); void func_0029F9B8_0020DDF8(R_0020DDF8 *, float) __asm__("func_0029F9B8");
// MATCH func_0020DDF8
void pchevent_0020ddf8(int on) { Q_0020DDF8 *p = func_0020BBD8_0020DDF8(D_004A45E8_0020DDF8); if (on) { if (D_004A1444_0020DDF8 == 0 && (D_004A140C_0020DDF8 & 0xc) && p != 0 && p->w476 != 0) { func_0029F9B8_0020DDF8(p->w476, D_004A46D0); p->w476->f96 = D_004A46D4; } } }

extern int D_004A1430_0020C7D0 __asm__("D_004A1430"); extern int D_004A1434_0020C7D0 __asm__("D_004A1434"); extern int D_004A4634; extern char D_004A48C0[]; extern char D_003C23C8[];
int func_00239568_0020C7D0(void *, int, int, int, int) __asm__("func_00239568");
// MATCH func_0020C7D0
int pchevent_0020c7d0(int a) { func_00239568_0020C7D0(D_004A48C0, D_004A1430_0020C7D0 + 6, D_004A1434_0020C7D0, a ? 0xffff : 0x808080, (int)D_003C23C8 + D_004A4634 * 10); return 0; }
