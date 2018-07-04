#include "vm.h"
#include <string.h>

#define MAKE_READ(T) \
    T read_##T(virtual_machine *vm) { \
        T x = *(T *)(&vm->memory[vm->current_instruction]); \
        vm->current_instruction += sizeof(x); \
        return x; \
    }

MAKE_READ(uint8_t);
MAKE_READ(word);

void initialize(virtual_machine *vm) {
    memset(&vm->registers, 0, REGISTERS_COUNT * sizeof(word));
    vm->current_instruction = 0;
    memset(&vm->memory, 0, VM_MEMORY_SIZE);
}

uint8_t execute_next_instruction(virtual_machine *vm) {
    if (vm->current_instruction >= VM_MEMORY_SIZE)
        return 0;

    switch (vm->memory[vm->current_instruction++]) {
        case XOR: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] ^= vm->registers[src];
            break;
        }
        case AND: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] &= vm->registers[src];
            break;
        }
        case OR: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] |= vm->registers[src];
            break;
        }
        case XORI: {
            uint8_t dst = read_uint8_t(vm); 
            word arg = read_word(vm);

            vm->registers[dst] ^= arg;
            break;
        }
        case ANDI: {
            uint8_t dst = read_uint8_t(vm);
            word arg = read_word(vm);
            
            vm->registers[dst] &= arg;
            break;
        }
        case ORI: {
            uint8_t dst = read_uint8_t(vm);
            word arg = read_word(vm);
            
            vm->registers[dst] |= arg;
            break;
        }
        case ADD: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] += vm->registers[src];
            break;
        }        
        case SUB: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] -= vm->registers[src];
            break;
        }
        case ADDI: {
            uint8_t dst = read_uint8_t(vm);
            word arg = read_word(vm);

            vm->registers[dst] += arg;
            break;
        }
        case SUBI: {
            uint8_t dst = read_uint8_t(vm);
            word arg = read_word(vm);

            vm->registers[dst] -= arg;
            break;
        }
        case MOV: {
            uint8_t dst = read_uint8_t(vm);
            uint8_t src = read_uint8_t(vm);
            
            vm->registers[dst] = vm->registers[src];
            break;
        }
        case MOVI: {
            uint8_t dst = read_uint8_t(vm);
            word arg = read_word(vm);

            vm->registers[dst] = arg;
            break;
        }
        case HALT:
            return 0;
    }
    return 1;
}
