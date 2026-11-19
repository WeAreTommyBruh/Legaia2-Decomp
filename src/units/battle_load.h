#ifndef BATTLE_LOAD_H
#define BATTLE_LOAD_H

typedef struct {
    int pad;
    int size;
    char *data;
    char *name;
} BattleLoadEntry;

typedef struct {
    BattleLoadEntry entries[8];
    char *buffer;
    int remaining;
    int current;
    int totalSize;
} BattleLoadList;

#endif
