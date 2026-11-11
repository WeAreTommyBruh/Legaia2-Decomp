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

extern char D_00440120_18A918[] __asm__("D_00440120"), D_004401A8_18A918[] __asm__("D_004401A8"), D_004401C8_18A918[] __asm__("D_004401C8");
void func_0018BAE8_18A918(char *, char *) __asm__("func_0018BAE8"); void func_002EDC50_18A918(void) __asm__("func_002EDC50"); int func_002E9950_18A918(char *, int) __asm__("func_002E9950"); int func_002E9D58_18A918(int, int, int) __asm__("func_002E9D58"); void func_002E9BD8_18A918(int) __asm__("func_002E9BD8");
void *func_00162130_18A918(int, char *, int) __asm__("func_00162130"); int func_001118F8_18A918(char *, ...) __asm__("func_001118F8"); void func_002EDC98_18A918(void) __asm__("func_002EDC98"); void func_0010FE28_18A918(char *, void *) __asm__("func_0010FE28");
// MATCH func_0018A918
void *file_0018a918(char *name, unsigned *psize) { char buf[256]; int fd; int size; void *p; func_0018BAE8_18A918(buf, name); func_002EDC50_18A918(); fd = func_002E9950_18A918(buf, 1); if (fd < 0) { func_001118F8_18A918(D_004401A8_18A918, buf); return 0; } size = func_002E9D58_18A918(fd, 0, 2) + 2047; size &= -2048; func_002E9BD8_18A918(fd); p = func_00162130_18A918(size, D_00440120_18A918, 826); if (p == 0) { func_001118F8_18A918(D_004401C8_18A918, buf); return 0; } if (psize != 0) *psize = size; func_002EDC98_18A918(); func_0010FE28_18A918(buf, p); return p; }

extern char D_00440120_0018AF40[] __asm__("D_00440120"), D_004401C8_0018AF40[] __asm__("D_004401C8"), D_004A3658_18AF40[] __asm__("D_004A3658"), D_004A3630_18AF40 __asm__("D_004A3630");
void *func_002DD1DC_18AF40(char *, int) __asm__("func_002DD1DC"); int func_002DCE40_18AF40(char *, char *, ...) __asm__("func_002DCE40"); void *func_0018A708_18AF40(char *) __asm__("func_0018A708"); void *func_00162130_18AF40(int, char *, int) __asm__("func_00162130");
int func_001118F8_18AF40(char *, ...) __asm__("func_001118F8"); void func_0010FEB0_18AF40(char *, void *, int, int) __asm__("func_0010FEB0");
// MATCH func_0018AF40
void *file_0018af40(char *name, unsigned *psize) { char buf[256]; char *c, *n; int *e; void *p; unsigned size; c = func_002DD1DC_18AF40(name, 58); if (c != 0) c = c + 1; else c = name; e = func_0018A708_18AF40(c); if (e == 0) return 0; func_002DCE40_18AF40(buf, D_004A3658_18AF40, &D_004A3630_18AF40); size = (unsigned)*(unsigned short *)((char *)e + 10) << 11; p = func_00162130_18AF40(size, D_00440120_0018AF40, 1129); if (p == 0) { func_001118F8_18AF40(D_004401C8_0018AF40, buf); return 0; } if (psize != 0) *psize = size; func_0010FEB0_18AF40(buf, p, e[3] << 11, size); return p; }

extern char D_004401A8_18A828[] __asm__("D_004401A8"), D_004401C8_18A828[] __asm__("D_004401C8"), D_00440120_18A828[] __asm__("D_00440120");
void func_0018BAE8_18A828(char *, char *) __asm__("func_0018BAE8"); int func_002E9950_18A828(char *, int) __asm__("func_002E9950"); int func_002E9D58_18A828(int, int, int) __asm__("func_002E9D58"); int func_002E9F90_18A828(int, void *, int) __asm__("func_002E9F90"); void func_002E9BD8_18A828(int) __asm__("func_002E9BD8"); void *func_00162130_18A828(int, char *, int) __asm__("func_00162130"); int func_001118F8_18A828(char *, ...) __asm__("func_001118F8");
// MATCH func_0018A828
void *file_0018a828(char *name, unsigned *psize) { char buf[256]; int fd; int size; void *p; func_0018BAE8_18A828(buf, name); fd = func_002E9950_18A828(buf, 1); if (fd < 0) { func_001118F8_18A828(D_004401A8_18A828, buf); return 0; } size = func_002E9D58_18A828(fd, 0, 2) + 2047; size &= -2048; func_002E9D58_18A828(fd, 0, 0); p = func_00162130_18A828(size, D_00440120_18A828, 783); if (p == 0) { func_001118F8_18A828(D_004401C8_18A828, buf); return 0; } func_002E9F90_18A828(fd, p, size); if (psize != 0) *psize = size; func_002E9BD8_18A828(fd); return p; }

