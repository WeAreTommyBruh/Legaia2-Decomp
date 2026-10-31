/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_0041EEA8_00294FA8[] __asm__("D_0041EEA8"); int func_00164CD8(int);
// MATCH func_00294FA8
int battleslot_00294fa8(int a) { return D_0041EEA8_00294FA8[func_00164CD8(a) - 1]; }

typedef struct { char c[8]; } V8_00294BD0;
typedef struct { char p[56]; int w; char p2[16]; V8_00294BD0 a; V8_00294BD0 b; } O_00294BD0;
// MATCH func_00294BD0
int battleslot_00294bd0(O_00294BD0 *o) { if (o->w-- <= 0) { o->w = 0; o->a = o->b; } return -1; }

typedef struct { char pad[60]; char sub[1]; char pad1[7]; int a68; } S_00294B20;
extern char D_00499648[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00295078(void *, int); void func_00108B80_00294B20(void *) __asm__("func_00108B80");
// MATCH func_00294B20
void battleslot_00294b20(S_00294B20 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a68, D_00499648, 270); func_00164500(s->sub, 2); func_00295078(s, 2); if (fl & 1) func_00108B80_00294B20(s); }

typedef struct { char c[8]; } V8_294d50_00294D50;
typedef struct { char pad[76]; V8_294d50_00294D50 v; } S_294d50_00294D50;
extern V8_294d50_00294D50 D_004A6790[2];
int func_00164A00(void *);
// MATCH func_00294D50
int battleslot_00294d50(S_294d50_00294D50 *s) { if (func_00164A00(s) != 0) s->v = D_004A6790[0]; return -1; }

typedef struct { char c[8]; } V8_294c68_00294C68;
typedef struct { char pad[76]; V8_294c68_00294C68 v; } S_294c68_00294C68;
extern V8_294c68_00294C68 D_004A6780[2];
int func_00164A20(void *);
// MATCH func_00294C68
int battleslot_00294c68(S_294c68_00294C68 *s) { if (func_00164A20(s) != 0) s->v = D_004A6780[0]; return -1; }

typedef struct { char c[8]; } V8_00294C00;
typedef struct { char p[56]; int w; char p2[16]; V8_00294C00 v; } O1_00294C00;
extern V8_00294C00 D_004A6778[3];
void func_00294BA0(void *); void func_001649D8(void *, int); void func_00294DC8(void *, int);
// MATCH func_00294C00
int battleslot_00294c00(O1_00294C00 *o) { func_00294BA0(o); o->w = 1500; func_001649D8(o, 1); func_00294DC8(o, 0x80808080); o->v = D_004A6778[0]; return -1; }

typedef struct { char p[72]; int w72; short adj; short pad; void (*fn)(void *); } O2_00294DD0;
int func_00196FF8_00294DD0(void) __asm__("func_00196FF8"); void func_00294598(void *); void func_00164608_00294DD0(void *) __asm__("func_00164608"); void func_00294E50(void *);
// MATCH func_00294DD0
int battleslot_00294dd0(O2_00294DD0 *o) { int r; if (o->w72 == 0) { if (func_00196FF8_00294DD0() == 0) o->w72 = 1; return -1; } r = ((int (*)(void *))o->fn)((char *)o + o->adj); func_00294598(o); func_00164608_00294DD0((char *)o + 60); func_00294E50(o); return r; }

typedef struct { char c[8]; } V8_00294CB0;
typedef struct { char p[56]; int w; char p2[16]; V8_00294CB0 v; } O3_00294CB0;
extern V8_00294CB0 D_004A6788[3]; extern char D_00343028_00294CB0[] __asm__("D_00343028"); extern long D_004A12D8_00294CB0 __asm__("D_004A12D8");
void func_00294560(void *, int); void func_001649E0(void *); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00294CB0
int battleslot_00294cb0(O3_00294CB0 *o) { if (--o->w == 0 || (D_004A12D8_00294CB0 & 0x200040)) { func_00294560(o, 0); func_001649E0(o); o->v = D_004A6788[0]; func_0010C2B0(D_00343028_00294CB0, 120, 13, 1, 1, 0, 0); } return -1; }
