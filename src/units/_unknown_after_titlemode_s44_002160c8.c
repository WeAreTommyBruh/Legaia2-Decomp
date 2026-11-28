#include "../common.h"
extern int D_004A6F7C, D_004A1510, D_004A4ADC, D_004A135C, D_004A12A4; extern void *D_004A1360, *D_004A1364; extern char D_00455980[];
int func_00111400(int); void func_0024A510(void); void func_001118F8(char *, ...); void func_0018EA38(void); void func_0023EFB8(void); void func_001976B8(void); void func_0024AD58(int, int, int, int);
void func_00214158(void); void func_0012AE30(void); void func_0023A228(void); void func_00110490(void); void func_00216238(void); void func_00111DF8(void); void func_00215F88(int); void func_002144F0(void); void func_00216050(void); void func_0010F1D8(void);
// MATCH func_002160C8
void ReadInit(void) {
  D_004A6F7C = 1;
  func_00111400(0); func_0024A510();
  func_001118F8(D_00455980, func_00111400(1));
  func_0018EA38(); func_0023EFB8(); func_001976B8(); func_0024AD58(0, 0, 0, 128); func_00214158(); func_0012AE30(); func_0023A228();
  D_004A1360 = func_00110490; D_004A1364 = func_00216238; D_004A135C = 0;
  if (D_004A1510 == 0) { D_004A6F7C = 0; func_00111DF8(); }
  else {
    D_004A12A4 = 1;
    if (D_004A4ADC == 0) { D_004A4ADC = 1; func_00215F88(0); func_002144F0(); }
    else switch (D_004A1510) { case 1: func_00216050(); break; case 2: func_00215F88(1); break; case 3: func_00215F88(3); break; case 4: func_00215F88(4); break; case 6: func_00215F88(6); break; }
    D_004A1510 = 1;
  }
  func_0010F1D8(); }
