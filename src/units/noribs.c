/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

extern int D_004A140C_151F80 __asm__("D_004A140C"), D_004A24F4_151F80 __asm__("D_004A24F4"), D_004A24F0_151F80 __asm__("D_004A24F0"), D_004A29F4_151F80 __asm__("D_004A29F4"); extern char D_004A26D0_151F80 __asm__("D_004A26D0");
extern char D_00332DB0_151F80[] __asm__("D_00332DB0"), D_0032C6A8_151F80[] __asm__("D_0032C6A8"), D_00320980_151F80[] __asm__("D_00320980"), D_0043B198_151F80[] __asm__("D_0043B198"); extern char *D_0032C6B8_151F80[] __asm__("D_0032C6B8");
void *func_002DD4CC_151F80(char *, char *) __asm__("func_002DD4CC"); int func_0023C728_151F80(char *, char *) __asm__("func_0023C728"); int func_002E9950_151F80(char *, int) __asm__("func_002E9950"); void func_002E9BD8_151F80(int) __asm__("func_002E9BD8");
void func_0023F090_151F80(int, int, char *, void *) __asm__("func_0023F090"); void func_00152258_151F80(void) __asm__("func_00152258"); void func_00151F80_151F80(unsigned) __asm__("func_00151F80");
// MATCH func_00151F80
int noribs_00151f80(unsigned a) { int fd; if (a != 0) { if ((D_004A140C_151F80 & 0x200) != 0) { func_002DD4CC_151F80(D_00332DB0_151F80, &D_004A26D0_151F80); func_0023C728_151F80(D_00332DB0_151F80, D_0032C6A8_151F80); func_0023C728_151F80(D_00332DB0_151F80, D_0032C6B8_151F80[D_004A24F4_151F80]); fd = func_002E9950_151F80(D_00332DB0_151F80, 1); if (fd < 0) a = a | 8; else func_0023F090_151F80(96, 80, D_0043B198_151F80, (void *)func_00151F80_151F80); func_002E9BD8_151F80(fd); } if ((a & 8) != 0) { func_002DD4CC_151F80(D_00320980_151F80, D_0032C6B8_151F80[D_004A24F4_151F80]); func_00152258_151F80(); D_004A24F0_151F80 = 0; D_004A29F4_151F80 = 0; } } }

