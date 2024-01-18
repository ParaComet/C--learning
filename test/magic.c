#include "stdio.h"
#include "math.h"
int pri(int x){
	if(x==1) return 0;
	if(x==2) return 1; 
	int j=0;
	for(j=2;j<=(int)sqrt(x);++j){
		if(x%j==0) return 0; 
	}
	return 1;
}
int main(){
	int n=0;
	int a[13]={0};
	int num=0;
	int i=0;
	scanf("%d",&n);
	printf("%d=",n);
	if(pri(n)||n==1) printf("%d",n); 
	else{
		while(n!=1){
			for(i=2;i<=n;++i){
				if(n%i==0&&pri(i)){
					a[num++]=i;
					n/=i;
					break;
				}
			}
		}
		for(i=0;i<num-1;++i){
			printf("%d*",a[i]);
		}
		printf("%d",a[num-1]);
	}
	return 0;
} 
