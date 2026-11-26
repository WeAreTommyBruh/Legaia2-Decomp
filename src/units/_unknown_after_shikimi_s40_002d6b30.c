#include "../common.h"
typedef struct { void *cfa; void *eh_ptr; long cfa_offset; long args_size; long reg_or_offset[80]; unsigned short cfa_reg; unsigned short retaddr_column; char saved[80]; } FS_6b30;
struct eh_context_6b30 { void *handler_label; void **dynamic_handler_chain; void *info; void *table_index; };
void func_002D62C8_6b30(void) __asm__("func_002D62C8");
void func_002D6B28_6b30(void) __asm__("func_002D6B28");
FS_6b30 *func_002D6A98_6b30(void *, FS_6b30 *, FS_6b30 *) __asm__("func_002D6A98");
void *func_002D6990_6b30(unsigned, FS_6b30 *, FS_6b30 *) __asm__("func_002D6990");
void func_002D6A18_6b30(unsigned, FS_6b30 *, FS_6b30 *) __asm__("func_002D6A18");
void *func_002D6848_6b30(void *, void *, void *, int, int *) __asm__("func_002D6848");
void *func_002D6770_6b30(void *, void *) __asm__("func_002D6770");
static inline void *get_return_addr_6b30(FS_6b30 *udata, FS_6b30 *sub_udata) { long t = *(long *)func_002D6990_6b30(udata->retaddr_column, udata, sub_udata); return __builtin_extract_return_addr ((void *)t); }
// MATCH func_002D6B30
void *FUN_002d6b30(struct eh_context_6b30 *eh, void *pc, FS_6b30 *my_udata, FS_6b30 **udata_p) {
  FS_6b30 ustruct, saved_ustruct;
  FS_6b30 *sub_udata = &ustruct;
  FS_6b30 *udata = *udata_p;
  void *saved_pc = pc;
  void *handler;
  void *handler_p; void *pc_p; int only_cleanup = 0; int saved_state = 0;
  int cleanup = 0;
  int new_eh_model;
  int rethrow = 0;
  void *eh_info = eh->info;
  if (eh->table_index != 0) rethrow = 1;

  handler = 0;
  for (;;) {
    FS_6b30 *p = udata;
    udata = func_002D6A98_6b30(pc, udata, sub_udata);
    sub_udata = p;
    if (! udata)
      break;
    if (udata->eh_ptr == 0)
      new_eh_model = 0;
    else
      new_eh_model = (*(void **)udata->eh_ptr == (void *)-2);
    if (rethrow) {
      rethrow = 0;
      handler = func_002D6848_6b30(eh->table_index, udata->eh_ptr, eh_info, 1, &cleanup);
      eh->table_index = 0;
    } else if (new_eh_model)
      handler = func_002D6848_6b30(pc, udata->eh_ptr, eh_info, 0, &cleanup);
    else
      handler = func_002D6770_6b30(pc, udata->eh_ptr);
    if (handler) {
      if (cleanup) {
        if (!saved_state) {
          saved_ustruct = *udata;
          handler_p = handler;
          pc_p = pc;
          saved_state = 1;
          only_cleanup = 1;
        }
      } else {
        only_cleanup = 0;
        break;
      }
    }
    pc = (char *) get_return_addr_6b30(udata, sub_udata) - 1;
  }
  if (saved_state) {
    udata = &saved_ustruct;

    handler = handler_p;
    pc = pc_p;

    if (only_cleanup)
      func_002D6B28_6b30();
  }
  if (! handler)
    func_002D62C8_6b30();
  eh->handler_label = handler;
  if (pc == saved_pc)
    udata = my_udata;
  else {
    void *handler_pc = pc;
    int i;
    pc = saved_pc;
    *udata = *my_udata;
    while (pc != handler_pc) {
      FS_6b30 *p = udata;
      udata = func_002D6A98_6b30(pc, udata, sub_udata);
      sub_udata = p;
      for (i = 0; i < 79; ++i)
        if (i != udata->retaddr_column && udata->saved[i])
          func_002D6A18_6b30(i, udata, my_udata);
      pc = (char *) get_return_addr_6b30(udata, sub_udata) - 1;
    }
    if (udata->saved[udata->retaddr_column] == 2) {
      i = udata->reg_or_offset[udata->retaddr_column];
      if (0)
        func_002D6A18_6b30(i, udata, my_udata);
    }
  }
  *udata_p = udata;
  return handler;
}
