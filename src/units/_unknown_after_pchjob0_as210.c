// compiler: 991111-01-as210
typedef struct { char c[16]; } B16_20B230;
typedef struct { char p[32]; B16_20B230 a; B16_20B230 b; char p64[32]; float f96, f100, f104; char p108[64]; short s172; } E_20B230;
typedef struct { char p[8]; int w8; char p12[12]; int fl; char p28[146]; unsigned short s174; char p176[40]; B16_20B230 *src; } O_20B230;
extern float D_004A0408;
extern char D_003C0EF0[];
int rand(void);
E_20B230 *func_00246D88(char *, int);
// MATCH func_0020B230
void FUN_0020b230(O_20B230 *o) {
  float k;
  int i;
  E_20B230 *e;
  register int expired __asm__("$4") = -1;
  int remaining = o->s174 - 1;
  register int signed_remaining __asm__("$3") = (short)remaining;

  o->s174 = remaining;
  if (signed_remaining == expired) {
    o->fl |= 8;
    return;
  }
  k = D_004A0408;
  for (i = 0; i < 1; ++i) {
    e = func_00246D88(D_003C0EF0, o->w8);
    if (e != 0) {
      e->s172 = 0;
      e->a = *o->src;
      e->b = e->a;
      e->f96 = (float)(int)((rand() & 0xff) - 128);
      e->f100 = (float)(int)(rand() & 0xff) + k;
      e->f104 = (float)(int)((rand() & 0xff) - 128);
    }
  }
}
