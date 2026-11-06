/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

extern int D_004A1334_1FC050 __asm__("D_004A1334");
extern int D_004A1338_1FC050 __asm__("D_004A1338");
extern char D_0041EFB0_1FC050[] __asm__("D_0041EFB0");
void func_001540C0_1FC050(float, void *) __asm__("func_001540C0");
void func_00154170_1FC050(float, void *) __asm__("func_00154170");
inline float inline_fn_001FC050(float arg0) { return -arg0; }
// MATCH func_001FC050
void FUN_001fc050(void) { float x = ((float) (D_004A1334_1FC050 / 8)) * 16.0f; float y = ((float) (D_004A1338_1FC050 / 8)) * 16.0f; func_001540C0_1FC050(x + x, D_0041EFB0_1FC050); y = inline_fn_001FC050(y); func_00154170_1FC050(y + y, D_0041EFB0_1FC050); }
