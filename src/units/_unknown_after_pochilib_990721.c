/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int *D_004A6F44; extern char D_0043C280[], D_0043C290[], D_0043C2B8[];
unsigned long long func_001118F8_00161908(char *, ...) __asm__("func_001118F8");
// MATCH func_00161908
void FUN_00161908(void) { int *p, *e, *c; char *b; func_001118F8_00161908(D_0043C280); b = (char *)D_004A6F44[0]; p = *(int **)(b + 128); e = (int *)(b + 128); c = p; if (p != e) { do { p = (int *)*c; func_001118F8_00161908(D_0043C290, c, c[1], p, c[2]); c = p; } while (p != e); } func_001118F8_00161908(D_0043C2B8); e = (int *)D_004A6F44[0]; p = (int *)*e; c = p; if (p != e) { do { p = (int *)*c; func_001118F8_00161908(D_0043C290, c, c[1], p, c[2]); c = p; } while (p != e); } }
