/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_004A380A; typedef struct { char p[824]; int v; } O_001E42A0;
// MATCH func_001E42A0
void FUN_001e42a0(int a, O_001E42A0 *p, int v) { if (D_004A380A != 0) { if (p != 0) p->v = v; } }

extern char D_004A380A; typedef struct { char p[828]; int v; } O_001E42C0;
// MATCH func_001E42C0
void FUN_001e42c0(int a, O_001E42C0 *p, int v) { if (D_004A380A != 0) { if (p != 0) p->v = v; } }

extern char D_004A380A; typedef struct { char p[832]; int v; } O_001E4308;
// MATCH func_001E4308
void FUN_001e4308(int a, O_001E4308 *p, unsigned v) { if (D_004A380A != 0) { if (p != 0) { if (v < 256) p->v = v; } } }

extern char D_004A380A;
// MATCH func_001E42E0
void FUN_001e42e0(unsigned char *o, unsigned char a, unsigned char b, unsigned char c) { if (D_004A380A != 0) { o[0] = a; o[1] = b; o[2] = c; } }

extern char D_004A380A; typedef struct { int p; int a, b; } O_001E4330;
// MATCH func_001E4330
void FUN_001e4330(O_001E4330 *o, int a, int b) { if (D_004A380A != 0) { o->a = a; o->b = b; } }

extern char D_004A380A_001E40A8 __asm__("D_004A380A"); int func_001E3CD8(int); void func_001E3E38(int, int, int); void func_001E3380(int, int, int);
// MATCH func_001E40A8
int FUN_001e40a8(int a, int b, int c) { int r; if (D_004A380A_001E40A8 == 0) return 0; r = func_001E3CD8(a); if (r == 0) return 0; func_001E3E38(a, r, c); func_001E3380(a, r, 0); return r; }

extern char D_004A380A_001E4120 __asm__("D_004A380A"); int func_001E3D98(int); void func_001E3E38(int, int, int); void func_001E3380(int, int, int);
// MATCH func_001E4120
int FUN_001e4120(int a, int b, int x, int c) { int r; if (D_004A380A_001E4120 == 0) return 0; r = func_001E3D98(a); if (r == 0) return 0; func_001E3E38(a, r, c); func_001E3380(a, r, 0); return r; }

extern char D_004A380A_001E3F20 __asm__("D_004A380A"); extern int D_004A3864_001E3F20 __asm__("D_004A3864"); extern char D_0044B978[]; void func_001118F8_001E3F20(char *) __asm__("func_001118F8"); void func_001322C0(void *, int, int);
// MATCH func_001E3F20
void FUN_001e3f20(int a, void *p) { if (D_004A380A_001E3F20 != 0) { if (D_004A3864_001E3F20 & 0x200) func_001118F8_001E3F20(D_0044B978); if (p != 0) func_001322C0(p, -1, 1); } }

typedef struct { char p[300]; int n; int a[1]; } O_001E4198;
extern char D_004A380A_001E4198 __asm__("D_004A380A"); void func_001DFEE0(int, float);
// MATCH func_001E4198
void FUN_001e4198(int a, O_001E4198 *o, float f) { int i; int *q; if (D_004A380A_001E4198 != 0 && o != 0) { if (o->n > 0) { q = o->a; i = o->n; do { if (q[64] == 2) func_001DFEE0(q[0], f); i--; q++; } while (i != 0); } } }

typedef struct { char p[300]; int n; int a[1]; } O_001E4350;
extern char D_004A380A_001E4350 __asm__("D_004A380A"); void func_001D8F60(int, int);
// MATCH func_001E4350
void FUN_001e4350(int a, O_001E4350 *o, int b) { int i; int *q; if (D_004A380A_001E4350 != 0 && o != 0) { if (o->n > 0) { q = o->a; i = o->n; do { if (q[64] == 1) func_001D8F60(q[0], b); i--; q++; } while (i != 0); } } }

typedef struct { int w0; } O_001E4218;
extern char D_004A380A_001E4218 __asm__("D_004A380A"); int func_002D9440(float); void func_001E48E0(int, int, int, int, int);
// MATCH func_001E4218
void FUN_001e4218(int a, O_001E4218 *o, float *v) { int x, y, z; if (D_004A380A_001E4218 != 0) { x = func_002D9440(v[0]); y = func_002D9440(v[1]); z = func_002D9440(v[2]); func_001E48E0(9, o->w0, x, y, z); } }

