#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {};

Point::Point(const float x, const float y) : _x(x),_y(y){};

Point::Point(const Point &other) : _x(other._x),_y(other._y) {};

Point &Point::operator=(const Point &other){
	if(this != &other){
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}

Point::~Point(){};

float Point::getFloatXvalue() const{
	return this->_x.toFloat();
}

float Point::getFloatYvalue() const{
	return this->_y.toFloat();
}