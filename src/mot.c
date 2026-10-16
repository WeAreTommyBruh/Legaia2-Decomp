/*
 * Motion (.mov) accessors (0x00212f00-0x00213150). A motion file is a clip
 * count followed by byte offsets to each clip; see tools/mov_tool.py for the
 * clip layout. Functions marked MATCH compile to the original bytes with
 * ee-gcc 2.96 -O2 -G8 (check with tools/match.py); the others are kept
 * under NONMATCHING and the build uses the original assembly for them.
 */

typedef unsigned char u8;
typedef unsigned short u16;

/* the clip header of clip `clip` in motion file `mov`
   NONMATCHING: ee-gcc 2.96 adds a `move $v0, $a0` the original does not have */
#ifdef NONMATCHING
u8 *MotClip(int *mov, int clip)
{
    return (u8 *)mov + mov[clip + 1];
}
#else
u8 *MotClip(int *mov, int clip);
#endif

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
