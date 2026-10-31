/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[32]; float f32, f36, f40; } S__002AD028_002AD028;
typedef struct { S__002AD028_002AD028 *w0; } O__002AD028_002AD028;
int func_002D9440(float);
void func_001E48E0_002AD028() __asm__("func_001E48E0");
// MATCH func_002AD028
void FUN_002ad028(O__002AD028_002AD028 *o, int a, float d)
{
    int x = func_002D9440(o->w0->f32);
    int y = func_002D9440(o->w0->f36 + d);
    int z = func_002D9440(o->w0->f40);
    func_001E48E0_002AD028(2, a, x, y, z);
    func_001E48E0_002AD028(1, a);
}
