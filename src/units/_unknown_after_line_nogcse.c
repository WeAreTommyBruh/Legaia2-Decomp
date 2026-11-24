/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int pad0[4]; int x, y, z, pad1c; int bx, by, age, life, pad30, color; float ang, scale; } E186_00186C70;
typedef struct { E186_00186C70 e[64]; int pad[3]; float fade; int pad2[2]; int ox, oy, oz; } B186_00186C70;
extern float D_004A0158_186C70 __asm__("D_004A0158");
void func_002478D0_186C70(int) __asm__("func_002478D0");
void func_00243A68_186C70(int, void *) __asm__("func_00243A68");
void func_002478A8_186C70(void *) __asm__("func_002478A8");
extern char D_00342CD0_186C70[] __asm__("D_00342CD0");
int func_00235C48_186C70(void *, void *, void *, void *, float, float) __asm__("func_00235C48");
float func_0022F3C8_186C70(float, float) __asm__("func_0022F3C8");
void func_001867A8_186C70(float, float, long long, int, int, int, int, int, int, int, int) __asm__("func_001867A8");
// MATCH func_00186C70
void FUN_00186c70(B186_00186C70 *b) { E186_00186C70 *e; int i; int alpha, x, y, tx, ty, qx, qy; float fx, fy, sc, ang; int v[3]; float d; int pad; E186_00186C70 *p; func_002478D0_186C70(16); func_002478D0_186C70(256); func_002478D0_186C70(64); func_00243A68_186C70(1, D_00342CD0_186C70); func_002478A8_186C70(D_00342CD0_186C70); for (i = 0; i < 64; i++) { e = &b->e[i]; if (e->life <= 0) { e->life = 0; } else { alpha = (int)((float)e->life * b->fade); if (func_00235C48_186C70(&d, &pad, v, e, 1000.0f, 1000.0f) > 0) { qx = v[0] / 16; tx = e->bx - 1728; fx = (float)(qx + tx); qy = v[1] / 16; ty = e->by - 1936; fy = (float)(qy + ty); sc = d / 1000.0f; e->z = v[2]; x = (int)fx; y = (int)fy; e->x = x; e->y = y; e->scale = sc; p = &b->e[(i - 1) & 63]; ang = -func_0022F3C8_186C70((float)p->x - fx, (float)p->y - fy) - D_004A0158_186C70; e->ang = ang; func_001867A8_186C70(((float)e->age * 0.00390625f + 2.0f) * sc, ang, 0x2007c106a5323140LL, x + b->ox, y + b->oy, v[2] + b->oz, e->color * 32 + 129, 257, 31, 30, alpha * 2); } } e->age++; e->life--; } }


typedef struct { char pad[324]; int n; int pad2; int a[1]; } O_00187948;
typedef struct { float x, y, z, w; } V4_00187948;
extern float D_004A016C_187948 __asm__("D_004A016C");
extern char D_004A34A0_187948[] __asm__("D_004A34A0"), D_0043EAD8_187948[] __asm__("D_0043EAD8");
void sammon_00227e58(O_00187948 *, int) __asm__("func_00227E58");
void sammon_00227e68(O_00187948 *, int) __asm__("func_00227E68");
int sammon_00227a00(O_00187948 *, int, int, V4_00187948 *) __asm__("func_00227A00");
void func_0018D1F0_187948(void *, int) __asm__("func_0018D1F0");
int DbgPrintf(char *, ...) __asm__("func_001118F8");
static inline int at_00187948(O_00187948 *o, int i) { if (i < 0) return 0; if (i >= o->n) return 0; return o->a[i]; }
// MATCH func_00187948
void FUN_00187948(O_00187948 *o, int b) { V4_00187948 v; int i, n, e, r; v.y = D_004A016C_187948; v.w = 1.0f; v.x = 0; v.z = 0; sammon_00227e58(o, 0x70003e00); n = o->n; for (i = 0; i < n; i++) { e = at_00187948(o, i) + 0x20; r = sammon_00227a00(o, b, e, &v); func_0018D1F0_187948(D_004A34A0_187948, e); if (r == 0) DbgPrintf(D_0043EAD8_187948); } sammon_00227e68(o, 0x70003e00); }


typedef struct { char pad[324]; int n; int pad2; int a[1]; } O_00187A68;
typedef struct { float x, y, z, w; } V4_00187A68;
extern float D_004A0170_187A68 __asm__("D_004A0170");
extern char D_004A34A0_00187A68[] __asm__("D_004A34A0"), D_0043EAD8_00187A68[] __asm__("D_0043EAD8");
void sammon_00227e48(O_00187A68 *, int, int) __asm__("func_00227E48");
void sammon_00227e68_187A68(O_00187A68 *, int) __asm__("func_00227E68");
int sammon_00227a00_187A68(O_00187A68 *, int, int, V4_00187A68 *) __asm__("func_00227A00");
void func_0018D1F0_187A68(void *, int) __asm__("func_0018D1F0");
int DbgPrintf(char *, ...) __asm__("func_001118F8");
static inline int at_00187A68(O_00187A68 *o, int i) { if (i < 0) return 0; if (i >= o->n) return 0; return o->a[i]; }
// MATCH func_00187A68
void FUN_00187a68(O_00187A68 *o, int b) { V4_00187A68 v; int i, n, e, r; v.y = D_004A0170_187A68; v.w = 1.0f; v.x = 0; v.z = 0; sammon_00227e48(o, 100, 0x70003e00); n = o->n; for (i = 0; i < n; i++) { e = at_00187A68(o, i) + 0x20; r = sammon_00227a00_187A68(o, b, e, &v); func_0018D1F0_187A68(D_004A34A0_00187A68, e); if (r == 0) DbgPrintf(D_0043EAD8_00187A68); } sammon_00227e68_187A68(o, 0x70003e00); }