extern char D_00440120_18AE28[] __asm__("D_00440120"), D_004401A8_18AE28[] __asm__("D_004401A8"), D_004401C8_18AE28[] __asm__("D_004401C8"), D_004A3658_18AE28[] __asm__("D_004A3658"); extern char D_004A3630_18AE28 __asm__("D_004A3630");
void *func_002DD1DC_18AE28(char *, int) __asm__("func_002DD1DC"); void *func_0018A708_18AE28(char *) __asm__("func_0018A708"); int func_002DCE40_18AE28(char *, char *, ...) __asm__("func_002DCE40"); int func_002E9950_18AE28(char *, int) __asm__("func_002E9950"); int func_002E9D58_18AE28(int, int, int) __asm__("func_002E9D58"); void *func_00162130_18AE28(int, char *, int) __asm__("func_00162130"); int func_001118F8_18AE28(char *, ...) __asm__("func_001118F8"); int func_002E9F90_18AE28(int, void *, int) __asm__("func_002E9F90"); void func_002E9BD8_18AE28(int) __asm__("func_002E9BD8");
// MATCH func_0018AE28
void *file_0018ae28(char *name, unsigned *psize) { char buf[256]; char *c; int *e; int fd; unsigned size; void *p; c = func_002DD1DC_18AE28(name, 58); if (c != 0) c = c + 1; else c = name; e = func_0018A708_18AE28(c); if (e == 0) return 0; func_002DCE40_18AE28(buf, D_004A3658_18AE28, &D_004A3630_18AE28); fd = func_002E9950_18AE28(buf, 1); if (fd < 0) { func_001118F8_18AE28(D_004401A8_18AE28, buf); return 0; } func_002E9D58_18AE28(fd, e[3] << 11, 0); size = (unsigned)*(unsigned short *)((char *)e + 10) << 11; p = func_00162130_18AE28(size, D_00440120_18AE28, 1090); if (p == 0) { func_001118F8_18AE28(D_004401C8_18AE28, buf); return 0; } func_002E9F90_18AE28(fd, p, size); if (psize != 0) *psize = size; func_002E9BD8_18AE28(fd); return p; }

extern int D_004A3620_18A798 __asm__("D_004A3620");
int file_0018a298_18A798(int *) __asm__("file_0018a298"); int file_0018a300_18A798(int, int) __asm__("file_0018a300"); int file_0018a3d0_18A798(int, int, int) __asm__("file_0018a3d0");
// MATCH func_0018A798
int file_0018a798(int a, int b, int c) { int s[4]; int p; int r; s[0] = a; if (D_004A3620_18A798 == 0) return 0; p = D_004A3620_18A798 + *(unsigned short *)(D_004A3620_18A798 + 6); for (;;) { r = file_0018a298_18A798(s); if (s[0] == 0) break; p = file_0018a300_18A798(p, r); if (p == 0) return 0; __asm__ volatile ("" : : "r"(c)); } return file_0018a3d0_18A798(p, b, c); }

extern int D_004A3620_18A708 __asm__("D_004A3620");
void *file_0018a1c8_18A708(void) __asm__("file_0018a1c8"); int file_0018a218_18A708(char *) __asm__("file_0018a218"); int file_0018a298_18A708(int *) __asm__("file_0018a298"); int file_0018a300_18A708(int, int) __asm__("file_0018a300"); int file_0018a358_18A708(int, int, int) __asm__("file_0018a358");
// MATCH func_0018A708
int file_0018a708(int a) { int s[4]; int p, r, l; p = D_004A3620_18A708; s[0] = a; if (p == 0) return 0; l = file_0018a218_18A708(file_0018a1c8_18A708()); if (l < 0) return 0; p += *(unsigned short *)(p + 6); for (;;) { r = file_0018a298_18A708(s); if (s[0] == 0) break; p = file_0018a300_18A708(p, r); if (p == 0) return 0; } return file_0018a358_18A708(p, r, l); }

