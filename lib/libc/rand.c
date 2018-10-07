#include <stdlib.h>
#include "rnd.h"



extern volatile unsigned int kernelRandomSeed ;

unsigned int rand(void)
{
	kernelRandomSeed = ((kernelRandomSeed * MULTIPLIER + ADDEND) & MASK);
	return kernelRandomSeed;
}



