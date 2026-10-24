#include "../src/common.h"
typedef int u128 __attribute__((mode(TI)));
void func_00153690(void *, void *);
// WIP func_00154550
void FUN_00154550(char *s) { float a, b; func_00153690(s + 192, s + 64); a = *(float *)(s + 80); b = *(float *)(s + 84);
*(u128 *)(s + 48) = *(u128 *)(s + 80);
*(u128 *)(s + 16) = *(u128 *)(s + 96);
*(float *)(s + 32) = a;
*(float *)(s + 36) = -b;
*(float *)(s + 40) = *(float *)(s + 88);
}
