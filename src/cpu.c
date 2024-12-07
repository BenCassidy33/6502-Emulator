#include "cpu.h"

// TODO: init cpu
void init(CPU *cpu) {};
void stack_init(CPU *cpu) { cpu->stack_pointer = 0; };

const Instruction INSTRUCTION_SET[] = {
    // Load/Store Operations
    {LDA, "LDA", {Negative, Zero}},
    {LDX, "LDX", {Negative, Zero}},
    {LDY, "LDY", {Negative, Zero}},
    {STA, "STA", {}},
    {STX, "STX", {}},
    {STY, "STY", {}},

    // Register Transfers. All set N, Z
    {TAX, "TAX", {Negative, Zero}},
    {TAY, "TAY", {Negative, Zero}},
    {TXA, "TXA", {Negative, Zero}},
    {TYA, "TYA", {Negative, Zero}},
    {TSX, "TSX", {Negative, Zero}},
    {TXS, "TXS", {Negative, Zero}},

    // Stack Operations
    {PHA, "PHA", {Negative, Zero}},
    {PHP, "PHP", {}},
    {PLA, "PLA", {Negative, Zero}},
    {PLP, "PLP", {Zero, Carry, Interrupt, Decimal, Break, Overflow, Negative}},

    // Logical Operations
    {AND, "AND", {Negative, Zero}},
    {EOR, "EOR", {Negative, Zero}},
    {ORA, "ORA", {Negative, Zero}},
    {BIT, "BIT", {Negative, Overflow, Zero}},

    // Arithmetic
    {ADC, "ADC", {Negative, Overflow, Zero, Carry}},
    {SBC, "SBC", {Negative, Overflow, Zero, Carry}},
    {CMP, "CMP", {Negative, Zero, Carry}},
    {CPX, "CPX", {Negative, Zero, Carry}},
    {CPY, "CPY", {Negative, Zero, Carry}},

    // Inc and Dec
    {INC, "INC", {Negative, Zero}},
    {INX, "INX", {Negative, Zero}},
    {INY, "INY", {Negative, Zero}},
    {DEC, "DEC", {Negative, Zero}},
    {DEX, "DEX", {Negative, Zero}},
    {DEY, "DEY", {Negative, Zero}},

    // Shifts
    {ASL, "ASL", {Negative, Zero, Carry}},
    {LSR, "LSR", {Negative, Zero, Carry}},
    {ROL, "ROL", {Negative, Zero, Carry}},
    {ROR, "ROR", {Negative, Zero, Carry}},

    // Jumps and Calls
    {JMP, "JMP", {}},
    {JSR, "JSR", {}},
    {RTS, "RTS", {}},

    // Branches
    {BCC, "BCC", {}},
    {BCS, "BCS", {}},
    {BEQ, "BEQ", {}},
    {BMI, "BMI", {}},
    {BNE, "BNE", {}},
    {BPL, "BPL", {}},
    {BVC, "BVC", {}},
    {BVS, "BVS", {}},

    // Status Flag Changes
    {CLC, "CLC", {Carry}},
    {CLD, "CLD", {Decimal}},
    {CLI, "CLI", {Interrupt}},
    {CLV, "CLV", {Overflow}},
    {SEC, "SEC", {Carry}},
    {SED, "SED", {Decimal}},
    {SEI, "SEI", {Interrupt}},

    // System Functions
    {BRK, "BRK", {Break}},
    {NOP, "NOP", {}},
    {RTI, "RTI", {Zero, Carry, Interrupt, Decimal, Break, Overflow, Negative}},
};
