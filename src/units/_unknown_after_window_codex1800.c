/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern volatile unsigned char D_004A3841_00196340 __asm__("D_004A3841");

// MATCH func_00196340
int FUN_00196340(unsigned char c){if(c<2){register int r=1;__asm__ volatile("" : : "r"(r));D_004A3841_00196340=c;return r;}return -1;}
