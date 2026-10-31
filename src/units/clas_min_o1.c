/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char p[12]; unsigned w12; } P_0029D0B8;
typedef struct { char p[16]; P_0029D0B8 *w16; } O_0029D0B8;
void func_0029D378(O_0029D0B8 *); void func_0029D200(O_0029D0B8 *); void func_0029D120(O_0029D0B8 *);
// MATCH func_0029D0B8
int clas_min_0029d0b8(O_0029D0B8 *o) { P_0029D0B8 *p = o->w16; unsigned f; if (p == 0) return 0; f = p->w12; if (f & 8) { func_0029D378(o); return 1; } if (f & 1) { func_0029D200(o); return 1; } func_0029D120(o); return 1; }

typedef struct { char p[24]; unsigned w24; } P_0029CA78;
typedef struct { char p[28]; P_0029CA78 *w28; } O_0029CA78;
void func_0029CBF0(O_0029CA78 *); void func_0029CD90(O_0029CA78 *, int, int); void func_0029CAF8(O_0029CA78 *);
// MATCH func_0029CA78
int clas_min_0029ca78(O_0029CA78 *o, int a) { P_0029CA78 *p = o->w28; unsigned f; if (p == 0) return 0; f = p->w24; if (f & 1) { func_0029CBF0(o); return 1; } if (f & 4) { func_0029CD90(o, a, 10000); return 1; } if (f & 16) { func_0029CD90(o, a, 50000); return 1; } func_0029CAF8(o); return 1; }

// MATCH func_002A43A8
int clas_min_002a43a8(int *p, int n) { int i; for (i = 0; i < n && p != 0; i++) p = (int *)p[0]; if (p == 0) return -1; return p[1]; }

// MATCH func_002A1DF8
int clas_min_002a1df8(char *o, int key) { char *p; if (key == -1) return *(int *)(o + 1616) == 0; p = *(char **)(o + 1616); while (p != 0) { if (*(int *)(p + 260) == key) break; p = *(char **)(p + 256); } return p == 0; }
