/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

void func_002C1CF0(int, int, int, int, int);
// MATCH func_002C1FE8
void FUN_002c1fe8(int a, int b, int c) { func_002C1CF0(a, b, c, 0, -1); }

extern char D_0062B8D8[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC10
void FUN_002ccc10(int a) { func_002CCF20(a, 0, 0, 9, D_0062B8D8); }

extern char D_0062B8D8_002CCC40[] __asm__("D_0062B8D8"); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCC40
void FUN_002ccc40(int a) { func_002CCF20(a, 0, 0, 4, D_0062B8D8_002CCC40); }

extern char D_0062B8D8_002CCBA8[] __asm__("D_0062B8D8"); extern int D_00427DB0[]; void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCBA8
void FUN_002ccba8(int a, int b, int c) { D_00427DB0[0] = 0; func_002CCF20(a, b, c, 5, D_0062B8D8_002CCBA8); }

extern char D_0049F708[];
void func_002ED680(int, void *, int, int);
// MATCH func_002ED7A8
void FUN_002ed7a8(int a, int b) { func_002ED680(a, D_0049F708, b, 1); }

void func_002ED680_002ED788(int, int, int, int) __asm__("func_002ED680");
// MATCH func_002ED788
void FUN_002ed788(int a, int b, int c) { func_002ED680_002ED788(a, b, c, 1); }

extern int D_00427DB0_002CCE30[] __asm__("D_00427DB0"); extern int D_00426350[]; extern char D_0049E238[], D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE30[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE30
void sceCdStPause(void) { D_00427DB0_002CCE30[0] = 0; if (D_00426350[0] > 0) func_002E7940(D_0049E238); func_002CCF20(0, 0, 0, 7, D_0062B8D8_002CCE30); }

extern int D_00427DB0_002CCE80[] __asm__("D_00427DB0"); extern int D_00426350_002CCE80[] __asm__("D_00426350"); extern char D_0049E238_002CCE80[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCE80[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCE80
void sceCdStResume(void) { D_00427DB0_002CCE80[0] = 1; if (D_00426350_002CCE80[0] > 0) func_002E7940(D_0049E250); func_002CCF20(0, 0, 0, 8, D_0062B8D8_002CCE80); }

extern int D_00427DB0_002CCED8[] __asm__("D_00427DB0"); extern int D_00426350_002CCED8[] __asm__("D_00426350"); extern char D_0049E238_002CCED8[] __asm__("D_0049E238"), D_0049E250[], D_0049E268[]; extern char D_0062B8D8_002CCED8[] __asm__("D_0062B8D8");
void func_002E7940(void *); void func_002CCF20(int, int, int, int, void *);
// MATCH func_002CCED8
void sceCdStStat(void) { if (D_00426350_002CCED8[0] > 0) func_002E7940(D_0049E268); func_002CCF20(0, 0, 0, 6, D_0062B8D8_002CCED8); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7ED0
void FUN_002e7ed0(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 1, b, c, d, e, f); }

void func_002E7D58(int, int, int, int, int, int, int);
// MATCH func_002E7E90
void FUN_002e7e90(int a, int b, int c, int d, int e, int f) { func_002E7D58(a, 0, b, c, d, e, f); }

int func_002DBC48(void); void func_002D8148(void) __attribute__((noreturn));
// MATCH func_002D8228
void FUN_002d8228(void) { if (func_002DBC48() == 0) func_002D8148(); }

typedef struct { char p[4]; int w4; } Q_002BAF58;
typedef struct { char p[576]; Q_002BAF58 *w576; } R_002BAF58;
typedef struct { char p[216]; R_002BAF58 *w216; } O_002BAF58;
void func_002ADCC8(Q_002BAF58 *, O_002BAF58 *); void func_002AE0C8(Q_002BAF58 *, O_002BAF58 *);
// MATCH func_002BAF58
void FUN_002baf58(O_002BAF58 *o) { Q_002BAF58 *q = o->w216->w576; if (q != 0) { switch (q->w4) { case 0: func_002ADCC8(q, o); break; case 1: func_002AE0C8(q, o); break; } } }

void func_002C3200(void *, int, int); void func_002C30A0(void *, int, int);
// MATCH func_002C31B8
void FUN_002c31b8(char *o, int b, int c) { if (*(int *)(*(char **)(o + 64) + 372) != 3) func_002C3200(o, b, c); else func_002C30A0(o, b, c); }

int func_002C2F30(int);
// MATCH func_002C2BE0
void FUN_002c2be0(int p, unsigned q, int r, int s) { int e; e = *(int *)(p + 0x40); *(int *)(e + 0xe0) = s << 4; *(unsigned *)(e + 0xd8) = q & 0xfffffff | 0x20000000; *(int *)(e + 0xe4) = r * s; *(int *)(e + 0xdc) = r << 4; *(int *)(e + 0xb0) = 0; func_002C2F30(p); }


typedef struct O_8370 { int f0; short s4, s6; int f8; int f12; void (*dtor)(int, int); int f20; struct O_8370 *next; int pad28; long long cnt; int f40; } O_8370;
O_8370 **func_002D63A8_8370(void) __asm__("func_002D63A8"); void func_002D8148_8370(void) __asm__("func_002D8148") __attribute__((noreturn)); int func_002DB070_8370(int) __asm__("func_002DB070"); void func_002D8250_8370(void *) __asm__("func_002D8250");
// MATCH func_002D8370
void FUN_002d8370(O_8370 *o) {
  O_8370 **pp;
  pp = func_002D63A8_8370();
  o->cnt = o->cnt - 1;
  if (o->cnt != 0) return;
  if (o == *pp && o->f20 == 0) return;
  for (; *pp; pp = &(*pp)->next)
    if (*pp == o) break;
  if (*pp == 0) func_002D8148_8370();
  *pp = o->next;
  if (o->dtor != 0) o->dtor(o->f8, 2);
  if (func_002DB070_8370(o->f12) == 0) func_002D8250_8370((void *)o->f40);
  func_002D8250_8370(o);
}

void func_002DB900_62b8(void) __asm__("func_002DB900") __attribute__((noreturn));
// MATCH func_002D62B8
void FUN_002d62b8(void) { func_002DB900_62b8(); }

struct eh_context_6488 { void *handler_label; void **dynamic_handler_chain; void *info; };
extern struct eh_context_6488 *(*D_00427EF8_6488[])(void) __asm__("D_00427EF8");
void func_002D62C8_6488(void) __asm__("func_002D62C8");
// MATCH func_002D6488
void FUN_002d6488(void) {
  struct eh_context_6488 *eh = (*D_00427EF8_6488[0])();
  void ***dhc = &eh->dynamic_handler_chain;
  void *jmpbuf;
  void (*func)(void *, int);
  void *arg;
  void ***cleanup = (void ***)&(*dhc)[1];
  if (cleanup[0]) {
    double store[200];
    void **buf = (void **)store;
    buf[1] = 0;
    buf[0] = (*dhc);
    if (! __builtin_setjmp (&buf[2])) {
      *dhc = buf;
      while (cleanup[0]) {
        func = (void (*)(void *, int))cleanup[0][1];
        arg = (void *)cleanup[0][2];
        cleanup[0] = (void **)cleanup[0][0];
        (*func)(arg, 2);
      }
      *dhc = buf[0];
    } else {
      func_002D62C8_6488();
    }
  }
  if (! eh->info || (*dhc)[0] == 0)
    func_002D62C8_6488();
  jmpbuf = &(*dhc)[2];
  *dhc = (void **)(*dhc)[0];
  __builtin_longjmp (jmpbuf, 1);
}

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_6e60;
struct eh_context_6e60 { void *handler_label; void **dynamic_handler_chain; void *info; };
extern struct eh_context_6e60 *(*D_00427EF8_6e60[])(void) __asm__("D_00427EF8");
void func_002D62C8_6e60(void) __asm__("func_002D62C8");
FS_6e60 *func_002DA160_6e60(void *, FS_6e60 *) __asm__("func_002DA160");
void *func_002D6B30_6e60(struct eh_context_6e60 *, void *, FS_6e60 *, FS_6e60 **) __asm__("func_002D6B30");
// MATCH func_002D6E60
void FUN_002d6e60(void) {
  struct eh_context_6e60 *eh = (*D_00427EF8_6e60[0])();
  void *pc, *handler;
  FS_6e60 ustruct, ustruct2;
  FS_6e60 *udata = &ustruct;
  FS_6e60 *sub_udata = &ustruct2;
  __builtin_unwind_init ();
  if (! eh->info)
    func_002D62C8_6e60();
label:
  udata = func_002DA160_6e60(&&label, udata);
  if (! udata)
    func_002D62C8_6e60();
  udata->cfa = __builtin_dwarf_cfa ();
  ustruct2 = *udata;
  pc = __builtin_return_address (0) - 1;
  handler = func_002D6B30_6e60(eh, pc, sub_udata, &udata);
  __builtin_eh_return ((int) eh, (char *) udata->cfa - (char *) sub_udata->cfa, handler);
}

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_7040;
struct eh_context_7040 { void *handler_label; void **dynamic_handler_chain; void *info; void *table_index; };
extern struct eh_context_7040 *(*D_00427EF8_7040[])(void) __asm__("D_00427EF8");
void func_002D62C8_7040(void) __asm__("func_002D62C8");
FS_7040 *func_002DA160_7040(void *, FS_7040 *) __asm__("func_002DA160");
void *func_002D6B30_7040(struct eh_context_7040 *, void *, FS_7040 *, FS_7040 **) __asm__("func_002D6B30");
// MATCH func_002D7040
void FUN_002d7040(void *index) {
  struct eh_context_7040 *eh = (*D_00427EF8_7040[0])();
  void *pc, *handler;
  FS_7040 ustruct, ustruct2;
  FS_7040 *udata = &ustruct;
  FS_7040 *sub_udata = &ustruct2;
  __builtin_unwind_init ();
  if (! eh->info)
    func_002D62C8_7040();
  eh->table_index = index;
label:
  udata = func_002DA160_7040(&&label, udata);
  if (! udata)
    func_002D62C8_7040();
  udata->cfa = __builtin_dwarf_cfa ();
  ustruct2 = *udata;
  pc = __builtin_return_address (0) - 1;
  handler = func_002D6B30_7040(eh, pc, sub_udata, &udata);
  __builtin_eh_return ((int) eh, (char *) udata->cfa - (char *) sub_udata->cfa, handler);
}

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_6990;
void func_002DB900_6990(void) __asm__("func_002DB900");
// MATCH func_002D6990
void *FUN_002d6990(unsigned reg, FS_6990 *udata) {
  while (udata->saved[reg] == 2)
    reg = udata->reg_or_offset[reg];
  if (udata->saved[reg] == 1)
    return (void *)((char *)udata->cfa + udata->reg_or_offset[reg]);
  else
    func_002DB900_6990();
}

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_6a18;
void *func_002D6990_6a18(unsigned, FS_6a18 *, FS_6a18 *) __asm__("func_002D6990");
void *memcpy(void *, const void *, unsigned);
// MATCH func_002D6A18
void FUN_002d6a18(unsigned reg, FS_6a18 *udata, FS_6a18 *target_udata) {
  long *preg = func_002D6990_6a18(reg, udata, 0);
  long *ptreg = func_002D6990_6a18(reg, target_udata, 0);
  memcpy(ptreg, preg, __builtin_dwarf_reg_size(reg));
}

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_6a98;
FS_6a98 *func_002DA160_6a98(void *, FS_6a98 *) __asm__("func_002DA160");
void *func_002D6990_6a98(unsigned, FS_6a98 *, FS_6a98 *) __asm__("func_002D6990");
// MATCH func_002D6A98
FS_6a98 *FUN_002d6a98(void *pc, FS_6a98 *udata, FS_6a98 *caller_udata) {
  caller_udata = func_002DA160_6a98(pc, caller_udata);
  if (! caller_udata)
    return 0;
  if (udata->saved[caller_udata->cfa_reg])
    { long t = *(long *)func_002D6990_6a98(caller_udata->cfa_reg, udata, 0); caller_udata->cfa = (void *)t; }
  else
    caller_udata->cfa = udata->cfa;
  caller_udata->cfa += caller_udata->cfa_offset;
  return caller_udata;
}
