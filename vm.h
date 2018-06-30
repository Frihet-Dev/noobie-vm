#ifndef VM_H
#define VM_H

#include <stdint.h>

// Instruction set
#define NOP 0x00
#define XOR 0x01
#define AND 0x02
#define OR 0x03
#define XORI 0x04
#define ANDI 0x05
#define ORI 0x06
#define ADD 0x07
#define SUB 0x08
#define MOV 0x10
#define HALT 0xFF

#define REGISTERS_COUNT 8
#define VM_MEMORY_SIZE 1024

typedef uint32_t word;

typedef struct {
    word registers[REGISTERS_COUNT];
    word current_instruction;
    uint8_t memory[VM_MEMORY_SIZE];
} virtual_machine;

void initialize(virtual_machine *vm);
uint8_t execute_next_instruction(virtual_machine *vm);

#endif