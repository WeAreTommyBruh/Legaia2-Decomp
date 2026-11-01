/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct N__00212A98 { struct N__00212A98 *next; int w4, w8; char p[72]; char name[1]; } N__00212A98;
typedef struct { int w0; int w4; N__00212A98 *w8; } O__00212A98;
extern char D_00455728[];
int func_001118F8_00212A98(char *, ...) __asm__("func_001118F8"); void func_0010AF68_00212A98(int, int, char *, int) __asm__("func_0010AF68");
// MATCH func_00212A98
int PchSeLoad(O__00212A98 *o, int n)
{
    N__00212A98 *p;
    int i;
    char *s;
    p = o->w8;
    i = 0;
    if (p != 0 && n != 0) {
        do {
            p = p->next;
            if (p == 0) break;
            i++;
        } while (i != n);
    }
    if (p == 0) return 0;
    s = p->name;
    func_001118F8_00212A98(D_00455728, p->w4, s, p->w8);
    func_0010AF68_00212A98(o->w0, p->w4, s, p->w8);
    return 1;
}

typedef struct N__00212B30 { struct N__00212B30 *next; int w4, w8, w12, w16; } N__00212B30;
typedef struct { int w0; int w4; N__00212B30 *w8; } O__00212B30;
extern char D_00455740[];
int func_0010BFA0(int); int func_001118F8_00212B30(char *, ...) __asm__("func_001118F8"); void func_0010C2D0_00212B30(int, int, int, int, int) __asm__("func_0010C2D0");
// MATCH func_00212B30
int FUN_00212b30(O__00212B30 *o, int n, int m)
{
    N__00212B30 *p, *q;
    int i;
    while (func_0010BFA0(o->w0) == 0) ;
    p = o->w8;
    i = 0;
    if (p == 0) return 0;
    if (n != 0) {
        do {
            p = p->next;
            if (p == 0) break;
            i++;
        } while (i != n);
    }
    if (p == 0) return 0;
    q = (N__00212B30 *)p->w16;
    i = 0;
    if (q == 0) return 0;
    if (m != 0) {
        do {
            q = q->next;
            if (q == 0) break;
            i++;
        } while (i != m);
    }
    if (q == 0) return 0;
    func_001118F8_00212B30(D_00455740, q->w4, q->w8, q->w12, q->w16);
    func_0010C2D0_00212B30(o->w0, q->w4, q->w8, q->w12, q->w16);
    return 1;
}

typedef struct N__00212CA8 { struct N__00212CA8 *next; int w4; char p[128]; char name[1]; } N__00212CA8;
typedef struct { int w0; int w4, w8; N__00212CA8 *w12; } O__00212CA8;
extern char D_00455760[];
int func_0010BFA0(int); int func_001118F8_00212CA8(char *, ...) __asm__("func_001118F8"); void func_002B8EB0(int, char *, int);
// MATCH func_00212CA8
int FUN_00212ca8(O__00212CA8 *o, int n)
{
    N__00212CA8 *p;
    int i;
    char *s;
    while (func_0010BFA0(o->w0) == 0) ;
    p = o->w12;
    i = 0;
    if (p != 0 && n != 0) {
        do {
            p = p->next;
            if (p == 0) break;
            i++;
        } while (i != n);
    }
    if (p == 0) return 0;
    s = p->name;
    func_001118F8_00212CA8(D_00455760, p->w4, s);
    func_002B8EB0(p->w4, s, 100);
    return 1;
}

int func_00213548(int, int, int, int); int func_002138A0(int, int, int, int, int);
// MATCH func_002132E0
int FUN_002132e0(int a, int b, int c, int d, int e, int f) { int r; r = 0; if (func_00213548(a, b, c, d) != 0) r = func_002138A0(a, b, c, d, f) != 0; return r; }

int func_00213548(int, int, int, int); int func_002139B8(int, int, int, int, int, int, int);
// MATCH func_00213368
int FUN_00213368(int a, int b, int c, int d, int e, int f, int g, int h) { int r; r = 0; if (func_00213548(a, b, c, d) != 0) r = func_002139B8(a, b, c, d, f, g, h) != 0; return r; }

int func_00213088(int, int); char *func_00212F00(int, int);
// MATCH func_00213258
int MotBoneName(int a, int b, int c) { char *p; int r; int t; if (func_00213088(a, b) == 0) { t = c * 0x30 + 0x68; r = a + t; } else { p = func_00212F00(a, b); { int u = *(int *)(p + 0x34); int v = *(int *)(p + 0x38); int k = c * 0x18; r = (int)p + v + *(unsigned short *)(p + u + k); } } return r; }

