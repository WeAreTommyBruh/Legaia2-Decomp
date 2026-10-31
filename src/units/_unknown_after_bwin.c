/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A140C; extern char D_00239238[]; void func_002392F0(int, void *);
// MATCH func_002391F0
int FUN_002391f0(int a) { if (a == 0) return 0; if (a & 2) return 0; if ((D_004A140C & 8) == 0) return 0; func_002392F0(1, D_00239238); return 0; }

extern int D_004A1280, D_004A1288, D_004A1294; extern int D_0032965C[];
// MATCH func_0023A238
void FUN_0023a238(void) { D_004A1280 = 16; D_004A1288 = 8; D_004A1294 = D_0032965C[0]; }

typedef char *va_list;
void func_002396B8(int, va_list);
// MATCH func_00239568
void FUN_00239568(int a, ...) { va_list ap; ap = (va_list)__builtin_next_arg(a) - 56; func_002396B8(a, ap); }

extern int D_004A13E8;
void func_002396B8(int, va_list);
// MATCH func_002393E0
void FUN_002393e0(int a, int b, ...) { va_list ap; D_004A13E8 = a; ap = (va_list)__builtin_next_arg(b) - 48; func_002396B8(b, ap); D_004A13E8 = 0; }

extern int D_004A1280_002394D0 __asm__("D_004A1280"), D_004A1288, D_004A1298, D_004A7138;
void func_00249818(int *, int); void func_002396B8(int, va_list);
// MATCH func_002394D0
void FUN_002394d0(int a, int b, ...) { int pt[2]; int o1 = D_004A1280_002394D0; int o2 = D_004A1288; va_list ap; func_00249818(pt, a); D_004A1280_002394D0 = ((pt[0] >> 4) - 1728) >> 1; D_004A1288 = (pt[1] >> 4) - 1936; ap = (va_list)__builtin_next_arg(b) - 48; func_002396B8(b, ap); D_004A1280_002394D0 = o1; D_004A1288 = o2; }

extern char D_0045C658[]; extern int D_004A1498_002392F0 __asm__("D_004A1498"), D_004A1478_002392F0 __asm__("D_004A1478"), D_004A1474; int func_001118F8_002392F0(char *) __asm__("func_001118F8");
// MATCH func_002392F0
void FUN_002392f0(int a, int b) { char buf[128]; func_001118F8_002392F0(D_0045C658); D_004A1498_002392F0 = a; D_004A1478_002392F0 = b; D_004A1474 = 1; }

extern int D_004A129C_0023A258 __asm__("D_004A129C"); extern char D_0045C740[]; void func_00239568_0023A258(char *, ...) __asm__("func_00239568");
// MATCH func_0023A258
void FUN_0023a258(float *o) { int s = D_004A129C_0023A258; D_004A129C_0023A258 = 1; func_00239568_0023A258(D_0045C740, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); D_004A129C_0023A258 = s; }

extern int D_004A7164, D_004A7168, D_004A1418; extern long long D_005F7040[];
// MATCH func_0023C6C0
void FUN_0023c6c0(void) { int i; D_004A7168 = D_004A7164 / 32; D_004A7164 = D_004A1418 << 5; for (i = 63; i >= 0; i--) D_005F7040[i] = 0; }

void func_0023C780(int, int, int, int, int);
// MATCH func_0023B568
void FUN_0023b568(int a, int b, int k, int x) { switch (k) { case 0: func_0023C780(a, b, (x << 3) + 128, 248, 32640); break; case 1: func_0023C780(a, b, (x << 3) + 104, 248, 32640); break; case 2: func_0023C780(a, b, (x << 3) + 144, 248, 32640); break; } }

extern int D_004A7120, D_004A1478_00239338 __asm__("D_004A1478"), D_004A53A0, D_004A53A4, D_004A1470; extern char D_0045C670[], D_003D4060[]; void func_001118F8_00239338(char *, ...) __asm__("func_001118F8"); int func_002DD5E0_00239338(char *) __asm__("func_002DD5E0"); char *func_002DD4CC_00239338(char *, char *) __asm__("func_002DD4CC");
// MATCH func_00239338
void FUN_00239338(int a, char *s, int c) { func_001118F8_00239338(D_0045C670); D_004A7120 = a; D_004A53A4 = func_002DD5E0_00239338(s); D_004A1478_00239338 = c; D_004A53A0 = (int)s; func_002DD4CC_00239338(D_003D4060, s); D_004A1470 = 1; }

