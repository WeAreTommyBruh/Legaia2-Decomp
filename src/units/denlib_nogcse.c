/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_00440540[];
void *func_0018B508(int, void *);
void func_0018BBE0(int, int, void *, int, short, short, short, short);
void func_001621F8_0018C368(void *, void *, int) __asm__("func_001621F8");
// MATCH func_0018C368
void denlib_0018c368(int a, int b, int c, int d, int e) {
    unsigned cnt[4];
    char *ptr, *s, *t, *q;
    ptr = func_0018B508(a, cnt);
    t = ptr;
    s = ptr + 2;
    while (--cnt[0] != 0xffffffff) *t++ = *s++;
    q = ptr + 12;
    if (*(short *)(q + 14) == 24) func_0018BBE0(b, 2, ptr + 52, 1, d, e, *(short *)(q + 4), *(short *)(q + 8));
    func_001621F8_0018C368(ptr, D_00440540, 916);
}
