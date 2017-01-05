#!/bin/sh

openocd \
    -f board/atmel_samd21_xplained_pro.cfg \
    -c "init" \
    -c "reset" \
    -c "halt" \
    -c "flash write_image erase dafu.elf" \
    -c "reset run" \
    -c "shutdown"
