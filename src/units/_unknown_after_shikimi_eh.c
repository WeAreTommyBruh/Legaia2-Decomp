/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

void func_002C1CF0(int, int, int, int, int);
// MATCH func_002C1FE8
void FUN_002c1fe8(int a, int b, int c) { func_002C1CF0(a, b, c, 0, -1); }

extern char D_0062B8D8[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC10
void FUN_002ccc10(int a) { func_002CCF20(a, 0, 0, 9, D_0062B8D8); }

extern char D_0062B8D8_002CCC40[] __asm__("D_0062B8D8"); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC40
void FUN_002ccc40(int a) { func_002CCF20(a, 0, 0, 4, D_0062B8D8_002CCC40); }

extern char D_0062B8D8_002CCBA8[] __asm__("D_0062B8D8"); extern int D_00427DB0[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCBA8
void FUN_002ccba8(int a, int b, int c) { D_00427DB0[0] = 0; func_002CCF20(a, b, c, 5, D_0062B8D8_002CCBA8); }

extern char D_0049F708[];
void func_002ED680(int, void *, int, int);
// MATCH func_002ED7A8
void FUN_002ed7a8(int a, int b) { func_002ED680(a, D_0049F708, b, 1); }

void func_002ED680_002ED788(int, int, int, int) __asm__("func_002ED680");
// MATCH func_002ED788
void FUN_002ed788(int a, int b, int c) { func_002ED680_002ED788(a, b, c, 1); }

extern int D_00427DB0_002CCE30[] __asm__("D_00427DB0"); extern int D_00426350[]; extern char D_0049E238[], D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE30[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE30
void sceCdStPause(void) { D_00427DB0_002CCE30[0] = 0; if (D_00426350[0] > 0) func_002E7940(D_0049E238); func_002CCF20(0, 0, 0, 7, D_0062B8D8_002CCE30); }

extern int D_00427DB0_002CCE80[] __asm__("D_00427DB0"); extern int D_00426350_002CCE80[] __asm__("D_00426350"); extern char D_0049E238_002CCE80[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE80[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE80
void sceCdStResume(void) { D_00427DB0_002CCE80[0] = 1; if (D_00426350_002CCE80[0] > 0) func_002E7940(D_0049E250); func_002CCF20(0, 0, 0, 8, D_0062B8D8_002CCE80); }

extern int D_00427DB0_002CCED8[] __asm__("D_00427DB0"); extern int D_00426350_002CCED8[] __asm__("D_00426350"); extern char D_0049E238_002CCED8[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCED8[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCED8
void sceCdStStat(void) { if (D_00426350_002CCED8[0] > 0) func_002E7940(D_0049E268); func_002CCF20(0, 0, 0, 6, D_0062B8D8_002CCED8); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7ED0
void FUN_002e7ed0(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 1, b, c, d, e, f); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7E90
void FUN_002e7e90(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 0, b, c, d, e, f); }

int func_002DBC48(void); void func_002D8148(void) __attribute__((noreturn));
// MATCH func_002D8228
void FUN_002d8228(void) { if (func_002DBC48() == 0) func_002D8148(); }

typedef struct { char p[4]; int w4; } Q_002BAF58;
typedef struct { char p[576]; Q_002BAF58 *w576; } R_002BAF58;
typedef struct { char p[216]; R_002BAF58 *w216; } O_002BAF58;
void func_002ADCC8(Q_002BAF58 *, O_002BAF58 *); void func_002AE0C8(Q_002BAF58 *, O_002BAF58 *);
// MATCH func_002BAF58
void FUN_002baf58(O_002BAF58 *o) { Q_002BAF58 *q = o->w216->w576; if (q != 0) { switch (q->w4) { case 0: func_002ADCC8(q, o); break; case 1: func_002AE0C8(q, o); break; } } }

void func_002C3200(void *, int, int); void func_002C30A0(void *, int, int);
// MATCH func_002C31B8
void FUN_002c31b8(char *o, int b, int c) { if (*(int *)(*(char **)(o + 64) + 372) != 3) func_002C3200(o, b, c); else func_002C30A0(o, b, c); }

int func_002C2F30(int);
// MATCH func_002C2BE0
void FUN_002c2be0(int p, unsigned q, int r, int s) { int e; e = *(int *)(p + 0x40); *(int *)(e + 0xe0) = s << 4; *(unsigned *)(e + 0xd8) = q & 0xfffffff | 0x20000000; *(int *)(e + 0xe4) = r * s; *(int *)(e + 0xdc) = r << 4; *(int *)(e + 0xb0) = 0; func_002C2F30(p); }

