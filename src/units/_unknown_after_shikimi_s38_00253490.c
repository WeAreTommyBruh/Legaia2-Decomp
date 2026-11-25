#include "../common.h"
extern unsigned char D_003FDFA0[];
typedef struct { char p[64]; unsigned char a, b; char q[6]; } E72;
#define LIM(b) (((E72 *)D_003FDFA0)[b].a - ((E72 *)D_003FDFA0)[b].b)
int func_00252018(int, int);
int func_002510F0(int);
int func_00250EB0(int);
int func_00250EF0(int);
int func_00250F20(int);
int func_00250F50(int);
int func_00250F80(int);
int func_002530C8(int, int);
int func_00253160(int, int);
int func_002531F8(int, int);
int func_00253290(int, int);
int func_00253328(int, int);
int func_002533E8(int, int);
void func_002523D8(int);
// MATCH func_00253490
int FUN_00253490(int a, int b)
{
    int n;
    if (func_00252018(b, a) == 0) return -1;
    switch (func_002510F0(a)) {
    case 0:
        n = func_00250EB0(a);
        n -= func_00250EF0(b);
        if (n <= LIM(b)) func_002530C8(a, b);
        break;
    case 1:
        n = func_00250EB0(a);
        n -= func_00250F20(b);
        if (n <= LIM(b)) func_00253160(a, b);
        break;
    case 2:
        n = func_00250EB0(a);
        n -= func_00250F50(b);
        if (n <= LIM(b)) func_002531F8(a, b);
        break;
    case 3:
        n = func_00250EB0(a);
        n -= func_00250F80(b);
        if (n <= LIM(b)) func_00253290(a, b);
        break;
    case 4:
        if (func_00250EB0(a) <= LIM(b)) func_00253328(a, b);
        break;
    case 14:
        if (func_00250EB0(a) <= LIM(b)) func_002533E8(a, b);
        break;
    }
    func_002523D8(b);
    return 0;
}
