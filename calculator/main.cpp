#include "calculator.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    po::options_description desc("Логарифмический калькулятор");
    desc.add_options()
        ("help,h" , "Выдать справку")
        ("type,t" , po::value<std::string>()->required(), "Тип логарифма. natural-n or usual-u")
        ("arg,a" , po::value<double>()->required(), "Аргумент логарифма. Обязательно больше нуля!")
        ("base,b", po::value<double>(), "Основание логарифма. Обязательно больше нуля и не единица! (по дефолту равно экспоненте)");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    }
    catch(po::error& e) {
        std::cout<< e.what()<<std::endl;
        std::cout<<desc<<std::endl;
        return 1;
    }
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }
    
    std::string type = vm["type"].as<std::string>();
    double arg = vm["arg"].as<double>();
    double base = exp(1);
    
    if (vm.count("base") && type == "usual") { 
        base = vm["base"].as<double>();
    }
    
    if (vm.count("base") && type == "natural") {
        std::cerr << "Основание логарифма уже определено первым параметром! \n";
        return 1;
    }

    try {
        calculator calc(arg, base, type); 
        double result = calc.Logar(arg, base, type);
        std::cout << "Логарифм " << arg << " по основанию " << base << " = " << result << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}