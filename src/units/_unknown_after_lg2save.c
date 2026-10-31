/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A12A4_001382D0 __asm__("D_004A12A4"), D_004A140C_001382D0 __asm__("D_004A140C"); extern char D_00329C68[], D_00320980[], D_00434A20[], D_004A2308[]; void func_002DD4CC_001382D0(char *, char *) __asm__("func_002DD4CC"); void func_00245DB8(char *, char *, void *); void func_001382D0(void); int FUN_001382d0(int);
// MATCH func_001382D0
int FUN_001382d0(int a) { if (a == 0) return 0; if (a & 2) { func_002DD4CC_001382D0(D_00329C68, D_00320980); D_004A12A4_001382D0 = 20; return 0; } if (D_004A140C_001382D0 & 0x200) func_00245DB8(D_00434A20, D_004A2308, (void *)func_001382D0); return 0; }

typedef struct { char p[52]; int a; char q[32]; int b; char r[32]; int c; char s[128]; } R_00133B28;
extern int D_004A140C_00133B28 __asm__("D_004A140C"); extern char D_004A22D0[]; extern char D_00133B28[]; extern char D_004349B8[]; extern R_00133B28 D_0055BB00[];
int func_0023F090_00133B28(int, int, char *, char *) __asm__("func_0023F090"); int func_002E9950(char *, int); int func_002EA200_00133B28(int, R_00133B28 *, int) __asm__("func_002EA200"); int func_002E9BD8_00133B28(int) __asm__("func_002E9BD8");
// MATCH func_00133B28
int FUN_00133b28(int a) { int h; int i; if (a == 0) return 0; if (D_004A140C_00133B28 & 0x200) func_0023F090_00133B28(96, 80, D_004A22D0, D_00133B28); if (a & 8) { h = func_002E9950(D_004349B8, 1538); for (i = 0; i < 64; i++) { D_0055BB00[i].a = 0; D_0055BB00[i].b = 0; D_0055BB00[i].c = 0; } func_002EA200_00133B28(h, D_0055BB00, 16384); func_002E9BD8_00133B28(h); } }

typedef struct { volatile short s0; volatile short s2; volatile short s4; volatile short s6; volatile int w8; volatile int w12; volatile int w16; volatile int w20; volatile int w24; volatile int w28; volatile int w32; volatile short s36; volatile short s38; } E36_00136650;
extern int D_004A140C_00136650 __asm__("D_004A140C"); extern int D_004A238C; extern int D_004A2390; extern int D_004A6EF0; extern int D_004A6EEC; extern E36_00136650 D_056C48E0[][256][8][32];
// MATCH func_00136650
void FUN_00136650(int a) { E36_00136650 *e; E36_00136650 *new_var; int new_var2; if ((a != 0) && ((D_004A140C_00136650 & 0x200) != 0)) { e = &D_056C48E0[D_004A238C][D_004A2390][D_004A6EF0][D_004A6EEC]; new_var2 = 0; e->s6 = 1; do { e->s38 = 0; e->s0 = new_var2; e->s2 = 0; } while (0); e->s4 = 1; e->w8 = 0; e->w12 = 0; e->w16 = 0; e->w20 = 0; e->w24 = 0; e->w28 = 0; e->w32 = 0; new_var = e; new_var->s36 = 0; } }

typedef struct { volatile short s0, s2, s4, s6, s8, s10, s12, s14, s16; volatile char c18; } E20_001366E8;
extern int D_004A140C_001366E8 __asm__("D_004A140C"); extern int D_004A238C_001366E8 __asm__("D_004A238C"); extern int D_004A2390_001366E8 __asm__("D_004A2390"); extern int D_004A6EE4; extern E20_001366E8 D_056888E0[][256][16];
// MATCH func_001366E8
void FUN_001366e8(int a) { E20_001366E8 *e; if ((a != 0) && ((D_004A140C_001366E8 & 0x200) != 0)) { e = &D_056888E0[D_004A238C_001366E8][D_004A2390_001366E8][D_004A6EE4]; e->c18 = 0; e->s0 = 0; e->s4 = 0; e->s2 = 0; e->s6 = 0; e->s8 = 0; e->s10 = 0; e->s12 = 0; e->s14 = 0; e->s16 = 0; } }

typedef struct { volatile char c0, c1; volatile short s2, s4; volatile char c6, c7; } E8_00136768;
extern int D_004A140C_00136768 __asm__("D_004A140C"); extern int D_004A238C_00136768 __asm__("D_004A238C"); extern int D_004A2390_00136768 __asm__("D_004A2390"); extern int D_004A6EE8; extern E8_00136768 D_056788E0[][256][16];
// MATCH func_00136768
void FUN_00136768(int a) { E8_00136768 *e; if ((a != 0) && ((D_004A140C_00136768 & 0x200) != 0)) { e = &D_056788E0[D_004A238C_00136768][D_004A2390_00136768][D_004A6EE8]; e->c1 = 0; e->c6 = 0; e->c7 = 0; e->s4 = 0; e->s2 = 0; e->c0 = 0; } }
