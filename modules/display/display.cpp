
extern "C" {
#include "cmd.h"
#include "dio.h"
#include "log.h"
#include "module.h"
#include <stdio.h>
}

#include "display.h"

////////////////////////////////////////////////////////////////////////////////
// Type definitions
////////////////////////////////////////////////////////////////////////////////

enum states {
  STATE_OFF,
};

struct display_state {
  struct display_cfg cfg;
  enum states state;
  bool valid_dio;
  uint32_t blink_counter;
  int32_t tmr_id;
};

////////////////////////////////////////////////////////////////////////////////
// Private (static) function declarations
////////////////////////////////////////////////////////////////////////////////

static int32_t cmd_display_status(int32_t argc, const char **argv);

////////////////////////////////////////////////////////////////////////////////
// Private (static) variables
////////////////////////////////////////////////////////////////////////////////

static int32_t log_level = LOG_DEFAULT;

static struct display_state state = {};

static struct cmd_cmd_info cmds[] = {
    {
        .name = "status",
        .func = cmd_display_status,
        .help = "Get module status, usage: display status",
    },
};

static struct cmd_client_info cmd_info = {
    .name = "display",
    .num_cmds = ARRAY_SIZE(cmds),
    .cmds = cmds,
    .log_level_ptr = &log_level,
};

////////////////////////////////////////////////////////////////////////////////
// Public (global) functions
////////////////////////////////////////////////////////////////////////////////

int32_t display_get_def_cfg(struct display_cfg *cfg) {
  if (cfg == NULL)
    return MOD_ERR_ARG;

  //   memset(cfg, 0, sizeof(*cfg));
  //   cfg->code_num_blinks = 1;
  //   cfg->code_period_ms = 1000;
  //   cfg->sep_num_blinks = 5;
  //   cfg->sep_period_ms = 200;

  return 0;
}

int32_t display_init(struct display_cfg *cfg) {
  log_debug("In display_init()\n");

  state.tmr_id = -1;

  state.cfg = *cfg;
  return 0;
}

int32_t display_start(void) {
  int32_t result;

  log_debug("In display_start()\n");

  result = cmd_register(&cmd_info);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Private (static) functions
////////////////////////////////////////////////////////////////////////////////
static int32_t cmd_display_status(int32_t argc, const char **argv) {
  printf("state=%d blink_counter=%lu tmr_id=%lu\n", state.state,
         state.blink_counter, state.tmr_id);
  return 0;
}