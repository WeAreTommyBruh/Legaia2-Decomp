/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[16]; int a16; int a20; char pad1[9]; char b33; } S_00202878;
extern int D_004A4490, D_004A44A0; extern char D_004541A0[];
void func_00133528(int, void *, int); void func_00108B80_00202878(void *) __asm__("func_00108B80");
// MATCH func_00202878
void eftpack_00202878(S_00202878 *s, int fl) { if (s->a16 != 0) { if (s->b33 == 0) { if (D_004A4490 != 0) func_00133528(D_004A4490, D_004541A0, 40); D_004A44A0 = 2; D_004A4490 = s->a16; } } if (s->a20 != 0) func_00133528(s->a20, D_004541A0, 45); s->a16 = 0; s->a20 = 0; if (fl & 1) func_00108B80_00202878(s); }

extern int D_004A3864_00202CA8 __asm__("D_004A3864"); extern char D_00454278[]; void func_00202928(char *); void func_001118F8_00202CA8(char *, ...) __asm__("func_001118F8"); void func_00202F88(char *);
// MATCH func_00202CA8
int eftpack_00202ca8(char *o, int a, int b, int c) { if (o[32] <= 0) return -1; func_00202928(o); if (D_004A3864_00202CA8 & 0x400) func_001118F8_00202CA8(D_00454278, a); *(int *)(o + 16) = a; *(int *)(o + 12) = b; o[33] = c & 4; o[32] = 1; func_00202F88(o); return 1; }
