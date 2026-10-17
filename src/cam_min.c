/* cam_min.cpp (group cam_min in decomp/functions.csv): the camera's list of
   positions. Matched by hand. */
#include "common.h"

extern char D_0049B568[]; /* the source file name, for MemFreeDbg */
void MemFreeDbg(void *, char *, int);

/* frees the list at *list (linked through +0x4c) */
// MATCH func_002AA8A0
void cam_min_002aa8a0(int *list)
{
    int *head;
    int next;
    head = list;
    do {
    } while (0); /* an assertion, compiled out */
    if (*head != 0) {
        do {
            next = FIELD(int, *head, 0x4c);
            MemFreeDbg((void *)*head, D_0049B568, 507);
            *list = next;
        } while (next != 0);
    }
}
