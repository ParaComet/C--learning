
#include<stdio.h>
int isPrime(int n)
{
    int flag=1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    if(n==1||n==0)
        flag=0;
    if(n==2)
        flag=1;
    return flag;
}
int getResult(char word[]);

int main()
{
    char word[100];
    scanf("%s",word);
    printf("%d",getResult(word));
    return 0;
}
#include<string.h>
int getResult(char word[]) 
{
    int time[123]={0};
    int tem=0;
    int l=strlen(word);
    for(int i=0;i<l;i++)
    {
        time[word[i]]++;
    }
    for(int j=97;j<123;j++)
    {
        for(int i=97;i<123;i++)
        {
            if(time[i]>time[i+1])
            {
                tem=time[i];
                time[i]=time[i+1];
                time[i+1]=tem;
            }
        }
    }
    //printf("%d\n",time[122]);
    int n;
    for(int i=97;i<123;i++)
    {
        if(time[i]!=0)
        {
            n=time[122]-time[i];
            break;
        }
    }
    int flag=isPrime(n);
    if(flag==1)
        return n;
    else
        return -1;
}