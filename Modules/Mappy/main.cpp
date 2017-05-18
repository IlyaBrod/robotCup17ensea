#include <stdio.h>
#include <stdlib.h>
#include "Mappy.hpp"

int main()
{
	printf("Mappy test\n");

	Mappy mpp;
	mpp.moveRobot(0, 0, 55);
	if (mpp.check(0, 87))
		printf("No intersection\n");
	else printf("Intersection\n");

	printf("Press any key to continue");
	getchar();
	return 0;
}