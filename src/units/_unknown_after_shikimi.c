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

int func_002D7E48_2EF410(int, int) __asm__("func_002D7E48"); int func_002D78B8_2EF410(int, int) __asm__("func_002D78B8"); long long func_002EF470_2EF410(int) __asm__("func_002EF470");
// MATCH func_002EF410
long long FUN_002ef410(int a) { int z = 0; __asm__("" : "+r"(z)); if (func_002D7E48_2EF410(a, z) < 0) return -func_002EF470_2EF410(func_002D78B8_2EF410(z, a)); return func_002EF470_2EF410(a); }

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
int func_002CF458_2CF4B0(void *) __asm__("func_002CF458");
// 2 words differ
// WIP func_002CF4B0_2CF4B0
// MATCH func_002CF4B0
void FUN_002cf4b0(Pk_002CF4B0 *o, int x) { int r = func_002CF458_2CF4B0(o); int *p = o->w0; o->w8 = r; *(p++) = x | 0x10000000; do { } while (0); o->w12 = 0; o->w0 = p + 1; *p = 0; }

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF610;
int func_002CF458_2CF610(void *) __asm__("func_002CF458");
// 2 words differ
// WIP func_002CF610_2CF610
// MATCH func_002CF610
void FUN_002cf610(Pk_002CF610 *o, int x) { int r = func_002CF458_2CF610(o); int *p = o->w0; o->w8 = r; *(p++) = x | 0x70000000; do { } while (0); o->w12 = 0; o->w0 = p + 1; *p = 0; }

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

void func_002C6E20_2C8BB0(char *, unsigned) __asm__("func_002C6E20"); void func_002C2D58_2C8BB0(int, int *) __asm__("func_002C2D58"); int func_002EDC50_2C8BB0(void) __asm__("func_002EDC50"); void func_002EDC98_2C8BB0(void) __asm__("func_002EDC98");
// MATCH func_002C8BB0
void FUN_002c8bb0(char *o, unsigned a, int n) { int st[8]; int r; while ((int)*(volatile unsigned *)0x10002010 < 0) ; r = func_002EDC50_2C8BB0(); *(volatile unsigned *)0x1000b010 = a & 0x0fffffff; *(volatile int *)0x1000b020 = n << 6; *(volatile int *)0x1000b000 = 256; if (r != 0) func_002EDC98_2C8BB0(); func_002C6E20_2C8BB0(o, n | 0x70000000); st[0] = 4; func_002C2D58_2C8BB0(*(int *)(o + 2136), st); while ((*(volatile unsigned *)0x1000b000 >> 8) & 1) ; while ((int)*(volatile unsigned *)0x10002010 < 0) ; }

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

typedef struct { int sem; int *res; int w8; char name[1032]; } T_2ea9f0_002EA9F0;
extern T_2ea9f0_002EA9F0 D_00634280[]; extern char D_00635540[]; extern char D_00634EC0[]; extern int D_00429918[];
typedef struct { int a[8]; } S_2ea9f0_002EA9F0;
void func_002E95B0_002EA9F0(int) __asm__("func_002E95B0"); void func_002E96B8_002EA9F0(void) __asm__("func_002E96B8"); int func_002E58A0_002EA9F0(void *) __asm__("func_002E58A0"); int func_002E8928_002EA9F0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EA9F0(int) __asm__("func_002E58B0"); void func_002E95E0_002EA9F0(void) __asm__("func_002E95E0"); void func_002E58E0_002EA9F0(int) __asm__("func_002E58E0");
// MATCH func_002EA9F0
int FUN_002ea9f0(char *name, int b) { T_2ea9f0_002EA9F0 *t = D_00634280; S_2ea9f0_002EA9F0 s; int res; int i; int sem; int r; int v; unsigned c; func_002E95B0_002EA9F0(b); if (D_00429918[0] == 0) func_002E96B8_002EA9F0(); i = 0; if ((t->name[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name[i] = name[i]) == 0) break; } } if (i == 1024) { t->name[1023] = 0; i = 1023; } s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_002EA9F0(&s); t->sem = sem; t->res = &res; t->w8 = 4; r = func_002E8928_002EA9F0(D_00635540, b, 0, D_00634280, i + 13, D_00634EC0, 4, 0, 0); if (r < 0) { func_002E58B0_002EA9F0(sem); func_002E95E0_002EA9F0(); return -11; } v = *(int *)((unsigned)D_00634EC0 | 0x20000000); func_002E95E0_002EA9F0(); if (v == 0) { func_002E58B0_002EA9F0(sem); return -11; } func_002E58E0_002EA9F0(sem); func_002E58B0_002EA9F0(sem); return res; }

typedef struct { int sem; int *res; int w8; int w12; char name[1032]; } T_2eabb8_002EABB8;
extern T_2eabb8_002EABB8 D_00634280_002EABB8[] __asm__("D_00634280"); extern char D_00635540_002EABB8[] __asm__("D_00635540"); extern char D_00634EC0_002EABB8[] __asm__("D_00634EC0"); extern int D_00429918_002EABB8[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eabb8_002EABB8;
void func_002E95B0_002EABB8(int) __asm__("func_002E95B0"); void func_002E96B8_002EABB8(void) __asm__("func_002E96B8"); int func_002E58A0_002EABB8(void *) __asm__("func_002E58A0"); int func_002E8928_002EABB8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EABB8(int) __asm__("func_002E58B0"); void func_002E95E0_002EABB8(void) __asm__("func_002E95E0"); void func_002E58E0_002EABB8(int) __asm__("func_002E58E0");
// MATCH func_002EABB8
int FUN_002eabb8(char *name, int b) { T_2eabb8_002EABB8 *t = D_00634280_002EABB8; S_2eabb8_002EABB8 s; int res; int i; int sem; int r; int v;
  func_002E95B0(7); if (D_00429918_002EABB8[0] == 0) func_002E96B8();
  i = 0;
  if ((t->name[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name[i] = name[i]) == 0) break; } }
  if (i == 1024) { t->name[1023] = 0; i = 1023; }
  s.a[2] = 0; s.a[1] = 1; s.a[5] = 0;
  t->w12 = b;
  sem = func_002E58A0(&s); t->sem = sem; t->res = &res; t->w8 = 4;
  r = func_002E8928(D_00635540_002EABB8, 7, 0, D_00634280_002EABB8, i + 17, D_00634EC0_002EABB8, 4, 0, 0);
  if (r < 0) { func_002E58B0(sem); func_002E95E0(); return -11; }
  v = *(int *)((unsigned)D_00634EC0_002EABB8 | 0x20000000);
  func_002E95E0();
  if (v == 0) { func_002E58B0(sem); return -11; }
  func_002E58E0(sem); func_002E58B0(sem);
return res; }

