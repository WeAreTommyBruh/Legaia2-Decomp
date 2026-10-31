/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[16]; int w16, w20, w24; char q[116]; int w144; char r[192]; int w340; char s[50]; signed char b394; char t[17]; int w412; } O__00246CE0;
extern int D_004A1384, D_004A7204_00246CE0 __asm__("D_004A7204");
extern char D_0045D540[];
void *func_0024A1C8(int); void func_00246340(O__00246CE0 *); int func_001118F8_00246CE0(char *, ...) __asm__("func_001118F8");
// MATCH func_00246CE0
O__00246CE0 *work_00246ce0(int a, int b, int c, int d)
{
    O__00246CE0 *r = func_0024A1C8(a);
    if (r == 0) {
        D_004A1384 = D_004A1384 + 1;
        func_001118F8_00246CE0(D_0045D540, D_004A1384);
        return 0;
    }
    r->w144 = 0;
    r->w340 = 0;
    D_004A7204_00246CE0 = D_004A7204_00246CE0 + 1;
    r->w412 = 0;
    r->b394 = 0;
    func_00246340(r);
    r->w16 = b;
    r->w20 = c;
    r->w24 = d;
    return r;
}

int func_00246D88_00246C90(int, int) __asm__("func_00246D88");
// MATCH func_00246C90
int work_00246c90(float *v, int a, int b)
{
    int r = func_00246D88_00246C90(a, b);
    if (r != 0) return 0;
    *(float *)(r + 32) = v[0];
    *(float *)(r + 36) = v[1];
    *(float *)(r + 40) = v[2];
    return 0;
}
