all: challenge dev

challenge:
	gcc src/rev3.c --include-directory=/usr/include/libdrm -ldrm -s -o bin/rev3.elf

dev:
	gcc src/rev3.c --include-directory=/usr/include/libdrm -ldrm -DDEV -o bin/rev3-dev.elf
