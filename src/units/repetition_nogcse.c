/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char c[8]; } V8_00175CF8;
typedef struct { char p[372]; int w372; char p2[32]; V8_00175CF8 v; V8_00175CF8 v2; } O_00175CF8;
extern V8_00175CF8 D_004A3200[3], D_004A31D8[3], D_004A31E8[3];
extern unsigned long D_004A12D8_00175CF8 __asm__("D_004A12D8"), D_004A12E0_00175CF8 __asm__("D_004A12E0");
extern char D_00336528[], D_00343028_00175CF8[] __asm__("D_00343028");
void func_001749D8(void *, void *);
int func_0010C2B0(void *, int, int, int, int, int, int);
void func_00172C30(void *);
void func_00172CB0(void *);
void func_00174AB8(void *);
void func_00172CB8(void *);
// MATCH func_00175CF8
int repetition_00175cf8(O_00175CF8 *o) {
    func_001749D8(o, D_00336528);
    if ((D_004A12D8_00175CF8 | D_004A12E0_00175CF8) & 0x11000) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 - 1;
    }
    if ((D_004A12D8_00175CF8 | D_004A12E0_00175CF8) & 0x24000) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 + 1;
    }
    o->w372 = o->w372 & 1;
    if (D_004A12D8_00175CF8 & 0x200040) {
        func_0010C2B0(D_00343028_00175CF8, 0, 2, 0, 1, 0, 0);
        if (o->w372 == 0) {
            func_00172C30(o);
            func_00172CB0(o);
            func_00174AB8(o);
            o->v = D_004A3200[0];
        } else {
            func_00172CB8(o);
            o->v = D_004A31D8[0];
            o->v2 = D_004A31E8[0];
        }
    }
    return 0;
}

typedef struct { char c[8]; } V8_00175AF8;
typedef struct { char p[372]; int w372; char p2[32]; V8_00175AF8 v; V8_00175AF8 v2; } O_00175AF8;
extern V8_00175AF8 D_004A3200_00175AF8[3] __asm__("D_004A3200"), D_004A32D0[3];
extern unsigned long D_004A12D8_00175AF8 __asm__("D_004A12D8"), D_004A12E0_00175AF8 __asm__("D_004A12E0");
extern char D_00336518[], D_00343028_00175AF8[] __asm__("D_00343028");
void func_001749D8(void *, void *);
int func_0010C2B0(void *, int, int, int, int, int, int);
// MATCH func_00175AF8
int repetition_00175af8(O_00175AF8 *o) {
    func_001749D8(o, D_00336518);
    if ((D_004A12D8_00175AF8 | D_004A12E0_00175AF8) & 0x11000) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 - 1;
    }
    if ((D_004A12D8_00175AF8 | D_004A12E0_00175AF8) & 0x24000) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 0, 0, 0);
        o->w372 = o->w372 + 1;
    }
    o->w372 = o->w372 & 1;
    if (D_004A12D8_00175AF8 & 0x200040) {
        func_0010C2B0(D_00343028_00175AF8, 0, 2, 0, 1, 0, 0);
        if (o->w372 == 0) o->v = D_004A3200_00175AF8[0];
        else o->v = D_004A32D0[0];
    }
    return 0;
}
