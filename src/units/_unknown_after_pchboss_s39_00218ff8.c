// compiler: 991111-01
// cflags: -fno-schedule-insns
#include "../common.h"
typedef struct { char p0[174]; short id; char p176[33]; unsigned char lv; } U_218FF8;
typedef struct { char p0[64]; float x, y; U_218FF8 *u; } O_218FF8;
extern char *D_004A1A20; extern char *D_003279A0[]; extern char D_00342CD0[];
void func_0018EB98(int, O_218FF8 *); void func_00219300(float, float, int, int); void func_002489F0(void);
void func_00249108(void); void func_002491D8(void); void func_00243A68(int, char *);
// MATCH func_00218FF8
void FUN_00218ff8(O_218FF8 *o)
{
  int id = o->u->id;
  float f; int n;
  if (*(unsigned *)(D_003279A0[id] + 24) & 2) return;
  f = *(float *)(D_004A1A20 + id * 5472 + 5204);
  { float h; if (1.0f <= f) { f = f - 1.0f; h = (float)o->u->lv * 0.5f * (1.0f - f); } else { register float a __asm__("$f0") = (float)o->u->lv; h = a * 0.5f; }
  n = h; }
  if (n == 0) return;
  func_00243A68(0, D_00342CD0);
  func_00249108();
  func_0018EB98(0x70003f80, o);
  func_002489F0();
  { float y = o->y * 4608.0f; float x = o->x * 4608.0f; func_00219300(x, y, 0x202020, n); }
  func_002491D8();
}
