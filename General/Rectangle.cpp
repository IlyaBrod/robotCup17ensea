#include "Rectangle.hpp"

Rectangle::Rectangle(const Point &_A, const Point &_B, const Point &_C, const Point&_D): A(_A), B(_B), C(_C), D(_D){}

Rectangle::Rectangle(const Point &P, const Point &Q){
	A.X = min(P.X, Q.X);	A.Y = min(P.Y, Q.Y);
	B.X = max(P.X, Q.X);	B.Y = A.Y;
	C.X = B.X ;				C.Y = max()
}

bool Rectangle::intersect(const Rectangle &rect){
	return (max(A.x, rect.A.x) <= min(C.x, rect.C.x)) && (max(A.y, rect.A.y) <= min(C.y, rect.C.y));
}