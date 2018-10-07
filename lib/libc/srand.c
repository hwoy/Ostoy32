#include <stdlib.h>
#include "rnd.h"

volatile unsigned int kernelRandomSeed = 0;



void srand(unsigned int seed)
{
	kernelRandomSeed = ((seed ^ MULTIPLIER) & MASK);
}




