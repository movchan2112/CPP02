#include "Point.hpp"

float cross(const Point& A, const Point& B, const Point& P) {
    return (B.getFloatXvalue() - A.getFloatXvalue()) * (P.getFloatYvalue() - A.getFloatYvalue()) -
           (B.getFloatYvalue() - A.getFloatYvalue()) * (P.getFloatXvalue() - A.getFloatXvalue());
}
bool pointInTriangle(const Point& A, const Point& B, const Point& C, const Point& P) {
    const float eps = 1e-6f;

    float s1 = cross(A, B, P);
    float s2 = cross(B, C, P);
    float s3 = cross(C, A, P);

    bool has_neg = (s1 < -eps) || (s2 < -eps) || (s3 < -eps);
    bool has_pos = (s1 > eps)  || (s2 > eps)  || (s3 > eps);

    return !(has_neg && has_pos); 
    // true → P внутри или на границе
    // false → P снаружи
}

int main() {
    Point A(-1.0f, -1.0f);
    Point B(4.0f, 0.0f);
    Point C(0.0f, 3.0f);

    Point P(1.0f, 1.0f);

    if (pointInTriangle(A,B,C,P))
        std::cout << "Inside or on border\n";
    else
        std::cout << "Outside\n";
}
