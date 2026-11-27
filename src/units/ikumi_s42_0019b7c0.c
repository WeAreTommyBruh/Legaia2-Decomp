#include "../common.h"
// MATCH func_0019B7C0
int ikumi_0019b7c0(char *o, int off) { char *p; int n; char c, d; off += *(int *)(o + 12); p = (char *)off; n = 0; do { d = p[1]; c = *p; if (c == 13 && d == 10) { *(int *)(o + 284) += 1; return n + 2; } p++; n++; } while (c != 0); return n; }
