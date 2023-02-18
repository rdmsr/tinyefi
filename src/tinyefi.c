#include <tinyefi/tinyefi.h>
#include <tinyefi/types.h>

static EfiHandle _handle;
static EfiSystemTable *_st;
static uint64_t _mmap_key = 0;

void efi_init(EfiHandle handle, EfiSystemTable *st)
{
    _handle = handle;
    _st = st;
}

EfiHandle efi_handle(void) { return _handle; }

EfiSystemTable *efi_st(void) { return _st; }

void efi_deinit(void)
{
    efi_st()->boot_services->exit_boot_services(efi_handle(), _mmap_key);
}

EfiMemoryDescriptor *efi_mmap_snapshot(size_t *size, size_t *desc_size)
{
    uint64_t mmap_size = 0;
    uint64_t descriptor_size = 0;
    uint32_t descriptor_version = 0;
    EfiMemoryDescriptor *mmap;

    efi_st()->boot_services->get_memory_map(
        &mmap_size, NULL, &_mmap_key, &descriptor_size, &descriptor_version);

    /* https://stackoverflow.com/questions/39407280/uefi-simple-example-of-using-exitbootservices-with-gnu-efi
     */
    mmap_size += 2 * descriptor_size;

    efi_st()->boot_services->allocate_pool(EFI_BOOT_SERVICES_DATA, mmap_size,
                                           (void **)&mmap);

    efi_st()->boot_services->get_memory_map(
        &mmap_size, mmap, &_mmap_key, &descriptor_size, &descriptor_version);

    *size = (mmap_size / descriptor_size);
    *desc_size = descriptor_size;

    return mmap;
}

uint16_t *efi_str_to_utf16(const char *s, uint16_t **out, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++)
    {
        *out[i * 2] = s[i];
    }
    return *out;
}