// cflags: -fno-schedule-insns2
#include "../common.h"
extern float D_004A0DE4;
typedef struct { char p[1904]; float s[3]; float d; int q[2]; float a, b, c; int z[3]; } O;
// MATCH func_002A8950
void FUN_002a8950(O *p, float a, float b, float c) { p->a = a; p->b = b; p->c = c; p->z[0] = 0; p->z[1] = 0; p->z[2] = 0; p->s[0] = 3.0f; p->s[1] = 3.0f; p->s[2] = 3.0f; p->d = D_004A0DE4; }
