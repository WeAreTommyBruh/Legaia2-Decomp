/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

void FUN_00108b80(void *);
void FUN_00131588(void *);
extern char D_00342D00_15AA80[] __asm__("D_00342D00");
void FUN_00154db8(void *, void *);
void func_00245F98_15AA80(int, int) __asm__("func_00245F98");
// MATCH func_0015AA80
void FUN_0015aa80(char *p, int flag) { char *a; char *e; if (*(int *)(p + 0x120) != 0) func_00245F98_15AA80(*(int *)(p + 0x120), 3); a = *(char **)(p + 0x138); *(int *)(p + 0x120) = 0; if (a != 0) { e = a + *(int *)(a - 0x10) * 0x150; if (a != e) for (;;) { e -= 0x150; FUN_0015aa80(e, 0); if (*(char **)(p + 0x138) == e) break; } FUN_00131588(*(char **)(p + 0x138) - 0x10); } *(int *)(p + 0x138) = 0; if (*(int *)(p + 0x144) != 0) { FUN_00154db8(D_00342D00_15AA80, *(void **)(p + 0x144)); FUN_00108b80(*(void **)(p + 0x144)); *(int *)(p + 0x144) = 0; } if (flag & 1) FUN_00108b80(p); }

void FUN_00108b80(void *);
void FUN_00131588(void *);
void FUN_0015ab58(void *, int);
void func_00155A08_15ABB8(int, int) __asm__("func_00155A08");
// MATCH func_0015ABB8
void FUN_0015abb8(char *p, int flag) { char *a; char *e; a = *(char **)(p + 4); if (a != 0) { e = a + *(int *)(a - 0x10) * 0x150; if (a != e) for (;;) { e -= 0x150; FUN_0015aa80(e, 0); if (*(char **)(p + 4) == e) break; } FUN_00131588(*(char **)(p + 4) - 0x10); } *(int *)(p + 4) = 0; if (*(int *)(p + 0xc) != 0) FUN_00131588(*(void **)(p + 0xc)); a = *(char **)(p + 0x1c); *(int *)(p + 0xc) = 0; if (a != 0) { e = a + *(int *)(a - 0x10) * 0x30; if (a != e) for (;;) { e -= 0x30; FUN_0015ab58(e, 0); if (*(char **)(p + 0x1c) == e) break; } FUN_00131588(*(char **)(p + 0x1c) - 0x10); } *(int *)(p + 0x1c) = 0; if (*(int *)(p + 0x28) != 0) func_00155A08_15ABB8(*(int *)(p + 0x28), 3); *(int *)(p + 0x28) = 0; FUN_00108b80(*(void **)(p + 0x2c)); *(int *)(p + 0x2c) = 0; if (flag & 1) FUN_00108b80(p); }



float func_0018EAF8_15C170() __asm__("func_0018EAF8"); float func_00179648_15C170() __asm__("func_00179648"); float func_00178BB8_15C170() __asm__("func_00178BB8"); void func_0018F080_15C170(void *, void *, void *) __asm__("func_0018F080");
// MATCH func_0015C170
int FUN_0015c170(void *A, float e, void *B, void *C) { char s[16]; float x, y; if (func_0018EAF8_15C170(A, B) <= e) return 2; if (func_0018EAF8_15C170(A, C) <= e) return 2; x = func_00179648_15C170(A, B, C); if (e < __builtin_fabsf(x)) return 0; func_0018F080_15C170(s, C, B); y = func_00178BB8_15C170(A, s, B); x = func_00178BB8_15C170(A, s, C); if (y * x <= 0.0f) return 2; return 0; }


void FUN_00108b80_15AD10(int) __asm__("FUN_00108b80");
void FUN_00131588(void *);
typedef struct { char pad[0x30]; } Obj30_0015AD10;
// MATCH func_0015AD10
void FUN_0015ad10(int *p) { char *a; char *e; FUN_00108b80_15AD10(p[9]); a = (char *)p[0]; p[9] = 0; if (a != 0) { e = a + *(int *)(a - 0x10) * 0x30; if (a != e) for (;;) { e -= 0x30; FUN_0015abb8(e, 0); if ((char *)p[0] == e) break; } FUN_00131588((char *)p[0] - 0x10); } p[0] = 0; }
