/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern unsigned char D_0049EA61[];
unsigned long func_002EFBC8(unsigned long, unsigned long); long func_002F0198(unsigned long, unsigned long); long func_002D73E8(long, long);
// MATCH func_002E4900
unsigned long FUN_002e4900(int *ptr, const char *nptr, char **endptr, int base) { register const char *s = nptr; register unsigned long acc; register int c; register unsigned long cutoff; register int neg = 0, any, cutlim; long mb; do { c = *s++; } while (D_0049EA61[c] & 8); if (c == '-') { neg = 1; c = *s++; } else if (c == '+') c = *s++; if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) { c = s[1]; s += 2; base = 16; } if (base == 0) base = c == '0' ? 8 : 10; cutoff = 0xffffffffffffffffUL / (unsigned long)base; cutlim = 0xffffffffffffffffUL % (unsigned long)base; mb = base; for (acc = 0, any = 0;; c = *s++) { if (D_0049EA61[c] & 4) c -= '0'; else if (D_0049EA61[c] & 3) c -= (D_0049EA61[c] & 1) ? 'A' - 10 : 'a' - 10; else break; if (c >= base) break; if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) any = -1; else { any = 1; acc *= mb; acc += c; } } if (any < 0) { acc = 0xffffffffffffffffUL; ptr[0] = 34; } else if (neg) acc = -acc; if (endptr != 0) *endptr = (char *)(any ? (char *)s - 1 : nptr); return acc; }

extern unsigned char D_0049EA61_2DDB58[] __asm__("D_0049EA61");
// MATCH func_002DDB58
long FUN_002ddb58(int *ptr, const char *nptr, char **endptr, int base) { register const char *s = nptr; register unsigned long acc; register int c; register unsigned long cutoff; register int neg = 0, any, cutlim; long mb; do { c = *s++; } while (D_0049EA61_2DDB58[c] & 8); if (c == '-') { neg = 1; c = *s++; } else if (c == '+') c = *s++; if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) { c = s[1]; s += 2; base = 16; } if (base == 0) base = c == '0' ? 8 : 10; cutoff = neg ? 0x8000000000000000UL : 0x7fffffffffffffffUL; cutlim = cutoff % (unsigned long)base; cutoff /= (unsigned long)base; mb = base; for (acc = 0, any = 0;; c = *s++) { if (D_0049EA61_2DDB58[c] & 4) c -= '0'; else if (D_0049EA61_2DDB58[c] & 3) c -= (D_0049EA61_2DDB58[c] & 1) ? 'A' - 10 : 'a' - 10; else break; if (c >= base) break; if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) any = -1; else { any = 1; acc *= mb; acc += c; } } if (any < 0) { acc = neg ? 0x8000000000000000UL : 0x7fffffffffffffffUL; ptr[0] = 34; } else if (neg) acc = -acc; if (endptr != 0) *endptr = (char *)(any ? (char *)s - 1 : nptr); return acc; }

