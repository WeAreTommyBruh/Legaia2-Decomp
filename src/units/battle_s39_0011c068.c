#include "../common.h"
// compiler: 990721-r5900
typedef struct { float f[4]; } Q4;
extern Q4 D_004303D8[], D_004303E8[];
extern void *D_003279A0[]; extern char *D_004A1A20;
extern int D_004A1A50, D_004A1A6C, D_004A6DB4, D_004A6E50, D_004A13D4, D_004A6D9C;
extern float D_004A6D18, D_0049FCF8, D_0049FCFC, D_0049FD00, D_0049FD04, D_0049FD08, D_0049FD0C, D_0049FD10, D_0049FD14, D_0049FD18, D_0049FD1C;
extern int D_00314CC8[];
float *func_00270968(void *, int); int func_00127430(void); int func_0012C448(int); void func_00124A48(float, float, float, float, int);
void func_0011BC88(int, float, float, float, float, float, float, float); int func_0021AEE0(char *); float func_0021AF68(char *); float func_0015FB58(float, int);
void func_002191E8(float, int, int, float *);
typedef struct { char p[172]; short h172; } OB;
// MATCH func_0011C068
void battle_0011c068(float s, unsigned idx, int flag)
{
    float tbl[9];
    register float f23 __asm__("$f23");
    register float f21 __asm__("$f21");
    register float f20 __asm__("$f20");
    register float f27 __asm__("$f27");
    register float f25 __asm__("$f25");
    register float f24 __asm__("$f24");
    register float * e __asm__("$17");
    float *o2;
    register float fn __asm__("$f26");
    float off, sc, ff;
    char *actor;
    int backup;
    int P, i2, c, c3, mode;
    if (D_004A1A50 & 0x10) return;
    if (D_004A1A6C & 1) return;
    if (idx > 9) return;
    if (D_003279A0[idx] == 0) return;
    e = (float *)*(int *)(D_004A1A20 + idx * 5472 + 4800);
    o2 = func_00270968(D_003279A0[idx], 2);
    { register float value __asm__("$f0"); value = e[17]; fn = -value; }
    c3 = D_004A6DB4 & 3;
    *(Q4 *)tbl = D_004303D8[0];
    *(Q4 *)(tbl + 4) = D_004303E8[0];
    if (D_004A6E50 == 0 && flag == 0 && (D_004A13D4 == 12 || func_00127430())) {
        if (func_0012C448(idx)) return;
        sc = s * 5.0f;
        { register float value __asm__("$f0"); value = e[17]; fn = -value; }
        func_00124A48(sc, -e[32], -e[9], -e[34], 2855);
        func_0011BC88(2856, sc, o2[3], fn, e[18], o2[0], o2[1], o2[2]);
        return;
    }
    mode = D_004A13D4;
    if ((unsigned)(mode - 10) < 2) goto shifted;
    mode = D_004A6E50;
    if (!flag && !mode) { backup = 5472; goto F; }
    backup = 5472;
    __asm__("" : "+r"(backup));

    { register float angle __asm__("$f0"); register float delta __asm__("$f1");
      if (mode) {
shifted:
          angle = *(float *)(D_004A1A20 + idx * 5472 + 5300);
          delta = D_0049FCF8;
      } else {
          angle = e[17];
          delta = D_0049FCFC;
      }
      angle += delta;
      __asm__("" : : "f"(angle));
      fn = -angle;
    }
    { int stride; int renderOffset;
    { int ready;
      ready = func_0012C448(idx);
      stride = 5472;
      if (ready) { register float raw __asm__("$f0"); register float bias __asm__("$f1");
        __asm__("" : : "r"(stride)); raw = e[17]; bias = D_0049FD00; raw += bias;
        __asm__("" : "+f"(raw)); fn = -raw; }
      renderOffset = idx * stride;
      __asm__("" : "+r"(renderOffset), "+r"(stride));
      i2 = func_0021AEE0(D_004A1A20 + renderOffset);
    }
    { float lo; float perActor; register float bias __asm__("$f2"); register float f __asm__("$f0");
      actor = (char *)(renderOffset + (int)D_004A1A20);
      lo = 15360.0f;
      perActor = D_0049FD04;
      bias = 10240.0f;
      f = (*(float *)(actor + 5460) + *(float *)(D_004A1A20 + i2 * stride + 5460)) * lo * 0.5f * perActor;
      f24 = __builtin_fabsf(f) + bias;
      if (f24 < lo) f24 = lo;
    }
    if (40960.0f < f24) f24 = 40960.0f;
    f24 = -f24;
    f25 = 2560.0f;
    f27 = 0.0f;
    if (D_004A13D4 == 11) {
        f20 = func_0021AF68(actor);
    __asm__("" : "+f"(f20));
        f27 = 5.0f;
        f20 += func_0021AF68(D_004A1A20 + D_004A6D9C * stride);
        f20 *= 1536.0f;
        f25 = __builtin_fabsf(f20);
    }
    f23 = e[17];

    if (flag == 0) {
        ff = func_0015FB58(f23, 0) * f25;
        f20 = e[8]; f21 = e[9];
        f20 = -(f20 - ff); f21 = -f21;
        ff = func_0015FB58(f23, 1) * f25;
        func_00124A48(s, f20, f21, -(e[10] - ff), 2900);
        if ((int)idx < 4) {
            { register float *slot __asm__("$3");
              if (D_004A6D18 < D_0049FD08) { slot = (float *)((int)tbl + (c3 << 2)); off = slot[4]; }
              else { slot = (float *)((int)tbl + (c3 << 2)); off = slot[0]; } }
            func_0011BC88(2907, f27 * s, e[16] + off, fn, e[18], 0.0f, -6144.0f, f24);
        } else {
            func_0011BC88(2909, f27 * s, e[16] - D_0049FD0C, fn, e[18], 0.0f, -5888.0f, f24);
        }
    } else {
        ff = func_0015FB58(f23, 0) * f25;
        s = 1.0f;
        f20 = e[32]; f21 = e[33];
        f20 = -(f20 - ff); f21 = -f21;
        ff = func_0015FB58(f23, 1) * f25;
        func_00124A48(s, f20, f21, -(e[34] - ff), 2912);
        func_0011BC88(2913, s, e[16] + 0.5f, fn, e[18], 0.0f, -768.0f, f24);
    }
    return;
    }
F:
    { register int small __asm__("$2");
      small = (int)idx < 4;
      __asm__("" : : "r"(small), "r"(backup));
      P = idx * backup;
      if (small) {
        func_002191E8(o2[2], 480, 100, &tbl[8]);
        c = 0;
        if (*(int *)(*(int *)(P + (int)D_004A1A20 + 5188) + 56) == 0) c = D_004A13D4 == 13;
        if (((OB *)D_003279A0[idx])->h172 == 1 && D_00314CC8[0] == 100) c = 1;
        if (c) {
            func_00124A48(s * 5.0f, -e[32], -e[9], -e[34], 2938);
            func_0011BC88(2939, s * 10.0f, (0.200000003f), fn, e[18], o2[0] + tbl[8], -4000.0f, o2[2] - D_0049FD10);
        } else {
            func_00124A48(s * 5.0f, -e[8], -e[9], -e[10], 2943);
            func_0011BC88(2944, s * 10.0f, o2[3], fn + (o2[4] - D_0049FD18), e[18], o2[0] + tbl[8], o2[1], o2[2]);
        }
    } else {
        func_00124A48(s * 5.0f, -e[8], -e[9], -e[10], 2947);
        if (D_004A13D4 == 8) {
            register float tmp __asm__("$f0");
            register float offset __asm__("$f3");
            tmp = *(float *)(P + (int)D_004A1A20 + 5468) * 5120.0f;
            offset = -20480.0f;
            __asm__("" : "+f"(offset));
            f24 = offset - (tmp + tmp);
            if (-14080.0f < f24) f24 = -14080.0f;
        }
        tbl[8] = 0;
        func_0011BC88(2958, s * 10.0f, o2[3], fn + (o2[4] - D_0049FD1C), e[18], o2[0] + tbl[8], o2[1], o2[2]);
    }
}
}
