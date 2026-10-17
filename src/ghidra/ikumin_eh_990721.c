/* ikumin_eh_990721: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
// compiler: 990721
#include "../ghidra.h"

extern char D_00451410[];
extern int D_004A4090[];
char * func_002DD4CC(char *dst, char *src);
void * rouge_001334d0(undefined8 param_1, undefined8 param_2, int param_3);
void rouge_00133528(void *param_1, int, int);
char * strcat(char *dst, char *src);
uint strlen(char *s);

#define DAT_004a4090 (D_004A4090[0])
// MATCH func_001F6DE0
void ikumin_001f6de0(int param_1,int param_2)

{
  undefined1 *puVar1;
  int uVar2;
  char *dst;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0xfc) != 0) {
    rouge_00133528(*(int *)(param_1 + 0xfc),((int)D_00451410),0x135);
  }
  *(int *)(param_1 + 0xfc) = 0;
  if (param_2 == 0) {
    puVar1 = (undefined1 *)rouge_001334d0(1,((int)D_00451410),0x139);
    *(undefined1 **)(param_1 + 0xfc) = puVar1;
    *puVar1 = DAT_004a4090;
  }
  else {
    uVar2 = strlen((char *)param_2);
    dst = (char *)rouge_001334d0(uVar2 + 1,((int)D_00451410),0x13e);
    *(char **)(param_1 + 0xfc) = dst;
    func_002DD4CC(dst,(char *)param_2);
    strcat(*(char **)(param_1 + 0xfc),&DAT_004a4090);
  }
  *(int *)(param_1 + 0x100) = uVar2 + 1;
  return;
}
#undef DAT_004a4090
