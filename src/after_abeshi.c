/* Functions after abeshi.cpp whose source file is not known (group
   _unknown_after_abeshi in decomp/functions.csv). Matched by hand. */
#include "common.h"

extern struct {
    char unk0[0x8c];
    int count;
} D_003FEBA8;
extern void *D_0040D228[];
extern void *D_0040D8B8[];

/* counts up to INT_MAX and stays there */
// MATCH func_00264E40
void FUN_00264e40(void)
{
    if (D_003FEBA8.count != 0x7fffffff)
        D_003FEBA8.count++;
}

/* entry `i` (from 1) of the table at 0x40d228 */
// MATCH func_00269548
void *FUN_00269548(u32 i)
{
    return D_0040D228[i - 1];
}

/* entry `i` (from 1) of the table at 0x40d8b8 */
// MATCH func_00269568
void *FUN_00269568(u32 i)
{
    return D_0040D8B8[i - 1];
}
