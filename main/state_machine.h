#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "mode_manager.h"

software_mode_t software_mode_get(void);

void mode_execute(software_mode_t mode);

#endif