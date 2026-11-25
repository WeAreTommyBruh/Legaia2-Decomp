// compiler: 990721-r5900
#include "../common.h"
typedef struct { char pad[148]; int w[56]; unsigned short a[1200]; unsigned char b[1200]; unsigned char c[1200][2]; } G;
extern G D_003FEBA8;
int func_00254938(int);
int func_00250DA0(int);
int func_00254838(void);
void func_002552B8(void);
// MATCH func_00254990
int FUN_00254990(int id)
{
    int i, k;
    if (func_00254938(id & 0xffff) == 0) return -1;
    if (func_00250DA0(id) < 0) return -1;
    if (id < 301) {
        for (i = 0; i < 1200; i++) {
            if (D_003FEBA8.a[i] == id && D_003FEBA8.b[i] == 0) {
                D_003FEBA8.b[i] = 1;
                for (k = 1; k >= 0; k--) D_003FEBA8.c[i][k] = 0;
                break;
            }
        }
        if (i == 1200) {
            for (i = 0; i < 1200; i++) {
                if (D_003FEBA8.a[i] == 0) {
                    D_003FEBA8.a[i] = id;
                    D_003FEBA8.b[i] = 1;
                    for (k = 1; k >= 0; k--) D_003FEBA8.c[i][k] = 0;
                    break;
                }
            }
            if (i == 1200) {
                if (func_00254838() == 0) return -1;
                D_003FEBA8.b[1199] = 1;
                D_003FEBA8.a[1199] = id;
                i = 1199;
                for (k = 1; k >= 0; k--) D_003FEBA8.c[i][k] = 0;
            }
        }
    } else {
        for (i = 0; i < 1200; i++) {
            if (D_003FEBA8.a[i] == id) {
                if (D_003FEBA8.b[i] == 99) return -1;
                D_003FEBA8.b[i]++;
                break;
            }
        }
        if (i == 1200) {
            for (i = 0; i < 1200; i++) {
                if (D_003FEBA8.a[i] == 0 && D_003FEBA8.b[i] == 0) {
                    D_003FEBA8.a[i] = id;
                    D_003FEBA8.b[i] = 1;
                    for (k = 1; k >= 0; k--) D_003FEBA8.c[i][k] = 0;
                    break;
                }
            }
            if (i == 1200) {
                if (func_00254838() == 0) return -1;
                D_003FEBA8.b[1199] = 1;
                D_003FEBA8.a[1199] = id;
                i = 1199;
                for (k = 1; k >= 0; k--) D_003FEBA8.c[i][k] = 0;
            }
        }
    }
    D_003FEBA8.w[id / 32] |= 1 << (id & 31);
    func_002552B8();
    return 0;
}
