/*
 * Motion (.mov) accessors (0x00212f00-0x00213150). A motion file is a clip
 * count followed by byte offsets to each clip; see tools/mov_tool.py for the
 * clip layout. Functions marked MATCH compile to the original bytes with
 * ee-gcc 2.9-ee-991111-01 -O2 -G8 (check with tools/match.py); the others are kept
 * under NONMATCHING and the build uses the original assembly for them.
 */

#include "common.h"

/* bone record of the packed layout (section 2) */
typedef struct {
    u16 name;       /* offset into the name section */
    u16 base;       /* base vector index */
    u16 mask;       /* channels present */
    u16 seg[9];     /* first segment of tx ty tz rx ry rz sx sy sz */
} MotBone;

/* the clip header of clip `clip` in motion file `mov` */
// MATCH func_00212F00
u8 *MotClip(int *mov, int clip)
{
    return (u8 *)mov + mov[clip + 1];
}

// MATCH func_00212F18
int MotClipCount(int *mov)
{
    return *mov;
}

// MATCH func_00212F20
char *MotClipName(int *mov, int clip)
{
    return (char *)MotClip(mov, clip) + 8;
}

// MATCH func_00212F40
u8 MotHierarchyLength(int *mov, int clip)
{
    return MotClip(mov, clip)[7];
}

// MATCH func_00212F60
u8 MotIndexMapLength(int *mov, int clip)
{
    return MotClip(mov, clip)[5];
}

// MATCH func_00213048
u8 MotBoneCount(int *mov, int clip)
{
    return *MotClip(mov, clip);
}

// MATCH func_00213068
u16 MotFrameCount(int *mov, int clip)
{
    return *(u16 *)(MotClip(mov, clip) + 2);
}

/* flag 0x20: packed (new) layout */
// MATCH func_00213088
int MotIsPacked(int *mov, int clip)
{
    return MotClip(mov, clip)[1] >> 5 & 1;
}

// MATCH func_002130B0
int MotIsHalfRate(int *mov, int clip)
{
    return MotClip(mov, clip)[1] & 1;
}

// MATCH func_002130D8
int MotFlag02(int *mov, int clip)
{
    return MotClip(mov, clip)[1] >> 1 & 1;
}

// MATCH func_00213100
int MotHasScale(int *mov, int clip)
{
    return MotClip(mov, clip)[1] >> 4 & 1;
}

// MATCH func_00213128
int MotFlag40(int *mov, int clip)
{
    return MotClip(mov, clip)[1] >> 6 & 1;
}

/* flag 0x80: rotations in 1/16384 turns */
// MATCH func_00213150
int MotIsFineRotation(int *mov, int clip)
{
    return MotClip(mov, clip)[1] >> 7;
}

/* hierarchy: after the old layout's 0x30-byte bone records, or section 0 */
// MATCH func_00212F80
u8 *MotHierarchy(int *mov, int clip)
{
    u8 *c;

    if (MotIsPacked(mov, clip) == 0)
        return (u8 *)mov + (((u8 *)mov)[7] * 48 + 0x68);
    c = MotClip(mov, clip);
    return c + *(int *)(c + 0x2c);
}

/* index map: after the old layout's hierarchy, or section 1 */
// MATCH func_00212FE0
u8 *MotIndexMap(int *mov, int clip)
{
    u8 *c;

    if (MotIsPacked(mov, clip) == 0)
        return (u8 *)mov + ((u8 *)mov)[7] + (((u8 *)mov)[7] * 48 + 0x68);
    c = MotClip(mov, clip);
    return c + *(int *)(c + 0x30);
}

/* the name of bone `bone`
   NONMATCHING: the record address is added in the other register order */
#ifdef NONMATCHING
char *MotBoneName(int *mov, int clip, int bone)
{
    u8 *c;

    if (MotIsPacked(mov, clip) == 0)
        return (char *)mov + (bone * 48 + 0x68);
    c = MotClip(mov, clip);
    return (char *)c + *(int *)(c + 0x38) + ((MotBone *)(c + *(int *)(c + 0x34)))[bone].name;
}
#else
char *MotBoneName(int *mov, int clip, int bone);
#endif

/* blend envelopes (extra table bit 2, offset at +0x50) */
// MATCH func_00213FC8
int MotEnvelopeCount(int *mov, int clip)
{
    u8 *c = MotClip(mov, clip);
    int flags = *(int *)(c + 0x48);

    if (flags == -1 || (flags & 2) == 0)
        return 0;
    return *(int *)(c + *(int *)(c + 0x50));
}

// MATCH func_00214010
u8 *MotEnvelope(int *mov, int clip, int i)
{
    u8 *c = MotClip(mov, clip);
    int flags = *(int *)(c + 0x48);

    if (flags == -1 || (flags & 2) == 0)
        return 0;
    return c + *(int *)(c + 0x50) + (i * 16 + 4);
}

/* attachments (extra table bit 4, offset at +0x54) */
// MATCH func_00214068
int MotAttachmentCount(int *mov, int clip)
{
    u8 *c = MotClip(mov, clip);
    int flags = *(int *)(c + 0x48);

    if (flags == -1 || (flags & 4) == 0)
        return 0;
    return *(int *)(c + *(int *)(c + 0x54));
}

// MATCH func_002140B0
u8 *MotAttachment(int *mov, int clip, int i)
{
    u8 *c = MotClip(mov, clip);
    int flags = *(int *)(c + 0x48);

    if (flags == -1 || (flags & 4) == 0)
        return 0;
    return c + *(int *)(c + 0x54) + (i * 32 + 4);
}

/* the word at +0x28 of a packed clip (0 for the old layout) */
// MATCH func_00214108
int MotClipWord28(int *mov, int clip)
{
    if (MotIsPacked(mov, clip) == 0)
        return 0;
    return *(int *)(MotClip(mov, clip) + 0x28);
}
