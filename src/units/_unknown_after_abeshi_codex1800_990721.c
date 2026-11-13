/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_004A724C_00260428 __asm__("D_004A724C"), D_004A7250_00260428 __asm__("D_004A7250"), D_004A7254_00260428 __asm__("D_004A7254"), D_004A7258_00260428 __asm__("D_004A7258");
extern int D_004A5E38_00260428 __asm__("D_004A5E38"), D_004A5E3C_00260428 __asm__("D_004A5E3C"), D_004A5E40_00260428 __asm__("D_004A5E40"), D_004A5E44_00260428 __asm__("D_004A5E44");
extern int D_005F8780_00260428[21] __asm__("D_005F8780");
extern u64 D_0048CEA8_00260428[] __asm__("D_0048CEA8"), D_0048CEC0_00260428[] __asm__("D_0048CEC0"), D_0048CED0_00260428[] __asm__("D_0048CED0");
extern char D_0048CEE8_00260428[] __asm__("D_0048CEE8"), D_004A5E48_00260428[] __asm__("D_004A5E48"), D_00343028_00260428[] __asm__("D_00343028");
extern int *D_004042C0_00260428[] __asm__("D_004042C0");
int func_002CBB80_00260428(int) __asm__("func_002CBB80");
int func_0023C728_00260428(char *, int) __asm__("func_0023C728");
char *strcat(char *, const char *);
int func_0010D8A0_00260428(void *, char *) __asm__("func_0010D8A0");
int DbgPrintf(char *, ...);
typedef struct { char pad[24]; u32 flags; char p2[184 - 28]; int state; } Obj_00260428;
// MATCH func_00260428
int FUN_00260428(Obj_00260428 *o)
{
  char buf[64];
  register int r __asm__("$6");
  if ((u32)D_004A724C_00260428 > 20) { o->flags |= 8; return; }
  {int off = D_004A724C_00260428*4; if (D_004A7250_00260428 < 0 || *(int *)((char*)D_005F8780_00260428+off) < D_004A7250_00260428) { o->flags |= 8; return; }
  } switch (o->state) {
  case 0:
    D_004A5E44_00260428 = 1;
    switch (D_004A724C_00260428) {
    case 6:
      if (D_004A7250_00260428 >= 268 || D_004A7250_00260428 == 2 || D_004A7250_00260428 == 4) {
        __builtin_memcpy(buf, D_0048CEA8_00260428, 18);
        break;
      }
    case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
      __builtin_memcpy(buf, D_0048CEC0_00260428, 15);
      break;
    default:
      __builtin_memcpy(buf, D_0048CED0_00260428, 18);
      break;
    }
    func_0023C728_00260428(buf, D_004042C0_00260428[D_004A724C_00260428][D_004A7250_00260428]);
    strcat(buf, D_004A5E48_00260428);
{register int neg=-1;__asm__ volatile("" : : "r"(neg));    r = func_0010D8A0_00260428(D_00343028_00260428, buf);
    if (r == -1) {
__asm__ volatile("" : "+r"(r));      D_004A5E44_00260428 = 0;
      o->flags |= 8;
      D_004A5E38_00260428=neg;
    }
    if (r < 0)
      return;
    DbgPrintf(D_0048CEE8_00260428, buf);
    D_004A7254_00260428 = -1;
    D_004A7258_00260428 = -1;
    o->state++;
    D_004A5E3C_00260428++;
    D_004A5E40_00260428++;
    if (D_004A5E40_00260428 >= 601) {
      D_004A5E44_00260428 = 0;
      D_004A7254_00260428 = -1;
      D_004A7258_00260428 = -1;
      o->flags |= 8;
      D_004A5E38_00260428=neg;
    }
} break;
  case 1:
    D_004A5E3C_00260428++;
    if (func_002CBB80_00260428(1) == 0) {
      u32 f = o->flags;
      D_004A5E44_00260428 = 2;
      o->flags = f | 8;
    }
    break;
  }
}
