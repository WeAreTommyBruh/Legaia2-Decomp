/* Battle camera mode dispatcher and its entry thunk. */

typedef struct { char pad[620]; int state; } CameraState;
extern CameraState *D_004A1A94;
extern char D_0053FD30[];
void func_002A3ED8(void *, int);
void func_00219ED8(CameraState *, int, int);
void func_002194E0(CameraState *, int);
void func_002194B0(CameraState *);
// MATCH func_001265D8
void battle_001265d8(int mode)
{
    D_004A1A94->state = mode;
    switch (mode) {
    case 0: break;
    case 1: func_002A3ED8(D_0053FD30, 1); break;
    case 2: func_002A3ED8(D_0053FD30, 2); break;
    case 3: func_002A3ED8(D_0053FD30, 3); break;
    case 4: func_002A3ED8(D_0053FD30, 4); break;
    case 5: func_002A3ED8(D_0053FD30, 5); break;
    case 6: func_002A3ED8(D_0053FD30, 6); break;
    case 7: func_00219ED8(D_004A1A94, 32, 0); break;
    case 8: func_00219ED8(D_004A1A94, 32, 128); break;
    case 9: func_002194E0(D_004A1A94, 0); func_002194B0(D_004A1A94); break;
    }
}
