/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A3660, D_004A3664, D_004A3668;
int func_002DD5E0();
// MATCH func_0018A630
void file_0018a630(int a, int b) { D_004A3664 = b; D_004A3660 = a; D_004A3668 = func_002DD5E0(a); }

typedef struct { char pad[8]; int a8; char pad1[12]; int a24; } S_00189B28;
extern int D_004A6F64;
void func_002C1188(int); void func_00131588_00189B28(int) __asm__("func_00131588"); void func_00108B80_00189B28(void *) __asm__("func_00108B80");
// MATCH func_00189B28
void file_00189b28(S_00189B28 *s, int fl) { func_002C1188(D_004A6F64); if (s->a8 != 0) func_00131588_00189B28(s->a8); if (s->a24 != 0) func_00131588_00189B28(s->a24); if (fl & 1) func_00108B80_00189B28(s); }

extern char D_004401A8_0018AA00[] __asm__("D_004401A8"); void func_0018BAE8(char *, char *); int func_002E9950(char *, int); int func_002E9D58(int, int, int); int func_002E9F90_0018AA00(int, void *, int) __asm__("func_002E9F90"); void func_002E9BD8(int); void func_001118F8_0018AA00(char *, ...) __asm__("func_001118F8");
// MATCH func_0018AA00
int file_0018aa00(char *name, void *dst) { char buf[256]; int fd, n; func_0018BAE8(buf, name); fd = func_002E9950(buf, 1); if (fd < 0) { func_001118F8_0018AA00(D_004401A8_0018AA00, buf); return -1; } n = func_002E9D58(fd, 0, 2); n = (n + 2047) & -2048; func_002E9D58(fd, 0, 0); func_002E9F90_0018AA00(fd, dst, n); func_002E9BD8(fd); return n; }

extern int D_004A6F54; char *func_002DD1DC_0018ACF0(char *, int) __asm__("func_002DD1DC"); char *func_0018A708(char *); int func_00196AF8(int, int, int, int);
// MATCH func_0018ACF0
int file_0018acf0(char *name, int a) { char *p = func_002DD1DC_0018ACF0(name, 58); char *e; int n, r, w; if (p == 0) p = name; else p++; e = func_0018A708(p); if (e == 0) return -1; n = ((unsigned short *)e)[5]; w = ((int *)e)[3]; r = func_00196AF8(D_004A6F54 + w, n, a, 0); n <<= 11; if (r < 0) n = -1; return n; }

extern int D_004A6F54_0018AD80 __asm__("D_004A6F54"); extern char D_004401E8[], D_00440208[]; char *func_002DD1DC_0018AD80(char *, int) __asm__("func_002DD1DC"); char *func_0018A708(char *); int func_00196AF8(int, int, int, int); void func_001118F8_0018AD80(char *, ...) __asm__("func_001118F8");
// MATCH func_0018AD80
int file_0018ad80(char *name, int a) { char *p = func_002DD1DC_0018AD80(name, 58); char *e; int r, n; if (p == 0) p = name; else p++; e = func_0018A708(p); if (e == 0) { func_001118F8_0018AD80(D_004401E8); return -1; } n = ((unsigned short *)e)[5] << 11; r = func_00196AF8(D_004A6F54_0018AD80 + ((int *)e)[3], ((unsigned short *)e)[5], a, 1); if (r < 0) { func_001118F8_0018AD80(D_00440208, r); n = -1; } return n; }

extern char *D_004A3620; unsigned func_0018A178(char *);
// MATCH func_0018A218
int file_0018a218(char *s) { unsigned key = func_0018A178(s); char *t = D_004A3620; int lo = 0, hi = ((unsigned short *)t)[2] - 1, mid; unsigned *w = (unsigned *)(t + 16); while (lo <= hi) { mid = (lo + hi) >> 1; if (key < w[mid]) hi = mid - 1; else if (key > w[mid]) lo = mid + 1; else return mid; } return -1; }

extern int D_004A6F54_0018AAF0 __asm__("D_004A6F54"); extern char D_00440120[], D_004401C8[]; char *func_002DD1DC_0018AAF0(char *, int) __asm__("func_002DD1DC"); char *func_0018A708(char *); void *func_00162130_0018AAF0(int, char *, int) __asm__("func_00162130"); void func_001118F8_0018AAF0(char *, ...) __asm__("func_001118F8"); int func_00196AF8_0018AAF0(int, int, void *, int) __asm__("func_00196AF8"); void func_001621F8_0018AAF0(void *, char *, int) __asm__("func_001621F8");
// MATCH func_0018AAF0
void *file_0018aaf0(char *name, int *out) { char *p = func_002DD1DC_0018AAF0(name, 58); char *e; int n; void *buf; if (p == 0) p = name; else p++; e = func_0018A708(p); if (e == 0) return 0; n = ((unsigned short *)e)[5] << 11; buf = func_00162130_0018AAF0(n, D_00440120, 961); if (buf == 0) { func_001118F8_0018AAF0(D_004401C8, p); return 0; } if (func_00196AF8_0018AAF0(D_004A6F54_0018AAF0 + ((int *)e)[3], ((unsigned short *)e)[5], buf, 0) < 0) { func_001621F8_0018AAF0(buf, D_00440120, 970); buf = 0; } if (out) *out = n; return buf; }

extern int D_004A6F54_0018ABF0 __asm__("D_004A6F54"); extern char D_00440120_0018ABF0[] __asm__("D_00440120"), D_004401C8_0018ABF0[] __asm__("D_004401C8"); char *func_002DD1DC_0018ABF0(char *, int) __asm__("func_002DD1DC"); char *func_0018A708(char *); void *func_00162130_0018ABF0(int, char *, int) __asm__("func_00162130"); void func_001118F8_0018ABF0(char *, ...) __asm__("func_001118F8"); int func_00196AF8_0018ABF0(int, int, void *, int) __asm__("func_00196AF8"); void func_001621F8_0018ABF0(void *, char *, int) __asm__("func_001621F8");
// MATCH func_0018ABF0
void *file_0018abf0(char *name, int *out) { char *p = func_002DD1DC_0018ABF0(name, 58); char *e; int n; void *buf; if (p == 0) p = name; else p++; e = func_0018A708(p); if (e == 0) return 0; n = ((unsigned short *)e)[5] << 11; buf = func_00162130_0018ABF0(n, D_00440120_0018ABF0, 994); if (buf == 0) { func_001118F8_0018ABF0(D_004401C8_0018ABF0, p); return 0; } if (func_00196AF8_0018ABF0(D_004A6F54_0018ABF0 + ((int *)e)[3], ((unsigned short *)e)[5], buf, 1) < 0) { func_001621F8_0018ABF0(buf, D_00440120_0018ABF0, 1003); buf = 0; } if (out) *out = n; return buf; }

// MATCH func_0018A300
long *file_0018a300(char *o, long key) { unsigned i; unsigned n; i = 0; n = *((unsigned short *) (o + 8)); o = o + (((*((unsigned short *) (o + 10))) << 4) + 16); if (n != 0) { do { do { if ((*((long *) o)) == key) { return (long *) o; } i++; o = o + (((*((unsigned short *) (o + 12))) << 4) + 16); } while (i < n); } while (0); } return 0; }
