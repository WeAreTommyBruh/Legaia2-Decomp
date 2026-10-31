/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_004A3658[];
void *func_002DD1DC(void *, int); void func_002DCE40(void *, void *, void *);
// MATCH func_0018BAE8
void FUN_0018bae8(char *a, char *b) { char *r = func_002DD1DC(b, 58); if (r == 0) r = b; else r++; func_002DCE40(a, D_004A3658, r); }

extern int D_004A3850_0018B3A8 __asm__("D_004A3850"); extern char D_00440230[]; extern char D_00440248[]; extern char D_00440260[]; extern char D_00440280[]; extern char D_004402A0[]; void func_001118F8_0018B3A8(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018ABF0(char *, int); int func_0018AF40(char *, int); int func_0018A918(char *, int);
// MATCH func_0018B3A8
int MallocLoadFileNB(char *name, int b) { char buf[256]; int r = 0; switch (D_004A3850_0018B3A8) { case 0: func_001118F8_0018B3A8(D_00440230, name); r = func_0018A918(name, b); break; case 1: func_001118F8_0018B3A8(D_00440248, name); func_0018A658(name, buf); r = func_0018ABF0(buf, b); break; case 2: func_001118F8_0018B3A8(D_00440260, name); func_0018A658(name, buf); r = func_0018AF40(buf, b); break; case 3: func_001118F8_0018B3A8(D_00440248, name); func_0018A658(name, buf); r = func_0018ABF0(buf, b); if (r == 0) r = func_0018A918(buf, b); break; default: func_001118F8_0018B3A8(D_00440280, name); break; } if (r == 0) func_001118F8_0018B3A8(D_004402A0, name); return r; }

extern int D_004A3850_0018B508 __asm__("D_004A3850"); extern char D_004402C0[]; extern char D_004402D8[]; extern char D_00440300[]; extern char D_00440318[]; extern char D_00440330[]; extern char D_00440350[]; void func_001118F8_0018B508(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018AAF0(char *, int); int func_0018AE28(char *, int); int func_0018A828(char *, int);
// MATCH func_0018B508
int FUN_0018b508(char *name, int b) { char buf[256]; int r = 0; switch (D_004A3850_0018B508) { case 0: func_001118F8_0018B508(D_004402C0, name); r = func_0018A828(name, b); break; case 1: func_001118F8_0018B508(D_004402D8, name); func_0018A658(name, buf); r = func_0018AAF0(buf, b); break; case 2: func_001118F8_0018B508(D_00440300, name); func_0018A658(name, buf); r = func_0018AE28(buf, b); break; case 3: func_001118F8_0018B508(D_00440318, name); func_0018A658(name, buf); r = func_0018AAF0(buf, b); if (r == 0) r = func_0018A828(buf, b); break; default: func_001118F8_0018B508(D_00440330, name); break; } if (r == 0) func_001118F8_0018B508(D_00440350, name); return r; }

extern int D_004A3850_0018B668 __asm__("D_004A3850"); extern char D_00440370[]; extern char D_00440388[]; extern char D_004403A0[]; extern char D_004403B8[]; extern char D_004403D0[]; void func_001118F8_0018B668(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018AD80(char *, int); int func_0018B0F0(char *, int); int func_0018AAB0(char *, int);
// MATCH func_0018B668
int FUN_0018b668(char *name, int b) { char buf[256]; int r = -1; switch (D_004A3850_0018B668) { case 0: func_001118F8_0018B668(D_00440370, name); r = func_0018AAB0(name, b); break; case 1: func_001118F8_0018B668(D_00440388, name); func_0018A658(name, buf); r = func_0018AD80(buf, b); break; case 2: func_001118F8_0018B668(D_004403A0, name); func_0018A658(name, buf); r = func_0018B0F0(buf, b); break; case 3: func_001118F8_0018B668(D_00440388, name); func_0018A658(name, buf); r = func_0018AD80(buf, b); if (r < 0) r = func_0018AAB0(buf, b); break; default: func_001118F8_0018B668(D_004403B8, name); break; } if (r < 0) func_001118F8_0018B668(D_004403D0, name); return r; }

extern int D_004A3850_0018B7C8 __asm__("D_004A3850"); extern char D_004403E8[]; extern char D_004403F8[]; extern char D_00440420[]; extern char D_00440438[]; extern char D_00440448[]; extern char D_00440460[]; void func_001118F8_0018B7C8(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018ACF0(char *, int); int func_0018B020(char *, int); int func_0018AA00(char *, int);
// MATCH func_0018B7C8
int LoadFile(char *name, int b) { char buf[256]; int r = -1; switch (D_004A3850_0018B7C8) { case 0: func_001118F8_0018B7C8(D_004403E8, name); r = func_0018AA00(name, b); break; case 1: func_001118F8_0018B7C8(D_004403F8, name); func_0018A658(name, buf); r = func_0018ACF0(buf, b); break; case 2: func_001118F8_0018B7C8(D_00440420, name); func_0018A658(name, buf); r = func_0018B020(buf, b); break; case 3: func_001118F8_0018B7C8(D_00440438, name); func_0018A658(name, buf); r = func_0018ACF0(buf, b); if (r < 0) r = func_0018AA00(buf, b); break; default: func_001118F8_0018B7C8(D_00440448, name); break; } if (r < 0) func_001118F8_0018B7C8(D_00440460, name); return r; }

extern int D_004A3850_0018B2F8 __asm__("D_004A3850"); int func_0018B250(int);
// MATCH func_0018B2F8
int FUN_0018b2f8(int a) { int r = -1; if (D_004A3850_0018B2F8 != 0) { if (D_004A3850_0018B2F8 >= 0) { if (D_004A3850_0018B2F8 < 4) r = func_0018B250(a); } } return r; }

int func_0018B7C8(void *, int);
// MATCH func_0018B928
int FUN_0018b928(char *name, int buf, int *size) { int r = func_0018B7C8(name, buf); if (r < 0) return 0; if (size) *size = r; return buf; }

extern char D_004401A8[]; void func_0018BAE8(char *, char *); int func_002E9950(char *, int); int func_002E9D58(int, int, int); void func_002E9BD8(int);
// MATCH func_0018B180
int FUN_0018b180(char *name) { char buf[256]; int fd, n; if (name == 0) return -1; func_0018BAE8(buf, name); fd = func_002E9950(buf, 1); if (fd < 0) return -1; n = func_002E9D58(fd, 0, 2); n = (n + 2047) & -2048; func_002E9BD8(fd); return n; }

extern char D_004401A8_0018BA38[] __asm__("D_004401A8"), D_00440478[]; void func_0018BAE8(char *, char *); int func_002E9950(char *, int); int func_002E9D58(int, int, int); int func_002EA200(int, void *, int); void func_002E9BD8(int); void func_001118F8_0018BA38(char *, ...) __asm__("func_001118F8");
// MATCH func_0018BA38
int FUN_0018ba38(char *name, void *src, int n) { char buf[256]; int fd; func_0018BAE8(buf, name); fd = func_002E9950(buf, 514); if (fd < 0) { func_001118F8_0018BA38(D_004401A8_0018BA38, buf); return 0; } func_002E9D58(fd, 0, 2); if (func_002EA200(fd, src, n) < 0) { func_001118F8_0018BA38(D_00440478, buf); return 0; } func_002E9BD8(fd); return 1; }

extern char D_004401A8_0018B998[] __asm__("D_004401A8"), D_00440478_0018B998[] __asm__("D_00440478"); void func_0018BAE8(char *, char *); int func_002E9950(char *, int); int func_002EA200(int, void *, int); void func_002E9BD8(int); void func_001118F8_0018B998(char *, ...) __asm__("func_001118F8");
// MATCH func_0018B998
int FUN_0018b998(char *name, void *src, int n) { char buf[256]; int fd; func_0018BAE8(buf, name); fd = func_002E9950(buf, 1538); if (fd < 0) { func_001118F8_0018B998(D_004401A8_0018B998, buf); return 0; } if (func_002EA200(fd, src, n) < 0) { func_001118F8_0018B998(D_00440478_0018B998, buf); return 0; } func_002E9BD8(fd); return 1; }

extern int D_004A3630; extern char D_004A3658_0018B0F0[] __asm__("D_004A3658"); char *func_002DD1DC_0018B0F0(char *, int) __asm__("func_002DD1DC"); char *func_0018A708(char *); int func_002DCE40_0018B0F0(char *, char *, ...) __asm__("func_002DCE40"); void func_0010FEB0(char *, int, int, int);
// MATCH func_0018B0F0
int FUN_0018b0f0(char *name, int a) { char buf[256]; char *p, *e; int n; p = func_002DD1DC_0018B0F0(name, 58); if (p == 0) p = name; else p++; e = func_0018A708(p); func_002DCE40_0018B0F0(buf, D_004A3658_0018B0F0, &D_004A3630); n = ((unsigned short *)e)[5] << 11; func_0010FEB0(buf, a, ((int *)e)[3] << 11, n); return n; }

extern int D_004A3630_0018B020 __asm__("D_004A3630"); extern char D_004A3658_0018B020[] __asm__("D_004A3658"), D_004401A8_0018B020[] __asm__("D_004401A8"); char *func_002DD1DC_0018B020(char *, int) __asm__("func_002DD1DC"); int *func_0018A708_0018B020(char *) __asm__("func_0018A708"); int func_002DCE40_0018B020(char *, char *, ...) __asm__("func_002DCE40"); int func_002E9950(char *, int); int func_002E9D58(int, int, int); int func_002E9F90_0018B020(int, void *, int) __asm__("func_002E9F90"); void func_002E9BD8(int); void func_001118F8_0018B020(char *, ...) __asm__("func_001118F8");
// MATCH func_0018B020
int FUN_0018b020(char *name, void *dst) { char buf[256]; char *p; int *e; int fd, n; p = func_002DD1DC_0018B020(name, 58); if (p == 0) p = name; else p++; e = func_0018A708_0018B020(p); func_002DCE40_0018B020(buf, D_004A3658_0018B020, &D_004A3630_0018B020); fd = func_002E9950(buf, 1); if (fd < 0) { func_001118F8_0018B020(D_004401A8_0018B020, buf); return -1; } func_002E9D58(fd, e[3] << 11, 0); n = ((unsigned short *)e)[5] << 11; func_002E9F90_0018B020(fd, dst, n); func_002E9BD8(fd); return n; }
