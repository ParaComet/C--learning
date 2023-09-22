#include<stdio.h>
#include<string.h>
int main()
{
    char temp[21];
    scanf("%s",temp);
    int len=strlen(temp),i,s=0;
    if(temp[0]!='1'||len!=11) printf("no\n");
    else
    {
        for(i=0;i<11;i++)
        {
            if(temp[i]>='0'&&temp[i]<='9') s++;
            else break;
        }
        if(s==11) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
