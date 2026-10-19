/* yokota.cpp: small functions, matched by hand. */
#include "common.h"

extern int D_004A13AC, D_004A14D0, D_004A5580, D_004A717C, D_004A71D8;
extern char D_005F7560[];
extern char D_0045CE30[];
extern int D_0603D140[4], D_0603D144[4], D_0603D148[4];
extern int D_004A1478, D_004A149C, D_004A146C;
extern int D_002F9800[];
int DbgPrintf(char *, ...);
void FUN_0024a138(void);
int FUN_0024a190(void);
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

extern void (*D_004A1360)(void);
extern void (*D_004A1364)(void);
extern int D_004A12A4, D_004A71AC, D_004A1448;
extern long D_004A1300, D_004A12F0, D_004A12E8;
extern char D_0045C9C0[];
extern char D_00343028[];
void FUN_00110490(void);
void yokota_0023ccf0(void);
void FUN_0024a3b8(void);
void init_0024a510(void);
void yokota_0023efb8(void);
void init_0024ad58(int, int, int, int);
void *MemAllocDbg(int, char *, int);
void FUN_001976b8(void);
void FUN_0010e368(char *);
void FUN_002a1988(void);
void FUN_0010a458(char *, int, int, int);
extern char D_0045CE40[], D_0045CE50[], D_0045CE60[], D_00320980[], D_0603D040[], D_004A5518[], D_004A5520[];
extern int D_004A140C;
char *strcpy(char *, const char *);
void FUN_00245db8(char *, char *, void *);
int yokota_0023f108(int);

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

// MATCH func_0023EFB8
void yokota_0023efb8(void)
{
    FUN_0024a138();
    D_002F9800[1] = FUN_0024a190();
    D_002F9800[2] = FUN_0024a190();
    D_002F9800[3] = FUN_0024a190();
}

// MATCH func_0023F090
void yokota_0023f090(int a, int b, int c, int d)
{
    DbgPrintf(D_0045CE30);
    D_0603D140[0] = a;
    D_0603D144[0] = b;
    D_0603D148[0] = c;
    D_004A1478 = d;
    D_004A146C = 1;
    D_004A149C = 1;
}

// MATCH func_0023CC28
void yokota_0023cc28(void)
{
    D_004A1360 = FUN_00110490;
    D_004A1364 = yokota_0023ccf0;
    D_004A12A4 = 0x13;
    FUN_0024a3b8();
    init_0024a510();
    yokota_0023efb8();
    init_0024ad58(0, 0x40, 0x80, 0x80);
    D_004A1448 = 0;
    D_004A1300 = 0;
    D_004A12F0 = 0;
    D_004A12E8 = 0;
    D_004A71AC = (int)MemAllocDbg(0x200000, D_0045C9C0, 964);
    FUN_001976b8();
    FUN_0010e368(D_00343028);
    FUN_002a1988();
    FUN_0010a458(D_00343028, 0, 100, 100);
    FUN_0010a458(D_00343028, 1, 100, 100);
}

// MATCH func_0023F108
int yokota_0023f108(int flags)
{
  if (flags == 0) return 0;
  if ((flags & 2) != 0) {
    DbgPrintf(D_0045CE40, D_00320980);
    strcpy(D_0603D040, D_00320980);
    return 0;
  }
  if ((flags & 8) != 0) {
    DbgPrintf(D_004A5518);
    FUN_00245db8(D_0045CE50, D_004A5520, yokota_0023f108);
    return 0;
  }
  if ((D_004A140C & 8) != 0)
    yokota_0023f090(100, 100, (int)D_0045CE60, (int)yokota_0023f108);
  return 0;
}
