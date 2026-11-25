// compiler: 990721-r5900
#include "../common.h"
typedef struct { signed char a, b, c, d; int state; int timer; } S_343650;
extern S_343650 D_00343650;
extern int D_004A3C30, D_004A3C38, D_004A3C3C;
void func_00110080(int); void func_0029B5C0(void *, int);
// MATCH func_001B4738
int FUN_001b4738(signed char a, signed char b, int t, int mode)
{
    char buf[16];
    if (mode == 1) return D_00343650.state;
    if (D_00343650.timer < 1) {
        if (a < 0) return -1;
        if (t > 0) {
            if (D_00343650.state == 4) return -1;
            if (b == 1) {
                if (D_00343650.state == 2 && D_00343650.b < 0) {
                    func_00110080(5);
                    D_00343650.timer = 20;
                    D_004A3C30 = 0;
                    D_00343650.b = a;
                    D_00343650.state = 6;
                    if (D_00343650.a == 9 && (a == 1 || a == 14 || a == 10))
                        func_0029B5C0(buf, 10);
                } else {
                    if (D_00343650.state != 0 && D_00343650.state != 5) return -1;
                    func_00110080(5);
                    D_00343650.a = a;
                    D_00343650.timer = t;
                    D_00343650.state = 1;
                    D_004A3C30 = 0;
                    D_004A3C38 = 0;
                    D_004A3C3C = 0;
                    return 1;
                }
            }
            if (b == 2) {
                if (D_00343650.state != 2) return -1;
                D_00343650.a = a;
                D_00343650.timer = t;
                if (D_00343650.c < 0) D_00343650.state = 3;
                else D_00343650.state = 6;
                return 1;
            }
            if (b != 0) return -1;
            D_00343650.state = 0;
        }
    }
    return -1;
}
