#ifndef TINYEFI_TYPES_H
#define TINYEFI_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
} EfiGuid;

typedef uint64_t EfiStatus;
typedef void *EfiEvent;
typedef void *EfiHandle;

/* https://uefi.org/sites/default/files/resources/UEfi%20Spec%202.8B%20May%202020.pdf
  Section 8.3 */
typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t _pad1;
    uint32_t nanosecond;
    int16_t time_zone;
    uint8_t daylight;
    uint8_t _pad2;
} EfiTime;

typedef struct
{
    uint32_t resolution;
    uint32_t accuracy;
    bool sets_to_zero;
} EfiTimeCapabilities;

typedef struct
{
    uint32_t type;
    uint64_t physical_start;
    uint64_t virtual_start;
    uint64_t num_pages;
    uint64_t attribute;
} EfiMemoryDescriptor;

typedef struct
{
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t CRC32;
    uint32_t _reserved;
} EfiTableHeader;

#define EFI_SUCCESS 0
#define EFI_ERR (1ull << 63)
#define EFI_LOAD_ERROR (Efi_ERR | 0x1)
#define EFI_INVALID_PARAMETER (Efi_ERR | 0x2)
#define EFI_UNSUPPORTED (Efi_ERR | 0x3)
#define EFI_BAD_BUFFER_SIZE (Efi_ERR | 0x4)
#define EFI_BUFFER_TOO_SMALL (Efi_ERR | 0x5)
#define EFI_NOT_READY (Efi_ERR | 0x6)
#define EFI_DEVICE_ERROR (Efi_ERR | 0x7)
#define EFI_WRITE_PROTECTED (Efi_ERR | 0x8)
#define EFI_OUT_OF_RESOURCES (Efi_ERR | 0x9)
#define EFI_VOLUME_CORRUPTED (Efi_ERR | 0xa)
#define EFI_VOLUME_FULL (Efi_ERR | 0xb)
#define EFI_NO_MEDIA (Efi_ERR | 0xc)
#define EFI_MEDIA_CHANGED (Efi_ERR | 0xd)
#define EFI_NOT_FOUND (Efi_ERR | 0xe)
#define EFI_ACCESS_DENIED (Efi_ERR | 0xf)
#define EFI_NO_RESPONSE (Efi_ERR | 0x10)
#define EFI_NO_MAPPING (Efi_ERR | 0x11)
#define EFI_TIMEOUT (Efi_ERR | 0x12)
#define EFI_NOT_STARTED (Efi_ERR | 0x13)
#define EFI_ALREADY_STARTED (Efi_ERR | 0x14)
#define EFI_ABORTED (Efi_ERR | 0x15)
#define EFI_ICMP_ERROR (Efi_ERR | 0x16)
#define EFI_TFTP_ERROR (Efi_ERR | 0x17)
#define EFI_PROTOCOL_ERROR (Efi_ERR | 0x18)
#define EFI_INCOMPATIBLE_VERSION (Efi_ERR | 0x19)
#define EFI_SECURITY_VIOLATION (Efi_ERR | 0x1a)
#define EFI_CRC_ERROR (Efi_ERR | 0x1b)
#define EFI_END_OF_MEDIA (Efi_ERR | 0x1c)
#define EFI_END_OF_FILE (Efi_ERR | 0x1f)
#define EFI_INVALID_LANGUAGE (Efi_ERR | 0x20)
#define EFI_COMPROMISED_DATA (Efi_ERR | 0x21)
#define EFI_IP_ADDRESS_CONFLICT (Efi_ERR | 0x22)
#define EFI_HTTP_ERROR (Efi_ERR | 0x23)

#endif