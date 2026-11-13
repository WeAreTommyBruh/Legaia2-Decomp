/* Functions of this report unit, matched by hand. */
#include "../common.h"

void func_0029FE00(void *, int, int, float, float, float);
// MATCH func_00218470
void FUN_00218470(void *a, float *v, int c, int d) { func_0029FE00(a, c, d, v[0], v[1], v[2]); }

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_002184B0;
void func_0029D010_002184B0(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_002184B0
void FUN_002184b0(S_002184B0 *s, float *v) { func_0029D010_002184B0(s->a, 0, 0, v[0]); func_0029D010_002184B0(s->b, 0, 0, v[1]); func_0029D010_002184B0(s->c, 0, 0, v[2]); }

typedef struct { char p0[184]; int w184; char p1[28]; void *w216; char p2[60]; float f280, f284; } O_00217FF8;
extern char D_003C30C0[]; O_00217FF8 *func_00246D88(char *);
// MATCH func_00217FF8
O_00217FF8 *FUN_00217ff8(int a, int b, float *v, int n, float f) { O_00217FF8 *p = func_00246D88(D_003C30C0); if (p) { p->f280 = *v; p->f284 = f; p->w184 = n; p->w216 = v; } return p; }

typedef struct { char p0[184]; int w184; char p1[28]; void *w216; char p2[60]; float f280, f284; } O_002180E0;
extern char D_003C30D0[]; O_002180E0 *func_00246D88_002180E0(char *) __asm__("func_00246D88");
// MATCH func_002180E0
O_002180E0 *FUN_002180e0(int a, int b, int *v, int n, float f) { O_002180E0 *p = func_00246D88_002180E0(D_003C30D0); if (p) { p->w216 = v; p->f280 = (float)*v; p->f284 = f; p->w184 = n; } return p; }

typedef struct { char p0[184]; int w184; char p1[28]; void *w216; char p2[60]; float f280, f284; } O_002181D0;
extern char D_003C30E0[]; O_002181D0 *func_00246D88_002181D0(char *) __asm__("func_00246D88");
// MATCH func_002181D0
O_002181D0 *FUN_002181d0(int a, int b, unsigned char *v, int n, float f) { O_002181D0 *p = func_00246D88_002181D0(D_003C30E0); if (p) { p->w216 = v; p->f280 = (float)*v; p->f284 = f; p->w184 = n; } return p; }

typedef struct { char p0[184]; int w184; char p1[28]; void *w216; char p2[60]; float f280, f284; char p3[108]; int w396; } O_002182F0;
extern char D_003C30F0[]; O_002182F0 *func_00246D88_002182F0(char *) __asm__("func_00246D88"); int func_00228310(int, int);
// MATCH func_002182F0
O_002182F0 *FUN_002182f0(int a, int b, int c, float f, int n) { O_002182F0 *p = func_00246D88_002182F0(D_003C30F0); if (p) {
p->w216 = (void *)a;
p->w396 = c;
p->f280 = (float)func_00228310(a, c);
p->f284 = f;
p->w184 = n; } return p; }

// MATCH func_00218140
void FUN_00218140(int *o) { float *f = (float *)o; if (o[46] == 0) { *(char *)o[54] = (int)(f[71] + 0.5f); o[6] |= 8; return; } { float n = (float)o[46]; float cur = f[70]; f[70] = cur + (f[71] - cur) / n; *(char *)o[54] = (int)(f[70] + 0.5f); o[46]--; } }

// MATCH func_00218058
void FUN_00218058(int *o) { float *f = (float *)o; if (o[46] == 0) { *(int *)o[54] = (int)(f[71] + 0.5f); o[6] |= 8; return; } { float n = (float)o[46]; float cur = f[70]; f[70] = cur + (f[71] - cur) / n; *(int *)o[54] = (int)(f[70] + 0.5f); o[46]--; } }

// MATCH func_00217F98
void FUN_00217f98(int *o) { float *f = (float *)o; float *t; if (o[46] == 0) { t = (float *)o[54]; *t = f[71]; o[6] |= 8; return; } { float cur = f[70]; float n = (float)o[46]; float d = f[71] - cur; o[46] = o[46] - 1; t = (float *)o[54]; f[70] = cur + d / n; *t = f[70]; } }

typedef struct { char p[152]; void *w152; char q[32]; short w188; } B__00217DE0;
void *func_00217F48(void *, void *, int); int func_00212F18(void *); char *func_00213258(void *, int, int); char *func_002DDAE8(char *, char *);
// MATCH func_00217DE0
int FUN_00217de0(void *a, B__00217DE0 *b)
{
    void *h = b->w152;
    int cnt, i;
    char *t, *r;
    if (h == 0) return 0;
    t = func_00217F48(a, b, 0);
    cnt = 0;
    i = 0;
    while (i < func_00212F18(h)) {
        r = func_00213258(h, i++, 0);
        if (func_002DDAE8(r, t) == r) cnt++;
    }
    return cnt;
}

typedef struct { char p[152]; void *w152; char q[32]; short w188; } B__00217E90;
void *func_00217F48(void *, void *, int); int func_00212F18(void *); char *func_00213258(void *, int, int); char *func_002DDAE8(char *, char *);
// MATCH func_00217E90
void FUN_00217e90(void *a, B__00217E90 *b, int off)
{
    void *h = b->w152;
    int i;
    char *t, *r;
    if (h != 0) {
        t = func_00217F48(a, b, 0);
        for (i = 0; i < func_00212F18(h); i++) {
            r = func_00213258(h, i, 0);
            if (func_002DDAE8(r, t) == r) break;
        }
        if (i < func_00212F18(h))
            b->w188 = i + off;
    }
}

typedef struct N__002175E0 { int f0; struct N__002175E0 *next; int f8, fc, f10; float *f14; } N__002175E0;
typedef struct { char p[2156]; N__002175E0 *head; } H__002175E0;
// MATCH func_002175E0
N__002175E0 *FUN_002175e0(H__002175E0 *o, int a, int b, int c) { N__002175E0 *p = o->head; while (p != 0) { if (p->f8 == a && p->f10 >= 0 && p->fc == b && (int)*p->f14 == c) break; p = p->next; } return p; }

extern int D_00318C20_217F48[] __asm__("D_00318C20");
// MATCH func_00217F48
int FUN_00217f48(int param_1, int param_2, int param_3) { int b = D_00318C20_217F48[*(unsigned short *)(*(int *)(param_2 + 0x90) + 0x908)]; int c = b + 0x10; if (param_3 < (int)*(unsigned char *)(b + 3)) { return param_3 * 0xa0 + c + 0x60; } return 0; }

