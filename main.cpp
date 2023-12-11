#include <stdlib.h>
#include <stdio.h>

struct CPU
{
    using Byte = unsigned char;
    using Word = unsigned short;

    Word PC; // Program counter 
    Word SP; // Stack pointer

    Byte Accumulator, x, y; // Registers
    
    // Bit field, each flag is 1 bit. This makes up the Processor Status Register
    Byte C : 1; // Carry Flag   
    Byte Z : 1; // Zero Flag 
    Byte I : 1; // Interrupt Flag 
    Byte D : 1; // Decimal Flag 
    Byte B : 1; // Break Flag 
    Byte V : 1; // Overflow Flag 
    Byte N : 1; // Negative Flag 

    //  non-maskable interrupt
    void NMI(){
        SP = PC & 0xFF;  // push low byte PC onto SP
        SP = (PC>>8) & 0xFF; // push high byte PC onto SP
        // processor status onto SP
        // disable interupts
        PC = 0xFFFA;
    }
    // Cold reset
    void Reset(){
        PC = 0xFFFC;
        D = 0;
    }
};


int main()
{
    CPU cpu;
    cpu.Reset();
    printf("Hello World!");
    return 0;
}