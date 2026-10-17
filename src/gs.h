/* GS register values, built the way the game builds them (the bit layout of
   the PS2's Graphics Synthesizer registers; the same shape as the SDK's
   SCE_GS_SET_* macros, which the compiler folds the same way). */
#ifndef GS_H
#define GS_H

#include "common.h"

#define GS_TEX0_1 0x06
#define GS_TEST_1 0x47

#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
     ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
     ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

#define GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u64)(ate) | ((u64)(atst) << 1) | ((u64)(aref) << 4) | ((u64)(afail) << 12) | \
     ((u64)(date) << 14) | ((u64)(datm) << 15) | ((u64)(zte) << 16) | ((u64)(ztst) << 17))

#endif
