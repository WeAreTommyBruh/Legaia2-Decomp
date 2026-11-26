// compiler: 991111-01
#include "../common.h"
typedef struct { int pad[3]; int b[2]; } BT; extern BT D_003FEBA8;
extern char D_003E9DF0[];
// MATCH func_0025A708
int FUN_0025a708(unsigned a) {
  int pad[2];
  unsigned i;
  char *p, *q;
  int *t;
  if (a < 60) {
    
    
    if (((D_003FEBA8.b[(int)a / 32] >> a) & 1) == 0) goto zero;
    i = 0;
    q = D_003E9DF0;
    p = q + 8;
    do {
      i++;
      if (*(unsigned *)p == a) return 1;
      p += 168;
    } while (i < 60);
  }
  return -1;
zero:
  return 0;
}
