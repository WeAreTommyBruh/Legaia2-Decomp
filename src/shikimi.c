/* Functions of shikimi.cpp, matched by hand (the others of the group are
   Ghidra's code in src/ghidra/shikimi.c and src/gen/shikimi.c). */
#include "common.h"

/* the 32 64-byte records at D_00620920 */
typedef struct {
    char pad[52];
    int f34; /* 0 when the record is free */
    char pad2[8];
} Rec;
extern Rec D_00620920[32];
extern char D_0049ACD0[], D_0041EF40[], D_004A6A18[], D_0049B998[];
extern int D_004A7298;
extern struct {
    char p0[488];
    int a1, a2;
    char p1[608 - 496];
    char b0[1096 - 608];
    int c1, c2;
} D_005F9640;
int FUN_0018d800(void);
int DbgPrintf(char *, ...);
long FUN_00160c70();
void shikimi_002b3f10();
void shikimi_002b8ee8();
void shikimi_002b1d88();

/* the object that shikimi_002b8ee8 is given on the stack */
typedef struct {
    char pad[8];
    int f8, fc, f10, f14, f18, f1c;
} Obj8ee8;

// MATCH func_002B8EB0
void shikimi_002b8eb0(int a, int b, int c)
{
    Obj8ee8 o;
    o.fc = a;
    o.f8 = 0;
    o.f14 = c;
    o.f10 = c;
    o.f1c = 0;
    o.f18 = 0;
    shikimi_002b8ee8(&o);
}

// MATCH func_002B8E70
void shikimi_002b8e70(int a)
{
    Obj8ee8 o;
    o.f8 = 2;
    o.f14 = a;
    o.f10 = a;
    o.f1c = 0;
    o.f18 = 0;
    shikimi_002b8ee8(&o, D_0049ACD0);
}

/* the objects that shikimi_002b1d88 is given on the stack */
typedef struct {
    int f0, f4, f8, fc, f10, f14, f18, f1c;
    float f20;
} Obj1cc8;
typedef struct {
    int f0, f4, f8, fc, f10, f14;
    float f18;
    int f1c, f20;
} Obj1d08;
typedef struct {
    int f0, f4, f8;
    float fc, f10, f14, f18, f1c, f20;
} Obj1d48;

// MATCH func_002B1CC8
void shikimi_002b1cc8(int a0, int a1, float x)
{
    Obj1cc8 o;
    o.f4 = a1;
    o.f8 = 120;
    o.f20 = x;
    o.fc = 0;
    o.f10 = 0;
    o.f14 = 0;
    o.f18 = 0;
    o.f1c = 0;
    shikimi_002b1d88(a0, &o);
}

// MATCH func_002B1D08
void shikimi_002b1d08(int a0, int a1, int a2, float x)
{
    Obj1d08 o;
    o.f4 = a1;
    o.f8 = a2;
    o.f18 = x;
    o.fc = 0;
    o.f10 = 0;
    o.f14 = 0;
    o.f1c = 0;
    o.f20 = 0;
    shikimi_002b1d88(a0, &o);
}

// MATCH func_002B1D48
void shikimi_002b1d48(int a0, int a1, int a2, float x0, float x1, float x2, float x3, float x4, float x5)
{
    Obj1d48 o;
    o.f4 = a1;
    o.f8 = a2;
    o.fc = x0;
    o.f10 = x1;
    o.f14 = x2;
    o.f18 = x3;
    o.f1c = x4;
    o.f20 = x5;
    shikimi_002b1d88(a0, &o);
}

/* the last free record of D_00620920, or 0 */
// MATCH func_002B2650
Rec *shikimi_002b2650(void)
{
    int i;
    for (i = 31; i >= 0; i--)
        if (D_00620920[i].f34 == 0)
            return &D_00620920[i];
    return 0;
}

/* prints the time since the last call */
// MATCH func_002B0D80
void shikimi_002b0d80(void)
{
    char *s = D_0049B998;
    int t = FUN_0018d800();
    DbgPrintf(s, t - D_004A7298);
    D_004A7298 = FUN_0018d800();
}

// MATCH func_002B1010
void shikimi_002b1010(void)
{
    long r = FUN_00160c70(D_0041EF40, D_004A6A18, D_005F9640.a1);
    shikimi_002b3f10(r, &D_005F9640, &D_005F9640.a2);
}

// MATCH func_002B1058
void shikimi_002b1058(void)
{
    long r = FUN_00160c70(D_0041EF40, D_004A6A18, D_005F9640.c1);
    shikimi_002b3f10(r, D_005F9640.b0, &D_005F9640.c2);
}
