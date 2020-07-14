#include "ALU.h"

int main(void) {
    bool temp1[DATA_BITS] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 };
    bool temp2[DATA_BITS] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
    string alu_control = "0110";

    ALU ALUtemp;
    ALUtemp.ALU_operation(temp1, temp2, alu_control);
    ALUtemp.print_ALU_result();
    return 0;
}