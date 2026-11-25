// cflags: -fno-gcse
typedef struct { char *name; int (*fn)(int); } MI;
extern int D_004A5430, D_004A13FC, D_004A1400, D_004A140C; extern char D_004A48C0[];
void func_0023B8A0(int, int, int, int, int, int); void func_00239568(char *, int, int, int, char *);
// MATCH func_0020EEA0
int pchevent_0020eea0(int x, int y, int w, int h, MI *m)
{
    int tx = x + 4;
    int ty;
    int sel;
    int i;
    int c;
    int w8;
    func_0023B8A0(D_004A5430, x - 1, y - 1, w + 2, h + 2, 0x202020);
    func_0023B8A0(D_004A5430, x, y, w, h, 0x606060);
    ty = y + 2;
    sel = -1;
    w8 = w - 8;
    i = 0;
    if (m->name != 0) {
    MI *p = m;
    do {
        if (p->name[0] == 0) {
            func_0023B8A0(D_004A5430, x + 1, ty + 1, w - 2, 1, 0x484848);
            ty += 3;
        } else {
            int ny;
            c = 0x404040;
            ny = ty + 7;
            if (tx <= D_004A13FC && D_004A13FC < tx + w8 && ty <= D_004A1400 && D_004A1400 < ny) {
                c = 0x208060;
                sel = i;
            }
            func_00239568(D_004A48C0, tx, ty, c, p->name);
            ty = ny;
        }
        p++;
        i++;
    } while (p->name != 0);
    }
    if (sel >= 0) return m[sel].fn(D_004A140C);
    return 0;
}
