/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00329920[]; extern char D_00432C80[], D_00432C98[]; void func_001118F8_001336B8(char *, ...) __asm__("func_001118F8"); int func_0018B508_001336B8(int, int *) __asm__("func_0018B508"); void func_001621F8_001336B8(int, char *, int) __asm__("func_001621F8");
// MATCH func_001336B8
int lg2save_001336b8(int i) { int buf[4]; int *e = &D_00329920[i]; int r; func_001118F8_001336B8(D_00432C80, *e); r = func_0018B508_001336B8(*e, buf); if (r) func_001621F8_001336B8(r, D_00432C98, 62); return -1; }

extern int D_00329920[]; extern int D_003FEBA8[]; extern char D_00432C98[];
int func_001336B8(int); int *func_0018B508(int, int *); void func_001621F8(int *, char *, int);
// MATCH func_001337B8
int lg2save_001337b8(int a) { int buf[4]; int *src; unsigned i; if (func_001336B8(a) < 0) return; src = func_0018B508(D_00329920[a], buf); if (src == 0) return; for (i = 0; i < 2304; i++) D_003FEBA8[i] = src[i]; func_001621F8(src, D_00432C98, 105); }

