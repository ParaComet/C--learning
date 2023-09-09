#include <iostream>
using namespace std;
int main(){
    char let;
    scanf("%c",&let);
    if(let+3>'z'){
        printf("%c",let-23);
    }
    else{
        printf("%c",let+3);
    }
    return 0;
}