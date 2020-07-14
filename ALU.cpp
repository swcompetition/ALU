#include "ALU.h"

ALU::ALU() {
}
ALU::~ALU() {

}
void ALU::ALU_operation(bool data1[], bool data2[], string ALU_control) {
    bool flag = true;
    if (ALU_control.compare("0010") == 0) { //add
        this->add(data1, data2, flag);
    }
    else if (ALU_control.compare("0110") == 0 || ALU_control.compare("0111") == 0) { //sub or slt
        this->invert(data2);
        this->add(data1, data2, flag); // in slt, if overflow is 0, jump rd //in beq, if zero is 0, jump address
    }
    else if (ALU_control.compare("0000") == 0) { //and
        this->and_operation(data1, data2);
    }
    else if (ALU_control.compare("0001") == 0) { //or
        this->or_operation(data1, data2);
    }
}

void ALU::add(bool data1[], bool data2[], bool flag) {
    bool temp_result[DATA_BITS] = { 0 };
    for (int i = DATA_BITS - 1; i >= 0; i--) { //add
        int temp = data1[i] + data2[i] + temp_result[i];
        if (temp == 2) {
            temp_result[i] = 0;
            if (i - 1 < 0)
                this->overflow = 1;
            else
                temp_result[i - 1] = 1;
        }
        else if (temp == 3) {
            temp_result[i] = 1;
            if (i - 1 < 0)
                this->overflow = 1;
            else
                temp_result[i - 1] = 1;
        }
        else {
            temp_result[i] = temp;
        }
    }
    if (flag) {
        for (int i = DATA_BITS - 1; i >= 0; i--) {
            this->ALU_result[i] = temp_result[i];

            if (this->ALU_result[i] != 0)
                this->zero = 0;
        }
    }
    else {
        for (int i = DATA_BITS - 1; i >= 0; i--) {
            data1[i] = temp_result[i];
        }
    }
}
void ALU::and_operation(bool data1[], bool data2[]) {
    for (int i = DATA_BITS - 1; i >= 0; i--) {
        this->ALU_result[i] = (data1[i] & data2[i]);
        if (this->ALU_result[i] != 0)
            this->zero = 0;
    }
}
void ALU::or_operation(bool data1[], bool data2[]) {
    for (int i = DATA_BITS - 1; i >= 0; i--) {
        this->ALU_result[i] = (data1[i] | data2[i]);
        if (this->ALU_result[i] != 0)
            this->zero = 0;
    }
}
void ALU::invert(bool data2[]) {
    for (int i = DATA_BITS - 1; i >= 0; i--) {
        data2[i] == 0 ? data2[i] = 1 : data2[i] = 0;
    }
    bool flag = false;
    this->add(data2, this->add_one, flag);
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

void ALU::set_ALU_result(bool temp[]) {
    for (int i = 0; i < DATA_BITS; i++) {
        ALU_result[i] = temp[i];
    }
}

void ALU::set_zero(bool temp) {
    this->zero = temp;
}

void ALU::set_overflow(bool temp) {
    this->overflow = temp;
}

void ALU::print_ALU_result()
{
    for (int i = 0; i < DATA_BITS; i++) {
        cout << this->ALU_result[i];
    }
    cout << endl;
    cout << "overflow: " << this->overflow << endl;
    cout << "zero: " << this->zero << endl;
}
