/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_0042F2A0[];
int func_00162130_00113928(int, void *, int) __asm__("func_00162130"); void func_002DC804_00113928(int, int, int) __asm__("func_002DC804");
// MATCH func_00113928
int movieplay_00113928(int a) { int r = func_00162130_00113928(a, D_0042F2A0, 187); func_002DC804_00113928(r, 0, a); return r; }

void MemFreeDbg(void *,char *,int);
extern void *D_004A15DC;
extern void *D_004A15E0;
extern void *D_004A15E4;
extern void *D_004A15E8;
extern void *D_004A15C8;
extern void *D_004A15CC;
extern void *D_004A15D0;
extern void *D_004A15D4;
extern void *D_004A15D8;
extern void *D_004A15EC;
extern void *D_004A15F4;
extern void *D_004A15F8;
extern void *D_004A15FC;
extern void *D_004A1604;
extern void *D_004A1600;
extern void *D_004A1608;
extern void *D_004A160C;
// MATCH func_00113CD8
void movieplay_00113cd8(void)
{
  if (D_004A15DC != 0) {
    MemFreeDbg(D_004A15DC,D_0042F2A0,0x1c7);
    D_004A15DC = 0;
  }
  if (D_004A15E0 != 0) {
    MemFreeDbg(D_004A15E0,D_0042F2A0,0x1c8);
    D_004A15E0 = 0;
  }
  if (D_004A15E4 != 0) {
    MemFreeDbg(D_004A15E4,D_0042F2A0,0x1c9);
    D_004A15E4 = 0;
  }
  if (D_004A15E8 != 0) {
    MemFreeDbg(D_004A15E8,D_0042F2A0,0x1ca);
    D_004A15E8 = 0;
  }
  if (D_004A15C8 != 0) {
    MemFreeDbg(D_004A15C8,D_0042F2A0,0x1cc);
    D_004A15C8 = 0;
  }
  if (D_004A15CC != 0) {
    MemFreeDbg(D_004A15CC,D_0042F2A0,0x1cd);
    D_004A15CC = 0;
  }
  if (D_004A15D0 != 0) {
    MemFreeDbg(D_004A15D0,D_0042F2A0,0x1ce);
    D_004A15D0 = 0;
  }
  if (D_004A15D4 != 0) {
    MemFreeDbg(D_004A15D4,D_0042F2A0,0x1cf);
    D_004A15D4 = 0;
  }
  if (D_004A15D8 != 0) {
    MemFreeDbg(D_004A15D8,D_0042F2A0,0x1d0);
    D_004A15D8 = 0;
  }
  if (D_004A15EC != 0) {
    MemFreeDbg(D_004A15EC,D_0042F2A0,0x1d1);
    D_004A15EC = 0;
  }
  if (D_004A15F4 != 0) {
    MemFreeDbg(D_004A15F4,D_0042F2A0,0x1d3);
    D_004A15F4 = 0;
  }
  if (D_004A15F8 != 0) {
    MemFreeDbg(D_004A15F8,D_0042F2A0,0x1d4);
    D_004A15F8 = 0;
  }
  if (D_004A15FC != 0) {
    MemFreeDbg(D_004A15FC,D_0042F2A0,0x1d5);
    D_004A15FC = 0;
  }
  if (D_004A1604 != 0) {
    MemFreeDbg(D_004A1604,D_0042F2A0,0x1d6);
    D_004A1604 = 0;
  }
  if (D_004A1600 != 0) {
    MemFreeDbg(D_004A1600,D_0042F2A0,0x1d7);
    D_004A1600 = 0;
  }
  if (D_004A1608 != 0) {
    MemFreeDbg(D_004A1608,D_0042F2A0,0x1d8);
    D_004A1608 = 0;
  }
  if (D_004A160C != 0) {
    MemFreeDbg(D_004A160C,D_0042F2A0,0x1d9);
    D_004A160C = 0;
  }
  return;
}
