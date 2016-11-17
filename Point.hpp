
/**
 * Représente un point dans l'escpace 2D.
 * Position X,Y
 * Orientation : angle
 */
class Point
{
public:
	Point();
	Point(float x,float y,float angle);
	
	float getX();
	float getY();
	float getAngle();
	
	void setX(float x);
	void setY(float y);
	void setXY(float x,float y);
	void setAngle(float angle);
private :
	float x;
	float y;
	float angle;
};
