#ifndef __COMMON_H__
#define __COMMON_H__

extern const double PI;

#include <string>

class Account{
public:
    void calculate(){ amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    std::string owner;
    double amount = 0;
    static double interestRate;
    static double initRate();
};

#endif
