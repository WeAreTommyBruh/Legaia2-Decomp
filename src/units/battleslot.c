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

typedef struct { char p0[0x34]; unsigned w34; char p1[0xc]; int w44; } X_00294E50;
typedef struct { char p[78]; short h; int w80; } S_00294E50;
typedef struct { char p[16]; unsigned long long *cur; } G_00294E50;
extern char D_00499658_294E50[] __asm__("D_00499658");
extern char *D_0041EEA8_294E50[] __asm__("D_0041EEA8");
extern G_00294E50 D_00314C20_294E50 __asm__("D_00314C20");
extern char D_004A6798_294E50[] __asm__("D_004A6798"), D_0041EE98_294E50[] __asm__("D_0041EE98");
extern int func_00164A00_294E50(void *) __asm__("func_00164A00");
extern int func_00164CD8_294E50(void *) __asm__("func_00164CD8");
extern int func_00130FD8_294E50(char *) __asm__("func_00130FD8");
extern void func_00239568_294E50(char *, int, int, char *) __asm__("func_00239568");
extern void func_0024BC98_294E50(int, int, int, int, void *) __asm__("func_0024BC98");
extern void func_00294718_294E50(void *) __asm__("func_00294718");
extern void func_00190328_294E50(void *) __asm__("func_00190328");
extern void func_00190420_294E50(void *) __asm__("func_00190420");
extern void func_00164668_294E50(void *) __asm__("func_00164668");
extern void func_0012CF78_294E50(void) __asm__("func_0012CF78");
extern void func_001633E8_294E50(int, int, void *) __asm__("func_001633E8");
extern int func_00294BA8_294E50(void) __asm__("func_00294BA8");
// MATCH func_00294E50
void battleslot_00294e50(S_00294E50 *s) { char *str; int n; unsigned long long *p; if (s->h == -1 && (int)s->w80 == (int)func_00294BA8_294E50) return; if (func_00164A00_294E50(s) != 0) str = D_0041EEA8_294E50[func_00164CD8_294E50(s) - 1]; else str = D_00499658_294E50; n = func_00130FD8_294E50(str); func_00239568_294E50(D_004A6798_294E50, 160 - n / 2, 128, str); func_0024BC98_294E50(((X_00294E50 *)s)->w44, 0x3140, 0x3c00, 0, &D_00314C20_294E50); func_00294718_294E50(s); func_00190328_294E50(&D_00314C20_294E50); p = D_00314C20_294E50.cur; p[0] = 0x44; p[1] = 0x42; p[2] = (unsigned long long)((X_00294E50 *)s)->w34 | 0x3f80000000000000ULL; p[3] = 1; p[4] = 0x156; D_00314C20_294E50.cur = p + 6; p[5] = 0; func_001633E8_294E50(0x100, 0x60, D_0041EE98_294E50); func_00190420_294E50(&D_00314C20_294E50); func_00164668_294E50((char *)s + 60); func_0012CF78_294E50(); }

