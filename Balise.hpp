#include <math>

class Balise
{

public:
	Balise(float baliseRadius);

	
	float triangulate(float angle1, float angle2, float angle3);
		
	float duoangulate(float angle);
		
private:

	float baliseRadius;
	
	float calc_Dist_From_Balise(float angle);

		

		
		
		
		
		
};
