#include "Rectangle.hpp"

Rectangle::Rectangle(const Point &_A, const Point &_B, const Point &_C, const Point&_D): A(_A), B(_B), C(_C), D(_D){}

Rectangle::Rectangle(const Point &P, const Point &Q){
	A.X = min(P.X, Q.X);	A.Y = min(P.Y, Q.Y);
	B.X = max(P.X, Q.X);	B.Y = A.Y ;
	C.X = B.X ;				C.Y = max(P.Y, Q.Y);
	D.X = A.X ;             D.Y = C.Y ;
}

bool Rectangle::intersect(const Rectangle &rect){
	return (max(A.X, rect.A.X) <= min(C.X, rect.C.X)) && (max(A.Y, rect.A.Y) <= min(C.Y, rect.C.Y));
}
