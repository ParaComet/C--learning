#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char lett;
	int num;
	int x=255;
	char y=x;
	string s="321";
	string s1="A23"; 
	/*scanf("%c%d",&lett,&num);
	x=lett-64;
	lett=num+64;
	printf("%d\n%c",x,lett);*/
	num=strcmp(s.c_str(),s1.c_str());
	printf("%d",255);
	return 0;
	
}
