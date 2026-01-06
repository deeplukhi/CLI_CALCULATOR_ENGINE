#include "../include/calculator.h"
#include <stdexcept>


int calculator::add(int a, int b) {
    return a + b;
}

int calculator::sub(int a, int b) {
    return a - b;
}

int calculator::multiply(int a, int b) {
    return a * b;
}

int calculator::divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division by zero is not allowed");
    return a / b;
}

int calculator::remainder(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Modulo by zero is not allowed");
    return a % b;
}