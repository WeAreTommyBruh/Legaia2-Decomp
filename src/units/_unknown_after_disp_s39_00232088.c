// cflags: -fno-gcse
#include "../common.h"
typedef struct { int unk0[4]; u64 *p; } PacketBuf;
typedef struct {
    int type;          /* 0x00 */
    int unk4;
    short x0, y0;      /* 0x08 */
    short x1, y1;      /* 0x0c */
    int unk10;
    short unk14;
    short unk16;
    short unk18;
    short x2;          /* 0x1a */
    short y2;          /* 0x1c */
    short unk1e;
    int unk20, unk24;
    float t;           /* 0x28 */
    float u;           /* 0x2c */
    float speed;       /* 0x30 */
    int flags;         /* 0x34 */
    int unk38, unk3c, unk40;
    int limit;         /* 0x44 */
    int count;         /* 0x48 */
    int unk4c, unk50;
    float w;           /* 0x54 */
    float h;           /* 0x58 */
} Win;
extern PacketBuf D_00314C20;
extern int D_004A14B0;
extern float D_004A0674;
void FUN_00190328(PacketBuf *); void FUN_00190420(PacketBuf *);
void func_00233A48(Win *); void func_00237060(Win *, int, int); void func_00234A40(Win *, int, int);
void func_00233B38(Win *); void func_00232A40(Win *); void func_002334F0(Win *); void func_002340A8(Win *);
void func_002336D8(Win *); void func_00232348(Win *); void func_002344D0(Win *); void func_00233680(Win *);
int func_00111518(void); void func_00232028(Win *, float);
// MATCH func_00232088
void FUN_00232088(Win *o, int still)
{
    u64 *p;
    D_004A14B0 = 0x80;
    FUN_00190420(&D_00314C20);
    p = D_00314C20.p;
    p[0] = 0x5100d;
    p[1] = 0x47;
    D_00314C20.p = p + 2;
    FUN_00190328(&D_00314C20);
    if (o->speed >= 0.0f) {
        o->w = o->x1;
        o->h = o->y1;
    } else {
        o->w = o->x2;
        o->h = o->y2;
        if (o->flags & 0x40) {
            o->w = 160.0f;
            o->h = 32.0f;
        } else {
            o->w = o->x0;
            o->h = o->y0;
        }
    }
    switch (o->type) {
    case 0: func_00237060(o, 0, 0); break;
    case 1: func_00233A48(o); break;
    case 2: func_00237060(o, 1, 0); break;
    case 3: func_00234A40(o, 2, 0); break;
    case 4: func_00233B38(o); break;
    case 5: func_00232A40(o); break;
    case 6: func_002334F0(o); break;
    case 7: func_002340A8(o); break;
    case 8: func_002336D8(o); break;
    case 9: func_00232348(o); break;
    case 10: func_002344D0(o); break;
    case 11: func_00233680(o); break;
    }
    if (still == 0) {
        o->t += o->speed * func_00111518();
        o->u += o->speed * func_00111518();
        if (o->t > 1.0f) {
            o->t = 1.0f;
            o->count++;
            if (o->limit != 0 && o->count > o->limit) {
{ o->count = 0; __asm__ volatile(""); func_00232028(o, D_004A0674); }
            }
        }
        if (o->t < 0.0f) {
            o->u = o->t = 0.0f;
            o->count = 0;
        }
        if (o->u > 2.0f) o->u = 2.0f;
        D_004A14B0 = 0x80;
    }
}
