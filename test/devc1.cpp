#include"stdio.h"
int qread(int *x){
	char ch;
	int w=1,sum=0; 
	int tag=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		tag=1;
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	if(ch=='\n') tag=0;
 	(*x)=w*sum;
	return tag;
}
int main(){
	int a[100]={0};
	int num=0;
	while(qread(a+num++));
	for(int i=0;i<num;++i){
		printf("%d ",a[i]);
	}
	return 0;
} 
