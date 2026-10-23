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
