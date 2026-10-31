/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001D8368;
typedef struct { char p[224]; E_001D8368 e; } O_001D8368;
// MATCH func_001D8368
void nayuki_001d8368(O_001D8368 *o, float x) {  if (-1.0f < x) { float z = 0.0f; E_001D8368 *p = &o->e; p->d = z; __asm__("" : "+f"(z)); p->b = x; p->c = x; p->f = z; p->e = z; p->g = z; o->e.a = x; p->h = 1;  }  }
