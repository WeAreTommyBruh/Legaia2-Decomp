/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { int a0, a4, a8, a12, a16, a20; } S_29b608_0029B608;
extern S_29b608_0029B608 D_00620058; extern int D_00425518[];
// MATCH func_0029B608
void FUN_0029b608(int x, int b) { S_29b608_0029B608 *s = &D_00620058; if (s->a4 != 0 || (D_00425518[0] & 0x10)) { s->a0 = 0; s->a4 = b; s->a12 = 0; s->a8 = 0; s->a20 = 0; s->a16 = 0; } }
