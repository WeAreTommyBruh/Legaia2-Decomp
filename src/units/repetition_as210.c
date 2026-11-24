/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00175E80;
typedef struct { char p[408]; V8_00175E80 v; } O_00175E80;
extern V8_00175E80 D_00336530[];
// MATCH func_00175E80
void repetition_00175e80(O_00175E80 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336530[i]; }

typedef struct { char c[8]; } B8_00174AB8;
extern B8_00174AB8 D_004A31F0_174AB8[] __asm__("D_004A31F0"), D_004A31D8_174AB8[] __asm__("D_004A31D8");
// MATCH func_00174AB8
void repetition_00174ab8(char *o) { *(int *)(o + 372) = 0; *(int *)(o + 344) = 0; *(short *)(o + 368) = -1; *(int *)(o + 352) = 0; *(int *)(o + 356) = 2; *(int *)(o + 340) = 1; *(int *)(o + 360) = 2; *(B8_00174AB8 *)(o + 888) = D_004A31F0_174AB8[0]; *(B8_00174AB8 *)(o + 408) = D_004A31D8_174AB8[0]; }

