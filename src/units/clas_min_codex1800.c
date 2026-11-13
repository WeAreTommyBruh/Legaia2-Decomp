/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00425510_002A45E8[] __asm__("D_00425510");

// MATCH func_002A45E8
void clas_min_002a45e8(void){int h=D_00425510_002A45E8[1];register int l __asm__("$5");h=(h & 0xfffeffffU);h=(h & 0xfffffdffU);h=(h & 0xfffffbffU);h=(h & 0xfffff7ffU);h=(h & 0xffffefffU);h=(h & 0xffff7fffU);h=(h & 0xfffdffffU);h=(h & 0xfffbffffU);h=(h & 0xfff7ffffU);h=(h & 0xffefffffU);l=D_00425510_002A45E8[0];l=(l & 0xdfffffffU);h=(h & 0xffffffbfU);l=(l & 0xbfffffffU);h=(h & 0xffffff7fU);l=(l & 0xffbfffffU);D_00425510_002A45E8[1]=h;D_00425510_002A45E8[0]=l;}
