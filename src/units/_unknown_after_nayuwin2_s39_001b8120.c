#include "../common.h"
extern long D_004A12D8;
extern int D_0036CB88[]; extern int D_004A3874;
extern char D_00343028[];
void func_001AE398(int); void func_001AD888(int, int); void func_001B4B40(int);
void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_001B8120
void FUN_001b8120(int *ev)
{
    long f = D_004A12D8;
    if (ev[0] != 0) return;
    if (f & 0x40) {
        int w = D_0036CB88[3];
        *(int *)(*(int *)(w + 0x168) + 0x20) = ev[1] + 1;
        func_001AE398(w);
        func_001AD888(D_0036CB88[3], 20);
        func_001B4B40(D_004A3874);
        func_0010C2B0(D_00343028, 0, 2, 0, 1, 0, 0);
    } else if (f & 0x10) {
        int w = D_0036CB88[3];
        *(int *)(*(int *)(w + 0x168) + 0x20) = 2;
        func_001AE398(w);
        func_001AD888(D_0036CB88[3], 20);
        func_001B4B40(D_004A3874);
        func_0010C2B0(D_00343028, 0, 2, 0, 2, 0, 0);
    }
}
