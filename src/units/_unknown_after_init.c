/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int n; int a[64]; int b[64]; } O_0024CDD0;
extern char D_0045DFF0[]; void func_001118F8_0024CDD0(char *) __asm__("func_001118F8");
// MATCH func_0024CDD0
int FUN_0024cdd0(O_0024CDD0 *o, int a, int b) { if (o->n >= 64) { func_001118F8_0024CDD0(D_0045DFF0); return 0; } o->a[o->n] = a; o->b[o->n] = b; o->n++; return 1; }

typedef struct { float x, y, z; } V3_0024CC58;
extern float D_004A087C_24CC58 __asm__("D_004A087C");
float func_0024CAE0_24CC58(V3_0024CC58, int, int) __asm__("func_0024CAE0");
// MATCH func_0024CC58
void FUN_0024cc58(int a, int b, int c, float *out, int p5, int p6) { V3_0024CC58 v, t; v.x = (float)a * D_004A087C_24CC58; v.y = (float)b * D_004A087C_24CC58; v.z = (float)c * D_004A087C_24CC58; t = v; *out = func_0024CAE0_24CC58(t, p5, p6); }

typedef struct { float x, y, z; } V3_0024CCD8;
V3_0024CCD8 func_0024C938_24CCD8(void) __asm__("func_0024C938");
// MATCH func_0024CCD8
void FUN_0024ccd8(int *r, int *g, int *b) { V3_0024CCD8 v, t; t = func_0024C938_24CCD8(); v = t; *r = (int)(v.x * 255.0f); *g = (int)(v.y * 255.0f); *b = (int)(v.z * 255.0f); }

