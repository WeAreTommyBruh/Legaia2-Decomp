/* Ghidra's type names, for the functions in src/ghidra/ (Ghidra's
   decompilation kept where it compiles to the original bytes). With
   ee-gcc, long is 64 bits, like Ghidra's. */
#ifndef GHIDRA_H
#define GHIDRA_H

typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned int dword;
typedef unsigned int uint;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long undefined8;
typedef unsigned short word;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef char bool;
typedef int code();

#endif
