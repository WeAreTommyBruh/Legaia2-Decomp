// cflags: -fno-gcse

typedef struct {
    char pad00[0x12cc];
    int selectedCommand;
    char pad12d0[0x94];
    int state;
    char pad1368[0x1f8];
} BattleCommandSlot_121C90;

typedef struct { char data[128]; } BattleCommand_121C90;

extern int D_004A6DA4, D_004A6D94, D_004A6D80, D_004A1A48, D_004A6D84;
extern unsigned int D_004A6E74;
extern BattleCommandSlot_121C90 *D_004A1A20_121C90 __asm__("D_004A1A20");
extern float D_0049FDA4, D_0049FDA8;
extern BattleCommand_121C90 D_00327DA0[];
extern int D_004A1A8C, D_004A1A2C, D_004A1A54, D_004A1A58, D_004A1A60;

extern void func_00232028(float, BattleCommand_121C90 *);
extern void func_001100B8(void);
extern void func_001297A0(int, int, int, int, int, int);
extern void func_0021A8F8(BattleCommandSlot_121C90 *);
extern void func_0012AEA8(int);
extern void func_0012C800(int);
extern void func_0012C1D8(int, int);
extern void func_0011BB28(int, int, int, int, int);
extern void func_00122118(void);
extern void func_00235130(int, int);

// MATCH func_00121C90
void battle_00121c90(void)
{
    int slot = D_004A6D94;
    int selection = D_004A6DA4;
    D_004A6D80 = -1;
    if (D_004A1A48 == 0) {
        if (D_004A6D84 == 7 && D_004A1A20_121C90[slot].state == 4)
            D_004A6E74 &= 0xfff35fff;
        if (D_004A6E74 & 0x82000) {
            func_00232028(D_0049FDA4, &D_00327DA0[selection]);
            D_004A6DA4++;
            if (D_004A6DA4 > D_004A1A8C - 1)
                D_004A6DA4 = 0;
            D_004A1A2C = 10;
            func_001100B8();
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x48000) {
            func_00232028(D_0049FDA8, &D_00327DA0[selection]);
            D_004A6DA4--;
            if (D_004A6DA4 < 0)
                D_004A6DA4 = D_004A1A8C - 1;
            D_004A1A2C = 10;
            func_001100B8();
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x200040) {
            D_004A1A2C = 0;
            if (D_004A1A54 != 0 && D_004A6DA4 != 0) {
                func_001297A0(0, 2, 0, 3, 0, 0);
                D_004A1A58 = -1;
                D_004A1A54 += 2;
            } else {
                D_004A1A48 = 1;
            }
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x100010) {
            D_004A1A2C = 0;
            func_001297A0(0, 2, 0, 2, 0, 0);
            func_0021A8F8(&D_004A1A20_121C90[slot]);
            func_0012AEA8(D_004A6D84);
            D_004A6E74 = 0;
        }
        if (selection != D_004A6DA4)
            func_001297A0(0, 2, 0, 0, 0, 0);
        func_0012C800(selection);
    } else {
        D_004A1A48++;
    }
    selection = D_004A6DA4;
    func_0012C1D8(selection, 0);
    func_0011BB28(selection, 12, 160, 0, 0);
    if (D_004A1A48 > 10) {
        D_004A1A48 = 0;
        func_001297A0(0, 2, 0, 1, 0, 0);
        D_004A1A20_121C90[slot].selectedCommand = D_004A6DA4;
        func_0012AEA8(3);
        {
            int next;
            register int count __asm__("$2");
            next = D_004A6D94 + 1;
            count = D_004A1A8C;
            D_004A6D94 = next;
            if (next >= count)
                func_00122118();
        }
        func_00235130(-1, D_004A1A60);
    }
}
