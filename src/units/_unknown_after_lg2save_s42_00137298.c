#include "../common.h"
extern int D_004A140C, D_004A238C, D_004A2390;
typedef struct { short s[6]; } E;
extern E D_0562A8E0[][256][4];
// MATCH func_00137298
void FUN_00137298(int a, int k) { if (a != 0 && (D_004A140C & 0x200)) { D_0562A8E0[D_004A238C][D_004A2390][k].s[0] = 0; D_0562A8E0[D_004A238C][D_004A2390][k].s[1] = 0; D_0562A8E0[D_004A238C][D_004A2390][k].s[2] = 0; D_0562A8E0[D_004A238C][D_004A2390][k].s[3] = 0; D_0562A8E0[D_004A238C][D_004A2390][k].s[4] = 0; D_0562A8E0[D_004A238C][D_004A2390][k].s[5] = 0; } }
