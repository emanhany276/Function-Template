#include <iostream>
#include <string>
#include"array.hpp"
#include "math.hpp"
#include "lib.hpp"

using namespace std;
using namespace lib;



int main ()
{   
    std::cout << lib::max(100, 200, 521.2 ,8957)  << "\n";
    std::cout << lib::min(100, 200, 521.2 ,8957)   << "\n";
    std::cout << lib::sub(7800, 200 , 25 ) << "\n";

    lib::Custom c1("Object1");
    lib::Custom c2("Object2");
    lib::Custom c3 = c1 - c2;

    std::cout << "Custom Sub: " << c3 << std::endl;
}