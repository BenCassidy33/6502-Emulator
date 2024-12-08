; Test Program for CPU Emulator

START:
    LDA #10      ; Load the value 10 into the accumulator
    STA $0200    ; Store the value of the accumulator at memory address $0200
    LDA #20      ; Load the value 20 into the accumulator
    STA $0201    ; Store the value at memory address $0201

    LDA $0200    ; Load the value from memory address $0200 into the accumulator
    ADC $0201    ; Add the value at memory address $0201 to the accumulator
    TAX          ; Transfer the accumulator value to register X

    LDA #0       ; Load 0 into the accumulator
    TAY          ; Transfer the accumulator value to register Y

    JMP START    ; Jump back to START (loop forever)

; End of the program
