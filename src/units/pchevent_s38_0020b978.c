// cflags: -fno-gcse
typedef struct { int a, b, n; void **p; } L;
extern char D_00454D80[]; void func_001621F8(void *, char *, int);
// MATCH func_0020B978
void pchevent_0020b978(L *l, int i)
{
    void **p;
    if (i >= 0 && i < l->n) {
        func_001621F8(l->p[i], D_00454D80, 193);
        l->n--;
        if (i < l->n) {
            p = (void **)(i * 4 + (int)l->p);
            i = l->n - i;
            do { p[0] = p[1]; i--; p++; } while (i != 0);
        }
        l->p[l->n] = 0;
    }
}
