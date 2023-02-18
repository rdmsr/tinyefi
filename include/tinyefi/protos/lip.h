#pragma once

#include <tinyefi/tables/system.h>

#define EFI_LIP_GUID                                       \
    {                                                      \
        0x5b1b31a1, 0x9562, 0x11d2,                        \
        {                                                  \
            0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b \
        }                                                  \
    }

#define EFI_LIP_REVISION 0x1000

typedef EfiStatus (*EFI_IMAGE_UNLOAD)(EfiHandle);

typedef struct efi_lip
{
    uint32_t revision;
    EfiHandle parent_handle;
    EfiSystemTable *system_table;
    EfiHandle device_handle;
    EfiDevicePath *file_path;
    void *_reserved;
    uint32_t load_options_size;
    void *load_options;
    void *image_base;
    uint64_t image_size;
    uint64_t image_code_type;
    EFI_IMAGE_UNLOAD unload;
} EfiLoadedImage;
