// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../src/common.h"
typedef struct { union { int w; u16 a; } u; char pad[172]; } EA;
typedef struct { u16 c; char pad[174]; } EC;
typedef struct { u8 b; char pad[175]; } EB;
typedef struct { char pad[34]; u16 a; u16 unk24; u16 c; char pad2[67 - 40]; u8 b; char pad3[72 - 68]; } O;
typedef struct { char pad[148]; int k; char p1[168 - 152]; float a; char p2[4]; float c; char p3[236 - 180]; float b; char p4[472 - 240]; } Q;
extern int D_00314D08[3];
extern EA D_00419D50[3];
extern EC D_00419D54[3];
extern EB D_00419D7C[3];
extern struct { O o[5]; char pad[427 - 360]; u8 b; } D_003FDFA0;
extern struct { char pad[6384]; Q q[5]; char p2[8980 - 6384 - 5 * 472]; float f; } D_003FEBA8;
extern int D_005F8AF8[];
void FUN_0025ac90(void);
// WIP func_00265C30
void FUN_00265c30(void)
{
  int i;
  for (i = 0; i < 3; i++) {
    int slot = D_00314D08[i];
    if (slot == 5) {
      if (D_00419D50[i].u.w != 0)
        D_003FEBA8.f = D_003FDFA0.b = *(u8 *)((char *)D_00419D50 + 44 + i * 176);
      else {
        D_003FEBA8.f = 0;
        D_003FDFA0.b = 0;
      }
    }
    if (slot < 5) {
      O *o = &D_003FDFA0.o[slot];
      Q *q = &D_003FEBA8.q[slot];
      q->a = o->a = D_00419D50[i].u.a;
      q->c = o->c = *(u16 *)((char *)D_00419D50 + 4 + i * 176);
      q->k = D_005F8AF8[slot];
      q->b = o->b = *(u8 *)((char *)D_00419D50 + 44 + i * 176);
      if (q->a == 0.0f) {
        q->b = 0;
        o->a = o->a + 1;
        q->a = q->a + 1.0f;
        o->b = 0;
      }
    }
  }
  FUN_0025ac90();
}
