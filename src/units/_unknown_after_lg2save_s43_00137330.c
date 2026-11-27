extern int D_004A140C;
extern int D_004A238C;
extern int D_004A2390;
extern int *D_00329C10[];
typedef struct
{
  short a;
  short b;
  short c;
  short d;
} Q;
typedef struct
{
  Q q[16];
} E;
extern E D_056308E0[][256][4];
// MATCH func_00137330
unsigned char FUN_00137330(int a, int k)
{
  if ((a != 0) && (D_004A140C & 0x200))
  {
    int j = *D_00329C10[k];
    D_056308E0[D_004A238C][D_004A2390][k].q[j].b = 0;
    D_056308E0[D_004A238C][D_004A2390][k].q[j].a = 0;
    D_056308E0[D_004A238C][D_004A2390][k].q[j].c = 0;
    D_056308E0[D_004A238C][D_004A2390][k].q[j].d = 0;
  }
}
