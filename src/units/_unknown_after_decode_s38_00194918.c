typedef struct { int st; char p[0x4ce40 - 4]; } E;
typedef struct { int x0; E *e; int head; int cnt; int size; } Q;
void func_002EDC50(void); void func_002EDC98(void);
// MATCH func_00194918
void FUN_00194918(Q *q)
{
  func_002EDC50();
  q->e[q->head].st = 2;
  q->cnt++;
  { int z = q->cnt % q->size; }
  q->head = (q->head + 1) % q->size;
  func_002EDC98();
}
