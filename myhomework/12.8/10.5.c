
#include <stdio.h>
#include <stdlib.h>

void shift(int *array , int num , int size ) ;

int main()
{
    int        i , n , p , array[100] ;
    
    scanf(" %d%d" , &n , &p ) ;//测试用例保证0<p<n<=100
    for( i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] ) ;//测试用例保证所有输入可以用整型存储

    shift( array , p , n ) ;//向左移p位
    for( i = 0 ; i < n - 1 ; i++ )
        printf( "%d " , array[i] ) ;
    printf( "%d\n" , array[i] ) ;
        
    return 0;    
}

/* 请在这里填写答案 */
void shift(int *array,int num,int size){
    if(num>=size){
        num=num%size;
    }
    int *temp=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        temp[i]=array[i];
    }
    for(int j=0;j<size-num;j++){
        array[j]=array[j+num];
    }
    for(int k=0;k<num;k++){
        array[size-num+k]=temp[k];
    }
    free(temp);
}