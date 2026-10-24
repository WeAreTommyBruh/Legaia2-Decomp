// cflags: -fno-schedule-insns
#include "../src/common.h"
typedef struct R_t { char pad[56]; int sdidinit; } R_t; typedef struct { char pad[84]; R_t *data; } F_t;
extern R_t *D_004293F4[];
void func_002DBB20(R_t *); int func_002DDF40(R_t *, F_t *, char *, char *);
// 6 words differ
// WIP func_002DDEC8
int vfprintf(F_t *fp, char *fmt, char *ap) { if (fp->data == 0) { fp->data = D_004293F4[0]; if (D_004293F4[0]->sdidinit == 0) func_002DBB20(D_004293F4[0]); } return func_002DDF40(fp->data, fp, fmt, ap); }
