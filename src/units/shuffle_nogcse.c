/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_0043E188[]; void func_002971C0(int, int); void func_001621F8(int, char *, int); void func_00164500(char *, int); void func_001775C0(char *, int); void func_00108B80(char *);
// MATCH func_00177B00
void shuffle_00177b00(char *o, int flag) { char *p; func_002971C0(18, 50); func_001621F8(*(int *)(o + 464), D_0043E188, 219); func_00164500(o + 456, 2); if (o != 0) { p = o + 384; if (o != p) { do { p -= 96; func_001775C0(p, 0); } while (o != p); } } if (flag & 1) func_00108B80(o); }

typedef struct { char c[8]; } V8_001783A0;
extern unsigned long D_004A12D8, D_004A12E0;
extern V8_001783A0 D_004A3368[3];
extern char D_00343028_001783A0[] __asm__("D_00343028");
int func_0010C2B0(void *, int, int, int, int, int, int);
// MATCH func_001783A0
int shuffle_001783a0(char *o) {
    int v, w;
    if ((D_004A12D8 | D_004A12E0) & 0x48000) {
        func_0010C2B0(D_00343028_001783A0, 0, 2, 0, 0, 0, 0);
        v = *(int *)(o + 408) - 1;
        *(int *)(o + 408) = v;
        if (v < 0) *(int *)(o + 408) = 3;
    }
    if ((D_004A12D8 | D_004A12E0) & 0x82000) {
        func_0010C2B0(D_00343028_001783A0, 0, 2, 0, 0, 0, 0);
        v = *(int *)(o + 408) + 1;
        *(int *)(o + 408) = v;
        if (v > 3) *(int *)(o + 408) = 0;
    }
    w = *(int *)(o + 448) - 1;
    *(int *)(o + 448) = w;
    if (w == 0 || (D_004A12D8 & 0x200040)) {
        func_0010C2B0(D_00343028_001783A0, 162, 12, 0, 0, 0, 0);
        *(int *)(o + 416) = 0;
        *(V8_001783A0 *)(o + 476) = D_004A3368[0];
    }
    return 0;
}
