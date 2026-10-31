/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

// MATCH func_0018D8E8
void FUN_0018d8e8(void) { *(volatile unsigned *)0x10000810 = 0x83; *(volatile unsigned *)0x10000800 = 0; }

// MATCH func_0018EB98
void FUN_0018eb98(void *d, void *s)
{
    __asm__ volatile (
        "lq $7, 0($5)\n"
        "lq $6, 16($5)\n"
        "lq $3, 32($5)\n"
        "lq $2, 48($5)\n"
        "sq $7, 0($4)\n"
        "sq $6, 16($4)\n"
        "sq $3, 32($4)\n"
        "sq $2, 48($4)\n"
    );
}

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F790
void FUN_0018f790(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F818
void FUN_0018f818(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018F898
void FUN_0018f898(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F520((float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F900
void FUN_0018f900(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F988
void FUN_0018f988(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018FA08
void FUN_0018fa08(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F520((float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018FA70
void FUN_0018fa70(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018FAF8
void FUN_0018faf8(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018FB78
void FUN_0018fb78(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F520((float *)m); }
