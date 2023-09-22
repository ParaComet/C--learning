#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int i,j,a;
	for (i=1;i<=n/2+1;i++)
	{
		for (j=1;j<=(n+1)/2-i;j++)
		{
			printf("  ");
		}
			for (a=1;a<=2*i-1;a++)
			{
				printf("* ");
			}		
				printf("\n");
	}
	
	for (i=1;i<=n/2;i++)
	{
		for (j=1;j<=i;j++)
		{
			printf("  ");
		}
			for (a=1;a<=n-2*i;a++)
			{
				printf("* ");
			}		
				printf("\n");
	}
	

	
	return 0;
}