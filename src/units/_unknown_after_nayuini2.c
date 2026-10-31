/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char c[164]; } B164_001AA160;
typedef struct { char c[232]; } B232_001AA160;
extern B164_001AA160 D_0039C590[]; extern B232_001AA160 D_0039CFD0[]; extern int *D_0036CAB0_001AA160[] __asm__("D_0036CAB0");
// MATCH func_001AA160
int *FUN_001aa160(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001AA160 *cur; i = 0; cur = &D_0039CFD0[*p2]; do { n = i + *p1; if (n == 16) return D_0036CAB0_001AA160[0]; i++; r = nayuwin2_001ad548(&D_0039C590[n], cur, buf); r[30] = n; D_0036CAB0_001AA160[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 2); *p1 += 2; return 0; }

typedef struct { char c[164]; } B164_001AA270;
typedef struct { char c[232]; } B232_001AA270;
extern B164_001AA270 D_003A0D70[]; extern B232_001AA270 D_003A1290[]; extern int *D_0036CAB0_001AA270[] __asm__("D_0036CAB0");
// MATCH func_001AA270
int *FUN_001aa270(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001AA270 *cur; i = 0; cur = &D_003A1290[*p2]; do { n = i + *p1; if (n == 8) return D_0036CAB0_001AA270[0]; i++; r = nayuwin2_001ad548(&D_003A0D70[n], cur, buf); r[30] = n; D_0036CAB0_001AA270[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 3); *p1 += 3; return 0; }

typedef struct { char c[164]; } B164_001AA420;
typedef struct { char c[232]; } B232_001AA420;
extern B164_001AA420 D_003A5900[]; extern B232_001AA420 D_003A61F8[]; extern int *D_0036CAB0_001AA420[] __asm__("D_0036CAB0");
// MATCH func_001AA420
int *FUN_001aa420(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001AA420 *cur; i = 0; cur = &D_003A61F8[*p2]; do { n = i + *p1; if (n == 14) return D_0036CAB0_001AA420[0]; i++; r = nayuwin2_001ad548(&D_003A5900[n], cur, buf); r[30] = n; D_0036CAB0_001AA420[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 5); *p1 += 5; return 0; }

typedef struct { char c[164]; } B164_001AA050;
typedef struct { char c[232]; } B232_001AA050;
extern B164_001AA050 D_0038B3A8[]; extern B232_001AA050 D_0038B780[]; extern int *D_0036CAB0_001AA050[] __asm__("D_0036CAB0");
// MATCH func_001AA050
int *FUN_001aa050(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001AA050 *cur; i = 0; cur = &D_0038B780[*p2]; do { n = i + *p1; if (n == 6) return D_0036CAB0_001AA050[1]; i++; r = nayuwin2_001ad548(&D_0038B3A8[n], cur, buf); r[30] = n; D_0036CAB0_001AA050[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 5); *p1 += 5; return 0; }

typedef struct { char c[164]; } B164_001A9F20;
typedef struct { char c[232]; } B232_001A9F20;
extern B164_001A9F20 D_00376FF8[]; extern B232_001A9F20 D_00379290[]; extern int *D_0036CAB0_001A9F20[] __asm__("D_0036CAB0"); extern int D_004A12A4_001A9F20 __asm__("D_004A12A4"); extern char D_004A3C5C; extern unsigned D_00425514[];
// MATCH func_001A9F20
int *FUN_001a9f20(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001A9F20 *cur; if (D_004A12A4_001A9F20 != 17) { unsigned m; m = D_00425514[0] & 0x10000000; D_004A3C5C = m != 0; } i = 0; cur = &D_00379290[*p2]; do { n = i + *p1; if (n == 54) return D_0036CAB0_001A9F20[46]; i++; r = nayuwin2_001ad548(&D_00376FF8[n], cur, buf); r[30] = n; D_0036CAB0_001A9F20[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 5); *p1 += 5; return 0; }
