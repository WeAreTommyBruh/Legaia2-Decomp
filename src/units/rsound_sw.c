/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[64]; int kind; } E_10C690;
extern volatile int D_004A118C_10C690 __asm__("D_004A118C"); extern int D_004A12B0_10C690 __asm__("D_004A12B0"); extern char D_0042D928[], D_0042D950[];
void func_001118F8_10C690(char *, ...) __asm__("func_001118F8"); void func_002D4010(int, int, int);
// MATCH func_0010C690
void rsound_0010c690(char *o, int i) {
  int r, v;
  r = 45;
  switch (((E_10C690 *)(o + i * 40))->kind) {
  case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x22: case 0x55: case 0x66:
    r = 65;
    break;
  case 0x27: case 0x2c: case 0x2f:
    r = 70;
    break;
  case 0x2d: case 0x30: case 0x69: case 0x6b: case 0x6c: case 0x6d: case 0x74: case 0x7b:
    r = 60;
    break;
  case 0x29: case 0x2a: case 0x2b:
    r = 44;
    break;
  }
  if (D_004A118C_10C690 & 0x40) func_001118F8_10C690(D_0042D928, D_004A12B0_10C690);
  v = r * 0x7fff / 0x7f;
  func_002D4010(0, v, v);
  func_002D4010(1, v, v);
  if (D_004A118C_10C690 & 1) func_001118F8_10C690(D_0042D950, v);
}
