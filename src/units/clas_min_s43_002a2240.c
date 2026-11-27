// compiler: 990721-r5900
extern char D_00424A98[];
extern char D_00424B18[];
extern char D_00424D18[];
extern char D_00424D98[];
extern char D_0049ADF0[];
extern char D_0049AE08[];
extern char D_0049AE28[];
int func_002DCE40(char *, char *, ...);
// MATCH func_002A2240
int clas_min_002a2240(void)
{
  char buf[32];
  int delimiter;
  int i;
  char *s;
  char *d;
  for (i = 0; i < 32; i++)
  {
    buf[i] = 0;
  }

  if ((D_00424A98[18] != '.') && (D_00424A98[18] != 0))
  {
    s = D_00424A98 + 18;
    delimiter = '.';
    d = buf;
    do
    {
      *(d++) = *(s++);
    }
    while (((*s) != delimiter) && ((*s) != 0));
  }
  func_002DCE40(D_00424B18, D_0049ADF0, buf);
  func_002DCE40(D_00424D18, D_0049AE08, buf);
  return func_002DCE40(D_00424D98, D_0049AE28, buf);
}
