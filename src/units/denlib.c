/* Functions of this report unit, matched by hand. */
#include "../common.h"

void func_0018C4C8(void *); void func_0018CA90(void *, void *);
// MATCH func_0018C588
void denlib_0018c588(void *a, void *b) { func_0018C4C8(a); func_0018CA90(a, b); }

typedef struct { int a, b; } O_0018C4C8;
void func_00131588_0018C4C8(int) __asm__("func_00131588");
// MATCH func_0018C4C8
void denlib_0018c4c8(O_0018C4C8 *o) { if (o->a != 0) { func_00131588_0018C4C8(o->a); } o->a = 0; if (o->b != 0) { func_00131588_0018C4C8(o->b); } o->b = 0; }

void func_0018C4C8_0018C518(int, int) __asm__("func_0018C4C8"); int func_0018B508_0018C518(int, char *) __asm__("func_0018B508"); void func_0018CA90_0018C518(int, int) __asm__("func_0018CA90"); void func_001621F8_0018C518(int, char *, int) __asm__("func_001621F8");
extern char D_00440540[];
// MATCH func_0018C518
int denlib_0018c518(int a, int b) { char buf[16]; int r; func_0018C4C8_0018C518(a, b); r = func_0018B508_0018C518(b, buf); if (r == 0) return 0; func_0018CA90_0018C518(a, r); func_001621F8_0018C518(r, D_00440540, 947); return 1; }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int); } VT_0018C710;
typedef struct { int w0, w4; int w8; char pad[12]; VT_0018C710 *vt; } QS_0018C710;
int func_00241C98(int, int);
int func_00241D00(int, int, int, int, int, int, int, int, int, int);
int func_00241FD8(int, int, int, int, int, int, int, int, int, int);
// MATCH func_0018C710
void denlib_0018c710(int *p, QS_0018C710 *q) {
    int v = func_00241C98(q->w8, 0);
    if (p[1] != 0)
        v = func_00241D00(v, *(unsigned short *)((char *)p + 52), 0, 4, p[1], (unsigned)p[5] >> 2, 0, 0, *(unsigned short *)((char *)p + 36), *(unsigned short *)((char *)p + 38));
    v = func_00241FD8(v, *(unsigned short *)((char *)p + 48), *(unsigned char *)((char *)p + 28), *(unsigned short *)((char *)p + 32), p[0], (unsigned)p[2] >> 4, 0, 0, p[3], p[4]);
    q->w8 = (int)v;
    q->vt->fn((char *)q + q->vt->adj, v);
}

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int); } VT_0018C640;
typedef struct { int w0, w4; int w8; char pad[12]; VT_0018C640 *vt; } QS_0018C640;
extern char D_00342CD0_0018C640[] __asm__("D_00342CD0");
int func_00241C98(int, int);
int func_00241D00(int, int, int, int, int, int, int, int, int, int);
int func_00241FD8(int, int, int, int, int, int, int, int, int, int);
// MATCH func_0018C640
void denlib_0018c640(int *p) {
    QS_0018C640 *q = (QS_0018C640 *)D_00342CD0_0018C640;
    int v = func_00241C98(q->w8, 0);
    if (p[1] != 0)
        v = func_00241D00(v, *(unsigned short *)((char *)p + 52), 0, 4, p[1], (unsigned)p[5] >> 2, 0, 0, *(unsigned short *)((char *)p + 36), *(unsigned short *)((char *)p + 38));
    v = func_00241FD8(v, *(unsigned short *)((char *)p + 48), *(unsigned char *)((char *)p + 28), *(unsigned short *)((char *)p + 32), p[0], (unsigned)p[2] >> 4, 0, 0, p[3], p[4]);
    q->w8 = (int)v;
    q->vt->fn((char *)q + q->vt->adj, v);
}
