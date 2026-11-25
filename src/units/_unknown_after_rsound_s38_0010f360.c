// cflags: -G0 -mno-split-addresses
extern volatile int D_1100C000, D_11008000;
// MATCH func_0010F360
void FUN_0010f360(void)
{
  int i;
  i = 0xfff; do { D_1100C000 = 0; i--; } while (i >= 0);
  i = 0xfff; do { D_11008000 = 0; i--; } while (i >= 0);
}
