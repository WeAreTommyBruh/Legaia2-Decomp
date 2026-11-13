/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct {char f,c;} E_002E6750; typedef struct {int x,idx;E_002E6750 e[512];} S_002E6750;
extern int D_00429880_002E6750[] __asm__("D_00429880"), D_00631F00_002E6750[] __asm__("D_00631F00"); extern S_002E6750 D_00631F08_002E6750 __asm__("D_00631F08"); int func_002E57E0_002E6750(unsigned) __asm__("func_002E57E0"); void func_002E58D0_002E6750(int) __asm__("func_002E58D0");
// MATCH func_002E6750
int FUN_002e6750(unsigned c) {__asm__ volatile("" : : "r"(c));{ unsigned v; int i; { register int n __asm__("$3") = -47; register unsigned rv __asm__("$2"); __asm__ volatile ("syscall" : "=r"(rv) : "r"(n)); v = rv; } if(v != c) return func_002E57E0_002E6750(c); if(v>=256 || D_00429880_002E6750[0]==0) return -1; i=D_00631F08_002E6750.idx &511; D_00631F08_002E6750.idx=i+1; D_00631F08_002E6750.e[i].f=0; D_00631F08_002E6750.e[i].c=v; func_002E58D0_002E6750(D_00631F00_002E6750[0]); return v; }
}

extern void (*D_00429888_002E71B0[])(int) __asm__("D_00429888");
extern const double D_0049F548_002E71B0[] __asm__("D_0049F548"),D_0049F550_002E71B0[] __asm__("D_0049F550"),D_0049F558_002E71B0[] __asm__("D_0049F558");
extern char D_0049F530_002E71B0[] __asm__("D_0049F530"),D_0049F538_002E71B0[] __asm__("D_0049F538"),D_0049F540_002E71B0[] __asm__("D_0049F540");
int func_002D7E48_002E71B0(double,double) __asm__("func_002D7E48");
unsigned long func_002EF470_002E71B0(double) __asm__("func_002EF470");
int func_002E7120_002E71B0(unsigned long) __asm__("func_002E7120");
void func_002E7908_002E71B0(char *,...) __asm__("func_002E7908");
// MATCH func_002E71B0
void FUN_002e71b0(double x) {
 int e=0;
 if(func_002D7E48_002E71B0(x,0.)<0){x=0.-x;D_00429888_002E71B0[0](45);}
 if(func_002D7E48_002E71B0(x,0.1)<0){
  while(func_002D7E48_002E71B0(x,0.1)<0){e--;x*=10.;}
 }else if(func_002D7E48_002E71B0(x,1.)>=0){
  while(func_002D7E48_002E71B0(x,1.)>=0){e++;x/=10.;}
 }
 {int n=func_002E7120_002E71B0(func_002EF470_002E71B0(x*1000000.0)); char *fmt=D_0049F530_002E71B0;func_002E7908_002E71B0(fmt,n);}
 if(e>=0){func_002E7908_002E71B0(D_0049F538_002E71B0,e);return;}
 func_002E7908_002E71B0(D_0049F540_002E71B0,e);
}
