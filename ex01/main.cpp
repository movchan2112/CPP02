#include "Fixed.hpp"

int main( void ) {
    Fixed a(3);
    Fixed b(a);
    Fixed c(3);
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}