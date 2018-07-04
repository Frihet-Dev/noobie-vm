#include "vm.h"
#include <stdio.h>
#include <string.h>

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7

void print_vm_state(virtual_machine *vm);

int main(void) {
    virtual_machine vm;
    initialize(&vm);

    unsigned char buf[] = {
        MOVI, R0, 0x17, 0x00, 0x00, 0x00,
        MOVI, R1, 0x29, 0x00, 0x00, 0x00,
        SUB, R0, R1,
        MOV, R7, R0,
        ADDI, R7, 0xaf, 0xf0, 0x00, 0x00,
        SUB, R7, R1,
        HALT
    };

    memcpy(vm.memory, buf, sizeof(buf));

    do {
        print_vm_state(&vm);       
    } while (execute_next_instruction(&vm));
    
    return 0;
}

void print_vm_state(virtual_machine *vm) {
    printf("0x%08x: ", vm->current_instruction);
    for (int i = 0; i < REGISTERS_COUNT; i++) {
        printf("r%d = 0x%08x ", i, vm->registers[i]);
    }
    printf("\n");  
}
