#include "stdio.h"
int main(){
    char *t=NULL;
    char c[1][3][10]={"Hello","World","New World"};
    
    for(int i=0;i<3;++i){
        t=&c[1][i];
        printf("%s\n",t);
    }
}