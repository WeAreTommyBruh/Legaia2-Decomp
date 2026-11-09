/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { unsigned char *p; int r; int w; short flags; short file; unsigned char *base; } F_002DDF40_2DDF40;
struct siov { void *iov_base; int iov_len; };
struct suio { struct siov *iov; int iovcnt; int resid; };
extern char D_0049EB70_2DDF40[] __asm__("D_0049EB70"), D_0049EB80_2DDF40[] __asm__("D_0049EB80"), D_0049EB90_2DDF40[] __asm__("D_0049EB90"), D_0049EB98_2DDF40[] __asm__("D_0049EB98"), D_0049EBA0_2DDF40[] __asm__("D_0049EBA0"), D_0049EBB8_2DDF40[] __asm__("D_0049EBB8"), D_0049EBC0_2DDF40[] __asm__("D_0049EBC0"), D_0049EBD8_2DDF40[] __asm__("D_0049EBD8"), D_0049EBF8_2DDF40[] __asm__("D_0049EBF8"), D_0049EC00_2DDF40[] __asm__("D_0049EC00");
extern int D_00429850_2DDF40[] __asm__("D_00429850");
extern void *D_004293F4_2DDF40[] __asm__("D_004293F4");
extern char **func_002E2450_2DDF40(void) __asm__("func_002E2450");
extern int func_002E2628_2DDF40(void *, int *, const char *, int, int *) __asm__("func_002E2628");
extern int func_002E0388_2DDF40(F_002DDF40_2DDF40 *) __asm__("func_002E0388");
extern int func_002DDE10_2DDF40(F_002DDF40_2DDF40 *, const char *, char *) __asm__("func_002DDE10");
extern int func_002DDDC8_2DDF40(F_002DDF40_2DDF40 *, struct suio *) __asm__("func_002DDDC8");
extern int func_002E3960_2DDF40(double) __asm__("func_002E3960");
extern int func_002D6108_2DDF40(double) __asm__("func_002D6108");
void *func_002DF458_2DDF40(void *, double, int, int, void *, void *, int, void *) __asm__("func_002DF458");
extern int func_002DF608_2DDF40(char *, int, int) __asm__("func_002DF608");
void *func_002E2664_2DDF40(void *, int, int) __asm__("func_002E2664");
extern unsigned strlen(const char *);
#define ALT 0x001
#define HEXPREFIX 0x002
#define LADJUST 0x004
#define LONGDBL 0x008
#define LONGINT 0x010
#define QUADINT 0x020
#define SHORTINT 0x040
#define ZEROPAD 0x080
#define FPT 0x100
#define BUF 348
#define NIOV 8
#define PADSIZE 16
#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n) ((n) + '0')
#define VA(T) (*(T *)((ap += 8) - 8))
#define PRINT(ptr, len) { \
  iovp->iov_base = (ptr); \
  iovp->iov_len = (len); \
  uio.resid += (len); \
  iovp++; \
  if (++uio.iovcnt >= NIOV) { \
    if (func_002DDDC8_2DDF40(fp, &uio)) \
      goto error; \
    iovp = iov; \
  } \
}
#define PAD(howmany, with) { \
  if ((n = (howmany)) > 0) { \
    while (n > PADSIZE) { \
      PRINT (with, PADSIZE); \
      n -= PADSIZE; \
    } \
    PRINT (with, n); \
  } \
}
#define FLUSH() { \
  if (uio.resid && func_002DDDC8_2DDF40(fp, &uio)) \
    goto error; \
  uio.iovcnt = 0; \
  iovp = iov; \
}
// MATCH func_002DDF40
int FUN_002ddf40(void *data, F_002DDF40_2DDF40 *fp, const char *fmt0, char *ap) { char *fmt; register int ch; register int n, m; register char *cp; register struct siov *iovp; register int flags; int ret; int width; int prec; char sign; char *decimal_point = *func_002E2450_2DDF40(); char softsign; double _double; int expt; int expsize; int ndig; char expstr[7]; unsigned long _uquad; enum { OCT, DEC, HEX } base; int dprec; int realsz; int size; char *xdigs; struct suio uio; struct siov iov[NIOV]; char buf[BUF]; char ox[2]; int wc; int state; state = 0; if (((fp->flags & 8) == 0 || fp->base == 0) && func_002E0388_2DDF40(fp)) return (-1); if ((fp->flags & 0x1a) == 0xa && fp->file >= 0) return func_002DDE10_2DDF40(fp, fmt0, ap); fmt = (char *)fmt0; uio.iov = iovp = iov; uio.resid = 0; uio.iovcnt = 0; ret = 0; for (;;) { cp = fmt; while ((n = func_002E2628_2DDF40(D_004293F4_2DDF40[0], &wc, fmt, D_00429850_2DDF40[0], &state)) > 0) { fmt += n; if (wc == '%') { fmt--; break; } } if ((m = fmt - cp) != 0) { PRINT (cp, m); ret += m; } if (n <= 0) goto done; fmt++; flags = 0; dprec = 0; width = 0; prec = -1; sign = '\0'; rflag: ch = (char)*fmt++; reswitch: switch (ch) { case ' ': if (!sign) sign = ' '; goto rflag; case '#': flags |= ALT; goto rflag; case '*': if ((width = VA(int)) >= 0) goto rflag; width = -width; case '-': flags |= LADJUST; goto rflag; case '+': sign = '+'; goto rflag; case '.': if ((ch = *fmt++) == '*') { n = VA(int); prec = n < 0 ? -1 : n; goto rflag; } n = 0; while (is_digit (ch)) { n = 10 * n + to_digit (ch); ch = *fmt++; } prec = n < 0 ? -1 : n; goto reswitch; case '0': flags |= ZEROPAD; goto rflag; case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': n = 0; do { n = 10 * n + to_digit (ch); ch = *fmt++; } while (is_digit (ch)); width = n; goto reswitch; case 'L': flags |= LONGDBL; goto rflag; case 'h': flags |= SHORTINT; goto rflag; case 'l': if (*fmt == 'l') { fmt++; flags |= QUADINT; } else { flags |= LONGINT; } goto rflag; case 'q': flags |= QUADINT; goto rflag; case 'c': *(cp = buf) = VA(int); size = 1; sign = '\0'; break; case 'D': flags |= LONGINT; case 'd': case 'i': _uquad = (flags & LONGINT) ? VA(long) : (long)(flags & SHORTINT ? (short)VA(int) : VA(int)); if ((long)_uquad < 0) { _uquad = -_uquad; sign = '-'; } base = DEC; goto number; case 'e': case 'E': case 'f': case 'g': case 'G': if (prec == -1) { prec = 6; } else if ((ch == 'g' || ch == 'G') && prec == 0) { prec = 1; } if (flags & LONGDBL) _double = (double)VA(long double); else _double = VA(double); if (func_002E3960_2DDF40 (_double)) { if (_double < 0) sign = '-'; cp = D_0049EB90_2DDF40; size = 3; break; } if (func_002D6108_2DDF40 (_double)) { cp = D_0049EB98_2DDF40; size = 3; break; } flags |= FPT; cp = func_002DF458_2DDF40 (data, _double, prec, flags, &softsign, &expt, ch, &ndig); if (ch == 'g' || ch == 'G') { if (expt <= -4 || expt > prec) ch = (ch == 'g') ? 'e' : 'E'; else ch = 'g'; } if (ch <= 'e') { --expt; expsize = func_002DF608_2DDF40 (expstr, expt, ch); size = expsize + ndig; if (ndig > 1 || flags & ALT) ++size; } else if (ch == 'f') { if (expt > 0) { size = expt; if (prec || flags & ALT) size += prec + 1; } else size = prec + 2; } else if (expt >= ndig) { size = expt; if (flags & ALT) ++size; } else size = ndig + (expt > 0 ? 1 : 2 - expt); if (softsign) sign = '-'; break; case 'n': if (flags & LONGINT) *VA(long *) = ret; else if (flags & SHORTINT) *VA(short *) = ret; else *VA(int *) = ret; continue; case 'O': flags |= LONGINT; case 'o': _uquad = (flags & LONGINT) ? VA(unsigned long) : (unsigned long)(flags & SHORTINT ? (unsigned short)VA(int) : VA(unsigned)); base = OCT; goto nosign; case 'p': _uquad = (unsigned long)(long)VA(int); base = HEX; xdigs = D_0049EBA0_2DDF40; flags |= HEXPREFIX; ch = 'x'; goto nosign; case 's': if ((cp = VA(char *)) == 0) cp = D_0049EBB8_2DDF40; if (prec >= 0) { char *p = func_002E2664_2DDF40 (cp, 0, prec); if (p != 0) { size = p - cp; if (size > prec) size = prec; } else size = prec; } else size = strlen (cp); sign = '\0'; break; case 'U': flags |= LONGINT; case 'u': _uquad = (flags & LONGINT) ? VA(unsigned long) : (unsigned long)(flags & SHORTINT ? (unsigned short)VA(int) : VA(unsigned)); base = DEC; goto nosign; case 'X': xdigs = D_0049EBC0_2DDF40; goto hex; case 'x': xdigs = D_0049EBA0_2DDF40; hex: _uquad = (flags & LONGINT) ? VA(unsigned long) : (unsigned long)(flags & SHORTINT ? (unsigned short)VA(int) : VA(unsigned)); base = HEX; if (flags & ALT && _uquad != 0) flags |= HEXPREFIX; nosign: sign = '\0'; number: if ((dprec = prec) >= 0) flags &= ~ZEROPAD; cp = buf + BUF; if (_uquad != 0 || prec != 0) { switch (base) { case OCT: do { *--cp = to_char (_uquad & 7); _uquad >>= 3; } while (_uquad); if (flags & ALT && *cp != '0') *--cp = '0'; break; case DEC: while (_uquad >= 10) { *--cp = to_char (_uquad % 10); _uquad /= 10; } *--cp = to_char (_uquad); break; case HEX: do { *--cp = xdigs[_uquad & 15]; _uquad >>= 4; } while (_uquad); break; default: cp = D_0049EBD8_2DDF40; size = strlen (cp); goto skipsize; } } size = buf + BUF - cp; skipsize: break; default: if (ch == '\0') goto done; cp = buf; *cp = ch; size = 1; sign = '\0'; break; } realsz = dprec > size ? dprec : size; if (sign) realsz++; else if (flags & HEXPREFIX) realsz += 2; if ((flags & (LADJUST | ZEROPAD)) == 0) PAD (width - realsz, D_0049EB70_2DDF40); if (sign) { PRINT (&sign, 1); } else if (flags & HEXPREFIX) { ox[0] = '0'; ox[1] = ch; PRINT (ox, 2); } if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD) PAD (width - realsz, D_0049EB80_2DDF40); PAD (dprec - size, D_0049EB80_2DDF40); if ((flags & FPT) == 0) { PRINT (cp, size); } else { if (ch >= 'f') { if (_double == 0) { PRINT (D_0049EBF8_2DDF40, 1); if (expt < ndig || (flags & ALT) != 0) { PRINT (decimal_point, 1); PAD (ndig - 1, D_0049EB80_2DDF40); } } else if (expt <= 0) { PRINT (D_0049EBF8_2DDF40, 1); PRINT (decimal_point, 1); PAD (-expt, D_0049EB80_2DDF40); PRINT (cp, ndig); } else if (expt >= ndig) { PRINT (cp, ndig); PAD (expt - ndig, D_0049EB80_2DDF40); if (flags & ALT) PRINT (D_0049EC00_2DDF40, 1); } else { PRINT (cp, expt); cp += expt; PRINT (D_0049EC00_2DDF40, 1); PRINT (cp, ndig - expt); } } else { if (ndig > 1 || flags & ALT) { ox[0] = *cp++; ox[1] = '.'; PRINT (ox, 2); if (_double) { PRINT (cp, ndig - 1); } else PAD (ndig - 1, D_0049EB80_2DDF40); } else PRINT (cp, 1); PRINT (expstr, expsize); } } if (flags & LADJUST) PAD (width - realsz, D_0049EB70_2DDF40); ret += width > realsz ? width : realsz; FLUSH (); } done: FLUSH (); error: return ((fp->flags & 0x40) ? -1 : ret); }
#undef ALT
#undef HEXPREFIX
#undef LADJUST
#undef LONGDBL
#undef LONGINT
#undef QUADINT
#undef SHORTINT
#undef ZEROPAD
#undef FPT
#undef BUF
#undef NIOV
#undef PADSIZE
#undef to_digit
#undef is_digit
#undef to_char
#undef VA
#undef PRINT
#undef PAD
#undef FLUSH
