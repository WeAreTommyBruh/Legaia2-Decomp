/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

extern int D_004A1A50;
extern int D_00425510[];
extern char D_004308E8[], D_004A1980[], D_004A1988[];
int func_001118F8(char *, ...);
void func_0012AEA8(int);

// MATCH func_00123018
void SetBattleEnd(int result)
{
    func_001118F8(D_004308E8);
    if (result == -2) {
        func_001118F8(D_004A1980);
        D_004A1A50 |= 8;
        D_00425510[1] |= 0x12000;
    }
    if (result == -3) {
        func_001118F8(D_004A1988);
        if (D_00425510[1] & 0x8000)
            D_004A1A50 |= 0x400;
        D_00425510[1] = (D_00425510[1] | 0x10000u) & ~0x2000u;
    }
    func_0012AEA8(14);
}

typedef struct { char pad[24]; int mode; } CameraConfig;
typedef struct { char bytes[16]; } CameraBlock;
typedef union { float v[4]; CameraBlock block; } CameraVector;
extern int D_004A13D4, D_004A1A6C;
extern CameraConfig D_00323B40[];
extern CameraVector D_00327A40[], D_0055AB90[];
extern char D_00324520[];
void func_0012AF88(char *, float *);
// MATCH func_00124A48
void battle_00124a48(int id, float time, float x, float y, float z)
{
    CameraVector target;
    if ((D_004A1A6C & 1) == 0) {
        if (time < 1.0f)
            time = 1.0f;
        switch (D_00323B40[D_004A13D4].mode) {
        case 0:
            D_00327A40[0].v[0] -= (D_00327A40[0].v[0] - x) / time;
            D_00327A40[0].v[1] -= (D_00327A40[0].v[1] - y) / time;
            D_00327A40[0].v[2] -= (D_00327A40[0].v[2] - z) / time;
            break;
        case 1:
            target.v[0] = x;
            target.v[1] = y;
            target.v[2] = z;
            target.v[3] = 1.0f;
            func_0012AF88(D_00324520, target.v);
            break;
        }
        D_0055AB90[0].block = D_00327A40[0].block;
    }
}

typedef struct { char pad[32]; float pos[3]; char gap[24]; float height; char rest[116]; short state; } Actor_122EB0;
typedef struct { int id; float v[7]; } View_122EB0;
extern Actor_122EB0 *D_003279A0[];
extern int D_004A6E74, D_004A1A50, D_004A6C50, D_004A6D94, D_004A6C48;
extern float D_0049FDB4;
int func_0012AEA8_122EB0(int) __asm__("func_0012AEA8");
View_122EB0 *func_0021E7C0(void);
int func_00124A48_122EB0(int, float, float, float, float) __asm__("func_00124A48");
void func_0011BC88(int,float,float,float,float,float,float,float);
// MATCH func_00122EB0
void battle_00122eb0(void)
{
    View_122EB0 *v;
    int id;
    if (D_004A6E74 & 0x200040) {
        func_0012AEA8_122EB0(2);
        if (D_004A1A50 & 8)
            func_0012AEA8_122EB0(14);
        return;
    }
    v = func_0021E7C0();
    if (!D_004A6C50)
        D_004A6C50 = 1;
    id = v->id;
    D_004A6D94 = id;
    D_004A6C48 = id;
    if (D_004A1A50 & 0x10000)
        D_003279A0[id]->state = 0;
    if (v->id >= 0) {
        Actor_122EB0 *a = D_003279A0[v->id];
        func_00124A48_122EB0(6557, v->v[0], -a->pos[0], -a->pos[1], -a->pos[2]);
    } else {
        func_00124A48_122EB0(6559, v->v[0], 0.0f, 0.0f, -D_003279A0[0]->pos[2]);
    }
    func_0011BC88(6560,v->v[0],v->v[1],v->v[2]-D_003279A0[v->id]->height-D_0049FDB4,
                  v->v[3],v->v[4],v->v[5],v->v[6]);
}

extern int D_004A6D94,D_004A6D80,D_004A6E9C,D_004A6E74,D_004A1A8C,D_004A1A60,D_004A6D84,D_004A1A20;
extern float D_0049FDAC;
extern float D_00327A40_121F68[] __asm__("D_00327A40");
extern char *D_003279A0_121F68[] __asm__("D_003279A0");
void func_0011B910(int,int,int,int); void func_0011B868(int,int,int);
void func_001297A0(int,int,int,int,int,int),func_0012AEA8(int),func_00122118(void),func_00235130(int,int),func_0021A8F8(int);
// MATCH func_00121F68
void battle_00121f68(void)
{
    int actor=D_004A6D94;
    D_004A6D80=-1;
    D_00327A40_121F68[9]=*(float *)(D_003279A0_121F68[actor]+68)-D_0049FDAC;
    switch(D_004A6E9C) {
    case 4: func_0011B910(160,1,0,-1); break;
    case 2: func_0011B868(160,0,0); break;
    case 5: func_0011B910(60,1,0,0); func_0011B868(160,0,0); break;
    }
    if (D_004A6E74 & 0x200040) {
        register int next __asm__("$3");
        register int total __asm__("$2");

        func_001297A0(0,2,0,1,0,0);
        func_0012AEA8(3);
        next = D_004A6D94 + 1;
        total = D_004A1A8C;
        D_004A6D94 = next;
        if (next >= total)
            func_00122118();
        func_00235130(-1,D_004A1A60);
        D_004A6E74=0;
    }
    D_004A6D80=-1;
    if (D_004A6E74 & 0x100010) {
        func_0012AEA8(D_004A6D84);
        func_00235130(-1,D_004A1A60);
        func_0021A8F8(D_004A1A20+actor*5472);
        D_004A6E74=0;
    }
    D_00327A40_121F68[0]=0;
    D_00327A40_121F68[2]=0;
}
