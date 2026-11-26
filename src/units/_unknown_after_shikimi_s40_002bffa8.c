// compiler: 991111-01-as210
#include "../common.h"
typedef unsigned long UL; typedef int u128_2BFFA8 __attribute__((mode(TI)));
typedef struct { UL NLOOP:15; UL EOP:1; UL pad16:16; UL id:14; UL PRE:1; UL PRIM:11; UL FLG:2; UL NREG:4; UL REGS0:4; UL REGS1:4; UL REGS2:4; UL REGS3:4; UL REGS4:4; UL REGS5:4; UL REGS6:4; UL REGS7:4; UL REGS8:4; UL REGS9:4; UL REGS10:4; UL REGS11:4; UL REGS12:4; UL REGS13:4; UL REGS14:4; UL REGS15:4; } __attribute__((aligned(16))) GifTag_2BFFA8;
typedef struct { UL FBP:9; UL pad:55; } Fb_2BFFA8;
typedef struct { UL pmode; UL smode2; Fb_2BFFA8 dispfb; UL display; UL bgcolor; } Disp_2BFFA8;
typedef struct { Fb_2BFFA8 frame; char rest[0x78]; } Draw_2BFFA8;
typedef struct { char d[0x60]; } Clear_2BFFA8;
typedef struct { Disp_2BFFA8 disp[2]; GifTag_2BFFA8 giftag0; Draw_2BFFA8 draw0; Clear_2BFFA8 clear0; GifTag_2BFFA8 giftag1; Draw_2BFFA8 draw1; Clear_2BFFA8 clear1; } DBuff_2BFFA8;
typedef struct { short interlace; short omode; short ffmode; } GParam_2BFFA8;
GParam_2BFFA8 *func_002BF838_2BFFA8(void) __asm__("func_002BF838");
void sceGsDefDispEnv_2BFFA8(Disp_2BFFA8 *, short, short, short, short, short) __asm__("sceGsDefDispEnv");
int func_002BFCD8_2BFFA8(Draw_2BFFA8 *, short, short, short, short, short) __asm__("func_002BFCD8");
int func_002C1780_2BFFA8(Clear_2BFFA8 *, short, short, short, short, short, unsigned char, unsigned char, unsigned char, unsigned char, unsigned) __asm__("func_002C1780");
short func_002C16B8_2BFFA8(short, short, short) __asm__("func_002C16B8");
// MATCH func_002BFFA8
void FUN_002bffa8(DBuff_2BFFA8 *db, short psm, short w, short h, short ztest, short zpsm, short clear) {
  GParam_2BFFA8 *gp = func_002BF838_2BFFA8();
  int fbp;
  sceGsDefDispEnv_2BFFA8(&db->disp[0], psm, w, h, 0, 0);
  sceGsDefDispEnv_2BFFA8(&db->disp[1], psm, w, h, 0, 0);
  func_002BFCD8_2BFFA8(&db->draw0, psm, w, h, ztest, zpsm);
  func_002BFCD8_2BFFA8(&db->draw1, psm, w, h, ztest, zpsm);
  if (clear) {
    func_002C1780_2BFFA8(&db->clear0, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
    func_002C1780_2BFFA8(&db->clear1, ztest, 2048 - (w >> 1), 2048 - (h >> 1), w, h, 0, 0, 0, 0, 0);
  }
  *(u128_2BFFA8 *)&db->giftag0 = 0;
  *(u128_2BFFA8 *)&db->giftag1 = 0;
  db->giftag0.NLOOP = clear ? 14 : 8;
  db->giftag0.EOP = 1;
  db->giftag0.NREG = 1;
  db->giftag0.REGS0 = 0xe;
  db->giftag1.NLOOP = clear ? 14 : 8;
  db->giftag1.EOP = 1;
  db->giftag1.NREG = 1;
  db->giftag1.REGS0 = 0xe;
  fbp = func_002C16B8_2BFFA8(psm, w, h);
  if ((*(UL *)gp & 0xffff0000ffffUL) == 0x100000001UL || gp->interlace == 0) {
    { short sf = fbp >> 1; db->disp[1].dispfb.FBP = sf; db->draw0.frame.FBP = fbp >> 1; }
  }
}
