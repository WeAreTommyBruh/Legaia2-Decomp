/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char c[8]; } V8_1694_001694D0;
extern long long D_004A12D8_1694D0 __asm__("D_004A12D8");
extern V8_1694_001694D0 D_004A2E60_1694D0[] __asm__("D_004A2E60");
void func_00168AC0_1694D0(void *) __asm__("func_00168AC0");
// MATCH func_001694D0
int pachislot_001694d0(char *o) { if ((D_004A12D8_1694D0 & 0x20000) != 0) *(int *)(o + 468) = 1; if ((*(int *)(o + 464))++ < 10) return 0; *(int *)(o + 464) = 0; if (*(int *)(o + 364) > 0 && *(int *)(o + 360) < 3) { func_00168AC0_1694D0(o); return 0; } *(V8_1694_001694D0 *)(o + 544) = D_004A2E60_1694D0[0]; return 0; }
