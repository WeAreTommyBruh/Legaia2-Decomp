/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *); } VT_00180BF8;
typedef struct { char p[12]; VT_00180BF8 *vt; } O_00180BF8;
extern char D_0043E420[]; void *func_00162130(int, void *, int); O_00180BF8 *func_00180C58(void *);
// MATCH func_00180BF8
O_00180BF8 *screfct_00180bf8(void) { O_00180BF8 *p = func_00180C58(func_00162130(896, D_0043E420, 140)); if (p != 0) p->vt->fn((char *)p + p->vt->adj); return p; }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *); } VT_00183BB8;
typedef struct { char p[12]; VT_00183BB8 *vt; } O_00183BB8;
extern char D_0043E420_00183BB8[] __asm__("D_0043E420"); void *func_00162130(int, void *, int); O_00183BB8 *func_00183C18(void *);
// MATCH func_00183BB8
O_00183BB8 *screfct_00183bb8(void) { O_00183BB8 *p = func_00183C18(func_00162130(176, D_0043E420_00183BB8, 891)); if (p != 0) p->vt->fn((char *)p + p->vt->adj); return p; }

typedef struct { char p[12]; void *vt; char p2[128]; int w; } O_001832D8;
extern char D_0043E4A8[]; void func_00131588_001832D8(int) __asm__("func_00131588"); void func_00185168(void *, int);
// MATCH func_001832D8
void screfct_001832d8(O_001832D8 *o, int f) { o->vt = D_0043E4A8; if (o->w != 0) func_00131588_001832D8(o->w); func_00185168(o, f); }

typedef struct { char p[12]; char *w12; char q[136]; void *w152, *w156, *w160; } O_00183C50;
extern char D_0043E480[]; void func_00131588(void *); void func_00185168_00183C50(O_00183C50 *, int) __asm__("func_00185168");
// MATCH func_00183C50
void screfct_00183c50(O_00183C50 *o, int a) { o->w12 = D_0043E480; if (o->w152) func_00131588(o->w152); if (o->w156) func_00131588(o->w156); if (o->w160) func_00131588(o->w160); func_00185168_00183C50(o, a); }

extern char D_0043E420_00181840[] __asm__("D_0043E420"); void *func_00162130(int, void *, int);
typedef struct { char p[8]; short adj; short pad; void (*fn)(void *); } VT_181840_00181840;
typedef struct { char p[12]; VT_181840_00181840 *vt; } O_181840_00181840;
void *func_001818B8(void *, void *, float);
// MATCH func_00181840
O_181840_00181840 *screfct_00181840(void *o, float x) { O_181840_00181840 *r = func_001818B8(func_00162130(240, D_0043E420_00181840, 327), o, x); if (r != 0) r->vt->fn((char *)r + r->vt->adj); return r; }
