/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_004570A8[]; void func_001118F8_0021E910(char *, ...) __asm__("func_001118F8"); void func_00220B48(void *);
// MATCH func_0021E910
void batread_0021e910(char *o) { int i; if (*(int *)(o + 6976) >= 64) { func_001118F8_0021E910(D_004570A8); return; } i = *(int *)(o + 6980); *(o + i + 4608) = 4; func_00220B48(o); }

extern int D_004A6FDC, D_004A6FC4, D_004A6FC0, D_004A4D98, D_004A4D9C; extern char D_00457098[]; void func_0021EFE0(char *); void *func_00162130_0021E870(int, char *, int) __asm__("func_00162130"); int func_00202840(void *);
// MATCH func_0021E870
void batread_0021e870(char *o) { D_004A6FDC = 0; D_004A6FC4 = 0; D_004A6FC0 = 0; *(int *)(o + 7164) = 0; *(int *)(o + 7236) = 0; *(int *)(o + 8192) = 0; *(int *)(o + 8188) = 0; *(int *)(o + 7624) = 0; *(int *)(o + 6976) = 0; *(int *)(o + 6984) = 0; *(int *)(o + 6980) = 0; *(int *)(o + 6988) = 0; *(int *)(o + 7012) = 0; *(int *)(o + 7004) = 0; *(int *)(o + 7008) = 0; func_0021EFE0(o); D_004A4D98 = func_00202840(func_00162130_0021E870(36, D_00457098, 59)); D_004A4D9C = func_00202840(func_00162130_0021E870(36, D_00457098, 60)); }

extern char D_004570A8_0021F048[] __asm__("D_004570A8"), D_00457158[]; void func_001118F8_0021F048(char *, ...) __asm__("func_001118F8"); void func_002DD4CC_0021F048(char *, char *) __asm__("func_002DD4CC"); void func_00220B48_0021F048(char *) __asm__("func_00220B48");
// MATCH func_0021F048
void batread_0021f048(char *o, char *a, int b) { if (*(int *)(o + 6976) >= 64) { func_001118F8_0021F048(D_004570A8_0021F048); return; } func_002DD4CC_0021F048(o + 512 + (*(int *)(o + 6980) << 6), a); *(int *)(o + (*(int *)(o + 6980) << 2) + 4672) = b; *(o + *(int *)(o + 6980) + 4608) = 8; func_001118F8_0021F048(D_00457158, b, a, *(int *)(o + 6976)); func_00220B48_0021F048(o); }

extern char D_004570A8_0021ECB0[] __asm__("D_004570A8"); void func_001118F8_0021ECB0(char *, ...) __asm__("func_001118F8"); void func_002DD4CC_0021ECB0(char *, char *) __asm__("func_002DD4CC"); void func_00220B48_0021ECB0(char *) __asm__("func_00220B48");
// MATCH func_0021ECB0
void batread_0021ecb0(char *o, char *a, int b) { int i; if (*(int *)(o + 6976) >= 64) { func_001118F8_0021ECB0(D_004570A8_0021ECB0); return; } func_002DD4CC_0021ECB0(o + 512 + (*(int *)(o + 6980) << 6), a); i = *(int *)(o + 6980); *(int *)(o + (i << 2)) = b; *(o + i + 4608) = 1; func_00220B48_0021ECB0(o); }

extern int D_004A1688; extern char D_004570A8_0021EE50[] __asm__("D_004570A8"); void func_001118F8_0021EE50(char *, ...) __asm__("func_001118F8"); void func_002DD4CC_0021EE50(char *, char *) __asm__("func_002DD4CC"); void func_00220B48(void *);
// MATCH func_0021EE50
void batread_0021ee50(char *o, char *s, int a, int b) { int i; if (D_004A1688 == 0) return; if (*(int *)(o + 6976) >= 64) { func_001118F8_0021EE50(D_004570A8_0021EE50); return; } func_002DD4CC_0021EE50(o + 512 + (*(int *)(o + 6980) << 6), s); i = *(int *)(o + 6980); *(int *)(o + (i << 2)) = a; *(o + i + 4608) = 6; *(int *)(o + (*(int *)(o + 6980) << 2) + 4672) = b; func_00220B48(o); }

extern int D_004A1688_0021EF18 __asm__("D_004A1688"); extern char D_004570A8_0021EF18[] __asm__("D_004570A8"); void func_001118F8_0021EF18(char *, ...) __asm__("func_001118F8"); void func_002DD4CC_0021EF18(char *, char *) __asm__("func_002DD4CC"); void func_00220B48(void *);
// MATCH func_0021EF18
void batread_0021ef18(char *o, char *s, int a, int b) { int i; if (D_004A1688_0021EF18 == 0) return; if (*(int *)(o + 6976) >= 64) { func_001118F8_0021EF18(D_004570A8_0021EF18); return; } func_002DD4CC_0021EF18(o + 512 + (*(int *)(o + 6980) << 6), s); i = *(int *)(o + 6980); *(int *)(o + (i << 2)) = a; *(o + i + 4608) = 7; *(int *)(o + (*(int *)(o + 6980) << 2) + 4672) = b; func_00220B48(o); }

extern char D_004570A8_0021E960[] __asm__("D_004570A8"); extern char *D_003CA240[]; extern int D_003293A0[]; void func_001118F8_0021E960(char *, ...) __asm__("func_001118F8"); void func_002DD4CC_0021E960(char *, char *) __asm__("func_002DD4CC"); void func_00220B48(void *);
// MATCH func_0021E960
void batread_0021e960(char *o, int k) { int i; char *src; if (*(int *)(o + 6976) >= 64) { func_001118F8_0021E960(D_004570A8_0021E960); return; } i = *(int *)(o + 6980); src = D_003CA240[k]; D_003293A0[k] = 0; func_002DD4CC_0021E960(o + 512 + (i << 6), src); *(int *)(o + (*(int *)(o + 6980) << 2) + 4672) = k; *(o + *(int *)(o + 6980) + 4608) = 11; func_00220B48(o); }
