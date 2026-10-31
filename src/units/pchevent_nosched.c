/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

extern int D_004A1444, D_004A140C; extern float D_003C0F30[3];
// MATCH func_0020CB58
int pchevent_0020cb58(int a) { if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) { float z = 0.0f; __asm__("" : "+f"(z)); D_003C0F30[0] = z; D_003C0F30[1] = z; D_003C0F30[2] = z; } return 0; }

typedef struct { char p[112]; float f112, f116, f120; } R_0020C138;
typedef struct { R_0020C138 *w0; } Q_0020C138;
extern int D_004A45E8; extern float D_004A45FC; Q_0020C138 *func_0020BBD8(int);
// MATCH func_0020C138
int pchevent_0020c138(void) { if (D_004A45E8 >= 0) { Q_0020C138 *p = func_0020BBD8(D_004A45E8); if (p != 0) { R_0020C138 *q = p->w0; if (q != 0) { q->f112 = D_004A45FC; q->f120 = D_004A45FC; q->f116 = D_004A45FC; } } } return 0; }