typedef struct { char p[52]; int w52; char q[200]; } A_001E4700;
extern A_001E4700 D_00346780[], D_0035A780[];
// MATCH func_001E4700
int FUN_001e4700(void) { int i; for (i = 0; i < 291; i++) { if (D_00346780[i].w52 > 0) return 1; } for (i = 0; i < 75; i++) { if (D_0035A780[i].w52 > 0) return 1; } return 0; }

int func_001E24D8(void *); int func_001E24E8(void *); int func_001E24E0(void *); void func_001E2530_001E7D38(void *) __asm__("func_001E2530"); int func_001E2588(void *); void func_001EAC98(void *); int func_001322C0_001E7D38(int, int, int) __asm__("func_001322C0");
// MATCH func_001E7D38
int FUN_001e7d38(void *o, int a, int b) { if (func_001E24D8(o) == 0 && func_001E24E8(o) == 0) return func_001322C0_001E7D38(a, b, 1); if (func_001E24E0(o) == 0) return 0; func_001E2530_001E7D38(o); if (func_001E2588(o) != 1) return 0; func_001EAC98(o); return 0; }

extern char D_004A380A_001E3E38 __asm__("D_004A380A"); extern int D_004A3864_001E3E38 __asm__("D_004A3864"); extern int D_004A3838_001E3E38 __asm__("D_004A3838"); extern int D_004A383C_001E3E38 __asm__("D_004A383C"); extern char D_0044B938[];
void func_001118F8_001E3E38(char *, int *, int *, int) __asm__("func_001118F8"); void func_001E2478(int, int); void func_001E2488(int, int); void func_001E2498(int, int);
// MATCH func_001E3E38
void FUN_001e3e38(int a, int *h, int c) { int n; int i; int *p; int *q; if (D_004A380A_001E3E38 == 0) return; if (D_004A3864_001E3E38 & 0x200) func_001118F8_001E3E38(D_0044B938, h + 4, h, c); if (h == 0) return; n = h[75]; if (n > 0) { p = h + 76; i = n; do { if (p[64] != 0) { func_001E2478(p[0], 1); func_001E2488(p[0], 0); func_001E2498(p[0], c); } i--; p++; } while (i != 0); } h[1] = 0; if (D_004A3838_001E3E38 == 0) { h[2] = (int)h; D_004A3838_001E3E38 = (int)h; } else { q = (int *)D_004A383C_001E3E38; q[1] = (int)h; h[2] = (int)q; } D_004A383C_001E3E38 = (int)h; }

extern char D_004A380A_001E3D98 __asm__("D_004A380A"); extern int D_004A3864_001E3D98 __asm__("D_004A3864"); extern char D_0044B908[];
int func_00132A20(int, int); int func_00198790(int, float *, float *, int); void func_001118F8_001E3D98(char *, int) __asm__("func_001118F8");
// MATCH func_001E3D98
int FUN_001e3d98(int a, int b, int c) { int r; float v[4]; float w[4]; if (D_004A380A_001E3D98 == 0) return 0; r = func_00132A20(b, c); if (r == 0) return 0; v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 1.0f; w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 1.0f; func_00198790(r, v, w, 0); if (D_004A3864_001E3D98 & 0x200) func_001118F8_001E3D98(D_0044B908, r); return r; }

extern char D_004A380A_001E3CD8 __asm__("D_004A380A"); extern int D_004A3864_001E3CD8 __asm__("D_004A3864"); extern char D_0044B8E0[];
int func_00196FF8_001E3CD8(void) __asm__("func_00196FF8"); int func_00132670(int, int, int); int func_00198790(int, float *, float *, int); void func_001118F8_001E3CD8(char *, int, int) __asm__("func_001118F8");
// MATCH func_001E3CD8
int FUN_001e3cd8(int a, int b) { int r; float v[4]; float w[4]; if (D_004A380A_001E3CD8 == 0) return 0; while (func_00196FF8_001E3CD8() != 0) ; r = func_00132670(b, 0, 0); if (r == 0) return 0; v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 1.0f; w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 1.0f; func_00198790(r, v, w, 0); if (D_004A3864_001E3CD8 & 0x200) func_001118F8_001E3CD8(D_0044B8E0, b, r); return r; }
