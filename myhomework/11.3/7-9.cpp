#include "iostream"
#include "cstring"
using namespace std;
int main(){
    int stat[26];
    string str;
    memset(stat,0,sizeof(stat));
    cin>>str;
    //cout<<str<<endl;
    for(int i=str.length()-1;i>=0;--i){
        int flag=(int)str[i]-'a'+1;
        //cout<<flag<<endl; 
        if(flag>0){
            ++stat[str[i]-'a'];
        }
        else{
            ++stat[str[i]-'A'];
        }       
    }
    for(int i=0;i<26;++i){
        if(stat[i]){
            printf("%c出现%d次\n",i+'a',stat[i]);
        }
    }
    return 0;
}