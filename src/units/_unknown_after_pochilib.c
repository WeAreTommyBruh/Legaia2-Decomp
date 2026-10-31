/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A14EC; extern char D_0043C570[]; void func_001118F8(void *); void func_00162238(int);
// MATCH func_001621F8
void MemFreeDbg(int a) { if (D_004A14EC != 0) func_001118F8(D_0043C570); func_00162238(a); }

extern char **D_004A6F44; extern char D_004A2C28[], D_004A2C30[]; int func_00161E58(char *, char *);
// MATCH func_001620A8
int FUN_001620a8(void) { int r = func_00161E58(*D_004A6F44 + 128, D_004A2C28); if (r) return r; return func_00161E58(*D_004A6F44, D_004A2C30); }

extern int D_004A13D0, D_004A14CC; extern char D_0043C550[]; void *func_00161388(int, int); void func_001118F8_00162190(char *, int) __asm__("func_001118F8"); void func_002D7228(int) __attribute__((noreturn));
// MATCH func_00162190
void *MemAlloc(int size) { void *r; D_004A13D0++; r = func_00161388(0, size); if (r == 0) { func_001118F8_00162190(D_0043C550, (unsigned)size >> 10); D_004A14CC += 0x30d41; func_002D7228(1); } return r; }

extern int D_004A13D0_00162238 __asm__("D_004A13D0"), D_004A14CC_00162238 __asm__("D_004A14CC"); extern char D_0043C588[]; void func_001118F8_00162238(char *) __asm__("func_001118F8"); void func_00162230(void); void func_00161690(void *);
// MATCH func_00162238
void MemFree(void *p) { if (p != 0) { D_004A13D0_00162238--; func_00161690(p); return; } func_001118F8_00162238(D_0043C588); func_00162230(); D_004A14CC_00162238 += 0x186a0; }

extern int *D_004A6F44_00162290 __asm__("D_004A6F44");
// MATCH func_00162290
unsigned FUN_00162290(void) { char *h = *(char **)D_004A6F44_00162290; int *c = *(int **)(h + 128); int *e = (int *)(h + 128); unsigned r = 0; if (c != e) do { unsigned v = c[2]; c = (int *)c[0]; if (r < v) r = v; } while (c != e); return r; }
