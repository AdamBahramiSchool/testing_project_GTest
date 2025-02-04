#include <iostream>
#include "../include/calculator.h"

/*
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
    public:
    int add(int x,int y);
    int subtract(int x, int y);
};

#endif


*/

Calculator::Calculator() {}

int Calculator::add(int x, int y) {
    return x + y;
}

int Calculator::subtract(int x, int y) {
    return x - y;
}
