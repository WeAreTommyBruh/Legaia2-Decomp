/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "common.h"

typedef struct { int a0, a4, a8, a12, a16, a20; } N_2da070_002DA070;
extern N_2da070_002DA070 *D_00631AF8[];
// MATCH func_002DA070
void FUN_002da070(int a, N_2da070_002DA070 *s) { N_2da070_002DA070 *h = D_00631AF8[0]; s->a12 = a; s->a20 = (int)h; D_00631AF8[0] = s; s->a8 = a; s->a4 = 0; s->a0 = 0; s->a16 = 0; }

extern int D_004A6F54; void func_0018A658(char *, char *); char *func_002DD1DC(char *, int); int *func_0018A708(char *);
// MATCH func_0018B250
int FUN_0018b250(char *name) { char buf[256]; char *p; int *e; int w; func_0018A658(name, buf); p = func_002DD1DC(buf, 58); if (p == 0) p = buf; else p++; e = func_0018A708(p); if (e == 0) return -1; w = e[3]; return D_004A6F54 + w; }

extern char D_00400498[]; void func_002523A0(void);
// MATCH func_0025AC10
void FUN_0025ac10(void) { int p = (int)D_00400498; do { *(short *)((char *)p + 248) = 0; *(short *)((char *)p + 250) = 0; *(short *)((char *)p + 252) = 0; *(short *)((char *)p + 254) = 0; *(short *)((char *)p + 256) = 0; *(short *)((char *)p + 258) = 0; *(short *)((char *)p + 260) = 0; *(short *)((char *)p + 262) = 0; *(short *)((char *)p + 264) = 0; *(short *)((char *)p + 266) = 0; *(short *)((char *)p + 268) = 0; *(short *)((char *)p + 270) = 0; *(short *)((char *)p + 272) = 0; *(short *)((char *)p + 274) = 0; *(short *)((char *)p + 276) = 0; *(short *)((char *)p + 278) = 0; *(short *)((char *)p + 280) = 0; *(short *)((char *)p + 282) = 0; *(short *)((char *)p + 284) = 0; *(short *)((char *)p + 286) = 0; *(short *)((char *)p + 288) = 0; *(short *)((char *)p + 290) = 0; p += 472; } while (p < (int)D_00400498 + 2360); func_002523A0(); }

extern char D_00400498_0025AC90[] __asm__("D_00400498"); int func_00127210(void); void func_0025ADB8(void); void func_002523A0(void);
// MATCH func_0025AC90
void FUN_0025ac90(void) { int p; if (func_00127210() == 0) { p = (int)D_00400498_0025AC90; do { short *s = (short *)p; if (s[135]) s[135]--; if (s[136]) s[136]--; if (s[137]) s[137]--; if (s[138]) s[138]--; if (s[139]) s[139]--; if (s[140]) s[140]--; if (s[141]) s[141]--; if (s[142]) s[142]--; if (s[143]) s[143]--; if (s[144]) s[144]--; if (s[145]) s[145]--; p += 472; } while (p < (int)D_00400498_0025AC90 + 2360); } func_0025ADB8(); func_002523A0(); }

extern int D_004A1A3C;
// MATCH func_00127430
int battle_00127430(void) { int *new_var; int r = 0; if (D_004A1A3C != 0) { r = 1; } if (D_004A1A3C) { new_var = &r; return *new_var; } else { return r; } }
