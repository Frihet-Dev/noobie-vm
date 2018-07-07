all:
	cd asm; nasm program.nasm
	cd asm;	objcopy --input binary --out elf64-x86-64 --binary-architecture i386:x86-64 "program" "program.o"
	gcc vm.c test.c "./asm/program.o" -o app.out
