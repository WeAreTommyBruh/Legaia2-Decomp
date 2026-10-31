/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern long long D_004A12D8; extern int D_004A3070;
// MATCH func_0016F7F0
int FUN_0016f7f0(void) { if (D_004A12D8 & 0x8000) { D_004A3070 = 0; return 1; } if (D_004A12D8 & 0x2000) { D_004A3070 = 1; return 1; } return 0; }

typedef struct { char pad[20]; int a, b; char p2[16]; int c, d; } O_0016F898;
extern long long D_004A12D8;
// MATCH func_0016F898
int FUN_0016f898(O_0016F898 *o) { if (D_004A12D8 & 0x8000) { o->a = 213; o->b = 112; return 1; } if (D_004A12D8 & 0x2000) { o->c = 0; o->d = 0; return 1; } return 0; }

typedef struct { char pad[20]; int a, b; char p2[16]; int c, d; } O_0016F8E0;
extern long long D_004A12D8;
// MATCH func_0016F8E0
int FUN_0016f8e0(O_0016F8E0 *o) { if (D_004A12D8 & 0x8000) { o->c = 0; o->d = 0; return 1; } if (D_004A12D8 & 0x2000) { o->a = 213; o->b = 112; return 1; } return 0; }

typedef struct { char p[64]; int col; char p2[12]; unsigned fl; } O_0016F828;
extern long long D_004A12D8_0016F828 __asm__("D_004A12D8");
// MATCH func_0016F828
int FUN_0016f828(O_0016F828 *o) { int r; if (o->fl & 0x10) o->col = 0x808080; else o->col = 0xffffff; r = 1; if ((D_004A12D8_0016F828 & 0xa000) == 0) r = 0; return r; }

typedef struct { char p[64]; int col; char p2[12]; unsigned fl; } O_0016F860;
extern long long D_004A12D8_0016F860 __asm__("D_004A12D8");
// MATCH func_0016F860
int FUN_0016f860(O_0016F860 *o) { int r; if (o->fl & 0x10) o->col = 0xffffff; else o->col = 0x808080; r = 1; if ((D_004A12D8_0016F860 & 0xa000) == 0) r = 0; return r; }

typedef struct { char c[8]; } V8_0016F928;
extern V8_0016F928 D_004A3078[3]; extern char D_0043D580[]; extern char D_0043D598[];
int func_001644A0_0016F928(char *) __asm__("func_001644A0"); void func_002971C0(int, int); int func_0018B3A8(char *, int); void func_001118F8_0016F928(char *) __asm__("func_001118F8");
// MATCH func_0016F928
char *FUN_0016f928(char *o) { *(int *)(o + 0) = 0; *(int *)(o + 4) = 0; *(int *)(o + 60) = 0; *(int *)(o + 64) = 0; *(int *)(o + 72) = 0; *(int *)(o + 76) = 0; *(int *)(o + 88) = 0; *(int *)(o + 92) = 0; *(int *)(o + 96) = 0; *(int *)(o + 100) = 0; *(int *)(o + 80) = 12; *(int *)(o + 84) = 640; func_001644A0_0016F928(o + 104); *(int *)(o + 112) = 24;
*(int *)(o + 120) = 116;
*(int *)(o + 124) = 1;
*(int *)(o + 116) = 0; *(V8_0016F928 *)(o + 136) = D_004A3078[0]; func_002971C0(0, 0); *(int *)(o + 132) = 0; *(int *)(o + 128) = func_0018B3A8(D_0043D580, 0); if (*(int *)(o + 128) == 0) func_001118F8_0016F928(D_0043D598); return o; }
