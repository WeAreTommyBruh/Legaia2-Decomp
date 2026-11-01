/* Functions of this report unit, matched by hand. */
#include "../common.h"
typedef char *va_list;

typedef struct { char p[112]; int a; long long b; } P_002C2DD0;
typedef struct { char p[64]; P_002C2DD0 *q; } O_002C2DD0;
// MATCH func_002C2DD0
void FUN_002c2dd0(O_002C2DD0 *o, long long v) { o->q->a = 1; o->q->b = v; }

extern char D_0062F600[];
// MATCH func_002CFFC0
char *FUN_002cffc0(int a, int b) { return D_0062F600 + (a << 12) + (b << 4); }

// MATCH func_002CADD8
int FUN_002cadd8(void) { int *p = (int *)0x10003820; __asm__("" : "+r"(p)); return *p; }

// MATCH func_002CED60
int FUN_002ced60(int a) { int *p = (int *)0x1000e060; __asm__("" : "+r"(p)); { int r = *p; *p = a; return r; } }

// MATCH func_002CE9E8
unsigned FUN_002ce9e8(unsigned a) { unsigned r = a; if ((a >> 28) == 7) { r = a & 0xfffffff; r |= 0x80000000; } return r; }

typedef struct { char p[384]; int w[16]; } P_002D5568;
P_002D5568 *func_002CFFB0(void);
// MATCH func_002D5568
int FUN_002d5568(unsigned a) { int r = 0; if (a < 16) r = func_002CFFB0()->w[a]; return r; }

void func_0029FDE8(float, float, float, float, float, float);
// MATCH func_002BEE90
void FUN_002bee90(float a, float b, float c) { func_0029FDE8(a, b, c, 0.0f, 0.0f, 0.0f); }

void func_0029FDE8(float, float, float, float, float, float);
// MATCH func_002BEE78
void FUN_002bee78(float a) { func_0029FDE8(a, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f); }

void func_002BEE90(void *, int, int, int, float, float, float);
// MATCH func_002BEE38
void FUN_002bee38(void *s, float a, int b) { func_002BEE90(s, 15, b, 0, 0.0f, a, 0.0f); }

void func_002BEE90(void *, int, int, int, float, float, float);
// MATCH func_002BEE58
void FUN_002bee58(void *s) { func_002BEE90(s, 44, 0, 0, 0.0f, 0.0f, 0.0f); }

typedef struct { long long *p; } W_002CF410;
// MATCH func_002CF410
void FUN_002cf410(W_002CF410 *w, unsigned a, long long b) { long long *p = w->p; *p = b; p++; *p = (long long)a; p++; w->p = p; }

extern int D_00426300[]; extern unsigned char D_0049DF50[]; void func_002DD4CC_002C9D00(void *, int) __asm__("func_002DD4CC");
// MATCH func_002C9D00
void FUN_002c9d00(unsigned i, unsigned char *d) { if (i < 8) func_002DD4CC_002C9D00(d, D_00426300[i]); else *d = D_0049DF50[0]; }

extern int D_00426320[]; extern unsigned char D_0049DF50_002C9DF0[] __asm__("D_0049DF50"); void func_002DD4CC_002C9DF0(void *, int) __asm__("func_002DD4CC");
// MATCH func_002C9DF0
void FUN_002c9df0(unsigned i, unsigned char *d) { if (i < 4) func_002DD4CC_002C9DF0(d, D_00426320[i]); else *d = D_0049DF50_002C9DF0[0]; }

// MATCH func_002BC8F8
float FUN_002bc8f8(float a, float b) { if (a > 0.0f) { if (a > b) a = b; } else { b = -b; if (a < b) a = b; } return a; }

typedef struct { char pad[12]; float a, b, c; } S_2bec78_002BEC78;
void func_002A74F8(void *); void func_002A71F8(void *);
// MATCH func_002BEC78
void FUN_002bec78(S_2bec78_002BEC78 *s, float x, float y, float z) { s->a = x; s->b = y; s->c = z; func_002A74F8(s); func_002A71F8(s); }

typedef struct { char pad[64]; int a64; } S_2c2b28_002C2B28;
void func_002C3620(int, int, int);
// MATCH func_002C2B28
void FUN_002c2b28(S_2c2b28_002C2B28 *s, int a, int n) { func_002C3620(s->a64, a, ((n + 19) / 16) * 16); }

// MATCH func_002C5C38
void FUN_002c5c38(int a) { unsigned *p = (unsigned *)0x10002010; *p = (*p & 0xff7fffff) | (a << 23); }

extern unsigned D_00426280[];
typedef struct { char pad[2072]; unsigned v; } S_2c6e20_002C6E20;
// MATCH func_002C6E20
void FUN_002c6e20(S_2c6e20_002C6E20 *s, unsigned b) { *(volatile unsigned *)0x10002000 = b; s->v = D_00426280[b >> 28]; }

typedef struct { char pad[30]; unsigned short h; } S_2d46b0_002D46B0;
void *func_002CFF20(unsigned);
// MATCH func_002D46B0
int FUN_002d46b0(unsigned n) { int r = -1; if (n < 48) r = ((S_2d46b0_002D46B0 *)func_002CFF20(n))->h; return r; }

