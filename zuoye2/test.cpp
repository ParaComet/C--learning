#include <stdio.h>
#include <math.h>
int main()
{
	float x;
	double z;
	double k,sum = 1.0,sum1 = 1,part = 1;
	scanf("%f",&x);
	for(k = 1;fabs(part) > 0.00001;k++)
	{
		sum1 *= k;
		part = pow(x,k) / sum1;
		sum += part;
		
	}
	printf("%.4lf",sum);
} 