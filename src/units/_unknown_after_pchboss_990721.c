/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p0[172]; short id; } E_219600_00219600;
typedef struct { int n; int cnt; int max_frame; int pad[7]; int ids[75]; E_219600_00219600 *ev[65]; } S_219600_00219600;
void *func_002A3F78_219600(int, int) __asm__("func_002A3F78");
int func_0021B5B8_219600(void *) __asm__("func_0021B5B8");
void func_001118F8_219600(const void *, ...) __asm__("func_001118F8");
// MATCH func_00219600
int FUN_00219600(S_219600_00219600 *s, int flag) { int i, j; E_219600_00219600 *e; s->cnt = 0; s->n = 0; if (flag == 0) return 0; for (i = 0; i < 256; i++) { e = func_002A3F78_219600(i, 0); if (e == 0) continue; e->id = i; s->ids[s->n] = i; s->n++; if (i == 0) { s->max_frame = func_0021B5B8_219600(e); func_001118F8_219600("max_frame %d \n", s->max_frame); } if (s->n > 64) { func_001118F8_219600("BATTLE EVENT SET ERRRRRRRRRRRRRRRRRRRRRRR 1\n"); return 0; } j = 1; s->ev[s->cnt++] = e; while ((e = func_002A3F78_219600(i, j)) != 0) { e->id = i; j++; s->ev[s->cnt++] = e; if (s->cnt > 64) func_001118F8_219600("BATTLE EVENT SET ERRRRRRRRRRRRRRRRRRRRRRR 1\n"); } } }
