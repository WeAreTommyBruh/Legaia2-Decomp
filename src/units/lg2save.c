/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00329920[]; extern char D_00432C80[], D_00432C98[]; void func_001118F8_001336B8(char *, ...) __asm__("func_001118F8"); int func_0018B508_001336B8(int, int *) __asm__("func_0018B508"); void func_001621F8_001336B8(int, char *, int) __asm__("func_001621F8");
// MATCH func_001336B8
int lg2save_001336b8(int i) { int buf[4]; int *e = &D_00329920[i]; int r; func_001118F8_001336B8(D_00432C80, *e); r = func_0018B508_001336B8(*e, buf); if (r) func_001621F8_001336B8(r, D_00432C98, 62); return -1; }
