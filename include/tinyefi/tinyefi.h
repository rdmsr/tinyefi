#ifndef TINYEFI_TINYEFI_H
#define TINYEFI_TINYEFI_H

#include <tinyefi/console.h>
#include <tinyefi/protos.h>
#include <tinyefi/tables.h>

void efi_init(EfiHandle handle, EfiSystemTable *st);

void efi_deinit(void);

uint16_t *efi_str_to_utf16(const char *s, uint16_t **out, size_t len);

EfiHandle efi_handle(void);

EfiSystemTable *efi_st(void);

/* you should free EfiMemoryDescriptor if you don't need it */
EfiMemoryDescriptor *efi_mmap_snapshot(size_t *size, size_t *desc_size);

#endif