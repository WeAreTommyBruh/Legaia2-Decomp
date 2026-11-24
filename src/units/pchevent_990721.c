/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B598;
extern char D_00455618[], D_00454D80[]; int func_001621F8(int, char *, int); void func_00108B80(void *);
// MATCH func_0020B598
void pchevent_0020b598(O_0020B598 *o, int fl) { int i; o->vt = D_00455618; if (o->w12 != 0) { for (i = 0; i < o->w4; i++) { if (o->w12[i] != 0) func_001621F8(o->w12[i], D_00454D80, 117); } func_001621F8((int)o->w12, D_00454D80, 118); } if (fl & 1) func_00108B80(o); }

extern int D_004A45E8_20DBB8 __asm__("D_004A45E8"), D_004A1444_20DBB8 __asm__("D_004A1444"), D_004A140C_0020DBB8 __asm__("D_004A140C"), D_004A46C8_20DBB8 __asm__("D_004A46C8"), D_004A1430_20DBB8 __asm__("D_004A1430"), D_004A1434_20DBB8 __asm__("D_004A1434"); extern char D_00455098_20DBB8[] __asm__("D_00455098"), D_00455088_20DBB8[] __asm__("D_00455088");
void *func_0020BBD8_20DBB8(int) __asm__("func_0020BBD8"); void func_0029F868_20DBB8(int, int, int) __asm__("func_0029F868"); int func_00213258_20DBB8(int, int, int) __asm__("func_00213258"); void func_00239568_20DBB8(char *, int, int, int, int, ...) __asm__("func_00239568");
// MATCH func_0020DBB8
void pchevent_0020dbb8(int p) { int *q; int v, m, x; q = func_0020BBD8_20DBB8(D_004A45E8_20DBB8); if (q == 0) return; if (p != 0 && D_004A1444_20DBB8 == 0 && (D_004A140C_0020DBB8 & 0xc) != 0 && q[119] != 0) func_0029F868_20DBB8(q[119], q[0], D_004A46C8_20DBB8); v = 0xa0a0a0; if (p != 0 && D_004A1444_20DBB8 == 0) v = 0xc0c0; m = *(int *)(q[0] + 152); if (m != 0) { x = D_004A1430_20DBB8 + 6; func_00239568_20DBB8(D_00455088_20DBB8, x, D_004A1434_20DBB8, v, D_004A46C8_20DBB8, func_00213258_20DBB8(m, *(short *)(q[0] + 188), D_004A46C8_20DBB8)); return; } func_00239568_20DBB8(D_00455098_20DBB8, D_004A1430_20DBB8 + 6, D_004A1434_20DBB8, v, D_004A46C8_20DBB8); }

extern int D_004A45E8_0020DCD8 __asm__("D_004A45E8"), D_004A1444_0020DCD8 __asm__("D_004A1444"), D_004A140C_0020DCD8 __asm__("D_004A140C"), D_004A46CC_20DCD8 __asm__("D_004A46CC"), D_004A1430_0020DCD8 __asm__("D_004A1430"), D_004A1434_0020DCD8 __asm__("D_004A1434"); extern char D_00455098_0020DCD8[] __asm__("D_00455098"), D_00455088_0020DCD8[] __asm__("D_00455088");
void *func_0020BBD8_20DCD8(int) __asm__("func_0020BBD8"); void func_0029F8D8_20DCD8(int, int, int) __asm__("func_0029F8D8"); int func_00213258_20DCD8(int, int, int) __asm__("func_00213258"); void func_00239568_20DCD8(char *, int, int, int, int, ...) __asm__("func_00239568");
// MATCH func_0020DCD8
void pchevent_0020dcd8(int p) { int *q; int v, m, x; q = func_0020BBD8_20DCD8(D_004A45E8_0020DCD8); if (q == 0) return; if (p != 0 && D_004A1444_0020DCD8 == 0 && (D_004A140C_0020DCD8 & 0xc) != 0 && q[119] != 0) func_0029F8D8_20DCD8(q[119], q[0], D_004A46CC_20DCD8); v = 0xa0a0a0; if (p != 0 && D_004A1444_0020DCD8 == 0) v = 0xc0c0; m = *(int *)(q[0] + 152); if (m != 0) { x = D_004A1430_0020DCD8 + 6; func_00239568_20DCD8(D_00455088_0020DCD8, x, D_004A1434_0020DCD8, v, D_004A46CC_20DCD8, func_00213258_20DCD8(m, *(short *)(q[0] + 188), D_004A46CC_20DCD8)); return; } func_00239568_20DCD8(D_00455098_0020DCD8, D_004A1430_0020DCD8 + 6, D_004A1434_0020DCD8, v, D_004A46CC_20DCD8); }


