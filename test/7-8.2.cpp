#include <stdio.h>
int main()
{
	char c;
	int i,j,t,index;
	int a[4]={0},b[4],flag[4]={1,1,1,1};	
	while((c=getchar())!='\n')
	{
		switch(c)
		{
			case 'A':a[0]++;break;
			case 'B':a[3]++;break;
			case 'C':a[1]++;break;
			case 'D':a[2]++;break;
		}
	}
	
	for(i=0;i<4;i++)
	{
		b[i]=a[i];
	}
	
	for(i=0;i<3;i++)
	{	index=i;
	  for(j=i+1;j<4;j++)
	  {
	  	  if(b[index]<b[j])
	  	    index=j;
	  }
	  
	  if(index!=i)
	  {
	  	t=b[index];
	  	b[index]=b[i];
	  	b[i]=t;
	  }
	}
	
	for(j=0;j<4;j++)
{
	for(i=0;i<4;i++)
	{
		if((b[j]==a[i])&&(j!=3))
		{
			if(i==0&&flag[0]!=0)
			{
				flag[0]=0;
				printf("Competition department %d people!\n",b[j]);goto NEXT;
				
			}else if(i==1&&flag[1]!=0)
			{
				flag[1]=0;
				printf("Office %d people!\n",b[j]);goto NEXT;
			}else if(i==2&&flag[2]!=0)
			{
				flag[2]=0;
				printf("Organization Department %d people!\n",b[j]);goto NEXT;
			}else if(i==3&&flag[3]!=0)
			{
				flag[3]=0;
				printf("Propaganda Department %d people!\n",b[j]);goto NEXT;
			}
		/*	switch(i)
			{
				case 0:
				case 1:
				case 2:
				case 3:
			}*/
		}
	}
	
	for(i=0;i<4;i++)
	{
		if((b[j]==a[i])&&(j==3))
		{
			if(i==0&&flag[0]!=0)
			{
				flag[0]=0;
				printf("Competition department %d people!",b[j]);goto NEXT;
				
			}else if(i==1&&flag[1]!=0)
			{
				flag[1]=0;
				printf("Office %d people!",b[j]);goto NEXT;
			}else if(i==2&&flag[2]!=0)
			{
				flag[2]=0;
				printf("Organization Department %d people!",b[j]);goto NEXT;
			}else if(i==3&&flag[3]!=0)
			{
				flag[3]=0;
				printf("Propaganda Department %d people!",b[j]);goto NEXT;
			}
		/*	switch(i)
			{
				case 0:
				case 1:
				case 2:
				case 3:
			}*/
		}
	}
NEXT:   ;
}

return 0;
}
