/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B598;
extern char D_00455618[], D_00454D80[]; int func_001621F8(int, char *, int); void func_00108B80(void *);
// MATCH func_0020B598
void pchevent_0020b598(O_0020B598 *o, int fl) { int i; o->vt = D_00455618; if (o->w12 != 0) { for (i = 0; i < o->w4; i++) { if (o->w12[i] != 0) func_001621F8(o->w12[i], D_00454D80, 117); } func_001621F8((int)o->w12, D_00454D80, 118); } if (fl & 1) func_00108B80(o); }
