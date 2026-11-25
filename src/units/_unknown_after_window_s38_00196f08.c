// compiler: 990721
typedef struct { unsigned int lsn; unsigned int size; char name[16]; char date[8]; int flag; char pad[12]; } F;
extern unsigned int D_00343030[];
int func_002CB958(F *, char *);
// MATCH func_00196F08
int FUN_00196f08(char *name, unsigned int *lsn, unsigned int *nsec)
{
  F f;
  if (func_002CB958(&f, name) == 0) return -1;
  *lsn = f.lsn;
  *nsec = (f.size + D_00343030[0] - 1) / D_00343030[0];
  return 1;
}
