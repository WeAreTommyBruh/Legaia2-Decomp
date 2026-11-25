typedef struct { char p0[76]; int f76; char p80[4]; int f84, f88; char p92[4]; float f96; } R;
typedef struct { char p0[152]; int f152; char p156[32]; short f188; } M;
typedef struct { M *m; char p4[472]; R *r; } O;
extern int D_004A45E8, D_004A1444, D_004A140C, D_004A46C8, D_004A46CC; extern float D_004A46D0, D_004A46D4; extern float D_003C18A0[];
O *func_0020BBD8(int); int func_00213048(int, int); float func_0029F9F0(R *);
// MATCH func_0020DAB0
void pchevent_0020dab0(int a)
{
    O *o = func_0020BBD8(D_004A45E8);
    if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) {
        if (o == 0) goto zero;
        if (o->m->f152 != 0 && o->r != 0) o->r->f76 |= 0x401;
    }
    if (o != 0 && o->m->f152 != 0 && o->r != 0) {
        float t = func_00213048(o->m->f152, o->m->f188) - 1;
        D_004A46C8 = o->r->f84;
        D_004A46CC = o->r->f88;
        D_003C18A0[21] = t;
        D_003C18A0[13] = t;
        D_004A46D0 = func_0029F9F0(o->r);
        D_004A46D4 = o->r->f96;
        return;
    }
zero:
    D_004A46C8 = 0;
    D_004A46CC = 0;
    D_004A46D0 = 0;
    D_004A46D4 = 0;
}
