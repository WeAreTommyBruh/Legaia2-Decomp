#include "../common.h"
// compiler: 991111-01
// cflags:
typedef unsigned long u_long; typedef int u128 __attribute__((mode(TI)));
typedef struct { u_long NLOOP:15; u_long EOP:1; u_long pad16:16; u_long id:14; u_long PRE:1; u_long PRIM:11; u_long FLG:2; u_long NREG:4; u_long REGS0:4; u_long REGS1:4; u_long REGS2:4; u_long REGS3:4; u_long REGS4:4; u_long REGS5:4; u_long REGS6:4; u_long REGS7:4; u_long REGS8:4; u_long REGS9:4; u_long REGS10:4; u_long REGS11:4; u_long REGS12:4; u_long REGS13:4; u_long REGS14:4; u_long REGS15:4; } __attribute__((aligned(16))) GifTag;
typedef struct { char pad[80]; GifTag tag; char env[32]; long f128; } DB;
extern DB D_00321320;
extern char D_00440F58[];
typedef union { u_long l[2]; u128 q; } Q; extern Q D_00440F48;
void *func_00162130(int, char *, int); void func_001621F8(void *, char *, int);
int func_002CEA48(int); void func_002E5B20(int); void func_002C0338(int, int); void func_002BFEC0(void *);
void func_002BFCD8(void *, int, int, int, int, int);
void func_002CF138(void *, void *); void func_002CF148(void *); void func_002CF2C0(void *, int, int, int);
void func_002CF350(void *, u128); void func_002CF410(void *, int, u_long); void func_002CF368(void *); void func_002CF158(void *);
void func_002CED78(int, int);
// MATCH func_00194A68
void mp_disp_00194a68(int r, int g, int b, int w, int h) { Q c = D_00440F48; struct { int a; int b; char rest[8]; } buf; void *p; int k; p = func_00162130(0x60, D_00440F58, 697); k = func_002CEA48(2); *(u128 *)&D_00321320.tag = 0; __asm__ volatile ("sync"); D_00321320.tag.NLOOP = 8; D_00321320.tag.EOP = 1; D_00321320.tag.NREG = 1; D_00321320.tag.REGS0 = 0xe; func_002BFCD8(D_00321320.env, 0, (short)w, (short)(((h / 2 + 31) / 32 + (h + 31) / 32) * 64), 0, 0); D_00321320.f128 = 0; func_002E5B20(0); func_002C0338(0, 0); func_002BFEC0(&D_00321320.tag); func_002CF138(&buf, p); func_002CF148(&buf); func_002CF2C0(&buf, 0, 0, 0); func_002CF350(&buf, c.q); func_002CF410(&buf, 0, 6); func_002CF410(&buf, 1, (u_long)r | (u_long)g << 8 | (u_long)b << 16); func_002CF410(&buf, 5, 0); func_002CF410(&buf, 5, 0xb4002d00); func_002CF368(&buf); func_002CF158(&buf); func_002E5B20(0); func_002C0338(0, 0); func_002CED78(k, buf.b); func_002C0338(0, 0); func_001621F8(p, D_00440F58, 746); }
