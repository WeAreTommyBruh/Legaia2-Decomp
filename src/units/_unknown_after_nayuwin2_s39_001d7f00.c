#include "../common.h"
typedef struct { char p0[80]; short a; short b; char p84[172]; } E_1d7f00;
extern E_1d7f00 D_00346780[];
extern int D_004A3864;
extern char D_0044B338[];
void func_002DCE40(char *, char *, ...); void func_001335E8(char *, int, int);
// MATCH func_001D7F00
void FUN_001d7f00(unsigned n)
{
    char buf[256];
    if (n < 292) {
        E_1d7f00 *e = &D_00346780[n];
        if (e->a > 0) {
            e->a--;
            if (D_004A3864 & 0x800) {
                func_002DCE40(buf, D_0044B338, n, e->a, e->b);
                func_001335E8(buf, n, 0);
            }
        }
    }
}
