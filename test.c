#include "vm.h"
#include <stdio.h>

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7

int main(void) {
    virtual_machine vm;
    initialize(&vm);

    vm.registers[R0] = 0x17;
    vm.registers[R1] = 0x29;

    unsigned char buf[] = { SUB, R0, R1, MOV, R7, R0, ADD, R7, 0xaf, 0xf0, 0x00, 0x00, HALT };
    
    for (int i = 0; i < sizeof(buf) / sizeof(unsigned char); i++)
        vm.memory[i] = buf[i];

    do {
        for (int i = 0; i < REGISTERS_COUNT; i++) {
            printf("r%d = 0x%08x ", i, vm.registers[i]);
        }
        printf("ci = 0x%08x\n", vm.current_instruction);        
    } while (execute_next_instruction(&vm));
    
    return 0;
}