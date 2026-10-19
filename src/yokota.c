/* yokota.cpp: small functions, matched by hand. */
#include "common.h"

extern int D_004A13AC, D_004A14D0, D_004A5580, D_004A717C, D_004A71D8;
extern char D_005F7560[];
typedef struct { char pad[56]; int a; int b; int c; } Obj;
extern Obj D_005F7500;
typedef struct { char pad[148]; int f; } Thing;

Thing *FUN_002415e8(void);
void FUN_002492e8(char *);
void FUN_002306e8(void);
void FUN_0022f208(void);
void FUN_002467f8(int, void (*)(void));
void work_00246800(int);
void object_00242f40(void *);

// MATCH func_0023CFF0
void yokota_0023cff0(void)
{
    D_005F7500.b = D_004A13AC;
    D_005F7500.a = 0;
    D_005F7500.c = 0;
    object_00242f40(&D_005F7500);
}

// MATCH func_0023D010
void yokota_0023d010(int x)
{
    Thing *p = FUN_002415e8();
    p->f = x;
}

// MATCH func_0023DE18
void yokota_0023de18(int x)
{
    D_004A5580 = x;
    if (x != 0)
        FUN_002492e8(D_005F7560);
}

// MATCH func_0023E7A0
void yokota_0023e7a0(int a, int b)
{
    D_004A71D8 = b;
    if (b != 0)
        FUN_002467f8(a, FUN_0022f208);
    else
        work_00246800(a);
}

// MATCH func_0023EE78
void yokota_0023ee78(void)
{
    D_004A14D0++;
}

// MATCH func_0023F070
int yokota_0023f070(int a, int b)
{
    if (D_004A717C != b) {
        FUN_002306e8();
        return;
    }
    return 1;
}
