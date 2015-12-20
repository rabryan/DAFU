#pragma once
#include "common/util.h"
#include "common/hw.h"

// Memory Layout
// - first 4k reserved for DAFU Bootloader
// - remainder of flash for main firmware
//
#define FLASH_BOOT_START 	0
#define FLASH_BOOT_SIZE 	4096

#ifndef FLASH_TOTAL_SIZE
#define FLASH_TOTAL_SIZE 	(256*1024)
#endif

#define FLASH_FW_START 		FLASH_BOOT_SIZE
#define FLASH_FW_SIZE 		(FLASH_TOTAL_SIZE - FLASH_BOOT_SIZE)

#define FLASH_BOOT_ADDR 	FLASH_BOOT_START
#define FLASH_FW_ADDR 		FLASH_FW_START

#define BOOT_MAGIC 			0

// USB pins
const static Pin PIN_USB_DM = {.group = 0, .pin = 24, .mux = MUX_PA24G_USB_DM };
const static Pin PIN_USB_DP = {.group = 0, .pin = 25, .mux = MUX_PA25G_USB_DP };

