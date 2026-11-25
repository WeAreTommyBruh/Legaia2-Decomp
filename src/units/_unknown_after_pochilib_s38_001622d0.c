// compiler: 990721
// cflags: -fno-schedule-insns
typedef struct { float x, y, z; } V;
typedef struct { int x0; char p[12]; float f[8]; char q[8]; int x38; void *vt; } S;
extern char D_0043C688[];
void func_001625C8(S *); void func_001625E8(S *, float);
// MATCH func_001622D0
S *FUN_001622d0(S *s)
{
  float z = 0.0f;
  s->x38 = 0;
  s->x0 = 0;
  s->vt = D_0043C688;
  s->f[4] = z; s->f[3] = z; s->f[2] = z; s->f[1] = z; s->f[0] = z;
  s->f[7] = z; s->f[6] = z; s->f[5] = z;
  func_001625C8(s);
  func_001625E8(s, 10.0f);
  return s;
}
