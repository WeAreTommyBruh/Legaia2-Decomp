/* Functions of this report unit, matched by hand. */
#include "../common.h"

int func_002EA200(int, void *, int);
// MATCH func_001A0608
void FUN_001a0608(int fd, char *s) { char crlf[2]; int n = 0; crlf[0] = 13; crlf[1] = 10; if (s[0] != 0) { do { n++; } while (s[n] != 0); } func_002EA200(fd, s, n); func_002EA200(fd, crlf, 2); }

extern int D_0036CAB0_001A0680[] __asm__("D_0036CAB0"); extern int D_00343654_001A0680[] __asm__("D_00343654"); void func_001AF660(int, int); void func_001AE728(int, int); void func_001B4B40(int);
// MATCH func_001A0680
void FUN_001a0680(void) { func_001AF660(D_0036CAB0_001A0680[6], 1); func_001AF660(D_0036CAB0_001A0680[5], 1); func_001AF660(D_0036CAB0_001A0680[4], 1); func_001AF660(D_0036CAB0_001A0680[3], 1); func_001AF660(D_0036CAB0_001A0680[2], 1); func_001AF660(D_0036CAB0_001A0680[1], 1); func_001AF660(D_0036CAB0_001A0680[0], 1); func_001AE728(D_0036CAB0_001A0680[0], 0); D_00343654_001A0680[0] = 2; func_001B4B40(D_0036CAB0_001A0680[0]); }

typedef struct { char c[164]; } B164_001A19B8;
typedef struct { char c[232]; } B232_001A19B8;
extern B164_001A19B8 D_0036D180[]; extern B232_001A19B8 D_0036D930[]; extern int *D_0036CAB0_001A19B8[] __asm__("D_0036CAB0");
// MATCH func_001A19B8
int *FUN_001a19b8(int *p1, int *p2) { int i, n; int buf[4]; int *r; B232_001A19B8 *cur; i = 0; cur = &D_0036D930[*p2]; do { n = i + *p1; if (n == 12) return D_0036CAB0_001A19B8[7]; i++; r = nayuwin2_001ad548(&D_0036D180[n], cur, buf); r[30] = n; D_0036CAB0_001A19B8[n] = r; *p2 += buf[0]; cur += buf[0]; } while (i < 5); *p1 += 5; return 0; }
