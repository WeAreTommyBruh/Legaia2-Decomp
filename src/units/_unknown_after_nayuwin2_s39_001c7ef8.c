// compiler: 990721-r5900
#include "../common.h"
extern char D_00449CF8[], D_00449D18[], D_00449D40[], D_00449D60[], D_00449D80[], D_00449DA0[], D_00449DB0[];
extern char D_004A3C5C;
extern short D_005B6140[][1800];
int func_00254790(void); void func_001118F8(char *, ...); char *func_001AD458(int);
void func_001C8C78(char *, int); int func_002E9950(char *, int); void func_002EA200(int, void *, int); void func_002E9BD8(int);
void func_001C7B60(int);
// MATCH func_001C7EF8
void FUN_001c7ef8(void)
{
    char *w;
    int i, j;
    int *p;
    int fd;
    if (func_00254790() < 900) return;
    func_001118F8(D_00449CF8);
    w = func_001AD458(1800);
    func_001118F8(D_00449D18);
    i = 0;
    do {
        int t = i << 8;
        i++;
        *(char *)(t + *(int *)(w + 0x168) + 0xfd) = 0x66;
    } while (i < 1800);
    D_004A3C5C = 0;
    i = 0;
    do {
        func_001118F8(D_00449D40, i);
        func_001C8C78(w, i);
        j = 0;
        p = (int *)(*(int *)(w + 0x168) + 0x28);
        do {
            if (*p > 0)
                D_005B6140[i][*p] = j;
            j++;
            p += 0x40;
        } while (j < 1800);
        i++;
    } while (i < 10);
    func_001118F8(D_00449D60);
    fd = func_002E9950(D_00449D80, 0x602);
    if (fd >= 0) {
        func_002EA200(fd, D_005B6140, 36000);
        func_002E9BD8(fd);
        func_001118F8(D_00449DA0);
    } else {
        func_001118F8(D_00449DB0);
    }
    func_001C7B60(-1);
}
