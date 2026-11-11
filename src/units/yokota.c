/* Functions of this report unit, matched by hand. */
#include "../common.h"


typedef struct { char pad[32]; float f32, f36, f40; char pad2[64 - 44]; float f64, f68, f72; char pad3[80 - 76]; char sub[120]; float f200; } P_0023DEF0_23DEF0;
extern int D_004A13C8_23DEF0 __asm__("D_004A13C8");
extern volatile float D_004A0704_23DEF0 __asm__("D_004A0704");
extern char D_005F7560_23DEF0[] __asm__("D_005F7560");
void func_00249108_23DEF0(void) __asm__("func_00249108");
void func_00249100_23DEF0(float, float, float) __asm__("func_00249100");
void func_00248CF8_23DEF0(int, float) __asm__("func_00248CF8");
void func_002492E8_23DEF0(void *) __asm__("func_002492E8");
void func_002468F0_23DEF0(void *) __asm__("func_002468F0");
void func_0018F3D8_23DEF0(void *, int, int) __asm__("func_0018F3D8");
void func_0022D470_23DEF0(void *, void *, int) __asm__("func_0022D470");
void func_00246550_23DEF0(void *) __asm__("func_00246550");
void func_002491D8_23DEF0(void) __asm__("func_002491D8");
// MATCH func_0023DEF0
void yokota_0023def0(P_0023DEF0_23DEF0 *p) { char m[64]; func_00249108_23DEF0(); func_00249100_23DEF0(p->f32, p->f36, p->f40); func_00248CF8_23DEF0(0, p->f64); func_00248CF8_23DEF0(1, p->f68); func_00248CF8_23DEF0(2, p->f72); do { func_002492E8_23DEF0(D_005F7560_23DEF0); } while (0); func_002468F0_23DEF0(p); func_0018F3D8_23DEF0(m, 0x70003c00, 0x70003f80); func_0022D470_23DEF0(p->sub, m, 0x70003e00); if ((D_004A13C8_23DEF0 & 4) != 0) p->f200 = D_004A0704_23DEF0; func_00246550_23DEF0(p); func_002491D8_23DEF0(); }

