// compiler: 990721-r5900
#include "../common.h"
typedef struct { char pad[4816]; int flags; char pad2[368]; char *q; char pad3[280]; } E;
extern E *D_004A1A20;
extern struct { int pad[10]; int a; int b; } D_003244F0;
extern char *D_003279A0[];
extern char D_0045E168[], D_0045E178[], D_0045E190[];
int func_00127F70(void);
int func_0024E0C8(int, int);
void func_001118F8(char *, ...);
void func_0018F098(void *, void *);
void func_0018F080(void *, void *, void *);
void func_0018F020(void *, void *, void *);
void func_0021DAC8(float, void *);
// MATCH func_0024DD98
void FUN_0024dd98(void)
{
    float v[4];
    char buf[16] __attribute__((aligned(16)));
    float maxx, minx, maxz, minz, t;
    int i, n, ok, ea, eb;
    unsigned fl;

    if (func_00127F70() != 0) return;
    n = 0;
    func_001118F8(D_0045E168);
    ea = D_003244F0.a;
    eb = D_003244F0.b;
    v[0] = 0.0f;
    v[3] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    minz = maxz = minx = maxx = v[0];
    for (i = 0; i < 10; i++) {
        if (func_0024E0C8(i, 0) == 0 || i == eb || i == ea) continue;
        fl = D_004A1A20[i].flags;
        ok = 0;
        if (fl & 0x40000000) ok = 1;
        if ((fl & 0x20000000) && *(int *)(D_004A1A20[i].q + 56) != 0) ok = 1;
        if (!ok) continue;
        n++;
        t = *(float *)(D_003279A0[i] + 0x80);
        if (maxx < t) maxx = t;
        if (t < minx) minx = t;
        t = *(float *)(D_003279A0[i] + 0x88);
        if (maxz < t) maxz = t;
        if (t < minz) minz = t;
    }
    if (n == 0) return;
    func_001118F8(D_0045E178, minx, maxx);
    func_001118F8(D_0045E190, minz, maxz);
    v[1] = 0.0f;
    v[0] = (maxx + minx) * 0.5f;
    v[2] = (maxz + minz) * 0.5f;
    for (i = 0; i < 10; i++) {
        if ((D_004A1A20[i].flags & 0x60000000) && i != eb && i != ea) {
            func_0018F098(D_003279A0[i] + 0x80, v);
            func_0018F098(D_003279A0[i] + 0x20, v);
        }
    }
    for (i = 0; i < 10; i++) {
        char *p = D_003279A0[i];
        if (p != 0 && i != eb && i != ea) {
            func_0018F080(buf, p + 0x20, p + 0x80);
            func_0021DAC8(20480.0f, D_003279A0[i] + 0x20);
            func_0018F020(D_003279A0[i] + 0x20, D_003279A0[i] + 0x80, buf);
        }
    }
}
