#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _bits; 
}

Fixed::Fixed(const float n){
	std::cout << "Float constructor called" << std::endl;
	this->_value =  static_cast<int>(roundf(n * (1 << _bits))); 
}

Fixed::Fixed(const Fixed &other) : _value(other._value){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other){
		this->_value = other._value;
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const{
	float f = static_cast<float>(this->_value) / (1 << _bits);
	return f;
}

int Fixed::toInt(void) const{
	return this->_value >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &other) const{
	return this->_value < other._value;
}

bool Fixed::operator>(const Fixed &other) const{
	return this->_value > other._value;
}

bool Fixed::operator<=(const Fixed &other) const{
	return this->_value <= other._value;
}

bool Fixed::operator>=(const Fixed &other) const{
	return this->_value >= other._value;
}

Fixed Fixed::operator+(const Fixed &other) const{
	Fixed r;
	r.setRawBits(this->_value + other._value);
	return r;
}

Fixed Fixed::operator-(const Fixed &other) const{
	Fixed r;
	r.setRawBits(this->_value - other._value);
	return r;
}

bool Fixed::operator==(const Fixed &other) const{
	return this->_value == other._value;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed r;
    long long prod = static_cast<long long>(this->_value) * other._value;
    r.setRawBits(static_cast<int>(prod >> _bits)); // сдвиг назад на frac-биты
    return r;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed r;
    if (other._value == 0) { 
        r.setRawBits(0);
        return r;
    }
    long long num = (static_cast<long long>(this->_value) << _bits); // масштабируем числитель
    r.setRawBits(static_cast<int>(num / other._value));
    return r;
}

bool Fixed::operator!=(const Fixed &other) const{
	return this->_value != other._value;
}

Fixed &Fixed::operator++(){
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed &Fixed::operator--(){
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}
