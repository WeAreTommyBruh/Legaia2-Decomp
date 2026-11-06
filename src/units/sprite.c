/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[16]; int a16; char pad1[56]; char *a76; } S_00201B78;
extern char D_00454088_00201B78[] __asm__("D_00454088"), D_00454010[];
void func_00133528(int, void *, int); void func_00108B80_00201B78(void *) __asm__("func_00108B80");
// MATCH func_00201B78
void sprite_00201b78(S_00201B78 *s, int fl) { s->a76 = D_00454088_00201B78; if (s->a16 != 0) func_00133528(s->a16, D_00454010, 47); s->a16 = 0; if (fl & 1) func_00108B80_00201B78(s); }

typedef struct { char p[12]; int w12; int w16; } S_201d08_00201D08;
extern char D_00454010_00201D08[] __asm__("D_00454010"); void func_00133528(int, void *, int); int func_0018B508(int, void *);
// MATCH func_00201D08
void sprite_00201d08(S_201d08_00201D08 *s, int a) { if (s->w16 != 0) func_00133528(s->w16, D_00454010_00201D08, 105); s->w16 = func_0018B508(a, &s->w12); }

typedef struct { int w0; char p[16]; float f20, f24; int w28, w32; char q[40]; char *w76; int w80; } O_002021C0;
extern char D_00454020[], D_00314C20_002021C0[] __asm__("D_00314C20"); void func_00201B08(O_002021C0 *);
// MATCH func_002021C0
O_002021C0 *sprite_002021c0(O_002021C0 *o) { func_00201B08(o); o->w76 = D_00454020; o->f20 = 255.0f; o->w80 = -1; o->w0 = (int)D_00314C20_002021C0; o->f24 = 255.0f; o->w28 = 8; o->w32 = 8; return o; }

extern int D_0036CBC0_202248[] __asm__("D_0036CBC0"), D_00319670_202248[] __asm__("D_00319670"); extern char D_00454010_202248[] __asm__("D_00454010"); void func_0024BD50_202248(int, int, int, int, int, char *, int) __asm__("func_0024BD50");
// MATCH func_00202248
void sprite_00202248(int *o, int x) { int v; func_0024BD50_202248(D_0036CBC0_202248[0], 12608, 15360, 0, x, D_00454010_202248, 208); v = D_00319670_202248[0]; o[0] = x; o[2] = v + 12608; o[1] = 16168; ((float *)o)[5] = 255.0f; ((float *)o)[6] = 255.0f; o[7] = 8; o[8] = 8; }

