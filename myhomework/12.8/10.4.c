
#include<stdio.h>

#define        MAXLEN        110

int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}
int isPrime(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i=3;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

/* 请在这里填写答案 */
int getResult(char word[]){
    int i=0;
    int max=-1,min=100;
    int num[27]={0};
    while(word[i]!='\0'){
        num[word[i]-'a']++;
        ++i;
    }
    for(int j=0;j<=26;j++){
        if(num[j]>max){
            max=num[j];
        }
        if(num[j]<min&&num[j]!=0){
            min=num[j];
        }
    }
    if(isPrime(max-min)){
        return max-min;
    }
    return -1;
}