#include "Parameters.h"
#include<time.h>
#include<cstdlib>

//--------------------------------------------------------------
int randomGenerator(int min, int max) {
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); // it seeds the first time
		first = false;
	}
	return min + rand() % (max + 1 - min);
}