typedef struct { char pad[81]; unsigned char b; } S_2d4fe0_002D4FE0;
void *func_002CFF08(unsigned);
// MATCH func_002D4FE0
int FUN_002d4fe0(unsigned n) { if (n < 48) { S_2d4fe0_002D4FE0 *p = (S_2d4fe0_002D4FE0 *)func_002CFF08(n); if (p->b == 3) p->b = 0; } return -1; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5448
int FUN_002d5448(long a) { if ((a & 0xff000000) == 0) func_002D04C0(75, (int)a, 0, 0); return 0; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5488
int FUN_002d5488(long a) { if ((a & 0xff000000) == 0) func_002D04C0(76, (int)a, 0, 0); return 0; }

int func_002DA4E0(int, int, int);
// MATCH func_002DA588
int FUN_002da588(int a, int b, int c, int d) { if (func_002DA4E0(a, b, c) == 0) d = 0; return d; }

long func_002DDD90(char *, char **, int);
// MATCH func_002DB920
int FUN_002db920(char *a) { return func_002DDD90(a, 0, 10); }

int func_002E5CB0(int); void func_002E5D20(void);
// MATCH func_002EDB08
int FUN_002edb08(void) { if (func_002E5CB0(4) & 0x40000) { func_002E5D20(); return 1; } return 0; }

void func_002EE200(int); void func_002E54C0(int);
// MATCH func_002EE2C0
void FUN_002ee2c0(int a) { func_002EE200(a); func_002E54C0(a); }

void func_002E5CD0(int, void *);
// MATCH func_002E6970
void FUN_002e6970(int a, signed char b) { struct { int a, b; } t; t.a = a; t.b = b; func_002E5CD0(3, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E69C8
void FUN_002e69c8(int a, int b, unsigned short c) { struct { int a, b, c; } t; t.a = a; t.b = b; t.c = c; func_002E5CD0(-5, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E6A00
void FUN_002e6a00(int a, int b, unsigned short c) { struct { int a, b, c; } t; t.a = a; t.b = b; t.c = c; func_002E5CD0(-6, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E6A38
void FUN_002e6a38(int a, signed char b) { struct { int a, b; } t; t.a = a; t.b = b; func_002E5CD0(-7, &t); }

extern int D_00427DC8[];
int func_002CD428(int, int, int, int);
// MATCH func_002CD560
int FUN_002cd560(int a, int b, int c) { int r = func_002CD428(a, b, c, 64); if (r == 0) D_00427DC8[0] = 11; return r; }

extern void (*D_00427EF4[])(void);
// MATCH func_002D62C8
void FUN_002d62c8(void) { D_00427EF4[0](); }

extern void (*D_00427EF8[])(void); void func_002D63F8(void);
// MATCH func_002D63D0
void FUN_002d63d0(void) { (D_00427EF8[0] = func_002D63F8)(); }

extern int D_004A7418[]; extern char D_0049E6B8[];
void func_002DA568(void *, void *);
// MATCH func_002D8860
int *FUN_002d8860(void) { if (D_004A7418[0] == 0) func_002DA568(D_004A7418, D_0049E6B8); return D_004A7418; }

extern int D_004A7420[]; extern char D_0049E8A0[];
void func_002DA568(void *, void *);
// MATCH func_002DAB40
int *FUN_002dab40(void) { if (D_004A7420[0] == 0) func_002DA568(D_004A7420, D_0049E8A0); return D_004A7420; }

int func_002E5CB0(int);
// MATCH func_002EDAE0
int FUN_002edae0(void) { return (func_002E5CB0(4) & 0x10000) > 0; }

typedef struct { int a0, a4, a8, a12, tail; } S_2e6ae0_002E6AE0;
extern S_2e6ae0_002E6AE0 D_00632340;
// MATCH func_002E6AE0
S_2e6ae0_002E6AE0 *FUN_002e6ae0(int a) { S_2e6ae0_002E6AE0 *s = &D_00632340; int *t = &s->tail;
s->a4 = 0;
s->a12 = (int)t;
s->a8 = (int)t;
s->a0 = a;
return s; }

extern void (*D_0062B644[])(int); extern int D_0062B648[], D_00426364[];
// MATCH func_002CB588
void FUN_002cb588(void) { void (*cb)(int) = D_0062B644[0]; if (cb != 0 && D_00426364[0] == 0) cb(D_0062B648[0]); }

int func_002EE6B0(int);
// MATCH func_002EE6C0
int FUN_002ee6c0(int a) { if ((unsigned)(a - 13) >= 35) return -1; return func_002EE6B0(a); }

typedef struct { char pad[68]; int a68; } P_2d38a0_002D38A0;
extern char D_00631A80[];
void *func_002CFF38(void); int func_002E8B18(void *);
// MATCH func_002D38A0
int FUN_002d38a0(void) { int r = 0; if (((P_2d38a0_002D38A0 *)func_002CFF38())->a68 != 0) r = func_002E8B18(D_00631A80); return r; }

typedef struct { int a0, a4, a8; char *a12; } R_2e6b08_002E6B08;
// MATCH func_002E6B08
void FUN_002e6b08(R_2e6b08_002E6B08 *s) { char *p; s->a4 = s->a4 + 1; p = s->a12 + 1; s->a12 = p; if (p == (char *)s + (s->a0 + 16)) s->a12 = (char *)s + 16; }

typedef struct { int a0, a4; char *a8; } R_2e6b48_002E6B48;
// MATCH func_002E6B48
void FUN_002e6b48(R_2e6b48_002E6B48 *s) { char *p; s->a4 = s->a4 - 1; p = s->a8 + 1; s->a8 = p; if (p == (char *)s + (s->a0 + 16)) s->a8 = (char *)s + 16; }

void func_002ECE08(int, int, int, void *);
// MATCH func_002ED3D8
void FUN_002ed3d8(int a, int b, int c) { int x[4]; func_002ECE08(a, b, c, x); }

extern int D_004A7428[];
int func_002E5E68(int, int, int);
// MATCH func_002E0328
int FUN_002e0328(int *e, int p0, int p1, int p2) { int r; D_004A7428[0] = 0; r = func_002E5E68(p0, p1, p2); if (r == -1 && D_004A7428[0] != 0) *e = D_004A7428[0]; return r; }

extern int D_004A7428_002E4E90[] __asm__("D_004A7428");
int func_002E6058(int, int);
// MATCH func_002E4E90
int FUN_002e4e90(int *e, int p0, int p1) { int r; D_004A7428_002E4E90[0] = 0; r = func_002E6058(p0, p1); if (r == -1 && D_004A7428_002E4E90[0] != 0) *e = D_004A7428_002E4E90[0]; return r; }

extern int D_004A7428_002DCD58[] __asm__("D_004A7428");
int func_002E6078(int, int);
// MATCH func_002DCD58
int FUN_002dcd58(int *e, int p0, int p1) { int r; D_004A7428_002DCD58[0] = 0; r = func_002E6078(p0, p1); if (r == -1 && D_004A7428_002DCD58[0] != 0) *e = D_004A7428_002DCD58[0]; return r; }

extern int D_004A7428_002DC9A8[] __asm__("D_004A7428");
unsigned func_002E5FA0(int);
// MATCH func_002DC9A8
unsigned FUN_002dc9a8(int *e, int p0) { unsigned r; D_004A7428_002DC9A8[0] = 0; r = func_002E5FA0(p0); if (r == 0xffffffff && D_004A7428_002DC9A8[0] != 0) *e = D_004A7428_002DC9A8[0]; return r; }

void func_002E5640(void);
// MATCH func_002E6520
void FUN_002e6520(void) { func_002E5640(); __asm__ volatile("sync"); }

void func_002E5650(void);
// MATCH func_002E6540
void FUN_002e6540(void) { func_002E5650(); __asm__ volatile("sync"); }

void func_002E5660(void);
// MATCH func_002E6560
void FUN_002e6560(void) { func_002E5660(); __asm__ volatile("sync"); }

void func_002E5670(void);
// MATCH func_002E6580
void FUN_002e6580(void) { func_002E5670(); __asm__ volatile("sync"); }

void func_002ED418(int, int, int, void *, int);
// MATCH func_002ED640
void FUN_002ed640(int a, int b, int c) { int x[4]; func_002ED418(a, b, c, x, 0); }

void func_002D7580(void *, void *); void *func_002D7620(void *, void *, void *); long func_002D7450(void *);
// MATCH func_002D7860
long __adddf3(long a, long b) { int x[8]; int y[8]; int r[8]; func_002D7580(&a, x); func_002D7580(&b, y); return func_002D7450(func_002D7620(x, y, r)); }

void func_002D7580(void *, void *); void *func_002D7620(void *, void *, void *); long func_002D7450(void *);
// MATCH func_002D78B8
long __subdf3(long a, long b) { int x[8]; int y[8]; int r[8]; func_002D7580(&a, x); func_002D7580(&b, y); y[1] ^= 1; return func_002D7450(func_002D7620(x, y, r)); }

void func_002D89B0(void *, void *); int func_002D9090(void *, void *);
// MATCH func_002D91A8
int FUN_002d91a8(float a, float b) { int x[4]; int y[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); return func_002D9090(x, y); }

void func_002D89B0(void *, void *); void *func_002D8A40(void *, void *, void *); float func_002D88A0(void *);
// MATCH func_002D8C78
float FUN_002d8c78(float a, float b) { int x[4]; int y[4]; int r[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); return func_002D88A0(func_002D8A40(x, y, r)); }

void func_002D89B0(void *, void *); void *func_002D8A40(void *, void *, void *); float func_002D88A0(void *);
// MATCH func_002D8CD0
float FUN_002d8cd0(float a, float b) { int x[4]; int y[4]; int r[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); y[1] ^= 1; return func_002D88A0(func_002D8A40(x, y, r)); }

int func_002D3B98(void *, int); void func_002D39B0(int, int, int);
// MATCH func_002D3B28
int FUN_002d3b28(int a, int *b, int c) { int r = func_002D3B98(b, c); if (r != -1) func_002D39B0(a, c, b[1]); return r; }

int func_002E5790(void); void func_002E5620(int, void *, int); void func_002E57C0(void); void func_002CDA58(void);
// MATCH func_002CDA80
void FUN_002cda80(unsigned a) { func_002E5620(a & 0xffff, func_002CDA58, func_002E5790()); func_002E57C0(); }

void func_002D7580(void *, void *); long func_002D7450_002D8088(void *) __asm__("func_002D7450");
// MATCH func_002D8088
long FUN_002d8088(long a) { int x[8]; func_002D7580(&a, x); x[1] = x[1] == 0; return func_002D7450_002D8088(x); }

void func_002D89B0(void *, void *); float func_002D88A0_002D93D8(void *) __asm__("func_002D88A0");
// MATCH func_002D93D8
float FUN_002d93d8(float a) { int x[4]; func_002D89B0(&a, x); x[1] = x[1] == 0; return func_002D88A0_002D93D8(x); }

long func_002D7450_002D80C0(void *) __asm__("func_002D7450");
// MATCH func_002D80C0
long __make_dp(int cls, int sign, int exp, long frac) { struct { int c, s, e, p; long f; } x; x.c = cls; x.s = sign; x.e = exp; x.f = frac; return func_002D7450_002D80C0(&x); }

float func_002D88A0_002D9410(void *) __asm__("func_002D88A0");
// MATCH func_002D9410
float FUN_002d9410(int cls, int sign, int exp, int frac) { int x[4]; x[0] = cls; x[1] = sign; x[2] = exp; x[3] = frac; return func_002D88A0_002D9410(x); }

// MATCH func_002D94C8
unsigned char *FUN_002d94c8(unsigned char *p, int *val) { unsigned shift = 0; unsigned char byte; int result = 0; do { byte = *p++; result |= (int)(byte & 0x7f) << shift; shift += 7; } while (byte & 0x80); if (shift < 32 && (byte & 0x40) != 0) result |= -(1 << shift); *val = result; return p; }

void func_002D89B0(void *, void *); long func_002D80C0(int, int, int, long);
// MATCH func_002D9440
long __extendsfdf2(float a) { int x[4]; func_002D89B0(&a, x); return func_002D80C0(x[0], x[1], x[2], (unsigned long)(unsigned)x[3] << 30); }

// MATCH func_002D9480
unsigned char *FUN_002d9480(unsigned char *p, unsigned *val) { unsigned shift = 0; unsigned char byte; unsigned result; byte = *p++; result = byte & 0x7f; while (byte & 0x80) { byte = *p++; shift += 7; result |= (unsigned)(byte & 0x7f) << shift; } *val = result; return p; }

extern int D_0042992C[]; extern int D_00635640[]; extern char D_00635600[];
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002EC9F0
unsigned FUN_002ec9f0(void) { int r; if (D_0042992C[0] < 0) return 0; r = func_002E8928(D_00635600, 5, 0, 0, 0, D_00635640, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640[0]; }

extern int D_0042992C_002ECA60[] __asm__("D_0042992C"); extern int D_00635640_002ECA60[] __asm__("D_00635640"); extern char D_00635600_002ECA60[] __asm__("D_00635600");
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002ECA60
unsigned FUN_002eca60(void) { int r; if (D_0042992C_002ECA60[0] < 0) return 0; r = func_002E8928(D_00635600_002ECA60, 6, 0, 0, 0, D_00635640_002ECA60, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECA60[0]; }

extern int D_0042992C_002ECAD0[] __asm__("D_0042992C"); extern int D_00635640_002ECAD0[] __asm__("D_00635640"); extern char D_00635600_002ECAD0[] __asm__("D_00635600");
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002ECAD0
unsigned FUN_002ecad0(void) { int r; if (D_0042992C_002ECAD0[0] < 0) return 0; r = func_002E8928(D_00635600_002ECAD0, 7, 0, 0, 0, D_00635640_002ECAD0, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECAD0[0]; }

extern int D_0062B5C0[]; extern char D_0062B380[];
int func_002E8928_002CA738(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA738
int FUN_002ca738(void) { int r; D_0062B5C0[0] = 12; r = func_002E8928_002CA738(D_0062B380, 1, 0, D_0062B5C0, 128, D_0062B5C0, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0[3]; }

extern int D_0062B5C0_002CA808[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA808[] __asm__("D_0062B380");
int func_002E8928_002CA808(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA808
int FUN_002ca808(void) { int r; D_0062B5C0_002CA808[0] = 18; r = func_002E8928_002CA808(D_0062B380_002CA808, 1, 0, D_0062B5C0_002CA808, 128, D_0062B5C0_002CA808, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA808[3]; }

extern int D_0062B5C0_002CA7A0[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA7A0[] __asm__("D_0062B380");
int func_002E8928_002CA7A0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA7A0
int FUN_002ca7a0(int x) { int r; D_0062B5C0_002CA7A0[1] = x; D_0062B5C0_002CA7A0[0] = 13; r = func_002E8928_002CA7A0(D_0062B380_002CA7A0, 1, 0, D_0062B5C0_002CA7A0, 128, D_0062B5C0_002CA7A0, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA7A0[3]; }

extern int D_0062B5C0_002CA870[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA870[] __asm__("D_0062B380");
int func_002E8928_002CA870(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA870
int FUN_002ca870(int x) { int r; D_0062B5C0_002CA870[1] = x; D_0062B5C0_002CA870[0] = 20; r = func_002E8928_002CA870(D_0062B380_002CA870, 1, 0, D_0062B5C0_002CA870, 128, D_0062B5C0_002CA870, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA870[2]; }

extern int D_0042992C_002EC868[] __asm__("D_0042992C"); extern int D_00635680[]; extern int D_00635640_002EC868[] __asm__("D_00635640"); extern char D_00635600_002EC868[] __asm__("D_00635600");
int func_002E8928_002EC868(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC868
int FUN_002ec868(int x) { int r; if (D_0042992C_002EC868[0] < 0) return 0; D_00635680[0] = x; r = func_002E8928_002EC868(D_00635600_002EC868, 2, 0, D_00635680, 4, D_00635640_002EC868, 4, 0, 0); if (r < 0) return -1; return D_00635640_002EC868[0]; }

extern int D_0042992C_002ECB40[] __asm__("D_0042992C"); extern int D_00635680_002ECB40[] __asm__("D_00635680"); extern int D_00635640_002ECB40[] __asm__("D_00635640"); extern char D_00635600_002ECB40[] __asm__("D_00635600");
int func_002E8928_002ECB40(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ECB40
unsigned FUN_002ecb40(int x) { int r; if (D_0042992C_002ECB40[0] < 0) return 0; D_00635680_002ECB40[0] = x; r = func_002E8928_002ECB40(D_00635600_002ECB40, 8, 0, D_00635680_002ECB40, 4, D_00635640_002ECB40, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECB40[0]; }

extern int D_0042992C_002ECBC0[] __asm__("D_0042992C"); extern int D_00635680_002ECBC0[] __asm__("D_00635680"); extern int D_00635640_002ECBC0[] __asm__("D_00635640"); extern char D_00635600_002ECBC0[] __asm__("D_00635600");
int func_002E8928_002ECBC0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ECBC0
unsigned FUN_002ecbc0(int x) { int r; if (D_0042992C_002ECBC0[0] < 0) return 0; D_00635680_002ECBC0[0] = x; r = func_002E8928_002ECBC0(D_00635600_002ECBC0, 9, 0, D_00635680_002ECBC0, 4, D_00635640_002ECBC0, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECBC0[0]; }

extern int D_0042992C_002EC7E8[] __asm__("D_0042992C"); extern int D_00635680_002EC7E8[] __asm__("D_00635680"); extern int D_00635640_002EC7E8[] __asm__("D_00635640"); extern char D_00635600_002EC7E8[] __asm__("D_00635600");
int func_002E8928_002EC7E8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC7E8
int FUN_002ec7e8(int x, int y, int z) { int r; if (D_0042992C_002EC7E8[0] < 0) return 0; D_00635680_002EC7E8[0] = y; D_00635680_002EC7E8[1] = x; D_00635680_002EC7E8[2] = z; r = func_002E8928_002EC7E8(D_00635600_002EC7E8, 4, 0, D_00635680_002EC7E8, 12, D_00635640_002EC7E8, 4, 0, 0); if (r < 0) return 0; return D_00635640_002EC7E8[0]; }

extern int D_0042992C_002EC778[] __asm__("D_0042992C"); extern int D_00635680_002EC778[] __asm__("D_00635680"); extern int D_00635640_002EC778[] __asm__("D_00635640"); extern char D_00635600_002EC778[] __asm__("D_00635600");
int func_002E8928_002EC778(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC778
int FUN_002ec778(int x) { int r; if (D_0042992C_002EC778[0] >= 0) { D_00635680_002EC778[0] = x; r = func_002E8928_002EC778(D_00635600_002EC778, 1, 0, D_00635680_002EC778, 4, D_00635640_002EC778, 4, 0, 0); if (r >= 0) return D_00635640_002EC778[0]; } return 0; }

extern int D_0062B5C0_002C9838[] __asm__("D_0062B5C0"); extern char D_0062B380_002C9838[] __asm__("D_0062B380"); extern int D_004262F8[];
int func_002E8928_002C9838(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002C9838
int FUN_002c9838(void) { int r; int v; D_0062B5C0_002C9838[0] = 15; r = func_002E8928_002C9838(D_0062B380_002C9838, 1, 0, D_0062B5C0_002C9838, 128, D_0062B5C0_002C9838, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002C9838[3]; if (v == 1) D_004262F8[0] = 0; return v; }

extern char D_00427D88[]; extern int D_00427540[]; extern int D_0042636C[];
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CC908(int) __asm__("func_002E58C0");
// MATCH func_002CC908
int FUN_002cc908(void) { int r; int v; if (func_002CBC90(1) == 0) return 0; r = func_002E8928(D_00427D88, 3, 0, 0, 0, D_00427540, 4, 0, 0); if (r < 0) { func_002E58C0_002CC908(D_0042636C[0]); return 0; } v = *(int *)((unsigned)D_00427540 | 0x20000000); func_002E58C0_002CC908(D_0042636C[0]); return v; }

extern char D_00427D88_002CC9A0[] __asm__("D_00427D88"); extern int D_00427540_002CC9A0[] __asm__("D_00427540"); extern int D_0042636C_002CC9A0[] __asm__("D_0042636C");
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CC9A0(int) __asm__("func_002E58C0");
// MATCH func_002CC9A0
int FUN_002cc9a0(void) { int r; int v; if (func_002CBC90(3) == 0) return -1; r = func_002E8928(D_00427D88_002CC9A0, 4, 0, 0, 0, D_00427540_002CC9A0, 4, 0, 0); if (r < 0) { func_002E58C0_002CC9A0(D_0042636C_002CC9A0[0]); return -1; } v = *(int *)((unsigned)D_00427540_002CC9A0 | 0x20000000); func_002E58C0_002CC9A0(D_0042636C_002CC9A0[0]); return v; }

extern char D_00427510[]; extern int D_004263C0[]; extern int D_00426368[];
int func_002CB978(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CBAE8(int) __asm__("func_002E58C0");
// MATCH func_002CBAE8
int FUN_002cbae8(void) { int r; int v; if (func_002CB978(2) == 0) return 0; r = func_002E8928(D_00427510, 14, 0, 0, 0, D_004263C0, 4, 0, 0); if (r < 0) { func_002E58C0_002CBAE8(D_00426368[0]); return 0; } v = *(int *)((unsigned)D_004263C0 | 0x20000000); func_002E58C0_002CBAE8(D_00426368[0]); return v; }

extern int D_0062B5C0_002CA1A0[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA1A0[] __asm__("D_0062B380");
int func_002E8928_002CA1A0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA1A0
int FUN_002ca1a0(int a, int b, int c, int d) { int r; int v; D_0062B5C0_002CA1A0[3] = c; D_0062B5C0_002CA1A0[4] = d; D_0062B5C0_002CA1A0[0] = 6; D_0062B5C0_002CA1A0[1] = a; D_0062B5C0_002CA1A0[2] = b; r = func_002E8928_002CA1A0(D_0062B380_002CA1A0, 1, 0, D_0062B5C0_002CA1A0, 128, D_0062B5C0_002CA1A0, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA1A0[5]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA1A0[5]; }

extern int D_0062B5C0_002CA4A8[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA4A8[] __asm__("D_0062B380");
int func_002E8928_002CA4A8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA4A8
int FUN_002ca4a8(int a, int b, int c) { int r; int v; D_0062B5C0_002CA4A8[3] = c; D_0062B5C0_002CA4A8[0] = 10; D_0062B5C0_002CA4A8[1] = a; D_0062B5C0_002CA4A8[2] = b; r = func_002E8928_002CA4A8(D_0062B380_002CA4A8, 1, 0, D_0062B5C0_002CA4A8, 128, D_0062B5C0_002CA4A8, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA4A8[4]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA4A8[4]; }

extern char D_00427D88_002CCA38[] __asm__("D_00427D88"); extern int D_00427540_002CCA38[] __asm__("D_00427540"); extern int D_0042636C_002CCA38[] __asm__("D_0042636C"); extern int D_00426350[]; extern char D_0049E190[]; extern int D_00426394[];
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CCA38(int) __asm__("func_002E58C0"); void func_002E7940(void *);
// MATCH func_002CCA38
int FUN_002cca38(void) { int r; int v; if (func_002CBC90(2) == 0) return -1; r = func_002E8928(D_00427D88_002CCA38, 12, 0, 0, 0, D_00427540_002CCA38, 4, 0, 0); if (r < 0) { func_002E58C0_002CCA38(D_0042636C_002CCA38[0]); return -1; } v = *(int *)((unsigned)D_00427540_002CCA38 | 0x20000000); func_002E58C0_002CCA38(D_0042636C_002CCA38[0]); if (D_00426350[0] >= 2) func_002E7940(D_0049E190); return v; }

extern char D_0062B900[], D_0062B980[]; extern int D_0062CEC0[]; extern char D_0049E328[];
int func_002E8928_002CDD88(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E7940(void *);
// MATCH func_002CDD88
int sceMcUdCheckNewCard(void) { if (func_002E8928_002CDD88(D_0062B900, 53, 0, D_0062B980, 48, D_0062CEC0, 4, 0, 0) != 0) { func_002E7940(D_0049E328); return -1; } return D_0062CEC0[0]; }

typedef struct { int v; int pad; char name[252]; } T_002ED2A8;
extern T_002ED2A8 D_006357C0; extern char D_006359C0[];
int func_002ECC40(void); int func_002ECD40(void); void *func_002DD928(void *, void *, int);
int func_002E8928_002ED2A8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED2A8
int FUN_002ed2a8(char *name) { int r; if (func_002ECC40() < 0) return -65536; if (func_002ECD40() != 0) return -65540; func_002DD928(D_006357C0.name, name, 252); D_006357C0.name[251] = 0; r = func_002E8928_002ED2A8(D_006359C0, 9, 0, &D_006357C0, 512, &D_006357C0, 4, 0, 0); if (r < 0) return -65537; return D_006357C0.v; }

extern char D_006357C0_002ED7D0[] __asm__("D_006357C0"); extern char D_006359C0_002ED7D0[] __asm__("D_006359C0");
int func_002ECC40(void);
int func_002E8928_002ED7D0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED7D0
int FUN_002ed7d0(int a, unsigned char *dst, unsigned size) { int r; if (func_002ECC40() < 0) return -65536; if (size >= 3) return -65538; *(int *)D_006357C0_002ED7D0 = a; *(int *)(D_006357C0_002ED7D0 + 4) = size; r = func_002E8928_002ED7D0(D_006359C0_002ED7D0, 3, 0, D_006357C0_002ED7D0, 32, D_006357C0_002ED7D0, 32, 0, 0); if (r < 0) return -65537; if (size == 0) *dst = *(unsigned char *)D_006357C0_002ED7D0; else if (size == 1) *(unsigned short *)dst = *(unsigned short *)D_006357C0_002ED7D0; else if (size == 2) *(int *)dst = *(int *)D_006357C0_002ED7D0; else return -65538; return 0; }

extern char D_006357C0_002ED8C0[] __asm__("D_006357C0"); extern char D_006359C0_002ED8C0[] __asm__("D_006359C0");
int func_002ECC40(void);
int func_002E8928_002ED8C0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED8C0
int FUN_002ed8c0(int a, unsigned char *src, int size) { int r; if (func_002ECC40() < 0) return -65536; *(int *)D_006357C0_002ED8C0 = a; *(int *)(D_006357C0_002ED8C0 + 4) = size; if (size == 0) *(unsigned char *)(D_006357C0_002ED8C0 + 8) = *src; else if (size == 1) *(unsigned short *)(D_006357C0_002ED8C0 + 8) = *(unsigned short *)src; else if (size == 2) *(int *)(D_006357C0_002ED8C0 + 8) = *(int *)src; else return -65538; r = func_002E8928_002ED8C0(D_006359C0_002ED8C0, 2, 0, D_006357C0_002ED8C0, 32, D_006357C0_002ED8C0, 16, 0, 0); if (r < 0) return -65537; return 0; }

// MATCH func_002EDD40
int *FUN_002edd40(int *p, int *end, int v) { while (*p != v && p < end) p++; return p < end ? p : 0; }

extern int D_0042ABF8[]; void func_002E5550(int, void *); void func_002EE9C0(void);
// MATCH func_002EE478
int FUN_002ee478(int x) { D_0042ABF8[0] = x; func_002E5550(1, func_002EE9C0); func_002E5550(2, func_002EE9C0); func_002E5550(3, func_002EE9C0); return x; }

extern char D_0049F740[]; extern int D_0042AC40[];
void func_002EE0E8(void *, int, int); void func_002EE200_002EE2E8(void) __asm__("func_002EE200"); void func_002E5CC0(int, int);
// MATCH func_002EE2E8
void FUN_002ee2e8(int s, int c) { func_002EE0E8(D_0049F740, s, c); func_002EE200_002EE2E8(); func_002E5CC0(s, D_0042AC40[0] + 4); }

extern int D_0042AC00[];
void func_002E5550(int, void *); void func_002E5560(int, void *); void func_002EEC00(void);
// MATCH func_002EE4D8
unsigned FUN_002ee4d8(int n, int h) { int old; if ((unsigned)(n - 1) >= 13) return 0xffffffff; old = D_0042AC00[n]; D_0042AC00[n] = h; if ((unsigned)(n - 1) < 3) func_002E5550(n, func_002EEC00); else func_002E5560(n, func_002EEC00); return old; }

extern char D_006359E8[]; extern char D_00429874[]; extern char *D_00429934[];
int func_002F06D8(void *, void *, int);
// MATCH func_002ECD40
int FUN_002ecd40(void) { int r = 0; char *b = D_00429874; char *a = D_006359E8; if (func_002F06D8(a, b, 4) != 0) { if (func_002F06D8(a, D_00429934[0], 4) != 0) r = func_002F06D8(b, D_00429934[0], 4) != 0; } return r; }

extern int D_00427DCC[]; extern int D_00427DC8_002CD2B0[] __asm__("D_00427DC8"); extern int D_0062B900_002CD2B0[] __asm__("D_0062B900"); extern int D_0062B980_002CD2B0[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD2B0[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD2B0(int) __asm__("func_002E58C0"); int func_002E8928_002CD2B0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD2B0
int FUN_002cd2b0(int x) { int r; if (func_002E58F0(D_00427DCC[0]) < 0) return -200; if (D_0062B900_002CD2B0[9] == 0) { func_002E58C0_002CD2B0(D_00427DCC[0]); return -100; } D_0062B980_002CD2B0[5] = x; r = func_002E8928_002CD2B0(D_0062B900_002CD2B0, 20, 1, D_0062B980_002CD2B0, 48, D_0062CEC0_002CD2B0, 4, 0, 0); if (r == 0) D_00427DC8_002CD2B0[0] = 20; else func_002E58C0_002CD2B0(D_00427DCC[0]); return r; }

extern int D_00427DCC_002CD598[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD598[] __asm__("D_00427DC8"); extern int D_0062B900_002CD598[] __asm__("D_0062B900"); extern int D_0062B980_002CD598[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD598[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD598(int) __asm__("func_002E58C0"); int func_002E8928_002CD598(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD598
int FUN_002cd598(int x) { int r; if (func_002E58F0(D_00427DCC_002CD598[0]) < 0) return -200; if (D_0062B900_002CD598[9] == 0) { func_002E58C0_002CD598(D_00427DCC_002CD598[0]); return -100; } D_0062B980_002CD598[0] = x; r = func_002E8928_002CD598(D_0062B900_002CD598, 3, 1, D_0062B980_002CD598, 48, D_0062CEC0_002CD598, 4, 0, 0); if (r == 0) D_00427DC8_002CD598[0] = 3; else func_002E58C0_002CD598(D_00427DCC_002CD598[0]); return r; }

extern int D_00427DCC_002CE318[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE318[] __asm__("D_00427DC8"); extern int D_0062B900_002CE318[] __asm__("D_0062B900"); extern int D_0062B980_002CE318[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE318[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE318(int) __asm__("func_002E58C0"); int func_002E8928_002CE318(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE318
int FUN_002ce318(int x) { int r; if (func_002E58F0(D_00427DCC_002CE318[0]) < 0) return -200; if (D_0062B900_002CE318[9] == 0) { func_002E58C0_002CE318(D_00427DCC_002CE318[0]); return -100; } D_0062B980_002CE318[0] = x; r = func_002E8928_002CE318(D_0062B900_002CE318, 10, 1, D_0062B980_002CE318, 48, D_0062CEC0_002CE318, 4, 0, 0); if (r == 0) D_00427DC8_002CE318[0] = 10; else func_002E58C0_002CE318(D_00427DCC_002CE318[0]); return r; }

extern int D_00427DCC_002CD650[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD650[] __asm__("D_00427DC8"); extern int D_0062B900_002CD650[] __asm__("D_0062B900"); extern int D_0062B980_002CD650[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD650[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD650(int) __asm__("func_002E58C0"); int func_002E8928_002CD650(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD650
int FUN_002cd650(int a, int b, int c) { int r; if (func_002E58F0(D_00427DCC_002CD650[0]) < 0) return -200; if (D_0062B900_002CD650[9] == 0) { func_002E58C0_002CD650(D_00427DCC_002CD650[0]); return -100; } D_0062B980_002CD650[0] = a; D_0062B980_002CD650[4] = b; D_0062B980_002CD650[5] = c; r = func_002E8928_002CD650(D_0062B900_002CD650, 4, 1, D_0062B980_002CD650, 48, D_0062CEC0_002CD650, 4, 0, 0); if (r == 0) D_00427DC8_002CD650[0] = 4; else func_002E58C0_002CD650(D_00427DCC_002CD650[0]); return r; }

extern int D_00427DCC_002CE128[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE128[] __asm__("D_00427DC8"); extern int D_0062B900_002CE128[] __asm__("D_0062B900"); extern int D_0062B980_002CE128[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE128[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE128(int) __asm__("func_002E58C0"); int func_002E8928_002CE128(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE128
int FUN_002ce128(int a, int b) { int r; if (func_002E58F0(D_00427DCC_002CE128[0]) < 0) return -200; if (D_0062B900_002CE128[9] == 0) { func_002E58C0_002CE128(D_00427DCC_002CE128[0]); return -100; } D_0062B980_002CE128[2] = b; D_0062B980_002CE128[1] = a; r = func_002E8928_002CE128(D_0062B900_002CE128, 16, 1, D_0062B980_002CE128, 48, D_0062CEC0_002CE128, 4, 0, 0); if (r == 0) D_00427DC8_002CE128[0] = 16; else func_002E58C0_002CE128(D_00427DCC_002CE128[0]); return r; }

extern int D_00427DCC_002CE710[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE710[] __asm__("D_00427DC8"); extern int D_0062B900_002CE710[] __asm__("D_0062B900"); extern int D_0062B980_002CE710[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE710[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE710(int) __asm__("func_002E58C0"); int func_002E8928_002CE710(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE710
int FUN_002ce710(int a, int b) { int r; if (func_002E58F0(D_00427DCC_002CE710[0]) < 0) return -200; if (D_0062B900_002CE710[9] == 0) { func_002E58C0_002CE710(D_00427DCC_002CE710[0]); return -100; } D_0062B980_002CE710[2] = b; D_0062B980_002CE710[1] = a; r = func_002E8928_002CE710(D_0062B900_002CE710, 17, 1, D_0062B980_002CE710, 48, D_0062CEC0_002CE710, 4, 0, 0); if (r == 0) D_00427DC8_002CE710[0] = 17; else func_002E58C0_002CE710(D_00427DCC_002CE710[0]); return r; }

extern int D_00427DCC_002CD368[] __asm__("D_00427DCC"); extern int D_0062B900_002CD368[] __asm__("D_0062B900"); extern int D_0062B980_002CD368[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD368[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD368(int) __asm__("func_002E58C0"); int func_002E8928_002CD368(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD368
int FUN_002cd368(int a) { int r; if (func_002E58F0(D_00427DCC_002CD368[0]) < 0) return -200; if (D_0062B900_002CD368[9] == 0) { func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return -100; } D_0062B980_002CD368[1] = a; r = func_002E8928_002CD368(D_0062B900_002CD368, 21, 0, D_0062B980_002CD368, 48, D_0062CEC0_002CD368, 4, 0, 0); if (r != 0) { func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return r; } func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return D_0062CEC0_002CD368[0]; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CE7D8;
extern T_002CE7D8 D_0062B9B0_002CE7D8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CE7D8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE7D8[] __asm__("D_00427DC8"); extern int D_0062B900_002CE7D8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CE7D8[] __asm__("D_0062CEC0");
int func_002E58F0(int); void *func_002DD928(void *, void *, int);
int func_002E8928_002CE7D8(int *, int, int, void *, int, int *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE7D8
int FUN_002ce7d8(int a, int b, char *name) { int r; if (func_002E58F0(D_00427DCC_002CE7D8[0]) < 0) return -200; if (D_0062B900_002CE7D8[9] == 0) { func_002E58C0(D_00427DCC_002CE7D8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CE7D8[0]); return -210; } D_0062B9B0_002CE7D8.a0 = a; D_0062B9B0_002CE7D8.a4 = b; func_002DD928(D_0062B9B0_002CE7D8.name, name, 1023); D_0062B9B0_002CE7D8.name[1023] = 0; r = func_002E8928_002CE7D8(D_0062B900_002CE7D8, 18, 1, &D_0062B9B0_002CE7D8, 1044, D_0062CEC0_002CE7D8, 4, 0, 0); if (r == 0) D_00427DC8_002CE7D8[0] = 18; else func_002E58C0(D_00427DCC_002CE7D8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CE1F0;
extern T_002CE1F0 D_0062B9B0_002CE1F0 __asm__("D_0062B9B0"); extern int D_00427DCC_002CE1F0[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE1F0[] __asm__("D_00427DC8"); extern int D_0062B900_002CE1F0[] __asm__("D_0062B900"); extern int D_0062CEC0_002CE1F0[] __asm__("D_0062CEC0");
int func_002E58F0(int); void *func_002DD928(void *, void *, int);
int func_002E8928_002CE1F0(int *, int, int, void *, int, int *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE1F0
int FUN_002ce1f0(int a, int b, char *name) { int r; if (func_002E58F0(D_00427DCC_002CE1F0[0]) < 0) return -200; if (D_0062B900_002CE1F0[9] == 0) { func_002E58C0(D_00427DCC_002CE1F0[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CE1F0[0]); return -210; } func_002DD928(D_0062B9B0_002CE1F0.name, name, 1023); D_0062B9B0_002CE1F0.a0 = a; D_0062B9B0_002CE1F0.a4 = b; D_0062B9B0_002CE1F0.name[1023] = 0; D_0062B9B0_002CE1F0.a8 = 0; r = func_002E8928_002CE1F0(D_0062B900_002CE1F0, 15, 1, &D_0062B9B0_002CE1F0, 1044, D_0062CEC0_002CE1F0, 4, 0, 0); if (r == 0) D_00427DC8_002CE1F0[0] = 15; else func_002E58C0(D_00427DCC_002CE1F0[0]); return r; }
typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CDDF8;
extern T_002CDDF8 D_0062B9B0_002CDDF8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CDDF8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CDDF8[] __asm__("D_00427DC8"); extern int D_0062B900_002CDDF8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CDDF8[] __asm__("D_0062CEC0"); extern char D_0062BD40[];
int func_002E58F0(int); void *func_002DD928(void *, void *, int); void func_002E8038(void *, int); void func_002CDF58(void);
int func_002E8928_002CDDF8(void *, int, int, void *, int, void *, int, void *, int) __asm__("func_002E8928");
// MATCH func_002CDDF8
int FUN_002cddf8(int a, int b, char *name, int c, int d, char *buf) { int r; if (func_002E58F0(D_00427DCC_002CDDF8[0]) < 0) return -200; if (D_0062B900_002CDDF8[9] == 0) { func_002E58C0(D_00427DCC_002CDDF8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CDDF8[0]); return -210; } D_0062B9B0_002CDDF8.a0 = a; D_0062B9B0_002CDDF8.a4 = b; D_0062B9B0_002CDDF8.a8 = c; D_0062B9B0_002CDDF8.a12 = d; D_0062B9B0_002CDDF8.a16 = (int)buf; func_002DD928(D_0062B9B0_002CDDF8.name, name, 1023); D_0062B9B0_002CDDF8.name[1023] = 0; if (d >= 0) func_002E8038(buf, d << 6); r = func_002E8928_002CDDF8(D_0062B900_002CDDF8, 13, 1, &D_0062B9B0_002CDDF8, 1044, D_0062CEC0_002CDDF8, 4, 0, 0); if (r == 0) D_00427DC8_002CDDF8[0] = 13; else func_002E58C0(D_00427DCC_002CDDF8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CDFD8;
extern T_002CDFD8 D_0062B9B0_002CDFD8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CDFD8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CDFD8[] __asm__("D_00427DC8"); extern int D_0062B900_002CDFD8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CDFD8[] __asm__("D_0062CEC0"); extern char D_0062BEC0[];
int func_002E58F0(int); int func_002E58C0_002CDFD8(int) __asm__("func_002E58C0"); void *func_002DD928(void *, void *, int); void func_002E8038(void *, int); void func_002CDF50(void);
int func_002E8928_002CDFD8(void *, int, int, void *, int, void *, int, void *, int) __asm__("func_002E8928");
// MATCH func_002CDFD8
int FUN_002cdfd8(int a, int b, char *name, int c) { int r; if (func_002E58F0(D_00427DCC_002CDFD8[0]) < 0) return -200; if (D_0062B900_002CDFD8[9] == 0) { func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return -210; } D_0062B9B0_002CDFD8.a0 = a; D_0062B9B0_002CDFD8.a16 = (int)D_0062BEC0; D_0062B9B0_002CDFD8.a4 = b; func_002DD928(D_0062B9B0_002CDFD8.name, name, 1023); D_0062B9B0_002CDFD8.name[1023] = 0; func_002E8038(D_0062BEC0, 1024); r = func_002E8928_002CDFD8(D_0062B900_002CDFD8, 12, 1, &D_0062B9B0_002CDFD8, 1044, D_0062CEC0_002CDFD8, 4, func_002CDF50, c); if (r == 0) D_00427DC8_002CDFD8[0] = 12; else func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CD428;
extern T_002CD428 D_0062B9B0_002CD428 __asm__("D_0062B9B0"); extern int D_00427DCC_002CD428[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD428[] __asm__("D_00427DC8"); extern int D_0062B900_002CD428[] __asm__("D_0062B900"); extern int D_0062CEC0_002CD428[] __asm__("D_0062CEC0");
int func_002E58F0(int); int func_002E58C0_002CD428(int) __asm__("func_002E58C0"); void *func_002DD928(void *, void *, int);
int func_002E8928_002CD428(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD428
int FUN_002cd428(int a, int b, char *name, int c) { int r; if (func_002E58F0(D_00427DCC_002CD428[0]) < 0) return -200; if (D_0062B900_002CD428[9] == 0) { func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return -210; } func_002DD928(D_0062B9B0_002CD428.name, name, 1023); D_0062B9B0_002CD428.a0 = a; D_0062B9B0_002CD428.a8 = c; D_0062B9B0_002CD428.a4 = b; D_0062B9B0_002CD428.name[1023] = 0; r = func_002E8928_002CD428(D_0062B900_002CD428, 2, 1, &D_0062B9B0_002CD428, 1044, D_0062CEC0_002CD428, 4, 0, 0); if (r == 0) D_00427DC8_002CD428[0] = 2; else func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return r; }

extern char D_00635568[]; extern char D_00429874_002E9888[] __asm__("D_00429874"); extern char *D_00429928[];
int func_002F06D8(void *, void *, int);
// MATCH func_002E9888
int FUN_002e9888(void) { int r = 0; char *b = D_00429874_002E9888; char *a = D_00635568; if (func_002F06D8(a, b, 4) != 0) { if (func_002F06D8(a, D_00429928[0], 4) != 0) r = func_002F06D8(b, D_00429928[0], 4) != 0; } return r; }

extern int D_0042991C[];
int func_002E58A0(void *);
// MATCH func_002E9560
void FUN_002e9560(void) { int t[6]; if (D_0042991C[0] == -1) { t[5] = 0; t[2] = 1; t[1] = 1; D_0042991C[0] = func_002E58A0(t); } }

extern int D_00429920[]; extern int D_00429924[];
int func_002E58A0(void *);
// MATCH func_002E9048
void FUN_002e9048(void) { int t[6]; if (D_00429920[0] == -1) { t[5] = 0; t[2] = 1; t[1] = 1; D_00429920[0] = func_002E58A0(t); D_00429924[0] = func_002E58A0(t); } }

extern int D_00429950[]; extern int D_00429954[];
int func_002E58A0(void *);
// MATCH func_002EDCB0
void FUN_002edcb0(void) { int t[16];
t[1] = 1;
t[2] = 1;
t[9] = 1;
t[10] = 1;
D_00429950[0] = func_002E58A0(t); D_00429954[0] = func_002E58A0(t + 8); }

typedef struct { int a0, a4, a8, a12; } E_002E9130;
extern E_002E9130 D_00635340[]; extern int D_00429920_002E9130[] __asm__("D_00429920");
void func_002E9048(void); int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_002E9130
E_002E9130 *FUN_002e9130(unsigned i) { E_002E9130 *r; func_002E9048(); func_002E58E0(D_00429920_002E9130[0]); if (i >= 32) { func_002E58C0(D_00429920_002E9130[0]); return 0; } r = &D_00635340[i]; func_002E58C0(D_00429920_002E9130[0]); return r; }

typedef struct { int a0, a4, a8, a12; } E_002E90A8;
extern E_002E90A8 D_00635340_002E90A8[] __asm__("D_00635340"); extern int D_00429920_002E90A8[] __asm__("D_00429920");
void func_002E9048(void); int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_002E90A8
E_002E90A8 *FUN_002e90a8(void) { E_002E90A8 *p; func_002E9048(); func_002E58E0(D_00429920_002E90A8[0]); for (p = D_00635340_002E90A8; p < D_00635340_002E90A8 + 32; p++) { if (p->a4 == 0) { p->a4 = 0x10000000; func_002E58C0(D_00429920_002E90A8[0]); return p; } } func_002E58C0(D_00429920_002E90A8[0]); return 0; }

extern int D_006355C0[]; extern int D_00429918[];
void func_002E95B0(int); void func_002E96B8(void); int func_002EDC50(void); void func_002EDC98(void); void func_002E95E0(void);
// MATCH func_002E95F0
int FUN_002e95f0(int a, int b) { int old; int r; int *p = D_006355C0; func_002E95B0(27); if (D_00429918[0] == 0) func_002E96B8(); r = func_002EDC50(); old = D_006355C0[0]; p[1] = b; D_006355C0[0] = a; if (r != 0) func_002EDC98(); func_002E95E0(); return old; }

int func_002EDC50(void); int func_002EDC98_002E6380(void) __asm__("func_002EDC98"); int func_002E55F0(int);
// MATCH func_002E6380
int FUN_002e6380(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E55F0(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E6380(); return r; }

void func_002E7318(int, va_list);
// MATCH func_002E7908
void FUN_002e7908(int a, ...) { va_list ap; ap = (va_list)__builtin_next_arg(a) - 56; func_002E7318(a, ap); }

int func_002EDC50(void); int func_002EDC98_002E63E8(void) __asm__("func_002EDC98"); int func_002E55E0(int);
// MATCH func_002E63E8
int FUN_002e63e8(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E55E0(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E63E8(); return r; }

int func_002EDC50(void); int func_002EDC98_002E6450(void) __asm__("func_002EDC98"); int func_002E5610(int);
// MATCH func_002E6450
int FUN_002e6450(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E5610(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E6450(); return r; }

int func_002EDC50(void); int func_002EDC98_002E64B8(void) __asm__("func_002EDC98"); int func_002E5600(int);
// MATCH func_002E64B8
int FUN_002e64b8(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E5600(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E64B8(); return r; }

typedef struct { char pad[8]; int a8; } S_2dc8d8_002DC8D8;
void func_002DDF40(void *, int, int, va_list);
// MATCH func_002DC8D8
void FUN_002dc8d8(S_2dc8d8_002DC8D8 *s, int b, ...) { va_list ap; ap = (va_list)__builtin_next_arg(b) - 48; func_002DDF40(s, s->a8, b, ap); }

struct Q_2dc918_002DC918; typedef struct R_2dc918_002DC918 { char pad[8]; struct Q_2dc918_002DC918 *p; } R_2dc918_002DC918; typedef struct Q_2dc918_002DC918 { char pad[84]; R_2dc918_002DC918 *r; } Q_2dc918_002DC918;
extern R_2dc918_002DC918 *D_004293F4[];
void func_002DDEC8(void *, void *, va_list);
// MATCH func_002DC918
void printf(char *fmt, ...) { va_list ap; R_2dc918_002DC918 *r; ap = (va_list)__builtin_next_arg(fmt) - 56; r = D_004293F4[0]; r->p->r = r; func_002DDEC8(r->p, fmt, ap); }

extern int D_00429888[];
void func_002E7318_002E7940(char *, va_list) __asm__("func_002E7318"); void func_002E7038(void);
// MATCH func_002E7940
void FUN_002e7940(char *fmt, ...) { va_list ap; int old; ap = (va_list)__builtin_next_arg(fmt) - 56; old = D_00429888[0]; D_00429888[0] = (int)func_002E7038; func_002E7318_002E7940(fmt, ap); D_00429888[0] = old; }

typedef struct { char *p; int r; int w; short flags; short file; char *base; int size; int lbfsize; char pad[56]; void *data; } FILE_t_002DCE40;
extern void *D_004293F4_002DCE40[] __asm__("D_004293F4");
int func_002DDEC8_002DCE40(void *, void *, va_list) __asm__("func_002DDEC8");
// MATCH func_002DCE40
int sprintf(char *s, char *fmt, ...) { FILE_t_002DCE40 f; va_list ap; int r; ap = (va_list)__builtin_next_arg(fmt) - 48; f.flags = 520; f.base = f.p = s; f.size = f.w = 0x7fffffff; f.data = D_004293F4_002DCE40[0]; r = func_002DDEC8_002DCE40(&f, fmt, ap); *f.p = 0; return r; }

typedef struct { char *p; int r; int w; short flags; short file; char *base; int size; int lbfsize; char pad[56]; void *data; } FILE_t_002DCDD8;
int func_002DDEC8_002DCDD8(void *, void *, va_list) __asm__("func_002DDEC8");
// MATCH func_002DCDD8
int FUN_002dcdd8(void *reent, char *s, char *fmt, ...) { FILE_t_002DCDD8 f; va_list ap; int r; ap = (va_list)__builtin_next_arg(fmt) - 40; f.flags = 520; f.base = f.p = s; f.size = f.w = 0x7fffffff; f.data = reent; r = func_002DDEC8_002DCDD8(&f, fmt, ap); *f.p = 0; return r; }

// MATCH func_002DDAE8
char *strstr(char *searchee, char *lookfor) { if (*searchee == 0) { if (*lookfor) return 0; return searchee; } while (*searchee) { int i = 0; while (1) { if (lookfor[i] == 0) return searchee; if (lookfor[i] != searchee[i]) break; i++; } searchee++; } return 0; }

extern unsigned char D_0049EA61[];
// MATCH func_002DD718
char *strlwr(char *s) { char *p = s; while (*p) { int c = *p; if (D_0049EA61[c] & 1) *p = c + 32; p++; } return s; }

typedef struct { char pad[468]; int *a468; } R_t_002DCA08;
void *func_002DBED8(void *, int);
// MATCH func_002DCA08
int FUN_002dca08(R_t_002DCA08 *r) { int i; if (r->a468 == 0) { r->a468 = func_002DBED8(r, 128); if (r->a468 == 0) return -1; for (i = 31; i >= 0; i--) r->a468[i] = 0; } return 0; }

typedef struct { int errno_; char pad[464]; int *a468; } R_t_002DCA78;
int func_002DCA08(void *);
// MATCH func_002DCA78
unsigned FUN_002dca78(R_t_002DCA78 *r, unsigned n, int fn) { unsigned old; if (n >= 32) { r->errno_ = 22; return 0xffffffff; } if (r->a468 == 0) { if (func_002DCA08(r) != 0) return 0xffffffff; } old = r->a468[n]; r->a468[n] = fn; return old; }

typedef struct R_t R_t; typedef struct { char pad[12]; unsigned short flags; short file; char pad2[64]; int a80; R_t *data; } F_t_002DD028;
long func_002E2478(R_t *, int, int, int);
// MATCH func_002DD028
long FUN_002dd028(F_t_002DD028 *fp, int a, int b) { long r = func_002E2478(fp->data, fp->file, a, b); if (r == -1) fp->flags &= 0xefff; else { fp->a80 = r; fp->flags |= 0x1000; } return r; }

typedef struct F_t_002DDE10 { char *p; int r; int w; unsigned short flags; short file; char *base; int size; int lbfsize; int a28; int pad1; int a36; char pad[44]; void *data; } F_t_002DDE10;
int func_002DDEC8_002DDE10(F_t_002DDE10 *, char *, char *) __asm__("func_002DDEC8"); int func_002E18F8(F_t_002DDE10 *);
// MATCH func_002DDE10
int FUN_002dde10(F_t_002DDE10 *fp, char *fmt, char *ap) { F_t_002DDE10 t; char buf[1024]; int r;
t.data = fp->data;
t.flags = fp->flags & 0xfffd;
t.file = fp->file;
t.a28 = fp->a28;
t.a36 = fp->a36;
t.base = t.p = buf;
t.size = t.w = 1024;
t.lbfsize = 0;
r = func_002DDEC8_002DDE10(&t, fmt, ap); if (r >= 0) { if (func_002E18F8(&t) != 0) r = -1; } if (t.flags & 0x40) fp->flags |= 0x40; return r; }

int func_002C7318(void *, int); void func_002C7728(void *);
// MATCH func_002C7B00
void FUN_002c7b00(char *s) { *(int *)(s + 232) = 0; *(int *)(s + 2132) = 1; *(int *)(s + 2124) = *(int *)(s + 2128) + 1; func_002C7318(s, 1); func_002C7318(s, 5); func_002C7318(s, 6); func_002C7318(s, 1); func_002C7318(s, 6); func_002C7318(s, 6); *(int *)(s + 420) = func_002C7318(s, 1); *(int *)(s + 424) = func_002C7318(s, 1); func_002C7728(s); }

typedef struct { char c[16]; int x; } V20_2ced28_002CED28;
extern V20_2ced28_002CED28 D_0062CF00[2];
// MATCH func_002CED28
V20_2ced28_002CED28 *FUN_002ced28(V20_2ced28_002CED28 *d) { *d = D_0062CF00[0]; return d; }

typedef void __attribute__((noreturn)) (*F_2d8148)(void); extern F_2d8148 D_00427EF4_002D8148[] __asm__("D_00427EF4");
// MATCH func_002D8148
void FUN_002d8148(void) { D_00427EF4_002D8148[0](); }


void func_002E7000(int);
// MATCH func_002E70E8
void FUN_002e70e8(int c) { if (c == 10) { func_002E7000(13); func_002E7000(10); } else func_002E7000(c); }

int func_002DD36C_002DA4E0(int, int) __asm__("func_002DD36C");
// MATCH func_002DA4E0
int FUN_002da4e0(int *a, int *b) { int r = 0; if (b == a || func_002DD36C_002DA4E0(*a, *b) == 0) r = 1; return r; }

extern int D_00427DCC_002CD240[] __asm__("D_00427DCC"); int func_002E58B0(int);
// MATCH func_002CD240
int FUN_002cd240(void) { if (D_00427DCC_002CD240[0] >= 0) { func_002E58B0(D_00427DCC_002CD240[0]); D_00427DCC_002CD240[0] = -1; } return 1; }

extern int D_00632854[]; extern int D_0042988C[]; int func_002E6450(int); int func_002E55D0(int, int);
// MATCH func_002E7C98
void FUN_002e7c98(void) { func_002E6450(5); func_002E55D0(5, D_00632854[0]); D_0042988C[0] = 0; }

typedef struct { int w0; int p[7]; int w32; } Q_002CEED0;
void func_002CE8F0(void *);
// MATCH func_002CEED0
void FUN_002ceed0(Q_002CEED0 *o) { int v; func_002CE8F0(o); v = o->w0; o->w32 = 0; v &= ~0xc; v |= 4; v &= ~1; v |= 0x100; o->w0 = v; }

typedef struct { int w0; int p[7]; int w32; int p2[3]; unsigned w48; } Q_002CED78;
int func_002CE9E8(int); void func_002CE8F0_002CED78(Q_002CED78 *) __asm__("func_002CE8F0");
// MATCH func_002CED78
void FUN_002ced78(Q_002CED78 *o, int a) { int r = func_002CE9E8(a); func_002CE8F0_002CED78(o); if (o->w48 != 0xffffffff) o->w48 = r; o->w32 = 0; o->w0 = (o->w0 & ~0xc) | 0x105; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5220
int FUN_002d5220(unsigned long long a) { int r = -1; if ((a & 0xff000000) == 0) { func_002D04C0(66, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), 0); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5280
int FUN_002d5280(unsigned long long a) { int r = -1; if ((a & 0xff000000) == 0) { func_002D04C0(67, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), 0); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5380
int FUN_002d5380(int *a) { int r = -1; if ((unsigned)a[2] <= 0x1fffff && (unsigned)a[3] <= 0x1fffff && a[0] >= 0 && a[0] < 16) { func_002D04C0(72, (a[0] << 24) | a[1], a[2], a[3]); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D55B0
int FUN_002d55b0(unsigned a, unsigned long long b, int c) { int r = -1; if (a < 2 && (unsigned)c <= 0x1fffff && (b & 0xff000000) == 0) { func_002D04C0(79, (int)b, c, a); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5518
void FUN_002d5518(unsigned long long a, int b, int c) { if ((unsigned)b > 32767) return; if (c < 0) return; if (c > 32767) return; if (a & 0xff000000) return; func_002D04C0(74, (int)a, b, c); }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5120
int FUN_002d5120(unsigned long long a, unsigned b, int c) { int r = -1; if (b < 16384 && c >= 0 && c < 16384 && (a & 0xff000000) == 0) { func_002D04C0(64, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), (b << 16) | c); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D51A8
int FUN_002d51a8(unsigned long long a, int b) { int r = -1; if ((a & 0xff000000) == 0 && b >= 0 && b <= 192000) { func_002D04C0(65, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), b); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D1F48
int SndVoiceSetPitch(int x, int a1, int a2, int a3, int a4, int a5, int a6) { int hi = (a1 << 24) | a4; int lo = ((a3 & 0xff) << 8) | (a2 << 16); func_002D04C0(4, x, hi | lo, (a5 << 24) | a6); return 0; }

typedef struct { volatile unsigned w0; char p[60]; int w64; int w68; int w72; } Ch_002D4D98;
void *func_002CFF20_002D4D98(int) __asm__("func_002CFF20");
// MATCH func_002D4D98
void FUN_002d4d98(unsigned ch, int v) { if (ch < 48 && v >= 0 && v < 16384) { Ch_002D4D98 *p = func_002CFF20_002D4D98(ch); p->w0 |= 0x2000; p->w64 = v; p->w0 |= 0x400; p->w0 &= ~0x2000; } }

typedef struct { volatile unsigned w0; char p[60]; int w64; int w68; int w72; } Ch_002D4CF8;
void *func_002CFF20_002D4CF8(int) __asm__("func_002CFF20");
// MATCH func_002D4CF8
void FUN_002d4cf8(unsigned ch, int v, int w) { if (ch < 48 && v >= -4096 && v <= 4096 && w >= -4096 && w <= 4096) { Ch_002D4CF8 *p = func_002CFF20_002D4CF8(ch); p->w0 |= 0x2000; p->w68 = v; p->w72 = w; p->w0 |= 0x800; p->w0 &= ~0x2000; } }

typedef struct { volatile unsigned w0; char w4[80]; } Ch_002D3F58;
void *func_002CFF20_002D3F58(int) __asm__("func_002CFF20"); void func_002DC804(void *, int, int);
// MATCH func_002D3F58
int FUN_002d3f58(unsigned ch) { int r = -1; if (ch < 48) { Ch_002D3F58 *p = func_002CFF20_002D3F58(ch); p->w0 |= 0x2000; if ((p->w0 & 3) == 1) { func_002DC804(p->w4, 0, 80); r = 0; p->w0 = 0; } p->w0 &= ~0x2000; } return r; }

typedef struct { volatile unsigned w0; char p[44]; int w48; int w52; int w56; int w60; } Ch_002D41C0;
void *func_002CFF20_002D41C0(int) __asm__("func_002CFF20");
// MATCH func_002D41C0
int FUN_002d41c0(unsigned ch, int v, unsigned w) { int r = -1; if (ch < 48 && v >= 0 && v < 128) { Ch_002D41C0 *p = func_002CFF20_002D41C0(ch); p->w0 |= 0x2000; if (w == 0xffff) { r = p->w52; p->w48 = w; p->w52 = v; } else { p->w56 = w; r = 0; p->w60 = v; } p->w0 |= 0x200; p->w0 &= ~0x2000; } return r; }

typedef struct { volatile unsigned w0; } Ch_002D46E0;
void *func_002CFF20_002D46E0(int) __asm__("func_002CFF20");
// MATCH func_002D46E0
int FUN_002d46e0(unsigned ch) { int r = -1; if (ch < 48) { Ch_002D46E0 *p = func_002CFF20_002D46E0(ch); p->w0 |= 0x2000; if (p->w0 & 1) { r = ((int)p->w0 >> 1) & 1; if (p->w0 & 0x20) r |= 2; } p->w0 &= ~0x2000; } return r; }

typedef struct { int w0; int w4; char p[70]; unsigned short h78; } O_002D2320;
typedef struct { char p[8]; unsigned char *w8; char p2[4]; unsigned char *w16; } Pp_002D2320;
void *func_002CFFA0(void);
// MATCH func_002D2320
void FUN_002d2320(O_002D2320 *o) { if (o->w0 & 2) { Pp_002D2320 *p = func_002CFFA0(); *(p->w8 + (o->h78 << 4) + 18) = p->w16[1]; *(p->w8 + (o->h78 << 4) + 26) = 64; *(p->w8 + (o->h78 << 4) + 27) = 64; } o->w4 += 2; }

typedef struct { int w0; unsigned char *w4; } Pp_002D1EC0;
void *func_002CFFA0(void);
// MATCH func_002D1EC0
int FUN_002d1ec0(int a, int idx, int c) { Pp_002D1EC0 *p = func_002CFFA0(); unsigned char *q; if (a == 255) a = 1; else { int t; q = p->w4 + idx * 16; p->w4 = q; if (c < q[0]) a = 0; else { t = q[1] < c; a = t ^ 1; } p->w4 = q - idx * 16; } return a; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEDE0;
int func_002CE9E8(int); void func_002CE8F0_002CEDE0(Q_002CEDE0 *) __asm__("func_002CE8F0");
// MATCH func_002CEDE0
void FUN_002cede0(Q_002CEDE0 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEDE0(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (o->w0 & ~0xc) | 0x101; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEE58;
int func_002CE9E8(int); void func_002CE8F0_002CEE58(Q_002CEE58 *) __asm__("func_002CE8F0");
// MATCH func_002CEE58
void FUN_002cee58(Q_002CEE58 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEE58(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (o->w0 & ~0xc) | 0x109; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEF98;
int func_002CE9E8(int); void func_002CE8F0_002CEF98(Q_002CEF98 *) __asm__("func_002CE8F0");
// MATCH func_002CEF98
void FUN_002cef98(Q_002CEF98 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEF98(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (((o->w0 & ~0xc) | 8) & ~1) | 0x100; }

typedef struct { volatile unsigned w0; } Q_002CE8F0;
extern char D_0049E348[]; void func_002E7940_002CE8F0(char *) __asm__("func_002E7940"); void func_002CF088(Q_002CE8F0 *);
// MATCH func_002CE8F0
void FUN_002ce8f0(Q_002CE8F0 *o) { int n = 0x1000000; while (o->w0 & 0x100) { n--; if (n < 0) { func_002E7940_002CE8F0(D_0049E348); func_002CF088(o); } } }

typedef struct { int p[4]; volatile unsigned w16; } Q_002CE960;
extern char D_0049E348_002CE960[] __asm__("D_0049E348"); void func_002E7940_002CE960(char *) __asm__("func_002E7940"); void func_002CF088_002CE960(Q_002CE960 *) __asm__("func_002CF088");
// MATCH func_002CE960
void FUN_002ce960(Q_002CE960 *o, unsigned b, int c) { int n = c ? c : 0x1000000; while (o->w16 < b) { n--; if (n < 0) { func_002E7940_002CE960(D_0049E348_002CE960); func_002CF088_002CE960(o); } } }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP_002D7F50;
static inline int isnan__002D7F50(FP_002D7F50 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D7F50(FP_002D7F50 *x) { return x->cls == 4; }
static inline int iszero__002D7F50(FP_002D7F50 *x) { return x->cls == 2; }
void func_002D7580(void *, void *);
// MATCH func_002D7F50
int __fixdfsi(double arg) { FP_002D7F50 a; unsigned long long tmp; func_002D7580(&arg, &a); if (iszero__002D7F50(&a)) return 0; if (isnan__002D7F50(&a)) return 0; if (isinf__002D7F50(&a)) return a.sign ? 0x80000000 : 0x7fffffff; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? 0x80000000 : 0x7fffffff; tmp = a.ll >> (60 - a.exp); return a.sign ? -(int)tmp : (int)tmp; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FP_002D92B0;
static inline int isnan__002D92B0(FP_002D92B0 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D92B0(FP_002D92B0 *x) { return x->cls == 4; }
static inline int iszero__002D92B0(FP_002D92B0 *x) { return x->cls == 2; }
void func_002D89B0(void *, void *);
// MATCH func_002D92B0
int FUN_002d92b0(float arg) { FP_002D92B0 a; unsigned tmp; func_002D89B0(&arg, &a); if (iszero__002D92B0(&a)) return 0; if (isnan__002D92B0(&a)) return 0; if (isinf__002D92B0(&a)) return a.sign ? 0x80000000 : 0x7fffffff; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? 0x80000000 : 0x7fffffff; tmp = a.ll >> (30 - a.exp); return a.sign ? -(int)tmp : (int)tmp; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FP_002D9340;
static inline int isnan__002D9340(FP_002D9340 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D9340(FP_002D9340 *x) { return x->cls == 4; }
static inline int iszero__002D9340(FP_002D9340 *x) { return x->cls == 2; }
void func_002D89B0(void *, void *);
// MATCH func_002D9340
unsigned FUN_002d9340(float arg) { FP_002D9340 a; unsigned tmp; func_002D89B0(&arg, &a); if (iszero__002D9340(&a)) return 0; if (isnan__002D9340(&a)) return 0; if (a.sign) return 0; if (isinf__002D9340(&a)) return 0xffffffff; if (a.exp < 0) return 0; if (a.exp > 31) return 0xffffffff; if (a.exp > 30) tmp = a.ll << (a.exp - 30); else tmp = a.ll >> (30 - a.exp); return tmp; }

typedef struct { char c[12]; } V12_002CA668;
extern int D_0062B5C0_002CA668[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA668[] __asm__("D_0062B380"); int func_002E8928_002CA668(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA668
int FUN_002ca668(int a, int b, V12_002CA668 *c) { int r; int v; D_0062B5C0_002CA668[0] = 11; D_0062B5C0_002CA668[1] = a; D_0062B5C0_002CA668[2] = b; *(V12_002CA668 *)&D_0062B5C0_002CA668[3] = *c; r = func_002E8928_002CA668(D_0062B380_002CA668, 1, 0, D_0062B5C0_002CA668, 128, D_0062B5C0_002CA668, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA668[7]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA668[7]; }

extern int D_00631AB0[]; extern int D_00631AC0[]; extern int D_00631AC8[]; int func_002DC804_002D63F8(void *, int, int) __asm__("func_002DC804");
// MATCH func_002D63F8
int *FUN_002d63f8(void) { if (D_00631AC0[0] == 0) { D_00631AC0[0] = 1; func_002DC804_002D63F8(D_00631AB0, 0, 16); D_00631AB0[1] = (int)D_00631AC8; } return D_00631AB0; }

int func_002CADE8(void);
// MATCH func_002CAD78
int FUN_002cad78(void) { if (func_002CADE8() != 1) return 0; *(volatile int *)0x10003810 = 8; return 1; }

typedef struct { char p[16]; int a; int b; } R_x_002E2BC8;
void *func_002E2748(int, int);
// MATCH func_002E2BC8
void * FUN_002e2bc8(int a, int b) { R_x_002E2BC8 *r = (R_x_002E2BC8 *)func_002E2748(a, 1); r->b = b; r->a = 1; return r; }

extern int D_0062B640[]; int func_002CBB80(int); int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002CB0A8
int FUN_002cb0a8(int a) { int r, old; if (func_002CBB80(1)) return 0; r = func_002EDC50(); old = D_0062B640[0]; D_0062B640[0] = a; if (r != 0) func_002EDC98(); return old; }

typedef struct { int w0, w4, w8, w12, w16, w20; } S_002CB040;
extern char D_002CB018[]; int func_002E58A0_002CB040(S_002CB040 *) __asm__("func_002E58A0"); void func_002E5620_002CB040(int, char *, int) __asm__("func_002E5620"); void func_002E58E0_002CB040(int) __asm__("func_002E58E0"); void func_002E58B0_002CB040(int) __asm__("func_002E58B0");
// MATCH func_002CB040
void FUN_002cb040(unsigned short a) { S_002CB040 s; int r; s.w4 = 1; s.w8 = 0; s.w20 = 0; r = func_002E58A0_002CB040(&s); func_002E5620_002CB040(a, D_002CB018, r); func_002E58E0_002CB040(r); func_002E58B0_002CB040(r); }


typedef struct { char p[324]; int w324, w328, w332; } O_002C3E00;
int func_002C7318_002C3E00(O_002C3E00 *, int) __asm__("func_002C7318");
// MATCH func_002C3E00
void FUN_002c3e00(O_002C3E00 *o) { func_002C7318_002C3E00(o, 3); if (func_002C7318_002C3E00(o, 1) != 0) { func_002C7318_002C3E00(o, 8); func_002C7318_002C3E00(o, 8); o->w324 = func_002C7318_002C3E00(o, 8); } o->w328 = func_002C7318_002C3E00(o, 14); func_002C7318_002C3E00(o, 1); o->w332 = func_002C7318_002C3E00(o, 14); }

typedef struct { char p[436]; int w436; } O_002C74E8;
int func_002C7318_002C74E8(O_002C74E8 *, int) __asm__("func_002C7318"); void func_002C7228(O_002C74E8 *, int); void func_002C7A40(O_002C74E8 *);
// MATCH func_002C74E8
int FUN_002c74e8(O_002C74E8 *o) { o->w436 = func_002C7318_002C74E8(o, 5); if (func_002C7318_002C74E8(o, 1) != 0) { func_002C7318_002C74E8(o, 1); func_002C7228(o, 7); func_002C7A40(o); } return 0; }

extern char D_0062BEC0_002CDF50[] __asm__("D_0062BEC0"); unsigned func_002DD5E0_002CDF50(char *) __asm__("func_002DD5E0"); int func_002DC650(char *, char *, int);
// MATCH func_002CDF50
void FUN_002cdf50(char *d) { if (d != 0) { unsigned n; if (func_002DD5E0_002CDF50((char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000)) < 1024) n = func_002DD5E0_002CDF50((char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000)); else n = 1023; func_002DC650(d, (char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000), n); d[n] = 0; } }

int func_002C9420(void *, int); int func_002C9368(void *, int);
// MATCH func_002C2250
int FUN_002c2250(void *o) { func_002C9420(o, 56); func_002C9420(o, 40); while (func_002C9368(o, 1) == 1) func_002C9420(o, 24); return 1; }

typedef struct { long long q0; int w8, w12, w16; long long q24; int w32, w36, w40; } O_002C9330;
void func_002C9388(O_002C9330 *, int);
// MATCH func_002C9330
void FUN_002c9330(O_002C9330 *o, int b, int c, int d) { o->w40 = d; o->w8 = b; o->q0 = 0; o->w16 = 0; o->w12 = b; o->q24 = 0; o->w32 = c; o->w36 = c + d; func_002C9388(o, 0); }

void func_002E5950(unsigned *); void func_002E5940(unsigned *);
// MATCH func_002EDF80
int FUN_002edf80(void) { unsigned a[2]; func_002E5950(a); a[1] = (a[0] & 0xffff1fff) | 0x2000; func_002E5940(&a[1]); func_002E5950(&a[1]); func_002E5940(a); return ((a[1] >> 13) & 7) == 0; }

typedef struct { char p[20]; int w20; char q[4]; int w28, w32, w36, w40; } O_002E84A0;
typedef struct { char p[20]; int w20; char q[4]; int w28, w32; } P_002E84A0;
P_002E84A0 *func_002E8378(int); void func_002E7ED0(unsigned, P_002E84A0 *, int, int, int, int);
// MATCH func_002E84A0
void FUN_002e84a0(O_002E84A0 *o, int b) { P_002E84A0 *p = func_002E8378(b); int x = o->w20, y = o->w28; p->w20 = x; p->w28 = y; p->w32 = 0x8000000c; func_002E7ED0(0x80000008, p, 64, o->w32, o->w36, o->w40); }

int func_002D7E48(int, int); int func_002D78B8(int, int); long long func_002EF470(int);
// MATCH func_002EF410
long long FUN_002ef410(int a) { int z = 0; __asm__("" : "+r"(z)); if (func_002D7E48(a, z) < 0) return -func_002EF470(func_002D78B8(z, a)); return func_002EF470(a); }

typedef struct { int n0, n1; unsigned char *d0, *d1; unsigned char s0[64]; unsigned char s1[64]; } P_002CD728;
// MATCH func_002CD728
void FUN_002cd728(unsigned p) { P_002CD728 *q = (P_002CD728 *)((unsigned)p | 0x20000000); int i; if (q->n0 != 0) { unsigned char *d = q->d0; for (i = 0; i < q->n0; i++) *d++ = q->s0[i]; } if (q->n1 != 0) { unsigned char *d = q->d1; for (i = 0; i < q->n1; i++) *d++ = q->s1[i]; } }

extern int D_0042637C[]; extern int D_0062B644_002CB510[] __asm__("D_0062B644"), D_0062B648_002CB510[] __asm__("D_0062B648"); void func_002CB5C8(void); int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002CB510
int FUN_002cb510(int a, int b) { int r, old; if (D_0042637C[0] < 0) func_002CB5C8(); r = func_002EDC50(); old = D_0062B644_002CB510[0]; D_0062B648_002CB510[0] = b; D_0062B644_002CB510[0] = a; if (r != 0) func_002EDC98(); return old; }

extern char D_0049D3B0[], D_0049D3D0[]; int func_00295098(int); void func_002DC918(char *, ...); int func_002DBC48(int);
// MATCH func_002BF640
unsigned FullAllocAndFree(int a) { int r = func_00295098(a); unsigned n; func_002DC918(D_0049D3B0, r); n = ((unsigned)(func_002DBC48(a + 128) + 127) >> 7) << 7; func_002DC918(D_0049D3D0, n, a); return n; }

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF4B0;
int func_002CF458(void *);
// 2 words differ
// WIP func_002CF4B0
// MATCH func_002CF4B0
void FUN_002cf4b0(Pk_002CF4B0 *o, int x)
{
  int r = func_002CF458(o);
  int *p = o->w0;
  o->w8 = r;
  *(p++) = x | 0x10000000;
 do { } while (0);
  o->w12 = 0;
  o->w0 = p + 1;
  *p = 0;
}

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF610;
int func_002CF458(void *);
// 2 words differ
// WIP func_002CF610
// MATCH func_002CF610
void FUN_002cf610(Pk_002CF610 *o, int x)
{
  int r = func_002CF458(o);
  int *p = o->w0;
  o->w8 = r;
  *(p++) = x | 0x70000000;
 do { } while (0);
  o->w12 = 0;
  o->w0 = p + 1;
  *p = 0;
}

// MATCH func_002CADE8
int FUN_002cade8(void) { unsigned *p = (unsigned *)0x10003800; unsigned v; __asm__("" : "+r"(p)); v = *p; if (!(v & 3)) return 0; if (v & 0x700) return 1; if (v & 0xc) return 2; return (v & 0x3000) ? 3 : 4; }

extern int D_00427DCC_002CD7B8[] __asm__("D_00427DCC"), D_00427DC8_002CD7B8[] __asm__("D_00427DC8"), D_0062B900_002CD7B8[] __asm__("D_0062B900"), D_0062B980_002CD7B8[] __asm__("D_0062B980"), D_0062CEC0_002CD7B8[] __asm__("D_0062CEC0"); extern char D_0062BE00[]; int func_002E58F0(int); void func_002E58C0_002CD7B8(int) __asm__("func_002E58C0"); void func_002E8038(void *, int); int func_002E8928_002CD7B8(void *, int, int, void *, int, void *, int, void *, void *) __asm__("func_002E8928"); void func_002CD728(void);
// MATCH func_002CD7B8
int FUN_002cd7b8(int a, void *b, int c) { int r; if (func_002E58F0(D_00427DCC_002CD7B8[0]) < 0) return -200; if (D_0062B900_002CD7B8[9] == 0) { func_002E58C0_002CD7B8(D_00427DCC_002CD7B8[0]); return -100; } D_0062B980_002CD7B8[0] = a; D_0062B980_002CD7B8[7] = (int)D_0062BE00; D_0062B980_002CD7B8[6] = (int)b; D_0062B980_002CD7B8[3] = c; func_002E8038(b, c); func_002E8038(D_0062BE00, 192); r = func_002E8928_002CD7B8(D_0062B900_002CD7B8, 5, 1, D_0062B980_002CD7B8, 48, D_0062CEC0_002CD7B8, 4, (void *)func_002CD728, D_0062BE00); if (r == 0) D_00427DC8_002CD7B8[0] = 5; else func_002E58C0_002CD7B8(D_00427DCC_002CD7B8[0]); return r; }

void func_002BEB38(int, int); void func_00108B80_002BEAA0(int *) __asm__("func_00108B80");
// MATCH func_002BEAA0
void FUN_002beaa0(int *o, int flag) { int *p; if (o[404]) func_002BEB38(o[404], 3); p = o + 340; func_002BEB38((int)p, 2); flag &= 1; if (o != 0) { if (o != p) { do { p -= 68; func_002BEB38((int)p, 0); } while (o != p); } } if (flag) func_00108B80_002BEAA0(o); }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEF18_002CEF18;
int func_002CE9E8(int); void func_002CE8F0_002CEF18(Q_002CEF18_002CEF18 *) __asm__("func_002CE8F0");
// MATCH func_002CEF18
void FUN_002cef18(Q_002CEF18_002CEF18 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEF18(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; { int t = o->w0 & ~0xc; o->w0 = (t & ~1) | 0x100; } }

extern char D_00631A80_002D37C0[] __asm__("D_00631A80"); int func_002E8928_002D37C0(void *, int, int, int, int, int, int, int, int) __asm__("func_002E8928");
// MATCH func_002D37C0
int FUN_002d37c0(int a, int b, int c, int d, int e, int f) { return func_002E8928_002D37C0(D_00631A80_002D37C0, a, b, c, e, d, f, 0, 0); }

extern int D_0062B5C0_002CA318[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA318[] __asm__("D_0062B380"); int func_002E8928_002CA318(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
typedef struct { int w0; int a; int b; char c[8]; int w5; } T_2ca318_002CA318;
// MATCH func_002CA318
int FUN_002ca318(int a, int b, char *c) { T_2ca318_002CA318 *t = (T_2ca318_002CA318 *)D_0062B5C0_002CA318; int r; int v; int i; D_0062B5C0_002CA318[0] = 8; t->a = a; t->b = b; for (i = 0; i < 6; i++) t->c[i] = c[i]; r = func_002E8928_002CA318(D_0062B380_002CA318, 1, 0, t, 128, t, 128, 0, 0); if (r < 0) return 0; v = t->w5; if (v == 1) func_002C9D38(a, b, 2); return t->w5; }

extern char D_00427D88_002CC2D8[] __asm__("D_00427D88"); extern int D_00427540_002CC2D8[] __asm__("D_00427540"); extern int D_0042636C_002CC2D8[] __asm__("D_0042636C"); extern int D_00427980[];
int func_002CBC90(int); int func_002E8928_002CC2D8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58C0_002CC2D8(int) __asm__("func_002E58C0"); void func_002E8038(void *, int);
// MATCH func_002CC2D8
int FUN_002cc2d8(int a) { int *p = D_00427980; int r; int v; if (func_002CBC90(34) == 0) return 0; D_00427980[0] = a; func_002E8038(p, 4); r = func_002E8928_002CC2D8(D_00427D88_002CC2D8, 34, 0, p, 4, D_00427540_002CC2D8, 4, 0, 0); if (r < 0) { func_002E58C0_002CC2D8(D_0042636C_002CC2D8[0]); return 0; } v = *(int *)((unsigned)D_00427540_002CC2D8 | 0x20000000); func_002E58C0_002CC2D8(D_0042636C_002CC2D8[0]); return v; }

extern char D_00427D88_002CCAF0[] __asm__("D_00427D88"); extern int D_00427540_002CCAF0[] __asm__("D_00427540"); extern volatile int D_0042636C_002CCAF0[] __asm__("D_0042636C"); extern volatile int D_00426394_002CCAF0[] __asm__("D_00426394");
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CCAF0(int) __asm__("func_002E58C0");
// MATCH func_002CCAF0
int FUN_002ccaf0(void) { int r; int v; if (func_002CBC90(30) == 0) return 0; D_00426394_002CCAF0[0] = 8; r = func_002E8928(D_00427D88_002CCAF0, 22, 0, 0, 0, D_00427540_002CCAF0, 4, 0, 0); if (r < 0) { func_002E58C0_002CCAF0(D_0042636C_002CCAF0[0]); D_00426394_002CCAF0[0] = 0; return 0; } D_00426394_002CCAF0[0] = 0; v = *(int *)((unsigned)D_00427540_002CCAF0 | 0x20000000); func_002E58C0_002CCAF0(D_0042636C_002CCAF0[0]); return v; }

void *func_002CFF38(void); void func_002D04C0_002D3A08(int, unsigned, unsigned, unsigned) __asm__("func_002D04C0");
// MATCH func_002D3A08
void FUN_002d3a08(int a, unsigned b, unsigned c, unsigned d) { volatile int *r = func_002CFF38(); unsigned x5, x6, x7; r[18] = r[18] + 1; x7 = (c << 24) | (d & 0xffffff); x6 = (b << 16) | ((c >> 8) & 0xffff); x5 = (r[18] << 8) | ((b >> 16) & 0xff); func_002D04C0_002D3A08(a, x5, x6, x7); }

void func_002C2DA8(int);
// MATCH func_002C6E50
int FUN_002c6e50(char *p) { int i = 0; if ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000) { do { if (i++ > 5000) { func_002C2DA8(*(int *)(p + 2136)); i = 0; } } while ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000); return i; } }

int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002C8B28
void FUN_002c8b28(unsigned a, int b) { int r = func_002EDC50(); *(volatile unsigned *)0x1000b010 = (a & 0x0fffffff) | 0x80000000; *(volatile int *)0x1000b020 = b >> 4; *(volatile int *)0x1000b000 = 256; if (r != 0) func_002EDC98(); }

int func_002EDC50(void); int func_002EDC98_002C34B8(void) __asm__("func_002EDC98"); void func_002CFC00(int, int);
// MATCH func_002C34B8
void FUN_002c34b8(int *o) { int r; o[518] = 1; o[108] = 0; r = func_002EDC50(); *(volatile unsigned *)0x1000f590 = *(volatile unsigned *)0x1000f520 | 0x10000; *(volatile int *)0x1000b000 = 0; *(volatile int *)0x1000b400 = 0; *(volatile int *)0x1000d400 = 0; *(volatile unsigned *)0x1000f590 = *(volatile unsigned *)0x1000f520 & 0xfffeffff; if (r != 0) func_002EDC98_002C34B8(); *(volatile int *)0x1000b020 = 0; *(volatile int *)0x1000b420 = 0; *(volatile int *)0x1000d420 = 0; *(volatile unsigned *)0x10002010 = 0x40000000; func_002CFC00(0, 0); }

int func_002EDC50(void); void func_002EDC98(void); void func_002CFCD0(void);
// MATCH func_002C2870
void FUN_002c2870(void) { int r = func_002EDC50(); *(volatile unsigned *)0x1000f590 = *(volatile unsigned *)0x1000f520 | 0x10000; *(volatile unsigned *)0x1000b000 = *(volatile unsigned *)0x1000b000 & 0xfffffeff; *(volatile unsigned *)0x1000b400 = *(volatile unsigned *)0x1000b400 & 0xfffffeff; *(volatile unsigned *)0x1000f590 = *(volatile unsigned *)0x1000f520 & 0xfffeffff; if (r != 0) func_002EDC98(); *(volatile int *)0x1000b020 = 0; *(volatile int *)0x1000b420 = 0; func_002CFCD0(); }

extern unsigned D_00425510_002B9B98[] __asm__("D_00425510");
// MATCH func_002B9B98
void FUN_002b9b98(int n) { D_00425510_002B9B98[0] &= 0xfffff7ff; D_00425510_002B9B98[0] &= 0xffffefff; D_00425510_002B9B98[0] &= 0xffffdfff; D_00425510_002B9B98[n / 32] |= 1 << n; }

typedef struct { char p[16]; int wds; unsigned x[1]; } BI_002E30A8;
// MATCH func_002E30A8
int FUN_002e30a8(BI_002E30A8 *a, BI_002E30A8 *b) { int i, j; unsigned *xa, *xa0, *xb, *xb0; i = a->wds; j = b->wds; if (i -= j) return i; xa0 = a->x; xa = xa0 + j; xb0 = b->x; xb = xb0 + j; for (;;) { if (*--xa != *--xb) return *xa < *xb ? -1 : 1; if (xa <= xa0) break; } return 0; }

void func_002EDC50_002E8CC0(void) __asm__("func_002EDC50"); void func_002EDC98(void);
// MATCH func_002E8CC0
int *FUN_002e8cc0(int *n, int *h) { int *p; func_002EDC50_002E8CC0(); p = (int *)h[2]; if (p == n) h[2] = p[14]; else { for (; p != 0; p = (int *)p[14]) { if ((int *)p[14] == n) { p[14] = n[14]; break; } } } func_002EDC98(); return p; }

extern char D_00632310[];
int func_002E5CD0_002E6900(int, void *) __asm__("func_002E5CD0");
// MATCH func_002E6900
int FUN_002e6900(unsigned short a, int b, int c) { int st[4]; st[0] = a; st[1] = b; st[2] = c; st[3] = (int)D_00632310 | 0x20000000; return func_002E5CD0_002E6900(1, st); }

typedef struct { char f; char c; } E_002E67E8;
typedef struct { int x; int idx; E_002E67E8 e[512]; } S_002E67E8;
extern int D_00429880[]; extern S_002E67E8 D_00631F08; extern int D_00631F00[]; void func_002E58D0(int);
// MATCH func_002E67E8
int FUN_002e67e8(unsigned c) { int i; if (c >= 128 || D_00429880[0] == 0) return -1; i = D_00631F08.idx & 511; D_00631F08.idx = i + 1; D_00631F08.e[i].f = 1; D_00631F08.e[i].c = c; func_002E58D0(D_00631F00[0]); return c; }

extern unsigned long D_0049F2A0[]; unsigned long func_002D7920(unsigned long, unsigned long);
// MATCH func_002E36F8
unsigned long FUN_002e36f8(int n) { unsigned long r = 0x3ff0000000000000UL; if (n < 24) return D_0049F2A0[n]; while (n > 0) { r = func_002D7920(r, 0x4024000000000000UL); n--; } return r; }

// MATCH func_002DBBB0
unsigned FUN_002dbbb0(int param_1,unsigned (*param_2)())

{
  unsigned uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  unsigned uVar5;

  uVar5 = 0;
  piVar4 = (int *)(param_1 + 0x1d8);
  if (piVar4 != (int *)0x0) {
    iVar2 = piVar4[1];
    while (1) {
      iVar3 = piVar4[2];
      while (iVar2 = iVar2 + -1, -1 < iVar2) {
        if (*(short *)(iVar3 + 0xc) != 0) {
          uVar1 = (*param_2)(iVar3);
          uVar5 = uVar5 | uVar1;
        }
        iVar3 = iVar3 + 0x58;
      }
      piVar4 = (int *)*piVar4;
      if (piVar4 == (int *)0x0) break;
      iVar2 = piVar4[1];
    }
  }
  return uVar5;
}

void func_002C2DA8(int);
// MATCH func_002C6EF8
long FUN_002c6ef8(char *p) { long v; int i = 0; v = *(volatile long *)0x10002000; if (v < 0 && (*(volatile unsigned *)0x10002010 & 0x4000) == 0) { do { if (i++ > 5000) { func_002C2DA8(*(int *)(p + 2136)); i = 0; } v = *(volatile long *)0x10002000; } while (v < 0 && (*(volatile unsigned *)0x10002010 & 0x4000) == 0); } return v; }

extern int D_00426280_002C7228[] __asm__("D_00426280"); void func_002C2DA8(int); long func_002C6EF8(char *);
// MATCH func_002C7228
void FUN_002c7228(char *o, unsigned v) { int i = 0; unsigned w; if ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000) { do { if (i++ > 5000) { func_002C2DA8(*(int *)(o + 2136)); i = 0; } } while ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000); } w = v | 0x40000000; *(volatile unsigned *)0x10002000 = w; *(int *)(o + 2072) = D_00426280_002C7228[w >> 28]; *(int *)(o + 2104) = (int)func_002C6EF8(o); *(int *)(o + 2108) = 32; }

extern int D_00426280_002C7120[] __asm__("D_00426280"); void func_002C2DA8(int); long func_002C6EF8(char *);
// MATCH func_002C7120
unsigned FUN_002c7120(char *o, int n) { if (*(int *)(o + 2072) != 0 || *(int *)(o + 2108) < n) { int i = 0; if ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000) { do { if (i++ > 5000) { func_002C2DA8(*(int *)(o + 2136)); i = 0; } } while ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000); } *(volatile unsigned *)0x10002000 = 0x40000000; *(int *)(o + 2072) = D_00426280_002C7120[4]; *(int *)(o + 2104) = (int)func_002C6EF8(o); *(int *)(o + 2108) = 32; } return *(unsigned *)(o + 2104) >> (32 - n); }

void func_002C6E20(char *, unsigned); void func_002C2D58(int, int *); int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002C8BB0
void FUN_002c8bb0(char *o, unsigned a, int n) { int st[8]; int r; while ((int)*(volatile unsigned *)0x10002010 < 0) ; r = func_002EDC50(); *(volatile unsigned *)0x1000b010 = a & 0x0fffffff; *(volatile int *)0x1000b020 = n << 6; *(volatile int *)0x1000b000 = 256; if (r != 0) func_002EDC98(); func_002C6E20(o, n | 0x70000000); st[0] = 4; func_002C2D58(*(int *)(o + 2136), st); while ((*(volatile unsigned *)0x1000b000 >> 8) & 1) ; while ((int)*(volatile unsigned *)0x10002010 < 0) ; }

void func_002C6E50(int); void func_002C7228_002C7468(int, int) __asm__("func_002C7228"); int func_002C7120(int, int);
// MATCH func_002C7468
void FUN_002c7468(int a)
{
    unsigned v;
    int k;
    func_002C6E50(a);
    v = *(volatile unsigned *)0x10002020;
    k = (-(v & 7)) & 7;
    if (k != 0) func_002C7228_002C7468(a, k);
    while (func_002C7120(a, 24) != 1) func_002C7228_002C7468(a, 8);
}

extern int D_00426350_002CBC20[] __asm__("D_00426350");
extern char D_0049E090[], D_00427D88_002CBC20[] __asm__("D_00427D88");
void func_002E7940(void *); void func_002CB040(int); int func_002E8B18_002CBC20(void *) __asm__("func_002E8B18");
// MATCH func_002CBC20
int FUN_002cbc20(int a)
{
    if (a == 0) {
        if (D_00426350_002CBC20[0] > 0) func_002E7940(D_0049E090);
        while (func_002E8B18_002CBC20(D_00427D88_002CBC20) != 0) func_002CB040(60);
        return 0;
    }
    return func_002E8B18_002CBC20(D_00427D88_002CBC20);
}

int func_002CAA38(void); int func_002CAA88(void); void func_002CAA78(int);
// MATCH func_002CA968
int FUN_002ca968(void) { int r = 0; int n = func_002CAA38(); if (n < 4) { if (n > 0) { r = 1; func_002CAA78(func_002CAA88()); } } return r; }

extern int D_00634200[];
int func_002EDC50(void); int func_002EDC98_002E8D58(void) __asm__("func_002EDC98");
// MATCH func_002E8D58
int *FUN_002e8d58(int *n) { int *p; func_002EDC50(); p = (int *)D_00634200[10];
if (p == n) D_00634200[10] = p[5]; else { for (; p != 0; p = (int *)p[5]) { if ((int *)p[5] == n) { p[5] = n[5]; break; } } } func_002EDC98_002E8D58(); return p; }

void func_002C5C38(int);
// MATCH func_002C3458
void FUN_002c3458(char *o) { int c = 0x70000000; func_002C5C38(1); *(int *)(o + 1424) = c; *(int *)(o + 1428) = 0x70001800; *(int *)(o + 1744) = 0x70001b00; *(int *)(o + 1748) = 0x70003300; *(int *)(o + 2064) = 0; }

// MATCH func_002D9880
int FUN_002d9880(char *p) { int off, n, t; off = *(int *)p; n = 0; if (off != 0) { for (;;) { if (*(int *)(p + 4) != 0) { if (*(int *)(p + 8) != 0) n++; } t = *(int *)(p + off + 4); p = p + off + 4; if (t == 0) break; off = t; } } return n; }

extern unsigned D_004A6B40_002B9250 __asm__("D_004A6B40"); extern char D_0041EF40[], D_004A6A18[];
int func_00160C70_002B9250(int, char *, int) __asm__("func_00160C70"); int func_002B3F10(int, void *, void *); void func_002A0190(void *); void func_002BEEA0(void *);
// MATCH func_002B9250
void FUN_002b9250(char *p) { char *q; int u; q = *(char **)(p + 0xd8); if ((D_004A6B40_002B9250 & 8) == 0) { u = func_00160C70_002B9250((int)D_0041EF40, D_004A6A18, *(int *)(q + 0x1e8)); func_002B3F10(u, q, q + 0x1ec); } *(int *)(q + 0x1f0) = 0x15002; func_002A0190(q); func_002BEEA0(q); }

void func_002CF960(int); void func_002CF8F8(int);
// MATCH func_002CF9C8
void FUN_002cf9c8(unsigned *o) { func_002CF960(1); o[0] = *(volatile unsigned *)0x1000b410; o[1] = *(volatile unsigned *)0x1000b430; o[2] = *(volatile unsigned *)0x1000b420; o[3] = *(volatile unsigned *)0x1000b400; while (*(volatile unsigned *)0x10002010 & 0xf0) ; func_002CF8F8(0); o[4] = *(volatile unsigned *)0x1000b010; o[5] = *(volatile unsigned *)0x1000b020; o[6] = *(volatile unsigned *)0x1000b000; o[7] = *(volatile unsigned *)0x10002020; o[8] = *(volatile unsigned *)0x10002010; }

// MATCH func_002CF458
int *FUN_002cf458(int *o) { int *w; int *p; w = (int *)o[2]; for (p = (int *)*o; ((unsigned)p & 0xc) != 0; p++) *p = 0; if (w != 0) *w = *w - 1 + (((int)p - (int)w) >> 4); *o = (int)p; o[2] = 0; return p; }

// MATCH func_002CF158
int *FUN_002cf158(int *o) { int *w; int *p; w = (int *)o[2]; for (p = (int *)*o; ((unsigned)p & 0xc) != 0; p++) *p = 0; if (w != 0) *w = *w - 1 + (((int)p - (int)w) >> 4); *o = (int)p; o[2] = 0; return p; }

// MATCH func_002E8378
int FUN_002e8378(char *o) { int new_var; int i; i = (*((int *) (o + 0x24))) % (*((int *) (o + 0x18))); new_var = i * 0x40; *((int *) (o + 0x24)) = i + 1; return (*((int *) (o + 0x14))) + new_var; }

void func_002EDC50_002E6198(void) __asm__("func_002EDC50"); void func_002EDC98(void); void func_002E60F0(unsigned, unsigned);
// MATCH func_002E6198
void FUN_002e6198(unsigned a, unsigned b) { int st; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50_002E6198(); func_002E60F0(a & 0xffffffc0, b & 0xffffffc0); if (st) func_002EDC98(); }

void func_002EDC50_002E62D8(void) __asm__("func_002EDC50"); void func_002EDC98(void); void func_002E6230(unsigned, unsigned);
// MATCH func_002E62D8
void FUN_002e62d8(unsigned a, unsigned b) { int st; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50_002E62D8(); func_002E6230(a & 0xffffffc0, b & 0xffffffc0); if (st) func_002EDC98(); }

// MATCH func_002E60F0
void FUN_002e60f0(unsigned a, unsigned b) { int i; unsigned t; i = 0; do { __asm__ volatile("sync"); __asm__ volatile("cache 0x10, 0(%0)" : : "r"(i)); __asm__ volatile("sync"); __asm__ volatile("mfc0 %0, $28" : "=r"(t)); t = (t & 0xfffff000) + i; if (a <= t && t <= b) { __asm__ volatile("sync"); __asm__ volatile("cache 0x14, 0(%0)" : : "r"(i)); __asm__ volatile("sync"); } __asm__ volatile("sync"); __asm__ volatile("cache 0x10, 1(%0)" : : "r"(i)); __asm__ volatile("sync"); __asm__ volatile("mfc0 %0, $28" : "=r"(t)); t = (t & 0xfffff000) + i; if (a <= t && t <= b) { __asm__ volatile("sync"); __asm__ volatile("cache 0x14, 1(%0)" : : "r"(i)); __asm__ volatile("sync"); } __asm__ volatile("sync"); i = i + 64; } while (i < 4096); }

// MATCH func_002E6230
void FUN_002e6230(unsigned a, unsigned b) { int i; unsigned t; i = 0; do { __asm__ volatile("sync"); __asm__ volatile("cache 0x10, 0(%0)" : : "r"(i)); __asm__ volatile("sync"); __asm__ volatile("mfc0 %0, $28" : "=r"(t)); t = (t & 0xfffff000) + i; if (a <= t && t <= b) { __asm__ volatile("sync"); __asm__ volatile("cache 0x16, 0(%0)" : : "r"(i)); __asm__ volatile("sync"); } __asm__ volatile("sync"); __asm__ volatile("cache 0x10, 1(%0)" : : "r"(i)); __asm__ volatile("sync"); __asm__ volatile("mfc0 %0, $28" : "=r"(t)); t = (t & 0xfffff000) + i; if (a <= t && t <= b) { __asm__ volatile("sync"); __asm__ volatile("cache 0x16, 1(%0)" : : "r"(i)); __asm__ volatile("sync"); } __asm__ volatile("sync"); i = i + 64; } while (i < 4096); }

int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002E5D30
void FUN_002e5d30(void) { int r; r = func_002EDC50(); *(volatile int *)0x1000f000 = 4; __asm__ volatile("sync"); if (r) func_002EDC98(); while ((*(volatile int *)0x1000f000 & 4) == 0) ; r = func_002EDC50(); *(volatile int *)0x1000f000 = 4; __asm__ volatile("sync"); if (r) func_002EDC98(); }

int func_002EDC50(void); void func_002EDC98(void); void func_002E5C10(volatile int *, volatile long long *);
// MATCH func_002E5DC0
long long FUN_002e5dc0(void) { volatile int flag; volatile long long out; int r; flag = 0; func_002E5C10(&flag, &out); r = func_002EDC50(); *(volatile int *)0x1000f000 = 4; __asm__ volatile("sync"); if (r) func_002EDC98(); while ((*(volatile int *)0x1000f000 & 4) == 0 && flag == 0) ; r = func_002EDC50(); *(volatile int *)0x1000f000 = 4; __asm__ volatile("sync"); if (r) func_002EDC98(); return out; }

typedef struct { void (*fn)(int); int arg; } CB9688_002E9688;
// MATCH func_002E9688
void FUN_002e9688(int a, CB9688_002E9688 *c) { if (c->fn != 0) c->fn(c->arg); __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); }

typedef struct { unsigned len; unsigned addr; } DM_002C8FD8;
// MATCH func_002C8FD8
int FUN_002c8fd8(int a, DM_002C8FD8 *p) { *(volatile int *)0x1000e010 = 16; if (p->len == 0) return 1; if (p->len > 0xffff) { *(volatile unsigned *)0x1000b410 = p->addr; *(volatile unsigned *)0x1000b420 = 0xffff; *(volatile unsigned *)0x1000b400 = 257; p->addr = (p->addr + 0xffff0) & 0xfffffff; p->len = p->len - 0xffff; } else { *(volatile unsigned *)0x1000b410 = p->addr; *(volatile unsigned *)0x1000b420 = p->len; *(volatile unsigned *)0x1000b400 = 257; p->len = 0; } __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return 0; }

typedef struct { int *w0; } PkW_002CF8C8;
// MATCH func_002CF8C8
void FUN_002cf8c8(PkW_002CF8C8 *o, int a, long long b) { int *p; p = o->w0; *(p++) = (int)b; p[0] = (int)(b >> 32); o->w0 = p + 3; p[1] = a; p[2] = 0; }

int func_002C5E60(long long); void func_002C6AA8(int *, unsigned, int, int, int); short func_002C6FA8(int, int); unsigned func_002C7318_002C6CD0(long long, unsigned) __asm__("func_002C7318");
// MATCH func_002C6CD0
void FUN_002c6cd0(int p1, int *p2, int *p3, int p4, int p5, int p6, int p7, int p8) { int l; int v; int *q; l = func_002C6FA8(p1, 2); if (p4 != 0 && l != 0) { v = func_002C7318_002C6CD0(p1, p4); } else { v = 0; } func_002C6AA8(p2, p4, l, v, p8); if (p6 != 0) { *p3 = func_002C5E60(p1); } l = func_002C6FA8(p1, 2); if (p5 != 0 && l != 0) { v = func_002C7318_002C6CD0(p1, p5); } else { v = 0; } q = p2; if (p7 != 0) { q[1] = q[1] >> 1; } func_002C6AA8(q + 1, p5, l, v, p8); if (p7 != 0) { q[1] = q[1] << 1; } if (p6 != 0) { p3[1] = func_002C5E60(p1); } }

extern char D_00621120[]; extern unsigned char D_00621320_002BB650[] __asm__("D_00621320"); void func_00242F40(unsigned char *); void func_002445F0(int); void func_0023FE68(int, int);
// MATCH func_002BB650
void FUN_002bb650(int *param_1) { int new_var; param_1[0x7c] = param_1[0x7c] & 0xff7fffff; *((unsigned *) ((*param_1) + 0x18)) = (*((unsigned *) ((*param_1) + 0x18))) & 0xfffffffd; if ((&D_00621120[0])[param_1[0x79]] != '\0') { func_00242F40((&D_00621320_002BB650[0]) + (param_1[0x79] * 0x4c)); (&D_00621120[0])[param_1[0x79]] = 0; } func_002445F0(*param_1); if (9999 < (*((short *) ((*param_1) + 0xac)))) { new_var = *param_1; func_0023FE68(new_var, 0); return; } return; }

void func_002E6750_002E8898(void) __asm__("func_002E6750");
// MATCH func_002E8898
void FUN_002e8898(int p) { int q; int *r; int a, b; q = *(int *)(p + 0x34); r = *(int **)(q + 0x40); if (r[3] == 0) { r[3] = q; } else { *(int *)(r[4] + 0x3c) = q; } r[4] = q; a = *(int *)(p + 0x14); b = *(int *)(p + 0x1c); *(int *)(q + 0x20) = a; *(int *)(q + 0x1c) = b; *(int *)(q + 0x24) = *(int *)(p + 0x20); *(int *)(q + 0xc) = *(int *)(p + 0x24); *(int *)(q + 0x28) = *(int *)(p + 0x28); *(int *)(q + 0x2c) = *(int *)(p + 0x2c); *(int *)(q + 0x30) = *(int *)(p + 0x30); *(int *)(q + 0x34) = *(int *)(p + 0x10); p = *r; if ((-1 < p) && (r[1] == 0)) { func_002E6750_002E8898(); return; } return; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002CA5B8;
extern E28_002CA5B8 D_0062B3D0[][4];
int func_002CA4A8(int, int, int);
// MATCH func_002CA5B8
int FUN_002ca5b8(int a, int b) { if (D_0062B3D0[a][b].a16 == 0) return 0; return func_002CA4A8(a, b, 0xfff); }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002CA610;
extern E28_002CA610 D_0062B3D0_002CA610[][4] __asm__("D_0062B3D0");
int func_002CA4A8_002CA610(int, int, int) __asm__("func_002CA4A8");
// MATCH func_002CA610
int FUN_002ca610(int a, int b) { if (D_0062B3D0_002CA610[a][b].a16 == 0) return 0; return func_002CA4A8_002CA610(a, b, 0); }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002CA558;
extern E28_002CA558 D_0062B3D0_002CA558[][4] __asm__("D_0062B3D0");
int func_002CA3F0(int, int);
// MATCH func_002CA558
int FUN_002ca558(int a, int b) { if (D_0062B3D0_002CA558[a][b].a16 == 0) return 0; return func_002CA3F0(a, b) == 0x3ffff; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002CA3F0;
extern E28_002CA3F0 D_0062B3D0_002CA3F0[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002CA3F0
int FUN_002ca3f0(int a, int b) { unsigned char *p; if (D_0062B3D0_002CA3F0[a][b].a16 == 0) return 0; p = func_002C9B58(a, b); if (p[0x72] != 1) return 0; if (p[100] < 2) return 0; if (p[0x66] < 2) return 0; return (int)(long)p[0x79] + ((long)p[0x7a] << 8) + ((long)p[0x7b] << 16) + ((long)p[0x7c] << 24); }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002C9BB8;
extern E28_002C9BB8 D_0062B3D0_002C9BB8[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002C9BB8
int FUN_002c9bb8(int a, int b) { if (D_0062B3D0_002C9BB8[a][b].a16 == 0) return 0; return *(int *)(func_002C9B58(a, b) + 0x58); }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002C9C08;
extern E28_002C9C08 D_0062B3D0_002C9C08[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002C9C08
int FUN_002c9c08(int a, int b, void *dst) { char *src; if (D_0062B3D0_002C9C08[a][b].a16 == 0) return 0; src = func_002C9B58(a, b); memcpy(dst, src, *(unsigned *)(src + 0x60)); return *(int *)(src + 0x60); }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002C9C88;
extern E28_002C9C88 D_0062B3D0_002C9C88[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002C9C88
int FUN_002c9c88(int a, int b) { unsigned char *p; if (D_0062B3D0_002C9C88[a][b].a16 == 0) return 99; p = func_002C9B58(a, b); if (p[0x70] != 6) return p[0x70]; if (p[0x71] == 2) return 5; return p[0x70]; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002C9D38;
extern E28_002C9D38 D_0062B3D0_002C9D38[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002C9D38
int FUN_002c9d38(int a, int b, int v) { unsigned char *p; if (D_0062B3D0_002C9D38[a][b].a16 == 0) return 0; p = func_002C9B58(a, b); p[0x71] = v; return 1; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002C9DA0;
extern E28_002C9DA0 D_0062B3D0_002C9DA0[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
// MATCH func_002C9DA0
int FUN_002c9da0(int a, int b) { if (D_0062B3D0_002C9DA0[a][b].a16 == 0) return 0; return func_002C9B58(a, b)[0x71]; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } E28_002CA258;
extern E28_002CA258 D_0062B3D0_002CA258[][4] __asm__("D_0062B3D0");
unsigned char *func_002C9B58(int, int);
int func_002C9540(int, int);
// MATCH func_002CA258
int FUN_002ca258(int a, int b, char *src) { int r; int i; char *rec; char *q; if (func_002C9B58(a, b)[0x72] != 1) return 0; i = 0; rec = (char *)D_0062B3D0_002CA258[a][b].a4; q = rec + 0xc; do { q[i] = src[i]; i++; } while (i < 6); r = 1; *(int *)(rec + 4) = r; *(int *)(rec + 8) = 6; if (func_002C9540(a, b) != 1) r = 0; return r; }

void *func_002CFF20_002D4C50(int) __asm__("func_002CFF20"); void func_002D4B20(unsigned);
// MATCH func_002D4C50
void FUN_002d4c50(int a) { volatile unsigned *p; unsigned i; unsigned v; i = 0; p = func_002CFF20_002D4C50(0); do { v = i | (a << 15); i++; *p = *p | 0x2000; if ((*p & 5) == 4) func_002D4B20(v); *p = *p & 0xffffdfff; p = p + 21; } while ((int)i < 48); }

void func_0029D010_002BECB0(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002BECB0
void FUN_002becb0(char *o, int p, float a, float b) { func_0029D010_002BECB0(o + 80, a, 0, p); func_0029D010_002BECB0(o + 120, b, 0, p); }

void func_0029D010_002BED60(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002BED60
void FUN_002bed60(char *o, int b, float x, float y, float z) { func_0029D010_002BED60(o, x, 0, b); func_0029D010_002BED60(o + 20, y, 0, b); func_0029D010_002BED60(o + 40, z, 0, b); }

void func_0029D010_002BED08(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002BED08
void FUN_002bed08(char *o, int p, float a, float b) { func_0029D010_002BED08(o + 60, a, 0, p); func_0029D010_002BED08(o + 100, b, 0, p); }
