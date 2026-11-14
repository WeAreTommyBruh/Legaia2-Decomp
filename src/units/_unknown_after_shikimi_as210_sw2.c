/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { volatile unsigned flags; int pc; void *base; int x0c; int tick; int time; char p18[6]; unsigned short x1e; char p20[4]; unsigned char b24; char p25[0x2b]; unsigned char b50; unsigned char b51; char p52[2]; } Tk_2CFFE0;
typedef struct { unsigned long m0, m8, m16, m24, m32, m40; char p30[0xc]; volatile int x3c; volatile int x40; } Gl_2CFFE0;
typedef struct { char p0[0x10]; unsigned char *ev; } Sq_2CFFE0;
Tk_2CFFE0 *func_002CFF20_2CFFE0(int) __asm__("func_002CFF20");
Gl_2CFFE0 *func_002CFF38_2CFFE0(void) __asm__("func_002CFF38");
Sq_2CFFE0 *func_002CFFA0_2CFFE0(void) __asm__("func_002CFFA0");
void *func_002CFFB0_2CFFE0(void) __asm__("func_002CFFB0");
void *func_002CFFC0_2CFFE0(int, int) __asm__("func_002CFFC0");
void func_002D3430_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D3430");
int func_002D1760_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D1760");
void func_002D21C0_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D21C0");
void func_002D2290_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2290");
void func_002D2320_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2320");
void func_002D23B0_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D23B0");
void func_002D2510_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2510");
void func_002D2D88_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2D88");
void func_002D27D8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D27D8");
void func_002D2990_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2990");
void func_002D2BB0_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2BB0");
void func_002D2688_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2688");
void func_002D2CC8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D2CC8");
void func_002D33D8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D33D8");
void func_002D3108_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D3108");
void func_002D3190_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D3190");
void func_002D32C8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D32C8");
void func_002D1DB8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D1DB8");
void func_002D0558_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D0558");
void func_002D09D8_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D09D8");
void func_002D1580_2CFFE0(Tk_2CFFE0 *) __asm__("func_002D1580");
void func_002D0E78_2CFFE0(void) __asm__("func_002D0E78");
void func_002D37C0_2CFFE0(int, int, void *, void *, int, int) __asm__("func_002D37C0");
int SndVoiceSetParam_2CFFE0(int, int, int, int) __asm__("SndVoiceSetParam");
// MATCH func_002CFFE0
void FUN_002cffe0(void) {
  Tk_2CFFE0 *t = func_002CFF20_2CFFE0(0);
  Gl_2CFFE0 *g = func_002CFF38_2CFFE0();
  Sq_2CFFE0 *s = func_002CFFA0_2CFFE0();
  void *x = func_002CFFB0_2CFFE0();
  int i, r, st;
  func_002D3430_2CFFE0(t);
  for (i = 0; i < 48; i++, t++) {
    if (t->flags & 0x2000) continue;
    st = t->flags & 0xf;
    if (st == 3 || st == 12) {
    while (t->time <= 0) {
      r = func_002D1760_2CFFE0(t);
      if (r == -1) goto next;
      if (r == 1) {
        switch (t->b50 & 0xf0) {
        case 0xf0:
          switch (s->ev[1]) {
          case 0x2f: func_002D21C0_2CFFE0(t); goto done;
          case 0x51: func_002D2290_2CFFE0(t); break;
          }
          break;
        case 0xc0: func_002D2320_2CFFE0(t); break;
        case 0xb0:
          switch (s->ev[1]) {
          case 1: func_002D23B0_2CFFE0(t); break;
          case 2: func_002D2510_2CFFE0(t); break;
          case 6: func_002D2D88_2CFFE0(t); break;
          case 7: func_002D27D8_2CFFE0(t); break;
          case 10: func_002D2990_2CFFE0(t); break;
          case 64: func_002D2BB0_2CFFE0(t); break;
          case 65: func_002D2688_2CFFE0(t); break;
          case 96:
            func_002D2CC8_2CFFE0(t);
            func_002D33D8_2CFFE0(t);
            t->time = 0;
            goto done;
          case 98: func_002D3108_2CFFE0(t); break;
          case 99: func_002D3190_2CFFE0(t); break;
          }
          break;
        case 0xe0: func_002D32C8_2CFFE0(t); break;
        case 0x80: func_002D1DB8_2CFFE0(t); break;
        case 0xa0: func_002D0558_2CFFE0(t); break;
        case 0x90: func_002D09D8_2CFFE0(t); break;
        }
      }
      func_002D33D8_2CFFE0(t);
    }
  done:
    if (t->x1e != 0 || (t->flags & 8)) t->time -= t->tick;
    if (t->flags & 0x80) {
      t->flags &= ~0x80;
      t->b51 = t->b50 = t->b24;
      t->pc = t->x0c;
      if (t->flags & 4) {
        t->flags |= 8;
      } else {
        t->time = 0;
        t->flags |= 2;
        t->flags &= ~0x40;
      }
    }
    }
    func_002D1580_2CFFE0(t);
  next:;
  }
  func_002D0E78_2CFFE0();
  if (g->m8 != g->m0) {
    SndVoiceSetParam_2CFFE0(12, 0, g->m0 & 0xffffff, (g->m0 >> 24) & 0xffffff);
    g->m8 = g->m0;
  }
  if (g->m24 != g->m16) {
    SndVoiceSetParam_2CFFE0(13, 0, g->m16 & 0xffffff, (g->m16 >> 24) & 0xffffff);
    g->m24 = g->m16;
  }
  if (g->m32 != 0) {
    SndVoiceSetParam_2CFFE0(10, 0, g->m32 & 0xffffff, (g->m32 >> 24) & 0xffffff);
    g->m32 = 0;
  }
  if (g->m40 != 0) {
    SndVoiceSetParam_2CFFE0(11, 0, g->m40 & 0xffffff, (g->m40 >> 24) & 0xffffff);
    g->m40 = 0;
  }
  func_002D37C0_2CFFE0(100, 1, func_002CFFC0_2CFFE0(g->x3c, 0), x, g->x40 << 4, 512);
  g->x40 = 0;
  g->x3c = (g->x3c + 1) & 1;
}
