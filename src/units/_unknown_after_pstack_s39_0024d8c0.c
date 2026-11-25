// compiler: 990721-r5900
#include "../common.h"
extern int D_003279A0[];
extern char D_0045E150[];

int func_00127F70(void);
int func_00127430(void);
int func_0024E0C8(int, int);
void func_001118F8(char *, ...);
float func_0021AF68(int);
float func_0024D6C0(int, float);
void func_0024D810(int, float);
extern char *D_004A1A3C;
extern int D_004A1A20;
// MATCH func_0024D8C0
void FUN_0024d8c0(int p0, float x, float s, int a, int b)
{
    float fa, fb, m, f, v;
    int i, n;

    if (func_00127F70() != 0) return;
    if (D_003279A0[a] == 0) return;
    if (func_00127430() != 0 && *(int *)(D_004A1A3C + 1248) != 0) return;
    func_001118F8(D_0045E150, a, b);
    fb = func_0021AF68(D_004A1A20 + b * 5472);
    fa = func_0021AF68(D_004A1A20 + a * 5472);
    v = (fb < fa ? fa : fb) * 4608.0f * s;
    m = v;
    n = 0;
    i = 0;
    do {
        if (i != a && i != b && func_0024E0C8(i, 1) != 0) {
            f = func_0024D6C0(i, v);
            if (f != 0.0f) n++;
            if (m < f) m = f;
        }
        i++;
    } while (i < 10);
    i = 0;
    if (n != 0) {
        do {
            if (i != a && i != b && func_0024E0C8(i, 1) != 0)
                func_0024D810(i, m);
            i++;
        } while (i < 10);
    }
}
