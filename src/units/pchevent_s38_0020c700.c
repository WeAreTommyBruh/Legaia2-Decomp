// cflags: -fno-gcse
extern int D_004A1444, D_004A1430, D_004A1434, D_004A140C, D_004A4624, D_004A462C, D_004A4638; extern float D_004A4630; extern char D_004A48C0[], D_0041EFB0[]; extern char D_003C23A0[];
void func_0012F090(int, char *, float); void func_00239568(char *, int, int, int, char *);
// MATCH func_0020C700
int pchevent_0020c700(int a)
{
    if (a != 0 && D_004A1444 == 0 && D_004A4624 != 0) {
        if (D_004A140C & 8) {
            int v = D_004A462C;
            D_004A4638 = 0;
            if (v == 0) D_004A4630 = 0;
            D_004A462C = v != 1 ? 1 : 4;
        } else if (D_004A140C & 4) {
            D_004A4630 = 0;
            D_004A462C = 0;
            func_0012F090(D_004A4624, D_0041EFB0, D_004A4630);
        }
    }
    { int c = 0x808010; if (a != 0) c = 0xffff; func_00239568(D_004A48C0, D_004A1430 + 6, D_004A1434, c, D_003C23A0 + D_004A462C * 8); }
    return 0;
}
