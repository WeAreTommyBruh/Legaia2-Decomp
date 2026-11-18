/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { void *w0; int w4; char p8[8]; void *w16; char p20[20]; int w40, w44; } M_2A2A38;
extern int D_004A69FC, D_004A69F4; extern char *D_004A14E0; extern int *D_004A6A00;
extern char D_00424A98[], D_00424D18[], D_00424B18[], D_00424C18[], D_0049A700[], D_0049AF00[];
void func_002A2240(void); int func_0018B2A8(char *); void *func_00162130(int, void *, int); void func_0018B7C8(char *, char *); void func_001118F8(char *, ...);
int *func_002A3950(char *, int); void func_002A2F00(M_2A2A38 *, char *, int); int func_00190640(void *, void *, int *, int); void func_00190740(int, int);
void func_001621F8(void *, char *, int); void func_00190710(int, int); void func_002A3268(M_2A2A38 *, void *); int func_002A3278(M_2A2A38 *); void func_002BEA90(M_2A2A38 *, char *);
// MATCH func_002A2A38
void clas_min_002a2a38(M_2A2A38 *m) {
  func_002A2240();
  m->w4 = func_0018B2A8(D_00424A98);
  m->w0 = func_00162130(m->w4, D_0049A700, 3259);
  m->w40 = func_0018B2A8(D_00424D18);
  m->w16 = func_00162130(m->w40, D_0049A700, 3261);
  if (!(D_004A69FC & 0x400)) {
    func_0018B7C8(D_00424B18, D_004A14E0);
    func_001118F8(D_0049AF00);
  }
  D_004A6A00 = func_002A3950(D_004A14E0, func_0018B2A8(D_00424B18) + 3);
  D_004A69FC = 0;
  func_002A2F00(m, D_00424C18, 1);
  D_004A69F4 = func_00190640(func_00162130(32, D_0049A700, 3275), m->w0, D_004A6A00, *D_004A6A00);
  func_00190740(D_004A69F4, -1);
  func_001621F8(D_004A6A00, D_0049A700, 3277);
  D_004A6A00 = 0;
  if (D_004A69F4 != 0) func_00190710(D_004A69F4, 3);
  m->w44 = 0;
  D_004A69F4 = 0;
  func_002A3268(m, m->w0);
  while (func_002A3278(m) == 0);
  func_002BEA90(m, D_00424A98);
}

typedef struct { void *w0; int w4; char p8[8]; void *w16; char p20[20]; int w40; } M_2A2420;
extern int D_004A69FC, D_004A4AA4; extern char D_00424A98[], D_00424A18[], D_00424D18[], D_0049A700[], D_004A6A10[], D_0049AEB0[], D_0049AE70[], D_0049AE90[];
void func_002A2240_2A2420(M_2A2420 *) __asm__("func_002A2240"); void func_002BEA90_2A2420(M_2A2420 *, char *) __asm__("func_002BEA90"); int func_002DD36C(char *, char *); int func_0018B2A8(char *); void *func_00162130(int, void *, int);
void func_0010F1C8(void); void func_0018B7C8_2A2420(char *, void *) __asm__("func_0018B7C8"); void func_0010F1D8(void); void func_001118F8(char *, ...);
// MATCH func_002A2420
void clas_min_002a2420(M_2A2420 *m) {
  func_002A2240_2A2420(m);
  if (!(D_004A69FC & 0x40)) {
    D_004A69FC = 0;
    func_002BEA90_2A2420(m, D_004A6A10);
  }
  if (func_002DD36C(D_00424A98, D_00424A18) != 0) {
    m->w4 = func_0018B2A8(D_00424A98);
    m->w0 = func_00162130(m->w4, D_0049A700, 3090);
    m->w40 = func_0018B2A8(D_00424D18);
    m->w16 = func_00162130(m->w40, D_0049A700, 3092);
    if (D_004A4AA4 != 0) func_0010F1C8();
    func_0018B7C8_2A2420(D_00424A98, m->w0);
    func_0018B7C8_2A2420(D_00424D18, m->w16);
    func_0010F1D8();
    D_004A4AA4 = 0;
    if (!(D_004A69FC & 0x40)) func_001118F8(D_0049AE70, m->w0);
    else func_001118F8(D_0049AE90, m->w0);
  } else {
    m->w0 = func_00162130(m->w4, D_0049A700, 3131);
    m->w16 = func_00162130(m->w40, D_0049A700, 3132);
    func_001118F8(D_0049AEB0, m->w0);
  }
}
