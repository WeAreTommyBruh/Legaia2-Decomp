#include "../common.h"
typedef struct { char p0[0x4c]; signed char c4c, c4d, c4e; char p4f[0x31]; int st; char p84[0x84]; float f108; int p10c; int m110; char p114[0x8f0]; unsigned fl; } O_1d8030;
extern int D_004A13EC;
void func_0010FF28(int);
int func_001DC640(O_1d8030 *); int func_001DCEE8(O_1d8030 *); int func_001DEDF0(O_1d8030 *); int func_001DE088(O_1d8030 *); int func_001DE0F0(O_1d8030 *);
void func_001D8478(O_1d8030 *, int);
// MATCH func_001D8030
void FUN_001d8030(O_1d8030 *o)
{
    int r = 0;
    int save = 0;
    if (o->c4d != 0 && o->c4c == 0) goto end;
    if (o->st == 2 || o->st == 8) {
        save = D_004A13EC;
        func_0010FF28(0x400);
    }
    if (o->st == 5) {
        r = func_001DC640(o);
    } else if (o->st < 3 || o->st == 8) {
        if (o->fl & 2) r = func_001DE0F0(o);
        else if (o->fl & 0x800) r = func_001DE088(o);
        else r = func_001DEDF0(o);
    } else if (o->st < 6) {
        r = func_001DCEE8(o);
    }
    if (r == 0 && o->m110 == 2) func_001D8478(o, 3);
    if (o->st == 2 || o->st == 8) func_0010FF28(save);
end:
    if (o->m110 == 3 && o->f108 > 0.0f) {
        o->c4e = 0;
        o->c4d = 0;
    }
}
