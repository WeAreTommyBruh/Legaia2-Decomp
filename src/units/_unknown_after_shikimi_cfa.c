/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_9c80_002D9C80_2D9C80;
typedef struct FSI_9c80_002D9C80_2D9C80 { FS_9c80_002D9C80_2D9C80 s; struct FSI_9c80_002D9C80_2D9C80 *saved_state; } FSI_9c80_002D9C80_2D9C80;
typedef struct { int pad[2]; int code_align; int data_align; } CIE_9c80_002D9C80_2D9C80;
typedef struct { unsigned v; } __attribute__((packed)) PU_9c80;
typedef struct { unsigned short v; } __attribute__((packed)) PS_9c80;
unsigned char *func_002D9480_9c80(unsigned char *, unsigned *) __asm__("func_002D9480");
void *func_002DBC48_9c80(int) __asm__("func_002DBC48");
void func_002DBC70_9c80(void *) __asm__("func_002DBC70");
void func_002DB900_9c80(void) __asm__("func_002DB900");
// MATCH func_002D9C80
unsigned char *FUN_002d9c80(unsigned char *insn_ptr, FSI_9c80_002D9C80_2D9C80 *state, CIE_9c80_002D9C80_2D9C80 *cie, unsigned *pc) { unsigned char insn = *insn_ptr++; unsigned int reg, reg2; int offset; if (insn & 0x40) *pc += (insn & 0x3f) * cie->code_align; else if (insn & 0x80) { reg = (insn & 0x3f); insn_ptr = func_002D9480_9c80(insn_ptr, (unsigned *)&offset); offset = offset * cie->data_align; state->s.saved[reg] = 1; state->s.reg_or_offset[reg] = offset; } else if (insn & 0xc0) { reg = (insn & 0x3f); state->s.saved[reg] = 0; } else switch (insn) { case 1: *pc = ((PU_9c80 *)insn_ptr)->v; insn_ptr += 4; break; case 2: *pc += *insn_ptr++; break; case 3: *pc += ((PS_9c80 *)insn_ptr)->v; insn_ptr += 2; break; case 4: *pc += ((PU_9c80 *)insn_ptr)->v; insn_ptr += 4; break; case 5: insn_ptr = func_002D9480_9c80(insn_ptr, &reg); insn_ptr = func_002D9480_9c80(insn_ptr, (unsigned *)&offset); offset = offset * cie->data_align; state->s.saved[reg] = 1; state->s.reg_or_offset[reg] = offset; break; case 6: insn_ptr = func_002D9480_9c80(insn_ptr, &reg); state->s.saved[reg] = 0; break; case 9: insn_ptr = func_002D9480_9c80(insn_ptr, &reg); insn_ptr = func_002D9480_9c80(insn_ptr, &reg2); state->s.saved[reg] = 2; state->s.reg_or_offset[reg] = reg2; break; case 12: insn_ptr = func_002D9480_9c80(insn_ptr, &reg); insn_ptr = func_002D9480_9c80(insn_ptr, (unsigned *)&offset); state->s.cfa_reg = reg; state->s.cfa_offset = offset; break; case 13: insn_ptr = func_002D9480_9c80(insn_ptr, &reg); state->s.cfa_reg = reg; break; case 14: insn_ptr = func_002D9480_9c80(insn_ptr, (unsigned *)&offset); state->s.cfa_offset = offset; break; case 10: { FSI_9c80_002D9C80_2D9C80 *save = (FSI_9c80_002D9C80_2D9C80 *)func_002DBC48_9c80(sizeof (*save)); *save = *state; state->saved_state = save; break; } case 11: { FSI_9c80_002D9C80_2D9C80 *p = state->saved_state; *state = *p; func_002DBC70_9c80(p); break; } case 0x2d: for (reg = 16; reg < 32; reg++) { state->s.saved[reg] = 1; state->s.reg_or_offset[reg] = (reg - 16) * sizeof (void *); } break; case 0x2e: insn_ptr = func_002D9480_9c80(insn_ptr, (unsigned *)&offset); state->s.args_size = offset; break; case 0: case 7: case 8: break; default: func_002DB900_9c80(); break; } return insn_ptr; }

extern float D_004A0F78;
float func_002B9C00(float);
// MATCH func_002B9C58
float FUN_002b9c58(float a, float b, float cc)
{
  register float c __asm__("$f20") = cc;
  float k = D_004A0F78, v, d;
  v = func_002B9C00(a + (k - b));
  if (v == k) return 0.0f;
  d = v - k;
  if (c <= d) return c;
  if (c <= k - v) return -c;
  return d;
}

long func_002C7F50(char *, int);
int func_002C7DF0(char *);
void func_002C2DA8(char *);
void func_002C7EC0(char *, int, int);
// MATCH func_002C30A0
long FUN_002c30a0(char *mp, int a, int b) {
  char *d = *(char **)(mp + 0x40);
  int last = 0;
  unsigned long r;
  if (b == -1 || a < b) {
    if (*(int *)(d + 8) == 0) { *(int *)(mp + 8) = 0; *(int *)(d + 8) = 1; }
    { register long t __asm__("$3"); if (func_002C7F50(d, 0) == 0) t = 0; else t = func_002C7DF0(d) != 0; r = t; }
  } else {
    r = func_002C7F50(d, 0);
    last = 1;
    func_002C2DA8(mp);
  }
  func_002C7EC0(d, *(int *)(d + 0x118), *(int *)(d + 4));
  if (*(int *)(d + 0x174) != 3 && !last) *(int *)(d + 0x120) = *(int *)(d + 0x120) == 0;
  *(int *)(mp + 8) = *(int *)(d + 0x118) - *(int *)(d + 0xac);
  if (*(int *)(d + 0x120) == 0) { *(int *)(d + 0x118) += 1; *(int *)(d + 4) += 1; }
  return r;
}
