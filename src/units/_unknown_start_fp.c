/* Functions of this report unit, matched by hand. */
// cflags: -fno-omit-frame-pointer -fexceptions -fno-schedule-insns2
#include "../common.h"

extern char D_002F7080[]; void func_002DA0C8(void *);
// MATCH func_00100210
void FUN_00100210(void) { func_002DA0C8(D_002F7080); }

extern char D_004A75C8[];
void func_002DA070(void *, void *);

// MATCH func_001001D8
void FUN_001001d8(void)
{
    func_002DA070(
        ({ void *table = D_002F7080;
           __asm__("" : : "r"(table));
           table; }),
        D_004A75C8);
}
