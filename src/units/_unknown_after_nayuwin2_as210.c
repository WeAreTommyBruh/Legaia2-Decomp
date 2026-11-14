// compiler: 991111-01-as210
extern int D_0036CB88[], D_0036CB60[];
void nayuwin2_001af938(int,char *,int,int);
extern char D_004490B8[], D_004490D8[], D_004490F0[], D_00449108[], D_00449128[], D_00449150[], D_00449160[], D_00449178[], D_00449190[], D_004491A8[], D_004A3C70[];

// MATCH func_001BA170
void FUN_001ba170(int *event)
{
  nayuwin2_001af938(D_0036CB88[12],D_004490B8,1,0);
  *(unsigned char *)(*(int *)(D_0036CB88[12] + 0x168) + 0x1fe) = 0x7f;
  switch (event[1]) {
  case 0:
    nayuwin2_001af938(D_0036CB60[0],D_004490D8,0,0);
    return;
  case 1:
    nayuwin2_001af938(D_0036CB60[0],D_004490F0,0,0);
    return;
  case 2:
    nayuwin2_001af938(D_0036CB60[0],D_00449108,0,0);
    return;
  case 3:
    nayuwin2_001af938(D_0036CB60[0],D_00449128,0,0);
    return;
  case 4:
    nayuwin2_001af938(D_0036CB60[0],D_00449150,0,0);
    return;
  case 5:
    nayuwin2_001af938(D_0036CB60[0],D_00449160,0,0);
    return;
  case 6:
    nayuwin2_001af938(D_0036CB60[0],D_00449178,0,0);
    return;
  case 7:
    nayuwin2_001af938(D_0036CB60[0],D_00449190,0,0);
    return;
  case 8:
    nayuwin2_001af938(D_0036CB60[0],D_004491A8,0,0);
    return;
  case 9:
    nayuwin2_001af938(D_0036CB60[0],D_00449128,0,0);
    return;
  default:
    nayuwin2_001af938(D_0036CB60[0],D_004A3C70,0,1);
    return;
  }
}
