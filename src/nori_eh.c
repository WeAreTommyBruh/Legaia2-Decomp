/* Functions of nori built with -fexceptions (calls in tail position are
   not turned into jumps): they come from a C++ source file. Matched by
   hand. */
// cflags: -fexceptions
#include "common.h"

typedef struct {
    char unk0[0x20];
    u8 kind;
    char unk21[0x2f - 0x21];
    u8 count;
    char unk30[0x3c - 0x30];
    u8 *snd; /* [0] kind, [1] range, [6] base, [7] set */
} Part;
typedef struct {
    char unk0[0x140];
    Part *part[1];
} PartTable;
typedef struct {
    char unk0[0xa8];
    PartTable *parts;
} Model;

extern int D_004A1A20; /* the battle characters, 0x1560 bytes each */
extern int D_004A5E44, D_004A5E50;
int rand(void);
void FUN_0025feb0(int, int, int);

/* for part `j` of character `i`: calls FUN_0025feb0 with a random id
   around snd[6] (only for the current character, in states 0 and 4, when
   the part's kind is 2) */
// MATCH func_00272E00
void nori_00272e00(int i, int j)
{
    int two;
    int busy = D_004A5E44;
    two = 2;
    if (busy == 0) {
        int c = i * 0x1560 + D_004A1A20;
        Part *p = FIELD(Model *, c, 0x12c0)->parts->part[j];
        u8 *s = p->snd;
        int ok = busy < p->count;
        do {
            do {
            } while (0);
            if (ok && s[0] == 4) {
                if (p->kind == 2) {
                    if (i == D_004A5E50 && (FIELD(int, c, 0x12e4) == 0 || FIELD(int, c, 0x12e4) == 4))
                        FUN_0025feb0(s[7], s[6] + (rand() % (s[1] + 1) - two), 1);
                } else {
                    FUN_0025feb0(s[7], s[6] + (rand() % (s[1] + 1) - two), 1);
                }
            }
        } while (0);
    }
}
