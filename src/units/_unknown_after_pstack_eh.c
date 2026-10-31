/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

void func_0022F5A0(float, float);
typedef struct { char p[128]; float x; char p2[4]; float y; } O_0024D490;
// MATCH func_0024D490
void FUN_0024d490(O_0024D490 *a, O_0024D490 *b) { func_0022F5A0(b->x - a->x, b->y - a->y); }

extern int D_004A12A4; void func_002562F8(void); void func_002594B0(void);
// MATCH func_00256260
void FUN_00256260(void) { if (D_004A12A4 == 11) func_002562F8(); else func_002594B0(); }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00250EF0;
extern char D_003FEBA8[]; int func_00250E90(int);
// MATCH func_00250EF0
void FUN_00250ef0(int i) { func_00250E90(((E9_00250EF0 *)(D_003FEBA8 + i * 472))->a); }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00250F20;
extern char D_003FEBA8_00250F20[] __asm__("D_003FEBA8"); int func_00250E90(int);
// MATCH func_00250F20
void FUN_00250f20(int i) { func_00250E90(((E9_00250F20 *)(D_003FEBA8_00250F20 + i * 472))->b); }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00250F50;
extern char D_003FEBA8_00250F50[] __asm__("D_003FEBA8"); int func_00250E90(int);
// MATCH func_00250F50
void FUN_00250f50(int i) { func_00250E90(((E9_00250F50 *)(D_003FEBA8_00250F50 + i * 472))->c); }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00250F80;
extern char D_003FEBA8_00250F80[] __asm__("D_003FEBA8"); int func_00250E90(int);
// MATCH func_00250F80
void FUN_00250f80(int i) { func_00250E90(((E9_00250F80 *)(D_003FEBA8_00250F80 + i * 472))->d); }
