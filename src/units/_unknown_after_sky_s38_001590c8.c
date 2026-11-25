typedef struct { char a[0x40]; char b[0x40]; } E;
extern E D_00589040[];
extern int D_004A2ABC;
void func_00230CB0(void); void func_0018EB98(void *, int); void func_002492E8(void *);
// MATCH func_001590C8
int FUN_001590c8(int a, int i)
{
  func_00230CB0();
  func_0018EB98(D_00589040[i].a, 0x70003f80);
  func_002492E8(D_00589040[i].b);
  __asm__ volatile ("" : : "r"(i));
  if (i == 0) D_004A2ABC = 1;
  return 1;
}
