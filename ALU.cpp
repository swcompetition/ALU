#include "ALU.h"

ALU::ALU() {
}
ALU::~ALU() {

}
void ALU::ALU_operation(bool data1[], bool data2[]) {
    for (int i = DATA_BITS-1; i>=0; i--) {
        int temp = data1[i] + data2[i] + this->ALU_result[i];
        if (temp == 2) {
            this->ALU_result[i] = 0;
            if (i-1<0)
                this->overflow = 1;
            else
                this->ALU_result[i - 1] = 1;
        }
        else if (temp == 3) {
            this->ALU_result[i] = 1;
            if (i - 1 < 0)
                this->overflow = 1;
            else
                this->ALU_result[i - 1] = 1;
        }
        else {
            this->ALU_result[i] = temp;
        }
        if (this->ALU_result[i] != 0)
            this->zero = 0;
    }
}

bool* ALU::get_ALU_result() {
    return this->ALU_result;
}
bool ALU::get_zero() {
    return this->zero;
}
bool ALU::get_overflow() {
    return this->overflow;
}

void ALU::print_ALU_result()
{
    for (int i = 0; i < DATA_BITS; i++) {
        cout << this->ALU_result[i];
    }
    cout << endl;
    cout << "overflow: "<< this->overflow << endl;
    cout << "zero: "<<this->zero << endl;
}
