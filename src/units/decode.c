/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_00440A48[]; void *func_00162130_001909F8(int, char *, int) __asm__("func_00162130"); void func_001908F0(void *, int *, int);
// MATCH func_001909F8
void *LzssDecodeAlloc(int *p) { int n = p[0]; void *buf = func_00162130_001909F8((n + 2047) & -2048, D_00440A48, 191); func_001908F0(buf, p, n); return buf; }

extern char D_00440A48_00190698[] __asm__("D_00440A48"); void *func_00162130_00190698(int, char *, int) __asm__("func_00162130"); void func_00190668(void *, void *, void *, int);
// MATCH func_00190698
void *decode_00190698(void *a, int *b) { int n = b[0]; void *p = func_00162130_00190698((n + 2047) & -2048, D_00440A48_00190698, 48); func_00190668(a, p, b, n); return p; }
