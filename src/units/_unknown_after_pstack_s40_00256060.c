#include "../common.h"
typedef struct { char p[376]; unsigned char c376; char q[95]; } E472; extern E472 D_00400498[], D_003FE270[];
// MATCH func_00256060
int FUN_00256060(int i) { if ((unsigned)i < 10) { E472 *e; if (i < 5) e = &D_00400498[i]; else { char *b = (char *)D_003FE270; b -= 2360; e = (E472 *)(b + i * 472); } return e->c376; } return -1; }
