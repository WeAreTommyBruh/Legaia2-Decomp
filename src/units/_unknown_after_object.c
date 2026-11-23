/* Functions of this report unit, matched by hand. */
#include "../common.h"
#include "../ghidra.h"

extern char D_003D7058[]; void func_002454A8(void *, void *, void *);
// MATCH func_00245578
void FUN_00245578(void *a, void *b) { func_002454A8(D_003D7058, a, b); }

typedef struct { char pad[8]; int a8; char pad1[132]; int a144; char pad2[192]; int a340; char pad3[50]; char b394; char pad4[17]; int a412; } S_245e10_00245E10;
extern int D_004A7204;
void func_002461E0(void *);
// MATCH func_00245E10
S_245e10_00245E10 *FUN_00245e10(S_245e10_00245E10 *s) { int n = D_004A7204; s->a144 = 0; n++; s->a412 = 0; s->a8 = 0; s->a340 = 0; D_004A7204 = n; func_002461E0(s); s->b394 = 0; return s; }

extern char D_0045D448[]; extern int D_004A1478, D_004A1498; int func_001118F8_00245DB8(char *) __asm__("func_001118F8"); void func_00245578(int, int);
// MATCH func_00245DB8
void FUN_00245db8(int a, int b, int c) { func_001118F8_00245DB8(D_0045D448); D_004A1478 = c; D_004A1498 = 1; func_00245578(a, b); }

extern char D_003D7058_00245590[] __asm__("D_003D7058"), D_005F75B8[]; extern void (*D_004A1478_00245590)(int) __asm__("D_004A1478"); int func_00245518(char *, char *);
// MATCH func_00245590
int FUN_00245590(void) { int r = func_00245518(D_003D7058_00245590, D_005F75B8); if (r == 1) D_004A1478_00245590(4); if (r == 2) D_004A1478_00245590(2); return r; }

void func_002478D0(int);
void func_002478B8(int);
void func_00247970(int);
void func_00247A70(int,int,int);
void func_00247C98(float,float,float);
void func_002479F0(void);

// MATCH func_00244880
void FUN_00244880(float *p,float *q,int r,int g,int b)
{
    func_002478D0(8);
    func_002478B8(16);
    func_00247970(4);
    func_00247A70(r, g, b);
    func_00247C98(p[0]-128.0f, p[1], p[2]-128.0f);
    func_00247C98(p[0]+128.0f, p[1], p[2]-128.0f);
    func_00247A70(r, g, 0);
    func_00247C98(q[0], q[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70(r, g, b);
    func_00247C98(p[0]-128.0f, p[1], p[2]+128.0f);
    func_00247C98(p[0]+128.0f, p[1], p[2]+128.0f);
    func_00247A70(r, g, 0);
    func_00247C98(q[0], q[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70(r, g, b);
    func_00247C98(p[0]-128.0f, p[1], p[2]-128.0f);
    func_00247C98(p[0]-128.0f, p[1], p[2]+128.0f);
    func_00247A70(r, g, 0);
    func_00247C98(q[0], q[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70(r, g, b);
    func_00247C98(p[0]+128.0f, p[1], p[2]-128.0f);
    func_00247C98(p[0]+128.0f, p[1], p[2]+128.0f);
    func_00247A70(r, g, 0);
    func_00247C98(q[0], q[1], q[2]);
    func_002479F0();
}

#define FABS_245108(x) __builtin_fabsf(x)
// MATCH func_00245108
void FUN_00245108(float *p) {
  float m = 0;
  if (m < FABS_245108(p[6])) m = p[6];
  if (m < FABS_245108(p[8])) m = p[8];
  if (m < FABS_245108(p[10])) m = p[10];
  if (m < FABS_245108(p[7])) m = p[7];
  if (m < FABS_245108(p[9])) m = p[9];
  if (m < FABS_245108(p[11])) m = p[11];
  p[6] = -m; p[7] = m; p[8] = -m; p[9] = m; p[10] = -m; p[11] = m;
}

extern char D_0045D2A8[]; void func_001118F8(char *, ...);
typedef struct { char p[16]; int *s; char p2[140]; } S_245078;
// MATCH func_00245078
int FUN_00245078(char *base, int *tab) {
  int n = tab[0], i; S_245078 *sb = (S_245078 *)(base + 16);
  i = 0;
  if (n > 0) { do {
    short *e = (short *)(tab + tab[i + 1]);
    int *t = sb[((signed char *)e)[6]].s;
    if (t == 0) { func_001118F8(D_0045D2A8, i); return 0; }
    if (t[e[2] + 1] == 0) t[e[2] + 1] = (int)e;
    i++;
  } while (i < n); }
}

extern int D_004A71F0, D_004A71EC, D_004A7200, D_004A71F8, D_004A14A0, D_004A71E8, D_004A71F4;
extern char D_003D6EE0[];
int func_0023A350(void *);
// MATCH func_00245518
int FUN_00245518(int p, int b)
{
int t = *(int *)(p + 0x3110); D_004A71F4 = p; D_004A71F8 = 0; D_004A14A0 = 0; D_004A71E8 = b; D_004A71EC = p + 0x3000; D_004A7200 = t; D_004A71F0 = p + 0x3100;
  func_0023A350(D_003D6EE0);
  if (D_004A71F8 == 0) D_004A14A0 = 1;
  return D_004A71F8;
}
