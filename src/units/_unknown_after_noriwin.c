/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A140C, D_004A253C;
// MATCH func_0013D5D8
void FUN_0013d5d8(int a) { if (a != 0 && (D_004A140C & 0x200) != 0) D_004A253C++; }

extern int D_004A140C_0013D320 __asm__("D_004A140C"), D_004A2534; extern int D_00419D18_0013D320[] __asm__("D_00419D18");
// MATCH func_0013D320
int FUN_0013d320(int a) { if (a != 0 && (D_004A140C_0013D320 & 0x200)) {
D_00419D18_0013D320[26] = 255;
D_00419D18_0013D320[70] = 255;
D_00419D18_0013D320[114] = 255;
D_004A2534 = D_004A2534 + 1;
} }

extern int D_004A2A38, D_004A2A3C, D_004A2A40, D_004A3860; extern char D_00343010_0013F2E8[] __asm__("D_00343010"); extern int D_003323B0[]; int func_001E3A00(char *, int *, int, int);
// MATCH func_0013F2E8
int FUN_0013f2e8(void) { int loc; loc = 0; if (D_004A2A38 >= 0) { int r; D_004A3860 = D_004A2A3C; r = func_001E3A00(D_00343010_0013F2E8, &loc, D_004A2A40, 0); D_004A3860 = 1; D_003323B0[D_004A2A38] = r; } else loc = 1; return loc; }

typedef struct { char p[34]; short h; } T36_0013C220;
extern T36_0013C220 D_0041C600[]; extern int D_004A66E0, D_004A66E4, D_004A66E8;
extern float D_0041C540[], D_0041C550[], D_0041C5A0[], D_0041C5B0[], D_004028D0[], D_004028E0[];
// MATCH func_0013C220
void FUN_0013c220(void) { int i; for (i = 0; i < 32; i++) D_0041C600[i].h = 0; if (D_004A66E0 != 0) { D_0041C5A0[0] = D_004028D0[0] = D_0041C540[0]; D_0041C5A0[1] = D_004028D0[1] = D_0041C540[1]; D_0041C5A0[2] = D_004028D0[2] = D_0041C540[2]; D_0041C5B0[0] = D_004028E0[0] = D_0041C550[0]; D_0041C5B0[1] = D_004028E0[1] = D_0041C550[1]; D_0041C5B0[2] = D_004028E0[2] = D_0041C550[2]; } D_004A66E4 = 0; D_004A66E8 = 0; D_004A66E0 = 0; }

void func_00247970(int);
void func_002479F0(void);
void func_00247A70(int,int,int);
void func_00247C98(float,float,float);
typedef struct { float x, y, z, w; } AxisPosition;
extern AxisPosition D_05BF68E0[];
extern int D_004A1B9C;
void func_002489F0(void);

// MATCH func_0013A5D0
void FUN_0013a5d0(void)
{
    AxisPosition *v;
    func_002489F0();
    func_00247970(2);
    func_00247A70(255, 0, 0);
    func_00247C98(-1024.0f, 0.0f, 0.0f);
    func_00247C98(+1024.0f, 0.0f, 0.0f);
    func_002479F0();

    func_00247970(2);
    func_00247A70(0, 255, 0);
    func_00247C98(0.0f, -1024.0f, 0.0f);
    func_00247C98(0.0f, +1024.0f, 0.0f);
    func_002479F0();

    func_00247970(2);
    func_00247A70(0, 0, 255);
    func_00247C98(0.0f, 0.0f, -1024.0f);
    func_00247C98(0.0f, 0.0f, +1024.0f);
    func_002479F0();

    func_00247970(2);
    func_00247A70(255, 0, 0);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x-1024.0f, -v->y, -v->z);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x+1024.0f, -v->y, -v->z);
    func_002479F0();

    func_00247970(2);
    func_00247A70(0, 255, 0);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x, -v->y-1024.0f, -v->z);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x, -v->y+1024.0f, -v->z);
    func_002479F0();

    func_00247970(2);
    func_00247A70(0, 0, 255);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x, -v->y, -v->z-1024.0f);
    v = D_05BF68E0+D_004A1B9C;
    func_00247C98(-v->x, -v->y, -v->z+1024.0f);
    func_002479F0();
}

typedef struct {float x,y,z,w;} Point; typedef struct {long a,b;} Pair;
extern Pair D_00434B50[];
extern Point D_05BF6950[];
extern int D_004A237C,D_004A14AC;
void *func_002DC804(void*,int,unsigned);
void func_0018F368(void*,void*,void*);
void func_00249950(void*,void*);
void func_00230078(void*,int,int,int);
void func_0022F3C8(float,float);
void func_00248CF8(int,float);
void func_0022FDA0(int);
void func_0022ECB0(void*);

// MATCH func_0013D008
void FUN_0013d008(char *p,int b)
{
    Point zero;
    Point pos, end, *out;
    float *item;
    char *tab;
    int save;
    func_002DC804(&zero, 0, 16);
    save = D_004A14AC;
    func_0018F368(&pos, (void*)0x70003f80, &zero);
    func_0018F368(&end, (void*)0x70003f80, p+32);
    func_00249950(&pos, &end);
    out = &D_05BF6950[D_004A237C];
    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
    D_004A237C++;
    tab = *(char **)(p+144);
    tab = tab+b*4;
    item = *(float **)(tab+2052);
    func_00248CF8(0, item[16]);
    func_00248CF8(1, item[17]);
    func_00248CF8(2, item[18]);
    func_0022FDA0(1);
    func_0022ECB0(item);
    D_004A14AC = save;
}
