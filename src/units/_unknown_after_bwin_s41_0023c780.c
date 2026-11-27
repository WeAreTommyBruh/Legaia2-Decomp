#include "../common.h"
typedef struct { unsigned char r, g, b, a; } __attribute__((aligned(4))) Col_23C780;
extern int D_004A13E8, D_004A5430, D_004A148C; extern Col_23C780 D_004A1294;
void object_002436f8(int, int, int, int, int, int, int, int, Col_23C780);
// MATCH func_0023C780
void FUN_0023c780(int a, int b, int c, int d) {
  int save = D_004A13E8;
  D_004A13E8 = D_004A5430;
  object_002436f8(a * 32 + 0x6c00, (b + 0x790) * 16, 16 << (4 - D_004A148C), 8 << (4 - D_004A148C), c << 4, d << 4, 0x80, 0x78, D_004A1294);
  D_004A13E8 = save;
}
