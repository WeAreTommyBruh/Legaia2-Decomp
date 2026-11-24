/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A1610;
extern char D_00321640[];
int func_001911F0(void *);
// MATCH func_00114360
int FUN_00114360(void) { if (D_004A1610 != 0) return func_001911F0(D_00321640); return 1; }

extern int D_004A1618, D_004A15F4, D_004A1638; extern char D_00321588[], D_00321550[]; void func_00113978(void); void func_001140C0(char *, int, char *); void func_001143C8(void);
// MATCH func_00114310
int FUN_00114310(void) { D_004A1618++; func_00113978(); func_001140C0(D_00321588, D_004A15F4, D_00321550); func_001143C8(); return D_004A1638; }

extern int D_004A15F4_001143C8 __asm__("D_004A15F4"), D_004A162C, D_004A1630; extern int D_00321588_001143C8[] __asm__("D_00321588"); extern char D_00321300[], D_00321640_001143C8[] __asm__("D_00321640"), D_00321550_001143C8[] __asm__("D_00321550"); void func_002E5D30(void); void func_002E6380(int); void func_00190DC0(int); void func_001948E8(char *); void func_002E56F0(int); void func_002E56B0(int); void func_002E6450_001143C8(int) __asm__("func_002E6450"); void func_002E55D0_001143C8(int, int) __asm__("func_002E55D0"); void func_002E55A0(int, int); void func_001926F8(int *); void func_00190FC0(char *); void func_001953F0(char *);
// MATCH func_001143C8
void FUN_001143c8(void) { func_002E5D30(); func_002E6380(3); func_00190DC0(D_004A15F4_001143C8); func_001948E8(D_00321300); func_002E56F0(D_004A162C); func_002E56B0(D_004A162C); func_002E56F0(D_004A1630); func_002E56B0(D_004A1630); func_002E6450_001143C8(2); func_002E55D0_001143C8(2, D_00321588_001143C8[44]); func_002E6380(2); func_002E55A0(2, D_00321588_001143C8[45]); func_001926F8(D_00321588_001143C8); func_00190FC0(D_00321640_001143C8); func_001953F0(D_00321550_001143C8); func_002E5D30(); }

typedef struct { char p0[16]; long *q; } Pk_115390;
typedef struct { char p0[8]; float w, h, s; int i20, i24; char p28[16]; unsigned u44; char p48[8]; unsigned u56, u60; char p64[8]; unsigned u72; } T_115390;
extern Pk_115390 D_00314C20;
void func_00190328(Pk_115390 *); void func_00190420(Pk_115390 *);
// MATCH func_00115390
void FUN_00115390(int *p, int a, int c, T_115390 *t)
{
    int x0, y0, x1, y1;
    long *q;
    unsigned long col;
    x0 = p[0] * 32 + 0x6c00;
    y0 = p[1] * 16 + 0x7900;
    x1 = x0 + (int)(t->w * 32.0f * t->s);
    y1 = y0 + (int)(t->h * 16.0f * t->s);
    { int n = (x0 < 0x9400) + (y0 < 0x8700) + (x1 > 0x6c00) + (y1 > 0x7900); if (n != 4) return; }
    func_00190328(&D_00314C20);
    q = D_00314C20.q;
    q[0] = 68;
    q[1] = 66;
    q[2] = 0x31001;
    q[3] = 71;
    q[4] = (long)t->i20 | 0x21320000L | 0x600000000L | (long)t->i24 << 37 | 0x2000000000000000L;
    q[5] = 6;
    q[6] = 94;
    q[7] = 0;
    q[8] = (unsigned long)t->u44 | (unsigned long)t->u60 << 32;
    q[9] = 2;
    col = (unsigned long)c | (unsigned long)c << 8 | (unsigned long)c << 16 | (unsigned long)a << 24 | 0x3f80000000000000L;
    q[10] = col;
    q[11] = 1;
    q[12] = (long)x0 | (long)y0 << 16 | (long)p[2] << 32;
    q[13] = 5;
    q[14] = (unsigned long)t->u56 | (unsigned long)t->u72 << 32;
    q[15] = 2;
    q[16] = col;
    q[17] = 1;
    q[18] = (long)x1 | (long)y1 << 16 | (long)p[2] << 32;
    q[19] = 5;
    q[20] = 0x5000d;
    q[21] = 71;
    D_00314C20.q = q + 22;
    func_00190420(&D_00314C20);
}

