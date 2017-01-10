#include "Rectangle.hpp"

Rectangle::Rectangle(): Point(), w(0.0), h(0.0){}

Rectangle::Rectangle(const Point &P, const Point &Q){
	x = std::min(P.x, Q.x);     y = std::min(P.y, Q.y);
	w = std::max(P.x, Q.x)-x ;  h = std::max(P.y, Q.y)-y ;
}

Rectangle::Rectangle(const double &_x, const double &_y, const double &_w, const double &_h):
    Point(_x, _y), w(_w), h(_h){}

bool Rectangle::intersect(const Rectangle &rect){
	return (std::max(x, rect.x) <= std::min(x+w, rect.x+rect.w)) && (std::max(y, rect.y) <= std::min(y+h, rect.y+rect.h));
}
