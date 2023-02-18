CC = clang
LD = lld-link

CFLAGS = -ffreestanding -nostdlib -D__x86_64__ -Iinclude -Wall -Wextra -Werror -target x86_64-pc-win32-coff -ansi -fno-stack-protector -fshort-wchar -mno-red-zone
LDFLAGS = -subsystem:efi_application -nodefaultlib -dll

DIRECTORY_GUARD=@mkdir -p $(@D)

BUILD_DIRECTORY = build

EFI_FILE = $(BUILD_DIRECTORY)/main.efi

OVMF = $(BUILD_DIRECTORY)/tools/OVMF.fd

SRCS = $(wildcard example/*.c)

TINYEFI_SRCS = $(wildcard src/*.c)
OBJS = $(patsubst %.c, $(BUILD_DIRECTORY)/%.c.o, $(SRCS)) \
	   $(patsubst %.c, $(BUILD_DIRECTORY)/%.c.o, $(TINYEFI_SRCS))

$(EFI_FILE): $(OBJS)
	$(LD) $(LDFLAGS) -entry:efi_main $^ -out:$@

$(BUILD_DIRECTORY)/%.c.o: %.c
	$(DIRECTORY_GUARD)
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(EFI_FILE) $(OVMF) $(BUILD_DIRECTORY)/image/EFI/BOOT/BOOTX64.EFI
	qemu-system-x86_64 -bios $(OVMF) -cpu host -enable-kvm -drive file=fat:rw:$(BUILD_DIRECTORY)/image,media=disk,format=raw

$(BUILD_DIRECTORY)/image/EFI/BOOT/BOOTX64.EFI: $(EFI_FILE)
	$(DIRECTORY_GUARD)
	ln -sf ../../../../$(EFI_FILE) $@

$(OVMF):
	$(DIRECTORY_GUARD)
	wget https://retrage.github.io/edk2-nightly/bin/RELEASEX64_OVMF.fd
	mv RELEASEX64_OVMF.fd OVMF.fd
	mv OVMF.fd $(@D)

