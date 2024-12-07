#ifndef CPU_EMULATOR_H
#define CPU_EMULATOR_H

#include <stdint.h>

typedef uint8_t byte;  // 8 bits or 1 byte
typedef uint16_t word; // 16 bits or 2 bytes

#define STACK_SIZE 256

typedef struct {
	byte X;
	byte Y;
} Registers;

typedef enum {
	Zero,  // set if the result of the last operation was 0
	Carry, // set if the last operation caused an overflow from bit 7 or an
	       // underflow from bit 0
	Interrupt, // set if the program has executed a 'set interrupt disable'
	           // instruction
	Decimal, // while set, cpu follows the rules of the Binary Coded Decimal
	Break,   // set when a break instruction is executed
	Overflow, // set if a math operation has overflowed the registers
	          // eg. 64 + 64  = -128
	Negative  // set if the last operation set the 7th bit to a 1
} Status;

typedef struct {
	byte accumulator;       // temp storage for math operations
	word program_counter;   // points to the next instruction to be executed
	word stack_pointer;     // pointer to the current part of memory being
	                        // accessed
	word stack[STACK_SIZE]; // memory for the cpu
	Registers registers;    // cpu registers
	Status status;          // current cpu status
} CPU;

void stack_init(CPU *cpu);
void init(CPU *cpu);

#endif

// reference: http://www.6502.org/users/obelisk/6502/instructions.html
#define MAX_FLAGS 7

// B: Break Flag
// C: Carry Flag
// D: Decimal Flag
// I: Interrupt
// N: Negative Flag
// V: Overflow Flag
// Z: Zero Flag
typedef enum {
	// Load/Store Operations
	LDA, // Sets: N, Z
	LDX, // Sets: N, Z
	LDY, // Sets: N, Z
	STA,
	STX,
	STY,

	// Register Transfers. All set N, Z
	TAX,
	TAY,
	TXA,
	TYA,
	TSX,
	TXS,

	// Stack Operations
	PHA, // Sets: N, Z
	PHP,
	PLA, // Sets: N, Z
	PLP, // Sets: ALL

	// Logical Operations. All set N, Z except BIT
	AND,
	EOR,
	ORA,
	BIT, // Sets: N, V, Z

	// Arithmetic. All set N, Z, C except ADC & SBC
	ADC, // Sets: N, V, Z, C
	SBC, // Sets: N, V, Z, C
	CMP,
	CPX,
	CPY,

	// Inc and Dec. All set N, Z
	INC,
	INX,
	INY,
	DEC,
	DEX,
	DEY,

	// Shifts. All set N, Z, C
	ASL,
	LSR,
	ROL,
	ROR,

	// Jumps and Calls. None set
	JMP,
	JSR,
	RTS,

	// Branches. None set
	BCC,
	BCS,
	BEQ,
	BMI,
	BNE,
	BPL,
	BVC,
	BVS,

	// Status Flag Changes
	CLC, // Clears C
	CLD, // Clears D
	CLI, // Clears I
	CLV, // Clears V
	SEC, // Sets C
	SED, // Sets D
	SEI, // Sets I

	// System Functions
	BRK, // Sets B
	NOP,
	RTI // Sets All
} Instruction_Ident;

typedef struct {
	Instruction_Ident ident;
	const char *string_name;
	Status set_flags[MAX_FLAGS];
} Instruction;

extern const Instruction INSTRUCTION_SET[]; // Declare as extern
