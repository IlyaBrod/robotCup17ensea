/**/


class Balise
{

public:
	Balise(float baliseRadius);


	/**
	 *
	 * @param angle
	 * @return
	 */
	float triangulate(float angle);
		
	float duoangulate(float angle);
		
private:

	float baliseRadius;


	float calc_Dist_From_Balise(float angle);

		

		
		
		
		
		
};
