/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00329920[]; extern char D_00432C80[], D_00432C98[]; void func_001118F8_001336B8(char *, ...) __asm__("func_001118F8"); int func_0018B508_001336B8(int, int *) __asm__("func_0018B508"); void func_001621F8_001336B8(int, char *, int) __asm__("func_001621F8");
// MATCH func_001336B8
int lg2save_001336b8(int i) { int buf[4]; int *e = &D_00329920[i]; int r; func_001118F8_001336B8(D_00432C80, *e); r = func_0018B508_001336B8(*e, buf); if (r) func_001621F8_001336B8(r, D_00432C98, 62); return -1; }

extern int D_00329920[]; extern int D_003FEBA8[]; extern char D_00432C98[];
int func_001336B8(int); int *func_0018B508(int, int *); void func_001621F8(int *, char *, int);
// MATCH func_001337B8
int lg2save_001337b8(int a) { int buf[4]; int *src; unsigned i; if (func_001336B8(a) < 0) return; src = func_0018B508(D_00329920[a], buf); if (src == 0) return; for (i = 0; i < 2304; i++) D_003FEBA8[i] = src[i]; func_001621F8(src, D_00432C98, 105); }


extern char *D_00329920_133720[] __asm__("D_00329920");
extern char *D_004A1B80_133720 __asm__("D_004A1B80");
extern char D_003FEBA8_133720[] __asm__("D_003FEBA8");
int func_002E9950_133720(void *, int) __asm__("func_002E9950");
int func_002EA200_133720(int, void *, int) __asm__("func_002EA200");
int func_002E9BD8_133720(int) __asm__("func_002E9BD8");
// MATCH func_00133720
int lg2save_00133720(int n) { int i, fd; char *buf = D_003FEBA8_133720; for (i = 0; i < 9; i++) D_004A1B80_133720[i + 5] = D_00329920_133720[n][i]; fd = func_002E9950_133720(D_004A1B80_133720, 0x602); func_002EA200_133720(fd, buf, 0x2400); func_002E9BD8_133720(fd); return 0; }