typedef struct { int sem; int *res; int w8; int w12; char name[1032]; } T_2eb4c0_002EB4C0;
extern T_2eb4c0_002EB4C0 D_00634280_002EB4C0[] __asm__("D_00634280"); extern char D_00635540_002EB4C0[] __asm__("D_00635540"); extern char D_00634EC0_002EB4C0[] __asm__("D_00634EC0"); extern int D_00429918_002EB4C0[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eb4c0_002EB4C0;
void func_002E95B0_002EB4C0(int) __asm__("func_002E95B0"); void func_002E96B8_002EB4C0(void) __asm__("func_002E96B8"); int func_002E58A0_002EB4C0(void *) __asm__("func_002E58A0"); int func_002E8928_002EB4C0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EB4C0(int) __asm__("func_002E58B0"); void func_002E95E0_002EB4C0(void) __asm__("func_002E95E0"); void func_002E58E0_002EB4C0(int) __asm__("func_002E58E0");
// MATCH func_002EB4C0
int FUN_002eb4c0(char *name, int b) { T_2eb4c0_002EB4C0 *t = D_00634280_002EB4C0; S_2eb4c0_002EB4C0 s; int res; int i; int sem; int r; int v; unsigned char c;
  func_002E95B0(12); if (D_00429918_002EB4C0[0] == 0) func_002E96B8();
  i = 0; c = t->name[0] = name[0];
  if (c != 0) { while (++i < 1024) { c = t->name[i] = name[i]; if (c == 0) break; } }
  if (i == 1024) { t->name[1023] = 0; i = 1023; }
  s.a[2] = 0; s.a[1] = 1; s.a[5] = 0;
  t->w12 = b;
  sem = func_002E58A0(&s); t->sem = sem; t->res = &res; t->w8 = 4;
  r = func_002E8928(D_00635540_002EB4C0, 12, 0, D_00634280_002EB4C0, i + 17, D_00634EC0_002EB4C0, 4, 0, 0);
  if (r < 0) { func_002E58B0(sem); func_002E95E0(); return -11; }
  v = *(int *)((unsigned)D_00634EC0_002EB4C0 | 0x20000000);
  func_002E95E0();
  if (v == 0) { func_002E58B0(sem); return -11; }
  func_002E58E0(sem); func_002E58B0(sem);
return res; }

typedef struct { int sem; int *res; int w8; int wc; int w16; char name[1024]; } T_2ebab0_002EBAB0;
extern T_2ebab0_002EBAB0 D_00634280_002EBAB0[] __asm__("D_00634280"); extern char D_00635540_002EBAB0[] __asm__("D_00635540"); extern char D_00634EC0_002EBAB0[] __asm__("D_00634EC0"); extern int D_00429918_002EBAB0[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ebab0_002EBAB0;
void func_002E95B0_002EBAB0(int) __asm__("func_002E95B0"); void func_002E96B8_002EBAB0(void) __asm__("func_002E96B8"); int func_002E58A0_002EBAB0(void *) __asm__("func_002E58A0"); int func_002E8928_002EBAB0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EBAB0(int) __asm__("func_002E58B0"); void func_002E95E0_002EBAB0(void) __asm__("func_002E95E0"); void func_002E58E0_002EBAB0(int) __asm__("func_002E58E0");
// MATCH func_002EBAB0
int FUN_002ebab0(char *name, int b) { T_2ebab0_002EBAB0 *t = D_00634280_002EBAB0; S_2ebab0_002EBAB0 s; int res; int i; int sem; int r; int v;
  func_002E95B0(19); if (D_00429918_002EBAB0[0] == 0) func_002E96B8();
  i = 0;
  if ((t->name[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name[i] = name[i]) == 0) break; } }
  if (i == 1024) { t->name[1023] = 0; }
  s.a[2] = 0; s.a[1] = 1; s.a[5] = 0;
  t->w16 = b;
  sem = func_002E58A0(&s); t->sem = sem; t->res = &res; t->w8 = 4;
  r = func_002E8928(D_00635540_002EBAB0, 19, 0, D_00634280_002EBAB0, 1044, D_00634EC0_002EBAB0, 4, 0, 0);
  if (r < 0) { func_002E58B0(sem); func_002E95E0(); return -11; }
  v = *(int *)((unsigned)D_00634EC0_002EBAB0 | 0x20000000);
  func_002E95E0();
  if (v == 0) { func_002E58B0(sem); return -11; }
  func_002E58E0(sem); func_002E58B0(sem);
return res; }

typedef struct { int sem; int *res; int w8; int wc; } T_2eaff8_002EAFF8;
extern T_2eaff8_002EAFF8 D_00634280_002EAFF8[] __asm__("D_00634280"); extern char D_00635540_002EAFF8[] __asm__("D_00635540"); extern char D_00634EC0_002EAFF8[] __asm__("D_00634EC0"); extern int D_00429918_002EAFF8[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eaff8_002EAFF8;
int func_002E95B0_002EAFF8(int) __asm__("func_002E95B0"); void func_002E96B8_002EAFF8(void) __asm__("func_002E96B8"); int func_002E58A0_002EAFF8(void *) __asm__("func_002E58A0"); int func_002E8928_002EAFF8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EAFF8(int) __asm__("func_002E58B0"); void func_002E95E0_002EAFF8(void) __asm__("func_002E95E0"); void func_002E58E0_002EAFF8(int) __asm__("func_002E58E0");
// MATCH func_002EAFF8
int FUN_002eaff8(int a) { T_2eaff8_002EAFF8 *t = D_00634280_002EAFF8; S_2eaff8_002EAFF8 s; int res; int sem; int r; int v;
  func_002E95B0_002EAFF8(15); if (D_00429918_002EAFF8[0] == 0) func_002E96B8();
  s.a[2] = 0; s.a[1] = 1; s.a[5] = 0;
  t->wc = a;
  sem = func_002E58A0(&s); t->res = &res; t->sem = sem; t->w8 = 4;
  r = func_002E8928(D_00635540_002EAFF8, 15, 0, D_00634280_002EAFF8, 16, D_00634EC0_002EAFF8, 4, 0, 0);
  if (r < 0) { func_002E58B0(sem); func_002E95E0(); return -1; }
  v = *(int *)((unsigned)D_00634EC0_002EAFF8 | 0x20000000);
  func_002E95E0();
  if (v == 0) { func_002E58B0(sem); return -1; }
  func_002E58E0(sem); func_002E58B0(sem);
return res; }

typedef struct { int sem; int *res; int w8; int wc; int w16; } T_2eb368_002EB368;
extern T_2eb368_002EB368 D_00634280_002EB368[] __asm__("D_00634280"); extern char D_00635540_002EB368[] __asm__("D_00635540"); extern char D_00634EC0_002EB368[] __asm__("D_00634EC0"); extern int D_00429918_002EB368[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eb368_002EB368;
void func_002E95B0_002EB368(int) __asm__("func_002E95B0"); void func_002E96B8_002EB368(void) __asm__("func_002E96B8"); int func_002E58A0_002EB368(void *) __asm__("func_002E58A0"); int func_002E8928_002EB368(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_002EB368(int) __asm__("func_002E58B0"); void func_002E95E0_002EB368(void) __asm__("func_002E95E0"); void func_002E58E0_002EB368(int) __asm__("func_002E58E0"); int *func_002E9130_002EB368(void) __asm__("func_002E9130");
// MATCH func_002EB368
int FUN_002eb368(int a, int b) { T_2eb368_002EB368 *t = D_00634280_002EB368; S_2eb368_002EB368 s; int res; int sem; int r; int v; int *h;
  h = func_002E9130(); func_002E95B0(11);
  if (D_00429918_002EB368[0] == 0) { func_002E95E0(); return -1; }
  if (h == 0 || h[1] == 0) { func_002E95E0(); return -9; }
  t->wc = h[0]; s.a[2] = 0; s.a[5] = 0; t->w16 = b; s.a[1] = 1;
  sem = func_002E58A0(&s); t->res = &res; t->sem = sem; t->w8 = 4;
  r = func_002E8928(D_00635540_002EB368, 11, 0, D_00634280_002EB368, 32, D_00634EC0_002EB368, 4, 0, 0);
  if (r < 0) { func_002E58E0(sem); func_002E95E0(); return -11; }
  v = *(int *)((unsigned)D_00634EC0_002EB368 | 0x20000000);
  func_002E95E0();
  if (v == 0) { func_002E58B0(sem); return -11; }
  func_002E58E0(sem); func_002E58B0(sem);
return res; }

typedef struct { int sem; int *res; int w8; int wc; int w16; char name[1024]; } T_2ec528_002EC528;
extern T_2ec528_002EC528 D_00634280_2EC528[] __asm__("D_00634280"); extern char D_00635540_2EC528[] __asm__("D_00635540"); extern char D_00634EC0_2EC528[] __asm__("D_00634EC0"); extern int D_00429918_2EC528[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ec528_002EC528;
void func_002E95B0_2EC528(int) __asm__("func_002E95B0"); void func_002E96B8_2EC528(void) __asm__("func_002E96B8"); int func_002E58A0_2EC528(void *) __asm__("func_002E58A0"); int func_002E8928_2EC528(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EC528(int) __asm__("func_002E58B0"); void func_002E95E0_2EC528(void) __asm__("func_002E95E0"); void func_002E58E0_2EC528(int) __asm__("func_002E58E0"); void func_002E8038_2EC528(int, unsigned) __asm__("func_002E8038");
// MATCH func_002EC528
int FUN_002ec528(char *name, int b, unsigned c) { T_2ec528_002EC528 *t = D_00634280_2EC528; S_2ec528_002EC528 s; int res; int i; int sem; int r; int v; func_002E95B0_2EC528(17); if (D_00429918_2EC528[0] == 0) func_002E96B8_2EC528(); i = 0; if ((t->name[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name[i] = name[i]) == 0) break; } } if (i == 1024) { t->name[1023] = 0; } if (c > 1023) c = 1023; t->w16 = b; t->wc = c; func_002E8038_2EC528(b, c); s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EC528(&s); t->sem = sem; t->w8 = 4; t->res = &res; r = func_002E8928_2EC528(D_00635540_2EC528, 25, 0, D_00634280_2EC528, 2060, D_00634EC0_2EC528, 4, 0, 0); if (r < 0) { func_002E58B0_2EC528(sem); func_002E95E0_2EC528(); return -11; } v = *(int *)((unsigned)D_00634EC0_2EC528 | 0x20000000); func_002E95E0_2EC528(); if (v == 0) { func_002E58B0_2EC528(sem); return -11; } func_002E58E0_2EC528(sem); func_002E58B0_2EC528(sem); return res; }

typedef struct { int sem; int *res; int w8; char name1[1024]; char name2[1024]; } T_2ec348_002EC348;
extern T_2ec348_002EC348 D_00634280_002EC348[] __asm__("D_00634280"); extern char D_00635540_002EC348[] __asm__("D_00635540"); extern char D_00634EC0_002EC348[] __asm__("D_00634EC0"); extern int D_00429918_002EC348[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ec348_002EC348;
void func_002E95B0_2EC348(int) __asm__("func_002E95B0"); void func_002E96B8_2EC348(void) __asm__("func_002E96B8"); int func_002E58A0_2EC348(void *) __asm__("func_002E58A0"); int func_002E8928_2EC348(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EC348(int) __asm__("func_002E58B0"); void func_002E95E0_2EC348(void) __asm__("func_002E95E0"); void func_002E58E0_2EC348(int) __asm__("func_002E58E0");
// MATCH func_002EC348
int FUN_002ec348(char *name, char *name2) { T_2ec348_002EC348 *t = D_00634280_002EC348; S_2ec348_002EC348 s; int res; int i; int sem; int r; int v; func_002E95B0_2EC348(17); if (D_00429918_002EC348[0] == 0) func_002E96B8_2EC348(); i = 0; if ((t->name1[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name1[i] = name[i]) == 0) break; } } if (i == 1024) { t->name1[1023] = 0; } i = 0; if ((t->name2[0] = name2[0]) != 0) { while (++i < 1024) { if ((t->name2[i] = name2[i]) == 0) break; } } if (i == 1024) { t->name2[1023] = 0; } s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EC348(&s); t->sem = sem; t->w8 = 4; t->res = &res; r = func_002E8928_2EC348(D_00635540_002EC348, 24, 0, D_00634280_002EC348, 2060, D_00634EC0_002EC348, 4, 0, 0); if (r < 0) { func_002E58B0_2EC348(sem); func_002E95E0_2EC348(); return -11; } v = *(int *)((unsigned)D_00634EC0_002EC348 | 0x20000000); func_002E95E0_2EC348(); if (v == 0) { func_002E58B0_2EC348(sem); return -11; } func_002E58E0_2EC348(sem); func_002E58B0_2EC348(sem); return res; }

typedef struct { int sem; int *res; int w8; char name1[1024]; char name2[1024]; } T_2eb8a0_002EB8A0;
extern T_2eb8a0_002EB8A0 D_00634280_002EB8A0[] __asm__("D_00634280"); extern char D_00635540_002EB8A0[] __asm__("D_00635540"); extern char D_00634EC0_002EB8A0[] __asm__("D_00634EC0"); extern int D_00429918_002EB8A0[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eb8a0_002EB8A0;
void func_002E95B0_2EB8A0(int) __asm__("func_002E95B0"); void func_002E96B8_2EB8A0(void) __asm__("func_002E96B8"); int func_002E58A0_2EB8A0(void *) __asm__("func_002E58A0"); int func_002E8928_2EB8A0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EB8A0(int) __asm__("func_002E58B0"); void func_002E95E0_2EB8A0(void) __asm__("func_002E95E0"); void func_002E58E0_2EB8A0(int) __asm__("func_002E58E0"); void func_002E8038_002EB8A0(void *, int) __asm__("func_002E8038");
// MATCH func_002EB8A0
int FUN_002eb8a0(char *name, char *name2) { T_2eb8a0_002EB8A0 *t = D_00634280_002EB8A0; S_2eb8a0_002EB8A0 s; int res; int i; int sem; int r; int v; func_002E95B0_2EB8A0(17); if (D_00429918_002EB8A0[0] == 0) func_002E96B8_2EB8A0(); i = 0; if ((t->name1[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name1[i] = name[i]) == 0) break; } } if (i == 1024) { t->name1[1023] = 0; } i = 0; if ((t->name2[0] = name2[0]) != 0) { while (++i < 1024) { if ((t->name2[i] = name2[i]) == 0) break; } } if (i == 1024) { t->name2[1023] = 0; } s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EB8A0(&s); t->sem = sem; t->res = &res; t->w8 = 4; func_002E8038_002EB8A0(D_00634280_002EB8A0, 2060); r = func_002E8928_2EB8A0(D_00635540_002EB8A0, 17, 0, D_00634280_002EB8A0, 2060, D_00634EC0_002EB8A0, 4, 0, 0); if (r < 0) { func_002E58B0_2EB8A0(sem); func_002E95E0_2EB8A0(); return -11; } v = *(int *)((unsigned)D_00634EC0_002EB8A0 | 0x20000000); func_002E95E0_2EB8A0(); if (v == 0) { func_002E58B0_2EB8A0(sem); return -11; } func_002E58E0_2EB8A0(sem); func_002E58B0_2EB8A0(sem); return res; }

typedef struct { int q[16]; } B64_2eb660_002EB660;
typedef struct { int sem; int *res; int w8; int wc; B64_2eb660_002EB660 blk; char name[1032]; } T_2eb660_002EB660;
extern T_2eb660_002EB660 D_00634280_2EB660[] __asm__("D_00634280"); extern char D_00635540_2EB660[] __asm__("D_00635540"); extern char D_00634EC0_2EB660[] __asm__("D_00634EC0"); extern int D_00429918_2EB660[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eb660_002EB660;
void func_002E95B0_2EB660(int) __asm__("func_002E95B0"); void func_002E96B8_2EB660(void) __asm__("func_002E96B8"); int func_002E58A0_2EB660(void *) __asm__("func_002E58A0"); int func_002E8928_2EB660(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EB660(int) __asm__("func_002E58B0"); void func_002E95E0_2EB660(void) __asm__("func_002E95E0"); void func_002E58E0_2EB660(int) __asm__("func_002E58E0"); void func_002E8038_2EB660(void *, int) __asm__("func_002E8038");
// MATCH func_002EB660
int FUN_002eb660(char *name, B64_2eb660_002EB660 *blk, int c) { T_2eb660_002EB660 *t = D_00634280_2EB660; S_2eb660_002EB660 s; int res; int i; int sem; int r; int v; unsigned char ch; func_002E95B0_2EB660(13); if (D_00429918_2EB660[0] == 0) func_002E96B8_2EB660(); i = 0; ch = t->name[0] = name[0]; if (ch != 0) { while (++i < 1024) { ch = t->name[i] = name[i]; if (ch == 0) break; } } if (i == 1024) { t->name[1023] = 0; i = 1023; } t->blk = *blk; t->wc = c; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EB660(&s); t->w8 = 4; t->res = &res; t->sem = sem; func_002E8038_2EB660(D_00634280_2EB660, 1104); r = func_002E8928_2EB660(D_00635540_2EB660, 13, 0, D_00634280_2EB660, i + 81, D_00634EC0_2EB660, 4, 0, 0); if (r < 0) { func_002E58B0_2EB660(sem); func_002E95E0_2EB660(); return -11; } v = *(int *)((unsigned)D_00634EC0_2EB660 | 0x20000000); func_002E95E0_2EB660(); if (v == 0) { func_002E58B0_2EB660(sem); return -11; } func_002E58E0_2EB660(sem); func_002E58B0_2EB660(sem); return res; }

typedef struct { int a[8]; } S_2e8758_002E8758;
extern char D_00634200_2E8758[] __asm__("D_00634200");
void *func_002E82B0_2E8758(char *) __asm__("func_002E82B0"); void func_002E8358_2E8758(int *) __asm__("func_002E8358"); int func_002E58A0_2E8758(void *) __asm__("func_002E58A0"); void func_002E58B0_2E8758(int) __asm__("func_002E58B0"); void func_002E58E0_2E8758(int) __asm__("func_002E58E0"); int func_002E7E90_2E8758(int, int *, int, int, int, int) __asm__("func_002E7E90");
// MATCH func_002E8758
int FUN_002e8758(int *p, int a, unsigned fl) { int *n; S_2e8758_002E8758 s; int sema; int rr; int v; p[4] = 0; p[9] = 0; n = func_002E82B0_2E8758(D_00634200_2E8758); if (n == 0) return -1; v = n[6]; *p = (int)n; p[1] = v; n[8] = a; n[5] = (int)n; n[7] = (int)p; if ((fl & 1) == 0) { s.a[2] = 0; s.a[1] = 1; sema = func_002E58A0_2E8758(&s); p[2] = sema; if (sema < 0) { func_002E8358_2E8758(n); return -3; } rr = func_002E7E90_2E8758(0x80000009, n, 64, 0, 0, 0); if (rr == 0) { func_002E8358_2E8758(n); func_002E58B0_2E8758(p[2]); return -2; } func_002E58E0_2E8758(p[2]); func_002E58B0_2E8758(p[2]); return 0; } p[2] = -1; rr = func_002E7E90_2E8758(0x80000009, n, 64, 0, 0, 0); if (rr == 0) { func_002E8358_2E8758(n); return -2; } return 0; }

typedef struct { int a[8]; } S_2e8500_002E8500;
extern char D_00634200_002E8500[] __asm__("D_00634200");
void *func_002E82B0_2E8500(char *) __asm__("func_002E82B0"); void func_002E8358_2E8500(int *) __asm__("func_002E8358"); int func_002E58A0_2E8500(void *) __asm__("func_002E58A0"); void func_002E58B0_2E8500(int) __asm__("func_002E58B0"); void func_002E58E0_2E8500(int) __asm__("func_002E58E0"); int func_002E7E90_2E8500(int, int *, int, int, int, int) __asm__("func_002E7E90");
// MATCH func_002E8500
int FUN_002e8500(int *p, int a, int b, int c, unsigned fl) { int *n; S_2e8500_002E8500 s; int sema; int rr; int v; n = func_002E82B0_2E8500(D_00634200_002E8500); if (n == 0) return -1; v = n[6]; *p = (int)n; p[1] = v; n[8] = a; n[9] = b; n[10] = c; n[5] = (int)n; n[7] = (int)p; if ((fl & 1) == 0) { s.a[2] = 0; s.a[1] = 1; sema = func_002E58A0_2E8500(&s); p[2] = sema; if (sema < 0) { func_002E8358_2E8500(n); return -3; } rr = func_002E7E90_2E8500(0x8000000c, n, 64, 0, 0, 0); if (rr == 0) { func_002E8358_2E8500(n); func_002E58B0_2E8500(p[2]); return -2; } func_002E58E0_2E8500(p[2]); func_002E58B0_2E8500(p[2]); return 0; } p[2] = -1; rr = func_002E7E90_2E8500(0x8000000c, n, 64, 0, 0, 0); if (rr == 0) { func_002E8358_2E8500(n); return -2; } return 0; }

typedef struct { int a; char name[256]; } R_2ec900_002EC900;
extern int D_0042992C_2EC900[] __asm__("D_0042992C"); extern char D_00635600_2EC900[] __asm__("D_00635600"); extern R_2ec900_002EC900 D_006356C0_2EC900 __asm__("D_006356C0"); extern char D_00635640_2EC900[] __asm__("D_00635640");
int func_002E8928_2EC900(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC900
int FUN_002ec900(char *name, int b) { int i; int r; if (D_0042992C_2EC900[0] < 0) return 0; i = 0; if ((D_006356C0_2EC900.name[0] = name[0]) != 0) { while (++i < 252) { if ((D_006356C0_2EC900.name[i] = name[i]) == 0) break; } } if (i == 252) { i = 251; D_006356C0_2EC900.name[251] = 0; } D_006356C0_2EC900.a = b; D_006356C0_2EC900.name[251] = 0; r = func_002E8928_2EC900(D_00635600_2EC900, 3, 0, &D_006356C0_2EC900, i + 5, D_00635640_2EC900, 4, 0, 0); if (r >= 0) return *(int *)D_00635640_2EC900; return -1; }

extern int *D_00634200_2E8B58[] __asm__("D_00634200");
volatile short func_002EDC50_2E8B58(void) __asm__("func_002EDC50"); void func_002EDC98_2E8B58(void) __asm__("func_002EDC98");
// MATCH func_002E8B58
void FUN_002e8b58(int *n, int v) { int *h; int *p; int *q; int *t; func_002EDC50_2E8B58(); *n = v; n[1] = 0; h = D_00634200_2E8B58[10]; n[2] = 0; n[3] = 0; n[4] = 0; n[5] = 0; if (h == 0) D_00634200_2E8B58[10] = n; else { p = h; q = (int *)p[5]; if (q != 0) { do { p = q; t = (int *)p[5]; q = t; } while (t != 0); } p[5] = (int)n; } func_002EDC98_2E8B58(); }

typedef struct { int pad[9]; int w36; } T_2ec6f0_002EC6F0;
extern T_2ec6f0_002EC6F0 D_00635600_2EC6F0 __asm__("D_00635600"); extern int D_0042992C_2EC6F0[] __asm__("D_0042992C");
int func_002E8758_2EC6F0(void *, int, unsigned) __asm__("func_002E8758");
// MATCH func_002EC6F0
int FUN_002ec6f0(void) { int i; do { for (;;) { if (func_002E8758_2EC6F0(&D_00635600_2EC6F0, 0x80000003, 0) < 0) { return -1; } if (D_00635600_2EC6F0.w36 != 0) { break; } i = 0x100000; do { i--; } while (i != (-1)); } D_0042992C_2EC6F0[0] = 0; } while (0); return 0; }

extern int D_0042A888_2EE3A0[] __asm__("D_0042A888"); extern char D_0042A120_2EE3A0[] __asm__("D_0042A120"); extern char D_0042A860_2EE3A0[] __asm__("D_0042A860");
void func_002EE338_2EE3A0(int, int) __asm__("func_002EE338"); void func_002EE348_2EE3A0(int, char *, int) __asm__("func_002EE348"); void func_002E5B20_2EE3A0(int) __asm__("func_002E5B20"); int func_002EE390_2EE3A0(int) __asm__("func_002EE390");
// MATCH func_002EE3A0
void FUN_002ee3a0(void) { int *b; int *p; unsigned k; int k2; int r; if ((*(volatile unsigned *)0x10001810 & 0x100) == 0) { k = 2; b = D_0042A888_2EE3A0; func_002EE338_2EE3A0(b[0], b[1]); p = b + 4; func_002EE348_2EE3A0(0x80076000, D_0042A120_2EE3A0, 1856); func_002EE348_2EE3A0(0x82000, D_0042A860_2EE3A0, 40); func_002E5B20_2EE3A0(0); do { func_002E5B20_2EE3A0(2); } while (0); k2 = 3; func_002EE338_2EE3A0(b[2], b[k2]); do { k++; r = func_002EE390_2EE3A0(*p); func_002EE338_2EE3A0(*p, r); p += 2; } while (k < 8); } }

extern int D_00429940_2EDDC8[] __asm__("D_00429940"); extern int D_00429938_2EDDC8[] __asm__("D_00429938");
void func_002EDD40_2EDDC8(void) __asm__("func_002EDD40"); void func_002EDD08_2EDDC8(void) __asm__("func_002EDD08");
void func_002EDEC8_2EDDC8(int, int) __asm__("func_002EDEC8"); int func_002EDD80_2EDDC8(int, int, void *) __asm__("func_002EDD80");
// MATCH func_002EDDC8
void FUN_002eddc8(void) { int *b; int a; int c; unsigned u; unsigned v; b = D_00429940_2EDDC8; func_002EDEC8_2EDDC8(b[0], b[1]); func_002EDEC8_2EDDC8(b[2], b[3]); a = func_002EDD80_2EDDC8(0x80000000, 0x80080000, (void *)func_002EDD40_2EDDC8); c = func_002EDD80_2EDDC8(0x80000000, 0x80080000, (void *)func_002EDD08_2EDDC8); u = a - 524; v = c - 360; while (u != v) { if (u < v) { a = func_002EDD80_2EDDC8(a + 4, 0x80080000, (void *)func_002EDD40_2EDDC8); u = a - 524; } else { c = func_002EDD80_2EDDC8(c + 4, 0x80080000, (void *)func_002EDD08_2EDDC8); v = c - 360; } } D_00429938_2EDDC8[0] = u; }

void *func_002BF838_2C15F8(void) __asm__("func_002BF838");
// MATCH func_002C15F8
void FUN_002c15f8(long *p) { short *r = func_002BF838_2C15F8(); if (r[3] == 1) { *(volatile long *)0x12000000 = p[0]; *(volatile long *)0x12000070 = p[2]; *(volatile long *)0x12000080 = p[3]; *(volatile long *)0x120000c0 = p[4]; } else { *(volatile long *)0x12000000 = p[0]; *(volatile long *)0x12000020 = p[1]; *(volatile long *)0x12000090 = p[2]; *(volatile long *)0x120000a0 = p[3]; *(volatile long *)0x120000e0 = p[4]; } }

extern char D_0049DD50_2C7BA0[] __asm__("D_0049DD50"), D_0049DD78_2C7BA0[] __asm__("D_0049DD78");
int func_002C7318_2C7BA0(void *, int) __asm__("func_002C7318"); void func_002C6E50_2C7BA0(void *) __asm__("func_002C6E50"); void func_002C6E20_2C7BA0(void *, int) __asm__("func_002C6E20"); void func_002C35C8_2C7BA0(void *, char *) __asm__("func_002C35C8");
// MATCH func_002C7BA0
void FUN_002c7ba0(char *o) { int r; r = func_002C7318_2C7BA0(o, 1); *(int *)(o + 2112) = r; if (r != 0) { func_002C6E50_2C7BA0(o); func_002C6E20_2C7BA0(o, 0x50000000); func_002C6E50_2C7BA0(o); } r = func_002C7318_2C7BA0(o, 1); *(int *)(o + 2116) = r; if (r != 0) { func_002C6E50_2C7BA0(o); func_002C6E20_2C7BA0(o, 0x58000000); func_002C6E50_2C7BA0(o); } if (func_002C7318_2C7BA0(o, 1) != 0) func_002C35C8_2C7BA0(o, D_0049DD50_2C7BA0); if (func_002C7318_2C7BA0(o, 1) != 0) func_002C35C8_2C7BA0(o, D_0049DD78_2C7BA0); }

#define R(a) (*(volatile unsigned *)(a))
extern char D_0049D430_2BFEC0[] __asm__("D_0049D430"); void func_002E7940_2BFEC0(char *) __asm__("func_002E7940");
// MATCH func_002BFEC0
int sceGsPutDrawEnv(long *p) { unsigned c, i; i = 0; while ((R(0x1000a000) & 0x100) != 0) { if (0x1000000 < i++) { func_002E7940_2BFEC0(D_0049D430_2BFEC0); return -1; } } R(0x1000a020) = (int)(*p & 0x7fff) + 1; if (((unsigned)p & 0x70000000) == 0x70000000) R(0x1000a010) = ((unsigned)p & 0xfffffff) | 0x80000000; else R(0x1000a010) = (unsigned)p & 0xfffffff; R(0x1000a000) = 0x101; return 0; }

#define R(a) (*(volatile unsigned *)(a))
extern char D_0049D710_2C0978[] __asm__("D_0049D710"); void func_002E7940_2C0978(char *) __asm__("func_002E7940");
// MATCH func_002C0978
int sceGsExecLoadImage(unsigned a, unsigned b) { unsigned i; i = 0; while ((R(0x1000a000) & 0x100) != 0) { if (0x1000000 < i++) { func_002E7940_2C0978(D_0049D710_2C0978); return -1; } } R(0x1000a020) = 6; if ((a & 0x70000000) == 0x70000000) R(0x1000a010) = (a & 0xfffffff) | 0x80000000; else R(0x1000a010) = a & 0xfffffff; R(0x1000a000) = 0x101; while ((R(0x1000a000) & 0x100) != 0) { if (0x1000000 < i++) { func_002E7940_2C0978(D_0049D710_2C0978); return -1; } } R(0x1000a020) = (int)(*(long *)(a + 80) & 0x7fff); if ((b & 0x70000000) == 0x70000000) R(0x1000a010) = (b & 0xfffffff) | 0x80000000; else R(0x1000a010) = b & 0xfffffff; R(0x1000a000) = 0x101; return 0; }

extern int D_0042AC48_2EE5C8[] __asm__("D_0042AC48");
extern char D_0042A8C8_2EE5C8[] __asm__("D_0042A8C8");
extern int D_0042AC40_2EE5C8[] __asm__("D_0042AC40");
void func_002EE5B8_2EE5C8(int, int) __asm__("func_002EE5B8");
void func_002EE560_2EE5C8(int, void *, int) __asm__("func_002EE560");
void func_002E5B20_2EE5C8(int) __asm__("func_002E5B20");
int func_002EE5A8_2EE5C8(int) __asm__("func_002EE5A8");
// MATCH func_002EE5C8
void FUN_002ee5c8(void) { int *b; int *p; unsigned k; int k2; int k3; k = 3; b = D_0042AC48_2EE5C8; func_002EE5B8_2EE5C8(b[0], b[1]); func_002EE560_2EE5C8(0x80075000, D_0042A8C8_2EE5C8, 816); func_002E5B20_2EE5C8(0); func_002E5B20_2EE5C8(2); k2 = 3; func_002EE5B8_2EE5C8(b[2], b[3]); k3 = 5; func_002EE5B8_2EE5C8(b[4], b[5]); p = b + 6; do { k++; func_002EE5B8_2EE5C8(*p, func_002EE5A8_2EE5C8(*p)); p += 2; } while (k < 8); D_0042AC40_2EE5C8[0] = func_002EE5A8_2EE5C8(3); }

extern int D_0042A100_2EDFE8[] __asm__("D_0042A100");
extern char D_00429958_2EDFE8[] __asm__("D_00429958");
int func_002EDF80_2EDFE8(void) __asm__("func_002EDF80");
void func_002EDF18_2EDFE8(int, int) __asm__("func_002EDF18");
void func_002EDF28_2EDFE8(int, void *, int) __asm__("func_002EDF28");
void func_002E5B20_2EDFE8(int) __asm__("func_002E5B20");
int func_002EDF70_2EDFE8(int) __asm__("func_002EDF70");
// MATCH func_002EDFE8
void FUN_002edfe8(void) { int *b; int *p; unsigned k; int k2; int r; if (func_002EDF80_2EDFE8() != 0) { k = 2; b = D_0042A100_2EDFE8; k2 = 3; func_002EDF18_2EDFE8(b[0], b[1]); func_002EDF28_2EDFE8(0x80074000, D_00429958_2EDFE8, 1960); func_002E5B20_2EDFE8(0); func_002E5B20_2EDFE8(2); func_002EDF18_2EDFE8(b[2], b[3]); p = b + 4; do { k++; r = func_002EDF70_2EDFE8(*p); func_002EDF18_2EDFE8(*p, r); p += 2; } while (k < 3); } }

typedef int u128 __attribute__((mode(TI)));
#define R(a) (*(volatile unsigned *)(a))
// MATCH func_002CAFB8
int FUN_002cafb8(u128 *p, int n) { int i, k; i = 0; k = n - 1; if (n != 0) { do { if ((R(0x10003800) & 0x10000000) != 0) return i; *(u128 *)0x10004000 = *p; i++; p++; k--; } while (k != -1); } return i; }

// MATCH func_002BF950
int FUN_002bf950(void) { register int n __asm__("$3") = 128; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5490
int ResetEE(void) { register int n __asm__("$3") = 1; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54A0
int SetGsCrt(void) { register int n __asm__("$3") = 2; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54B0
int RFU003(void) { register int n __asm__("$3") = 3; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54C0
int _Exit(void) { register int n __asm__("$3") = 4; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54D0
int RFU005_ResumeIntrDispatch(void) { register int n __asm__("$3") = 5; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54E0
int _LoadExecPS2(void) { register int n __asm__("$3") = 6; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E54F0
int _ExecPS2(void) { register int n __asm__("$3") = 7; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5500
int RFU008_ResumeT3IntrDispatch(void) { register int n __asm__("$3") = 8; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5510
int RFU009(void) { register int n __asm__("$3") = 9; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5520
int AddSbusIntcHandler(void) { register int n __asm__("$3") = 10; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5530
int RemoveSbusIntcHandler(void) { register int n __asm__("$3") = 11; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5540
int Interrupt2Iop(void) { register int n __asm__("$3") = 12; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5550
int SetVTLBRefillHandler(void) { register int n __asm__("$3") = 13; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5560
int SetVCommonHandler(void) { register int n __asm__("$3") = 14; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5570
int SetVInterruptHandler(void) { register int n __asm__("$3") = 15; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5580
int AddIntcHandler_2E5580(void) { register int n __asm__("$3") = 16; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5590
int AddIntcHandler_2E5590(void) { register int n __asm__("$3") = 16; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55A0
int RemoveIntcHandler(void) { register int n __asm__("$3") = 17; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55B0
int AddDmacHandler_2E55B0(void) { register int n __asm__("$3") = 18; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55C0
int AddDmacHandler_2E55C0(void) { register int n __asm__("$3") = 18; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55D0
int RemoveDmacHandler(void) { register int n __asm__("$3") = 19; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55E0
int _EnableIntc(void) { register int n __asm__("$3") = 20; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E55F0
int _DisableIntc(void) { register int n __asm__("$3") = 21; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5600
int _EnableDmac(void) { register int n __asm__("$3") = 22; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5610
int _DisableDmac(void) { register int n __asm__("$3") = 23; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5620
int SetAlarm(void) { register int n __asm__("$3") = 252; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5630
int ReleaseAlarm(void) { register int n __asm__("$3") = 253; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5640
int _iEnableIntc(void) { register int n __asm__("$3") = -26; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5650
int _iDisableIntc(void) { register int n __asm__("$3") = -27; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5660
int _iEnableDmac(void) { register int n __asm__("$3") = -28; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5670
int _iDisableDmac(void) { register int n __asm__("$3") = -29; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5680
int iSetAlarm(void) { register int n __asm__("$3") = -254; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5690
int iReleaseAlarm(void) { register int n __asm__("$3") = -255; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56A0
int CreateThread(void) { register int n __asm__("$3") = 32; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56B0
int DeleteThread(void) { register int n __asm__("$3") = 33; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56C0
int _StartThread(void) { register int n __asm__("$3") = 34; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56D0
int ExitThread(void) { register int n __asm__("$3") = 35; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56E0
int ExitDeleteThread(void) { register int n __asm__("$3") = 36; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E56F0
int TerminateThread(void) { register int n __asm__("$3") = 37; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5700
int iTerminateThread(void) { register int n __asm__("$3") = -38; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5710
int DisableDispatchThread(void) { register int n __asm__("$3") = 39; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5720
int EnableDispatchThread(void) { register int n __asm__("$3") = 40; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5730
int ChangeThreadPriority(void) { register int n __asm__("$3") = 41; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5740
int iChangeThreadPriority(void) { register int n __asm__("$3") = -42; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5750
int RotateThreadReadyQueue(void) { register int n __asm__("$3") = 43; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5760
int _iRotateThreadReadyQueue(void) { register int n __asm__("$3") = -44; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5770
int ReleaseWaitThread(void) { register int n __asm__("$3") = 45; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5780
int iReleaseWaitThread(void) { register int n __asm__("$3") = -46; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5790
int GetThreadId(void) { register int n __asm__("$3") = 47; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57A0
int ReferThreadStatus(void) { register int n __asm__("$3") = 48; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57B0
int iReferThreadStatus(void) { register int n __asm__("$3") = -49; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57C0
int SleepThread(void) { register int n __asm__("$3") = 50; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57D0
int WakeupThread(void) { register int n __asm__("$3") = 51; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57E0
int _iWakeupThread(void) { register int n __asm__("$3") = -52; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E57F0
int CancelWakeupThread(void) { register int n __asm__("$3") = 53; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5800
int iCancelWakeupThread(void) { register int n __asm__("$3") = -54; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5810
int SuspendThread(void) { register int n __asm__("$3") = 55; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5820
int _iSuspendThread(void) { register int n __asm__("$3") = -56; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5830
int ResumeThread(void) { register int n __asm__("$3") = 57; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5840
int iResumeThread(void) { register int n __asm__("$3") = -58; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5850
int JoinThread(void) { register int n __asm__("$3") = 59; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5860
int RFU060_SetupThread(void) { register int n __asm__("$3") = 60; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5870
int RFU061_SetupHeap(void) { register int n __asm__("$3") = 61; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5880
int EndOfHeap(void) { register int n __asm__("$3") = 62; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5890
int RFU063(void) { register int n __asm__("$3") = 63; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58A0
int CreateSema(void) { register int n __asm__("$3") = 64; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58B0
int DeleteSema(void) { register int n __asm__("$3") = 65; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58C0
int SignalSema(void) { register int n __asm__("$3") = 66; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58D0
int iSignalSema(void) { register int n __asm__("$3") = -67; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58E0
int WaitSema(void) { register int n __asm__("$3") = 68; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E58F0
int PollSema(void) { register int n __asm__("$3") = 69; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5900
int iPollSema(void) { register int n __asm__("$3") = -70; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5910
int ReferSemaStatus(void) { register int n __asm__("$3") = 71; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5920
int iReferSemaStatus(void) { register int n __asm__("$3") = -72; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5930
int RFU073(void) { register int n __asm__("$3") = 73; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5940
int SetOsdConfigParam(void) { register int n __asm__("$3") = 74; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5950
int GetOsdConfigParam(void) { register int n __asm__("$3") = 75; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5960
int GetGsHParam(void) { register int n __asm__("$3") = 76; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5970
int GetGsVParam(void) { register int n __asm__("$3") = 77; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5980
int SetGsHParam(void) { register int n __asm__("$3") = 78; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5990
int SetGsVParam(void) { register int n __asm__("$3") = 79; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59A0
int RFU080_CreateEventFlag(void) { register int n __asm__("$3") = 80; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59B0
int RFU081_DeleteEventFlag(void) { register int n __asm__("$3") = 81; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59C0
int RFU082_SetEventFlag(void) { register int n __asm__("$3") = 82; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59D0
int RFU083_iSetEventFlag(void) { register int n __asm__("$3") = -83; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59E0
int RFU084_ClearEventFlag(void) { register int n __asm__("$3") = 84; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E59F0
int RFU085_iClearEventFlag_2E59F0(void) { register int n __asm__("$3") = -85; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A00
int RFU086_WaitEvnetFlag_2E5A00(void) { register int n __asm__("$3") = 86; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A10
int RFU087_PollEvnetFlag_2E5A10(void) { register int n __asm__("$3") = 87; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A20
int RFU088_iPollEvnetFlag_2E5A20(void) { register int n __asm__("$3") = -88; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A30
int RFU089_ReferEventFlagStatus_2E5A30(void) { register int n __asm__("$3") = 89; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A40
int RFU090_iReferEventFlagStatus(void) { register int n __asm__("$3") = -90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A50
int RFU091_2E5A50(void) { register int n __asm__("$3") = 91; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A60
int EnableIntcHandler(void) { register int n __asm__("$3") = 92; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A70
int iEnableIntcHandler(void) { register int n __asm__("$3") = -92; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A80
int DisableIntcHandler(void) { register int n __asm__("$3") = 93; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5A90
int iDisableIntcHandler(void) { register int n __asm__("$3") = -93; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AA0
int EnableDmacHandler(void) { register int n __asm__("$3") = 94; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AB0
int iEnableDmacHandler(void) { register int n __asm__("$3") = -94; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AC0
int DisableDmacHandler(void) { register int n __asm__("$3") = 95; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AD0
int iDisableDmacHandler(void) { register int n __asm__("$3") = -95; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AE0
int KSeg0(void) { register int n __asm__("$3") = 96; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5AF0
int EnableCache(void) { register int n __asm__("$3") = 97; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B00
int DisableCache(void) { register int n __asm__("$3") = 98; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B10
int GetCop0(void) { register int n __asm__("$3") = 99; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B20
int FlushCache(void) { register int n __asm__("$3") = 100; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B30
int CpuConfig(void) { register int n __asm__("$3") = 102; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B40
int iGetCop0(void) { register int n __asm__("$3") = -103; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B50
int iFlushCache(void) { register int n __asm__("$3") = -104; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B60
int iCpuConfig(void) { register int n __asm__("$3") = -106; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B70
int sceSifStopDma(void) { register int n __asm__("$3") = 107; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B80
int SetCPUTimerHandler(void) { register int n __asm__("$3") = 108; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5B90
int SetCPUTimer(void) { register int n __asm__("$3") = 109; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BA0
int SetOsdConfigParam2(void) { register int n __asm__("$3") = 110; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BB0
int GetOsdConfigParam2(void) { register int n __asm__("$3") = 111; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BC0
int GsGetIMR(void) { register int n __asm__("$3") = 112; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BD0
int iGsGetIMR(void) { register int n __asm__("$3") = -112; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BE0
int GsPutIMR(void) { register int n __asm__("$3") = 113; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5BF0
int iGsPutIMR(void) { register int n __asm__("$3") = -113; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C00
int SetPgifHandler(void) { register int n __asm__("$3") = 114; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C10
int SetVSyncFlag(void) { register int n __asm__("$3") = 115; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C20
int RFU116_SetSyscall_2E5C20(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C30
int _print(void) { register int n __asm__("$3") = 117; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C40
int sceSifDmaStat(void) { register int n __asm__("$3") = 118; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C50
int isceSifDmaStat(void) { register int n __asm__("$3") = -118; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C60
int sceSifSetDma(void) { register int n __asm__("$3") = 119; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C70
int isceSifSetDma(void) { register int n __asm__("$3") = -119; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C80
int sceSifSetDChain(void) { register int n __asm__("$3") = 120; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5C90
int isceSifSetDChain(void) { register int n __asm__("$3") = -120; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CA0
int sceSifSetReg(void) { register int n __asm__("$3") = 121; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CB0
int sceSifGetReg(void) { register int n __asm__("$3") = 122; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CC0
int _ExecOSD(void) { register int n __asm__("$3") = 123; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CD0
int Deci2Call(void) { register int n __asm__("$3") = 124; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CE0
int PSMode(void) { register int n __asm__("$3") = 125; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5CF0
int MachineType(void) { register int n __asm__("$3") = 126; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5D00
int GetMemorySize(void) { register int n __asm__("$3") = 127; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002E5D10
int _InitTLB(void) { register int n __asm__("$3") = 130; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDCF8
int FUN_002edcf8(void) { register int n __asm__("$3") = 90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDD80
int FUN_002edd80(void) { register int n __asm__("$3") = 131; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDEC8
int RFU116_SetSyscall_2EDEC8(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDF18
int RFU116_SetSyscall_2EDF18(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDF28
int FUN_002edf28(void) { register int n __asm__("$3") = 90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EDF70
int RFU091_2EDF70(void) { register int n __asm__("$3") = 91; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE098
int FUN_002ee098(void) { register int n __asm__("$3") = 90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE0D8
int RFU116_SetSyscall_2EE0D8(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE338
int RFU116_SetSyscall_2EE338(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE348
int FUN_002ee348(void) { register int n __asm__("$3") = 90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE390
int RFU091_2EE390(void) { register int n __asm__("$3") = 91; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE560
int FUN_002ee560(void) { register int n __asm__("$3") = 90; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE5A8
int RFU091_2EE5A8(void) { register int n __asm__("$3") = 91; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE5B8
int RFU116_SetSyscall_2EE5B8(void) { register int n __asm__("$3") = 116; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE690
int FUN_002ee690(void) { register int n __asm__("$3") = 85; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE6A0
int RFU085_iClearEventFlag_2EE6A0(void) { register int n __asm__("$3") = -85; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE6B0
int RFU086_WaitEvnetFlag_2EE6B0(void) { register int n __asm__("$3") = 86; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE6F0
int FUN_002ee6f0(void) { register int n __asm__("$3") = -86; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE700
int RFU087_PollEvnetFlag_2EE700(void) { register int n __asm__("$3") = 87; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE710
int FUN_002ee710(void) { register int n __asm__("$3") = -87; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE720
int FUN_002ee720(void) { register int n __asm__("$3") = 88; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE730
int RFU088_iPollEvnetFlag_2EE730(void) { register int n __asm__("$3") = -88; __asm__ volatile("syscall" : : "r"(n)); }

// MATCH func_002EE740
int RFU089_ReferEventFlagStatus_2EE740(void) { register int n __asm__("$3") = 89; __asm__ volatile("syscall" : : "r"(n)); }

#define R(a) (*(volatile unsigned *)(a))
#define W() do { v = R(0x10002010); } while (v < 0)
#define Q(i) (*(volatile u128 *)0x10007010 = D_00427E40_2CFCD0[i])
#define P(i) (*(volatile u128 *)0x10007010 = D_00427E90_2CFCD0[i])
extern volatile u128 D_00427E40_2CFCD0[] __asm__("D_00427E40"), D_00427E90_2CFCD0[] __asm__("D_00427E90"); void func_002CFC68_2CFCD0(int) __asm__("func_002CFC68");
// MATCH func_002CFCD0
void FUN_002cfcd0(void) { int v; func_002CFC68_2CFCD0(1); R(0x10002010) = 0x40000000; W(); R(0x10002000) = 0; W(); Q(0); Q(1); Q(2); Q(3); Q(4); Q(4); Q(4); Q(4); R(0x10002000) = 0x50000000; W(); R(0x10002000) = 0x58000000; W(); P(0); P(1); R(0x10002000) = 0x60000000; W(); R(0x10002000) = 0x90000000; W(); R(0x10002010) = 0x40000000; W(); R(0x10002000) = 0; W(); }

extern unsigned D_0042987C_2E5FA0[] __asm__("D_0042987C"); unsigned func_002E5880_2E5FA0(void) __asm__("func_002E5880"); int *func_002DB948_2E5FA0(void) __asm__("func_002DB948");
// MATCH func_002E5FA0
unsigned FUN_002e5fa0(int n) { unsigned s, v, e, nb, ret; int *p; __asm__ volatile("mfc0 %0, $12" : "=r"(s)); s = s & 0x10000; if (s != 0) { do { __asm__ volatile(".word 0x42000039"); __asm__ volatile(".word 0x0000040f"); __asm__ volatile("mfc0 %0, $12" : "=r"(v)); } while ((v & 0x10000) != 0); } nb = D_0042987C_2E5FA0[0] + n; e = func_002E5880_2E5FA0(); if (e < nb) { p = func_002DB948_2E5FA0(); *p = 12; if (s != 0) __asm__ volatile(".word 0x42000038"); return -1; } ret = D_0042987C_2E5FA0[0]; D_0042987C_2E5FA0[0] = nb; if (s != 0) __asm__ volatile(".word 0x42000038"); return ret; }

extern int D_00429884_2E7038[] __asm__("D_00429884"); extern char D_00632700_2E7038[] __asm__("D_00632700"); void func_002E6AB8_2E7038(char *) __asm__("func_002E6AB8");
// MATCH func_002E7038
void FUN_002e7038(int c) { int n; n = D_00429884_2E7038[0]; if (125 < n) { D_00429884_2E7038[0] = 0; D_00632700_2E7038[127] = 0; func_002E6AB8_2E7038(D_00632700_2E7038); n = D_00429884_2E7038[0]; } if (c != 10) { D_00429884_2E7038[0] = n + 1; D_00632700_2E7038[n] = c; return; } D_00429884_2E7038[0] = 0; D_00632700_2E7038[n] = 10; D_00632700_2E7038[n + 1] = 0; func_002E6AB8_2E7038(D_00632700_2E7038); }

void *func_002BF838_2C02A0(void) __asm__("func_002BF838"); void func_002E5D30_2C02A0(void) __asm__("func_002E5D30"); long long func_002E5DC0_2C02A0(void) __asm__("func_002E5DC0");
// MATCH func_002C02A0
int FUN_002c02a0(void) { short *p = func_002BF838_2C02A0(); long long l, v; if (*(int *)(p + 4) == 0) { func_002E5D30_2C02A0(); if (*p == 1) return (*(volatile unsigned long long *)0x12001000 >> 13) & 1; return 1; } l = func_002E5DC0_2C02A0(); v = (l >> 13) & 1; if (*p == 1) return v; return 1; }

extern char D_0049DDE8_2C8208[] __asm__("D_0049DDE8");
int func_002DCE40_2C8208(char *, char *, ...) __asm__("func_002DCE40"); void func_002C35C8_2C8208(int *, char *) __asm__("func_002C35C8");
// MATCH func_002C8208
int FUN_002c8208(int *o, int *pic) { char buf[256]; int r; if (o[56] != 0) { r = !(o[55] < pic[1]) && !(o[56] < pic[2]); } else r = !(o[57] < pic[3] * pic[4]); if (r == 0) { func_002DCE40_2C8208(buf, D_0049DDE8_2C8208, pic[1], pic[2]); func_002C35C8_2C8208(o, buf); } return r; }

typedef struct { int sem; int *res; int w8; char name1[1024]; char name2[1024]; char buf[1024]; int w3084; int w3088; } T_2ebc48_002EBC48;
extern T_2ebc48_002EBC48 D_00634280_2EBC48[] __asm__("D_00634280"); extern char D_00635540_2EBC48[] __asm__("D_00635540"); extern char D_00634EC0_2EBC48[] __asm__("D_00634EC0"); extern int D_00429918_2EBC48[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ebc48_002EBC48;
void func_002E95B0_2EBC48(int) __asm__("func_002E95B0"); void func_002E96B8_2EBC48(void) __asm__("func_002E96B8"); int func_002E58A0_2EBC48(void *) __asm__("func_002E58A0"); int func_002E8928_2EBC48(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EBC48(int) __asm__("func_002E58B0"); void func_002E95E0_2EBC48(void) __asm__("func_002E95E0"); void func_002E58E0_2EBC48(int) __asm__("func_002E58E0"); void func_002E8038_2EBC48(void *, int) __asm__("func_002E8038");
// MATCH func_002EBC48
int FUN_002ebc48(char *name, char *name2, int a3, char *a4, int a5) { T_2ebc48_002EBC48 *t = D_00634280_2EBC48; S_2ebc48_002EBC48 s; int res; int i; int sem; int r; int v; func_002E95B0_2EBC48(20); if (D_00429918_2EBC48[0] == 0) func_002E96B8_2EBC48(); i = 0; if ((t->name1[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name1[i] = name[i]) == 0) break; } } if (i == 1024) { t->name1[1023] = 0; } i = 0; if ((t->name2[0] = name2[0]) != 0) { while (++i < 1024) { if ((t->name2[i] = name2[i]) == 0) break; } } if (i == 1024) { t->name2[1023] = 0; } if (a5 > 1024) { func_002E95E0_2EBC48(); return -7; } for (i = 0; i < a5; i++) t->buf[i] = a4[i]; t->w3088 = a5; t->w3084 = a3; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EBC48(&s); t->sem = sem; t->res = &res; t->w8 = 4; func_002E8038_2EBC48(D_00634280_2EBC48, 3092); r = func_002E8928_2EBC48(D_00635540_2EBC48, 20, 0, D_00634280_2EBC48, 3092, D_00634EC0_2EBC48, 4, 0, 0); if (r < 0) { func_002E58B0_2EBC48(sem); func_002E95E0_2EBC48(); return -11; } v = *(int *)((unsigned)D_00634EC0_2EBC48 | 0x20000000); func_002E95E0_2EBC48(); if (v == 0) { func_002E58B0_2EBC48(sem); return -11; } func_002E58E0_2EBC48(sem); func_002E58B0_2EBC48(sem); return res; }

typedef struct { int sem; int *res; int w8; char name1[1024]; char name2[1024]; char buf[1024]; int w3084; } T_2ead88_002EAD88;
extern T_2ead88_002EAD88 D_00634280_002EAD88[] __asm__("D_00634280"); extern char D_00635540_002EAD88[] __asm__("D_00635540"); extern char D_00634EC0_002EAD88[] __asm__("D_00634EC0"); extern int D_00429918_002EAD88[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ead88_002EAD88;
void func_002E95B0_2EAD88(int) __asm__("func_002E95B0"); void func_002E96B8_2EAD88(void) __asm__("func_002E96B8"); int func_002E58A0_2EAD88(void *) __asm__("func_002E58A0"); int func_002E8928_2EAD88(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EAD88(int) __asm__("func_002E58B0"); void func_002E95E0_2EAD88(void) __asm__("func_002E95E0"); void func_002E58E0_2EAD88(int) __asm__("func_002E58E0"); void func_002E8038_2EAD88(void *, int) __asm__("func_002E8038");
// MATCH func_002EAD88
int FUN_002ead88(char *name, char *name2, char *a3, int a4) { T_2ead88_002EAD88 *t = D_00634280_002EAD88; S_2ead88_002EAD88 s; int res; int i; int sem; int r; int v; func_002E95B0_2EAD88(14); if (D_00429918_002EAD88[0] == 0) func_002E96B8_2EAD88(); i = 0; if ((t->name1[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name1[i] = name[i]) == 0) break; } } if (i == 1024) { t->name1[1023] = 0; } if (name2 == 0) { t->name2[0] = 0; } else { i = 0; if ((t->name2[0] = name2[0]) != 0) { while (++i < 1024) { if ((t->name2[i] = name2[i]) == 0) break; } } if (i == 1024) { t->name2[1023] = 0; } } if (a4 > 1024) { func_002E95E0_2EAD88(); return -7; } for (i = 0; i < a4; i++) t->buf[i] = a3[i]; t->w3084 = a4; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EAD88(&s); t->sem = sem; t->res = &res; t->w8 = 4; func_002E8038_2EAD88(D_00634280_002EAD88, 3088); r = func_002E8928_2EAD88(D_00635540_002EAD88, 14, 0, D_00634280_002EAD88, 3088, D_00634EC0_002EAD88, 4, 0, 0); if (r < 0) { func_002E58B0_2EAD88(sem); func_002E95E0_2EAD88(); return -11; } v = *(int *)((unsigned)D_00634EC0_002EAD88 | 0x20000000); func_002E95E0_2EAD88(); if (v == 0) { func_002E58B0_2EAD88(sem); return -11; } func_002E58E0_2EAD88(sem); func_002E58B0_2EAD88(sem); return res; }

typedef struct { int sem; int *res; int w8; char name1[1024]; char buf[1024]; int wb; int wd; int we; int wf; } T_2ec110_002EC110;
extern T_2ec110_002EC110 D_00634280_002EC110[] __asm__("D_00634280"); extern char D_00635540_002EC110[] __asm__("D_00635540"); extern char D_00634EC0_002EC110[] __asm__("D_00634EC0"); extern int D_00429918_002EC110[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ec110_002EC110;
void func_002E95B0_2EC110(int) __asm__("func_002E95B0"); void func_002E96B8_2EC110(void) __asm__("func_002E96B8"); int func_002E58A0_2EC110(void *) __asm__("func_002E58A0"); int func_002E8928_2EC110(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EC110(int) __asm__("func_002E58B0"); void func_002E95E0_2EC110(void) __asm__("func_002E95E0"); void func_002E58E0_2EC110(int) __asm__("func_002E58E0"); void func_002E8038_2EC110(void *, int) __asm__("func_002E8038");
// MATCH func_002EC110
int FUN_002ec110(char *name, int b, char *c, unsigned d, int e, unsigned f) { T_2ec110_002EC110 *t = D_00634280_002EC110; S_2ec110_002EC110 s; int res; int i; unsigned j; int sem; int r; int v; func_002E95B0_2EC110(23); if (D_00429918_002EC110[0] == 0) func_002E96B8_2EC110(); i = 0; if ((t->name1[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name1[i] = name[i]) == 0) break; } } if (i == 1024) { t->name1[1023] = 0; } if (d > 1024 || f > 1024) { func_002E95E0_2EC110(); return -22; } for (j = 0; j < d; j++) t->buf[j] = c[j]; t->wd = d; t->wb = b; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EC110(&s); t->wf = f; t->res = &res; t->w8 = 4; t->we = e; t->sem = sem; func_002E8038_2EC110(D_00634280_002EC110, 2076); r = func_002E8928_2EC110(D_00635540_002EC110, 23, 0, D_00634280_002EC110, 2076, D_00634EC0_002EC110, 4, 0, 0); if (r < 0) { func_002E58B0_2EC110(sem); func_002E95E0_2EC110(); return -11; } v = *(int *)((unsigned)D_00634EC0_002EC110 | 0x20000000); func_002E95E0_2EC110(); if (v == 0) { func_002E58B0_2EC110(sem); return -11; } func_002E58E0_2EC110(sem); func_002E58B0_2EC110(sem); return res; }

typedef struct { int sem; int *res; int w8; int w12; int w16; char buf[1024]; int w1044; int w1048; int w1052; } T_2ea810_002EA810;
typedef struct { int w0; int w4; } H_2ea810_002EA810;
extern T_2ea810_002EA810 D_00634280_002EA810[] __asm__("D_00634280"); extern char D_00635540_002EA810[] __asm__("D_00635540"); extern char D_00634EC0_002EA810[] __asm__("D_00634EC0"); extern int D_00429918_002EA810[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2ea810_002EA810;
void *func_002E9130_2EA810(void) __asm__("func_002E9130"); void func_002DC650_2EA810(void *, void *, unsigned) __asm__("func_002DC650");
void func_002E95B0_2EA810(int) __asm__("func_002E95B0"); void func_002E96B8_2EA810(void) __asm__("func_002E96B8"); int func_002E58A0_2EA810(void *) __asm__("func_002E58A0"); int func_002E8928_2EA810(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EA810(int) __asm__("func_002E58B0"); void func_002E95E0_2EA810(void) __asm__("func_002E95E0"); void func_002E58E0_2EA810(int) __asm__("func_002E58E0"); void func_002E8038_2EA810(void *, int) __asm__("func_002E8038");
// MATCH func_002EA810
int FUN_002ea810(int a0, int a1, void *a2, unsigned a3, int a4, unsigned a5) { T_2ea810_002EA810 *t = D_00634280_002EA810; S_2ea810_002EA810 s; int res; int sem; int r; int v; H_2ea810_002EA810 *h; h = func_002E9130_2EA810(); func_002E95B0_2EA810(26); if (D_00429918_002EA810[0] == 0) func_002E96B8_2EA810(); if (h == 0 || h->w4 == 0) { func_002E95E0_2EA810(); return -9; } if (a3 > 1024 || a5 > 1024) { func_002E95E0_2EA810(); return -22; } if (a2 == 0) t->w1052 = 0; else func_002DC650_2EA810(t->buf, a2, a3); t->w12 = h->w0; t->w16 = a1; t->w1052 = a3; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EA810(&s); t->w1048 = a5; t->res = &res; t->w8 = 4; t->w1044 = a4; t->sem = sem; func_002E8038_2EA810(D_00634280_002EA810, 1056); r = func_002E8928_2EA810(D_00635540_002EA810, 26, 0, D_00634280_002EA810, 1056, D_00634EC0_002EA810, 4, 0, 0); if (r < 0) { func_002E58B0_2EA810(sem); func_002E95E0_2EA810(); return -11; } v = *(int *)((unsigned)D_00634EC0_002EA810 | 0x20000000); func_002E95E0_2EA810(); if (v == 0) { func_002E58B0_2EA810(sem); return -11; } func_002E58E0_2EA810(sem); func_002E58B0_2EA810(sem); return res; }


// MATCH func_002CF338
void FUN_002cf338(int *o, int a) { int p; int new_var; if (p) { a = a << 2; p = *o; new_var = p + a; *o = new_var; } else { a = a << 2; p = *o; new_var = p + a; *o = new_var; } }

typedef struct { int w0; int w4; char n1[252]; char n2[252]; } T_2ed680_002ED680;
extern char D_006357C8_2ED680[] __asm__("D_006357C8"); extern char D_006359C0_2ED680[] __asm__("D_006359C0");
int func_002ECC40_2ED680(void) __asm__("func_002ECC40"); int func_002ECD40_2ED680(void) __asm__("func_002ECD40"); void func_002DD928_2ED680(void *, void *, int) __asm__("func_002DD928"); int func_002E8928_2ED680(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED680
int FUN_002ed680(char *a, char *b, int *c, int d) { T_2ed680_002ED680 *p; char *t; int r; if (func_002ECC40_2ED680() < 0) return -65536; if (func_002ECD40_2ED680() != 0) return -65540; t = D_006357C8_2ED680; p = (T_2ed680_002ED680 *)(t - 8); func_002DD928_2ED680(t, a, 252); p->n1[251] = 0; func_002DD928_2ED680(t + 252, b, 252); p->n2[251] = 0; r = func_002E8928_2ED680(D_006359C0_2ED680, d, 0, p, 512, p, 16, 0, 0); if (r < 0) return -65537; if (p->w0 == 0) return -65539; c[0] = p->w0; c[1] = p->w4; return 0; }

extern int D_006357C0_2ED218[] __asm__("D_006357C0"); extern char D_006359C0_2ED218[] __asm__("D_006359C0");
int func_002ECC40_2ED218(void) __asm__("func_002ECC40"); int func_002ECD40_2ED218(void) __asm__("func_002ECD40");
int func_002E8928_2ED218(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED218
int FUN_002ed218(int x) { int r; if (func_002ECC40_2ED218() < 0) return -65536; if (func_002ECD40_2ED218() != 0) return -65540; D_006357C0_2ED218[0] = x; r = func_002E8928_2ED218(D_006359C0_2ED218, 8, 0, D_006357C0_2ED218, 4, D_006357C0_2ED218, 4, 0, 0); if (r < 0) return -65537; return D_006357C0_2ED218[0]; }

extern int D_006357C0_002ED348[] __asm__("D_006357C0"); extern char D_006359C0_002ED348[] __asm__("D_006359C0");
int func_002ECC40_2ED348(void) __asm__("func_002ECC40"); int func_002ECD40_2ED348(void) __asm__("func_002ECD40");
int func_002E8928_2ED348(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED348
int FUN_002ed348(int x) { int r; if (func_002ECC40_2ED348() < 0) return -65536; if (func_002ECD40_2ED348() != 0) return -65540; D_006357C0_002ED348[0] = x; r = func_002E8928_2ED348(D_006359C0_002ED348, 10, 0, D_006357C0_002ED348, 4, D_006357C0_002ED348, 4, 0, 0); if (r < 0) return -65537; return D_006357C0_002ED348[0]; }

typedef struct 
{
  int *w0;
  int pad[2];
  int *w12;
} O_002CF6C0;
// MATCH func_002CF6C0
void FUN_002cf6c0(O_002CF6C0 *o) { int *w = o->w0; int *new_var; int *p = o->w12; o->w12 = 0; new_var = w - 1; p[0] += ((unsigned) (new_var - p)) / 4; }

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF228;
void func_002CF158_2CF228(void *) __asm__("func_002CF158");
// MATCH func_002CF228
void FUN_002cf228(Pk_002CF228 *o, unsigned a, unsigned b, int c, int d, unsigned e) { int *p; unsigned t; func_002CF158_2CF228(o); p = o->w0; t = b | 0x30000000; *p++ = e | t; *p = a & 0x9fffffff; p[1] = c; p[2] = d; o->w0 = p + 3; }

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF508;
void func_002CF458_2CF508(void *) __asm__("func_002CF458");
// MATCH func_002CF508
void FUN_002cf508(Pk_002CF508 *o, unsigned a, unsigned b, int c, int d, unsigned e) { int *p; unsigned t; func_002CF458_2CF508(o); p = o->w0; t = b | 0x30000000; *p++ = e | t; *p = a & 0x9fffffff; p[1] = c; p[2] = d; o->w0 = p + 3; }


// MATCH func_002CF368
void FUN_002cf368(int *o) { unsigned long *hdr = (unsigned long *)o[3]; int *cur = (int *)*o; unsigned long h = *hdr; unsigned n; unsigned long f; unsigned q; int *p; n = (((int)cur - (int)hdr) >> 3) - 2; f = h >> 58 & 3; if (f != 1) n = n >> 1; if (f != 2) { q = h >> 60; if (q == 0) q = 16; n = (n + q - 1) / q; } o[3] = 0; *hdr = h + n; p = cur; while (((unsigned)p & 0xc) != 0) { *p = 0; p++; } *o = (int)p; }


// MATCH func_002CF708
void FUN_002cf708(int *o) { unsigned long *hdr = (unsigned long *)o[5]; int *cur = (int *)*o; unsigned long h = *hdr; unsigned n; unsigned long f; unsigned q; int *p; n = (((int)cur - (int)hdr) >> 3) - 2; f = h >> 58 & 3; if (f != 1) n = n >> 1; if (f != 2) { q = h >> 60; if (q == 0) q = 16; n = (n + q - 1) / q; } o[5] = 0; *hdr = h + n; p = cur; while (((unsigned)p & 0xc) != 0) { *p = 0; p++; } *o = (int)p; }

typedef struct 
{
  int *w0;
  int w4;
  int w8;
  int w12;
} Pk_002CF1B0;
int func_002CF158_2CF1B0(void *) __asm__("func_002CF158");
// MATCH func_002CF1B0
void FUN_002cf1b0(Pk_002CF1B0 *o, int a, int b, unsigned c) { int new_var; int r; int *p; unsigned t; r = func_002CF158_2CF1B0(o); p = o->w0; t = c | 0x10000000; do { o->w8 = r; } while (0); *(p++) = t; p[1] = a; o->w0 = p + 3; p[2] = b; p[0] = (new_var = 0); }

#define R(a) (*(volatile unsigned *)(a))
void func_002CF8F8_2CFAB0(int) __asm__("func_002CF8F8"); void func_002CF960_2CFAB0(int) __asm__("func_002CF960");
// MATCH func_002CFAB0
void FUN_002cfab0(int *o) { unsigned c, cmd; int n, q, p, v, a0, a2; c = o[7]; cmd = c & 0x7f; a0 = o[0]; a2 = o[2]; n = ((c >> 16) & 3) + ((c >> 8) & 0xf); q = a2 + n; p = a0 - n * 16; if (o[4] != 0 && o[5] != 0) { R(0x1000b010) = o[4]; R(0x1000b020) = o[5]; func_002CF8F8_2CFAB0(o[6] | 0x100); } do { v = R(0x10002010); } while (v < 0); R(0x10002000) = cmd; do { v = R(0x10002010); } while (v < 0); if (p != 0 && q != 0) { R(0x1000b410) = p; R(0x1000b430) = o[1]; R(0x1000b420) = q; func_002CF960_2CFAB0(o[3] | 0x100); } }

typedef struct { int *w0; int w4; int w8; int w12; } Pk_002CF2C0;
int func_002CF158_2CF2C0(void *) __asm__("func_002CF158");
// MATCH func_002CF2C0
void FUN_002cf2c0(Pk_002CF2C0 *o, int a, int b, unsigned c) { int r; int *p; unsigned t; r = func_002CF158_2CF2C0(o); p = o->w0; t = c | 0x70000000; do { o->w8 = r; } while (0); *(p++) = t; p[1] = a; o->w0 = p + 3; p[2] = b; p[0] = 0; }

int func_002CA8D8_2CAA98(void) __asm__("func_002CA8D8");
// MATCH func_002CAA98
int FUN_002caa98(char *o) { unsigned t; if (func_002CA8D8_2CAA98() != 0) return 0; __asm__ ("cfc2 %0, $16" : "=r"(t)); *(int *)(o + 512) = t; __asm__ ("cfc2 %0, $17" : "=r"(t)); *(int *)(o + 516) = t; __asm__ ("cfc2 %0, $18" : "=r"(t)); *(int *)(o + 520) = t; __asm__ ("cfc2 %0, $20" : "=r"(t)); *(int *)(o + 524) = t; __asm__ ("cfc2 %0, $21" : "=r"(t)); *(int *)(o + 528) = t; __asm__ ("cfc2 %0, $22" : "=r"(t)); *(int *)(o + 532) = t; __asm__ ("cfc2 %0, $0" : "=r"(t)); *(short *)(o + 536) = t; __asm__ ("cfc2 %0, $1" : "=r"(t)); *(short *)(o + 538) = t; __asm__ ("cfc2 %0, $2" : "=r"(t)); *(short *)(o + 540) = t; __asm__ ("cfc2 %0, $3" : "=r"(t)); *(short *)(o + 542) = t; __asm__ ("cfc2 %0, $4" : "=r"(t)); *(short *)(o + 544) = t; __asm__ ("cfc2 %0, $5" : "=r"(t)); *(short *)(o + 546) = t; __asm__ ("cfc2 %0, $6" : "=r"(t)); *(short *)(o + 548) = t; __asm__ ("cfc2 %0, $7" : "=r"(t)); *(short *)(o + 550) = t; __asm__ ("cfc2 %0, $8" : "=r"(t)); *(short *)(o + 552) = t; __asm__ ("cfc2 %0, $9" : "=r"(t)); *(short *)(o + 554) = t; __asm__ ("cfc2 %0, $10" : "=r"(t)); *(short *)(o + 556) = t; __asm__ ("cfc2 %0, $11" : "=r"(t)); *(short *)(o + 558) = t; __asm__ ("cfc2 %0, $12" : "=r"(t)); *(short *)(o + 560) = t; __asm__ ("cfc2 %0, $13" : "=r"(t)); *(short *)(o + 562) = t; __asm__ ("cfc2 %0, $14" : "=r"(t)); *(short *)(o + 564) = t; __asm__ ("cfc2 %0, $15" : "=r"(t)); *(short *)(o + 566) = t; return 1; }

int func_002CAA38_2CA908(void) __asm__("func_002CAA38");
// MATCH func_002CA908
int FUN_002ca908(void) { int r = 0; unsigned t; switch (func_002CAA38_2CA908()) { case 4: __asm__ volatile("cfc2 %0, $28" : "=r"(t)); t |= 1; __asm__ volatile("ctc2 %0, $28" : : "r"(t)); case 0: case 3: r = 1; break; case 1: case 2: break; } return r; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_002D89B0;
typedef union { float f; unsigned raw; struct { unsigned fraction:23; unsigned exp:8; unsigned sign:1; } bits; } FU_002d89b0;
// MATCH func_002D89B0
void __unpack_f(FU_002d89b0 *src, FPF_002D89B0 *dst) { unsigned fraction; int exp; int sign; fraction = src->bits.fraction; exp = src->bits.exp; sign = src->bits.sign; dst->sign = sign; if (exp == 0) { dst->cls = 2; } else if (exp == 0xff) { if (fraction == 0) { dst->cls = 4; } else { if (fraction & 0x100000) dst->cls = 1; else dst->cls = 0; dst->ll = fraction; } } else { dst->exp = exp - 127; dst->cls = 3; dst->ll = (fraction << 7) | 0x40000000; } }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FPD_002D7580;
typedef union { double d; unsigned long long raw; struct { unsigned long long fraction:52; unsigned exp:11; unsigned sign:1; } bits; } FU_002D7580;
// MATCH func_002D7580
void __unpack_d(FU_002D7580 *src, FPD_002D7580 *dst) { unsigned long long fraction; int exp; int sign; fraction = src->bits.fraction; exp = src->bits.exp; sign = src->bits.sign; dst->sign = sign; if (exp == 0) { do { dst->cls = 2; } while (0); } else if (exp == 0x7ff) { if (fraction == 0) { dst->cls = 4; } else { if (fraction & 0x8000000000000ULL) dst->cls = 1; else dst->cls = 0; dst->ll = fraction; } } else { dst->exp = exp - 1023; dst->cls = 3; dst->ll = (fraction << 8) | 0x1000000000000000ULL; } }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FPD_2d7450_002D7450;
typedef union { double d; unsigned long long raw; struct { unsigned long long fraction:52; unsigned exp:11; unsigned sign:1; } bits; } FU_2d7450;
static inline int isnan_2d7450_002D7450(FPD_2d7450_002D7450 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7450_002D7450(FPD_2d7450_002D7450 *x) { return x->cls == 4; }
static inline int iszero_2d7450_002D7450(FPD_2d7450_002D7450 *x) { return x->cls == 2; }
// MATCH func_002D7450
long __pack_d(FPD_2d7450_002D7450 *src) { FU_2d7450 dst; unsigned long long fraction = src->ll; int sign = src->sign; int exp = 0; if (isnan_2d7450_002D7450(src)) { exp = 2047; if (src->cls == 1 || 1) fraction |= 0x8000000000000ULL; } else if (isinf_2d7450_002D7450(src)) { exp = 2047; fraction = 0; } else if (iszero_2d7450_002D7450(src)) { exp = 0; fraction = 0; } else if (fraction == 0) { exp = 0; } else { if (src->exp < -1022) { int shift = -1022 - src->exp; exp = 0; if (shift > 56) { fraction = 0; } else { fraction >>= shift; } fraction >>= 8; } else if (src->exp > 1023) { exp = 2047; fraction = 0; } else { exp = src->exp + 1023; if ((fraction & 0xff) == 0x80) { if (fraction & (1 << 8)) fraction += 0x7f + 1; } else { fraction += 0x7f; } if (fraction >= 0x2000000000000000ULL) { fraction >>= 1; exp += 1; } fraction >>= 8; } } dst.bits.fraction = fraction; dst.bits.exp = exp; dst.bits.sign = sign; return dst.raw; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_2d88a0_002D88A0;
typedef union { float f; unsigned raw; struct { unsigned fraction:23; unsigned exp:8; unsigned sign:1; } bits; } FU_2d88a0;
static inline int isnan_2d88a0_002D88A0(FPF_2d88a0_002D88A0 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d88a0_002D88A0(FPF_2d88a0_002D88A0 *x) { return x->cls == 4; }
static inline int iszero_2d88a0_002D88A0(FPF_2d88a0_002D88A0 *x) { return x->cls == 2; }
// MATCH func_002D88A0
float FUN_002d88a0(FPF_2d88a0_002D88A0 *src) { FU_2d88a0 dst; unsigned fraction = src->ll; int sign = src->sign; int exp = 0; if (isnan_2d88a0_002D88A0(src)) { exp = 255; if (src->cls == 1 || 1) fraction |= 0x100000; } else if (isinf_2d88a0_002D88A0(src)) { exp = 255; fraction = 0; } else if (iszero_2d88a0_002D88A0(src)) { exp = 0; fraction = 0; } else if (fraction == 0) { exp = 0; } else { if (src->exp < -126) { int shift = -126 - src->exp; exp = 0; if (shift > 25) { fraction = 0; } else { fraction >>= shift; } fraction >>= 7; } else if (src->exp > 127) { exp = 255; fraction = 0; } else { exp = src->exp + 127; if ((fraction & 0x7f) == 0x40) { if (fraction & (1 << 7)) fraction += 0x3f + 1; } else { fraction += 0x3f; } if (fraction >= 0x80000000U) { fraction >>= 1; exp += 1; } fraction >>= 7; } } dst.bits.fraction = fraction; dst.bits.exp = exp; dst.bits.sign = sign; return dst.f; }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FPD_2d7620_002D7620;
static inline int isnan_2d7620_002D7620(FPD_2d7620_002D7620 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7620_002D7620(FPD_2d7620_002D7620 *x) { return x->cls == 4; }
static inline int iszero_2d7620_002D7620(FPD_2d7620_002D7620 *x) { return x->cls == 2; }
extern FPD_2d7620_002D7620 D_00631AD0_2D7620 __asm__("D_00631AD0");
static inline FPD_2d7620_002D7620 *nan_2d7620_002D7620(void) { return &D_00631AD0_2D7620; }
// MATCH func_002D7620
FPD_2d7620_002D7620 *_fpadd_parts(FPD_2d7620_002D7620 *a, FPD_2d7620_002D7620 *b, FPD_2d7620_002D7620 *tmp) { long long tfraction; int a_normal_exp; int b_normal_exp; unsigned long long a_fraction; unsigned long long b_fraction; if (isnan_2d7620_002D7620(a)) return a; if (isnan_2d7620_002D7620(b)) return b; if (isinf_2d7620_002D7620(a)) { if (isinf_2d7620_002D7620(b) && a->sign != b->sign) return nan_2d7620_002D7620(); return a; } if (isinf_2d7620_002D7620(b)) { return b; } if (iszero_2d7620_002D7620(b)) { if (iszero_2d7620_002D7620(a)) { *tmp = *a; tmp->sign = a->sign & b->sign; return tmp; } return a; } if (iszero_2d7620_002D7620(a)) { return b; } { int diff; a_normal_exp = a->exp; b_normal_exp = b->exp; a_fraction = a->ll; b_fraction = b->ll; diff = a_normal_exp - b_normal_exp; if (diff < 0) diff = -diff; if (diff < 64) { while (a_normal_exp > b_normal_exp) { b_normal_exp++; b_fraction = (b_fraction & 1) | (b_fraction >> 1); } while (b_normal_exp > a_normal_exp) { a_normal_exp++; a_fraction = (a_fraction & 1) | (a_fraction >> 1); } } else { if (a_normal_exp > b_normal_exp) { b_normal_exp = a_normal_exp; b_fraction = 0; } else { a_normal_exp = b_normal_exp; a_fraction = 0; } } } if (a->sign != b->sign) { if (a->sign) { tfraction = -a_fraction + b_fraction; } else { tfraction = a_fraction - b_fraction; } if (tfraction >= 0) { tmp->sign = 0; tmp->exp = a_normal_exp; tmp->ll = tfraction; } else { tmp->sign = 1; tmp->exp = a_normal_exp; tmp->ll = -tfraction; } while (tmp->ll < 0x1000000000000000ULL && tmp->ll) { tmp->ll <<= 1; tmp->exp--; } } else { tmp->sign = a->sign; tmp->exp = a_normal_exp; tmp->ll = a_fraction + b_fraction; } tmp->cls = 3; if (tmp->ll >= 0x2000000000000000ULL) { tmp->ll = (tmp->ll & 1) | (tmp->ll >> 1); tmp->exp++; } return tmp; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_2d8a40_002D8A40;
static inline int isnan_2d8a40_002D8A40(FPF_2d8a40_002D8A40 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d8a40_002D8A40(FPF_2d8a40_002D8A40 *x) { return x->cls == 4; }
static inline int iszero_2d8a40_002D8A40(FPF_2d8a40_002D8A40 *x) { return x->cls == 2; }
extern FPF_2d8a40_002D8A40 D_00631AE8_2D8A40 __asm__("D_00631AE8");
static inline FPF_2d8a40_002D8A40 *nan_2d8a40_002D8A40(void) { return &D_00631AE8_2D8A40; }
// MATCH func_002D8A40
FPF_2d8a40_002D8A40 *FUN_002d8a40(FPF_2d8a40_002D8A40 *a, FPF_2d8a40_002D8A40 *b, FPF_2d8a40_002D8A40 *tmp) { int tfraction; int a_normal_exp; int b_normal_exp; unsigned a_fraction; unsigned b_fraction; if (isnan_2d8a40_002D8A40(a)) return a; if (isnan_2d8a40_002D8A40(b)) return b; if (isinf_2d8a40_002D8A40(a)) { if (isinf_2d8a40_002D8A40(b) && a->sign != b->sign) return nan_2d8a40_002D8A40(); return a; } if (isinf_2d8a40_002D8A40(b)) { return b; } if (iszero_2d8a40_002D8A40(b)) { if (iszero_2d8a40_002D8A40(a)) { *tmp = *a; tmp->sign = a->sign & b->sign; return tmp; } return a; } if (iszero_2d8a40_002D8A40(a)) { return b; } { int diff; a_normal_exp = a->exp; b_normal_exp = b->exp; a_fraction = a->ll; b_fraction = b->ll; diff = a_normal_exp - b_normal_exp; if (diff < 0) diff = -diff; if (diff < 32) { while (a_normal_exp > b_normal_exp) { b_normal_exp++; b_fraction = (b_fraction & 1) | (b_fraction >> 1); } while (b_normal_exp > a_normal_exp) { a_normal_exp++; a_fraction = (a_fraction & 1) | (a_fraction >> 1); } } else { if (a_normal_exp > b_normal_exp) { b_normal_exp = a_normal_exp; b_fraction = 0; } else { a_normal_exp = b_normal_exp; a_fraction = 0; } } } if (a->sign != b->sign) { if (a->sign) { tfraction = -a_fraction + b_fraction; } else { tfraction = a_fraction - b_fraction; } if (tfraction >= 0) { tmp->sign = 0; tmp->exp = a_normal_exp; tmp->ll = tfraction; } else { tmp->sign = 1; tmp->exp = a_normal_exp; tmp->ll = -tfraction; } while (tmp->ll < 0x40000000U && tmp->ll) { tmp->ll <<= 1; tmp->exp--; } } else { tmp->sign = a->sign; tmp->exp = a_normal_exp; tmp->ll = a_fraction + b_fraction; } tmp->cls = 3; if (tmp->ll >= 0x80000000U) { tmp->ll = (tmp->ll & 1) | (tmp->ll >> 1); tmp->exp++; } return tmp; }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FPD_2d7e98_002D7E98;
long func_002D7450_2D7E98(void *) __asm__("func_002D7450");
// MATCH func_002D7E98
long __floatsidf(int arg_a) { FPD_2d7e98_002D7E98 in; in.cls = 3; in.sign = arg_a < 0; if (!arg_a) { in.cls = 2; } else { in.exp = 60; if (in.sign) { if (arg_a == (int)0x80000000) { return 0xc1e0000000000000L; } in.ll = (-arg_a); } else in.ll = arg_a; while (in.ll < (1LL << 60)) { in.ll <<= 1; in.exp -= 1; } } return func_002D7450_2D7E98(&in); }

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_2d91f8_002D91F8;
float func_002D88A0_2D91F8(void *) __asm__("func_002D88A0");
// MATCH func_002D91F8
float FUN_002d91f8(int arg_a) { FPF_2d91f8_002D91F8 in; in.cls = 3; in.sign = arg_a < 0; if (!arg_a) { in.cls = 2; } else { in.exp = 30; if (in.sign) { if (arg_a == (int)0x80000000) { return -2147483648.0f; } in.ll = (-arg_a); } else in.ll = arg_a; while (in.ll < (1 << 30)) { in.ll <<= 1; in.exp -= 1; } } return func_002D88A0_2D91F8(&in); }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP_2d7d30_002D7D30;
static inline int isnan_2d7d30_002D7D30(FP_2d7d30_002D7D30 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7d30_002D7D30(FP_2d7d30_002D7D30 *x) { return x->cls == 4; }
static inline int iszero_2d7d30_002D7D30(FP_2d7d30_002D7D30 *x) { return x->cls == 2; }
// MATCH func_002D7D30
int __fpcmp_parts_d(FP_2d7d30_002D7D30 *a, FP_2d7d30_002D7D30 *b) { if (isnan_2d7d30_002D7D30(a) || isnan_2d7d30_002D7D30(b)) { return 1; } if (isinf_2d7d30_002D7D30(a) && isinf_2d7d30_002D7D30(b)) { return b->sign - a->sign; } if (isinf_2d7d30_002D7D30(a)) { return a->sign ? -1 : 1; } if (isinf_2d7d30_002D7D30(b)) { return b->sign ? 1 : -1; } if (iszero_2d7d30_002D7D30(a) && iszero_2d7d30_002D7D30(b)) { return 0; } if (iszero_2d7d30_002D7D30(a)) { return b->sign ? 1 : -1; } if (iszero_2d7d30_002D7D30(b)) { return a->sign ? -1 : 1; } if (a->sign != b->sign) { return a->sign ? -1 : 1; } if (a->exp > b->exp) { return a->sign ? -1 : 1; } if (a->exp < b->exp) { return a->sign ? 1 : -1; } if (a->ll > b->ll) { return a->sign ? -1 : 1; } if (a->ll < b->ll) { return a->sign ? 1 : -1; } return 0; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FP_2d9090_002D9090;
static inline int isnan_2d9090_002D9090(FP_2d9090_002D9090 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d9090_002D9090(FP_2d9090_002D9090 *x) { return x->cls == 4; }
static inline int iszero_2d9090_002D9090(FP_2d9090_002D9090 *x) { return x->cls == 2; }
// MATCH func_002D9090
int FUN_002d9090(FP_2d9090_002D9090 *a, FP_2d9090_002D9090 *b) { if (isnan_2d9090_002D9090(a) || isnan_2d9090_002D9090(b)) { return 1; } if (isinf_2d9090_002D9090(a) && isinf_2d9090_002D9090(b)) { return b->sign - a->sign; } if (isinf_2d9090_002D9090(a)) { return a->sign ? -1 : 1; } if (isinf_2d9090_002D9090(b)) { return b->sign ? 1 : -1; } if (iszero_2d9090_002D9090(a) && iszero_2d9090_002D9090(b)) { return 0; } if (iszero_2d9090_002D9090(a)) { return b->sign ? 1 : -1; } if (iszero_2d9090_002D9090(b)) { return a->sign ? -1 : 1; } if (a->sign != b->sign) { return a->sign ? -1 : 1; } if (a->exp > b->exp) { return a->sign ? -1 : 1; } if (a->exp < b->exp) { return a->sign ? 1 : -1; } if (a->ll > b->ll) { return a->sign ? -1 : 1; } if (a->ll < b->ll) { return a->sign ? 1 : -1; } return 0; }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP_2d7fe8_002D7FE8;
static inline int isnan_2d7fe8_002D7FE8(FP_2d7fe8_002D7FE8 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7fe8_002D7FE8(FP_2d7fe8_002D7FE8 *x) { return x->cls == 4; }
static inline int iszero_2d7fe8_002D7FE8(FP_2d7fe8_002D7FE8 *x) { return x->cls == 2; }
void func_002D7580_2D7FE8(void *, void *) __asm__("func_002D7580");
// MATCH func_002D7FE8
unsigned FUN_002d7fe8(double arg_a) { FP_2d7fe8_002D7FE8 a; func_002D7580_2D7FE8(&arg_a, &a); if (iszero_2d7fe8_002D7FE8(&a)) return 0; if (isnan_2d7fe8_002D7FE8(&a)) return 0; if (a.sign) return 0; if (isinf_2d7fe8_002D7FE8(&a)) return 0xffffffffU; if (a.exp < 0) return 0; if (a.exp > 31) return 0xffffffffU; else if (a.exp > 60) return a.ll << (a.exp - 60); else return a.ll >> (60 - a.exp); }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP_2d80f0_002D80F0;
void func_002D7580_2D80F0(void *, void *) __asm__("func_002D7580"); float func_002D9410_2D80F0(int, int, int, int) __asm__("func_002D9410");
// MATCH func_002D80F0
float FUN_002d80f0(double arg_a) { FP_2d80f0_002D80F0 in; unsigned sffrac; func_002D7580_2D80F0(&arg_a, &in); sffrac = in.ll >> 30; if ((in.ll & ((1ULL << 30) - 1)) != 0) sffrac |= 1; return func_002D9410_2D80F0(in.cls, in.sign, in.exp, sffrac); }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FPD_2d7bc8_002D7BC8;
static inline int isnan_2d7bc8_002D7BC8(FPD_2d7bc8_002D7BC8 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7bc8_002D7BC8(FPD_2d7bc8_002D7BC8 *x) { return x->cls == 4; }
static inline int iszero_2d7bc8_002D7BC8(FPD_2d7bc8_002D7BC8 *x) { return x->cls == 2; }
extern FPD_2d7bc8_002D7BC8 D_00631AD0;
static inline FPD_2d7bc8_002D7BC8 *nan_2d7bc8_002D7BC8(void) { return &D_00631AD0; }
void func_002D7580(void *, void *); long func_002D7450(void *);
static inline FPD_2d7bc8_002D7BC8 *fpdiv_parts_2d7bc8_002D7BC8(FPD_2d7bc8_002D7BC8 *a, FPD_2d7bc8_002D7BC8 *b) { unsigned long long bit; unsigned long long numerator; unsigned long long denominator; unsigned long long quotient; if (isnan_2d7bc8_002D7BC8(a)) return a; if (isnan_2d7bc8_002D7BC8(b)) return b; a->sign = a->sign ^ b->sign; if (isinf_2d7bc8_002D7BC8(a) || iszero_2d7bc8_002D7BC8(a)) { if (a->cls == b->cls) return nan_2d7bc8_002D7BC8(); return a; } if (isinf_2d7bc8_002D7BC8(b)) { a->ll = 0; a->exp = 0; return a; } if (iszero_2d7bc8_002D7BC8(b)) { a->cls = 4; return a; } { a->exp = a->exp - b->exp; numerator = a->ll; denominator = b->ll; if (numerator < denominator) { numerator *= 2; a->exp--; } bit = 0x1000000000000000ULL; quotient = 0; while (bit) { if (numerator >= denominator) { quotient |= bit; numerator -= denominator; } bit >>= 1; numerator *= 2; } if ((quotient & 0xff) == 0x80) { if (quotient & (1 << 8)) { quotient += 0x7f + 1; } else if (numerator) { quotient += 0x7f + 1; } } a->ll = quotient; return a; } } 
// MATCH func_002D7BC8
long FUN_002d7bc8(long x, long y) { FPD_2d7bc8_002D7BC8 a; FPD_2d7bc8_002D7BC8 b; func_002D7580(&x, &a); func_002D7580(&y, &b); return func_002D7450(fpdiv_parts_2d7bc8_002D7BC8(&a, &b)); }

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_2d8f30_002D8F30;
static inline int isnan_2d8f30_002D8F30(FPF_2d8f30_002D8F30 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d8f30_002D8F30(FPF_2d8f30_002D8F30 *x) { return x->cls == 4; }
static inline int iszero_2d8f30_002D8F30(FPF_2d8f30_002D8F30 *x) { return x->cls == 2; }
extern FPF_2d8f30_002D8F30 D_00631AE8_2D8F30 __asm__("D_00631AE8");
static inline FPF_2d8f30_002D8F30 *nan_2d8f30_002D8F30(void) { return &D_00631AE8_2D8F30; }
void func_002D89B0_2D8F30(void *, void *) __asm__("func_002D89B0"); float func_002D88A0_2D8F30(void *) __asm__("func_002D88A0");
static inline FPF_2d8f30_002D8F30 *fpdiv_parts_2d8f30_002D8F30(FPF_2d8f30_002D8F30 *a, FPF_2d8f30_002D8F30 *b) { unsigned bit; unsigned numerator; unsigned denominator; unsigned quotient; if (isnan_2d8f30_002D8F30(a)) return a; if (isnan_2d8f30_002D8F30(b)) return b; a->sign = a->sign ^ b->sign; if (isinf_2d8f30_002D8F30(a) || iszero_2d8f30_002D8F30(a)) { if (a->cls == b->cls) return nan_2d8f30_002D8F30(); return a; } if (isinf_2d8f30_002D8F30(b)) { a->ll = 0; a->exp = 0; return a; } if (iszero_2d8f30_002D8F30(b)) { a->cls = 4; return a; } { a->exp = a->exp - b->exp; numerator = a->ll; denominator = b->ll; if (numerator < denominator) { numerator *= 2; a->exp--; } bit = 0x40000000U; quotient = 0; while (bit) { if (numerator >= denominator) { quotient |= bit; numerator -= denominator; } bit >>= 1; numerator *= 2; } if ((quotient & 0x7f) == 0x40) { if (quotient & (1 << 7)) { quotient += 0x3f + 1; } else if (numerator) { quotient += 0x3f + 1; } } a->ll = quotient; return a; } } float FUN_002d8f30(float x, float y) { FPF_2d8f30_002D8F30 a; FPF_2d8f30_002D8F30 b; func_002D89B0_2D8F30(&x, &a); func_002D89B0_2D8F30(&y, &b); return func_002D88A0_2D8F30(fpdiv_parts_2d8f30_002D8F30(&a, &b)); }
// MATCH func_002D8F30

typedef struct { int cls; int sign; int exp; unsigned ll; } FPF_2d8d38_002D8D38;
static inline int isnan_2d8d38_002D8D38(FPF_2d8d38_002D8D38 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d8d38_002D8D38(FPF_2d8d38_002D8D38 *x) { return x->cls == 4; }
static inline int iszero_2d8d38_002D8D38(FPF_2d8d38_002D8D38 *x) { return x->cls == 2; }
extern FPF_2d8d38_002D8D38 D_00631AE8_2D8D38 __asm__("D_00631AE8");
static inline FPF_2d8d38_002D8D38 *nan_2d8d38_002D8D38(void) { return &D_00631AE8_2D8D38; }
void func_002D89B0_2D8D38(void *, void *) __asm__("func_002D89B0"); float func_002D88A0_2D8D38(void *) __asm__("func_002D88A0");
static inline FPF_2d8d38_002D8D38 *fpmul_parts_2d8d38_002D8D38(FPF_2d8d38_002D8D38 *a, FPF_2d8d38_002D8D38 *b, FPF_2d8d38_002D8D38 *tmp) { unsigned low = 0; unsigned high = 0; if (isnan_2d8d38_002D8D38(a)) { a->sign = a->sign != b->sign; return a; } if (isnan_2d8d38_002D8D38(b)) { b->sign = a->sign != b->sign; return b; } if (isinf_2d8d38_002D8D38(a)) { if (iszero_2d8d38_002D8D38(b)) return nan_2d8d38_002D8D38(); a->sign = a->sign != b->sign; return a; } if (isinf_2d8d38_002D8D38(b)) { if (iszero_2d8d38_002D8D38(a)) return nan_2d8d38_002D8D38(); b->sign = a->sign != b->sign; return b; } if (iszero_2d8d38_002D8D38(a)) { a->sign = a->sign != b->sign; return a; } if (iszero_2d8d38_002D8D38(b)) { b->sign = a->sign != b->sign; return b; } { unsigned long long res = (unsigned long long)a->ll * (unsigned long long)b->ll; high = res >> 32; low = res; } tmp->exp = a->exp + b->exp + 2; tmp->sign = a->sign != b->sign; while (high >= 0x80000000U) { tmp->exp++; if (high & 1) { low >>= 1; low |= 0x80000000U; } high >>= 1; } while (high < 0x40000000U) { tmp->exp--; high <<= 1; if (low & 0x80000000U) high |= 1; low <<= 1; } if ((high & 0x7f) == 0x40) { if (high & (1 << 7)) { high += 0x3f + 1; } else if (low) { high += 0x3f + 1; } } tmp->ll = high; tmp->cls = 3; return tmp; } float FUN_002d8d38(float x, float y) { FPF_2d8d38_002D8D38 a; FPF_2d8d38_002D8D38 b; FPF_2d8d38_002D8D38 tmp; func_002D89B0_2D8D38(&x, &a); func_002D89B0_2D8D38(&y, &b); return func_002D88A0_2D8D38(fpmul_parts_2d8d38_002D8D38(&a, &b, &tmp)); }
// MATCH func_002D8D38

typedef struct { int pad[14]; int didinit; } R_2e18f8_002E18F8;
typedef struct F_2e18f8_002E18F8 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; void *cookie; void *rd; int (*wr)(void *, unsigned char *, int); char pad[44]; R_2e18f8_002E18F8 *data; } F_2e18f8_002E18F8;
extern R_2e18f8_002E18F8 *D_004293F4_2E18F8[] __asm__("D_004293F4");
long func_002DBBB0_2E18F8(R_2e18f8_002E18F8 *, void *) __asm__("func_002DBBB0"); void func_002DBB20_2E18F8(R_2e18f8_002E18F8 *) __asm__("func_002DBB20");
void func_002E18F8_2E18F8(void) __asm__("func_002E18F8");
// MATCH func_002E18F8
long FUN_002e18f8(F_2e18f8_002E18F8 *fp) { unsigned char *p; int n, t; R_2e18f8_002E18F8 *d; R_2e18f8_002E18F8 *a; int dd; if (fp == 0) return func_002DBBB0_2E18F8(D_004293F4_2E18F8[0], (void *)func_002E18F8_2E18F8); do { if (fp->data == 0) fp->data = D_004293F4_2E18F8[0]; if (fp->data->didinit == 0) func_002DBB20_2E18F8(fp->data); } while (0); t = fp->flags; if ((t & 8) == 0) return 0; if ((p = fp->base) == 0) return 0; n = fp->p - p; fp->p = p; fp->w = t & 3 ? 0 : fp->size; while (n > 0) { t = (*fp->wr)(fp->cookie, p, n); if (t <= 0) { fp->flags |= 0x40; return -1; } p += t; n -= t; } return 0; }

typedef struct { unsigned char *p; int r; } F_2e1a00_002E1A00;
void *memcpy(void *, const void *, unsigned);
int func_002E37E8_2E1A00(void *) __asm__("func_002E37E8");
// MATCH func_002E1A00
unsigned FUN_002e1a00(void *buf, unsigned size, unsigned count, F_2e1a00_002E1A00 *fp) { unsigned resid; char *p; int r; unsigned total; if ((resid = count * size) == 0) return 0; if (fp->r < 0) fp->r = 0; total = resid; p = buf; while (resid > (r = fp->r)) { (void) memcpy((void *) p, (void *) fp->p, (unsigned) r); fp->p += r; p += r; resid -= r; if (func_002E37E8_2E1A00(fp)) { return (total - resid) / size; } } (void) memcpy((void *) p, (void *) fp->p, resid); fp->r -= resid; fp->p += resid; return count; }

typedef struct { int pad[14]; int didinit; } R_2e0388_002E0388;
typedef struct F_2e0388_002E0388 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; char pad1[20]; unsigned char *ubbase; int ubsize; char pad3[8]; unsigned char ubuf[4]; char pad2[16]; R_2e0388_002E0388 *data; } F_2e0388_002E0388;
extern R_2e0388_002E0388 *D_004293F4_2E0388[] __asm__("D_004293F4");
void func_002DBB20_2E0388(R_2e0388_002E0388 *) __asm__("func_002DBB20"); void func_002E1B20_2E0388(R_2e0388_002E0388 *, void *) __asm__("func_002E1B20"); void func_002E24D8_2E0388(F_2e0388_002E0388 *) __asm__("func_002E24D8");
// MATCH func_002E0388
int FUN_002e0388(F_2e0388_002E0388 *fp) { do { if (fp->data == 0) fp->data = D_004293F4_2E0388[0]; if (fp->data->didinit == 0) func_002DBB20_2E0388(fp->data); } while (0); if ((fp->flags & 8) == 0) { if ((fp->flags & 0x10) == 0) return -1; if (fp->flags & 4) { if (fp->ubbase != 0) { if (fp->ubbase != fp->ubuf) func_002E1B20_2E0388(fp->data, fp->ubbase); fp->ubbase = 0; } fp->flags &= ~(4 | 0x20); fp->r = 0; fp->p = fp->base; } fp->flags |= 8; } if (fp->base == 0) func_002E24D8_2E0388(fp); if (fp->flags & 1) { fp->w = 0; fp->lbfsize = -fp->size; } else fp->w = fp->flags & 2 ? 0 : fp->size; return 0; }

typedef struct R_2e24d8_002E24D8 { int pad[15]; void *cleanup; } R_2e24d8_002E24D8;
typedef struct F_2e24d8_002E24D8 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; char pad1[12]; int (*seek)(); char pad2[23]; unsigned char nbuf[1]; char pad3[8]; int blksize; char pad4[4]; R_2e24d8_002E24D8 *data; } F_2e24d8_002E24D8;
typedef struct { int dev; unsigned mode; char rest[104]; } ST_2e24d8_002E24D8;
long func_002E4E90_2E24D8(R_2e24d8_002E24D8 *, int, ST_2e24d8_002E24D8 *) __asm__("func_002E4E90"); void *_malloc_r_2E24D8(R_2e24d8_002E24D8 *, int) __asm__("_malloc_r"); void func_002DBB00_2E24D8(void) __asm__("func_002DBB00"); int func_002DD028_2E24D8() __asm__("func_002DD028"); long func_002E6050_2E24D8(int) __asm__("func_002E6050");
// MATCH func_002E24D8
void FUN_002e24d8(F_2e24d8_002E24D8 *fp) { int couldbetty; void *p; int size; ST_2e24d8_002E24D8 st; if (fp->flags & 2) { fp->base = fp->p = fp->nbuf; fp->size = 1; return; } if (fp->file < 0 || func_002E4E90_2E24D8(fp->data, fp->file, &st) < 0) { couldbetty = 0; size = 0x400; fp->flags |= 0x800; } else { couldbetty = (st.mode & 0xf000) == 0x2000; size = 0x400; if ((st.mode & 0xf000) == 0x8000 && fp->seek == func_002DD028_2E24D8) { fp->blksize = size; fp->flags |= 0x400; } else fp->flags |= 0x800; } if ((p = _malloc_r_2E24D8(fp->data, size)) == 0) { fp->flags |= 2; fp->base = fp->p = fp->nbuf; fp->size = 1; } else { fp->data->cleanup = func_002DBB00_2E24D8; fp->flags |= 0x80; fp->base = fp->p = p; fp->size = size; if (couldbetty && func_002E6050_2E24D8(fp->file)) fp->flags |= 1; } }

typedef struct B_2e2748_002E2748 { struct B_2e2748_002E2748 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2748_002E2748;
typedef struct { char pad[76]; B_2e2748_002E2748 **freelist; } R_2e2748_002E2748;
void *func_002E4DD0_2E2748(void *, int, int) __asm__("func_002E4DD0");
// MATCH func_002E2748
B_2e2748_002E2748 *FUN_002e2748(R_2e2748_002E2748 *ptr, int k) { int x; B_2e2748_002E2748 *rv; if (ptr->freelist == 0) { ptr->freelist = (B_2e2748_002E2748 **) func_002E4DD0_2E2748(ptr, 4, 16); if (ptr->freelist == 0) return 0; } if ((rv = ptr->freelist[k])) { ptr->freelist[k] = rv->next; } else { x = 1 << k; rv = (B_2e2748_002E2748 *) func_002E4DD0_2E2748(ptr, 1, sizeof(B_2e2748_002E2748) + (x - 1) * sizeof(unsigned)); if (rv == 0) return 0; rv->k = k; rv->maxwds = x; } rv->sign = rv->wds = 0; return rv; }

typedef struct B_2e2820_002E2820 { struct B_2e2820_002E2820 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2820_002E2820;
typedef struct R_2e2820 R_2e2820;
void *memcpy(void *, const void *, unsigned);
void *func_002E2748_2E2820(R_2e2820 *, int) __asm__("func_002E2748"); void func_002E27F0_2E2820(R_2e2820 *, B_2e2820_002E2820 *) __asm__("func_002E27F0");
// MATCH func_002E2820
B_2e2820_002E2820 *FUN_002e2820(R_2e2820 *ptr, B_2e2820_002E2820 *b, int m, int a) { int i, wds; unsigned *x, y; unsigned xi, z; B_2e2820_002E2820 *b1; wds = b->wds; x = b->x; i = 0; do { xi = *x; y = (xi & 0xffff) * m + a; z = (xi >> 16) * m + (y >> 16); a = (int) (z >> 16); *x++ = (z << 16) + (y & 0xffff); } while (++i < wds); if (a) { if (wds >= b->maxwds) { b1 = func_002E2748_2E2820(ptr, b->k + 1); memcpy(&b1->sign, &b->sign, b->wds * sizeof(unsigned) + 2 * sizeof(int)); func_002E27F0_2E2820(ptr, b); b = b1; } b->x[wds++] = a; b->wds = wds; } return b; }


// MATCH func_002E2B08
int FUN_002e2b08(unsigned *y) { int k; unsigned x = *y; if (x & 7) { if (x & 1) return 0; if (x & 2) { *y = x >> 1; return 1; } *y = x >> 2; return 2; } k = 0; if (!(x & 0xffff)) { k = 16; x >>= 16; } if (!(x & 0xff)) { k += 8; x >>= 8; } if (!(x & 0xf)) { k += 4; x >>= 4; } if (!(x & 0x3)) { k += 2; x >>= 2; } if (!(x & 1)) { k++; x >>= 1; if (!x) return 32; } *y = x; return k; }

typedef struct B_2e2938_002E2938 { struct B_2e2938_002E2938 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2938_002E2938;
typedef struct R_2e2938 R_2e2938;
void *func_002E2748_002E2938(R_2e2938 *, int) __asm__("func_002E2748"); B_2e2938_002E2938 *func_002E2820_2E2938(R_2e2938 *, B_2e2938_002E2938 *, int, int) __asm__("func_002E2820");
// MATCH func_002E2938
B_2e2938_002E2938 *FUN_002e2938(R_2e2938 *ptr, const char *s, int nd0, int nd, unsigned y9) { B_2e2938_002E2938 *b; int i, k; int x, y; x = (nd + 8) / 9; for (k = 0, y = 1; x > y; y <<= 1, k++) ; b = func_002E2748_002E2938(ptr, k); b->x[0] = y9; b->wds = 1; i = 9; if (9 < nd0) { s += 9; do b = func_002E2820_2E2938(ptr, b, 10, *s++ - '0'); while (++i < nd0); s++; } else s += 10; for (; i < nd; i++) b = func_002E2820_2E2938(ptr, b, 10, *s++ - '0'); return b; }

typedef struct B_2e2c00_002E2C00 { struct B_2e2c00_002E2C00 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2c00_002E2C00;
typedef struct R_2e2c00 R_2e2c00;
void *func_002E2748_2E2C00(void *, int) __asm__("func_002E2748");
// MATCH func_002E2C00
B_2e2c00_002E2C00 *FUN_002e2c00(R_2e2c00 *ptr, B_2e2c00_002E2C00 *a, B_2e2c00_002E2C00 *b) { B_2e2c00_002E2C00 *c; int k, wa, wb, wc; unsigned carry, y, z; unsigned *x, *xa, *xae, *xb, *xbe, *xc, *xc0; unsigned z2; if (a->wds < b->wds) { c = a; a = b; b = c; } k = a->k; wa = a->wds; wb = b->wds; wc = wa + wb; if (wc > a->maxwds) k++; c = func_002E2748_2E2C00(ptr, k); for (x = c->x, xa = x + wc; x < xa; x++) *x = 0; xa = a->x; xae = xa + wa; xb = b->x; xbe = xb + wb; xc0 = c->x; for (; xb < xbe; xb++, xc0++) { if ((y = *xb & 0xffff)) { x = xa; xc = xc0; carry = 0; do { z = (*x & 0xffff) * y + (*xc & 0xffff) + carry; carry = z >> 16; z2 = (*x++ >> 16) * y + (*xc >> 16) + carry; carry = z2 >> 16; ((unsigned short *)xc)[1] = (unsigned short)z2; ((unsigned short *)xc)[0] = (unsigned short)z; xc++; } while (x < xae); *xc = carry; } if ((y = *xb >> 16)) { x = xa; xc = xc0; carry = 0; z2 = *xc; do { z = (*x & 0xffff) * y + (*xc >> 16) + carry; carry = z >> 16; ((unsigned short *)xc)[1] = (unsigned short)z; ((unsigned short *)xc)[0] = (unsigned short)z2; xc++; z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry; carry = z2 >> 16; } while (x < xae); *xc = z2; } } for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc) ; c->wds = wc; return c; }

typedef struct B_2e2f30_002E2F30 { struct B_2e2f30_002E2F30 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2f30_002E2F30;
typedef struct R_2e2f30 R_2e2f30;
void *func_002E2748_002E2F30(R_2e2f30 *, int) __asm__("func_002E2748"); void func_002E27F0_2E2F30(R_2e2f30 *, B_2e2f30_002E2F30 *) __asm__("func_002E27F0");
// MATCH func_002E2F30
B_2e2f30_002E2F30 *FUN_002e2f30(R_2e2f30 *ptr, B_2e2f30_002E2F30 *b, int k) { int i, k1, n, n1; B_2e2f30_002E2F30 *b1; unsigned *x, *x1, *xe, z; n = k >> 5; k1 = b->k; n1 = n + b->wds + 1; for (i = b->maxwds; n1 > i; i <<= 1) k1++; b1 = func_002E2748_002E2F30(ptr, k1); x1 = b1->x; for (i = 0; i < n; i++) *x1++ = 0; x = b->x; xe = x + b->wds; if (k &= 0x1f) { k1 = 32 - k; z = 0; do { *x1++ = *x << k | z; z = *x++ >> k1; } while (x < xe); if ((*x1 = z)) ++n1; } else do *x1++ = *x++; while (x < xe); b1->wds = n1 - 1; func_002E27F0_2E2F30(ptr, b); return b1; }

typedef struct B_2e2e30_002E2E30 { struct B_2e2e30_002E2E30 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e2e30_002E2E30;
typedef struct R_2e2e30_002E2E30 { char pad[72]; B_2e2e30_002E2E30 *p5s; } R_2e2e30_002E2E30;
extern int D_0049F290[];
void *func_002E2820(R_2e2e30_002E2E30 *, B_2e2e30_002E2E30 *, int, int); B_2e2e30_002E2E30 *func_002E2BC8(R_2e2e30_002E2E30 *, int); B_2e2e30_002E2E30 *func_002E2C00(R_2e2e30_002E2E30 *, B_2e2e30_002E2E30 *, B_2e2e30_002E2E30 *); void func_002E27F0(R_2e2e30_002E2E30 *, B_2e2e30_002E2E30 *);
// MATCH func_002E2E30
B_2e2e30_002E2E30 *FUN_002e2e30(R_2e2e30_002E2E30 *ptr, B_2e2e30_002E2E30 *b, int k) { B_2e2e30_002E2E30 *b1, *p5, *p51; int i; if ((i = k & 3)) b = func_002E2820(ptr, b, D_0049F290[i - 1], 0); if (!(k >>= 2)) return b; if (!(p5 = ptr->p5s)) { p5 = ptr->p5s = func_002E2BC8(ptr, 625); p5->next = 0; } for (;;) { if (k & 1) { b1 = func_002E2C00(ptr, b, p5); func_002E27F0(ptr, b); b = b1; } if (!(k >>= 1)) break; if (!(p51 = p5->next)) { p51 = p5->next = func_002E2C00(ptr, p5, p5); p51->next = 0; } p5 = p51; } return b; }

typedef struct B_2e3110_002E3110 { struct B_2e3110_002E3110 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e3110_002E3110;
typedef struct R_2e3110 R_2e3110;
void *func_002E2748_2E3110(R_2e3110 *, int) __asm__("func_002E2748"); int func_002E30A8_2E3110(B_2e3110_002E3110 *, B_2e3110_002E3110 *) __asm__("func_002E30A8");
// MATCH func_002E3110
B_2e3110_002E3110 *FUN_002e3110(R_2e3110 *ptr, B_2e3110_002E3110 *a, B_2e3110_002E3110 *b) { B_2e3110_002E3110 *c; int i; int wa, wb; int borrow, y; unsigned *xa, *xae, *xb, *xbe, *xc; int z; i = func_002E30A8_2E3110(a, b); if (!i) { c = func_002E2748_2E3110(ptr, 0); c->wds = 1; c->x[0] = 0; return c; } if (i < 0) { c = a; a = b; b = c; i = 1; } else i = 0; c = func_002E2748_2E3110(ptr, a->k); c->sign = i; wa = a->wds; xa = a->x; xae = xa + wa; wb = b->wds; xb = b->x; xbe = xb + wb; xc = c->x; borrow = 0; do { y = (*xa & 0xffff) - (*xb & 0xffff) + borrow; borrow = y >> 16; z = (*xa++ >> 16) - (*xb++ >> 16) + borrow; borrow = z >> 16; ((unsigned short *)xc)[1] = (unsigned short)z; ((unsigned short *)xc)[0] = (unsigned short)y; xc++; } while (xb < xbe); while (xa < xae) { y = (*xa & 0xffff) + borrow; borrow = y >> 16; z = (*xa++ >> 16) + borrow; borrow = z >> 16; ((unsigned short *)xc)[1] = (unsigned short)z; ((unsigned short *)xc)[0] = (unsigned short)y; xc++; } while (!*--xc) wa--; c->wds = wa; return c; }

typedef struct B_2e3638_002E3638 { struct B_2e3638_002E3638 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2e3638_002E3638;
typedef union { long l; struct { int lo; int hi; } w; } DW_2e3638;
long func_002E3338_2E3638(B_2e3638_002E3638 *, int *) __asm__("func_002E3338"); long func_002D7BC8_2E3638(long, long) __asm__("func_002D7BC8");
// MATCH func_002E3638
long FUN_002e3638(B_2e3638_002E3638 *a, B_2e3638_002E3638 *b) { DW_2e3638 da, db; int k, ka, kb; da.l = func_002E3338_2E3638(a, &ka); db.l = func_002E3338_2E3638(b, &kb); k = ka - kb + 32 * (a->wds - b->wds); if (k > 0) da.w.hi += k * 0x100000; else { k = -k; db.w.hi += k * 0x100000; } return func_002D7BC8_2E3638(da.l, db.l); }

typedef struct mc { unsigned prev_size; unsigned size; struct mc *fd; struct mc *bk; } *mp;
extern mp D_004293F8_2E1B20[] __asm__("D_004293F8");
extern unsigned long D_00429800_2E1B20[] __asm__("D_00429800");
extern int D_00429808_2E1B20[] __asm__("D_00429808");
#define bin_at(i) ((mp)((char *)&D_004293F8_2E1B20[2*(i)+2] - 8))
#define binblocks (bin_at(0)->size)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3):\
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): 126)
#define idx2binblock(ix) (1L << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define chunksize(p) ((p)->size & ~3)
#define chunk_at_offset(p, s) ((mp)((char *)(p) + (s)))
#define inuse_bit_at_offset(p, s) (((mp)((char *)(p) + (s)))->size & 1)
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define frontlink(P, S, IDX, BK, FD) { \
  if (S < 512) { IDX = smallbin_index(S); mark_binblock(IDX); BK = bin_at(IDX); FD = BK->fd; P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } \
  else { IDX = bin_index(S); BK = bin_at(IDX); FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else { while (FD != BK && S < chunksize(FD)) FD = FD->fd; BK = FD->bk; } \
    P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } }
void func_002DC8C8_2E1B20(void) __asm__("func_002DC8C8"); void func_002DC8D0_2E1B20(void *) __asm__("func_002DC8D0");
int func_002E1E40_2E1B20(void *, int) __asm__("func_002E1E40");
// MATCH func_002E1B20
void FUN_002e1b20(void *reent, void *mem) { mp p; unsigned hd; unsigned sz; int idx; mp next; unsigned nextsz; unsigned prevsz; mp bck; mp fwd; int islr; if (mem == 0) return; func_002DC8C8_2E1B20(); p = (mp)((char *)mem - 8); hd = p->size; sz = hd & ~1; next = chunk_at_offset(p, sz); nextsz = chunksize(next); if (next == top) { sz += nextsz; if (!(hd & 1)) { prevsz = p->prev_size; p = chunk_at_offset(p, -prevsz); sz += prevsz; unlink(p, bck, fwd); } p->size = sz | 1; top = p; if ((unsigned long)sz >= D_00429800_2E1B20[0]) func_002E1E40_2E1B20(reent, D_00429808_2E1B20[0]); func_002DC8D0_2E1B20(reent); return; } next->size = nextsz; islr = 0; if (!(hd & 1)) { prevsz = p->prev_size; p = chunk_at_offset(p, -prevsz); sz += prevsz; if (p->fd == last_remainder) islr = 1; else unlink(p, bck, fwd); } if (!inuse_bit_at_offset(next, nextsz)) { sz += nextsz; if (!islr && next->fd == last_remainder) { islr = 1; link_last_remainder(p); } else unlink(next, bck, fwd); } p->size = sz | 1; *(unsigned *)((char *)p + sz) = sz; if (!islr) frontlink(p, sz, idx, bck, fwd); func_002DC8D0_2E1B20(reent); }

void func_002DC8C8_2E1E40(void) __asm__("func_002DC8C8"); void func_002DC8D0_2E1E40(void *) __asm__("func_002DC8D0");
void *func_002DC9A8_2E1E40(void *, int) __asm__("func_002DC9A8");
unsigned long func_002EFBC8_2E1E40(unsigned long, unsigned long) __asm__("func_002EFBC8");
long func_002D73E8_2E1E40(unsigned long, unsigned long) __asm__("func_002D73E8");
extern int D_00429810_2E1E40[] __asm__("D_00429810");
extern int D_00429828_2E1E40[] __asm__("D_00429828");
// MATCH func_002E1E40
int FUN_002e1e40(void *reent, unsigned pad) { long top_size; long extra; char *current_brk; char *new_brk; unsigned long pagesz = 4096; func_002DC8C8_2E1E40(); top_size = chunksize(top); extra = func_002D73E8_2E1E40(func_002EFBC8_2E1E40(top_size - pad - 16 + (pagesz - 1), pagesz) - 1, pagesz); if (extra < (long)pagesz) { func_002DC8D0_2E1E40(reent); return 0; } else { current_brk = func_002DC9A8_2E1E40(reent, 0); if (current_brk != (char *)top + top_size) { func_002DC8D0_2E1E40(reent); return 0; } else { new_brk = func_002DC9A8_2E1E40(reent, -extra); if (new_brk == (char *)-1) { current_brk = func_002DC9A8_2E1E40(reent, 0); top_size = current_brk - (char *)top; if (top_size >= 16) { D_00429828_2E1E40[0] = current_brk - (char *)D_00429810_2E1E40[0]; top->size = top_size | 1; } func_002DC8D0_2E1E40(reent); return 0; } else { top->size = (top_size - extra) | 1; D_00429828_2E1E40[0] -= extra; func_002DC8D0_2E1E40(reent); return 1; } } } }

typedef struct { int pad[14]; int didinit; } R_t_002E1FB0;
typedef struct F_t_002E1FB0 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; void *cookie; void *rd; int (*wr)(void *, const char *, int); char pad[44]; R_t_002E1FB0 *data; } F_t_002E1FB0;
typedef struct { const char *base; unsigned len; } IOV_002E1FB0;
typedef struct { IOV_002E1FB0 *iov; int iovcnt; int resid; } UIO_002E1FB0;
long func_002E0388_2E1FB0(F_t_002E1FB0 *) __asm__("func_002E0388");
long func_002E18F8_2E1FB0(F_t_002E1FB0 *) __asm__("func_002E18F8");
void *func_002E2664_2E1FB0(const void *, int, unsigned) __asm__("func_002E2664");
void *memmove(void *, const void *, unsigned);
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define COPY(n) (void) memmove((void *) fp->p, (void *) p, (unsigned)(n))
#define GETIOV(extra_work) while (len == 0) { extra_work; p = iov->base; len = iov->len; iov++; }
// MATCH func_002E1FB0
int FUN_002e1fb0(F_t_002E1FB0 *fp, UIO_002E1FB0 *uio) { unsigned len; const char *p; IOV_002E1FB0 *iov; int w, s; char *nl; int nlknown, nldist; if ((len = uio->resid) == 0) return 0; if ((fp->flags & 8) == 0 || fp->base == 0) { if (func_002E0388_2E1FB0(fp)) return -1; } iov = uio->iov; len = 0; if (fp->flags & 2) { do { GETIOV(;); w = fp->wr(fp->cookie, p, MIN(len, 1024)); if (w <= 0) goto err; p += w; len -= w; } while ((uio->resid -= w) != 0); } else if ((fp->flags & 1) == 0) { do { GETIOV(;); w = fp->w; if (fp->flags & 0x200) { if (len < w) w = len; COPY(w); fp->w -= w; fp->p += w; w = len; } else if (fp->p > fp->base && len > w) { COPY(w); fp->p += w; if (func_002E18F8_2E1FB0(fp)) goto err; } else if (len >= (w = fp->size)) { w = fp->wr(fp->cookie, p, w); if (w <= 0) goto err; } else { w = len; COPY(w); fp->w -= w; fp->p += w; } p += w; len -= w; } while ((uio->resid -= w) != 0); } else { nlknown = 0; do { GETIOV(nlknown = 0); if (!nlknown) { nl = func_002E2664_2E1FB0(p, '\n', len); nldist = nl ? nl + 1 - p : len + 1; nlknown = 1; } s = MIN(len, nldist); w = fp->w + fp->size; if (fp->p > fp->base && s > w) { COPY(w); fp->p += w; if (func_002E18F8_2E1FB0(fp)) goto err; } else if (s >= (w = fp->size)) { w = fp->wr(fp->cookie, p, w); if (w <= 0) goto err; } else { w = s; COPY(w); fp->w -= w; fp->p += w; } if ((nldist -= w) == 0) { if (func_002E18F8_2E1FB0(fp)) goto err; nlknown = 0; } p += w; len -= w; } while ((uio->resid -= w) != 0); } return 0; err: fp->flags |= 0x40; return -1; }

extern mp D_004293F8_2DBED8[] __asm__("D_004293F8");
extern unsigned long D_00429800_2DBED8[] __asm__("D_00429800");
extern int D_00429808_2DBED8[] __asm__("D_00429808");
#define bin_at(i) ((mp)((char *)&D_004293F8_2DBED8[2*(i)+2] - 8))
#define binblocks (bin_at(0)->size)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3):\
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): 126)
#define idx2binblock(ix) (1L << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define chunksize(p) ((p)->size & ~3)
#define RSZ(a, b) ((a) < (b) ? -(long)((b) - (a)) : (long)((a) - (b)))
#define last(b) ((b)->bk)
#define first(b) ((b)->fd)
#define next_bin(b) ((mp)((char *)(b) + 8))
#define prev_bin(b) ((mp)((char *)(b) - 8))
#define set_inuse_bit_at_offset(p, s) (((mp)((char *)(p) + (s)))->size |= 1)
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define chunk_at_offset(p, s) ((mp)((char *)(p) + (s)))
#define inuse_bit_at_offset(p, s) (((mp)((char *)(p) + (s)))->size & 1)
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define frontlink(P, S, IDX, BK, FD) { \
  if (S < 512) { IDX = smallbin_index(S); mark_binblock(IDX); BK = bin_at(IDX); FD = BK->fd; P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } \
  else { IDX = bin_index(S); BK = bin_at(IDX); FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else { while (FD != BK && S < chunksize(FD)) FD = FD->fd; BK = FD->bk; } \
    P->bk = BK; P->fd = FD; FD->bk = BK->fd = P; } }
void func_002DC8C8_2DBED8(void *) __asm__("func_002DC8C8"); void func_002DC8D0_2DBED8(void *) __asm__("func_002DC8D0");
void func_002DBC80_2DBED8(void *, unsigned) __asm__("func_002DBC80");
// MATCH func_002DBED8
void *_malloc_r(void *reent, unsigned bytes) { mp victim; unsigned victim_size; int idx; mp bin; mp remainder; long remainder_size; int remainder_index; unsigned long block; int startidx; mp fwd; mp bck; mp q; unsigned nb; nb = (long)(bytes + 19) < 31 ? 16 : ((bytes + 19) & ~15); func_002DC8C8_2DBED8(reent); if (nb < 504) { idx = smallbin_index(nb); q = bin_at(idx); victim = last(q); if (victim != q) { victim_size = chunksize(victim); unlink(victim, bck, fwd); set_inuse_bit_at_offset(victim, victim_size); func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } idx += 2; } else { idx = bin_index(nb); bin = bin_at(idx); for (victim = last(bin); victim != bin; victim = victim->bk) { victim_size = chunksize(victim); remainder_size = RSZ(victim_size, nb); if (remainder_size >= 16) { --idx; break; } else if (remainder_size >= 0) { unlink(victim, bck, fwd); set_inuse_bit_at_offset(victim, victim_size); func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } } ++idx; } if ((victim = last_remainder->fd) != last_remainder) { victim_size = chunksize(victim); remainder_size = RSZ(victim_size, nb); if (remainder_size >= 16) { remainder = chunk_at_offset(victim, nb); victim->size = nb | 1; link_last_remainder(remainder); remainder->size = remainder_size | 1; *(unsigned *)((char *)remainder + remainder_size) = remainder_size; func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } clear_last_remainder; if (remainder_size >= 0) { set_inuse_bit_at_offset(victim, victim_size); func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } frontlink(victim, victim_size, remainder_index, bck, fwd); } if ((block = idx2binblock(idx)) <= binblocks) { if ((block & binblocks) == 0) { idx = (idx & ~3) + 4; block <<= 1; while ((block & binblocks) == 0) { idx += 4; block <<= 1; } } for (;;) { startidx = idx; q = bin = bin_at(idx); do { for (victim = last(bin); victim != bin; victim = victim->bk) { victim_size = chunksize(victim); remainder_size = RSZ(victim_size, nb); if (remainder_size >= 16) { remainder = chunk_at_offset(victim, nb); victim->size = nb | 1; unlink(victim, bck, fwd); link_last_remainder(remainder); remainder->size = remainder_size | 1; *(unsigned *)((char *)remainder + remainder_size) = remainder_size; func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } else if (remainder_size >= 0) { set_inuse_bit_at_offset(victim, victim_size); unlink(victim, bck, fwd); func_002DC8D0_2DBED8(reent); return (char *)victim + 8; } } bin = next_bin(bin); if (idx < 63) { bin = next_bin(bin); ++idx; } } while ((++idx & 3) != 0); do { if ((startidx & 3) == 0) { binblocks &= ~block; break; } --startidx; q = prev_bin(q); } while (first(q) == q); if ((block <<= 1) <= binblocks && (block != 0)) { while ((block & binblocks) == 0) { idx += 4; block <<= 1; } } else break; } } remainder_size = RSZ(chunksize(top), nb); if (chunksize(top) < nb || remainder_size < 16) { func_002DBC80_2DBED8(reent, nb); remainder_size = RSZ(chunksize(top), nb); if (chunksize(top) < nb || remainder_size < 16) { func_002DC8D0_2DBED8(reent); return 0; } } victim = top; victim->size = nb | 1; top = chunk_at_offset(victim, nb); top->size = remainder_size | 1; func_002DC8D0_2DBED8(reent); return (char *)victim + 8; }

int **func_002D63A8_2D8438(void) __asm__("func_002D63A8"); void func_002D8148_2D8438(void) __asm__("func_002D8148") __attribute__((noreturn));
// MATCH func_002D8438
void FUN_002d8438(void) { int *p = *func_002D63A8_2D8438(); if (p == 0) func_002D8148_2D8438(); p[5] = 0; }

int func_002DABA8_2D8270(int, int, int) __asm__("func_002DABA8");
// MATCH func_002D8270
int FUN_002d8270(int *o, int (*fn)(void), short *t) { int r; if (t != 0 && t[2] != 4) return 0; if (fn == (int (*)(void))-1) return o[2]; r = func_002DABA8_2D8270(fn(), o[3], o[10]); if (r != 0) o[2] = r; return r; }

typedef struct O_002D82E0 { int f0; short s4, s6; int f8, f12, f16, f20, f24, pad28; long long f32; int f40; int pad44; } O_002D82E0;
void *func_002D8228_2D82E0(int) __asm__("func_002D8228"); int *func_002D63A8_2D82E0(void) __asm__("func_002D63A8"); int func_002D8270_2D82E0(void) __asm__("func_002D8270");
// MATCH func_002D82E0
void FUN_002d82e0(int a, int b, int c) { O_002D82E0 *p; int *q; p = func_002D8228_2D82E0(48); p->f12 = b; p->f16 = c; p->f8 = a; p->f40 = a; p->f32 = 0; p->f20 = 0; p->f0 = (int)func_002D8270_2D82E0; p->s4 = 4; p->s6 = 1; q = func_002D63A8_2D82E0(); p->f24 = *q; *q = (int)p; }

extern int D_00631AF8_2DA0C8[] __asm__("D_00631AF8"); void func_002DB900_2DA0C8(void) __asm__("func_002DB900"); void func_002DBC70_2DA0C8(int) __asm__("func_002DBC70");
// MATCH func_002DA0C8
int *FUN_002da0c8(int a) { int *pp = D_00631AF8_2DA0C8; int *n; while (*pp != 0) { n = (int *)*pp; if (n[2] == a) { int t = n[0]; *pp = n[5]; if (t != 0) func_002DBC70_2DA0C8(n[3]); return n; } pp = &n[5]; } func_002DB900_2DA0C8(); }


// MATCH func_002D98C8
void FUN_002d98c8(int *a, int *out, unsigned *pmin, unsigned *pmax) { unsigned mn = *pmin, mx = *pmax; while (*a != 0) { if (a[1] != 0 && a[2] != 0) { ((int **)out[0])[out[1]++] = a; if ((unsigned)a[2] < mn) mn = a[2]; if (mx < (unsigned)a[2] + a[3]) mx = a[2] + a[3]; } a = (int *)((int)a + *a + 4); } *pmin = mn; *pmax = mx; }

typedef struct { char p[16]; short adj; short pad; long (*fn)(int, long, long, long, long, long); } VT_a5b8_002DA5B8;
typedef struct { int pad[2]; int *obj; } O_a5b8_002DA5B8;
long func_002DA4E0_2DA5B8() __asm__("func_002DA4E0");
// MATCH func_002DA5B8
long FUN_002da5b8(O_a5b8_002DA5B8 *o, long a, long b, long c, long d, long e) { int *obj; VT_a5b8_002DA5B8 *vt; if (func_002DA4E0_2DA5B8(o, a) != 0) return c; obj = o->obj; vt = *(VT_a5b8_002DA5B8 **)((char *)obj + 4); return vt->fn((int)obj + vt->adj, a, b, c, d, e); }

typedef struct { short adj; short pad; long (*fn)(int, long, long, long, long, long); } E_b188_002DB188;
// MATCH func_002DB188
void FUN_002db188(int (*f1)(void), long (*f2)(void), long c, long d, long (*f5)(void), long e) { int o; E_b188_002DB188 *t; long x, y; o = f1(); t = (E_b188_002DB188 *)(*(int *)(o + 4) + 16); o = o + t->adj; x = f2(); y = f5(); t->fn(o, x, c, d, y, e); }

typedef struct { int v; } __attribute__((packed)) UI_9b78;
extern char D_0049E6D0_2D9B78[] __asm__("D_0049E6D0"), D_0049E6D8_2D9B78[] __asm__("D_0049E6D8");
int strcmp(char *, char *); unsigned strlen(char *); int func_002D9480_2D9B78(char *, int *) __asm__("func_002D9480"); unsigned char *func_002D94C8_2D9B78(int, int *) __asm__("func_002D94C8");
// MATCH func_002D9B78
unsigned char *FUN_002d9b78(int p1, int *o) { char *s, *q; unsigned len; unsigned char *pb; int stk[4]; s = (char *)((p1 - *(int *)(p1 + 4)) + 13); o[0] = (int)s; if (strcmp(s, D_0049E6D0_2D9B78) == 0 || strcmp((char *)o[0], D_0049E6D8_2D9B78) == 0 || *(char *)o[0] == 'z') { len = strlen((char *)o[0]); q = (char *)o[0]; pb = (unsigned char *)(q + len + 1); if (strcmp(q, D_0049E6D8_2D9B78) == 0) { o[1] = ((UI_9b78 *)pb)->v; pb = (unsigned char *)(q + len + 5); } else o[1] = 0; pb = func_002D94C8_2D9B78(func_002D9480_2D9B78((char *)pb, o + 2), o + 3); o[4] = *pb; pb++; if (*(char *)o[0] == 'z') { int x = func_002D9480_2D9B78((char *)pb, stk); pb = (unsigned char *)(x + stk[0]); } return pb; } return 0; }

typedef void (*sigf)(int);
typedef struct { int err; char pad[464]; sigf *sf; } R_dcbf8_002DCBF8;
int func_002DCA08_2DCBF8(void *) __asm__("func_002DCA08");
// MATCH func_002DCBF8
int FUN_002dcbf8(R_dcbf8_002DCBF8 *ptr, int sig) { sigf func; if (sig < 0 || sig >= 32) return -1; if (ptr->sf == 0) { if (func_002DCA08_2DCBF8(ptr) != 0) return -1; } func = ptr->sf[sig]; switch ((int)func) { case 0: return 1; case -1: return 2; case 1: return 3; default: { sigf f2 = ptr->sf[sig]; ptr->sf[sig] = (sigf)0; f2(sig); return 0; } } }

typedef struct { int err; char pad[464]; sigf *sf; } R_dcb08_002DCB08;
int func_002DCA08_002DCB08(R_dcb08_002DCB08 *) __asm__("func_002DCA08"); int func_002DCDB8_2DCB08(R_dcb08_002DCB08 *) __asm__("func_002DCDB8"); int func_002DCD58_2DCB08(R_dcb08_002DCB08 *, int, int) __asm__("func_002DCD58");
// MATCH func_002DCB08
int FUN_002dcb08(R_dcb08_002DCB08 *ptr, int sig) { sigf func; int r = 0; if (sig < 0 || sig >= 32) { ptr->err = 22; return -1; } if (ptr->sf == 0) { if (func_002DCA08_002DCB08(ptr) != 0) return -1; } func = ptr->sf[sig]; switch ((int)func) { case 0: return func_002DCD58_2DCB08(ptr, func_002DCDB8_2DCB08(ptr), sig); case 1: break; case -1: ptr->err = 22; r = 1; break; default: { sigf f2 = ptr->sf[sig]; ptr->sf[sig] = (sigf)0; f2(sig); } break; } return r; }

typedef struct { char *p; int r; int w; short flags; short file; char *base; int size; int lbfsize; int cookie; int (*rd)(); char pad1[12]; int ubbase; char pad2[16]; int lbbase; char pad3[12]; void *data; } FS_dceb8_002DCEB8;
extern void *D_004293F4_2DCEB8[] __asm__("D_004293F4"); int func_002DCEB0_2DCEB8() __asm__("func_002DCEB0"); unsigned strlen(char *); int func_002DF6E8_2DCEB8(FS_dceb8_002DCEB8 *, char *, va_list) __asm__("func_002DF6E8");
// MATCH func_002DCEB8
int FUN_002dceb8(char *s, char *fmt, ...) { FS_dceb8_002DCEB8 f; f.flags = 4; f.p = s; f.base = s; f.size = f.r = strlen(s); f.rd = func_002DCEB0_2DCEB8; f.ubbase = 0; f.lbbase = 0; f.data = D_004293F4_2DCEB8[0]; return func_002DF6E8_2DCEB8(&f, fmt, (va_list)__builtin_next_arg(fmt) - 48); }

typedef struct { int pad[14]; int didinit; } R_ddec8_002DDEC8;
typedef struct { char p[84]; R_ddec8_002DDEC8 *data; } F_ddec8_002DDEC8;
extern R_ddec8_002DDEC8 *D_004293F4_2DDEC8[] __asm__("D_004293F4"); void func_002DBB20_2DDEC8(R_ddec8_002DDEC8 *) __asm__("func_002DBB20"); int func_002DDF40_2DDEC8(R_ddec8_002DDEC8 *, F_ddec8_002DDEC8 *, char *, va_list) __asm__("func_002DDF40");
// MATCH func_002DDEC8
int vfprintf(F_ddec8_002DDEC8 *fp, char *fmt, va_list ap) { do { if (fp->data == 0) fp->data = D_004293F4_2DDEC8[0]; if (fp->data->didinit == 0) func_002DBB20_2DDEC8(fp->data); } while (0); return func_002DDF40_2DDEC8(fp->data, fp, fmt, ap); }

typedef struct { unsigned char *p; int pad0[11]; unsigned char *ubbase; int ubsize; int pad1[2]; unsigned char ubuf[3]; char pad2[17]; void *data; } F_4b58_002E4B58;
void *_malloc_r_2E4B58(void *, int) __asm__("_malloc_r"); void *func_002E4EF0_2E4B58(void *, void *, int) __asm__("func_002E4EF0"); void *memcpy(void *, const void *, unsigned);
// MATCH func_002E4B58
int FUN_002e4b58(F_4b58_002E4B58 *fp) { int i; unsigned char *p; if (fp->ubbase == fp->ubuf) { if ((p = (unsigned char *)_malloc_r_2E4B58(fp->data, 1024)) == 0) return -1; fp->ubbase = p; fp->ubsize = 1024; p += 1024 - 3; for (i = 2; i >= 0; i--) p[i] = fp->ubuf[i]; fp->p = p; return 0; } i = fp->ubsize; p = (unsigned char *)func_002E4EF0_2E4B58(fp->data, fp->ubbase, i << 1); if (p == 0) return -1; (void)memcpy(p + i, p, i); fp->p = p + i; fp->ubbase = p; fp->ubsize = i << 1; return 0; }

typedef struct B_002E3338_2E3338 { struct B_002E3338_2E3338 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_002E3338_2E3338;
typedef union { long l; struct { unsigned lo; unsigned hi; } w_2E3338; } DW_2E3338;
int func_002E2A80_2E3338(unsigned) __asm__("func_002E2A80");
// MATCH func_002E3338
long FUN_002e3338(B_002E3338_2E3338 *a, int *e) { unsigned *xa, *xa0, w_2E3338, y, z; int k; DW_2E3338 d; xa0 = a->x; xa = xa0 + a->wds; y = *--xa; k = func_002E2A80_2E3338(y); *e = 32 - k; if (k < 11) { d.w_2E3338.hi = 0x3ff00000 | y >> (11 - k); w_2E3338 = xa > xa0 ? *--xa : 0; d.w_2E3338.lo = y << (21 + k) | w_2E3338 >> (11 - k); goto ret_d; } z = xa > xa0 ? *--xa : 0; if ((k -= 11)) { d.w_2E3338.hi = 0x3ff00000 | y << k | z >> (32 - k); y = xa > xa0 ? *--xa : 0; d.w_2E3338.lo = z << k | y >> (32 - k); } else { d.w_2E3338.hi = 0x3ff00000 | y; d.w_2E3338.lo = z; } ret_d: return d.l; }

typedef struct B_002E34B8_2E34B8 { struct B_002E34B8_2E34B8 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_002E34B8_2E34B8;
typedef union { long l; struct { unsigned lo; unsigned hi; } w_2E34B8; } DW_2E34B8;
int func_002E2A80_2E34B8(unsigned) __asm__("func_002E2A80"); int func_002E2B08_2E34B8(unsigned *) __asm__("func_002E2B08"); B_002E34B8_2E34B8 *func_002E2748_2E34B8(void *, int) __asm__("func_002E2748");
// MATCH func_002E34B8
B_002E34B8_2E34B8 *FUN_002e34b8(void *ptr, long dd, int *e, int *bits) { B_002E34B8_2E34B8 *b; int de, i, k; unsigned *x, y, z; DW_2E34B8 d; d.l = dd; b = func_002E2748_2E34B8(ptr, 1); x = b->x; z = d.w_2E34B8.hi & 0xfffff; d.w_2E34B8.hi &= 0x7fffffff; if ((de = (int)(d.w_2E34B8.hi >> 20))) z |= 0x100000; if ((y = d.w_2E34B8.lo)) { if ((k = func_002E2B08_2E34B8(&y))) { x[0] = y | z << (32 - k); z >>= k; } else x[0] = y; i = b->wds = (x[1] = z) ? 2 : 1; } else { k = func_002E2B08_2E34B8(&z); x[0] = z; i = b->wds = 1; k += 32; } if (de) { *e = de - 1075 + k; *bits = 53 - k; } else { *e = de - 1074 + k; *bits = 32 * i - func_002E2A80_2E34B8(x[i - 1]); } return b; }

typedef union { long l; struct { unsigned lo; unsigned hi; } w_2E32A0; } DW_2E32A0;
// MATCH func_002E32A0
long FUN_002e32a0(long dd) { DW_2E32A0 x, a; int L; x.l = dd; L = (x.w_2E32A0.hi & 0x7ff00000) - 0x03400000; if (L > 0) { a.w_2E32A0.hi = L; a.w_2E32A0.lo = 0; } else { L = -L >> 20; if (L < 20) { a.w_2E32A0.hi = 0x80000 >> L; a.w_2E32A0.lo = 0; } else { a.w_2E32A0.hi = 0; L -= 20; a.w_2E32A0.lo = L >= 31 ? 1 : 1 << (31 - L); } } return a.l; }

typedef struct { int pad[14]; int didinit; } R_t_002E37E8_2E37E8;
typedef struct F_t_002E37E8_2E37E8 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; void *cookie; int (*rd)(void *, unsigned char *, int); char pad1[12]; unsigned char *ubbase; int ubsize; unsigned char *up; int ur; unsigned char ubuf[4]; char pad2[16]; R_t_002E37E8_2E37E8 *data; } F_t_002E37E8_2E37E8;
extern R_t_002E37E8_2E37E8 *D_004293F4_2E37E8[] __asm__("D_004293F4");
void func_002DBB20_2E37E8(R_t_002E37E8_2E37E8 *) __asm__("func_002DBB20"); long func_002E18F8_2E37E8(F_t_002E37E8_2E37E8 *) __asm__("func_002E18F8"); void func_002E1B20_2E37E8(R_t_002E37E8_2E37E8 *, void *) __asm__("func_002E1B20"); void func_002E24D8_2E37E8(F_t_002E37E8_2E37E8 *) __asm__("func_002E24D8"); void func_002DBBB0_2E37E8(R_t_002E37E8_2E37E8 *, void *) __asm__("func_002DBBB0"); void func_002E37C8_2E37E8(void) __asm__("func_002E37C8");
// MATCH func_002E37E8
int FUN_002e37e8(F_t_002E37E8_2E37E8 *fp) { do { if (fp->data == 0) fp->data = D_004293F4_2E37E8[0]; if (fp->data->didinit == 0) func_002DBB20_2E37E8(fp->data); } while (0); fp->r = 0; if (fp->flags & 0x20) return -1; if ((fp->flags & 4) == 0) { if ((fp->flags & 0x10) == 0) return -1; if (fp->flags & 8) { if (func_002E18F8_2E37E8(fp)) return -1; fp->flags &= ~8; fp->w = 0; fp->lbfsize = 0; } fp->flags |= 4; } else { if (fp->ubbase != 0) { if (fp->ubbase != fp->ubuf) func_002E1B20_2E37E8(fp->data, fp->ubbase); fp->ubbase = 0; if ((fp->r = fp->ur) != 0) { fp->p = fp->up; return 0; } } } if (fp->base == 0) func_002E24D8_2E37E8(fp); if (fp->flags & 3) func_002DBBB0_2E37E8(fp->data, (void *)func_002E37C8_2E37E8); fp->p = fp->base; fp->r = (*fp->rd)(fp->cookie, fp->p, fp->size); fp->flags &= ~0x2000; if (fp->r <= 0) { if (fp->r == 0) fp->flags |= 0x20; else { fp->r = 0; fp->flags |= 0x40; } return -1; } return 0; }

typedef struct { int pad[14]; int didinit; } R_t_002E4C48_2E4C48;
typedef struct F_t_002E4C48_2E4C48 { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; int size; int lbfsize; char pad1[20]; unsigned char *ubbase; int ubsize; unsigned char *up; int ur; unsigned char ubuf[3]; char pad2[17]; R_t_002E4C48_2E4C48 *data; } F_t_002E4C48_2E4C48;
extern R_t_002E4C48_2E4C48 *D_004293F4_002E4C48[] __asm__("D_004293F4");
void func_002DBB20_002E4C48(R_t_002E4C48_2E4C48 *) __asm__("func_002DBB20"); long func_002E18F8_002E4C48(F_t_002E4C48_2E4C48 *) __asm__("func_002E18F8"); long func_002E4B58_2E4C48(F_t_002E4C48_2E4C48 *) __asm__("func_002E4B58");
// MATCH func_002E4C48
int FUN_002e4c48(int c, F_t_002E4C48_2E4C48 *fp) { if (c == -1) return -1; do { if (fp->data == 0) fp->data = D_004293F4_002E4C48[0]; if (fp->data->didinit == 0) func_002DBB20_002E4C48(fp->data); } while (0); fp->flags &= ~0x20; if ((fp->flags & 4) == 0) { if ((fp->flags & 0x10) == 0) return -1; if (fp->flags & 8) { if (func_002E18F8_002E4C48(fp)) return -1; fp->flags &= ~8; fp->w = 0; fp->lbfsize = 0; } fp->flags |= 4; } c = (unsigned char)c; if (fp->ubbase != 0) { if (fp->r >= fp->ubsize && func_002E4B58_2E4C48(fp)) return -1; *--fp->p = c; fp->r++; return c; } if (fp->base != 0 && fp->p > fp->base && fp->p[-1] == c) { fp->p--; fp->r++; return c; } fp->ur = fp->r; fp->up = fp->p; fp->ubbase = fp->ubuf; fp->ubsize = 3; fp->ubuf[2] = c; fp->p = &fp->ubuf[2]; fp->r = 1; return c; }

typedef struct B_002E0510_2E0510 { struct B_002E0510_2E0510 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_002E0510_2E0510;
int func_002E30A8_2E0510(void *, void *) __asm__("func_002E30A8");
// MATCH func_002E0510
int FUN_002e0510(B_002E0510_2E0510 *b, B_002E0510_2E0510 *S) { int n; int borrow, y; unsigned carry, q, ys; unsigned *bx, *bxe, *sx, *sxe; int z; unsigned si, zs; n = S->wds; if (b->wds < n) return 0; sx = S->x; sxe = sx + --n; bx = b->x; bxe = bx + n; q = *bxe / (*sxe + 1); if (q) { borrow = 0; carry = 0; do { si = *sx++; ys = (si & 0xffff) * q + carry; zs = (si >> 16) * q + (ys >> 16); carry = zs >> 16; y = (*bx & 0xffff) - (ys & 0xffff) + borrow; borrow = y >> 16; z = (*bx >> 16) - (zs & 0xffff) + borrow; borrow = z >> 16; ((unsigned short *)bx)[1] = (unsigned short)z; ((unsigned short *)bx)[0] = (unsigned short)y; bx++; } while (sx <= sxe); if (!*bxe) { bx = b->x; while (--bxe > bx && !*bxe) --n; b->wds = n; } } if (func_002E30A8_2E0510(b, S) >= 0) { q++; borrow = 0; carry = 0; bx = b->x; sx = S->x; do { si = *sx++; ys = (si & 0xffff) + carry; zs = (si >> 16) + (ys >> 16); carry = zs >> 16; y = (*bx & 0xffff) - (ys & 0xffff) + borrow; borrow = y >> 16; z = (*bx >> 16) - (zs & 0xffff) + borrow; borrow = z >> 16; ((unsigned short *)bx)[1] = (unsigned short)z; ((unsigned short *)bx)[0] = (unsigned short)y; bx++; } while (sx <= sxe); bx = b->x; bxe = bx + n; if (!*bxe) { while (--bxe > bx && !*bxe) --n; b->wds = n; } } return q; }


// MATCH func_002E01F0
char *FUN_002e01f0(char *tab, char *fmt) { int c, n, v; c = *fmt++; if (c == '^') { v = 1; c = *fmt++; } else v = 0; for (n = 0; n < 256; n++) tab[n] = v; if (c == 0) return (fmt - 1); v = 1 - v; for (;;) { tab[c] = v; doswitch: n = *fmt++; switch (n) { case 0: return (fmt - 1); case '-': n = *fmt; if (n == ']' || n < c) { c = '-'; break; } fmt++; do { tab[++c] = v; } while (c < n); goto doswitch; case ']': return (fmt); default: c = n; break; } } }


// MATCH func_002D7350
double FUN_002d7350(long long u) { double d; d = (int) (u >> 32); d *= 65536.0; d *= 65536.0; d += (unsigned) (u & 0xffffffff); return d; }


// MATCH func_002D7258
unsigned long long FUN_002d7258(float original_a) { double a = (double) original_a; double b; unsigned long long v; if (a < 0) return 0; b = (a / 4294967296.0); v = (unsigned) b; v <<= 32; a -= (double) v; if (a < 0) v -= (unsigned) (- a); else v += (unsigned) a; return v; }


// MATCH func_002EF470
unsigned long long FUN_002ef470(double a) { double b; unsigned long long v; if (a < 0) return 0; b = (a / 4294967296.0); v = (unsigned) b; v <<= 32; a -= (double) v; if (a < 0) v -= (unsigned) (- a); else v += (unsigned) a; return v; }

typedef union { double d; struct { unsigned lo; unsigned hi; } w_2DF458; } DU;
void *func_002E0728_2DF458(void *, double d, int mode, int ndigits, void *, void *, void **rve) __asm__("func_002E0728");
// MATCH func_002DF458
char *FUN_002df458(void *ptr, double value, int ndigits, int flags, char *sign, int *decpt, int ch, int *length) { int mode, dsgn; char *digits, *bp, *rve; DU tmp; if (ch == 'f') { mode = 3; } else { if (ch == 'e' || ch == 'E') { ndigits++; } mode = 2; } tmp.d = value; if (tmp.w_2DF458.hi & 0x80000000) { value = -value; *sign = '-'; } else *sign = '\000'; digits = func_002E0728_2DF458(ptr, value, mode, ndigits, decpt, &dsgn, &rve); if ((ch != 'g' && ch != 'G') || flags & 1) { bp = digits + ndigits; if (ch == 'f') { if (*digits == '0' && value) *decpt = -ndigits + 1; bp += *decpt; } if (value == 0) rve = bp; while (rve < bp) *rve++ = '0'; } *length = rve - digits; return (digits); }

#define LIBGCC_CLZ_TAB D_0049F9C8
#define LIBGCC_UDIVMODDI4 udivmoddi4_2EFBC8
#include "../libgcc2_div.h"
// MATCH func_002EFBC8
UDWtype FUN_002efbc8(UDWtype n, UDWtype d) { return udivmoddi4_2EFBC8(n, d, (UDWtype *) 0); }

#define LIBGCC_CLZ_TAB D_0049FAC8
#define LIBGCC_UDIVMODDI4 udivmoddi4_2F0198
#include "../libgcc2_div.h"
// MATCH func_002F0198
UDWtype FUN_002f0198(UDWtype u, UDWtype v) { UDWtype w; (void) udivmoddi4_2F0198(u, v, &w); return w; }

#define LIBGCC_CLZ_TAB D_0049F8C8
#define LIBGCC_UDIVMODDI4 udivmoddi4_2EF560
#include "../libgcc2_div.h"
// MATCH func_002EF560
DWtype FUN_002ef560(DWtype u, DWtype v) { Wtype c = 0; DWunion uu, vv; DWtype w; uu.ll = u; vv.ll = v; if (uu.s.high < 0) c = ~c, uu.ll = negdi2 (uu.ll); if (vv.s.high < 0) vv.ll = negdi2 (vv.ll); (void) udivmoddi4_2EF560(uu.ll, vv.ll, &w); if (c) w = negdi2 (w); return w; }

#define LIBGCC_CLZ_TAB D_0049F7C8
#define LIBGCC_UDIVMODDI4 udivmoddi4_2EED20
#include "../libgcc2_div.h"
// MATCH func_002EED20
DWtype FUN_002eed20(DWtype u, DWtype v) { Wtype c = 0; DWunion uu, vv; DWtype w; uu.ll = u; vv.ll = v; if (uu.s.high < 0) c = ~c, uu.ll = negdi2 (uu.ll); if (vv.s.high < 0) c = ~c, vv.ll = negdi2 (vv.ll); w = udivmoddi4_2EED20(uu.ll, vv.ll, (UDWtype *) 0); if (c) w = negdi2 (w); return w; }

typedef struct { int cls; unsigned int sign; int exp; union { unsigned long long ll; unsigned int bits[4]; } fraction; } FPD_2d7920;
static inline int isnan_2d7920_002D7920(FPD_2d7920 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf_2d7920_002D7920(FPD_2d7920 *x) { return x->cls == 4; }
static inline int iszero_2d7920_002D7920(FPD_2d7920 *x) { return x->cls == 2; }
extern FPD_2d7920 D_00631AD0_2D7920 __asm__("D_00631AD0");
static inline FPD_2d7920 *nan_2d7920_002D7920(void) { return &D_00631AD0_2D7920; }
void func_002D7580_2D7920(void *, void *) __asm__("func_002D7580"); long func_002D7450_2D7920(void *) __asm__("func_002D7450"); unsigned long long func_002D73E8_2D7920(unsigned long long, unsigned long long) __asm__("func_002D73E8");
static inline FPD_2d7920 *fpmul_parts_2d7920_002D7920(FPD_2d7920 *a, FPD_2d7920 *b, FPD_2d7920 *tmp) { unsigned long long low = 0; unsigned long long high = 0; if (isnan_2d7920_002D7920(a)) { a->sign = a->sign != b->sign; return a; } if (isnan_2d7920_002D7920(b)) { b->sign = a->sign != b->sign; return b; } if (isinf_2d7920_002D7920(a)) { if (iszero_2d7920_002D7920(b)) return nan_2d7920_002D7920(); a->sign = a->sign != b->sign; return a; } if (isinf_2d7920_002D7920(b)) { if (iszero_2d7920_002D7920(a)) return nan_2d7920_002D7920(); b->sign = a->sign != b->sign; return b; } if (iszero_2d7920_002D7920(a)) { a->sign = a->sign != b->sign; return a; } if (iszero_2d7920_002D7920(b)) { b->sign = a->sign != b->sign; return b; } { unsigned long long nl = a->fraction.ll & 0xffffffffULL; unsigned long long nh = a->fraction.ll >> 32; unsigned long long ml = b->fraction.ll & 0xffffffffULL; unsigned long long mh = b->fraction.ll >> 32; unsigned long long pp_ll = ml * nl; unsigned long long pp_hl = mh * nl; unsigned long long pp_lh = ml * nh; unsigned long long pp_hh = mh * nh; unsigned long long res2 = 0; unsigned long long res0 = 0; unsigned long long ps_hh__ = pp_hl + pp_lh; if (ps_hh__ < pp_hl) res2 += (unsigned long long)1 << 32; pp_hl = ps_hh__ << 32; res0 = pp_ll + pp_hl; if (res0 < pp_ll) res2++; res2 += ((ps_hh__ >> 32) & 0xffffffffULL) + pp_hh; high = res2; low = res0; } tmp->exp = a->exp + b->exp + 4; tmp->sign = a->sign != b->sign; while (high >= 0x2000000000000000ULL) { tmp->exp++; if (high & 1) { low >>= 1; low |= 0x8000000000000000ULL; } high >>= 1; } while (high < 0x1000000000000000ULL) { tmp->exp--; high <<= 1; if (low & 0x8000000000000000ULL) high |= 1; low <<= 1; } if ((high & 0xff) == 0x80) { if (high & (1 << 8)) { high += 0x7f + 1; } else if (low) { high += 0x7f + 1; } } tmp->fraction.ll = high; tmp->cls = 3; return tmp; }
// MATCH func_002D7920
long __muldf3(long x, long y) { FPD_2d7920 a; FPD_2d7920 b; FPD_2d7920 tmp; func_002D7580_2D7920(&x, &a); func_002D7580_2D7920(&y, &b); return func_002D7450_2D7920(fpmul_parts_2d7920_002D7920(&a, &b, &tmp)); }

typedef struct fde_9518_002D9518_2D9518 { int length; int CIE_delta; unsigned pc_begin; unsigned pc_range; } fde_9518_002D9518_2D9518;
struct fv_9518 { fde_9518_002D9518_2D9518 **array; unsigned count; };
static inline int fde_compare_9518_002D9518(fde_9518_002D9518_2D9518 *x, fde_9518_002D9518_2D9518 *y) { return x->pc_begin - y->pc_begin; }
// MATCH func_002D9518
void FUN_002d9518(struct fv_9518 *v1, struct fv_9518 *v2) { unsigned i1, i2; fde_9518_002D9518_2D9518 *fde2; i2 = v2->count; if (i2 > 0) { i1 = v1->count; do { i2--; fde2 = v2->array[i2]; while (i1 > 0 && fde_compare_9518_002D9518(v1->array[i1-1], fde2) > 0) { v1->array[i1+i2] = v1->array[i1-1]; i1--; } v1->array[i1+i2] = fde2; } while (i2 > 0); v1->count += v2->count; } }


typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_a160_002DA160_2DA160;
typedef struct FSI_a160_002DA160_2DA160 { FS_a160_002DA160_2DA160 s; struct FSI_a160_002DA160_2DA160 *saved_state; } FSI_a160_002DA160_2DA160;
typedef struct { char *augmentation; void *eh_ptr; int code_align; int data_align; unsigned ra_column; } CIE_a160_002DA160_2DA160;
typedef struct fde_a160_002DA160_2DA160 { int length; int CIE_delta; unsigned pc_begin; unsigned pc_range; } fde_a160_002DA160_2DA160;
fde_a160_002DA160_2DA160 *func_002D9A90_a160(void *) __asm__("func_002D9A90");
unsigned char *func_002D9B78_a160(fde_a160_002DA160_2DA160 *, CIE_a160_002DA160_2DA160 *) __asm__("func_002D9B78");
unsigned char *func_002D9C80_a160(unsigned char *, FSI_a160_002DA160_2DA160 *, CIE_a160_002DA160_2DA160 *, unsigned *) __asm__("func_002D9C80");
unsigned char *func_002D9480_a160(unsigned char *, int *) __asm__("func_002D9480");
void *memset(void *, int, unsigned);
static inline fde_a160_002DA160_2DA160 *next_fde_a160_002DA160(fde_a160_002DA160_2DA160 *f) { return (fde_a160_002DA160_2DA160 *)(((char *)f) + f->length + sizeof (f->length)); }
static inline fde_a160_002DA160_2DA160 *get_cie_a160_002DA160(fde_a160_002DA160_2DA160 *f) { return (fde_a160_002DA160_2DA160 *)((char *)&f->CIE_delta - f->CIE_delta); }
// MATCH func_002DA160
FS_a160_002DA160_2DA160 *FUN_002da160(void *pc_target, FS_a160_002DA160_2DA160 *state_in) { fde_a160_002DA160_2DA160 *f; unsigned char *insn, *end; unsigned pc; CIE_a160_002DA160_2DA160 info; FSI_a160_002DA160_2DA160 state; f = func_002D9A90_a160(pc_target); if (f == 0) return 0; insn = func_002D9B78_a160(f, &info); if (insn == 0) return 0; memset(&state, 0, sizeof (state)); state.s.retaddr_column = info.ra_column; state.s.eh_ptr = info.eh_ptr; end = (unsigned char *) next_fde_a160_002DA160(get_cie_a160_002DA160(f)); while (insn < end) insn = func_002D9C80_a160(insn, &state, &info, 0); insn = (unsigned char *)(f + 1); if (info.augmentation[0] == 'z') { int i; insn = func_002D9480_a160(insn, &i); insn += i; } end = (unsigned char *) next_fde_a160_002DA160(f); pc = f->pc_begin; while (insn < end && pc <= (unsigned)pc_target) insn = func_002D9C80_a160(insn, &state, &info, &pc); *state_in = state.s; return state_in; }


typedef struct fde_9618 { int length; int CIE_delta; unsigned pc_begin; unsigned pc_range; } fde_9618;
struct fv_9618 { fde_9618 **array; unsigned count; };
struct acc_9618 { struct fv_9618 linear; struct fv_9618 erratic; };
void func_002DB900_9618(void) __asm__("func_002DB900") __attribute__((noreturn));
void func_002DA338_9618(struct fv_9618 *, struct fv_9618 *) __asm__("func_002DA338");
void func_002D9518_9618(struct fv_9618 *, struct fv_9618 *) __asm__("func_002D9518");
void func_002DBC70_9618(void *) __asm__("func_002DBC70");
static inline int fde_compare_9618(fde_9618 *x, fde_9618 *y) { return x->pc_begin - y->pc_begin; }
#define SWAP(x, y) do { fde_9618 *tmp = x; x = y; y = tmp; } while (0)
static inline void frame_heapsort_9618(struct fv_9618 *erratic) { fde_9618 **a; unsigned n, m, i; a = erratic->array; n = erratic->count; m = n; while (m > 0) { m--; for (i = m; 2*i+1 < n; ) { if (2*i+2 < n && fde_compare_9618(a[2*i+2], a[2*i+1]) > 0 && fde_compare_9618(a[2*i+2], a[i]) > 0) { SWAP(a[i], a[2*i+2]); i = 2*i+2; } else if (fde_compare_9618(a[2*i+1], a[i]) > 0) { SWAP(a[i], a[2*i+1]); i = 2*i+1; } else break; } } while (n > 1) { n--; SWAP(a[0], a[n]); for (i = 0; 2*i+1 < n; ) { if (2*i+2 < n && fde_compare_9618(a[2*i+2], a[2*i+1]) > 0 && fde_compare_9618(a[2*i+2], a[i]) > 0) { SWAP(a[i], a[2*i+2]); i = 2*i+2; } else if (fde_compare_9618(a[2*i+1], a[i]) > 0) { SWAP(a[i], a[2*i+1]); i = 2*i+1; } else break; } } }
// MATCH func_002D9618
fde_9618 **FUN_002d9618(struct acc_9618 *accu, unsigned count) { unsigned c0; c0 = accu->linear.count; if (c0 != count) func_002DB900_9618(); func_002DA338_9618(&accu->linear, &accu->erratic); if (accu->linear.count + accu->erratic.count != c0) func_002DB900_9618(); frame_heapsort_9618(&accu->erratic); func_002D9518_9618(&accu->linear, &accu->erratic); func_002DBC70_9618(accu->erratic.array); return accu->linear.array; }
#undef SWAP

struct glue_ba20 { struct glue_ba20 *_next; int _niobs; struct file_ba20 *_iobs; };
struct sbuf_ba20 { unsigned char *_base; int _size; };
struct file_ba20 { unsigned char *_p; int _r; int _w; short _flags; short _file; struct sbuf_ba20 _bf; int _lbfsize; void *_cookie; void *_read; void *_write; void *_seek; void *_close; struct sbuf_ba20 _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; struct sbuf_ba20 _lb; int _blksize; int _offset; struct reent_ba20 *_reent; };
struct reent_ba20 { int _errno; char pad[0x34]; int __sdidinit; char pad2[0x19c]; struct glue_ba20 __sglue; };
void func_002DBB20_ba20(struct reent_ba20 *) __asm__("func_002DBB20");
struct glue_ba20 *func_002DB9B0_ba20(struct reent_ba20 *, int) __asm__("func_002DB9B0");
// MATCH func_002DBA20
struct file_ba20 *FUN_002dba20(struct reent_ba20 *d) { struct file_ba20 *fp; int n; struct glue_ba20 *g; if (d->__sdidinit == 0) func_002DBB20_ba20(d); for (g = &d->__sglue;; g = g->_next) { for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++) if (fp->_flags == 0) goto found; if (g->_next == 0 && (g->_next = func_002DB9B0_ba20(d, 4)) == 0) break; } d->_errno = 12; return 0; found: fp->_file = -1; fp->_flags = 1; fp->_p = 0; fp->_w = 0; fp->_r = 0; fp->_bf._base = 0; fp->_bf._size = 0; fp->_lbfsize = 0; fp->_file = -1; fp->_ub._base = 0; fp->_ub._size = 0; fp->_lb._base = 0; fp->_lb._size = 0; fp->_reent = d; return fp; }


// MATCH func_002DF608
int FUN_002df608(char *p0, int exp, int fmtch) { register char *p, *t; char expbuf[308]; p = p0; *p++ = fmtch; if (exp < 0) { exp = -exp; *p++ = '-'; } else *p++ = '+'; t = expbuf + 308; if (exp > 9) { do { *--t = (exp % 10) + '0'; } while ((exp /= 10) > 9); *--t = exp + '0'; for (; t < expbuf + 308; *p++ = *t++) ; } else { *p++ = '0'; *p++ = exp + '0'; } return (p - p0); }

typedef struct { unsigned low; int high; } DWstruct_73E8;
typedef union { DWstruct_73E8 s; long long ll; } DWunion_73E8;
static inline DWunion_73E8 umulsidi3_73E8(unsigned u, unsigned v) { DWunion_73E8 w; __asm__("multu %2,%3" : "=l" ((unsigned)(w.s.low)), "=h" ((unsigned)(w.s.high)) : "d" ((unsigned)(u)), "d" ((unsigned)(v))); return w; }
// MATCH func_002D73E8
long long FUN_002d73e8(long long u, long long v) { DWunion_73E8 w; DWunion_73E8 uu, vv; uu.ll = u, vv.ll = v; w.ll = umulsidi3_73E8(uu.s.low, vv.s.low).ll; w.s.high += ((unsigned) uu.s.low * (unsigned) vv.s.high + (unsigned) uu.s.high * (unsigned) vv.s.low); return w.ll; }

struct fde_9950 { int length; int CIE_delta; unsigned pc_begin; unsigned pc_range; };
struct fv_9950 { struct fde_9950 **array; unsigned count; };
struct acc_9950 { struct fv_9950 linear; struct fv_9950 erratic; };
struct obj_9950 { unsigned pc_begin; unsigned pc_end; struct fde_9950 *fde_begin; struct fde_9950 **fde_array; unsigned count; struct obj_9950 *next; };
unsigned func_002D9880_9950(struct fde_9950 *) __asm__("func_002D9880");
void *func_002DBC48_9950(int) __asm__("func_002DBC48");
void func_002D98C8_9950(struct fde_9950 *, struct acc_9950 *, unsigned *, unsigned *) __asm__("func_002D98C8");
struct fde_9950 **func_002D9618_9950(struct acc_9950 *, unsigned) __asm__("func_002D9618");
// MATCH func_002D9950
void FUN_002d9950(struct obj_9950 *ob) {
  struct acc_9950 accu;
  unsigned count, beg, end;
  if (ob->fde_array) {
    struct fde_9950 **p = ob->fde_array;
    for (count = 0; *p; ++p)
      count += func_002D9880_9950(*p);
  } else
    count = func_002D9880_9950(ob->fde_begin);
  ob->count = count;
  accu.linear.array = func_002DBC48_9950(sizeof (struct fde_9950 *) * count);
  accu.erratic.array = func_002DBC48_9950(sizeof (struct fde_9950 *) * count);
  accu.linear.count = 0;
  accu.erratic.count = 0;
  beg = -1;
  end = 0;
  if (ob->fde_array) {
    struct fde_9950 **p = ob->fde_array;
    for (; *p; ++p)
      func_002D98C8_9950(*p, &accu, &beg, &end);
  } else
    func_002D98C8_9950(ob->fde_begin, &accu, &beg, &end);
  ob->fde_array = func_002D9618_9950(&accu, count);
  ob->pc_begin = beg;
  ob->pc_end = end;
}

typedef struct fde_a338 { int length; int CIE_delta; unsigned pc_begin; unsigned pc_range; } fde_a338;
struct fv_a338 { fde_a338 **array; unsigned count; };
static inline int fde_compare(fde_a338 *x, fde_a338 *y) { return x->pc_begin - y->pc_begin; }
// MATCH func_002DA338
void FUN_002da338(struct fv_a338 *linear, struct fv_a338 *erratic) {
  unsigned count = linear->count;
  unsigned linear_max = (unsigned) -1;
  unsigned previous_max[count];
  unsigned i, j;
  for (i = 0; i < count; i++) {
    j = linear_max;
    while (j != (unsigned) -1 && fde_compare(linear->array[i], linear->array[j]) < 0) {
      erratic->array[erratic->count++] = linear->array[j];
      linear->array[j] = 0;
      j = previous_max[j];
    }
    linear_max = i;
    previous_max[i] = j;
  }
  for (i = j = 0; i < count; i++)
    if (linear->array[i])
      linear->array[j++] = linear->array[i];
  linear->count = j;
}

typedef struct { void *start; void *end; void *exception_handler; } exception_table_6770;
// MATCH func_002D6770
void *FUN_002d6770(void *pc, exception_table_6770 *table) {
  if (table) {
    int best = -1;
    int pos = 0;
    while (table[pos].start != (void *) -1) {
      if (table[pos].start <= pc && table[pos].end > pc) {
        if (best == -1 || (table[pos].end <= table[best].end && table[pos].start >= table[best].start))
          best = pos;
      } else if (best >= 0 && table[pos].start > pc)
        break;
      pos++;
    }
    if (best != -1)
      return table[best].exception_handler;
  }
  return (void *) 0;
}

extern void (**D_00427EF0[])(void);
// MATCH func_002D6190
void FUN_002d6190(void) {
  while (*D_00427EF0[0]) {
    D_00427EF0[0]++;
    (*(D_00427EF0[0] - 1))();
  }
}

typedef struct { void *start_region; void *end_region; void *exception_handler; void *match_info; } exception_table_6848;
typedef struct { int (*match_function)(void *, void *, void *); } eh_info_6848;
// MATCH func_002D6848
void *FUN_002d6848(void *pc, char *table, eh_info_6848 *eh_info, int rethrow, int *cleanup) {
  void *retval = 0;
  *cleanup = 1;
  if (table) {
    int pos = 0;
    exception_table_6848 *tbl = (exception_table_6848 *)(table + 8);
    if (rethrow) {
      pos = ((char *)pc - (char *)tbl) >> 4;
      pc = (char *)((exception_table_6848 *)pc)->end_region - 1;
      if (tbl[pos].start_region != (void *) -1)
        pos++;
    } else
      pc = (char *)pc - 1;
    while (tbl[pos].start_region != (void *) -1) {
      if (tbl[pos].start_region <= pc && tbl[pos].end_region > pc) {
        if (tbl[pos].match_info) {
          if (eh_info->match_function) {
            if (eh_info->match_function(eh_info, tbl[pos].match_info, table)) {
              if (!retval) retval = tbl[pos].exception_handler;
              *cleanup = 0;
              return retval;
            }
          }
        } else {
          if (!retval) retval = tbl[pos].exception_handler;
        }
      }
      pos++;
    }
  }
  return retval;
}

typedef void (*func_ptr)(void);
extern func_ptr D_002F7098_2D61E8[] __asm__("D_002F7098");
// MATCH func_002D61E8
void FUN_002d61e8(void) { unsigned long nptrs; func_ptr *new_var; func_ptr *new_var2; unsigned i; do { nptrs = (unsigned long) D_002F7098_2D61E8[0]; if (nptrs == ((unsigned long) (-1))) { for (nptrs = 0; D_002F7098_2D61E8[nptrs + 1] != 0; nptrs++) { ; } } for (i = nptrs; i >= 1; i--) { if (1) { new_var = D_002F7098_2D61E8; new_var2 = new_var; new_var2[i](); } } } while (0); }

extern int D_0049E670_2D5618[] __asm__("D_0049E670");
extern char D_0049E610_2D5618[] __asm__("D_0049E610");
extern const double D_0049E618_2D5618[] __asm__("D_0049E618");
struct exc_2d5618 { int type; char *name; double arg1; double arg2; double retval; int err; };
double FUN_002d5990(double, double);
int FUN_002d6108(double);
int FUN_002d6140(void *);
int FUN_002d7e48(double, int);
int *FUN_002db948(void);
// MATCH func_002D5618
double FUN_002d5618(double x, double y) { double z; int v; struct exc_2d5618 exc; z = FUN_002d5990(x, y); v = D_0049E670_2D5618[0]; if (v == -1 || FUN_002d6108(y) || FUN_002d6108(x)) return z; if (y == 0.0) { exc.type = 1; exc.name = D_0049E610_2D5618; exc.arg1 = x; exc.arg2 = y; exc.err = 0; if (v == 0) exc.retval = x; else exc.retval = D_0049E618_2D5618[0]; if (D_0049E670_2D5618[0] == 2) *FUN_002db948() = 33; else if (!FUN_002d6140(&exc)) *FUN_002db948() = 33; if (exc.err != 0) *FUN_002db948() = exc.err; return exc.retval; } else return z; }

extern int D_0049E670_002D5738[] __asm__("D_0049E670");
extern char D_0049E620_2D5738[] __asm__("D_0049E620");
extern const double D_0049E628_2D5738[] __asm__("D_0049E628");
struct exc_2d5738 { int type; char *name; double arg1; double arg2; double retval; int err; };
float FUN_002d5d80(float, float);
int FUN_002d6168(float);
int FUN_002d6140(void *);
int *FUN_002db948(void);
// MATCH func_002D5738
float FUN_002d5738(float x, float y) { float z; int v; struct exc_2d5738 exc; z = FUN_002d5d80(x, y); v = D_0049E670_002D5738[0]; if (v == -1 || FUN_002d6168(y) || FUN_002d6168(x)) return z; if (y == 0.0f) { exc.type = 1; exc.name = D_0049E620_2D5738; exc.err = 0; exc.arg1 = (double)x; exc.arg2 = (double)y; if (v == 0) exc.retval = (double)x; else exc.retval = D_0049E628_2D5738[0]; if (D_0049E670_002D5738[0] == 2) *FUN_002db948() = 33; else if (!FUN_002d6140(&exc)) *FUN_002db948() = 33; if (exc.err != 0) *FUN_002db948() = exc.err; return (float)exc.retval; } else return z; }

extern int D_0049E670_002D5878[] __asm__("D_0049E670");
extern char D_0049E630_2D5878[] __asm__("D_0049E630");
extern const double D_0049E638_2D5878[] __asm__("D_0049E638");
struct exc_2d5878 { int type; char *name; double arg1; double arg2; double retval; int err; };
float FUN_002d5fd0(float);
int FUN_002d6168(float);
int FUN_002d6140(void *);
int *FUN_002db948(void);
// MATCH func_002D5878
float FUN_002d5878(float x) { float z; int v; struct exc_2d5878 exc; z = FUN_002d5fd0(x); v = D_0049E670_002D5878[0]; if (v == -1 || FUN_002d6168(x)) return z; if (x < 0.0f) { exc.type = 1; exc.name = D_0049E630_2D5878; exc.err = 0; exc.arg1 = exc.arg2 = (double)x; if (v == 0) exc.retval = 0.0; else exc.retval = D_0049E638_2D5878[0]; if (D_0049E670_002D5878[0] == 2) *FUN_002db948() = 33; else if (!FUN_002d6140(&exc)) *FUN_002db948() = 33; if (exc.err != 0) *FUN_002db948() = exc.err; return (float)exc.retval; } else return z; }

typedef union { double value; struct { unsigned lsw; unsigned msw; } parts_2D6108; } DW_2D6108;
#define EXTRACT_WORDS(ix0, ix1, d) do { DW_2D6108 ew_u; ew_u.value = (d); (ix0) = ew_u.parts_2D6108.msw; (ix1) = ew_u.parts_2D6108.lsw; } while (0)
// MATCH func_002D6108
int FUN_002d6108(double x) { int hx, lx; EXTRACT_WORDS(hx, lx, x); hx &= 0x7fffffff; hx |= (unsigned)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return (int)(((unsigned)hx) >> 31); }
#undef EXTRACT_WORDS

typedef union { float value; unsigned word; } FW_2D6168;
#define GET_FLOAT_WORD(i, d) do { FW_2D6168 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
// MATCH func_002D6168
int FUN_002d6168(float x) { int hx; GET_FLOAT_WORD(hx, x); hx &= 0x7fffffff; hx = 0x7f800000 - hx; return (int)(((unsigned)hx) >> 31); }
#undef GET_FLOAT_WORD

typedef union { float value; int word; } FW_2D5FD0;
#define GET_FLOAT_WORD(i, d) do { FW_2D5FD0 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { FW_2D5FD0 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
// MATCH func_002D5FD0
float FUN_002d5fd0(float x) { float z; int sign = (int)0x80000000; int ix, s, q, m, t, i; unsigned r; GET_FLOAT_WORD(ix, x); if ((ix & 0x7f800000) == 0x7f800000) return x * x + x; if (ix <= 0) { if ((ix & (~sign)) == 0) return x; else if (ix < 0) return (x - x) / (x - x); } m = (ix >> 23); if (m == 0) { for (i = 0; (ix & 0x00800000) == 0; i++) ix <<= 1; m -= i - 1; } m -= 127; ix = (ix & 0x007fffff) | 0x00800000; if (m & 1) ix += ix; m >>= 1; ix += ix; q = s = 0; r = 0x01000000; while (r != 0) { t = s + r; if (t <= ix) { s = t + r; ix -= t; q += r; } ix += ix; r >>= 1; } if (ix != 0) { q += (q & 1); } ix = (q >> 1) + 0x3f000000; ix += (m << 23); SET_FLOAT_WORD(z, ix); return z; }
#undef GET_FLOAT_WORD
#undef SET_FLOAT_WORD

typedef union { double value; struct { unsigned lsw; unsigned msw; } parts_2E3960; } DW_2E3960;
#define EXTRACT_WORDS(ix0, ix1, d) do { DW_2E3960 ew_u; ew_u.value = (d); (ix0) = ew_u.parts_2E3960.msw; (ix1) = ew_u.parts_2E3960.lsw; } while (0)
// MATCH func_002E3960
int FUN_002e3960(double x) { int hx, lx; EXTRACT_WORDS(hx, lx, x); hx &= 0x7fffffff; hx |= (unsigned)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return 1 - (int)((unsigned)(hx | (-hx)) >> 31); }
#undef EXTRACT_WORDS

volatile short func_002EDC50_2E82B0(void) __asm__("func_002EDC50"); void func_002EDC98_2E82B0(void) __asm__("func_002EDC98");
// MATCH func_002E82B0
int FUN_002e82b0(int *p) { int i; int j; int k; char *q; func_002EDC50_2E82B0(); i = 0; q = (char *)p[1]; if (0 < p[2]) { do { if ((*(unsigned *)(q + 16) & 1) == 0) { *(unsigned *)(q + 16) = (i << 16) | 5; k = *p; *p = k + 1; if (k + 1 == 1) { *p = k + 2; j = 1; } else j = k + 1; *(int *)(q + 20) = (int)q; *(int *)(q + 24) = j; func_002EDC98_2E82B0(); return (int)q; } i++; q += 64; } while (i < p[2]); } func_002EDC98_2E82B0(); return 0; }

extern const float D_0049E660_2D5D80[] __asm__("D_0049E660");
typedef union { float value; int word; } FW_2D5D80;
#define GET_FLOAT_WORD(i, d) do { FW_2D5D80 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d, i) do { FW_2D5D80 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
// MATCH func_002D5D80
float FUN_002d5d80(float x, float y) { int n, hx, hy, hz, ix, iy, sx, i; GET_FLOAT_WORD(hx, x); GET_FLOAT_WORD(hy, y); sx = hx & 0x80000000; hx ^= sx; hy &= 0x7fffffff; if (hy == 0 || (hx >= 0x7f800000) || (hy > 0x7f800000)) return (x * y) / (x * y); if (hx < hy) return x; if (hx == hy) return D_0049E660_2D5D80[(unsigned)sx >> 31]; if (hx < 0x00800000) { for (ix = -126, i = (hx << 8); i > 0; i <<= 1) ix -= 1; } else ix = (hx >> 23) - 127; if (hy < 0x00800000) { for (iy = -126, i = (hy << 8); i >= 0; i <<= 1) iy -= 1; } else iy = (hy >> 23) - 127; if (ix >= -126) hx = 0x00800000 | (0x007fffff & hx); else { n = -126 - ix; hx = hx << n; } if (iy >= -126) hy = 0x00800000 | (0x007fffff & hy); else { n = -126 - iy; hy = hy << n; } n = ix - iy; while (i = n, n--, i != 0) { hz = hx - hy; if (hz < 0) { hx = hx + hx; } else { if (hz == 0) return D_0049E660_2D5D80[(unsigned)sx >> 31]; hx = hz + hz; } } hz = hx - hy; if (hz >= 0) { hx = hz; } if (hx == 0) return D_0049E660_2D5D80[(unsigned)sx >> 31]; while (hx < 0x00800000) { hx = hx + hx; iy -= 1; __asm__ volatile ("" : : "r"(n)); } if (iy >= -126) { hx = ((hx - 0x00800000) | ((iy + 127) << 23)); SET_FLOAT_WORD(x, hx | sx); } else { n = -126 - iy; hx >>= n; SET_FLOAT_WORD(x, hx | sx); } return x; }
#undef GET_FLOAT_WORD
#undef SET_FLOAT_WORD

extern int D_00631800_2D3628[] __asm__("D_00631800"); extern char D_00631600_2D3628[] __asm__("D_00631600");
void *func_002CFF90_2D3628(void) __asm__("func_002CFF90"); void *func_002CFFC0_2D3628(int, int) __asm__("func_002CFFC0"); void *func_002CFF08_2D3628(int) __asm__("func_002CFF08"); void *func_002CFF48_2D3628(int) __asm__("func_002CFF48"); void *func_002CFF38_2D3628(void) __asm__("func_002CFF38"); void *func_002CFF20_2D3628(int) __asm__("func_002CFF20");
void func_002D37C0_2D3628() __asm__("func_002D37C0");
void *memset(void *, int, unsigned);
// MATCH func_002D3628
void FUN_002d3628(int a) { char *s0; char *s1; unsigned char *s2; char *s3; char *s4; char *s5; int i; int buf[16]; s0 = func_002CFF90_2D3628(); s1 = func_002CFFC0_2D3628(0, 0); s2 = (unsigned char *)func_002CFF08_2D3628(0); s3 = func_002CFF48_2D3628(0); s4 = func_002CFF38_2D3628(); s5 = func_002CFF20_2D3628(0); D_00631800_2D3628[0] = 0x20000000 | (int)D_00631600_2D3628; buf[0] = 0x1e; buf[4] = 0; buf[1] = a; func_002D37C0_2D3628(0x65, 0, buf, buf, 0x40, 0x40); memset(s2, 0, 0x1080); memset(s3, 0, 0x600); memset(s5, 0, 0xfc0); memset(s4, 0, 0x50); memset(s1, 0, 0x1000); memset((void *)D_00631800_2D3628[0], 0, 0x200); memset(s0, 0, 0x200); i = 0x2f; do { s2[0x50] = 0xff; i--; s2[0x56] = 0xff; s2[0x55] = 0xff; s2[0x54] = 0xff; s2 += 0x58; } while (i >= 0); *(volatile int *)(s4 + 0x48) = 0; *(volatile int *)(s4 + 0x44) = 1; *(volatile short *)(s4 + 0x3a) = 0x3c; *(int *)(s4 + 0x40) = 0; }

extern const double D_0049E648_2D5990[] __asm__("D_0049E648");
typedef union { double d; struct { unsigned lo; int hi; } w_2D5990; } DW_2D5990;
#define EXTRACT_WORDS(h, l, v) do { DW_2D5990 ew_u; ew_u.d = (v); (h) = ew_u.w_2D5990.hi; (l) = ew_u.w_2D5990.lo; } while (0)
#define INSERT_WORDS(v, h, l) do { DW_2D5990 iw_u; iw_u.w_2D5990.hi = (h); iw_u.w_2D5990.lo = (l); (v) = iw_u.d; } while (0)
// MATCH func_002D5990
double FUN_002d5990(double x, double y) { unsigned n; int hx, hy, hz, ix, iy, sx, i; unsigned lx, ly, lz; register int cp __asm__("$2"); EXTRACT_WORDS(hx, lx, x); EXTRACT_WORDS(hy, ly, y); sx = hx & 0x80000000; hx ^= sx; hy &= 0x7fffffff; if ((hy | ly) == 0 || (hx >= 0x7ff00000) || ((hy | ((ly | -ly) >> 31)) > 0x7ff00000)) return (x * y) / (x * y); if (hx <= hy) { if ((hx < hy) || (lx < ly)) return x; if (lx == ly) return D_0049E648_2D5990[(unsigned)sx >> 31]; } if (hx < 0x00100000) { if (hx == 0) { for (ix = -1043, i = lx; i > 0; i <<= 1) ix -= 1; } else { for (ix = -1022, i = (hx << 11); i > 0; i <<= 1) ix -= 1; } } else ix = (hx >> 20) - 1023; if (hy < 0x00100000) { if (hy == 0) { for (iy = -1043, i = ly; i > 0; i <<= 1) iy -= 1; } else { for (iy = -1022, i = (hy << 11); i > 0; i <<= 1) iy -= 1; } } else iy = (hy >> 20) - 1023; if (ix >= -1022) hx = 0x00100000 | (0x000fffff & hx); else { n = -1022 - ix; if ((int)n <= 31) { hx = (hx << n) | (lx >> (32 - n)); lx <<= n; } else { hx = lx << (n - 32); lx = 0; } } if (iy >= -1022) hy = 0x00100000 | (0x000fffff & hy); else { n = -1022 - iy; if ((int)n <= 31) { hy = (hy << n) | (ly >> (32 - n)); ly <<= n; } else { hy = ly << (n - 32); ly = 0; } } n = ix - iy; while (cp = n, n--, cp != 0) { hz = hx - hy; lz = lx - ly; if (lx < ly) hz -= 1; if (hz < 0) { hx = hx + hx + (lx >> 31); lx = lx + lx; } else { if ((hz | lz) == 0) return D_0049E648_2D5990[(unsigned)sx >> 31]; hx = hz + hz + (lz >> 31); lx = lz + lz; } } hz = hx - hy; lz = lx - ly; if (lx < ly) hz -= 1; if (hz >= 0) { hx = hz; lx = lz; } if ((hx | lx) == 0) return D_0049E648_2D5990[(unsigned)sx >> 31]; while (hx < 0x00100000) { hx = hx + hx + (lx >> 31); lx = lx + lx; iy -= 1; } if (iy >= -1022) { hx = ((hx - 0x00100000) | ((iy + 1023) << 20)); INSERT_WORDS(x, hx | sx, lx); } else { n = -1022 - iy; if ((int)n <= 20) { lx = (lx >> n) | ((unsigned)hx << (32 - n)); hx >>= n; } else if ((int)n <= 31) { lx = (hx << (32 - n)) | (lx >> n); hx = sx; } else { lx = hx >> (n - 32); hx = sx; } INSERT_WORDS(x, hx | sx, lx); } return x; }
#undef EXTRACT_WORDS
#undef INSERT_WORDS

extern int D_00429878_2E5EE8[] __asm__("D_00429878");
int func_002E6E70_2E5EE8(int param_1, int param_2) __asm__("func_002E6E70");
int func_002E6F40_2E5EE8() __asm__("func_002E6F40");
// MATCH func_002E5EE8
int FUN_002e5ee8(int param_1,int param_2,int param_3)  { int lVar1; int uVar2;  if (param_1 == 0) { if (D_00429878_2E5EE8[0] == 0) { lVar1 = func_002E6F40_2E5EE8(); if (lVar1 == 0) goto LAB_002e5f40; do { D_00429878_2E5EE8[0] = 1; } while (0); } uVar2 = func_002E6E70_2E5EE8(param_2,param_3); } else { LAB_002e5f40: uVar2 = 0xffffffffffffffff; } return uVar2; }

volatile short func_002EDC50_2E8BF0(void) __asm__("func_002EDC50"); void func_002EDC98_2E8BF0() __asm__("func_002EDC98");
// MATCH func_002E8BF0
void FUN_002e8bf0(int *n, int a, int b, int c, int d, int e, int *o) { int *h; int *p; int *q; int *t; func_002EDC50_2E8BF0(); ((volatile int *)n)[15] = 0; ((volatile int *)n)[14] = 0; *(volatile int *)n = a; h = (int *)o[2]; n[1] = b; n[2] = c; n[4] = d; n[5] = e; n[16] = (int)o; if (h == 0) o[2] = (int)n; else { p = h; q = (int *)p[14]; if (q != 0) { do { p = q; t = (int *)p[14]; q = t; } while (t != 0); } p[14] = (int)n; } func_002EDC98_2E8BF0(); }

extern int D_00429878_2E5E68[] __asm__("D_00429878");
int func_002E6D20_2E5E68(int, int) __asm__("func_002E6D20"); int func_002E6F40_2E5E68() __asm__("func_002E6F40");
// MATCH func_002E5E68
int FUN_002e5e68(int a, int b, int c) { if (a - 1U < 2) { if (D_00429878_2E5E68[0] == 0) { if (func_002E6F40_2E5E68() == 0) return -1; D_00429878_2E5E68[0] = 1; } return func_002E6D20_2E5E68(b, c); } return -1; }

int func_002E8DE8_2E9008(int) __asm__("func_002E8DE8"); void func_002E8E40_2E9008(int) __asm__("func_002E8E40");
// MATCH func_002E9008
void FUN_002e9008(int p) { int r; for (;;) { while ((r = func_002E8DE8_2E9008(p)) != 0) func_002E8E40_2E9008(r); SleepThread(); } }

typedef struct { volatile int h; volatile int a4; volatile int a8; volatile int ac; void *p10; void *p14; void *p18; } G6f40_002E6F40_2E6F40;
typedef struct { char pad[2]; short s2; short s4; char c6; char c7; int w8; } U6f40_002E6F40_2E6F40;
extern G6f40_002E6F40_2E6F40 D_00632450_2E6F40 __asm__("D_00632450"); extern char D_00632480_2E6F40[] __asm__("D_00632480"), D_006325C0_2E6F40[] __asm__("D_006325C0");
void func_002E5B20_2E6F40(int) __asm__("func_002E5B20"); int func_002E6900_2E6F40(int, G6f40_002E6F40_2E6F40 *, void *) __asm__("func_002E6900"); void *func_002E6AE0_2E6F40(int) __asm__("func_002E6AE0"); void func_002E6B88_2E6F40(void) __asm__("func_002E6B88");
// MATCH func_002E6F40
int FUN_002e6f40(void) { U6f40_002E6F40_2E6F40 *u; func_002E5B20_2E6F40(0); D_00632450_2E6F40.h = func_002E6900_2E6F40(0x210, &D_00632450_2E6F40, (void *)func_002E6B88_2E6F40); if (D_00632450_2E6F40.h < 0) return 0; D_00632450_2E6F40.ac = 0; D_00632450_2E6F40.a4 = 0; D_00632450_2E6F40.a8 = 0; D_00632450_2E6F40.p14 = (void *)((unsigned)D_006325C0_2E6F40 | 0x20000000); u = (U6f40_002E6F40_2E6F40 *)((unsigned)D_00632480_2E6F40 | 0x20000000); D_00632450_2E6F40.p10 = u; u->s4 = 0x210; u->c6 = 0x45; u->c7 = 0x48; u->s2 = 0; u->w8 = 0; D_00632450_2E6F40.p18 = func_002E6AE0_2E6F40(0x100); return 1; }

extern int D_00426350_2CBB80[] __asm__("D_00426350");
extern volatile int D_00426370_2CBB80[] __asm__("D_00426370");
extern char D_00427510_2CBB80[] __asm__("D_00427510");
extern char D_0049E080_2CBB80[] __asm__("D_0049E080");
int func_002E8B18_2CBB80(void *) __asm__("func_002E8B18");
void func_002CB040_2CBB80(int) __asm__("func_002CB040");
void func_002E7940_2CBB80(void *) __asm__("func_002E7940");
// MATCH func_002CBB80
int FUN_002cbb80(int a) { if (a == 0) { if (D_00426350_2CBB80[0] > 0) { func_002E7940_2CBB80(D_0049E080_2CBB80); } while ((D_00426370_2CBB80[0] != 0) || (func_002E8B18_2CBB80(D_00427510_2CBB80) != 0)) { func_002CB040_2CBB80(60); }  return 0; } if (D_00426370_2CBB80[0] != 0 || func_002E8B18_2CBB80(D_00427510_2CBB80) != 0) return 1; return 0; }

struct obj_9a90
{
  void *pc_begin;
  void *pc_end;
  struct fde_9a90 *fde_begin;
  struct fde_9a90 **fde_array;
  unsigned count;
  struct obj_9a90 *next;
};
struct fde_9a90
{
  int length;
  int CIE_delta;
  void *pc_begin;
  unsigned pc_range;
};
extern struct obj_9a90 *D_00631AF8_2D9A90[] __asm__("D_00631AF8");
void func_002D9950_2D9A90(void *) __asm__("func_002D9950");
// MATCH func_002D9A90
struct fde_9a90 *FUN_002d9a90(void *pc) { struct obj_9a90 *ob; unsigned lo; struct obj_9a90 *new_var; unsigned hi; for (ob = D_00631AF8_2D9A90[0]; ob; ob = ob->next) { if (ob->pc_begin == 0) { func_002D9950_2D9A90(ob); } if ((pc >= ob->pc_begin) && (pc < ob->pc_end)) { break; } }  new_var = ob; if (new_var == 0) { return 0; } for (lo = 0, hi = ob->count; lo < hi;) { unsigned i = (lo + hi) / 2; struct fde_9a90 *f = ob->fde_array[i]; if (pc < f->pc_begin) { hi = i; } else if (pc >= (f->pc_begin + f->pc_range)) { lo = i + 1; } else { return f; } }  return 0; }

typedef struct { int sem; int *res; int w8; int wc; } T_2eb200_002EB200;
extern T_2eb200_002EB200 D_00634280_2EB200[] __asm__("D_00634280"); extern char D_00635540_2EB200[] __asm__("D_00635540"); extern char D_00634EC0_2EB200[] __asm__("D_00634EC0"); extern int D_00429918_2EB200[] __asm__("D_00429918");
typedef struct { int a[8]; } S_2eb200_002EB200;
int func_002E95B0_2EB200(int) __asm__("func_002E95B0"); void func_002E96B8_2EB200(void) __asm__("func_002E96B8"); int func_002E58A0_2EB200(void *) __asm__("func_002E58A0"); int func_002E8928_2EB200(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2EB200(int) __asm__("func_002E58B0"); void func_002E95E0_2EB200(void) __asm__("func_002E95E0"); void func_002E58E0_2EB200(int) __asm__("func_002E58E0"); int *func_002E9130_2EB200(void) __asm__("func_002E9130");
// MATCH func_002EB200
int FUN_002eb200(void) { T_2eb200_002EB200 *t = D_00634280_2EB200; S_2eb200_002EB200 s; int res; int sem; int r; int v; int *h; h = func_002E9130_2EB200(); func_002E95B0_2EB200(10); { register int *gp __asm__("$3") = D_00429918_2EB200; register int initialized __asm__("$2") = gp[0]; if (initialized == 0) { func_002E95E0_2EB200(); return -1; } } if (h == 0 || h[1] == 0) { func_002E95E0_2EB200(); return -9; } t->wc = h[0]; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2EB200(&s); t->res = &res; t->sem = sem; t->w8 = 4; r = func_002E8928_2EB200(D_00635540_2EB200, 10, 0, D_00634280_2EB200, 20, D_00634EC0_2EB200, 4, 0, 0); if (r < 0) { func_002E58B0_2EB200(sem); func_002E95E0_2EB200(); return -11; } h[1] = 0; v = *(int *)((unsigned)D_00634EC0_2EB200 | 0x20000000); func_002E95E0_2EB200(); if (v == 0) { func_002E58B0_2EB200(sem); return -11; } func_002E58E0_2EB200(sem); func_002E58B0_2EB200(sem); { int m = -1; return m < res ? 0 : res; } }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_2ce5a8_002CE5A8;
extern T_2ce5a8_002CE5A8 D_0062B9B0_2CE5A8 __asm__("D_0062B9B0"); extern int D_00427DCC_2CE5A8[] __asm__("D_00427DCC"); extern int D_00427DC8_2CE5A8[] __asm__("D_00427DC8"); extern int D_0062B900_2CE5A8[] __asm__("D_0062B900"); extern int D_0062CEC0_2CE5A8[] __asm__("D_0062CEC0"); extern char D_0062B960_2CE5A8[] __asm__("D_0062B960");
int func_002E58F0_2CE5A8(int) __asm__("func_002E58F0"); int func_002E58C0_2CE5A8(int) __asm__("func_002E58C0"); void *func_002DD928_2CE5A8(void *, void *, int) __asm__("func_002DD928"); int func_002E5B20_2CE5A8(int) __asm__("func_002E5B20");
int func_002E8928_2CE5A8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE5A8
int FUN_002ce5a8(int a, int b, char *name, char *name2) { int r; char *p; if (func_002E58F0_2CE5A8(D_00427DCC_2CE5A8[0]) < 0) return -200; if (D_0062B900_2CE5A8[9] == 0) { func_002E58C0_2CE5A8(D_00427DCC_2CE5A8[0]); return -100; } if (name == 0 || *name == 0 || name2 == 0) { func_002E58C0_2CE5A8(D_00427DCC_2CE5A8[0]); return -210; } D_0062B9B0_2CE5A8.a0 = a; D_0062B9B0_2CE5A8.a4 = b; D_0062B9B0_2CE5A8.a8 = 16; func_002DD928_2CE5A8(D_0062B9B0_2CE5A8.name, name, 1023); D_0062B9B0_2CE5A8.name[1023] = 0; p = D_0062B960_2CE5A8; func_002DD928_2CE5A8(p, name2, 32); p -= 32; { register int zero __asm__("$4") = 0; __asm__ volatile ("" : "+r"(zero)); D_0062B9B0_2CE5A8.a16 = (int)p; __asm__ volatile ("" : : "m"(D_0062B9B0_2CE5A8.a16)); p[63] = 0; func_002E5B20_2CE5A8(zero); } r = func_002E8928_2CE5A8(D_0062B900_2CE5A8, 14, 1, &D_0062B9B0_2CE5A8, 1044, D_0062CEC0_2CE5A8, 4, 0, 0); if (r == 0) D_00427DC8_2CE5A8[0] = 19; else func_002E58C0_2CE5A8(D_00427DCC_2CE5A8[0]); return r; }

typedef struct { int sem; int *res; int w8; int wc; int w16; } T_2e9bd8_002E9BD8_2E9BD8;
extern T_2e9bd8_002E9BD8_2E9BD8 D_00634280_2E9BD8[] __asm__("D_00634280"); extern char D_00635540_2E9BD8[] __asm__("D_00635540"); extern char D_00634EC0_2E9BD8[] __asm__("D_00634EC0"); extern int D_00429918_2E9BD8[] __asm__("D_00429918"); extern char D_00635340_2E9BD8[] __asm__("D_00635340");
typedef struct { int a[8]; } S_2e9bd8_002E9BD8_2E9BD8;
int func_002E95B0_2E9BD8(int) __asm__("func_002E95B0"); void func_002E96B8_2E9BD8(void) __asm__("func_002E96B8"); int func_002E58A0_2E9BD8(void *) __asm__("func_002E58A0"); int func_002E8928_2E9BD8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E58B0_2E9BD8(int) __asm__("func_002E58B0"); void func_002E95E0_2E9BD8(void) __asm__("func_002E95E0"); void func_002E58E0_2E9BD8(int) __asm__("func_002E58E0"); int *func_002E9130_2E9BD8(void) __asm__("func_002E9130");
// MATCH func_002E9BD8
int FUN_002e9bd8(void) { T_2e9bd8_002E9BD8_2E9BD8 *t = D_00634280_2E9BD8; S_2e9bd8_002E9BD8_2E9BD8 s; int res; int sem; int r; register int v __asm__("$2"); int v2; int *h; h = func_002E9130_2E9BD8(); func_002E95B0_2E9BD8(1); v = D_00429918_2E9BD8[0]; if (v == 0) { func_002E95E0_2E9BD8(); return -1; } if (h == 0 || h[1] == 0) { func_002E95E0_2E9BD8(); return -9; } t->wc = h[0]; t->w16 = ((char *)h - D_00635340_2E9BD8) >> 4; s.a[2] = 0; s.a[1] = 1; s.a[5] = 0; sem = func_002E58A0_2E9BD8(&s); t->res = &res; t->sem = sem; t->w8 = 4; r = func_002E8928_2E9BD8(D_00635540_2E9BD8, 1, 0, D_00634280_2E9BD8, 20, D_00634EC0_2E9BD8, 4, 0, 0); if (r < 0) { func_002E58B0_2E9BD8(sem); func_002E95E0_2E9BD8(); return -11; } h[1] = 0; v2 = *(int *)((unsigned)D_00634EC0_2E9BD8 | 0x20000000); func_002E95E0_2E9BD8(); if (v2 == 0) { func_002E58B0_2E9BD8(sem); return -11; } func_002E58E0_2E9BD8(sem); func_002E58B0_2E9BD8(sem); { int m = -1; return m < res ? 0 : res; } }

extern int D_00429880_002E6678[] __asm__("D_00429880"), D_00631F00_002E6678[] __asm__("D_00631F00"); extern char D_00631B00_002E6678[] __asm__("D_00631B00"), D_004A7C70_002E6678[] __asm__("D_004A7C70"); extern int D_00631F08_002E6678[] __asm__("D_00631F08");
void func_002E65A0_002E6678(unsigned *) __asm__("func_002E65A0"); int func_002E58A0_002E6678(void *) __asm__("func_002E58A0"); int func_002E56A0_002E6678(void *) __asm__("func_002E56A0"); int func_002E58B0_002E6678(int) __asm__("func_002E58B0"); int func_002E56C0_002E6678(int, void *) __asm__("func_002E56C0"); int func_002E5790_002E6678(void) __asm__("func_002E5790"); int func_002E5730_002E6678(int, int) __asm__("func_002E5730");
typedef struct {int a[12];} Thread; typedef struct {int a[8];} Sema;
// MATCH func_002E6678
int FUN_002e6678(void) { Thread t; Sema s; int id; if(D_00429880_002E6678[0] > 0) return -1; s.a[2]=0; s.a[1]=255; if ((D_00631F00_002E6678[0]=func_002E58A0_002E6678(&s))<0) return -1; t.a[1]=(int)func_002E65A0_002E6678; t.a[2]=(int)D_00631B00_002E6678; t.a[3]=1024; t.a[4]=(int)D_004A7C70_002E6678; t.a[5]=0; id=func_002E56A0_002E6678(&t); D_00429880_002E6678[0]=id; if(id<0) { func_002E58B0_002E6678(D_00631F00_002E6678[0]); return -1; } D_00631F08_002E6678[0]=0; D_00631F08_002E6678[1]=0; func_002E56C0_002E6678(id,D_00631F08_002E6678); func_002E5730_002E6678(func_002E5790_002E6678(),1); return D_00429880_002E6678[0]; }

extern int D_00631F00_002E65A0[] __asm__("D_00631F00"); extern char D_0049F498_002E65A0[] __asm__("D_0049F498");
int func_002E58E0_002E65A0(int) __asm__("func_002E58E0"); int func_002E5750_002E65A0(int) __asm__("func_002E5750"); int func_002E57D0_002E65A0(int) __asm__("func_002E57D0"); int func_002E5810_002E65A0(int) __asm__("func_002E5810"); void func_002E7908_002E65A0(char *) __asm__("func_002E7908");
// MATCH func_002E65A0
void FUN_002e65a0(unsigned *pin) { register unsigned *p __asm__("$17")=pin; unsigned char *rb=(unsigned char*)p+9; for (;;) { unsigned i; unsigned char b; unsigned char *q,*r; func_002E58E0_002E65A0(D_00631F00_002E65A0[0]); i=*p & 0x1ff; { register unsigned ni __asm__("$4")=i+1;  *p=ni; } i=i*2; q=(unsigned char*)p+8; q+=i; r=rb+i; __asm__ volatile("" : "+r"(i) : "r"(q)); b=*q; switch(b) { case 0: {register unsigned char *v __asm__("$3")=r; __asm__ volatile("" : : "r"(v));func_002E57D0_002E65A0(*v);} break; case 1: func_002E5750_002E65A0(*r); break; case 2: {unsigned char *v=rb+i; func_002E5810_002E65A0(*v);} break; default: func_002E7908_002E65A0(D_0049F498_002E65A0); break; } } }

typedef struct { volatile int f0;volatile int f1;volatile int f2;volatile int f3;int f4;int f5;int f6; } C_002E6B88;
extern char D_0049F4C0_002E6B88[] __asm__("D_0049F4C0"),D_0049F4E8_002E6B88[] __asm__("D_0049F4E8"),D_0049F500_002E6B88[] __asm__("D_0049F500"),D_0049F518_002E6B88[] __asm__("D_0049F518");
void func_002E7908_002E6B88(char*,...) __asm__("func_002E7908"); int func_002E69C8_002E6B88(int,char*,unsigned short) __asm__("func_002E69C8"); int func_002E6A00_002E6B88(int,char*,unsigned short) __asm__("func_002E6A00"); void func_002E6B08_002E6B88(int*) __asm__("func_002E6B08");
// MATCH func_002E6B88
void FUN_002e6b88(int op,int lin,C_002E6B88 *p) { register int len __asm__("$16")=lin; int n; char *buf; switch(op) { case 1: case 2: if(len) { if((unsigned)(p->f2+len)>320) func_002E7908_002E6B88(D_0049F4C0_002E6B88); __asm__ volatile("" : : "r"(len));len=func_002E69C8_002E6B88(p->f0,(char*)p->f5+p->f2,(unsigned short)len); if(len<0)func_002E7908_002E6B88(D_0049F4E8_002E6B88); p->f2+=len; } else { buf=(char*)p->f5; for(n=12;n<*(unsigned short*)buf;n++){ *(char*)((int*)p->f6)[3]=((char*)p->f5)[n]; func_002E6B08_002E6B88((int*)p->f6); } p->f2=0; } break; case 3: { register int nr __asm__("$5"); nr=func_002E6A00_002E6B88(p->f0,(char*)p->f4,(unsigned short)p->f1); __asm__ volatile("" : : "r"(nr)); if(nr<0) {func_002E7908_002E6B88(D_0049F500_002E6B88);p->f3=0;}else{p->f4+=nr;p->f1-=nr;}  } break;case 4: if(p->f1)func_002E7908_002E6B88(D_0049F518_002E6B88,p->f1);p->f3=0;break;} }

void func_002E58D0_002E83E8(int) __asm__("func_002E58D0"); void func_002E8358_002E83E8(int) __asm__("func_002E8358");
// MATCH func_002E83E8
void FUN_002e83e8(int *r){unsigned c=r[8];int *q;int s;if(c==0x8000000a)goto ca;if(c>0x8000000a){q=(int*)r[7];goto common;}if(c==0x80000009)goto c9;q=(int*)r[7];goto common;ca:q=(int*)r[7];if(q[7]==0){s=q[2];goto check;}((void(*)(int))q[7])(q[8]);q=(int*)r[7];goto common;c9:q=(int*)r[7];q[9]=r[9];q[5]=r[10];q[6]=r[11];common:s=q[2];check:if(s>=0)func_002E58D0_002E83E8(s);func_002E8358_002E83E8(q[0]);q[0]=0;}

typedef struct { int f0; volatile int f4; char *f8; } Q6e70_002E6E70;
typedef struct { int h, a4, a8, ac; void *p10, *p14; Q6e70_002E6E70 *p18; } G6e70_002E6E70;
extern G6e70_002E6E70 D_00632450_002E6E70 __asm__("D_00632450"); extern Q6e70_002E6E70 *D_00632468_002E6E70[] __asm__("D_00632468");
void func_002E6B48_002E6E70(Q6e70_002E6E70 *) __asm__("func_002E6B48");
// MATCH func_002E6E70
int FUN_002e6e70(char *s, int n) { int i, j; char *p; i = 0; for (; i < n; i = j) { p = s + i; j = i + 1; while (D_00632468_002E6E70[0]->f4 == 0) ; *p = *D_00632450_002E6E70.p18->f8; func_002E6B48_002E6E70(D_00632450_002E6E70.p18); if (*p == '\n' || *p == '\r') return j; } return i; }

typedef struct { volatile int fd;volatile int len;int used;volatile int busy;char *packet;int w20;void *io;} C_002E6D20;
extern C_002E6D20 D_00632450_002E6D20[] __asm__("D_00632450"); extern char D_00632480_002E6D20[] __asm__("D_00632480");
void func_002EDC50_002E6D20(void) __asm__("func_002EDC50");void func_002EDC98_002E6D20(void) __asm__("func_002EDC98");int func_002E6970_002E6D20(int,int) __asm__("func_002E6970");void func_002E69A0_002E6D20(int) __asm__("func_002E69A0");
// MATCH func_002E6D20
int FUN_002e6d20(char *src,int len) { int consumed=0,used=0; char *packet,*d; C_002E6D20 *p=D_00632450_002E6D20; if(D_00632450_002E6D20[0].busy)return -1; func_002EDC50_002E6D20(); packet=(char*)((unsigned)D_00632480_002E6D20|0x20000000);D_00632450_002E6D20[0].busy=1;D_00632450_002E6D20[0].packet=packet; d=packet+12;while(--len!=-1) { if(*src==10){*d++=13;used++;if(used>=256)break;}*d++=*src++;used++;consumed++;if(used>=256)break;}D_00632450_002E6D20[0].len=used+12;*(unsigned short*)packet=D_00632450_002E6D20[0].len;if(func_002E6970_002E6D20(D_00632450_002E6D20[0].fd,packet[7])<0){*(int *)&D_00632450_002E6D20[0].busy=0;func_002EDC98_002E6D20();return -1;}while(D_00632450_002E6D20[0].busy)func_002E69A0_002E6D20(D_00632450_002E6D20[0].fd);func_002EDC98_002E6D20();return consumed; }

void *_malloc_r_002E4DD0(void *, int) __asm__("_malloc_r"); void *memset_002E4DD0(void *, int, unsigned) __asm__("memset");
// MATCH func_002E4DD0
unsigned *FUN_002e4dd0(void *r, int a, int b) {
 unsigned *mem; unsigned csz; unsigned *d;
 mem = (unsigned *)_malloc_r_002E4DD0(r, a * b);
 if (mem == 0) { register int zero __asm__("$2")=0;return (unsigned*)zero; } {
  {unsigned mask=0xfffffffc;unsigned h=mem[-1];csz=(h&mask)-4;}
  if (csz <= 36) {
    d = mem;
    if (csz > 19) {
      *d++ = 0; *d++ = 0;
      if (csz > 27) {
        *d++ = 0; *d++ = 0;
        if (csz > 35) { *d++ = 0; *d++ = 0; }
      }
    }
    *d++ = 0; *d++ = 0; *d = 0;
  } else memset_002E4DD0(mem, 0, csz);
  }
  return mem;
}
