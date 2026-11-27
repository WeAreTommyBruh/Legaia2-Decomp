// compiler: 990721-r5900

typedef struct {
    char pad[393];
    unsigned char count;
    unsigned char ids[78];
} IdList_0025AE60;

typedef struct {
    int id;
    int value;
    char pad[124];
} Entry_0025AE60;

extern IdList_0025AE60 D_00400498[];
extern Entry_0025AE60 D_0040F398[][32];

// MATCH func_0025AE60
int FUN_0025ae60(int a, int b)
{
    int i, k, r;
    IdList_0025AE60 *list;

    if ((unsigned)a >= 10 || b == 0)
        return -1;
    if (a < 5) {
        for (i = 0; i < 32; i++)
            if (b == D_0040F398[a][i].id)
                break;
        if (i == 32)
            return -1;

        list = &D_00400498[a];
        r = 0;
        k = 0;
        if (k >= list->count)
            goto done;
        while (k < list->count) {
            if (list->ids[k] == b)
                r = D_0040F398[a][i].value + 1;
            k++;
        }
        return r;
    } else {
        r = -1;
        if (a == 5) {
            if (b == 14)
                r = 1;
            if (b == 150)
                r = 2;
        }
    }
done:
    return r;
}
