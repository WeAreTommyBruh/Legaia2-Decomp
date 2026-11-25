extern int D_004A45E4, D_004A4960, D_004A13EC; extern float D_0041EFB0[]; extern char D_004550E0[];
int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
// MATCH func_0020F118
int pchevent_0020f118(int f)
{
    char buf[512];
    if (f & 8) {
        float *b = D_0041EFB0; float *u = b + 4; float *w = b + 8;
        double t = b[52];
        func_002DCE40(buf, D_004550E0, t, D_004A13EC, (double)b[0], (double)b[1], (double)b[2], (double)u[0], (double)u[1], (double)u[2], (double)w[0], (double)w[1], (double)w[2]);
        func_0020B858(D_004A45E4, buf);
        D_004A4960++;
    }
    return 0;
}
