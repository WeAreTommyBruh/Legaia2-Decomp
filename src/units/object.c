/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern unsigned D_004A71E4;
// MATCH func_00243678
void object_00243678(void) { D_004A71E4 = 0xffffffff; }

typedef struct { int a, b; } O_00244450;
// MATCH func_00244450
int object_00244450(O_00244450 *o) { if ((unsigned)(o->a - 27649) < 10239 && (unsigned)(o->b - 30977) < 3583) return 1; return 0; }

typedef struct { char p[16]; unsigned long long *w16; } S_00243A68;
extern unsigned long long D_00318680_00243A68[] __asm__("D_00318680"); void func_00190328_00243A68(S_00243A68 *) __asm__("func_00190328"); void func_00190420_00243A68(S_00243A68 *) __asm__("func_00190420");
// MATCH func_00243A68
void object_00243a68(int i, S_00243A68 *s) { unsigned long long *p; func_00190328_00243A68(s); p = s->w16; p[0] = D_00318680_00243A68[i]; p[1] = 66; s->w16 = p + 2; func_00190420_00243A68(s); }

typedef struct { char p[16]; unsigned long long *w16; } S_00243688;
extern S_00243688 D_00314C20; extern unsigned D_004A71E4_00243688 __asm__("D_004A71E4"); void func_00190328_00243688(S_00243688 *) __asm__("func_00190328"); void func_00190420_00243688(S_00243688 *) __asm__("func_00190420");
// MATCH func_00243688
void object_00243688(void) { unsigned long long *p; func_00190328_00243688(&D_00314C20); p = D_00314C20.w16; p[0] = 0x2007ff8621343140ULL; p[1] = 6; D_00314C20.w16 = p + 2; D_004A71E4_00243688 = 0xffffffff; func_00190420_00243688(&D_00314C20); }
