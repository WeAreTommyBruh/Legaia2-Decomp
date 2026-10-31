/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

void func_00113108(char *);
extern char D_00315D88[];
// MATCH func_00111968
void FUN_00111968(void) { func_00113108(D_00315D88); }

typedef struct { char p[100]; int w100; } O_0010E820;
extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042E5F8[], D_0042E618[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8(char *, ...); void func_0010E368(O_0010E820 *); void func_002D4398(int, int); void func_002D4C50(int);
// MATCH func_0010E820
void FUN_0010e820(O_0010E820 *o, int k) { int i; if (!(D_00343028[0] & 8) && D_004A3850 != 2) { if (D_004A118C & 0x40) func_001118F8(D_0042E5F8, D_004A12B0); switch (k) { case 101: func_0010E368(o); break; case 102: func_002D4398(o->w100, 0); break; case 103: if (D_004A118C & 1) func_001118F8(D_0042E618); func_002D4C50(0); for (i = 0; i < 48; i++) { D_002F95F0[i] = -1; D_002F96B0[i] = -1; } break; } } }
