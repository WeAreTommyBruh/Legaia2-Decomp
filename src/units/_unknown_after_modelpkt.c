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
