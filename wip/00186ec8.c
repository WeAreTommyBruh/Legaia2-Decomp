#include "../src/common.h"
extern char D_0043FED0[], D_0043FE88[];
void func_00202840(void *);
// WIP func_00186EC8
void *FUN_00186ec8(void *s) {
(*(int *)((char *)s + 2116)) = (int)D_0043FED0;
func_00202840((char *)s + 24);
(*(int *)((char *)s + 2116)) = (int)D_0043FE88;
(*(int *)((char *)s + 2132)) = -1;
(*(int *)((char *)s + 2128)) = -1;
(*(int *)((char *)s + 2136)) = 0;
(*(int *)((char *)s + 2140)) = 0;
(*(int *)((char *)s + 2144)) = 0;
(*(int *)((char *)s + 2148)) = 0;
return s; }
