/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct B_2E0728 { struct B_2E0728 *next; int k; int maxwds; int sign; int wds; unsigned x[1]; } B_2E0728;
typedef struct { char pad[64]; B_2E0728 *result; int result_k; } R_2E0728;
typedef union { double d; struct { unsigned lo; unsigned hi; } w; } DU_2E0728;
extern const double D_0049F2A0_2E0728[] __asm__("D_0049F2A0"), D_0049F368_2E0728[] __asm__("D_0049F368");
extern char D_0049F1F0[], D_0049F200[], D_0049F208[];
void func_002E27F0_2E0728(R_2E0728 *, B_2E0728 *) __asm__("func_002E27F0");
B_2E0728 *func_002E2748_2E0728(R_2E0728 *, int) __asm__("func_002E2748");
B_2E0728 *func_002E2BC8_2E0728(R_2E0728 *, int) __asm__("func_002E2BC8");
B_2E0728 *func_002E2E30_2E0728(R_2E0728 *, B_2E0728 *, int) __asm__("func_002E2E30");
B_2E0728 *func_002E2C00_2E0728(R_2E0728 *, B_2E0728 *, B_2E0728 *) __asm__("func_002E2C00");
B_2E0728 *func_002E2820_2E0728(R_2E0728 *, B_2E0728 *, int, int) __asm__("func_002E2820");
B_2E0728 *func_002E2F30_2E0728(R_2E0728 *, B_2E0728 *, int) __asm__("func_002E2F30");
int func_002E30A8_2E0728(B_2E0728 *, B_2E0728 *) __asm__("func_002E30A8");
B_2E0728 *func_002E3110_2E0728(R_2E0728 *, B_2E0728 *, B_2E0728 *) __asm__("func_002E3110");
int func_002E0510_2E0728(B_2E0728 *, B_2E0728 *) __asm__("func_002E0510");
B_2E0728 *func_002E34B8_2E0728(R_2E0728 *, double, int *, int *) __asm__("func_002E34B8");
int func_002E2A80_2E0728(unsigned) __asm__("func_002E2A80");
void *memcpy(void *, const void *, unsigned);
#define word0(x) ((x).w.hi)
#define word1(x) ((x).w.lo)
#define dval(x) ((x).d)
#define Sign_bit 0x80000000
#define Exp_mask 0x7ff00000
#define Exp_shift1 20
#define Exp_msk1 0x100000
#define Frac_mask1 0xfffff
#define Exp_11 0x3ff00000
#define Bias 1023
#define DTP 53
#define Bndry_mask 0xfffff
#define Log2P 1
#define Ten_pmax 22
#define Quick_max 14
#define Int_max 14
#define Bletch 0x10
#define n_bigtens 5
#define tens D_0049F2A0_2E0728
#define bigtens D_0049F368_2E0728
// MATCH func_002E0728
char *FUN_002e0728(R_2E0728 *ptr, double _d, int mode, int ndigits, int *decpt, int *sign, char **rve) {
  int bbits, b2, b5, be, dig, i, ieps, ilim, ilim0, ilim1, j, j1, k, k0, k_check, leftright, m2, m5, s2, s5, spec_case, try_quick;
  int L;
  int denorm;
  unsigned x;
  B_2E0728 *b, *b1, *delta, *mlo, *mhi, *S;
  DU_2E0728 d, d2, eps;
  double ds;
  char *s, *s0;
  d.d = _d;
  if (ptr->result) {
    ptr->result->k = ptr->result_k;
    ptr->result->maxwds = 1 << ptr->result_k;
    func_002E27F0_2E0728 (ptr, ptr->result);
    ptr->result = 0;
  }
  if (word0 (d) & Sign_bit) {
    *sign = 1;
    word0 (d) &= ~Sign_bit;
  } else
    *sign = 0;
  if ((word0 (d) & Exp_mask) == Exp_mask) {
    *decpt = 9999;
    s = !word1 (d) && !(word0 (d) & 0xfffff) ? D_0049F1F0 : D_0049F200;
    if (rve)
      *rve = s[3] ? s + 8 : s + 3;
    return s;
  }
  if (!dval (d)) {
    *decpt = 1;
    s = D_0049F208;
    if (rve)
      *rve = s + 1;
    return s;
  }
  b = func_002E34B8_2E0728 (ptr, dval (d), &be, &bbits);
  if ((i = (int) (word0 (d) >> Exp_shift1 & (Exp_mask >> Exp_shift1)))) {
    dval (d2) = dval (d);
    word0 (d2) &= Frac_mask1;
    word0 (d2) |= Exp_11;
    i -= Bias;
    denorm = 0;
  } else {
    i = bbits + be + (Bias + (DTP - 1) - 1);
    x = i > 32 ? word0 (d) << (64 - i) | word1 (d) >> (i - 32) : word1 (d) << (32 - i);
    dval (d2) = x;
    word0 (d2) -= 31 * Exp_msk1;
    i -= (Bias + (DTP - 1) - 1) + 1;
    denorm = 1;
  }
  ds = (dval (d2) - 1.5) * 0.289529654602168 + 0.1760912590558 + i * 0.301029995663981;
  k = (int) ds;
  if (ds < 0. && ds != k)
    k--;
  k_check = 1;
  if (k >= 0 && k <= Ten_pmax) {
    if (dval (d) < tens[k])
      k--;
    k_check = 0;
  }
  j = bbits - i - 1;
  if (j >= 0) {
    b2 = 0;
    s2 = j;
  } else {
    b2 = -j;
    s2 = 0;
  }
  if (k >= 0) {
    b5 = 0;
    s5 = k;
    s2 += k;
  } else {
    b2 -= k;
    b5 = -k;
    s5 = 0;
  }
  if (mode < 0 || mode > 9)
    mode = 0;
  try_quick = 1;
  if (mode > 5) {
    mode -= 4;
    try_quick = 0;
  }
  leftright = 1;
  switch (mode) {
  case 0:
  case 1:
    ilim = ilim1 = -1;
    i = 18;
    ndigits = 0;
    break;
  case 2:
    leftright = 0;
  case 4:
    if (ndigits <= 0)
      ndigits = 1;
    ilim = ilim1 = i = ndigits;
    break;
  case 3:
    leftright = 0;
  case 5:
    i = ndigits + k + 1;
    ilim = i;
    ilim1 = i - 1;
    if (i <= 0)
      i = 1;
  }
  j = 4;
  for (ptr->result_k = 0; 20u + j <= i; j <<= 1)
    ptr->result_k++;
  ptr->result = func_002E2748_2E0728 (ptr, ptr->result_k);
  s = s0 = (char *) ptr->result;
  if (ilim >= 0 && ilim <= Quick_max && try_quick) {
    i = 0;
    dval (d2) = dval (d);
    k0 = k;
    ilim0 = ilim;
    ieps = 2;
    if (k > 0) {
      ds = tens[k & 0xf];
      j = k >> 4;
      if (j & Bletch) {
        j &= Bletch - 1;
        dval (d) /= bigtens[n_bigtens - 1];
        ieps++;
      }
      for (; j; j >>= 1, i++)
        if (j & 1) {
          ieps++;
          ds *= bigtens[i];
        }
      dval (d) /= ds;
    } else if ((j1 = -k)) {
      dval (d) *= tens[j1 & 0xf];
      for (j = j1 >> 4; j; j >>= 1, i++)
        if (j & 1) {
          ieps++;
          dval (d) *= bigtens[i];
        }
    }
    if (k_check && dval (d) < 1. && ilim > 0) {
      if (ilim1 <= 0)
        goto fast_failed;
      ilim = ilim1;
      k--;
      dval (d) *= 10.;
      ieps++;
    }
    dval (eps) = ieps * dval (d) + 7.;
    word0 (eps) -= (DTP - 1) * Exp_msk1;
    if (ilim == 0) {
      S = mhi = 0;
      dval (d) -= 5.;
      if (dval (d) > dval (eps))
        goto one_digit;
      if (dval (d) < -dval (eps))
        goto no_digits;
      goto fast_failed;
    }
    if (leftright) {
      dval (eps) = 0.5 / tens[ilim - 1] - dval (eps);
      for (i = 0;;) {
        L = dval (d);
        dval (d) -= L;
        *s++ = '0' + (int) L;
        if (dval (d) < dval (eps))
          goto ret1;
        if (1. - dval (d) < dval (eps))
          goto bump_up;
        if (++i >= ilim)
          break;
        dval (eps) *= 10.;
        dval (d) *= 10.;
      }
    } else {
      dval (eps) *= tens[ilim - 1];
      for (i = 1;; i++, dval (d) *= 10.) {
        L = (int) (dval (d));
        dval (d) -= L;
        *s++ = '0' + (int) L;
        if (i == ilim) {
          if (dval (d) > 0.5 + dval (eps))
            goto bump_up;
          else if (dval (d) < 0.5 - dval (eps)) {
            while (*--s == '0');
            s++;
            goto ret1;
          }
          break;
        }
      }
    }
  fast_failed:
    s = s0;
    dval (d) = dval (d2);
    k = k0;
    ilim = ilim0;
  }
  if (be >= 0 && k <= Int_max) {
    ds = tens[k];
    if (ndigits < 0 && ilim <= 0) {
      S = mhi = 0;
      if (ilim < 0 || dval (d) <= 5 * ds)
        goto no_digits;
      goto one_digit;
    }
    for (i = 1;; i++) {
      L = (int) (dval (d) / ds);
      dval (d) -= L * ds;
      *s++ = '0' + (int) L;
      if (i == ilim) {
        dval (d) += dval (d);
        if (dval (d) > ds || (dval (d) == ds && L & 1)) {
        bump_up:
          while (*--s == '9')
            if (s == s0) {
              k++;
              *s = '0';
              break;
            }
          ++*s++;
        }
        break;
      }
      dval (d) *= 10.;
      if (!dval (d))
        break;
    }
    goto ret1;
  }
  m2 = b2;
  m5 = b5;
  mhi = mlo = 0;
  if (leftright) {
    if (mode < 2) {
      i = denorm ? be + (Bias + (DTP - 1) - 1 + 1) : 1 + DTP - bbits;
    } else {
      j = ilim - 1;
      if (m5 >= j)
        m5 -= j;
      else {
        s5 += j -= m5;
        b5 += j;
        m5 = 0;
      }
      if ((i = ilim) < 0) {
        m2 -= i;
        i = 0;
      }
    }
    b2 += i;
    s2 += i;
    mhi = func_002E2BC8_2E0728 (ptr, 1);
  }
  if (m2 > 0 && s2 > 0) {
    i = m2 < s2 ? m2 : s2;
    b2 -= i;
    m2 -= i;
    s2 -= i;
  }
  if (b5 > 0) {
    if (leftright) {
      if (m5 > 0) {
        mhi = func_002E2E30_2E0728 (ptr, mhi, m5);
        b1 = func_002E2C00_2E0728 (ptr, mhi, b);
        func_002E27F0_2E0728 (ptr, b);
        b = b1;
      }
      if ((j = b5 - m5))
        b = func_002E2E30_2E0728 (ptr, b, j);
    } else
      b = func_002E2E30_2E0728 (ptr, b, b5);
  }
  S = func_002E2BC8_2E0728 (ptr, 1);
  if (s5 > 0)
    S = func_002E2E30_2E0728 (ptr, S, s5);
  if (mode < 2) {
    if (!word1 (d) && !(word0 (d) & Bndry_mask) && word0 (d) & Exp_mask) {
      b2 += Log2P;
      s2 += Log2P;
      spec_case = 1;
    } else
      spec_case = 0;
  }
  if ((i = ((s5 ? 32 - func_002E2A80_2E0728 (S->x[S->wds - 1]) : 1) + s2) & 0x1f))
    i = 32 - i;
  if (i > 4) {
    i -= 4;
    b2 += i;
    m2 += i;
    s2 += i;
  } else if (i < 4) {
    i += 28;
    b2 += i;
    m2 += i;
    s2 += i;
  }
  if (b2 > 0)
    b = func_002E2F30_2E0728 (ptr, b, b2);
  if (s2 > 0)
    S = func_002E2F30_2E0728 (ptr, S, s2);
  if (k_check) {
    if (func_002E30A8_2E0728 (b, S) < 0) {
      k--;
      b = func_002E2820_2E0728 (ptr, b, 10, 0);
      if (leftright)
        mhi = func_002E2820_2E0728 (ptr, mhi, 10, 0);
      ilim = ilim1;
    }
  }
  if (ilim <= 0 && mode > 2) {
    if (ilim < 0 || func_002E30A8_2E0728 (b, S = func_002E2820_2E0728 (ptr, S, 5, 0)) <= 0) {
    no_digits:
      k = -1 - ndigits;
      goto ret;
    }
  one_digit:
    *s++ = '1';
    k++;
    goto ret;
  }
  if (leftright) {
    if (m2 > 0)
      mhi = func_002E2F30_2E0728 (ptr, mhi, m2);
    mlo = mhi;
    if (spec_case) {
      mhi = func_002E2748_2E0728 (ptr, mhi->k);
      memcpy (&mhi->sign, &mlo->sign, mlo->wds * sizeof (int) + 2 * sizeof (int));
      mhi = func_002E2F30_2E0728 (ptr, mhi, Log2P);
    }
    for (i = 1;; i++) {
      dig = func_002E0510_2E0728 (b, S) + '0';
      j = func_002E30A8_2E0728 (b, mlo);
      delta = func_002E3110_2E0728 (ptr, S, mhi);
      j1 = delta->sign ? 1 : func_002E30A8_2E0728 (b, delta);
      func_002E27F0_2E0728 (ptr, delta);
      if (j1 == 0 && !mode && !(word1 (d) & 1)) {
        if (dig == '9')
          goto round_9_up;
        if (j > 0)
          dig++;
        *s++ = dig;
        goto ret;
      }
      if (j < 0 || (j == 0 && !mode && !(word1 (d) & 1))) {
        if (j1 > 0) {
          b = func_002E2F30_2E0728 (ptr, b, 1);
          j1 = func_002E30A8_2E0728 (b, S);
          if ((j1 > 0 || (j1 == 0 && dig & 1)) && dig++ == '9')
            goto round_9_up;
        }
        *s++ = dig;
        goto ret;
      }
      if (j1 > 0) {
        if (dig == '9') {
        round_9_up:
          *s++ = '9';
          goto roundoff;
        }
        *s++ = dig + 1;
        goto ret;
      }
      *s++ = dig;
      if (i == ilim)
        break;
      b = func_002E2820_2E0728 (ptr, b, 10, 0);
      if (mlo == mhi)
        mlo = mhi = func_002E2820_2E0728 (ptr, mhi, 10, 0);
      else {
        mlo = func_002E2820_2E0728 (ptr, mlo, 10, 0);
        mhi = func_002E2820_2E0728 (ptr, mhi, 10, 0);
      }
    }
  } else
    for (i = 1;; i++) {
      *s++ = dig = func_002E0510_2E0728 (b, S) + '0';
      if (i >= ilim)
        break;
      b = func_002E2820_2E0728 (ptr, b, 10, 0);
    }
  b = func_002E2F30_2E0728 (ptr, b, 1);
  j = func_002E30A8_2E0728 (b, S);
  if (j > 0 || (j == 0 && dig & 1)) {
  roundoff:
    while (*--s == '9')
      if (s == s0) {
        k++;
        *s++ = '1';
        goto ret;
      }
    ++*s++;
  } else {
    while (*--s == '0');
    s++;
  }
ret:
  func_002E27F0_2E0728 (ptr, S);
  if (mhi) {
    if (mlo && mlo != mhi)
      func_002E27F0_2E0728 (ptr, mlo);
    func_002E27F0_2E0728 (ptr, mhi);
  }
ret1:
  func_002E27F0_2E0728 (ptr, b);
  *s = 0;
  *decpt = k + 1;
  if (rve)
    *rve = s;
  return s0;
}
#undef word0
#undef word1
#undef dval
#undef Sign_bit
#undef Exp_mask
#undef Exp_shift1
#undef Exp_msk1
#undef Frac_mask1
#undef Exp_11
#undef Bias
#undef DTP
#undef Bndry_mask
#undef Log2P
#undef Ten_pmax
#undef Quick_max
#undef Int_max
#undef Bletch
#undef n_bigtens
#undef tens
#undef bigtens
