// compiler: 990721
// MATCH func_0018A1C8
char *file_0018a1c8(char *s)
{
  if (s == 0) return 0;
  while (*s != '.' && *s != 0) s++;
  if (*s == '.') s++;
  return s;
}
