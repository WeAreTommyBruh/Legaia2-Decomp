/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_00241FA8
int *FUN_00241fa8(int *p, int a, long long b) { *p++ = (int)b; *p++ = (int)(b >> 32); *p++ = a; *p++ = 0; return p; }

extern int D_004A71A8; extern char D_0045CF30[]; void func_00246DB8(int); void func_001118F8(void *);
// MATCH func_002414D0
void FUN_002414d0(void) { if (D_004A71A8 != 0) func_00246DB8(D_004A71A8); D_004A71A8 = 0; func_001118F8(D_0045CF30); }

extern char D_005F7340[], D_005F7240[], D_0043B448[]; void func_00245E10(char *);
// MATCH func_00241C40
void FUN_00241c40(void) { int i; char *p; func_00245E10(D_005F7340); p = D_005F7240; for (i = 3; i != -1; i--) { *(int *)(p + 52) = (int)D_0043B448; p += 64; } }

void func_00247970(int); void func_00247A70(int, int, int); void func_00247E30(int); void func_002479F0(void);
// MATCH func_00242598
void FUN_00242598(int a, int b, int c) { unsigned char *p = (unsigned char *)&c; func_00247970(2); func_00247A70(p[0], p[1], p[2]); func_00247E30(a); func_00247E30(b); func_002479F0(); }

extern char D_0045CF20[]; void func_00239568_002413B0(int) __asm__("func_00239568"); void func_00247970_002413B0(unsigned) __asm__("func_00247970"); void func_002479F0(void); void func_00247EF8(unsigned, int); void func_00247A70_002413B0(unsigned, unsigned, unsigned) __asm__("func_00247A70");
// MATCH func_002413B0
void FUN_002413b0(void) { int a; int b; func_00239568_002413B0((int)D_0045CF20); a = 0; b = 0x6c00; do { func_00247970_002413B0(2); if (0x140 == a) { func_00247A70_002413B0(0x80, 0x80, 0x80); } else { func_00247A70_002413B0(0x80, 0x80, 0); } func_00247EF8(b, 0x7900); a = a + 0x40; func_00247EF8(b, 0x8700); b = b + 0x400; func_002479F0(); } while (a < 0x280); b = 0x7900; a = 0xc0; do { a = a + (-0x20); func_00247970_002413B0(2); func_00247A70_002413B0(0x80, 0x80, 0); func_00247EF8(0x6c00, b); func_00247EF8(0x9400, b); b = b + 0x200; func_002479F0(); } while ((-1) < a); func_00247970_002413B0(2); func_00247A70_002413B0(0x80, 0x80, 0x80); func_00247EF8(0x6c00, 0x8000); func_00247EF8(0x9400, 0x8000); func_002479F0(); }
