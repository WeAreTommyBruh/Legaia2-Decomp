/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_0034366C[];
void func_001297A0(int, int, int, int, int, int);
// MATCH func_0012D038
void FUN_0012d038(void) { if (D_0034366C[0] != 0) func_001297A0(0, 2, 0, 1, 0, 0); else func_001297A0(0, 2, 0, 0, 0, 0); }

extern char D_0053F980[], D_0053FD30[];
void func_00181128(void *, int);
void func_002A39F8(void *, int);
// MATCH func_0012D2E0
void FUN_0012d2e0(void) { func_00181128(D_0053F980, 2); func_002A39F8(D_0053FD30, 2); }

extern int D_004A6E38; extern int *D_003279A0[]; extern float D_0055B3A0[3];
typedef struct { char pad[112]; float x, y, z; } O_0012D078;
// MATCH func_0012D078
void FUN_0012d078(void) { if (D_004A6E38 >= 0) { O_0012D078 *o = ((O_0012D078 **)D_003279A0)[D_004A6E38]; o->x = D_0055B3A0[0]; o->y = D_0055B3A0[1]; o->z = D_0055B3A0[2]; } }

typedef struct N_0012D4F0 { char p[24]; struct N_0012D4F0 *next; } N_0012D4F0;
typedef struct { int n; int b; N_0012D4F0 *h; } O_0012D4F0;
// MATCH func_0012D4F0
N_0012D4F0 *FUN_0012d4f0(O_0012D4F0 *o, int a) { N_0012D4F0 *p; if (a < 0 || a >= o->n) return 0; p = o->h; if (a > 0) { do { p = p->next; } while (--a != 0); } return p; }

typedef struct N_0012D498 { char p[24]; struct N_0012D498 *nx; } N_0012D498;
typedef struct { char p[8]; N_0012D498 *h; int c; } O_0012D498;
void func_00108B80_0012D498(N_0012D498 *) __asm__("func_00108B80");
// MATCH func_0012D498
void FUN_0012d498(O_0012D498 *o) { N_0012D498 *n = o->h; if (n) { do { N_0012D498 *t = n->nx; func_00108B80_0012D498(n); n = t; } while (n); } o->c = 0; o->h = 0; }

extern int *D_004A1A94; extern int D_004A1AA0, D_004A6E30; extern char D_00431C18[]; int func_00127430(void); void func_00127F30(int, int, int, int, int, int); void func_001118F8_0012CF98(char *, int, int) __asm__("func_001118F8");
// MATCH func_0012CF98
int FUN_0012cf98(int a) { int t = func_00127430() ? 10 : 28; func_00127F30(0, a, 0xffffff, t, 5, 15); D_004A1A94[83] = 1; D_004A1AA0 = t; D_004A6E30 = 1; func_001118F8_0012CF98(D_00431C18, a, t); }

extern char D_0053FDA0[], D_00431C80[], D_0053FD30_0012D310[] __asm__("D_0053FD30"), D_0053FD00_0012D310[] __asm__("D_0053FD00"), D_0053F980_0012D310[] __asm__("D_0053F980"), D_0053F900[]; void func_002A39D0(char *); void func_0015ACE0(char *); void func_00180C58_0012D310(char *) __asm__("func_00180C58"); void func_002A4F30_0012D310(char *) __asm__("func_002A4F30");
// MATCH func_0012D310
void FUN_0012d310(void) { int i; char *p = D_0053FDA0; for (i = 3; i != -1; i--) { *(int *)(p + 52) = (int)D_00431C80; p += 64; } func_002A39D0(D_0053FD30_0012D310); func_0015ACE0(D_0053FD00_0012D310); func_00180C58_0012D310(D_0053F980_0012D310); func_002A4F30_0012D310(D_0053F900); }
