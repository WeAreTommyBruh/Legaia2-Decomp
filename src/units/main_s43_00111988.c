#include "../common.h"
typedef struct { void *src; int dst; int size; int attr; } Dma;
extern int D_004A154C, D_004A3850;
extern char *D_004A121C;
extern char D_0042EE38[], D_0042EE48[], D_0042EE58[], D_0042EE68[], D_0042EE88[], D_0042EEA8[], D_0042EEB8[];
extern char D_004A1248[], D_004A1250[], D_004A1258[], D_003DC5B0[];
extern char *D_003187A8[];
void func_002E80E8(int);
void func_002EC6F0(void);
void func_00161298(int, int, int);
void *func_00162130(int, char *, int);
void func_0018B7C8(char *, void *);
int func_00196728(char *, void *, int);
void func_001127F8(char *, void *);
int func_001118F8(char *, ...);
void *func_00112A28(char *, char *);
int func_00112A90(char *, char *);
void *func_002DC650(void *, void *, int);
int func_002EC778(int);
void func_002E5B20(int);
int func_002E5C60(Dma *, int);
int func_002DD5E0(char *);
int func_002ED3D8(int, int, char *);
int func_00111400(int);
int func_002EC8E0(int);
// MATCH func_00111988
void main_00111988(void)
{
    void *buf, *dst, *p;
    int size, iop, i, n, r;
    char *s;
    Dma d;
    size = 0;
    func_002E80E8(0);
    func_002EC6F0();
    func_00161298(1, D_004A154C, 0x1984000);
    buf = func_00162130(0x300000, D_0042EE38, 1544);
    dst = func_00162130(0x300000, D_0042EE38, 1545);
    if (D_004A3850 == 0) {
        func_0018B7C8(D_004A1248, buf);
    } else {
        while (func_00196728(D_0042EE48, buf, 8) < 0) ;
    }
    func_001127F8(D_003DC5B0, buf);

    for (i = 0; i < 6; i++) {
        func_001118F8(D_004A1250);
        p = func_00112A28(D_003DC5B0, D_003187A8[i]);
        if (p == 0) {
            func_001118F8(D_0042EE58);
        } else {
            size = func_00112A90(D_003DC5B0, D_003187A8[i]);
            func_002DC650(dst, p, size);
            func_001118F8(D_0042EE68, D_003187A8[i], size);
        }
        iop = func_002EC778(size);
        d.src = dst;
        d.dst = iop;
        d.size = size;
        d.attr = 0;
        func_002E5B20(0);
        func_002E5C60(&d, 1);
        func_001118F8(D_0042EE88, size, iop, dst);
        n = 0;
        s = 0;
        if (i == 5) {
            n = func_002DD5E0(D_004A121C) + 1;
            s = D_004A121C;
        }
        if (func_002ED3D8(iop, n, s) < 0) func_001118F8(D_0042EEA8, D_003187A8[i]);

        r = func_00111400(1);
        func_001118F8(D_0042EEB8, i, r);
        func_002EC8E0(iop);
    }
    func_001118F8(D_004A1258);
}
