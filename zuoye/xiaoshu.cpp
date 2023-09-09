#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	unsigned char x;
	int y;
	double z;
	scanf("%c%d%lf",&x,&y,&z);
	//cin>>x>>y>>z;
	//cout.setf(ios::fixed);
	//cout<<x<<"\n"<<y<<"\n"<<fixed<<setprecision(6)<<z;
	printf("%c\n%d\n%.6lf",x,y,z);
	return 0;
}
