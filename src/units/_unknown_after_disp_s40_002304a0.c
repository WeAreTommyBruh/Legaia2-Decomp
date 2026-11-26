// compiler: 991111-01
// cflags:
typedef struct { char pad0[144]; struct { char p[2052]; int a[1]; } *tbl; char pad94[76]; float f224; char pade4[88]; float x, y, z; } O_2304A0;
typedef struct { char pad[52]; float s; } S_2304A0;
extern S_2304A0 *D_004A14B4;
extern int D_004A70EC, D_004A70F0, D_004A70F8, D_004A70E4;
extern int D_004A147C, D_004A1480, D_004A1484, D_004A1488;
extern char D_00342CD0[];
void func_00231580(O_2304A0 *, int, int, float, float);
int func_002306E8(O_2304A0 *, int, unsigned short *, int);
void func_00231548(void);
void func_00243A68(int, char *);
void func_0017DB78(unsigned short *, unsigned long, float, float, float, int, float, int, int);
void func_0017B090(unsigned short *, unsigned long, float, float, float, int, float);
// MATCH func_002304A0
void FUN_002304a0(O_2304A0 *o, int i, unsigned short *m, int d)
{
    int c;
    unsigned long t;
    c = 0x80808080;
    ((unsigned char *)&c)[3] = (int)(o->f224 * 96.0f * D_004A14B4->s);
    if (D_004A70EC == 0) {
        if (D_004A70F0 != 0)
            func_00231580(o, o->tbl->a[i], (int)o->z, o->x, o->y);
        func_002306E8(o, i, m, d);
        if (D_004A70F0 != 0)
            func_00231548();
    }
    if (D_004A70F8 == 0) {
        { long a = (long)D_004A147C | 0x2000000000000000L, b = (long)D_004A1480 << 14 | 0x400000000L, cc = (long)D_004A1484 << 26 | 0x1300000L, e = (long)D_004A1488 << 30 | 0x7c48000000000L; t = (a | cc) | (b | e); }
        if (*m & 0x80) {
            func_00243A68(1, D_00342CD0);
            if (D_004A70E4 == 0 || D_004A70E4 == 2)
                func_0017DB78(m, t, 0.0f, 0.125f, 0.25f, c, 0.125f, 0x70002000, 0x70002800);
        } else {
            if (D_004A70E4 == 0 || D_004A70E4 == 2)
                func_0017B090(m, t, 0.0f, 0.125f, 0.25f, c, 0.125f);
        }
    }
    D_004A70EC = 0;
}
