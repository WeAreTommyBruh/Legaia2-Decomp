/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_003D7058[]; void func_002454A8(void *, void *, void *);
// MATCH func_00245578
void FUN_00245578(void *a, void *b) { func_002454A8(D_003D7058, a, b); }

typedef struct { char pad[8]; int a8; char pad1[132]; int a144; char pad2[192]; int a340; char pad3[50]; char b394; char pad4[17]; int a412; } S_245e10_00245E10;
extern int D_004A7204;
void func_002461E0(void *);
// MATCH func_00245E10
S_245e10_00245E10 *FUN_00245e10(S_245e10_00245E10 *s) { int n = D_004A7204; s->a144 = 0; n++; s->a412 = 0; s->a8 = 0; s->a340 = 0; D_004A7204 = n; func_002461E0(s); s->b394 = 0; return s; }

extern char D_0045D448[]; extern int D_004A1478, D_004A1498; int func_001118F8_00245DB8(char *) __asm__("func_001118F8"); void func_00245578(int, int);
// MATCH func_00245DB8
void FUN_00245db8(int a, int b, int c) { func_001118F8_00245DB8(D_0045D448); D_004A1478 = c; D_004A1498 = 1; func_00245578(a, b); }

extern char D_003D7058_00245590[] __asm__("D_003D7058"), D_005F75B8[]; extern void (*D_004A1478_00245590)(int) __asm__("D_004A1478"); int func_00245518(char *, char *);
// MATCH func_00245590
int FUN_00245590(void) { int r = func_00245518(D_003D7058_00245590, D_005F75B8); if (r == 1) D_004A1478_00245590(4); if (r == 2) D_004A1478_00245590(2); return r; }
