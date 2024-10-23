#include <string>
#include <cmath>
#include "calculator.h"
#include <stdexcept>

calculator::calculator(double arg, double base, std::string operation) : arg(arg), base(base), oper(operation){}

double calculator::Logar(double arg, double base, std::string oper) {
    if (arg <= 0) {
        throw std::invalid_argument("Аргумент должен быть больше нуля! ");
    }
    else if (base <= 0 || base == 1) {
        throw std::invalid_argument("Основание должно быть больше нуля и не быть равным единице! ");
    }
    else {
        if (oper == "natural") {
            return std::log(arg) / std::log(exp(1));
        }
        else {
            return std::log(arg) / std::log(base);
        }
    }
}