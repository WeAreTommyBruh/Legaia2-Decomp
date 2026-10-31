/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern char D_0043B3A0[]; void func_0012D398(void); void func_001558F8(void); void func_001557E0(void); int func_001118F8_00154E50(char *) __asm__("func_001118F8"); int func_00154C40(char *, void *); int func_00154CB0(char *, void *);
void *func_002DB188(int, void *, int, void *, void *, void *);
// MATCH func_00154E50
int FUN_00154e50(char *o, char *p) { void *r; if (p == 0) return 0; r = func_002DB188(*(int *)(*(char **)(p + 52) + 4), (void *)func_001558F8, 1, p + **(short **)(p + 52), (void *)func_0012D398, p); if (r != 0) return func_00154C40(o, r); r = func_002DB188(*(int *)(*(char **)(p + 52) + 4), (void *)func_001557E0, 1, p + **(short **)(p + 52), (void *)func_0012D398, p); if (r != 0) return func_00154CB0(o, r); func_001118F8_00154E50(D_0043B3A0); }

extern char D_0043B3A0_00154F28[] __asm__("D_0043B3A0"); void func_0012D398(void); void func_001558F8(void); void func_001557E0(void); int func_001118F8_00154F28(char *) __asm__("func_001118F8"); int func_00154D20(char *, void *); int func_00154DB8(char *, void *);
void *func_002DB188(int, void *, int, void *, void *, void *);
// MATCH func_00154F28
int FUN_00154f28(char *o, char *p) { void *r; if (p == 0) return 0; r = func_002DB188(*(int *)(*(char **)(p + 52) + 4), (void *)func_001558F8, 1, p + **(short **)(p + 52), (void *)func_0012D398, p); if (r != 0) return func_00154D20(o, r); r = func_002DB188(*(int *)(*(char **)(p + 52) + 4), (void *)func_001557E0, 1, p + **(short **)(p + 52), (void *)func_0012D398, p); if (r != 0) return func_00154DB8(o, r); func_001118F8_00154F28(D_0043B3A0_00154F28); }
