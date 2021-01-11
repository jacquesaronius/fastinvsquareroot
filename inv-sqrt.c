#include <math.h>
#include <time.h>
#include <stdio.h>
float Q_rsqrt(float number)
{
	/* Code for Q_rsqrt() courtesy of Wikipedia: https://en.wikipedia.org/wiki/Fast_inverse_square_root */ 
    
    long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

int main()
{
    
    int i = 0;
    for (i = 0; i < 10000; i++)
    {
        printf("Input %d\tInverse square root: %f\tFast Inverse square root: %f\n", i, 1 / sqrt((double)i), Q_rsqrt(i));
    }
    return 0;
}