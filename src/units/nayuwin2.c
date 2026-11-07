/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[36]; int a[4]; } O_001AF0C0;
// MATCH func_001AF0C0
int nayuwin2_001af0c0(O_001AF0C0 *o, unsigned i) { if (i < 4) return o->a[i]; return 0; }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF0F8;
// MATCH func_001AF0F8
int nayuwin2_001af0f8(O_001AF0F8 *o, int a, int b) { if (a < 0 || o->n < a) return 0; { char *r = o->q; r += a * 256; r += b * 4; return *(int *)(r + 40); } }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF7B8;
// MATCH func_001AF7B8
void nayuwin2_001af7b8(O_001AF7B8 *o, int a, int v, int b) { if (a < 0 || o->n < a) return; { char *r = o->q; r += a * 256; r += b * 4; *(int *)(r + 40) = v; } }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF7F0;
// MATCH func_001AF7F0
void nayuwin2_001af7f0(O_001AF7F0 *o, int a, int v) { if (a < 0 || o->n < a) return; { char *r = o->q + a * 256; *(int *)(r + 32) = v; } }

typedef struct { int a0; char pad[356]; int a360; } S_001AD790;
extern char D_00444670[];
void func_00133528(int, void *, int); void func_00131588_001AD790(int) __asm__("func_00131588"); void func_00108B80_001AD790(void *) __asm__("func_00108B80");
// MATCH func_001AD790
void nayuwin2_001ad790(S_001AD790 *s, int fl) { if (s->a0 != 0) func_00133528(s->a0, D_00444670, 968); s->a0 = 0; if (s->a360 != 0) func_00131588_001AD790(s->a360); s->a360 = 0; if (fl & 1) func_00108B80_001AD790(s); }

void func_001AD888(char *, int); void func_001AE4A0(char *);
// MATCH func_001AE398
void nayuwin2_001ae398(char *o) { float *a = (float *)(o + 140), *b = (float *)(o + 184), *c = (float *)(o + 228), *d = (float *)(o + 272), *e = (float *)(o + 316); *(int *)(o + 80) = *(int *)(o + 84); a[10] = -a[10]; b[10] = -b[10]; c[10] = -c[10]; d[10] = -d[10]; e[10] = -e[10]; func_001AD888(o, -1); func_001AE4A0(o); }

extern int D_004A382C_001AD6B0 __asm__("D_004A382C"), D_004A3830;
int func_001AD858(int);
int func_001AD860(int);
void func_001AD8B0(int, int);
void func_001AD8B8(int, int);
void func_001B4B40(int);
void func_001AD790(int, int);
// MATCH func_001AD6B0
int nayuwin2_001ad6b0(int p) {
    int a, b, t;
    if (p == 0) return 0;
    if (p == D_004A382C_001AD6B0) {
        t = func_001AD858(p);
        D_004A382C_001AD6B0 = t;
        if (t != 0) func_001AD8B0(t, 0);
    } else {
        a = func_001AD860(p);
        b = func_001AD858(p);
        func_001AD8B8(a, b);
        if (func_001AD858(p) != 0) {
            a = func_001AD858(p);
            b = func_001AD860(p);
            func_001AD8B0(a, b);
        }
    }
    if (D_004A3830 == p) func_001B4B40(D_004A382C_001AD6B0);
    if (p != 0) func_001AD790(p, 3);
    return 1;
}

