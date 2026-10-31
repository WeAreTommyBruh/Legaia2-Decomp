/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00204018;
typedef struct { char p[360]; R__00204018 *w360; } X__00204018;
typedef struct O__00204018 { X__00204018 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00204018;
void func_001AF938(X__00204018 *, int, int, int); void func_001AF908(X__00204018 *, int, int); int func_0012D3D8(int);
// MATCH func_00204018
void FUN_00204018(O__00204018 *o, int a, int b, int c)
{
    int i;
    for (i = 0; i < o->w528; i++) {
        if (o->sh[i] == a) {
            if (o->w0 == 0) {
                o->t[i] = 104;
                o->b[i] = b;
                o->q[i] = c;
            } else {
                ((char *)o->w0->w360)[i * 256 + 253] = 104;
                func_001AF938(o->w0, c, i, 0);
                func_001AF908(o->w0, i, func_0012D3D8(b));
            }
            return;
        }
    }
}

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__002043f0_002043F0;
typedef struct { char p[360]; R__002043f0_002043F0 *w360; } X__002043f0_002043F0;
typedef struct O__002043f0_002043F0 { X__002043f0_002043F0 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__002043f0_002043F0;
void func_001AF938_002043F0(X__002043f0_002043F0 *, void *, int, int) __asm__("func_001AF938"); void func_001AF908_002043F0(X__002043f0_002043F0 *, int, int) __asm__("func_001AF908"); int func_0012D3D8(int); void func_001302A8(void *, int, int);
// MATCH func_002043F0
void FUN_002043f0(O__002043f0_002043F0 *o, int a, int b, int c)
{
    int buf[64];
    int i;
    for (i = 0; i < o->w528; i++) {
        if (o->sh[i] == a) {
            if (o->w0 == 0) {
                o->t[i] = 104;
                o->b[i] = b;
                o->q[i] = c;
            } else {
                ((char *)o->w0->w360)[i * 256 + 253] = 104;
                o->b[i] = b;
                func_001302A8(buf, c, 256);
                func_001AF938_002043F0(o->w0, buf, i, 0);
                func_001AF908_002043F0(o->w0, i, func_0012D3D8(b));
            }
            return;
        }
    }
}
