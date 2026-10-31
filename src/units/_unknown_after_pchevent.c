/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int *D_004A4670; extern char D_004555D8[]; void func_002119E0(void *, void *);
// MATCH func_00211A20
int FUN_00211a20(void) { func_002119E0(&D_004A4670, D_004555D8); if ((unsigned)(int)(D_004A4670) < 2) return 0; return *D_004A4670; }

extern int *D_004A4674; extern char D_004555F8[]; void func_002119E0(void *, void *);
// MATCH func_00211AC8
int FUN_00211ac8(void) { func_002119E0(&D_004A4674, D_004555F8); if ((unsigned)(int)(D_004A4674) < 2) return 0; return *D_004A4674; }

typedef struct { char p[8]; int n; int *q; } O_00211C68;
// MATCH func_00211C68
int FUN_00211c68(O_00211C68 *o, int a) { if (a < 0 || o->n < a) return 0; return o->q[a]; }

extern char *D_004A4670_00211A58 __asm__("D_004A4670"); extern int D_004A4A2C; extern char D_004555D8_00211A58[] __asm__("D_004555D8"); void func_002119E0_00211A58(char **, char *) __asm__("func_002119E0"); int func_00211A20(void);
// MATCH func_00211A58
int FUN_00211a58(int i) { func_002119E0_00211A58(&D_004A4670_00211A58, D_004555D8_00211A58); if ((unsigned)D_004A4670_00211A58 < 2) return D_004A4A2C; if (i >= func_00211A20()) return D_004A4A2C; return (int)(D_004A4670_00211A58 + ((int *)D_004A4670_00211A58)[i + 1]); }

extern char *D_004A4674_00211B00 __asm__("D_004A4674"); extern int D_004A4A30; extern char D_004555F8_00211B00[] __asm__("D_004555F8"); void func_002119E0_00211B00(char **, char *) __asm__("func_002119E0"); int func_00211AC8(void);
// MATCH func_00211B00
int FUN_00211b00(int i) { func_002119E0_00211B00(&D_004A4674_00211B00, D_004555F8_00211B00); if ((unsigned)D_004A4674_00211B00 < 2) return D_004A4A30; if (i >= func_00211AC8()) return D_004A4A30; return (int)(D_004A4674_00211B00 + ((int *)D_004A4674_00211B00)[i + 1]); }
