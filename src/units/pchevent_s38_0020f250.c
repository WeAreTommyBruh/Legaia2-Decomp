extern int D_004A45E4, D_004A4960, D_004A13EC; extern float D_0041EFB0[]; extern char D_00455138[];
int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
// MATCH func_0020F250
int pchevent_0020f250(int f)
{
    char buf[512];
    if (f & 8) {
        float *b = D_0041EFB0; float *q = b + 48;
        double t = b[52], q0 = q[0], q1 = q[1], q2 = q[2], q3 = q[3];
        func_002DCE40(buf, D_00455138, t, D_004A13EC, (double)b[0], (double)b[1], (double)b[2], q0, q1, q2, q3);
        func_0020B858(D_004A45E4, buf);
        D_004A4960++;
    }
    return 0;
}
