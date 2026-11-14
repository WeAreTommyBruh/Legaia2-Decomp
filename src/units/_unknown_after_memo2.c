/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A11F0;
// MATCH func_00109620
int FUN_00109620(void) { return D_004A11F0 != 0; }

extern int D_00343028[];
// MATCH func_0010A250
int FUN_0010a250(void) { int r = D_00343028[0] & 8; return r == 0; }

// MATCH func_0010A268
int FUN_0010a268(int *p, int v) { int o = *p; if (o & 8) return o; *p = v; return v; }

extern int D_00343028[];
void func_002D4058(int);
// MATCH func_0010A288
void FUN_0010a288(int a, int b) { if ((D_00343028[0] & 8) == 0) func_002D4058(b); }

void func_00108B80(void);
// MATCH func_001098C8
void FUN_001098c8(int a, int b) { if (b & 1) func_00108B80(); }

typedef struct { char pad[360]; char *a360; } G_108b20_00108B20;
extern G_108b20_00108B20 *D_0036CB78[];
// MATCH func_00108B20
void FUN_00108b20(void) { short m = -2; char *p = D_0036CB78[0]->a360; int i; for (i = 11; i >= 0; i--) { *(short *)(p + 250) = m; *(short *)(p + 3322) = m; p += 256; } }

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_108b98_00108B98;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_00108B98
void FUN_00108b98(F_108b98_00108B98 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

extern char D_0042CD90[]; extern int D_004A118C_00109C68 __asm__("D_004A118C"); extern char *D_004A12B0_00109C68 __asm__("D_004A12B0"); void func_001118F8_00109C68(char *, ...) __asm__("func_001118F8"); void func_002D3FE0(int, int); void func_002D3FF8(int, int); void func_002D4010(int, int, int);
// MATCH func_00109C68
int FUN_00109c68(void) { if (D_004A118C_00109C68 & 0x40) func_001118F8_00109C68(D_0042CD90, D_004A12B0_00109C68); func_002D3FE0(0, 0x1fffff); func_002D3FE0(1, 0x1dffff); func_002D3FF8(0, 260); func_002D3FF8(1, 260); func_002D4010(0, 32767, 32767); func_002D4010(1, 32767, 32767); return 1; }

extern int D_00343028_00109630[] __asm__("D_00343028"); extern int D_004A3850_00109630 __asm__("D_004A3850"), D_004A118C_00109630 __asm__("D_004A118C"); extern volatile int D_004A1190_00109630 __asm__("D_004A1190"); extern char *D_004A12B0_00109630 __asm__("D_004A12B0"); extern char D_0042CBB8[]; void func_001118F8_00109630(char *, ...) __asm__("func_001118F8"); void func_002E57C0(void); int func_002D38A0(void); int func_002D3A98(int); void func_002D3968(void);
// MATCH func_00109630
void FUN_00109630(void) { if (!(D_00343028_00109630[0] & 8) && D_004A3850_00109630 != 2) { if (D_004A118C_00109630 & 0x40) func_001118F8_00109630(D_0042CBB8, D_004A12B0_00109630); for (;;) { func_002E57C0(); while (func_002D38A0() != 0) ; if (D_004A1190_00109630 == 0) D_004A1190_00109630 = func_002D3A98(0); func_002D3968(); } } }

typedef struct { char p[4]; int w4, w8; } O_0010AB58;
extern int D_00343028_0010AB58[] __asm__("D_00343028"); extern int D_004A3850_0010AB58 __asm__("D_004A3850"); int func_0010AC70(int, int, char *, int, char *, int, int);
// MATCH func_0010AB58
int FUN_0010ab58(int a, int b, O_0010AB58 *c, int d) { if (D_00343028_0010AB58[0] & 8) return 1; if (D_004A3850_0010AB58 == 2) return 1; if (c == 0) return -1; return func_0010AC70(a, b, (char *)c + 128, c->w4, (char *)c + 128 + c->w4, c->w8, d); }

typedef struct { char p[4]; int w4, w8; } O_0010ABC0;
extern int D_00343028_0010ABC0[] __asm__("D_00343028"); extern int D_004A3850_0010ABC0 __asm__("D_004A3850"); extern char D_0042CF40[], D_0042CF88[]; void func_001118F8_0010ABC0(char *, ...) __asm__("func_001118F8"); int func_0010B938(int, int, char *, int, char *, int, int);
// MATCH func_0010ABC0
int FUN_0010abc0(int a, int b, O_0010ABC0 *c, int d) { char *base, *end; int w4, w8; if (D_00343028_0010ABC0[0] & 8) return 1; if (D_004A3850_0010ABC0 == 2) return 1; if (c == 0) return -1; w4 = c->w4; base = (char *)c + 128; w8 = c->w8; end = (char *)c + (w4 + 128); if ((w4 & 0x7f) || (w8 & 0x7f)) { func_001118F8_0010ABC0(D_0042CF40, w4, w8, base, end, d); func_001118F8_0010ABC0(D_0042CF88); return -15; } return func_0010B938(a, b, base, w4, end, w8, d); }

typedef struct { char p[1484]; float f1484; char q[40]; float f1528; } O_0010A2B0;
extern int D_00343028_0010A2B0[] __asm__("D_00343028"); extern int D_004A118C_0010A2B0 __asm__("D_004A118C"); extern char *D_004A12B0_0010A2B0 __asm__("D_004A12B0"); extern char D_0042CE50[]; void func_001118F8_0010A2B0(char *, ...) __asm__("func_001118F8"); void func_00108B98(float *, float, float, float, float, float);
// MATCH func_0010A2B0
void FUN_0010a2b0(O_0010A2B0 *o, int a, int b, int c, int d, int mode) { if (D_00343028_0010A2B0[0] & 8) return; if (D_00343028_0010A2B0[0] & 0x10) return; if (D_004A118C_0010A2B0 & 0x40) func_001118F8_0010A2B0(D_0042CE50, D_004A12B0_0010A2B0); if (mode == 1) { if (a < 0) func_00108B98(&o->f1528, o->f1528, (float)b, (float)c, 0.5f, (float)d); else func_00108B98(&o->f1528, (float)a, (float)b, (float)c, 0.5f, (float)d); return; } if (a < 0) func_00108B98(&o->f1484, o->f1484, (float)b, (float)c, 0.5f, (float)d); else func_00108B98(&o->f1484, (float)a, (float)b, (float)c, 0.5f, (float)d); }

extern int D_002F7140[]; int func_00101190(void *, int, int, int); int func_00100F50(void *);
// MATCH func_001076F8
int FUN_001076f8(void) { if (D_002F7140[325] != 5) { func_00101190(D_002F7140, 5, 0, 0); return 1; } return func_00100F50(D_002F7140); }

extern int D_004A3850_001096C0 __asm__("D_004A3850"); extern int D_004A11CC; extern int D_00343028_001096C0[] __asm__("D_00343028");
void func_002E6750(int);
// MATCH func_001096C0
int FUN_001096c0(int a) { if ((D_00343028_001096C0[0] & 8) != 0 || D_004A3850_001096C0 == 2) { __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return 0; } if (a == 3) func_002E6750(D_004A11CC); __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return 1; }

extern int D_004B9E00_10A848[] __asm__("D_004B9E00"); extern char D_0042CF10_10A848[] __asm__("D_0042CF10");
void func_001118F8_10A848(void *, ...) __asm__("func_001118F8");
// MATCH func_0010A848
void FUN_0010a848(void) { int *p = D_004B9E00_10A848; int k, j; int mg = 0xbc614e; for (k = 0; k < 12; k++) { j = 0xbff; do { if (*p != mg) { func_001118F8_10A848(D_0042CF10_10A848, p, *p); __asm__ volatile(".word 0x0000000d"); } j = j - 1; p = p + 1; } while (-1 < j); } }

char *func_002AF418(void);
int func_002DD4B0(char *,char *);
extern char D_004A1148[];
extern char D_0042C470[];
extern char D_0042C480[];
extern char D_0042C490[];
extern char D_0042C4A0[];
extern char D_0042C4B0[];
extern char D_0042C4C0[];
extern char D_0042C4D0[];
extern char D_0042C4E0[];
extern char D_0042C4F0[];
extern char D_0042C500[];
extern char D_0042C510[];
extern char D_0042C520[];
extern char D_0042C530[];
extern char D_0042C540[];
extern char D_0042C550[];
extern char D_0042C560[];
extern char D_0042C570[];
extern char D_0042C580[];
extern char D_0042C590[];
extern char D_0042C5A0[];
extern char D_0042C5B0[];
extern char D_0042C5C0[];
extern char D_0042C5D0[];
extern char D_0042C5E0[];
extern char D_0042C5F0[];
extern char D_0042C600[];
extern char D_0042C610[];
extern char D_0042C620[];
extern char D_0042C630[];
extern char D_0042C640[];
extern char D_0042C650[];
extern char D_0042C660[];
extern char D_0042C670[];
extern char D_0042C680[];
extern char D_0042C690[];
extern char D_0042C6A0[];
extern char D_0042C6B0[];
extern char D_0042C6C0[];
extern char D_0042C6D0[];
extern char D_0042C6E0[];
extern char D_0042C6F0[];
extern char D_0042C700[];
extern char D_0042C710[];
extern char D_0042C720[];

// MATCH func_00108010
int FUN_00108010(void)
{
    char *name = func_002AF418();

    if (func_002DD4B0(name, D_004A1148) == 0) return 1;
    if (func_002DD4B0(name, D_0042C470) == 0) return 1;
    if (func_002DD4B0(name, D_0042C480) == 0) return 1;
    if (func_002DD4B0(name, D_0042C490) == 0) return 2;
    if (func_002DD4B0(name, D_0042C4A0) == 0) return 2;
    if (func_002DD4B0(name, D_0042C4B0) == 0) return 3;
    if (func_002DD4B0(name, D_0042C4C0) == 0) return 4;
    if (func_002DD4B0(name, D_0042C4D0) == 0) return 4;
    if (func_002DD4B0(name, D_0042C4E0) == 0) return 4;
    if (func_002DD4B0(name, D_0042C4F0) == 0) return 5;
    if (func_002DD4B0(name, D_0042C500) == 0) return 5;
    if (func_002DD4B0(name, D_0042C510) == 0) return 5;
    if (func_002DD4B0(name, D_0042C520) == 0) return 6;
    if (func_002DD4B0(name, D_0042C530) == 0) return 7;
    if (func_002DD4B0(name, D_0042C540) == 0) return 8;
    if (func_002DD4B0(name, D_0042C550) == 0) return 9;
    if (func_002DD4B0(name, D_0042C560) == 0) return 10;
    if (func_002DD4B0(name, D_0042C570) == 0) return 12;
    if (func_002DD4B0(name, D_0042C580) == 0) return 13;
    if (func_002DD4B0(name, D_0042C590) == 0) return 14;
    if (func_002DD4B0(name, D_0042C5A0) == 0) return 15;
    if (func_002DD4B0(name, D_0042C5B0) == 0) return 16;
    if (func_002DD4B0(name, D_0042C5C0) == 0) return 17;
    if (func_002DD4B0(name, D_0042C5D0) == 0) return 18;
    if (func_002DD4B0(name, D_0042C5E0) == 0) return 19;
    if (func_002DD4B0(name, D_0042C5F0) == 0) return 20;
    if (func_002DD4B0(name, D_0042C600) == 0) return 21;
    if (func_002DD4B0(name, D_0042C610) == 0) return 3;
    if (func_002DD4B0(name, D_0042C620) == 0) return 22;
    if (func_002DD4B0(name, D_0042C630) == 0) return 23;
    if (func_002DD4B0(name, D_0042C640) == 0) return 5;
    if (func_002DD4B0(name, D_0042C650) == 0) return 16;
    if (func_002DD4B0(name, D_0042C660) == 0) return 16;
    if (func_002DD4B0(name, D_0042C670) == 0) return 22;
    if (func_002DD4B0(name, D_0042C680) == 0) return 22;
    if (func_002DD4B0(name, D_0042C690) == 0) return 22;
    if (func_002DD4B0(name, D_0042C6A0) == 0) return 22;
    if (func_002DD4B0(name, D_0042C6B0) == 0) return 7;
    if (func_002DD4B0(name, D_0042C6C0) == 0) return 14;
    if (func_002DD4B0(name, D_0042C6D0) == 0) return 20;
    if (func_002DD4B0(name, D_0042C6E0) == 0) return 18;
    if (func_002DD4B0(name, D_0042C6F0) == 0) return 1;
    if (func_002DD4B0(name, D_0042C700) == 0) return 15;
    if (func_002DD4B0(name, D_0042C710) == 0) return 15;
    if (func_002DD4B0(name, D_0042C720) == 0) return 17;
    return 11;
}