extern char D_00444670_001AFE60[] __asm__("D_00444670");
void *func_002DD4CC_001AFE60(void *, void *) __asm__("func_002DD4CC");
int func_002DD5E0_001AFE60(void *) __asm__("func_002DD5E0");
void func_00133528(int, void *, int);
void *func_001334D0_001AFE60(int, void *, int) __asm__("func_001334D0");
// MATCH func_001AFE60
void nayuwin2_001afe60(int *h, char *s, int a, int b) {
    int n;
    char *p;
    if (s == 0) {
        if (h[0] != 0) {
            func_00133528(h[0], D_00444670_001AFE60, 2039);
            h[0] = 0;
        }
        return;
    }
    n = func_002DD5E0_001AFE60(s);
    p = func_001334D0_001AFE60(n + 2, D_00444670_001AFE60, 2045);
    if (p == 0) return;
    func_002DD4CC_001AFE60(p, s);
    h[7] = n;
    if (h[0] != 0) func_00133528(h[0], D_00444670_001AFE60, 2049);
    h[0] = (int)p;
    if (a >= 0) h[5] = a;
    if (b >= 0) h[6] = b;
}

void *func_002DD4CC_001AF938(void *, void *) __asm__("func_002DD4CC");
int func_002DD5E0_001AF938(void *) __asm__("func_002DD5E0");
// MATCH func_001AF938
void nayuwin2_001af938(char *o, char *s, int idx, int mode) {
    char *e, *q, *d;
    int k;
    if (idx >= 0 && idx <= *(int *)(o + 76)) {
        e = (char *)(*(int *)(o + 360) + idx * 256);
        d = e + 72;
        k = 177;
        q = e + 249;
        do { *q = 0; k--; q--; } while (k >= 0);
        if (s == 0) {
            e[255] = 0;
        } else if (*s == 0) {
            e[255] = 0;
        } else {
            func_002DD4CC_001AF938(d, s);
            e[255] = func_002DD5E0_001AF938(s);
            if (mode == 1) {
                *(int *)(o + 92) = 0;
                *(int *)(o + 96) = 0;
            } else if (mode == 2) {
                *(int *)(o + 92) = 0;
                *(int *)(o + 96) = 99;
            }
        }
    }
}

void func_001B7950(float, void *);
// MATCH func_001AF570
void nayuwin2_001af570(char *o, int a, int b, int c, int d, int e, int f) {
    if (a >= 0) func_001B7950((float)a, o + 140);
    if (b >= 0) func_001B7950((float)b, o + 184);
    if (c >= 0) *(int *)(o + 32) = c;
    if (d >= 0) func_001B7950((float)d, o + 228);
    if (e >= 0) func_001B7950((float)e, o + 272);
    if (f >= 0) func_001B7950((float)f, o + 316);
}

extern int D_004A3864_001AD458 __asm__("D_004A3864");
extern char *D_004A382C_001AD458 __asm__("D_004A382C");
extern char D_00444670_001AD458[] __asm__("D_00444670"), D_00448128[];
void *func_00162130(int, void *, int);
void *func_001AD788(void *);
void func_001AD8A0(void *, int);
void *func_001334D0_001AD458(int, void *, int) __asm__("func_001334D0");
void func_001AD790_001AD458(void *, int) __asm__("func_001AD790");
void func_001ADA08(void *, int);
void func_001AD8B0_001AD458(void *, void *) __asm__("func_001AD8B0");
void func_001AD8B8_001AD458(void *, void *) __asm__("func_001AD8B8");
int func_001118F8_001AD458(void *, ...) __asm__("func_001118F8");
// MATCH func_001AD458
char *nayuwin2_001ad458(int n) {
    char *obj;
    char *p;
    if (n < 0) return 0;
    obj = func_001AD788(func_00162130(364, D_00444670_001AD458, 877));
    if (D_004A3864_001AD458 & 0x40) func_001118F8_001AD458(D_00448128, obj);
    if (obj == 0) return 0;
    func_001AD8A0(obj, n);
    p = func_001334D0_001AD458(n << 8, D_00444670_001AD458, 881);
    *(char **)(obj + 360) = p;
    if (p == 0) {
        func_001AD790_001AD458(obj, 3);
        return 0;
    }
    func_001ADA08(obj, 0);
    if (D_004A382C_001AD458 != 0) {
        func_001AD8B0_001AD458(D_004A382C_001AD458, obj);
        func_001AD8B8_001AD458(obj, D_004A382C_001AD458);
    }
    D_004A382C_001AD458 = obj;
    return obj;
}

