/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[10284]; int a; } S_22cff8_0022CFF8;
extern char D_0045BFC0[];
void func_001621F8(int, void *, int); void func_00108B80_0022CFF8(void *) __asm__("func_00108B80");
// MATCH func_0022CFF8
void th_tex_0022cff8(S_22cff8_0022CFF8 *s, int fl) { if (s->a != 0) func_001621F8(s->a, D_0045BFC0, 335); if (fl & 1) func_00108B80_0022CFF8(s); }

extern char D_00342CD0_0022CF58[] __asm__("D_00342CD0");
void func_002478D0(int); void func_00243A68(int, char *); void func_0022C650(void *); void func_0022CB58(void *);
// MATCH func_0022CF58
void th_tex_0022cf58(char *o) { int s; if (*(int *)(o + 12372) == 0) return; func_002478D0(16); func_002478D0(256); func_002478D0(64); func_002478D0(8); func_00243A68(1, D_00342CD0_0022CF58); s = *(int *)(o + 12356); switch (s) { case 0: case 1: func_0022C650(o); break; case 2: func_0022CB58(o); break; } }

typedef struct { char c[16]; } B16_0022C0E0;
void func_0022C158_22C0E0(char *, int, int, int, int, float) __asm__("func_0022C158");
// MATCH func_0022C0E0
void th_tex_0022c0e0(char *o, B16_0022C0E0 *s, int a2) { *(B16_0022C0E0 *)(o + *(int *)(o + 12336) * 80) = *s; func_0022C158_22C0E0(o, 0, 0, 0, a2, 0.0f); }
