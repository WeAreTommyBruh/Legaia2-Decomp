/* Shared types and helpers for the C in src/. */
#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64; /* long is 64 bits with ee-gcc */
typedef unsigned long u64;

/* the field of type `type` at byte offset `off` of the object at `p`
   (used until the game's structures are known) */
#define FIELD(type, p, off) (*(type *)((char *)(p) + (off)))

#endif
