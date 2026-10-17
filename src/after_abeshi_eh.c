/* Functions of _unknown_after_abeshi that were built with exceptions on
   (no tail calls; see tools/asm_build.py). Matched by hand. */
// cflags: -fexceptions
#include "common.h"

extern char D_0040E060[];
int FUN_002619d8(float, int, void *, void *);

// MATCH func_002619A8
void FUN_002619a8(int a)
{
    FUN_002619d8(1.0f, a, D_0040E060, D_0040E060);
}
