#include "../common.h"
typedef struct B { struct B *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B;
typedef struct { int err; } R;
typedef union { double d; unsigned long ll; struct { unsigned lo; unsigned hi; } w; } DU;
extern const double D_0049F490[], D_0049F2A0[], D_0049F368[], D_0049F390[];
void func_002E27F0(R *, B *);
B *func_002E2748(R *, int);
B *func_002E2BC8(R *, int);
B *func_002E2E30(R *, B *, int);
B *func_002E2C00(R *, B *, B *);
B *func_002E2F30(R *, B *, int);
B *func_002E2938(R *, const char *, int, int, unsigned);
int func_002E30A8(B *, B *);
B *func_002E3110(R *, B *, B *);
B *func_002E34B8(R *, double, int *, int *);
double func_002E3638(B *, B *);
double func_002E32A0(double);
void *memcpy(void *, const void *, unsigned);
#define word0(x) ((x).w.hi)
#define word1(x) ((x).w.lo)
#define Exp_mask 0x7ff00000
#define Exp_msk1 0x100000
#define Bndry_mask 0xfffff
#define Bndry_mask1 0xfffff
#define Log2P 1
#define P 53
#define Bias 1023
#define Big0 0x7fefffff
#define Big1 0xffffffff
#define Tiny0 0
#define Tiny1 1
#define LSB 1
#define Ten_pmax 22
#define DBL_DIG 15
#define n_bigtens 5
#define tens D_0049F2A0
#define bigtens D_0049F368
#define tinytens D_0049F390
// MATCH func_002E39A8
double FUN_002e39a8(R *ptr, const char *s00, char **se) {
  int bb2, bb5, bd2, bd5, bbbits, c, dsign, e1, i, j, k, nd, nd0, nf, nz, nz0, sign;
  long e;
  int bbe, bs2;
  const char *s, *s0, *s1;
  double aadj, aadj1, adj;
  DU rv;
  DU rv0;
  long L;
  unsigned y;
  unsigned long z;
  B *bb, *bb1, *bd, *bd0, *bs, *delta;
  sign = nz0 = nz = 0;
  rv.d = 0.;
  for (s = s00;; s++) switch (*s) {
    case '-':
      sign = 1;
    case '+':
      if (*++s != '\0')
        goto break2;
    case 0:
      s = s00;
      goto ret;
    default:
      goto break2;
    case '\t': case '\n': case '\v': case '\f': case '\r': case ' ':
      continue;
    }
break2:
  if (*s == '0') {
    nz0 = 1;
    while (*++s == '0') ;
    if (!*s)
      goto ret;
  }
  s0 = s;
  y = z = 0;
  for (nd = nf = 0; (c = *s) >= '0' && c <= '9'; nd++, s++)
    if (nd < 9)
      y = 10 * y + c - '0';
    else if (nd < 16)
      z = 10 * z + c - '0';
  nd0 = nd;
  if (c == '.') {
    c = *++s;
    if (!nd) {
      for (; c == '0'; c = *++s)
        nz++;
      if (c > '0' && c <= '9') {
        s0 = s;
        nf += nz;
        nz = 0;
        goto have_dig;
      }
      goto dig_done;
    }
    for (; c >= '0' && c <= '9'; c = *++s) {
    have_dig:
      nz++;
      if (c -= '0') {
        nf += nz;
        for (i = 1; i < nz; i++)
          if (nd++ < 9)
            y *= 10;
          else if (nd <= DBL_DIG + 1)
            z *= 10;
        if (nd++ < 9)
          y = 10 * y + c;
        else if (nd <= DBL_DIG + 1)
          z = 10 * z + c;
        nz = 0;
      }
    }
  }
dig_done:
  e = 0;
  if (c == 'e' || c == 'E') {
    if (!nd && !nz && !nz0) {
      s = s00;
      goto ret;
    }
    s00 = s;
    i = 0;
    switch (c = *++s) {
    case '-':
      i = 1;
    case '+':
      c = *++s;
    }
    if (c >= '0' && c <= '9') {
      while (c == '0')
        c = *++s;
      if (c > '0' && c <= '9') {
        e = c - '0';
        s1 = s;
        while ((c = *++s) >= '0' && c <= '9')
          e = 10 * e + c - '0';
        if (s - s1 > 8)
          e = 9999999;
        if (i)
          e = -e;
      } else
        e = 0;
    } else
      s = s00;
  }
  if (!nd) {
    if (!nz && !nz0)
      s = s00;
    goto ret;
  }
  e1 = e -= nf;
  if (!nd0)
    nd0 = nd;
  k = nd < DBL_DIG + 1 ? nd : DBL_DIG + 1;
  rv.d = y;
  if (k > 9)
    rv.d = tens[k - 9] * rv.d + z;
  bd0 = 0;
  if (nd <= DBL_DIG) {
    if (!e)
      goto ret;
    if (e > 0) {
      if (e <= Ten_pmax) {
        rv.d *= tens[e];
        goto ret;
      }
      i = DBL_DIG - nd;
      if (e <= Ten_pmax + i) {
        e -= i;
        rv.d *= tens[i];
        rv.d *= tens[e];
        goto ret;
      }
    } else if (e >= -Ten_pmax) {
      rv.d /= tens[-e];
      goto ret;
    }
  }
  e1 += nd - k;
  if (e1 > 0) {
    if ((i = e1 & 15))
      rv.d *= tens[i];
    if (e1 &= ~15) {
      if (e1 > 308) {
      ovfl:
        ptr->err = 34;
        rv.d = D_0049F490[0];
        if (bd0)
          goto retfree;
        goto ret;
      }
      if (e1 >>= 4) {
        for (j = 0; e1 > 1; j++, e1 >>= 1)
          if (e1 & 1)
            rv.d *= bigtens[j];
        word0 (rv) -= P * Exp_msk1;
        rv.d *= bigtens[j];
        if ((z = word0 (rv) & Exp_mask) > Exp_msk1 * (1024 + Bias - P))
          goto ovfl;
        if (z > Exp_msk1 * (1024 + Bias - 1 - P)) {
          word0 (rv) = Big0;
          word1 (rv) = Big1;
        } else
          word0 (rv) += P * Exp_msk1;
      }
    }
  } else if (e1 < 0) {
    e1 = -e1;
    if ((i = e1 & 15))
      rv.d /= tens[i];
    if (e1 &= ~15) {
      e1 >>= 4;
      if (e1 >= 1 << n_bigtens)
        goto undfl;
      for (j = 0; e1 > 1; j++, e1 >>= 1)
        if (e1 & 1)
          rv.d *= tinytens[j];
      rv0.d = rv.d;
      rv.d *= tinytens[j];
      if (!rv.d) {
        rv.d = 2. * rv0.d;
        rv.d *= tinytens[j];
        if (!rv.d) {
        undfl:
          rv.d = 0.;
          ptr->err = 34;
          if (bd0)
            goto retfree;
          goto ret;
        }
        word0 (rv) = Tiny0;
        word1 (rv) = Tiny1;
      }
    }
  }
  bd0 = func_002E2938 (ptr, s0, nd0, nd, y);
  for (;;) {
    bd = func_002E2748 (ptr, bd0->k);
    memcpy (&bd->sign, &bd0->sign, bd0->wds * sizeof (int) + 2 * sizeof (int));
    bb = func_002E34B8 (ptr, rv.d, &bbe, &bbbits);
    bs = func_002E2BC8 (ptr, 1);
    if (e >= 0) {
      bb2 = bb5 = 0;
      bd2 = bd5 = e;
    } else {
      bb2 = bb5 = -e;
      bd2 = bd5 = 0;
    }
    if (bbe >= 0)
      bb2 += bbe;
    else
      bd2 -= bbe;
    bs2 = bb2;
    i = bbe + bbbits - 1;
    if (i < -1022)
      j = bbe + (P - -1022);
    else
      j = P + 1 - bbbits;
    bb2 += j;
    bd2 += j;
    i = bb2 < bd2 ? bb2 : bd2;
    if (i > bs2)
      i = bs2;
    if (i > 0) {
      bb2 -= i;
      bd2 -= i;
      bs2 -= i;
    }
    if (bb5 > 0) {
      bs = func_002E2E30 (ptr, bs, bb5);
      bb1 = func_002E2C00 (ptr, bs, bb);
      func_002E27F0 (ptr, bb);
      bb = bb1;
    }
    if (bb2 > 0)
      bb = func_002E2F30 (ptr, bb, bb2);
    if (bd5 > 0)
      bd = func_002E2E30 (ptr, bd, bd5);
    if (bd2 > 0)
      bd = func_002E2F30 (ptr, bd, bd2);
    if (bs2 > 0)
      bs = func_002E2F30 (ptr, bs, bs2);
    delta = func_002E3110 (ptr, bb, bd);
    dsign = delta->sign;
    delta->sign = 0;
    i = func_002E30A8 (delta, bs);
    if (i < 0) {
      if (dsign || (rv.ll & 0x000fffffffffffffUL))
        break;
      delta = func_002E2F30 (ptr, delta, Log2P);
      if (func_002E30A8 (delta, bs) > 0)
        goto drop_down;
      break;
    }
    if (i == 0) {
      if (dsign) {
        if ((rv.ll & 0x000fffffffffffffUL) == 0x000fffffffffffffUL) {
          word0 (rv) = (word0 (rv) & Exp_mask) + Exp_msk1;
          word1 (rv) = 0;
          break;
        }
      } else if (!(rv.ll & 0x000fffffffffffffUL)) {
      drop_down:
        L = (word0 (rv) & Exp_mask) - Exp_msk1;
        word0 (rv) = L | Bndry_mask1;
        word1 (rv) = 0xffffffff;
        break;
      }
      if (!(word1 (rv) & LSB))
        break;
      if (dsign)
        rv.d += func_002E32A0 (rv.d);
      else {
        rv.d -= func_002E32A0 (rv.d);
        if (!rv.d)
          goto undfl;
      }
      break;
    }
    if ((aadj = func_002E3638 (delta, bs)) <= 2.) {
      if (dsign)
        aadj = aadj1 = 1.;
      else if (word1 (rv) || word0 (rv) & Bndry_mask) {
        if (word1 (rv) == Tiny1 && !word0 (rv))
          goto undfl;
        aadj = 1.;
        aadj1 = -1.;
      } else {
        if (aadj < 2. / 2)
          aadj = 1. / 2;
        else
          aadj *= 0.5;
        aadj1 = -aadj;
      }
    } else {
      aadj *= 0.5;
      aadj1 = dsign ? aadj : -aadj;
    }
    y = word0 (rv) & Exp_mask;
    if (y == Exp_msk1 * (1024 + Bias - 1)) {
      rv0.d = rv.d;
      word0 (rv) -= P * Exp_msk1;
      adj = aadj1 * func_002E32A0 (rv.d);
      rv.d += adj;
      if ((word0 (rv) & Exp_mask) >= Exp_msk1 * (1024 + Bias - P)) {
        if (word0 (rv0) == Big0 && word1 (rv0) == Big1)
          goto ovfl;
        word0 (rv) = Big0;
        word1 (rv) = Big1;
        goto cont;
      } else
        word0 (rv) += P * Exp_msk1;
    } else {
      if (y <= (P - 1) * Exp_msk1 && aadj >= 1.) {
        aadj1 = (double) (int) (aadj + 0.5);
        if (!dsign)
          aadj1 = -aadj1;
      }
      adj = aadj1 * func_002E32A0 (rv.d);
      rv.d += adj;
    }
    z = word0 (rv) & Exp_mask;
    if (y == z) {
      L = aadj;
      aadj -= L;
      if (dsign || (rv.ll & 0x000fffffffffffffUL)) {
        if (aadj < .4999999 || aadj > .5000001)
          break;
      } else if (aadj < .4999999 / 2)
        break;
    }
  cont:
    func_002E27F0 (ptr, bb);
    func_002E27F0 (ptr, bd);
    func_002E27F0 (ptr, bs);
    func_002E27F0 (ptr, delta);
  }
retfree:
  func_002E27F0 (ptr, bb);
  func_002E27F0 (ptr, bd);
  func_002E27F0 (ptr, bs);
  func_002E27F0 (ptr, bd0);
  func_002E27F0 (ptr, delta);
ret:
  if (se)
    *se = (char *) s;
  return sign ? -rv.d : rv.d;
}
