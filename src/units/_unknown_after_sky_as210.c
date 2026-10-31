/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

// MATCH func_00156B58
void FUN_00156b58(char *o, unsigned c) { float r = (float)(c & 0xff); float g = (float)((c >> 8) & 0xff); float b = (float)((c >> 16) & 0xff); float *p = (float *)(o + 176); 
*(float *)(o + 176) = r;
p[1] = g;
p[2] = b;
p[3] = 128.0f;}

// MATCH func_00156408
void FUN_00156408(char *o, unsigned c, unsigned d) { float r = (float)(c & 0xff); float g = (float)((c >> 8) & 0xff); float b = (float)((c >> 16) & 0xff); float *p = (float *)(o + 64); float r2; float g2; float b2; float *q; *(float *)(o + 64) = r; p[1] = g; p[2] = b; p[3] = 128.0f; r2 = (float)(d & 0xff); g2 = (float)((d >> 8) & 0xff); b2 = (float)((d >> 16) & 0xff); q = (float *)(o + 80); *(float *)(o + 80) = r2; q[1] = g2; q[2] = b2; q[3] = 128.0f; }
