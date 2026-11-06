/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[48]; float v; } S_0012E608;
void *func_0012D9D8(void);
// MATCH func_0012E608
float pchsysw_0012e608(void) { S_0012E608 *s = func_0012D9D8(); if (s == 0) return 0.0f; return s->v; }

typedef struct { char pad[52]; float v; } S_0012E630;
void *func_0012D9D8(void);
// MATCH func_0012E630
float pchsysw_0012e630(void) { S_0012E630 *s = func_0012D9D8(); if (s == 0) return 0.0f; return s->v; }

void func_0012E658(int, void *);
typedef struct { char pad[12]; int a; } S_0012F4D0;
// MATCH func_0012F4D0
float pchsysw_0012f4d0(S_0012F4D0 *s) { float v[4]; func_0012E658(s->a, v); return v[0]; }

typedef struct { float x, y, z; char pad[4]; int p; char p2[44]; } It_0012F708;
typedef struct { int n; It_0012F708 *a; } S_0012F708;
// MATCH func_0012F708
void pchsysw_0012f708(S_0012F708 *s, int i, float x, float y, float z) { if (i >= s->n) return; if (s->a[i].p == 0) return; s->a[i].x = x; s->a[i].y = y; s->a[i].z = z; }

typedef struct { char c[16]; } V16_0012E500;
typedef struct { char p[0]; V16_0012E500 v; } N_0012E500;
N_0012E500 *func_0012D9D8_0012E500(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E500
int pchsysw_0012e500(int a, int b, V16_0012E500 *d) { N_0012E500 *n = func_0012D9D8_0012E500(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { char c[16]; } V16_0012E558;
typedef struct { char p[16]; V16_0012E558 v; } N_0012E558;
N_0012E558 *func_0012D9D8_0012E558(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E558
int pchsysw_0012e558(int a, int b, V16_0012E558 *d) { N_0012E558 *n = func_0012D9D8_0012E558(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { char c[16]; } V16_0012E5B0;
typedef struct { char p[32]; V16_0012E5B0 v; } N_0012E5B0;
N_0012E5B0 *func_0012D9D8_0012E5B0(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E5B0
int pchsysw_0012e5b0(int a, int b, V16_0012E5B0 *d) { N_0012E5B0 *n = func_0012D9D8_0012E5B0(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { int a, b, c, d; } O_0012EF68;
void func_0012DF68(int, int);
// MATCH func_0012EF68
void pchsysw_0012ef68(O_0012EF68 *o, int x) { func_0012DF68(o->a, x); func_0012DF68(o->b, x); func_0012DF68(o->c, x); func_0012DF68(o->d, x); }

typedef struct { int a, b, c, d; } O_0012F440;
void func_0012E2A8(int, float);
// MATCH func_0012F440
void pchsysw_0012f440(O_0012F440 *o, float f) { func_0012E2A8(o->a, f); func_0012E2A8(o->b, f); func_0012E2A8(o->c, f); func_0012E2A8(o->d, f); }

typedef struct { int a, b, c, d; } O_0012F3D0;
void func_0012E228(int, int, float);
// MATCH func_0012F3D0
void pchsysw_0012f3d0(O_0012F3D0 *o, int x, float f) { func_0012E228(o->a, x, f); func_0012E228(o->b, x, f); func_0012E228(o->c, x, f); func_0012E228(o->d, x, f); }

typedef struct { int a, p; } O_0012F650;
void func_00131588(void *); void func_00108B80_0012F650(void *) __asm__("func_00108B80");
// MATCH func_0012F650
void pchsysw_0012f650(O_0012F650 *o, int f) { if (o->p != 0) func_00131588(o->p); if (f & 1) func_00108B80_0012F650(o); }

typedef struct N_0012D9D8 { char p[60]; struct N_0012D9D8 *next; } N_0012D9D8;
typedef struct { int n; int b; N_0012D9D8 *h; } O_0012D9D8;
// MATCH func_0012D9D8
N_0012D9D8 *pchsysw_0012d9d8(O_0012D9D8 *o, int a) { N_0012D9D8 *p; if (a < 0 || a >= o->n) return 0; p = o->h; if (a > 0) { do { p = p->next; } while (--a != 0); } return p; }

void func_0012F2D8(); void func_0012F2E0(int, int, char *); void func_0012F2E8(int, int, char *); void func_0012F2F0(int, int, float);
// MATCH func_0012F270
void pchsysw_0012f270(int a, int b, char *c) { func_0012F2D8(); func_0012F2E0(a, b, c + 16); func_0012F2E8(a, b, c + 32); func_0012F2F0(a, b, *(float *)(c + 208)); }

typedef struct N_0012D980 { char p[60]; struct N_0012D980 *nx; } N_0012D980;
typedef struct { char p[8]; N_0012D980 *h; int c; } O_0012D980;
void func_00108B80_0012D980(N_0012D980 *) __asm__("func_00108B80");
// MATCH func_0012D980
void pchsysw_0012d980(O_0012D980 *o) { N_0012D980 *n = o->h; if (n) { do { N_0012D980 *t = n->nx; func_00108B80_0012D980(n); n = t; } while (n); } o->c = 0; o->h = 0; }

typedef struct { int w0; } Q_0012F1C0;
float func_0012E608(int, int);
// MATCH func_0012F1C0
float pchsysw_0012f1c0(Q_0012F1C0 *q, int n) { float s = 0.0f; int i = 0; if (n > 0) do { s += func_0012E608(q->w0, i); i++; } while (i < n); return s; }

typedef struct { int w0, w4, w8, w12; } Q_0012F348;
void func_0012E198(int, int, float);
// MATCH func_0012F348
void pchsysw_0012f348(Q_0012F348 *q, int a, float x) { if (a != 0) { func_0012E198(q->w0, a, x); func_0012E198(q->w4, a, x); func_0012E198(q->w8, a, x); func_0012E198(q->w12, a, x); } }

typedef struct { int n; char *p; } O_0012F5D8;
extern char D_00431D70[]; char *func_00162130_0012F5D8(int, char *, int) __asm__("func_00162130");
// MATCH func_0012F5D8
O_0012F5D8 *pchsysw_0012f5d8(O_0012F5D8 *o, int n) { char *p; int i; o->n = n; o->p = p = func_00162130_0012F5D8(n << 6, D_00431D70, 1053); if (n > 0) { i = n; do { *(int *)(p + 16) = 0; *(int *)(p + 56) = 0; p += 64; i--; } while (i != 0); } return o; }

void *func_0012D9D8_0012E228(void *) __asm__("func_0012D9D8"); void func_0012DA28(void *, void *);
// MATCH func_0012E228
void pchsysw_0012e228(void *t, float v) { int *o = (int *)func_0012D9D8_0012E228(t); if (o) { ((float *)o)[13] = v; func_0012DA28(t, o); func_0012DA28(t, (void *)o[14]); func_0012DA28(t, (void *)o[15]); } }

extern char D_00431D70_0012ED48[] __asm__("D_00431D70"); void *func_00162130_0012ED48(int, char *, int) __asm__("func_00162130"); void *func_0012D8D8(void *);
// MATCH func_0012ED48
void pchsysw_0012ed48(int *o) { o[0] = (int)func_0012D8D8(func_00162130_0012ED48(20, D_00431D70_0012ED48, 768)); o[1] = (int)func_0012D8D8(func_00162130_0012ED48(20, D_00431D70_0012ED48, 769)); o[2] = (int)func_0012D8D8(func_00162130_0012ED48(20, D_00431D70_0012ED48, 770)); o[3] = (int)func_0012D8D8(func_00162130_0012ED48(20, D_00431D70_0012ED48, 771)); }

extern char D_00431D70_0012EC30[] __asm__("D_00431D70"), D_004322C8[]; void *func_00162130_0012EC30(int, char *, int) __asm__("func_00162130"); void *func_0012D8D8(void *);
// MATCH func_0012EC30
int *pchsysw_0012ec30(int *o) { o[0] = 0; o[1] = 0; o[2] = 0; o[4] = (int)D_004322C8; o[0] = (int)func_0012D8D8(func_00162130_0012EC30(20, D_00431D70_0012EC30, 755)); o[1] = (int)func_0012D8D8(func_00162130_0012EC30(20, D_00431D70_0012EC30, 756)); o[2] = (int)func_0012D8D8(func_00162130_0012EC30(20, D_00431D70_0012EC30, 757)); o[3] = (int)func_0012D8D8(func_00162130_0012EC30(20, D_00431D70_0012EC30, 758)); return o; }

void *func_0012D9D8_0012E198(void *) __asm__("func_0012D9D8"); void func_0012DA28(void *, void *);
// MATCH func_0012E198
void pchsysw_0012e198(float *t, float v) { float *o = (float *)func_0012D9D8_0012E198(t); if (o) { t[1] = t[1] + (v - o[12]); o[12] = v; func_0012DA28(t, o); func_0012DA28(t, (void *)((int *)o)[14]); func_0012DA28(t, (void *)((int *)o)[15]); } }

typedef struct { char c[16]; } V16_0012E100;
void *func_0012D9D8_0012E100(void *) __asm__("func_0012D9D8"); void func_0012DA28(void *, void *);
// MATCH func_0012E100
void pchsysw_0012e100(void *t, int x, char *src) { int *o = (int *)func_0012D9D8_0012E100(t); if (o) { *(V16_0012E100 *)o = *(V16_0012E100 *)src; func_0012DA28(t, o); func_0012DA28(t, (void *)o[14]); func_0012DA28(t, (void *)o[15]); } }

void func_0012DDA0(int, int, void *, float, float);
// MATCH func_0012EEC0
void pchsysw_0012eec0(int *o, int a, float *p, float x, float y) { float t[4]; t[0] = p[52]; func_0012DDA0(o[0], a, p, x, y); func_0012DDA0(o[1], a, p + 4, x, y); func_0012DDA0(o[2], a, p + 8, x, y); func_0012DDA0(o[3], a, t, x, y); }

void func_0012DC70(int, void *, float, float);
// MATCH func_0012EE30
void pchsysw_0012ee30(int *o, float *p, float x, float y) { float t[4]; t[0] = p[52]; func_0012DC70(o[0], p, x, y); func_0012DC70(o[1], p + 4, x, y); func_0012DC70(o[2], p + 8, x, y); func_0012DC70(o[3], t, x, y); }

void func_0012E500(int, int, float *); void func_0018EB78_0012EFC0(float *, float *) __asm__("func_0018EB78"); void func_00153C38(float *, float *); void func_00153D40(float *, float *);
// MATCH func_0012EFC0
int pchsysw_0012efc0(int *o, float *dst, int p) { float buf[16]; func_0012E500(o[0], p, buf); func_0012E500(o[1], p, buf + 4); func_0012E500(o[2], p, buf + 8); func_0012E500(o[3], p, buf + 12); func_0018EB78_0012EFC0(dst, buf); dst[3] = 1.0f; func_00153C38(dst, buf + 4); func_00153D40(dst, buf + 8); dst[52] = buf[12]; return 1; }

int func_0012E658_0012F090(int, float *, float) __asm__("func_0012E658"); void func_0018EB78_0012F090(float *, float *) __asm__("func_0018EB78"); void func_00153C38(float *, float *); void func_00153D40(float *, float *);
// MATCH func_0012F090
int pchsysw_0012f090(int *o, float *dst, float x) { float buf[16]; int n; n = func_0012E658_0012F090(o[0], buf, x); n += func_0012E658_0012F090(o[1], buf + 4, x); n += func_0012E658_0012F090(o[2], buf + 8, x); n += func_0012E658_0012F090(o[3], buf + 12, x); if (n < 4) return 0; func_0018EB78_0012F090(dst, buf); dst[3] = 1.0f; func_00153C38(dst, buf + 4); func_00153D40(dst, buf + 8); dst[52] = buf[12]; return 1; }

void func_0012E500(int, int, float *); void func_0012E100(int, int, float *);
// MATCH func_0012F2F0
void pchsysw_0012f2f0(char *o, int a, float f) { float v; func_0012E500(*(int *)(o + 12), a, &v); v = f; func_0012E100(*(int *)(o + 12), a, &v); }

typedef struct { char c[16]; } V16_0012F4F8;
static inline void setw_0012F4F8(float *v) { v[3] = 1.0f; }
void func_0012E658_0012F4F8(int, float *, float) __asm__("func_0012E658"); void func_00153B40_0012F4F8(float *) __asm__("func_00153B40"); void func_0018EB78_0012F4F8(float *, float *) __asm__("func_0018EB78"); void func_00153C38(float *, float *); void func_001541C8(float *, float);
// MATCH func_0012F4F8
void pchsysw_0012f4f8(int *o, V16_0012F4F8 *dst, float x) { float buf[12]; float m[56]; func_0012E658_0012F4F8(o[0], buf, x); func_0012E658_0012F4F8(o[1], buf + 4, x); func_0012E658_0012F4F8(o[3], buf + 8, x); func_00153B40_0012F4F8(m); func_0018EB78_0012F4F8(m, buf); setw_0012F4F8(m); func_00153C38(m, buf + 4); m[52] = buf[8]; func_001541C8(m, 0.0f); *dst = *(V16_0012F4F8 *)m; }

typedef struct N_ N_; struct N_ { char p[48]; float w; int q; N_ *prev; N_ *next; };
typedef struct { int n; float tot; N_ *first; N_ *last; } L__0012DF68;
int func_0012E4F0_12DF68(L__0012DF68 *) __asm__("func_0012E4F0"); N_ *func_0012D9D8_12DF68(L__0012DF68 *, int) __asm__("func_0012D9D8"); void func_0012DA28_12DF68(L__0012DF68 *, N_ *) __asm__("func_0012DA28");
// MATCH func_0012DF68
void pchsysw_0012df68(L__0012DF68 *o, int i) { N_ *n, *p, *q; if (i >= 0 && i < func_0012E4F0_12DF68(o)) { n = func_0012D9D8_12DF68(o, i); p = n->prev; q = n->next; if (p != 0) p->next = q; else o->first = q; if (q != 0) q->prev = p; else o->last = p; if (p == 0) { o->tot -= o->first->w; o->first->w = 0; } else func_0012DA28_12DF68(o, p); if (q != 0) func_0012DA28_12DF68(o, q); o->n--; o->tot -= n->w; } }

typedef struct 
{
  int n;
  char *p;
} H_0012F6A8;
// MATCH func_0012F6A8
void pchsysw_0012f6a8(H_0012F6A8 *o, int idx, float x, float y, float z, int a, int b, int c, int d, int e, int f, int g, int h) { if (idx < o->n) { char *p = ((char *) (idx * 64)) + ((int) o->p); *((float *) (p + 0)) = x; *((float *) (p + 4)) = y; *((float *) (p + 8)) = z; *((int *) (p + 20)) = a; *((int *) (p + 24)) = b; *((int *) (p + 28)) = c; *((int *) (p + 32)) = d; *((int *) (p + 36)) = e; *((int *) (p + 40)) = f; *((int *) (p + 44)) = g; *((int *) (p + 48)) = h; *((int *) (p + 52)) = 0; *((int *) (p + 16)) = 1; } }

typedef struct NV_12E2A8 NV_12E2A8;
struct NV_12E2A8
{
  char p[48];
  float w;
  int q;
  NV_12E2A8 *prev;
  NV_12E2A8 * volatile next;
};
typedef struct 
{
  int n;
  float tot;
  NV_12E2A8 *first;
  NV_12E2A8 *last;
} L__0012E2A8;
int func_0012E4F0_12E2A8(void *) __asm__("func_0012E4F0");
float func_0012E4F8_12E2A8(void *) __asm__("func_0012E4F8");
void func_0012DA28_12E2A8(void *, void *) __asm__("func_0012DA28");
// MATCH func_0012E2A8
void pchsysw_0012e2a8(float v, L__0012E2A8 *o) { NV_12E2A8 *p; NV_12E2A8 *q; float k; float r; float t; if (func_0012E4F0_12E2A8(o) < 2) { return; } if (func_0012E4F0_12E2A8(o) == 2) { o->last->w = v; o->tot = v; } else { k = func_0012E4F8_12E2A8(o); r = v / k; t = 0.0f; p = o->first->next; ; while (p->next != 0) { p->w = p->w * r; t += p->w; p = (q = p->next); }  p->w = v - t; o->tot = v; p = *((NV_12E2A8 * volatile *) (&o->first)); for (; p != 0; p = p->next) { func_0012DA28_12E2A8(o, p); }  } }

typedef struct { char c[16]; } B16_0012E040;
typedef struct { B16_0012E040 v; char pad[32]; float f48; float f52; int w56; int w60; } P_12e040_0012E040;
void *func_0012D9D8_12E040(int) __asm__("func_0012D9D8"); void func_0012DA28_12E040(int, void *) __asm__("func_0012DA28");
// MATCH func_0012E040
void pchsysw_0012e040(int a0, int b, B16_0012E040 *v, float x, float y) { P_12e040_0012E040 *p = func_0012D9D8_12E040(a0); if (p != 0) { p->v = *v; p->f48 = x; p->f52 = y; func_0012DA28_12E040(a0, p); func_0012DA28_12E040(a0, (void *)p->w56); func_0012DA28_12E040(a0, (void *)p->w60); } }
