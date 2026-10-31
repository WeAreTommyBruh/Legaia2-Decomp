/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A1610;
extern char D_00321640[];
int func_001911F0(void *);
// MATCH func_00114360
int FUN_00114360(void) { if (D_004A1610 != 0) return func_001911F0(D_00321640); return 1; }

extern int D_004A1618, D_004A15F4, D_004A1638; extern char D_00321588[], D_00321550[]; void func_00113978(void); void func_001140C0(char *, int, char *); void func_001143C8(void);
// MATCH func_00114310
int FUN_00114310(void) { D_004A1618++; func_00113978(); func_001140C0(D_00321588, D_004A15F4, D_00321550); func_001143C8(); return D_004A1638; }

extern int D_004A15F4_001143C8 __asm__("D_004A15F4"), D_004A162C, D_004A1630; extern int D_00321588_001143C8[] __asm__("D_00321588"); extern char D_00321300[], D_00321640_001143C8[] __asm__("D_00321640"), D_00321550_001143C8[] __asm__("D_00321550"); void func_002E5D30(void); void func_002E6380(int); void func_00190DC0(int); void func_001948E8(char *); void func_002E56F0(int); void func_002E56B0(int); void func_002E6450_001143C8(int) __asm__("func_002E6450"); void func_002E55D0_001143C8(int, int) __asm__("func_002E55D0"); void func_002E55A0(int, int); void func_001926F8(int *); void func_00190FC0(char *); void func_001953F0(char *);
// MATCH func_001143C8
void FUN_001143c8(void) { func_002E5D30(); func_002E6380(3); func_00190DC0(D_004A15F4_001143C8); func_001948E8(D_00321300); func_002E56F0(D_004A162C); func_002E56B0(D_004A162C); func_002E56F0(D_004A1630); func_002E56B0(D_004A1630); func_002E6450_001143C8(2); func_002E55D0_001143C8(2, D_00321588_001143C8[44]); func_002E6380(2); func_002E55A0(2, D_00321588_001143C8[45]); func_001926F8(D_00321588_001143C8); func_00190FC0(D_00321640_001143C8); func_001953F0(D_00321550_001143C8); func_002E5D30(); }
