CC = aarch64-linux-gnu
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
all: kernel8.img

output/a.o: src/a.S
	${CC}-gcc ${CFLAGS} -c src/a.S -o output/a.o

output/main.o: src/main.c
	${CC}-gcc ${CFLAGS} -c src/main.c -o output/main.o

output/lib.o: src/lib.c
	${CC}-gcc ${CFLAGS} -c src/lib.c -o output/lib.o

output/UART.o: src/UART.c
	${CC}-gcc ${CFLAGS} -c src/UART.c -o output/UART.o

kernel8.img:  output/main.o output/UART.o output/a.o output/lib.o
	${CC}-ld -Iinclude -T src/linker.ld -o kernel8.elf output/a.o output/main.o output/UART.o output/lib.o
	${CC}-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm -f kernel8.elf
	rm -f output/*

run:
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -display none -s -S -serial null -serial stdio