extern int D_004A1280_00239420 __asm__("D_004A1280"); extern int D_004A1288_00239420 __asm__("D_004A1288"); void func_00249818(int *, int); void func_002396B8(int, va_list);
// MATCH func_00239420
void FUN_00239420(int a, int ox, int oy, int fmt, ...) { int pt[2]; int o1 = D_004A1280_00239420; int o2 = D_004A1288_00239420; va_list ap; func_00249818(pt, a); { int y = oy - 1936; D_004A1280_00239420 = (((pt[0] >> 4) - 1728) >> 1) + ox; D_004A1288_00239420 = (pt[1] >> 4) + y; } ap = (va_list)__builtin_next_arg(fmt) - 32; func_002396B8(fmt, ap); D_004A1280_00239420 = o1; D_004A1288_00239420 = o2; }

extern int D_004A14A0, D_004A1444_0023B5D0 __asm__("D_004A1444"), D_004A7144, D_004A1450, D_004A1454, D_004A13FC, D_004A1400;
// MATCH func_0023B5D0
int FUN_0023b5d0(int a, int b, int c, int d, int e)
{
    if (D_004A14A0 != 0) return 0;
    if (e != 0) {
        if (D_004A1444_0023B5D0 != 0) return 0;
        if (D_004A7144 == 0) return 0;
        if (D_004A1450 != 0) return 0;
    }
    if (D_004A1454 != 0) return 0;
    if (D_004A13FC < a) return 0;
    if (D_004A1400 < b) return 0;
    if (a + c < D_004A13FC) return 0;
    return !(b + d < D_004A1400);
}

extern int D_004A148C;
int func_0023B5D0(int, int, int, int, int); void func_0023B568(int, int, int, int);
// MATCH func_0023B4E0
int FUN_0023b4e0(int a, int b, int c)
{
    int ok;
    if (c < 0) return 0;
    ok = func_0023B5D0(a - 1, b - 1, 10 >> D_004A148C, 7 >> D_004A148C, 1) != 0;
    func_0023B568(a, b, c, ok);
    return ok;
}

extern int D_004A1298_0023C7F8 __asm__("D_004A1298"); extern int D_004A1274_0023C7F8 __asm__("D_004A1274"); extern int D_004A7134; extern int D_004A7130; extern char D_005F6A00[]; extern char D_00314C20_0023C7F8[] __asm__("D_00314C20");
void func_00190420_0023C7F8(char *) __asm__("func_00190420"); int func_00130CE0(int, int, int);
// MATCH func_0023C7F8
int FUN_0023c7f8(int a, int b, int c) { int n; if (D_004A1298_0023C7F8 != 0) return D_004A1274_0023C7F8; n = D_004A7134; if (n < 62) { D_005F6A00[n] = c; D_005F6A00[n + 1] = c >> 8; D_004A7134 = n + 2; } if (D_004A7130 != 0) { func_00190420_0023C7F8(D_00314C20_0023C7F8); D_004A7130 = 0; } return func_00130CE0(a, b, c); }

extern float D_003D4728[]; extern char D_004A5400[];
int func_00239568_0023AA20(void *, int) __asm__("func_00239568");
// MATCH func_0023AA20
void FUN_0023aa20(char *o, int n) { if (n < 8) { *(int *)(o + 0x20) = n; *(float *)(o + 0x14) = D_003D4728[n]; } else { func_00239568_0023AA20(D_004A5400, n); if (n == 8) *(unsigned short *)(o + 0x10) ^= 8; if (n == 9) *(unsigned short *)(o + 0x10) ^= 0x100; } }

extern int D_004A1A20_00238000 __asm__("D_004A1A20");
// MATCH func_00238000
void FUN_00238000(int a) { char *e; int v; e = (char *)(a * 5472 + D_004A1A20_00238000); v = *(int *)(*(int *)(e + 5188) + 8); if (v < *(int *)(e + 5388)) *(int *)(e + 5388) = v; }
