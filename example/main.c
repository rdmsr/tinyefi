#include <tinyefi/tinyefi.h>

void __chkstk() { return; }

void *memset(void *d, int c, size_t n)
{
    while (n--)
    {
        *(char *)d = c;
    }

    return d;
}

EfiStatus efi_main(EfiHandle image_handle, EfiSystemTable *st)
{
    efi_init(image_handle, st);

    efi_console_clear();
    efi_console_reset();

    efi_console_write(L"Hello, World!");

    for (;;)
    {
        __asm__ volatile("pause");
    }

    return EFI_SUCCESS;
}