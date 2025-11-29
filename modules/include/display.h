#ifndef DISPLAY_H
#define DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

struct display_cfg {
  int val;
};

int32_t display_get_def_cfg(struct display_cfg *cfg);
int32_t display_init(struct display_cfg *cfg);
int32_t display_start(void);
int32_t display_stub(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // DISPLAY_H