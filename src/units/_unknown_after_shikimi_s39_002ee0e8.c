// compiler: 990721-r5900
// cflags:
#include "../common.h"
extern int *D_0042AC40[];
extern int D_0042A118[];
void func_002EE098(void *, void *, int);
void func_002EE0D8(int, int);
int func_002DD5E0(char *);
// MATCH func_002EE0E8
char *FUN_002ee0e8(char *path, int argc, char **argv)
{
    int *q = D_0042AC40[0];
    char *ret;
    char *ptr;
    int len;
    int i;
    ptr = (char *)q + 64;
    ret = ptr;
    func_002EE0D8(D_0042A118[0], D_0042A118[1]);
    if (argc > 15)
        argc = 15;
    func_002EE098(q++, &ptr, 4);
    len = func_002DD5E0(path) + 1;
    func_002EE098(ptr, path, len);
    { register char *t __asm__("$3") = ptr + len; ptr = t; }
    for (i = 0; i < argc; i++) {
        func_002EE098(q++, &ptr, 4);
        len = func_002DD5E0(argv[i]) + 1;
        func_002EE098(ptr, argv[i], len);
        { register char *t __asm__("$3") = ptr + len; ptr = t; }
    }
    return ret;
}
