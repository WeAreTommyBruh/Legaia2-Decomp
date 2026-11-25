// compiler: 990721-r5900
extern int D_004A1444, D_004A1430, D_004A1434, D_004A140C, D_004A4678, D_004A467C, D_004A4680; extern char D_00455048[], D_00455058[], D_00455068[];
int func_001301E0(int, int); int func_00130218(int, int, int); void func_0012F740(int, int, int); void func_0012F8E0(int, int, int); void func_00239568(char *, int, int, int);
// MATCH func_0020D008
void pchevent_0020d008(int a)
{
    int c = 0xa0a0a0;
    if (a != 0 && D_004A1444 == 0) c = 0xc0c0;
    if (D_004A4678 == 0 || D_004A467C == D_004A4680 || func_001301E0(D_004A4678, D_004A467C) == 0 || func_001301E0(D_004A4678, D_004A4680) == 0) {
        func_00239568(D_00455048, D_004A1430 + 6, D_004A1434, c);
        return;
    }
    {
        if (func_00130218(D_004A4678, D_004A467C, D_004A4680) == 0)
            func_00239568(D_00455058, D_004A1430 + 6, D_004A1434, c);
        else
            func_00239568(D_00455068, D_004A1430 + 6, D_004A1434, c);
        if (a == 0 || *(volatile int *)&D_004A1444 != 0 || !(D_004A140C & 8)) return;
        {
            if (func_00130218(D_004A4678, D_004A467C, D_004A4680) == 0) {
                func_0012F740(D_004A4678, D_004A467C, D_004A4680);
                return;
            }
            func_0012F8E0(D_004A4678, D_004A467C, D_004A4680);
            return;
        }
    }
}
