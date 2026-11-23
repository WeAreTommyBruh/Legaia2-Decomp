// compiler: 990721-r5900
#include "../common.h"

typedef struct { char c[16]; } V16;
typedef struct { char p0[0x20]; float x, y, z; char p2c[0x18]; float f44; char p48[0x38]; float f80, f84, f88; char p8c[0x20]; short id; } Act;
typedef struct { char p[0x12d0]; unsigned flags; char p12d4[0x10]; int state; char p12e8[0x1cc]; float f14b4; char p14b8[0xa0]; float f1558, f155c; } Slot;
typedef struct { char p[0x20]; int f20; char p24[0x7c]; } T160;
extern Act *D_003279A0[];
extern Slot *D_004A1A20;
extern V16 D_0055AB80;
extern int D_004A6C98, D_004A6D94, D_004A6D9C, D_004A6E44, D_004A6CC0, D_004A6C9C;
extern const float D_0049FDDC;
extern float D_004A6C60, D_0049FDE0, D_0049FDE4, D_0049FDE8;
extern int D_003244F0[];
extern T160 D_003246D0[];
extern char D_00430CB8[], D_00430CE0[], D_00430D00[], D_00430D10[];
extern int func_00127F70(void);
extern int func_001227B8(void);
extern int func_00129E78(void);
extern int func_001118F8(char *, ...);
extern void func_0024D048(int, float);
extern int func_0012C448(int);
extern void func_00123118(int, int);
extern int func_00129E10(void);
extern int func_00127FC8(int);
extern float func_00219FB8(int, int);
extern void func_0012A6E0(float);
extern void func_0011DBB0(float, int);
extern void func_0021B088(float, float, Slot *);
extern void func_001296B0(void);
extern void func_0024D8C0(float, float, int, int, int);
extern int func_002DC978(void);
extern float func_0012D108(float);
extern int func_0024DA70(void);
// MATCH func_001243A0
void battle_001243a0(int a, int b)
{
    int c, i;
    Act *p, **pp;
    float fx, fz, f, w, h, save;

    if (func_00127F70() == 0 && func_001227B8() == 0 && (func_00129E78() != 0 || D_004A1A20[a].state == 4)) {
        func_001118F8(D_00430CB8);
        func_0024D048(a, 1.0f);
        D_0055AB80 = *(V16 *)&D_003279A0[b]->f80;
        c = func_0012C448(a) ? a : b;
        fx = D_003279A0[c]->f80;
        fz = D_003279A0[c]->f88;
        pp = D_003279A0;
        for (i = 0; i < 10; i++, pp++) {
            if (*pp) {
                (*pp)->x -= fx;
                (*pp)->z -= fz;
                (*pp)->f80 -= fx;
                (*pp)->f88 -= fz;
            }
        }
        if (D_004A6C98 != 0)
            func_00123118(b, a);
        else
            func_00123118(a, b);
        if (func_00129E10() != 0 && func_00127FC8(a) == 0) {
            f = func_00219FB8(a, b);
            D_003279A0[a]->f44 = f;
            D_003279A0[b]->f44 = f + D_0049FDDC;
        }
        if (D_004A6C98 != 0)
            func_00123118(b, a);
        else
            func_00123118(a, b);
        func_001118F8(D_00430CE0);
        D_004A6C60 = D_003279A0[a]->f44 + D_0049FDE0;
        func_0012A6E0(D_004A6C60);
        fx = 0.0f;
        fz = 2560.0f;
        if (D_004A1A20[a].state == 4 && D_003279A0[a]->id == 1)
            fz = -10240.0f;
        for (i = 0; i < 10; i++) {
            p = D_003279A0[i];
            if (p) {
                p->x -= fx;
                p->z -= fz;
                p->f80 -= fx;
                p->f88 -= fz;
            }
        }
        if ((unsigned)(D_004A1A20[a].state - 1) >= 2)
            D_004A1A20[b].flags |= 0x400000;
        else
            func_0011DBB0(1.0f, 0);
        if (D_004A1A20[a].state == 4) {
            w = D_004A1A20[b].f1558;
            h = D_004A1A20[b].f155c;
            save = D_003279A0[b]->f44;
            func_0021B088(w * 3.0f, h * 3.0f, &D_004A1A20[b]);
            func_0024D048(a, 1.0f);
            func_0021B088(w, h, &D_004A1A20[b]);
            func_001118F8(D_00430D00, (double)D_004A1A20[b].f1558);
            w = D_004A1A20[a].f1558;
            h = D_004A1A20[a].f155c;
            func_0021B088(w + w, h * 6.0f, &D_004A1A20[a]);
            func_0024D048(a, 1.0f);
            func_0021B088(w, h, &D_004A1A20[a]);
            w = D_004A1A20[b].f1558;
            h = D_004A1A20[b].f155c;
            if (D_003279A0[b]->id == 272)
                func_0021B088(1.0f, 1.0f, &D_004A1A20[b]);
            else
                func_0021B088(w + w, h * 8.0f, &D_004A1A20[b]);
            func_0024D048(b, 1.0f);
            func_0021B088(w, h, &D_004A1A20[b]);
            D_003279A0[b]->f44 = save;
            func_001296B0();
        }
        if (D_004A1A20[b].flags & 0x400000)
            func_0024D8C0(1.0f, 1.0f, 0, D_004A6D94, D_004A6D9C);
        func_001118F8(D_00430D10, D_003244F0[11], D_003244F0[10]);
        func_0011DBB0(1.0f, 1);
        func_0012A6E0(-D_004A6C60);
        D_004A1A20[b].flags &= ~0x400000;
        D_004A6E44 = 0;
        if (func_0012C448(a) != 0) {
            D_004A6C60 = D_003279A0[a]->f44 + (float)(int)((func_002DC978() & 0xffffff) - 0x800000) * 1.1920929e-07f * D_0049FDE4;
            func_0012A6E0(D_004A6C60);
            D_004A6E44 = 1;
        } else {
            D_004A6C60 = D_003279A0[a]->f44 + (float)(int)((func_002DC978() & 0xffffff) - 0x800000) * 1.1920929e-07f * D_0049FDE8;
            if (D_003246D0[D_004A6CC0].f20 != 0) {
                D_004A6E44 = 1;
                func_0012A6E0(D_004A6C60);
            } else {
                D_004A6C60 = func_0012D108(D_003279A0[a]->f44);
                func_0012A6E0(D_004A6C60);
            }
        }
        func_0024DA70();
        D_004A6C9C = 1;
        D_004A1A20[a].f14b4 = D_003279A0[a]->f44;
    }
}
