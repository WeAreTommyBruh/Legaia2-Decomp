/* Functions of this report unit, matched by hand. */
#include "../common.h"


// MATCH func_001D953C
void nayuki_001d953c(int a0, float *o, int a2, char *d) { float *p = (float *)(d + 440); int *ip = (int *)p; o[1] = p[0]; o[2] = (float)ip[3]; o[3] = p[9]; o[4] = p[10]; o[5] = (float)ip[15]; o[6] = p[1]; o[7] = (float)ip[4]; o[8] = p[11]; o[9] = p[12]; o[10] = (float)ip[16]; o[11] = p[2]; o[12] = (float)ip[5]; o[13] = p[13]; o[14] = p[14]; o[15] = (float)ip[17]; }


// MATCH func_001D9410
void nayuki_001d9410(int a0, float *o, int a2, char *d) { float *p = (float *)(d + 280); float *q = (float *)(d + 360); int *ip = (int *)p; int *iq = (int *)q; o[1] = p[0]; o[2] = q[0]; o[3] = (float)ip[3]; o[4] = (float)iq[3]; o[5] = p[9]; o[6] = q[9]; o[7] = p[10]; o[8] = q[10]; o[9] = (float)ip[15]; o[10] = (float)iq[15]; o[11] = p[1]; o[12] = q[1]; o[13] = (float)ip[4]; o[14] = (float)iq[4]; o[15] = p[11]; o[16] = q[11]; o[17] = p[12]; o[18] = q[12]; o[19] = (float)ip[16]; o[20] = (float)iq[16]; o[21] = p[2]; o[22] = q[2]; o[23] = (float)ip[5]; o[24] = (float)iq[5]; o[25] = p[13]; o[26] = q[13]; o[27] = p[14]; o[28] = q[14]; o[29] = (float)ip[17]; o[30] = (float)iq[17]; }


// MATCH func_001D95D4
void nayuki_001d95d4(int a0, float *o, int a2, char *d) { float *p0 = (float *)(d + 2324); int *i0 = (int *)p0; float *p1 = (float *)(d + 2404); int *i1 = (int *)p1; float *p2 = (float *)(d + 2484); int *i2 = (int *)p2; o[1] = p0[0]; o[2] = p1[0]; o[3] = p2[0]; o[4] = (float)i0[3]; o[5] = (float)i1[3]; o[6] = (float)i2[3]; o[7] = p0[9]; o[8] = p1[9]; o[9] = p2[9]; o[10] = p0[10]; o[11] = p1[10]; o[12] = p2[10]; o[13] = (float)i0[15]; o[14] = (float)i1[15]; o[15] = (float)i2[15]; o[16] = p0[1]; o[17] = p1[1]; o[18] = p2[1]; o[19] = (float)i0[4]; o[20] = (float)i1[4]; o[21] = (float)i2[4]; o[22] = p0[11]; o[23] = p1[11]; o[24] = p2[11]; o[25] = p0[12]; o[26] = p1[12]; o[27] = p2[12]; o[28] = (float)i0[16]; o[29] = (float)i1[16]; o[30] = (float)i2[16]; o[31] = p0[2]; o[32] = p1[2]; o[33] = p2[2]; o[34] = (float)i0[5]; o[35] = (float)i1[5]; o[36] = (float)i2[5]; o[37] = p0[13]; o[38] = p1[13]; o[39] = p2[13]; o[40] = p0[14]; o[41] = p1[14]; o[42] = p2[14]; o[43] = (float)i0[17]; ((volatile float *)o)[44] = (float)i1[17]; o[45] = (float)i2[17]; }


// MATCH func_001D82D0
void nayuki_001d82d0(float param_1, int param_2) { float *p = (float *)(param_2 + 224); if (0.0f <= p[3]) { p[3] = param_1; if (p[4] <= param_1) { p[3] = p[4]; } else if (param_1 < 0.0f) { p[3] = 0; } if (p[3] < p[5]) { p[0] = p[1]; return; } p[0] = p[6] * (p[3] - p[5]) + p[1]; } return; }

// cflags: -fexceptions
void th_tex_0022c0b8(void); void th_tex_0022cf58(long);
// MATCH func_001DE088
int nayuki_001de088(int param_1) { register int v __asm__("$4"); if (*(int *)(param_1 + 0x50) <= (int)*(float *)(param_1 + 0x44) && *(char *)(param_1 + 0x4c) != 0 && (v = *(int *)(param_1 + 0xa08)) != 0) { th_tex_0022c0b8(); th_tex_0022cf58(*(int *)(param_1 + 0xa08)); return 1; } return 0; }

