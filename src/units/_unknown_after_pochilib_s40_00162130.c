#include "../common.h"
extern int D_004A14EC; extern char D_0043C538[];
typedef struct { int pad[5]; int line; char *file; } Hd;
int func_001118F8x(char *, ...) __asm__("func_001118F8");void *func_00162190();
// MATCH func_00162130
void *MemAllocDbg(unsigned size0, char *file, int line) { char *p; Hd *h; register unsigned size __asm__("$18") = size0; if (D_004A14EC != 0) func_001118F8x(D_0043C538); p = func_00162190(size); h = (Hd *)(p - 0x80); h->line = line; h->file = file; return p; }
