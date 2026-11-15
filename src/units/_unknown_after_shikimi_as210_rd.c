/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef void (*F_2C7728)(void *);
void func_002C3EA0_2C7728(void *) __asm__("func_002C3EA0"); void func_002C3CD0_2C7728(void *) __asm__("func_002C3CD0"); void func_002C3E00_2C7728(void *) __asm__("func_002C3E00");
void func_002C7BA0_2C7728(void *) __asm__("func_002C7BA0"); void func_002C7D60_2C7728(void *) __asm__("func_002C7D60"); void func_002C3E90_2C7728(void *) __asm__("func_002C3E90");
void func_002C7C68_2C7728(void *) __asm__("func_002C7C68"); void func_002C7850_2C7728(void *) __asm__("func_002C7850"); void func_002C3EB0_2C7728(void *) __asm__("func_002C3EB0"); void func_002C3EC0_2C7728(void *) __asm__("func_002C3EC0");
void func_002C7468_2C7728(void *) __asm__("func_002C7468"); int func_002C7120_2C7728(void *, int) __asm__("func_002C7120"); void func_002C7228_2C7728(void *, int) __asm__("func_002C7228"); unsigned func_002C7318_2C7728(void *, int) __asm__("func_002C7318");
// MATCH func_002C7728
void FUN_002c7728(void *s) {
  F_2C7728 tbl[11] = { func_002C3EA0_2C7728, func_002C3CD0_2C7728, func_002C3E00_2C7728, func_002C7BA0_2C7728, func_002C7D60_2C7728, func_002C3E90_2C7728, func_002C3EA0_2C7728, func_002C7C68_2C7728, func_002C7850_2C7728, func_002C3EB0_2C7728, func_002C3EC0_2C7728 };
  int c;
  unsigned i;
  func_002C7468_2C7728(s);
  while ((c = func_002C7120_2C7728(s, 32)) == 0x1b5 || c == 0x1b2) {
    if (c == 0x1b5) {
      func_002C7228_2C7728(s, 32);
      i = func_002C7318_2C7728(s, 4);
      i = i > 10 ? 0 : i;
      tbl[i](s);
      func_002C7468_2C7728(s);
    } else {
      func_002C7228_2C7728(s, 32);
      func_002C7468_2C7728(s);
    }
  }
}
