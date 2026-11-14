/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char p0[6]; unsigned short x6; unsigned short x8; } Pr_2D2D88;
typedef struct { void *s0; Pr_2D2D88 *s4; char p8[8]; unsigned char *ev; } Sq_2D2D88;
typedef struct { char p0[0xc]; unsigned short x0c; char p0e[0x41]; unsigned char b4f; unsigned char b50; unsigned char b51; char p52[6]; } Vc_2D2D88;
typedef struct { volatile unsigned flags; int pc; char p8[0x1e]; unsigned short x26; char p28[2]; unsigned short x2a; unsigned short x2c; unsigned short x2e; char p30[0x1c]; unsigned short x4c; unsigned short x4e; } Tk_2D2D88;
Sq_2D2D88 *func_002CFFA0_2D2D88(void) __asm__("func_002CFFA0");
Vc_2D2D88 *func_002CFF08_2D2D88(int) __asm__("func_002CFF08");
void func_002D3FF8_2D2D88(int, int) __asm__("func_002D3FF8");
void func_002D4010_2D2D88(int, int, int) __asm__("func_002D4010");
void func_002D4040_2D2D88(int, int) __asm__("func_002D4040");
void func_002D4028_2D2D88(int, int) __asm__("func_002D4028");
int SndVoiceSetParam_2D2D88(int, int, int, int) __asm__("SndVoiceSetParam");
// MATCH func_002D2D88
void FUN_002d2d88(Tk_2D2D88 *t) {
  Sq_2D2D88 *s = func_002CFFA0_2D2D88();
  Vc_2D2D88 *p = func_002CFF08_2D2D88(0);
  int i;
  switch (t->x2a) {
  case 0:
    {
      unsigned char v = s->ev[2];
      t->x2a = 0;
      t->x26 = v;
    }
    goto end;
  case 4:
    s->s4->x6 &= 0xff;
    s->s4->x6 |= (127 - s->ev[2]) << 8;
    break;
  case 5:
    s->s4->x6 &= 0xff;
    s->s4->x6 = s->s4->x6 | (127 - s->ev[2]) << 8 | 0x8000;
    break;
  case 6:
    s->s4->x6 &= 0xff0f;
    s->s4->x6 |= (127 - s->ev[2]) >> 3 << 4;
    break;
  case 7:
    s->s4->x6 &= 0xfff0;
    s->s4->x6 |= s->ev[2] >> 3;
    break;
  case 8:
    s->s4->x8 &= 0x3f;
    s->s4->x8 |= (127 - s->ev[2]) << 6;
    s->s4->x8 |= 0x4000 - t->x2e;
    break;
  case 9:
    s->s4->x8 &= 0x3f;
    s->s4->x8 = s->s4->x8 | (127 - s->ev[2]) << 6 | 0x8000U;
    s->s4->x8 |= 0x4000 - t->x2e;
    break;
  case 10:
    s->s4->x8 &= 0xffc0;
    s->s4->x8 |= (127 - s->ev[2]) >> 2;
    break;
  case 11:
    s->s4->x8 &= 0xffc0;
    s->s4->x8 = s->s4->x8 | (127 - s->ev[2]) >> 2 | 0x20;
    break;
  case 12:
    if (s->ev[2] >= 65) t->x2e = 0x4000;
    else t->x2e = 0;
    break;
  case 15:
    func_002D3FF8_2D2D88(0, s->ev[2]);
    func_002D3FF8_2D2D88(1, s->ev[2]);
    goto end;
  case 16:
    func_002D4010_2D2D88(0, s->ev[2], s->ev[2]);
    func_002D4010_2D2D88(1, s->ev[2], s->ev[2]);
    goto end;
  case 17:
    func_002D4040_2D2D88(0, s->ev[2]);
    func_002D4040_2D2D88(1, s->ev[2]);
    goto end;
  case 18:
  case 19:
    func_002D4028_2D2D88(0, s->ev[2]);
    func_002D4028_2D2D88(1, s->ev[2]);
    goto end;
  }
  for (i = 0; i < 48; i++) {
    if (p->b51 == 1 && p->b4f == t->x4e && p->b50 == t->x4c && (t->x2c == 255 || p->x0c == t->x2c)) {
      SndVoiceSetParam_2D2D88(2, i, s->s4->x6, s->s4->x8);
    }
    p++;
  }
end:
  t->pc += 3;
}
