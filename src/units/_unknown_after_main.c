/* Functions of this report unit, matched by hand. */
#include "../common.h"

int func_001128E0(void *); int func_001129A0(void *, int);
// MATCH func_00112A90
int FUN_00112a90(void *o) { int r = func_001128E0(o); if (r >= 0) return func_001129A0(o, r); return 0; }

extern char D_004A1590[]; int func_002DCE40_00112D88(char *, char *, ...) __asm__("func_002DCE40"); int func_002E9950(char *, int); int func_002E9D58(int, int, int); void func_002E9BD8(int);
// MATCH func_00112D88
int FUN_00112d88(char *name) { char buf[256]; int fd, r; if (name == 0) return -1; func_002DCE40_00112D88(buf, D_004A1590, name); fd = func_002E9950(buf, 1); if (fd < 0) return -1; r = func_002E9D58(fd, 0, 2); func_002E9BD8(fd); return r; }

extern char D_004A1590_00112E00[] __asm__("D_004A1590"), D_0042F100[]; int func_002DCE40_00112E00(char *, char *, ...) __asm__("func_002DCE40"); int func_002E9950(char *, int); int func_002E9D58(int, int, int); int func_002E9F90_00112E00(int, void *, int) __asm__("func_002E9F90"); void func_002E9BD8(int); void func_001118F8_00112E00(char *, ...) __asm__("func_001118F8");
// MATCH func_00112E00
int FUN_00112e00(char *name, void *dst) { char buf[256]; int fd, n; func_002DCE40_00112E00(buf, D_004A1590_00112E00, name); fd = func_002E9950(buf, 1); if (fd < 0) { func_001118F8_00112E00(D_0042F100, buf); return -1; } n = func_002E9D58(fd, 0, 2); func_002E9D58(fd, 0, 0); func_002E9F90_00112E00(fd, dst, n); func_002E9BD8(fd); return n; }

extern char D_00320900[]; int func_002C9C08(int, int, char *);
// MATCH func_00113830
void FUN_00113830(char *o, int i) { char *s0 = o + 72; int *s = (int *)(s0 + i * 4); char *q; *s = 0; if (func_002C9C08(i, 0, D_00320900 + (i << 6)) == 0) *s = 1; q = o + i * 4; *(int *)(q + 64) = (unsigned char)(D_00320900 + (i << 6))[1]; }

extern char D_002F9800[], D_0042EEC8_00111CA8[] __asm__("D_0042EEC8"); extern int D_00314C20_00111CA8[] __asm__("D_00314C20"), D_00314C48[], D_00314C70[], D_00315E00_00111CA8[] __asm__("D_00315E00"); extern char D_00315D88[]; void func_00245E10(char *); int func_00113028(char *);
// MATCH func_00111CA8
int FUN_00111ca8(void) { int i; char *e = D_002F9800; char *p; int v, r; p = e + 1056; for (i = 255; i != -1; i--) { func_00245E10(p); p += 432; } v = (int)D_0042EEC8_00111CA8; D_00314C20_00111CA8[6] = v; D_00314C48[6] = v; D_00314C70[6] = v; r = func_00113028(D_00315D88); D_00315E00_00111CA8[2566] = v; return r; }

typedef struct { int a, f4, c, d, e, f, g, h, i; } E_00112AD0;
typedef struct { int x0, x1, n, x3; E_00112AD0 e[1]; } H_00112AD0;
// MATCH func_00112AD0
int *FUN_00112ad0(H_00112AD0 **p, int k) { H_00112AD0 *h = *p; E_00112AD0 *e = h->e; if (h->n <= k) return 0; return &e[k].f4; }

extern char D_0042F060_1128E0[] __asm__("D_0042F060"), D_0042F070_1128E0[] __asm__("D_0042F070"), D_0042F080_1128E0[] __asm__("D_0042F080"); void func_001118F8_1128E0(char *, ...) __asm__("func_001118F8"); int func_002DD36C_1128E0(char *, char *) __asm__("func_002DD36C");
// MATCH func_001128E0
int FUN_001128e0(int **a, char *name) { int *o; int i; register char *p __asm__("$17"); if (name == 0) { func_001118F8_1128E0(D_0042F060_1128E0); return -1; } if (*name == 0) { func_001118F8_1128E0(D_0042F070_1128E0); return -1; } o = *a; func_001118F8_1128E0(D_0042F080_1128E0, name, o[2]); i = 0; __asm__ volatile ("" : : "r"(i)); p = (char *)o + 20; { register int count __asm__("$3") = o[2]; if (count > 0) { do { if (func_002DD36C_1128E0(name, p) == 0) return i; i++; p += 36; } while (i < o[2]); } } return -1; }