typedef struct { char p0[500]; int w500; char p504[72]; int w576; } O_20BEB8;
extern int D_004A45E8, D_004A45F0, D_004A1444, D_004A4660, D_004A1430, D_004A1434, D_004A140C; extern int *D_004A4668; extern long long D_004A12F0, D_004A1300;
extern int *D_003C0FB8[]; extern char D_004A48C0[];
O_20BEB8 *func_0020BBD8(int); void func_00239568(char *, int, int, int, int); void func_00159220(int);

// MATCH func_0020BEB8
int pchevent_0020beb8(int f)
{
  O_20BEB8 *p, *q; int i;
  p = func_0020BBD8(D_004A45E8);
  D_003C0FB8[0] = p != 0 ? &p->w500 : &D_004A45F0;
  if (p == 0) goto done;
  if (f != 0 && D_004A1444 == 0 && (D_004A12F0 & 0x80) && (D_004A1300 & 0x20)) {
    for (i = 0; i < D_004A4660; i++) {
      q = func_0020BBD8(i);
      if (q != 0) q->w500 = -1;
    }
  }
  func_00239568(D_004A48C0, D_004A1430 + 6, D_004A1434, f != 0 ? 0xffff : 0x808080, D_004A4668[p->w500 + 1]);
  if (f != 0 && D_004A1444 == 0 && (D_004A140C & 0xc)) func_00159220(p->w576);
done:
  return 0;
}


typedef struct { char c[3]; } S3_0020BA70;
extern char D_004A45E0_20BA70[] __asm__("D_004A45E0");
extern char D_00454D80_20BA70[] __asm__("D_00454D80");
extern int func_002DD5E0_20BA70(char *) __asm__("func_002DD5E0");
void *func_00162130_20BA70(int, void *, int) __asm__("func_00162130");
void *func_002DD4CC_20BA70(void *, void *) __asm__("func_002DD4CC");
extern int func_0018B998_20BA70(int, char *, int) __asm__("func_0018B998");
// MATCH func_0020BA70
int pchevent_0020ba70(int *o, int a) { int i, j, n; char *buf, *d; if (o[3] == 0) return 0; n = 0; for (i = 0; i < o[1]; i++) { if (((char **)o[3])[i] != 0) n = n + func_002DD5E0_20BA70(((char **)o[3])[i]) + 2; } buf = func_00162130_20BA70(n, D_00454D80_20BA70, 226); d = buf; if (buf == 0) return 0; for (j = 0; j < o[1]; j++) { if (((char **)o[3])[j] != 0) { func_002DD4CC_20BA70(d, ((char **)o[3])[j]); d += func_002DD5E0_20BA70(((char **)o[3])[j]); *(S3_0020BA70 *)d = *(S3_0020BA70 *)D_004A45E0_20BA70; d += 2; } } return func_0018B998_20BA70(a, buf, n); }

typedef struct { int p0; int n; int cnt; int *a; } A__0020B760;
extern char D_00454D80_20B760[] __asm__("D_00454D80"); int *func_00162130_20B760(int, char *, int) __asm__("func_00162130"); void func_001621F8_20B760(void *, char *, int) __asm__("func_001621F8");
// MATCH func_0020B760
void pchevent_0020b760(A__0020B760 *o, int m) { int i; int *p; int n; if (o->a != 0 && o->n <= m && (p = func_00162130_20B760(m << 2, D_00454D80_20B760, 153)) != 0) { n = o->n; for (i = 0; i < n; i++) p[i] = o->a[i]; for (; i < m; i++) p[i] = 0; func_001621F8_20B760(o->a, D_00454D80_20B760, 158); o->a = p; o->n = m; } }

typedef struct { int n0; int n; int cnt; int *a; } A__0020B660;
extern char D_00454D80_0020B660[] __asm__("D_00454D80"); int *func_00162130_20B660(int, char *, int) __asm__("func_00162130"); void func_001621F8_20B660(void *, char *, int) __asm__("func_001621F8");
// MATCH func_0020B660
void pchevent_0020b660(A__0020B660 *o) { int i; int *p; int n; int j; if (o->a != 0) { o->cnt = 0; for (i = 0; i < o->n; i++) { if (o->a[i] != 0) { func_001621F8_20B660((void *)o->a[i], D_00454D80_0020B660, 132); o->a[i] = 0; } } if (o->n0 != o->n) { func_001621F8_20B660(o->a, D_00454D80_0020B660, 140); o->n = o->n0; p = func_00162130_20B660(o->n0 << 2, D_00454D80_0020B660, 142); o->a = p; n = o->n; for (j = 0; j < n; j++) p[j] = 0; } } }
