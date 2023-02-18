#pragma once

#include <tinyefi/protos/fp.h>
#include <tinyefi/types.h>

#define EFI_SFSP_REVISION 0x00010000

#define EFI_SFSP_GUID                                      \
    {                                                      \
        0x0964e5b22, 0x6459, 0x11d2,                       \
        {                                                  \
            0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b \
        }                                                  \
    }

struct efi_sfsp;

typedef EfiStatus (*EFI_SFSP_OPEN_VOLUME)(struct efi_sfsp *self, EfiFp **root);

typedef struct efi_sfsp
{
    uint64_t revision;
    EFI_SFSP_OPEN_VOLUME open_volume;
} EfiSfsp;
