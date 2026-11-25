// cflags: -O1
#include "../common.h"
// MATCH func_001B4598
int FUN_001b4598(char *o)
{
    int i = 0;
    if (*(int *)(o + 0x4c) > 0) {
        char *e = *(char **)(o + 0x168);
        int n = *(int *)(o + 0x4c);
        do {
            switch (*(e + (i << 8) + 0xfd)) {
            case 2: case 'h': case 'm':
                *(int *)(o + 0x5c) = 0;
                *(int *)(o + 0x60) = 99;
                break;
            }
            i++;
        } while (i < n);
    }
    return 1;
}
