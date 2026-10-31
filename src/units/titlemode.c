/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_00455908[]; void *func_00162130_00214200(int, char *, int) __asm__("func_00162130"); void *func_00214160(void *); int func_00214278(void *, void *); void func_002141B0(void *, int);
// MATCH func_00214200
void *titlemode_00214200(void *a) { void *r = func_00214160(func_00162130_00214200(52, D_00455908, 472)); if (r != 0) { if (func_00214278(r, a) == 0) { func_002141B0(r, 3); r = 0; } } return r; }
