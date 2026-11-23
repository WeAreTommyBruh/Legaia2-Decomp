/* Functions of this report unit, matched by hand. */
// cflags: -fno-strict-aliasing
#include "../common.h"


typedef struct {float x,y,z,w;} Point_0013D118;
typedef struct {long a,b;} Pair_0013D118;
extern Pair_0013D118 D_00434B50_13D118[] __asm__("D_00434B50");
extern Point_0013D118 D_05BF6950_13D118[] __asm__("D_05BF6950");
extern int D_004A237C_13D118 __asm__("D_004A237C");
void *func_002DC804_13D118(void *,int,unsigned) __asm__("func_002DC804");
void func_0018F368_13D118(void *,void *,void *) __asm__("func_0018F368");
void func_00249950_13D118(void *,void *) __asm__("func_00249950");
void func_00230078_13D118(void *,int,int,int) __asm__("func_00230078");
void func_0022F3C8_0013D118(float,float) __asm__("func_0022F3C8");
// MATCH func_0013D118
void FUN_0013d118(char *p, int a, int b, int c) { Point_0013D118 zero; Pair_0013D118 k; Point_0013D118 pos, end, *out; func_002DC804_13D118(&zero, 0, 16); k = D_00434B50_13D118[0]; func_0018F368_13D118(&pos, (void*)0x70003f80, &k); func_0022F3C8_0013D118(pos.x, pos.z); func_0018F368_13D118(&pos, (void*)0x70003f80, &zero); func_0018F368_13D118(&end, (void*)0x70003f80, p+32); func_00249950_13D118(&pos, &end); out = &D_05BF6950_13D118[D_004A237C_13D118]; out->x = pos.x; out->y = pos.y; out->z = pos.z; D_004A237C_13D118++; func_00230078_13D118(p, a, b, c); }


typedef struct {float x,y,z,w;} Point_0013D238;
extern Point_0013D238 D_05BF6950_0013D238[] __asm__("D_05BF6950");
extern int D_004A237C_0013D238 __asm__("D_004A237C");
void *func_002DC804_13D238(void *,int,unsigned) __asm__("func_002DC804");
void func_0018F368_13D238(void *,void *,void *) __asm__("func_0018F368");
void func_00249950_13D238(void *,void *) __asm__("func_00249950");
void func_002306E8_13D238(void *,int,int,int) __asm__("func_002306E8");
// MATCH func_0013D238
void FUN_0013d238(char *p, int a, int b, int c) { Point_0013D238 zero; Point_0013D238 pos, end, *out; func_002DC804_13D238(&zero, 0, 16); func_0018F368_13D238(&pos, (void*)0x70003f80, &zero); func_0018F368_13D238(&end, (void*)0x70003f80, p+32); func_00249950_13D238(&pos, &end); out = &D_05BF6950_0013D238[D_004A237C_0013D238]; out->x = pos.x; out->y = pos.y; out->z = pos.z; D_004A237C_0013D238++; func_002306E8_13D238(p, a, b, c); }
