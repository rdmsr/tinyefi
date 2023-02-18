#ifndef TINYEFI_PROTOS_GOP_H
#define TINYEFI_PROTOS_GOP_H

#include <tinyefi/types.h>

#define EFI_GOP_GUID                                                           \
  {                                                                            \
    0x9042a9de, 0x23dc, 0x4a38, {                                              \
      0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a                           \
    }                                                                          \
  }

typedef struct {
  uint32_t red_mask;
  uint32_t green_mask;
  uint32_t blue_mask;
  uint32_t reserved_mask;
} EfiPixelBitmap;

typedef enum {
  PIXEL_RGB_RESERVED_8_BIT,
  PIXEL_BGR_8_BIT,
  PIXEL_BIT_MASK,
  PIXEL_BLT_ONLY,
  PIXEL_FORMAT_MAX
} EfiGraphicsPixelFormat;

typedef struct {
  uint32_t version;
  uint32_t horizontal_resolution;
  uint32_t vertical_resolution;
  EfiGraphicsPixelFormat pixel_format;
  EfiPixelBitmap pixel_information;
  uint32_t pixels_per_scan_line;
} EfiGopModeInfo;

typedef struct {
  uint32_t max_mode;
  uint32_t mode;
  EfiGopModeInfo *info;
  uint64_t size_of_info;
  uint64_t framebuffer_base;
  uint64_t framebuffer_size;
} EfiGopMode;

typedef struct {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
  uint8_t _reserved;
} EfiGopBltPixel;

typedef enum {
  BLT_VIDEO_FILL,
  BLT_VIDEO_TO_BLT_BUFFER,
  BLT_BUFFER_TO_VIDEO,
  BLT_VIDEO_TO_VIDEO,
  BLT_OPERATION_MAX
} EfiGopBltOperation;

struct efi_gop;

#define DEF_GOP_EFI_FUNC(name, ...)                                            \
  typedef EfiStatus (*EFI_GOP_##name)(struct efi_gop * self, __VA_ARGS__)

DEF_GOP_EFI_FUNC(QUERY_MODE, uint32_t, uint64_t *, EfiGopModeInfo **);
DEF_GOP_EFI_FUNC(SET_MODE, uint32_t);
DEF_GOP_EFI_FUNC(BLT, EfiGopBltPixel *, EfiGopBltOperation, uint64_t s_x,
                 uint64_t s_y, uint64_t d_x, uint64_t d_y, uint64_t width,
                 uint64_t height, uint64_t delta);

typedef struct efi_gop {
  EFI_GOP_QUERY_MODE query_mode;
  EFI_GOP_SET_MODE set_mode;
  EFI_GOP_BLT blt;
  EfiGopMode *mode;
} EfiGop;

#endif