extern int D_004A3864_001AD548 __asm__("D_004A3864");
extern char *D_004A382C_001AD548 __asm__("D_004A382C");
extern char D_00444670_001AD548[] __asm__("D_00444670"), D_00448128_001AD548[] __asm__("D_00448128");
void *func_00162130(int, void *, int);
void *func_001AD788(void *);
void func_001AD8A0(void *, int);
void *func_001334D0_001AD548(int, void *, int) __asm__("func_001334D0");
void func_001AD790_001AD548(void *, int) __asm__("func_001AD790");
void func_001ADA08_001AD548(void *, void *) __asm__("func_001ADA08");
void func_001AD8B0_001AD548(void *, void *) __asm__("func_001AD8B0");
void func_001AD8B8_001AD548(void *, void *) __asm__("func_001AD8B8");
int func_001AD850(void *);
void func_001AF330(void *, int, void *, int);
int func_001118F8_001AD548(void *, ...) __asm__("func_001118F8");
// MATCH func_001AD548
char *nayuwin2_001ad548(int *a, int *b, int *c) {
    char *obj;
    char *p;
    int i, j, n;
    obj = func_001AD788(func_00162130(364, D_00444670_001AD548, 904));
    if (D_004A3864_001AD548 & 0x40) func_001118F8_001AD548(D_00448128_001AD548, obj);
    if (obj == 0) return 0;
    func_001AD8A0(obj, a[1]);
    n = a[1] << 8;
    *(int *)(obj + 360) = 0;
    p = func_001334D0_001AD548(n, D_00444670_001AD548, 909);
    *(char **)(obj + 360) = p;
    if (p == 0) {
        func_001AD790_001AD548(obj, 3);
        return 0;
    }
    func_001ADA08_001AD548(obj, a);
    *c = 0;
    if (b != 0) {
        i = 0;
        j = 0;
        while (j < func_001AD850(obj)) {
            func_001AF330(obj, j, b, i);
            i++;
            if (i == b[0]) {
                *c = *c + 1;
                b += 58;
                i = 0;
            }
            j++;
        }
    }
    if (D_004A382C_001AD548 != 0) {
        func_001AD8B0_001AD548(D_004A382C_001AD548, obj);
        func_001AD8B8_001AD548(obj, D_004A382C_001AD548);
    }
    D_004A382C_001AD548 = obj;
    return obj;
}

typedef struct { char p[12]; float a; char q[4]; float b; char r[20]; } E__001AF010;
typedef struct { char pad[140]; E__001AF010 e[5]; } O__001AF010;
static inline void chk_001AF010(E__001AF010 *e, int *n) { if (e->a == e->b) (*n)++; }
// MATCH func_001AF010
int nayuwin2_001af010(O__001AF010 *o) { int n = 0; chk_001AF010(&o->e[0], &n); chk_001AF010(&o->e[1], &n); chk_001AF010(&o->e[2], &n); chk_001AF010(&o->e[3], &n); chk_001AF010(&o->e[4], &n); if (n == 5) return 1; if (n == 0) return 0; return -1; }


// MATCH func_001AFB60
int nayuwin2_001afb60(int param_1,int param_2,int param_3,int param_4)  { int iVar1; int iVar2; int iVar3;  iVar3 = 0; if (0 < *(int *)(param_1 + 0x4c)) { iVar2 = *(int *)(param_1 + 0x168); do { iVar1 = iVar3 * (*(int *)(iVar2 + 0x18) + param_4); *(int *)(iVar2 + 8) = iVar1 + param_3; iVar3 = iVar3 + 1; *(int *)(iVar2 + 4) = param_2; iVar2 = iVar2 + 0x100; } while (iVar3 < *(int *)(param_1 + 0x4c)); } return 1; }

