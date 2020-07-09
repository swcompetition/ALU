#pragma once
#include <iostream>
using namespace std;

#define DATA_BITS 32
#define ALU_OPERATION_BITS 4

class ALU
{
private:
    bool ALU_result[DATA_BITS] = { 0 };
    bool zero=1;
    bool overflow = 0;
public:
    ALU();
    ~ALU();
    void ALU_operation(bool data1[], bool data2[]);
    bool* get_ALU_result();
    bool get_zero();
    bool get_overflow();

    void set_ALU_result(bool temp[]);
    void set_zero(bool temp);
    void set_overflow(bool temp);

    void print_ALU_result();
};

