/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_0022D750
int FUN_0022d750(int *b, int i) { unsigned char *e = (unsigned char *)b + b[i + 1]; int v = *(unsigned short *)(e + 2); if (((e[1] ^ 1) & 1) != 0) return v; return (v >> 1) + 1; }

static inline int clamp_nonnegative_0022D6E8(int value)
{
    return value > -1 ? value : 0;
}

// MATCH func_0022D6E8
unsigned FUN_0022d6e8(int o, int i, int x, int k)
{
    int v, r, m;
    unsigned char *p;
    unsigned short h;

    p = (unsigned char *)o + *(int *)(i * 4 + o + 4);
    v = clamp_nonnegative_0022D6E8(x);
    __asm__("" : "+r"(v) : : "memory");
    h = *(unsigned short *)(p + 2);
    m = h - 1;
    if (m < v)
        v = m;
    if ((p[1] ^ 1) & 1)
        return v;

    r = h >> 1;
    v = v / 2 + k;
    if (v < r)
        r = v;
    return r;
}
