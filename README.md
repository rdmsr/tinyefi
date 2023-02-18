# tinyefi

tinyefi is a tiny, public domain, EFI library originally written as part of **Brutal**.

## Naming scheme/Comparison

Contrary to the standard EFI naming scheme, tinyefi uses `snake_case` for functions and `PascalCase` for types.

Standard GNU EFI code:

```c
#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
   InitializeLib(ImageHandle, SystemTable);
   Print(L"Hello, world!\n");

   return EFI_SUCCESS;
}
```

tinyefi code:

```c
#include <tinyefi/tinyefi.h>

EfiStatus efi_main(EfiHandle image_handle, EfiSystemTable *st)
{
    efi_init(image_handle, st);

    efi_console_write(L"Hello, World!");

    return EFI_SUCCESS;
}
```

## Example

To compile and run the example, just execute `make run`
