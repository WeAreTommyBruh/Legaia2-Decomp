/* yokota.cpp functions that need -fno-gcse. Matched by hand. */
// cflags: -fno-gcse
#include "common.h"

extern u64 D_004A12C8;
extern int D_004A71DC, D_004A129C;
extern char *D_004A1378;
extern char D_0045CEB0[], D_0045CEC0[], D_0045CED8[];
void FUN_002cf018(char *, int, int);
void sceGsSyncPath(int, int);
void FUN_00239568(char *, ...);

// MATCH func_0023FCB0
void yokota_0023fcb0(long which)
{
    int i;
    unsigned idx;
    float *p;
    i = 0;
    FUN_002cf018(D_004A1378, 0, 0x9c4000);
    sceGsSyncPath(0, 0);
    FUN_00239568(D_0045CEB0, 0x32, 0x219);
    D_004A129C = 1;
    do {
        idx = (D_004A71DC + i) & 0x3ff;
        if (which == 0)
            p = (float *)(0x1100c000 + idx * 16);
        else
            p = (float *)(0x11008000 + idx * 16);
        if (((D_004A12C8 & 8) == 0) || ((int)(D_004A12C8 & 1) != 0))
            FUN_00239568(D_0045CEC0, idx, ((int *)p)[0], ((int *)p)[1], ((int *)p)[2], ((int *)p)[3]);
        else
            FUN_00239568(D_0045CED8, idx, (double)p[0], (double)p[1], (double)p[2], (double)p[3]);
        i = i + 1;
    } while (i < 16);
    D_004A129C = 0;
    if ((D_004A12C8 & 0x100) != 0)
        D_004A71DC = D_004A71DC - 1;
    if ((D_004A12C8 & 0x800) != 0)
        D_004A71DC = D_004A71DC + 1;
    D_004A71DC = D_004A71DC & 0x3ff;
}
