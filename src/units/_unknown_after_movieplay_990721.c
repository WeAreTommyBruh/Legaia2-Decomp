/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

// compiler: 990721-r5900
extern int D_004A11C8;
extern int D_004A1628;
extern int D_004A163C;
extern char D_00343028[];
extern char D_00321320[];
void func_002CC0E0(int);
int func_002CB958(void *, void *);
void func_0018EA38(void);
void func_0010E428(void *);
void func_002CCC70(void);
void func_002E5D30(void);
void func_002CBB80(int);
void func_00113BB0(void);
int func_002E5790(void);
int func_002E5730(int, int);
void func_002BF848(void);
void func_002CEA70(int);
void func_002BF6A8(int, int, int, int);
void func_00194A68(int, int, int, int, int);
void func_002BFFA8(void *, int, int, int, int, int, int);
void func_002E5B20(int);
void func_00114310(void *);
void func_002C0338(int, int);
void func_002A1988(void);
void func_001976B8(void);
void func_002E63E8(int);
void func_0010A120(void *, int);
void func_00109C68(void *);
void func_002C02A0(int);
void func_0017A388(void);
void func_00113CD8(void);
// MATCH func_00113EC8
int FUN_00113ec8(char *name) { char buf[48]; int i; volatile unsigned *r; func_002CC0E0(0); if (func_002CB958(buf, name) == 0) { return -1; } i = 15; func_0018EA38(); func_0010E428(D_00343028); func_002CCC70(); do { i--; func_002E5D30(); } while (i >= 0); func_002CBB80(0); func_00113BB0(); func_002E5730(func_002E5790(), 3); D_004A1628 = 0; D_004A163C = D_004A11C8; func_002BF848(); func_002CEA70(1); func_002BF6A8(0, 1, 3, 1); func_00194A68(0, 0, 0, 640, 512); func_002BFFA8(D_00321320, 0, 640, 256, 0, 0, 1); func_002E5B20(0); func_002E5D30(); func_00114310(name); func_002E5D30(); func_00194A68(0, 0, 0, 640, 512); func_002E5B20(0); func_002C0338(0, 0); r = (volatile unsigned *) 0x10009000; do { *r = (*r) & 0x100; } while ((*r) != 0); func_002A1988(); func_001976B8(); func_002E5730(func_002E5790(), 10); func_002E63E8(3); func_0010A120(D_00343028, 99); func_00109C68(D_00343028); func_002E5B20(0); func_002BF848(); func_002C02A0(0); func_0017A388(); func_002E5B20(0); func_002E5D30(); func_00113CD8(); return 0; }

