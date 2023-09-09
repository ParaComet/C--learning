#include <iostream>
using namespace std;
int main(){
	char lett;
	int num;
	int x;
	scanf("%c%d",&lett,&num);
	x=lett-64;
	lett=num+64;
	printf("%d\n%c",x,lett);
	return 0;
	
}
