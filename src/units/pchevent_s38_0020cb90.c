// cflags: -fno-gcse
extern int D_004A4678, D_004A467C, D_004A1444, D_004A1430, D_004A1434; extern int D_003208B8[]; extern char D_004A48E8[], D_004A48C0[];
extern float D_0041EFB0[]; extern char D_00425FB0[];
int func_001301E0(int, int); int func_00130150(int, int); void func_00130188(int, int, void *); void func_00239568(char *, int, int, int, int); void func_0018EB78(void *, void *); void func_002A8FB0(void *, void *);
// MATCH func_0020CB90
void pchevent_0020cb90(int a)
{
    char buf[16];
    int c, t;
    if (D_004A4678 != 0 && func_001301E0(D_004A4678, D_004A467C) != 0) {
        c = 0xa0a0a0;
        if (a != 0) { if (D_004A1444 == 0) c = 0xc0c0; }
    } else {
        c = 0x505050;
        if (a != 0) { if (D_004A1444 == 0) c = 0x40c0; }
    }
    if (D_004A4678 == 0 || func_00130150(D_004A4678, D_004A467C) == 0) {
        func_00239568(D_004A48E8, D_004A1430 + 6, D_004A1434, c, D_004A467C);
    } else {
        func_00239568(D_004A48C0, D_004A1430 + 6, D_004A1434, c, func_00130150(D_004A4678, D_004A467C));
    }
    if (a != 0 && *(volatile int *)&D_004A1444 == 0 && (D_003208B8[0] & 4) && D_004A4678 != 0 && func_001301E0(D_004A4678, D_004A467C) != 0) {
        func_00130188(D_004A4678, D_004A467C, buf);
        func_0018EB78(D_0041EFB0, buf);
        D_0041EFB0[3] = 1.0f;
        func_002A8FB0(D_00425FB0, D_0041EFB0);
    }
}
