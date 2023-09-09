//trans
#include <iostream>
using namespace std;
int main(){
    
    char let;
    scanf("%c",&let);
    if (let>='A'&&let<='Z'){
       int minu=let-'A';
        printf("%c",'a'+minu);
    }
    /*if(let>='A'&&let<='Z'){
        printf("%c",let+32); 大小写字母ASCii差32
    }*/
    else if(let>='a'&&let<='z'){
        printf("%c",let);
    }
    else{
        printf("Non-English Characters");
    }
    return 0;
}