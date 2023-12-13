#include<stdio.h>

#define        MAX        110
int        getPoint(char hand[]) ;

int main()
{
    char    poker[MAX];
    int        n ;
    
    scanf( "%d" , &n) ;
    while ( n -- )//循环n次 
    {
        scanf( "%s" , poker ); //读入字符串 
        printf( "%d\n" , getPoint(poker) ); //输出 
    }
        
    return 0;
}


/* 请在这里填写答案 */
int getPoint(char hand[]){
    int point=0;
    int i=0;
    while(hand[i]!='\0'){
        if(hand[i]>='3'&&hand[i]<='5'){
            ++point;
        }
        if(hand[i]>='6'&&hand[i]<='8'){
            point+=2;
        }
        if(hand[i]=='T'||hand[i]=='9'){
            point+=3;
        }
        if(hand[i]=='J'){
            point+=4;
        }
        if(hand[i]=='Q'){
            point+=5;
        }
        if(hand[i]=='K'){
            point+=6;
        }
        if(hand[i]=='A'){
            point+=8;
        }
        if(hand[i]=='2'){
            point+=10;
        }
        if(hand[i]=='B'){
            point+=15;
        }
        if(hand[i]=='R'){
            point+=20;
        }
        ++i;
    }
    return point;    
}