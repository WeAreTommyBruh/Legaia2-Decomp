#include "../src/common.h"

typedef struct { char pad[32]; float x, y, z; } P;
extern float D_004A0728;
int FUN_002dc978(void);
void FUN_0021dac8(float *, float);
// WIP func_23F990
void yokota_0023f990(P *p)
{
  p->x = p->x + (float)(FUN_002dc978() % 100 - 50);
  p->y = p->y + (float)(FUN_002dc978() % 100 - 50);
  p->z = p->z + (float)(FUN_002dc978() % 100 - 50);
  FUN_0021dac8(&p->x, D_004A0728);
}
