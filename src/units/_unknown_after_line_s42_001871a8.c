#include "../common.h"
typedef struct { char p0[16]; long *q; } Pk;
extern Pk D_00342CD0;
extern int D_0058B270[];
extern void (*D_004A349C)(long);
void func_00190328(Pk *); void func_00190420(Pk *);
void func_00231958(int);
// MATCH func_001871A8
void FUN_001871a8(long a)
{
    long *q;
    func_00190328(&D_00342CD0);
    q = D_00342CD0.q;
    q[0] = 0x51001;
    q[1] = 0x47;
    q[2] = 0x80000000a9L;
    q[3] = 0x42;
    q[4] = 0x46;
    q[5] = 0;
    q[6] = 0x3f80000000000000L;
    q[7] = 1;
    q[8] = 0xffffff79006c00L;
    q[9] = 12;
    q[10] = 0xffffff87009400L;
    q[11] = 4;
    q[12] = 0x3f800000ff000000L;
    q[13] = 1;
    q[14] = (long)(D_0058B270[0] + 0x6c00) | (long)(D_0058B270[1] + 0x7900) << 16 | 0xffffff00000000L;
    q[15] = 12;
    q[16] = (long)(D_0058B270[2] + 0x6c00) | (long)(D_0058B270[3] + 0x7900) << 16 | 0xffffff00000000L;
    q[17] = 4;
    q[18] = 0x44;
    q[19] = 0x42;
    q[20] = 0x5000d;
    q[21] = 0x47;
    D_00342CD0.q = q + 22;
    func_00190420(&D_00342CD0);
    func_00231958(1);
    if (D_004A349C != 0) D_004A349C(a);
    func_00231958(0);
}
