/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fexceptions
#include "common.h"

typedef struct { char pad[176]; int a176; char pad1[36]; unsigned a216; int a220; int a224; int a228; } P_2c2b50_002C2B50;
typedef struct { char pad[64]; P_2c2b50_002C2B50 *a64; } S_2c2b50_002C2B50;
void func_002C2F30(void *);
// MATCH func_002C2B50
void FUN_002c2b50(S_2c2b50_002C2B50 *s, unsigned b, int c) { P_2c2b50_002C2B50 *p = s->a64; b = (b & 0x0fffffff) | 0x20000000; p->a176 = 1; p->a216 = b; p->a228 = c; p->a220 = 0; p->a224 = 0; func_002C2F30(s); }

typedef struct { char pad[176]; int a176; char pad1[36]; unsigned a216; int a220; int a224; int a228; } P_2c2b98_002C2B98;
typedef struct { char pad[64]; P_2c2b98_002C2B98 *a64; } S_2c2b98_002C2B98;
void func_002C2F30(void *);
// MATCH func_002C2B98
void FUN_002c2b98(S_2c2b98_002C2B98 *s, unsigned b, int c) { P_2c2b98_002C2B98 *p = s->a64; b = (b & 0x0fffffff) | 0x20000000; p->a228 = c; p->a216 = b; p->a220 = 0; p->a176 = 0; p->a224 = 0; func_002C2F30(s); }

extern char D_0049F740[]; extern int D_0042AC40[];
void func_002EE0E8(void *, int, int); void func_002EE200(void); void func_002E54F0(int, int, int, int);
// MATCH func_002EE208
void FUN_002ee208(int a, int b, int c, int d) { func_002EE0E8(D_0049F740, c, d); func_002EE200(); func_002E54F0(a, b, c, D_0042AC40[0] + 4); }
