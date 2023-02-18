#ifndef TINYEFI_CONSOLE_H
#define TINYEFI_CONSOLE_H

#include <tinyefi/protos.h>

void efi_console_reset(void);
void efi_console_set_attribute(uint64_t attribute);
void efi_console_clear(void);

void efi_console_write(uint16_t *s);

EfiInputKey efi_console_read_key(void);

#endif