extern char D_00364F48[];
int func_00114660(int, int, int, int, int, int, int, int);
void func_00115390(int *, int, int, char *);
// MATCH func_00115FC0
void FUN_00115fc0(int *p, int t, int x, int flag, int c5, int c6)
{
    int w, m, sec, cs, q;
    cs = t / 50 % 60;
    q = t / 3000;
    m = q / 60;
    sec = q % 60;
    w = func_00114660(x, p[0], p[1], m, 2, c5, c6, '1');
    p[0] += 2;
    p[1]++;
    func_00115390(p, c5, c6, D_00364F48);
    p[0] += w - 1;
    p[1]--;
    func_00114660(x, p[0], p[1], sec, 2, c5, c6, '1');
    if (flag != 1) return;
    p[0] += 2;
    p[1]++;
    func_00115390(p, c5, 127, D_00364F48);
    p[0] += w - 1;
    p[1]--;
    func_00114660(x, p[0], p[1], cs, 2, c5, c6, '1');
}

typedef struct { int x, y, z, w; } __attribute__((aligned(8))) S_116358;
typedef struct { int i0; char p4[95]; signed char c99; char p100[4]; signed char c104; } O_116358;
typedef struct { float a, b, c, d; int i16, e20, e24; } M_116358;
extern M_116358 D_00360C34;
extern int D_00319680[];
extern int D_004A1B24;
O_116358 *func_0024FC70(int);
void func_00115090(float, float, float, S_116358 *, int, int, int, int, int, int);
void func_0023CB68(int);
void func_00114478(int, int, int, int, int, int);
int func_00114660(int, int, int, int, int, int, int, int);
// MATCH func_00116358
void FUN_00116358(int p1, S_116358 *src, int p3, int p4, int p5)
{
    O_116358 *o;
    S_116358 s;
    o = func_0024FC70(p1);
    if (o == 0) return;
    s = *src;
    func_00115090((float)(o->c99 % 10 * 24), (float)(o->c99 / 10 * 24), 0.5f, &s, 24, 24, D_00319680[0] + 0x3140, 0x3f40, p3, p4);
    s.x += 13;
    s.y += 1;
    func_0023CB68(p3);
    D_004A1B24 = 2;
    func_00114478(o->i0, s.x, s.y, 10, 10, p5);
    D_004A1B24 = 0;
    func_0023CB68(128);
    s.x += 98;
    s.y += 2;
    func_00115090(D_00360C34.a, D_00360C34.b, 1.0f, &s, (int)D_00360C34.c, (int)D_00360C34.d, D_00360C34.e20, D_00360C34.e24, p3, p4);
    s.x += 22;
    s.y -= 2;
    func_00114660(5, s.x, s.y, o->c104, 2, p3, p4, 17);
}


typedef struct { char p0[60]; int f60; char p64[112]; } E_116510_00116510;
typedef struct { float a, b, w, h, s; int i20, i24; char p28[184]; } T_116510_00116510;
extern E_116510_00116510 D_00419D18_116510[] __asm__("D_00419D18");
extern T_116510_00116510 D_00368A14_116510[] __asm__("D_00368A14");
extern int D_004A1B24_116510 __asm__("D_004A1B24");
int func_002561B8_116510(int, int) __asm__("func_002561B8"); int func_002561F8_116510(int, int) __asm__("func_002561F8"); unsigned func_00256218_116510(int, int) __asm__("func_00256218"); int battle_0012af38(int);
void func_00115090_116510(float, float, void *, int, int, int, int, float, int, int) __asm__("func_00115090");
void func_0023CB68_116510(int) __asm__("func_0023CB68");
void func_00114478_116510(int, int, int, int, int, int) __asm__("func_00114478");
int func_00114660_116510(int, int, int, int, int, int, int, int) __asm__("func_00114660");
// MATCH func_00116510
void FUN_00116510(int a, int b, int *p, int p4, int p5, int p6) { int o, hp, idx, i, k; unsigned f; T_116510_00116510 *e; o = func_002561B8_116510(b, a); if (o == 0) return; hp = func_002561F8_116510(b, a); idx = -1; i = 0; do { if (a == battle_0012af38(i)) idx = i; i++; } while (i < 3); if (idx < 0) return; if (D_00419D18_116510[idx].f60 < hp) { p5 = 64; p6 = 0x404040; } f = func_00256218_116510(b, a); k = 10; if ((f & 4) == 0) { k = (f & 0x20000) ? 6 : 0; if ((f & 0x200000) != 0) k = 6; if ((f & 0x40000) != 0) k = 2; if ((f & 0x100000) != 0) k = 4; if ((f & 2) != 0) k = 8; if ((f & 0x200) != 0) k = k + 1; } e = &D_00368A14_116510[k]; func_00115090_116510(e->a, e->b, p, (int)e->w, (int)e->h, e->i20, e->i24, e->s, p4, p5); func_0023CB68_116510(p4); { int x = p[0], y = p[1]; D_004A1B24_116510 = 2; func_00114478_116510(o, x + 12, y, 10, 10, p6); } D_004A1B24_116510 = 0; func_0023CB68_116510(128); func_00114660_116510(5, p[0] + 128, p[1], hp, 3, p4, p5, 17); }
