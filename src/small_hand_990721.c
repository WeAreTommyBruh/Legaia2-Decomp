/* Small functions matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

// MATCH func_00108C20
void FUN_00108c20(void *s)
{
    float b;
    float t;
    if (FIELD(float, s, 32) == 0.0f && FIELD(float, s, 36) == 0.0f) {
        FIELD(float, s, 0) = FIELD(float, s, 8);
        return;
    }
    b = FIELD(float, s, 36);
    t = FIELD(float, s, 20);
    FIELD(float, s, 0) = t * (FIELD(float, s, 32) * t + b) + FIELD(float, s, 4);
}

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B598;
extern char D_00455618[], D_00454D80[]; int func_001621F8(int, char *, int); void func_00108B80(void *);
// MATCH func_0020B598
void pchevent_0020b598(O_0020B598 *o, int fl) { int i; o->vt = D_00455618; if (o->w12 != 0) { for (i = 0; i < o->w4; i++) { if (o->w12[i] != 0) func_001621F8(o->w12[i], D_00454D80, 117); } func_001621F8((int)o->w12, D_00454D80, 118); } if (fl & 1) func_00108B80(o); }

extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042E718[], D_0042E740[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8(char *, ...); void func_0010E820(int, int); void func_0010E938(int *, int);
// MATCH func_0010ED80
void FUN_0010ed80(int a) { int i; if (!(D_00343028[0] & 8) && D_004A3850 != 2) { if (D_004A118C & 0x40) func_001118F8(D_0042E718, D_004A12B0); if (D_004A118C & 1) func_001118F8(D_0042E740); func_0010E820(a, 103); for (i = 0; i < 32; i++) { if (i != 2) func_0010E938(D_00343028, i); } for (i = 0; i < 48; i++) { D_002F95F0[i] = -1; D_002F96B0[i] = -1; } } }

extern int D_00343028_0010EE78[] __asm__("D_00343028"); extern int D_004A3850_0010EE78 __asm__("D_004A3850"), D_004A118C_0010EE78 __asm__("D_004A118C"); extern char *D_004A12B0_0010EE78 __asm__("D_004A12B0"); extern char D_0042E750[], D_0042E778[]; extern int D_002F95F0_0010EE78[] __asm__("D_002F95F0"), D_002F96B0_0010EE78[] __asm__("D_002F96B0"); void func_001118F8(char *, ...); void func_0010E938(int *, int); void func_0010E428(int *); void func_002D38F8(void);
// MATCH func_0010EE78
void FUN_0010ee78(void) { int i; if (!(D_00343028_0010EE78[0] & 8) && D_004A3850_0010EE78 != 2) { if (D_004A118C_0010EE78 & 0x40) func_001118F8(D_0042E750, D_004A12B0_0010EE78); if (D_004A118C_0010EE78 & 1) func_001118F8(D_0042E778); for (i = 0; i < 32; i++) func_0010E938(D_00343028_0010EE78, i); for (i = 0; i < 48; i++) { D_002F95F0_0010EE78[i] = -1; D_002F96B0_0010EE78[i] = -1; } func_0010E428(D_00343028_0010EE78); func_002D38F8(); } }

extern int D_004A6DA4, D_004A1A84; void func_0012AEA8(int); int func_00121918(int);
// MATCH func_00121980
void battle_00121980(int a, int step) { func_0012AEA8(8); do { if (D_004A6DA4 < 0) D_004A6DA4 = D_004A1A84 - 1; if (D_004A6DA4 >= D_004A1A84) D_004A6DA4 = 0; if (func_00121918(D_004A6DA4)) return; D_004A6DA4 += step; } while (1); }

extern char D_0044B678[], D_0044B4A0[]; void func_00133528(int, char *, int); void func_001E2400(void *, int);
// MATCH func_001DFC78
void mizuki_001dfc78(int *o, int a) { o[25] = (int)D_0044B678; if (o[36] != 0) func_00133528(o[36], D_0044B4A0, 154); if (o[22] != 0) func_00133528(o[22], D_0044B4A0, 155); if (o[21] != 0) { if (o[57] != 0) func_00133528(o[21], D_0044B4A0, 156); } o[22] = 0; o[36] = 0; o[21] = 0; func_001E2400(o, a); }

extern char D_00314C20[]; void func_00190328(char *); void func_00190420(char *);
// MATCH func_00164668
void FUN_00164668(int *o) { int *p; int *nx; func_00190328(D_00314C20); p = (int *)((int *)o[0])[23]; if (p != (int *)o[0]) do { int *vt = (int *)p[26]; nx = (int *)p[23]; ((void (*)(int))*(int *)((char *)vt + 28))((int)p + *(short *)((char *)vt + 24)); p = nx; } while (p != (int *)o[0]); func_00190420(D_00314C20); }

// MATCH func_00166FD8
int pachislot_00166fd8(int *o, int k) { if (o[2] == 0 && k == 4) return 0; if (o[2] == 1 && k == 5) return 1; if (o[2] == 2 && k == 6) return 2; if (o[2] == 3 && k == 7) return 3; return -1; }

typedef struct { char p[5216]; int a; int b; int c; int d; char q[240]; } E_00126798;
extern E_00126798 *D_004A1A20; extern int D_003279A0[];
// MATCH func_00126798
void battle_00126798(void) { int i; for (i = 0; i < 10; i++) { if (D_003279A0[i] != 0) { if (D_004A1A20[i].c <= D_004A1A20[i].a) D_004A1A20[i].c = D_004A1A20[i].a; if (D_004A1A20[i].b >= D_004A1A20[i].d) D_004A1A20[i].d = D_004A1A20[i].b; } } }

extern char D_0053FD00[]; extern int D_004A6DD0, D_004A6D00, D_004A6D04, D_004A6D08;
int func_0012C1E8(void); int func_0015ADE8(char *, int); int func_0015AE08(char *, int); int func_001565B0(int, int, int); int func_00156408(int, int, int); int func_00156D38(int, int, int); int func_00156B58(int, int);
// MATCH func_00118638
void battle_00118638(void) { int h; if (func_0012C1E8() == 0) return; h = func_0015ADE8(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_001565B0(h, 8768, 15760); if (D_004A6D00 != 0) func_00156408(h, D_004A6D04, D_004A6D08); } h = func_0015AE08(D_0053FD00, 0); if (h != 0) { if (D_004A6DD0 == 0) func_00156D38(h, 9792, 15768); if (D_004A6D00 != 0) func_00156B58(h, D_004A6D04); } D_004A6DD0 = 1; }

extern char D_004A3698[];
extern char D_004A36A8[];
extern char D_004A3688[];
unsigned long long func_001118F8_0018D550(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D550
void FUN_0018d550(float *p, float *q)
{
  int i;
  float v;
  while (p < q)
  {
    func_001118F8_0018D550(D_004A3698, p);
    i = 3;
    do
    {
      v = *p;
      i--;
      p++;
      func_001118F8_0018D550(D_004A36A8, (double) v);
    }
    while (i >= 0);
    func_001118F8_0018D550(D_004A3688);
  }

  func_001118F8_0018D550(D_004A3688);
}

typedef struct { char p[20]; int w20; } P_00294598;
typedef union { int w; struct { unsigned short a; short b; } s; } U;
typedef struct { P_00294598 *p; int pad4; U u; int w12; char pad16[24]; short d40; short i42; short v44; short v46; } O_00294598;
extern long D_004A12C8; extern long D_004A12D8; extern long D_004A12E0; extern char D_00343028_00294598[] __asm__("D_00343028");
int func_001114B0(void); void func_00164C10(O_00294598 *); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00294598
void FUN_00294598(O_00294598 *o) { int idx; void (*fn)(void *); int d; int dl; long e; if (func_001114B0() != 0) { func_00164C10(o); } else if ((D_004A12C8 & 4) != 0) { o->u.s.a = 0xffff; o->w12 = o->u.s.b; if (((D_004A12D8 | D_004A12E0) & 0x1000) != 0) o->u.s.b = (unsigned short)o->u.s.b - 1; if (((D_004A12D8 | D_004A12E0) & 0x4000) != 0) o->u.s.b = (unsigned short)o->u.s.b + 1; if (o->u.s.b < 0) o->u.s.b = (unsigned short)o->u.s.b + *(unsigned short *)&o->p->w20; if (o->u.s.b >= o->p->w20) o->u.s.b = (unsigned short)o->u.s.b - *(unsigned short *)&o->p->w20; idx = o->i42; if (idx > 0) { long *vt = *(long **)((char *)o + o->v44); e = vt[idx - 1]; fn = (void (*)(void *))(e >> 32); } else fn = *(void (**)(void *))&o->v44; dl = o->d40; d = idx > 0 ? (short)e + dl : dl; fn((char *)o + d); } else { func_00164C10(o); } if (o->w12 != o->u.s.b) func_0010C2B0(D_00343028_00294598, 120, 13, 1, 0, 1, 0); }

typedef struct { short delta; short index; union { int (*fn)(void *, int); short voff; } u_00168280;
} PMF;
extern char D_0043CCF0[]; extern char D_0043CD00[]; extern char D_0043CD10[]; extern int D_00334830[];
void func_001118F8_00168280() __asm__("func_001118F8");
#define PMFCALL(res, a) { int idx = f.index; int (*fn)(void *, int); long e; int dl; int d; if (idx > 0) { long *vt = *(long **)(o + f.u_00168280.voff); e = vt[idx - 1]; fn = (int (*)(void *, int))(e >> 32); } else fn = f.u_00168280.fn; dl = f.delta; d = idx > 0 ? (short)e + dl : dl; res = fn(o + d, a); }
// MATCH func_00168280
int pachislot_00168280(char *o, PMF f) { int i, k, r, a, b, c; i = 0; do { PMFCALL(r, i) if (r != 1) break; i++; } while (i < 6); if (i >= 6) return 0; func_001118F8_00168280(D_0043CCF0, i); a = -1; b = -1; c = -1; for (k = 5; i < k; k--) { PMFCALL(r, k) func_001118F8_00168280(D_0043CD00, k, D_00334830[r]); if (r == 2) a = k; if (r == 3) b = k; if (r == 4) c = k; } if (b >= 0) i = b; else if (a >= 0) i = a; else if (c >= 0) i = c; func_001118F8_00168280(D_0043CD10, i, a, b); return i; }

typedef struct { char p[8]; int w8; char q[4]; char *w16; int *w20; int *w24; char *w28; signed char b32; } O__002033C0;
int func_002DD4B0(void *, void *);
// MATCH func_002033C0
char *FUN_002033c0(O__002033C0 *o, char *key, int *out)
{
    int i, off;
    if (out != 0) *out = 0;
    if (o->b32 == 1) {
        off = 0;
        for (i = 0; i < o->w8; i++, off += 16) {
            if (func_002DD4B0(key, o->w28 + off) == 0) {
                if (out != 0) *out = o->w20[i];
                return o->w16 + o->w24[i];
            }
        }
    }
    return 0;
}

extern char D_004A3698_0018D4A8[] __asm__("D_004A3698"); extern char D_004A36A0[]; extern char D_004A3688_0018D4A8[] __asm__("D_004A3688");
unsigned long long func_001118F8_0018D4A8(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D4A8
void FUN_0018d4a8(int *p, int *q)
{
  int i;
  int v;
  while (p < q)
  {
    func_001118F8_0018D4A8(D_004A3698_0018D4A8, p);
    i = 3;
    do
    {
      v = *p;
      p++;
      func_001118F8_0018D4A8(D_004A36A0, v);
      i--;
    }
    while (i >= 0);
    func_001118F8_0018D4A8(D_004A3688_0018D4A8);
  }

  func_001118F8_0018D4A8(D_004A3688_0018D4A8);
}

extern char D_004A3698_0018D600[] __asm__("D_004A3698"); extern char D_004A36A0_0018D600[] __asm__("D_004A36A0"); extern char D_004A3688_0018D600[] __asm__("D_004A3688");
extern int D_004A129C;
unsigned long long func_00239568(char *, ...);
// MATCH func_0018D600
void FUN_0018d600(int *p, int *q)
{
  int i;
  int v;
  int save;
  save = D_004A129C;
  D_004A129C = 1;
  while (p < q)
  {
    func_00239568(D_004A3698_0018D600, p);
    i = 3;
    do
    {
      v = *p;
      p++;
      func_00239568(D_004A36A0_0018D600, v);
      i--;
    }
    while (i >= 0);
    func_00239568(D_004A3688_0018D600);
  }
  func_00239568(D_004A3688_0018D600);
  D_004A129C = save;
}

extern int *D_004A6F44; extern char D_0043C280[], D_0043C290[], D_0043C2B8[];
unsigned long long func_001118F8_00161908(char *, ...) __asm__("func_001118F8");
// MATCH func_00161908
void FUN_00161908(void) { int *p, *e, *c; char *b; func_001118F8_00161908(D_0043C280); b = (char *)D_004A6F44[0]; p = *(int **)(b + 128); e = (int *)(b + 128); c = p; if (p != e) { do { p = (int *)*c; func_001118F8_00161908(D_0043C290, c, c[1], p, c[2]); c = p; } while (p != e); } func_001118F8_00161908(D_0043C2B8); e = (int *)D_004A6F44[0]; p = (int *)*e; c = p; if (p != e) { do { p = (int *)*c; func_001118F8_00161908(D_0043C290, c, c[1], p, c[2]); c = p; } while (p != e); } }
