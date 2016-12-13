
/**
 * Représente un point dans l'escpace 2D.
 * Position X,Y
 * Orientation : angle
 */
class Point
{
public:
	float X;
	float Y;
	float ANGLE;

	Point();
	Point(const float &x, const float &y);
	Point(const float &x, const float &y, const float &angle);
	
};
