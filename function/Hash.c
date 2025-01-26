#include "stdio.h"
#include "stdlib.h"
int main(){
    int n = 0;
    int a[11] = {0},b[11] = {0};
    for (int i = 0; i < 11; i++)
    {
        a[i] = -1;
    } 
    //printf("%d", a[0]);
    scanf("%d", &n);
    int t = 0;
    for(int i = 0; i < n; i ++){
        scanf("%d", &t);
        if(a[(3*t)%11] == -1)
        {
            a[3*t%11] = t;
            b[3*t%11] = 1;
        }
        else
        {
            int j = 1;
            while(a[(3*t+j)%11] != -1)
            {
                j++;
            }
            a[(3*t+j)%11] = t;
            b[(3*t+j)%11] = j+1;
        }
    }
    for (int i = 0; i < 11; i++)
    {
        if(a[i] == -1)
        {
            printf("- ");
        }
        else
        {
            printf("%2d ", a[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        if(b[i] == 0)
        {
            printf("- ");
        }
        else
        {
            printf("%2d ", b[i]);
        }
    }
    
    return 0;
}