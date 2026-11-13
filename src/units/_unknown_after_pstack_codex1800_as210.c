/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

extern unsigned short D_004A598E_00254D70 __asm__("D_004A598E"); extern unsigned short D_00401028_00254D70[] __asm__("D_00401028"); extern unsigned short D_003FEBA8_00254D70[] __asm__("D_003FEBA8");
int func_00254938_00254D70(int) __asm__("func_00254938"); int func_00254990_00254D70(unsigned) __asm__("func_00254990"); void func_00255278_00254D70(int) __asm__("func_00255278");
// MATCH func_00254D70
int FUN_00254d70(unsigned id, int n) { unsigned x; unsigned short *q; if (id >= D_004A598E_00254D70) return -1; q = D_003FEBA8_00254D70; { unsigned n = D_00401028_00254D70[id]; register unsigned short *p __asm__("$3")=q; __asm__ volatile("" : "+r"(p)); q=p+n; } x = q[186]; if (x == 0) return -1; if (func_00254938_00254D70(x) == 0) return -1; if (n <= 0) return -1; func_00255278_00254D70(6); do { if (func_00254990_00254D70(x) != 0) { func_00255278_00254D70(5); return n; } n--; } while (n > 0); func_00255278_00254D70(5); return 0; }
