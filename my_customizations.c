// Board customization.
//
// Enable any of these function if you need more or different setup code.
// Placeholder version of same functions already weak-linked.
//
#include <stdbool.h>
#include "common/hw.h"
#include "common/board.h"
#include <port.h>
#if 0
void board_setup_early(void)
{
	// called immediately once we decide to go the DFU route
	volatile int a = 34;
}
#endif

void board_setup_late(void)
{
    struct port_config config;
    port_get_config_defaults(&config);
    
    port_pin_set_config(PIN_PA15, &config);

    
    config.direction = PORT_PIN_DIR_OUTPUT;
    port_pin_set_config(PIN_PB30, &config);
    port_pin_set_output_level(PIN_PB30, 0);
	// called after NVM and some other chip modules are init'ed
}

void board_reset_cleanup(void)
{
	// called after DFU has been loaded and we're going to run
	// the new firmware; might undo various setup that was in place.
    port_pin_set_output_level(PIN_PB30, 1);
}

bool button_pressed(void)
{
    struct port_config config;
    port_get_config_defaults(&config);
    
    port_pin_set_config(PIN_PA15, &config);
	// Return T to do DFU rather than run normal firmware.
    return port_pin_get_input_level(PIN_PA15) == false;
}

