#pragma once
#include <string>
#include <cmath>

class calculator {
public:
    calculator(double arg, double base, std::string operation);
    double Logar(double arg, double base, std::string operation);
    
private:
    double arg;
    double base;
    std::string oper;
};