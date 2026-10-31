/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[4]; int a4; int a8; char *a12; } S_002168B8;
extern char D_00455A48[], D_00455A38[];
void func_002163C0(int, int); void func_001621F8(int, void *, int); void func_00108B80_002168B8(void *) __asm__("func_00108B80");
// MATCH func_002168B8
void pchspplate_002168b8(S_002168B8 *s, int fl) { s->a12 = D_00455A48; if (s->a8 != 0) func_002163C0(s->a8, 3); if (s->a4 != 0) func_001621F8(s->a4, D_00455A38, 204); if (fl & 1) func_00108B80_002168B8(s); }

extern char D_00455A38_00216938[] __asm__("D_00455A38");
int func_00162130_00216938(int, char *, int) __asm__("func_00162130"); int func_00216398(int, int, int, int, int, int);
void func_00216420(int, int); void func_00216428(int, int, int, int, int, int);
// MATCH func_00216938
int pchspplate_00216938(int *o, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11) { int r; r = func_00216398(func_00162130_00216938(56, D_00455A38_00216938, 211), p2, p3, p4, p5, p6); if (r != 0) { func_00216420(r, o[2]); o[2] = r; func_00216428(r, p7, p8, p9, p10, p11); o[0] = o[0] + 1; } return r; }

