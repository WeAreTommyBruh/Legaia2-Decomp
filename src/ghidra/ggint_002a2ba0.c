/* ggint: Ghidra output with hand fixes (narrowed 64-bit types, data addresses as symbols); compiles to the original bytes. */
#include "../ghidra.h"
extern void * D_004A6A04;
extern char D_00424D98[]; extern char D_0041EF40[]; extern char D_004A6850[];
int FUN_00160c70(int param_1, char *param_2, int param_3);
int FUN_00196ff8(void);
void * MallocLoadFileNB(char *path, int flags);
bool PacLoadArea(int param_1);
int clas_min_002a2170(int param_1, char *param_2);
void clas_min_002a2cd0(int param_1, int param_2);
void clas_min_002a3268(int param_1, undefined4 param_2);
void clas_min_002a3908(int param_1);
// MATCH func_002A2BA0
void clas_min_002a2ba0(int param_1)

{
  int lVar1;
  int uVar2;
  
  do {
    lVar1 = FUN_00196ff8();
  } while (lVar1 != 0);
  D_004A6A04 = MallocLoadFileNB(D_00424D98,0);
  uVar2 = FUN_00160c70((int)D_0041EF40,(int)D_004A6850,*(undefined4 *)((int)param_1 + 0xc));
  clas_min_002a2170(param_1,uVar2);
  clas_min_002a2cd0(param_1,1);
  clas_min_002a3268(param_1,*(undefined4 *)((int)param_1 + 8));
  do {
    lVar1 = PacLoadArea(param_1);
  } while (lVar1 == 0);
  clas_min_002a3908(param_1);
  return;
}
