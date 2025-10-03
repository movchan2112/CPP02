#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		float getFloatXvalue(void) const;
		float getFloatYvalue(void) const;
};


#endif