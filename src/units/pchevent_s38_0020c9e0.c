extern int D_004A4614, D_004A4618, D_004A4658, D_004A1444, D_004A1430, D_004A1434; extern char D_004A48C0[], D_004A48D8[];
int func_00160C70(int, char *, int); void func_00239568(char *, int, int, int, int);
// MATCH func_0020C9E0
int pchevent_0020c9e0(int a)
{
    int c;
    if (D_004A4614 > 0 && D_004A4618 >= 0) {
        c = 0xa0a0a0;
        if (a != 0 && D_004A1444 == 0) c = 0xc0c0;
        func_00239568(D_004A48C0, D_004A1430 + 6, D_004A1434, c, func_00160C70(D_004A4658, D_004A48D8, D_004A4618));
    }
    return 0;
}
