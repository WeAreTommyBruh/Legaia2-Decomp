/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int a, b, c; } O_001809F8;
// MATCH func_001809F8
int FUN_001809f8(O_001809F8 *o) { if (o->a < o->b) return 0; return !(o->c < o->a); }

int func_0018B508(int, void *);
void func_00180068(void *);
// MATCH func_00180810
void FUN_00180810(char *o) {
    int a, b, c;
    char buf[16];
    if (*(int *)(o + 20)) a = func_0018B508(*(int *)(o + 20), buf); else a = 0;
    if (*(int *)(o + 28)) b = func_0018B508(*(int *)(o + 28), buf); else b = 0;
    if (*(int *)(o + 24)) c = func_0018B508(*(int *)(o + 24), buf); else c = 0;
    *(int *)(o + 56) = a;
    *(int *)(o + 64) = b;
    *(int *)(o + 60) = c;
    func_00180068(o);
}

// cflags: -fexceptions
int FUN_001809d0(void);
// MATCH func_00180A70
int FUN_00180a70(int param_1)  { int uVar1; int lVar2; float fVar3; float fVar4;  lVar2 = FUN_001809d0(); if (lVar2 == 0) { uVar1 = 0; } else { fVar3 = *(float *)(param_1 + 0x10) + *(float *)(param_1 + 0x20); *(float *)(param_1 + 0x10) = fVar3; if (fVar3 < *(float *)(param_1 + 0x18)) { *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x18); } if (*(float *)(param_1 + 0x10) > *(float *)(param_1 + 0x1c)) { *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x1c); } fVar4 = *(volatile float *)(param_1 + 0x20) + *(float *)(param_1 + 0x30); *(float *)(param_1 + 0x20) = fVar4; if (fVar4 < *(float *)(param_1 + 0x28)) { *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x28); } if (*(float *)(param_1 + 0x20) > *(float *)(param_1 + 0x2c)) { *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x2c); } uVar1 = 1; } return uVar1; }

