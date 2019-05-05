#include "common.h"

extern const double PI = 3.1415926535;

double Account::interestRate = 0.034;

void Account::rate(double newRate) {
    interestRate = newRate;
}

double Account::initRate() {
    interestRate = 0.0;
    return interestRate;
}