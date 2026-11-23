/* Functions of this report unit, matched by hand. */
// compiler: 990721
#include "../common.h"

typedef struct { char p0[42]; signed char i42, i43; float f44, f48, f52, f56, f60, f64; } C_13B758_0013B758;
typedef struct { float x, y, z, w; } E_13B758_0013B758;
typedef struct { char p0[144]; E_13B758_0013B758 *e; } O_13B758_0013B758;
extern C_13B758_0013B758 D_0032A4B0_13B758[] __asm__("D_0032A4B0"); extern int D_004A1BA4_13B758 __asm__("D_004A1BA4"), D_004A132C_13B758 __asm__("D_004A132C"), D_004A1330_13B758 __asm__("D_004A1330"), D_004A1334_13B758 __asm__("D_004A1334"), D_004A1338_13B758 __asm__("D_004A1338"); extern O_13B758_0013B758 *D_004A2360_13B758 __asm__("D_004A2360");
// MATCH func_0013B758
void FUN_0013b758(float y) { float x = 0.0f, z = x; E_13B758_0013B758 *e; if (D_0032A4B0_13B758[0].i42 < 0) return; switch (D_004A1BA4_13B758) { case 0: x = 0.0f; break; case 1: z = (float)D_004A1338_13B758; x = (float)-D_004A1334_13B758; break; case 2: z = (float)D_004A1330_13B758; x = (float)-D_004A132C_13B758; break; } e = D_004A2360_13B758->e; ((E_13B758_0013B758 *)((char *)e + (D_0032A4B0_13B758[0].i42 << 4)))->y = x * 0.0078125f * D_0032A4B0_13B758[0].f44; if (0.0f <= z) ((E_13B758_0013B758 *)((char *)e + (D_0032A4B0_13B758[0].i42 << 4)))->x = z * 0.0078125f * D_0032A4B0_13B758[0].f52; else ((E_13B758_0013B758 *)((char *)e + (D_0032A4B0_13B758[0].i42 << 4)))->x = z * 0.0078125f * D_0032A4B0_13B758[0].f48; if (D_004A1BA4_13B758 == 0) ((E_13B758_0013B758 *)((char *)D_004A2360_13B758->e + (D_0032A4B0_13B758[0].i42 << 4)))->y = y; }

typedef struct { char p0[42]; signed char i42, i43; float f44, f48, f52, f56, f60, f64; } C_13B860_0013B860;
typedef struct { float x, y, z, w; } E_13B860_0013B860;
typedef struct { char p0[144]; E_13B860_0013B860 *e; } O_13B860_0013B860;
extern C_13B860_0013B860 D_0032A4B0_0013B860[] __asm__("D_0032A4B0"); extern int D_004A1BA4_0013B860 __asm__("D_004A1BA4"), D_004A1BA8_13B860 __asm__("D_004A1BA8"), D_004A132C_0013B860 __asm__("D_004A132C"), D_004A1330_0013B860 __asm__("D_004A1330"), D_004A1334_0013B860 __asm__("D_004A1334"), D_004A1338_0013B860 __asm__("D_004A1338"); extern O_13B860_0013B860 *D_004A2360_0013B860 __asm__("D_004A2360");
// MATCH func_0013B860
void FUN_0013b860(float y) { float x = 0.0f, z = x; E_13B860_0013B860 *e; if (D_0032A4B0_0013B860[0].i43 < 0) return; switch (D_004A1BA8_13B860) { case 0: x = 0.0f; break; case 1: z = (float)D_004A1338_0013B860; x = (float)-D_004A1334_0013B860; break; case 2: z = (float)D_004A1330_0013B860; x = (float)-D_004A132C_0013B860; break; } e = D_004A2360_0013B860->e; ((E_13B860_0013B860 *)((char *)e + (D_0032A4B0_0013B860[0].i43 << 4)))->y = x * 0.0078125f * D_0032A4B0_0013B860[0].f56; if (0.0f <= z) ((E_13B860_0013B860 *)((char *)e + (D_0032A4B0_0013B860[0].i43 << 4)))->x = z * 0.0078125f * D_0032A4B0_0013B860[0].f64; else ((E_13B860_0013B860 *)((char *)e + (D_0032A4B0_0013B860[0].i43 << 4)))->x = z * 0.0078125f * D_0032A4B0_0013B860[0].f60; if (D_004A1BA4_0013B860 == 0) ((E_13B860_0013B860 *)((char *)D_004A2360_0013B860->e + (D_0032A4B0_0013B860[0].i43 << 4)))->y = y; }

typedef struct { float x, y, z; } V3_13C800;
typedef struct { int pad[3]; float f[6]; int pad2; } E40_13C800;
extern E40_13C800 D_056C48E0[][256][8][32];
extern int D_004A6F0C, D_004A6EEC, D_004A238C, D_004A2390, D_004A6EF0;
extern V3_13C800 D_0055FC60, D_0055FC70;
#define E_13C800 D_056C48E0[D_004A238C][D_004A2390][D_004A6EF0][D_004A6EEC]
// MATCH func_0013C800
void FUN_0013c800(void) {
  if (D_004A6F0C == D_004A6EEC) {
    if (D_0055FC60.x != E_13C800.f[0] || D_0055FC60.y != E_13C800.f[1] || D_0055FC60.z != E_13C800.f[2]
     || D_0055FC70.x != E_13C800.f[3] || D_0055FC70.y != E_13C800.f[4] || D_0055FC70.z != E_13C800.f[5]) {
      D_0055FC60.x -= E_13C800.f[0];
      D_0055FC60.y -= E_13C800.f[1];
      D_0055FC60.z -= E_13C800.f[2];
      D_0055FC70.x -= E_13C800.f[3];
      D_0055FC70.y -= E_13C800.f[4];
      D_0055FC70.z -= E_13C800.f[5];
      return;
    }
  }
  D_004A6F0C = -1;
}
