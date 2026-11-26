// compiler: 991111-01
// cflags:
typedef struct { char p0[16]; unsigned long *q; } Pk_2436F8;
typedef struct { unsigned char r, g, b, a; } Col_2436F8;
extern Pk_2436F8 D_00314C20;
extern int D_00319660[];
extern int D_004A13E8, D_004A14B0, D_004A71E4;
extern unsigned D_004A13C4;
void func_00190328(Pk_2436F8 *); void func_00190420(Pk_2436F8 *);
static inline unsigned long rgbaq(unsigned long r, unsigned long g, unsigned long b, unsigned long a, unsigned long qq) { return r | g << 8 | b << 16 | a << 24 | qq << 32; }
// MATCH func_002436F8
void object_002436f8(int x, int y, int w, int h, int x2, int y2, int w2, int h2, Col_2436F8 c)
{
    unsigned long *q;
    unsigned long z;
    int base = D_00319660[0];
    int zz = D_004A13E8 + 0xffffff;
    func_00190328(&D_00314C20);
    D_00314C20.q[0] = (long)(base + 0x3140) | 0x21440000 | (unsigned long)D_004A13C4 << 56 | 0x7ff8600000000L;
    D_00314C20.q[1] = 6;
    D_00314C20.q[2] = 342;
    D_00314C20.q[3] = 0;
    D_00314C20.q += 4;
    if (D_004A71E4 != *(int *)&c) {
        { float qf = 1.0f; D_00314C20.q[0] = (unsigned long)c.r | (unsigned long)c.g << 8 | (unsigned long)c.b << 16 | (long)D_004A14B0 << 24 | (unsigned long)*(unsigned *)&qf << 32; }
        D_00314C20.q[1] = 1;
        D_00314C20.q += 2;
        D_004A71E4 = *(int *)&c;
    }
    q = D_00314C20.q;
    z = (long)zz << 32;
    q[0] = (long)(x2 + 8) | (long)(y2 + 8) << 16;
    q[1] = 3;
    q[2] = (long)x | (long)y << 16 | z;
    q[3] = 4;
    q[4] = (long)(x2 + w2) | (long)(y2 + h2 + 4) << 16;
    q[5] = 3;
    q[6] = (long)(x + w) | (long)(y + h) << 16 | z;
    q[7] = 4;
    D_00314C20.q = q + 8;
    func_00190420(&D_00314C20);
}
