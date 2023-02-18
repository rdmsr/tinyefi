#include <tinyefi/tinyefi.h>

void efi_console_reset(void)
{
    efi_st()->console_in->reset(efi_st()->console_in, false);
}

void efi_console_set_attribute(uint64_t attribute)
{
    efi_st()->console_out->set_attribute(efi_st()->console_out, attribute);
}

void efi_console_clear(void)
{
    efi_st()->console_out->clear_screen(efi_st()->console_out);
}

void efi_console_write(uint16_t *s)
{
    efi_st()->console_out->output_string(efi_st()->console_out, s);
}

EfiInputKey efi_console_read_key(void)
{
    EfiInputKey key = {};
    uint64_t key_event = 0;

    efi_st()->boot_services->wait_for_event(
        1, &efi_st()->console_in->wait_for_key, &key_event);
    efi_st()->console_in->read_key(efi_st()->console_in, &key);

    return key;
}
