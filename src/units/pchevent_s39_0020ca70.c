typedef struct { float x, y, z, w; } V4f;
extern int D_004A1444, D_004A1430, D_004A1434, D_004A140C, D_004A461C; extern char D_004A48C0[], D_004A47D8[], D_004A48E0[];
extern V4f D_003C0F20, D_0041EFB0;
void func_00239568(char *, int, int, int, char *);
// MATCH func_0020CA70
int pchevent_0020ca70(int a)
{
    int c = 0xa0a0a0;
    if (a != 0 && D_004A1444 == 0) c = 0xc0c0;
    func_00239568(D_004A48C0, D_004A1430 + 24, D_004A1434, c, D_004A461C == 0 ? D_004A47D8 : D_004A48E0);
    if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) {
        if (D_004A461C == 0) {
            V4f *s = &D_0041EFB0; D_003C0F20 = *s;
        } else {
            D_003C0F20.x = 0;
            D_003C0F20.y = 0;
            D_003C0F20.z = 4096.0f;
        }
    }
    return 0;
}
