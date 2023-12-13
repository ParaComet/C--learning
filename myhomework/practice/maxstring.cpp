#include "iostream"
#include "cstring"
using namespace std;
struct number{
    string name;
};
number num[21];
bool judge(string s1,string s2){
    int n=strcmp(s1.c_str(),s2.c_str());
    if(n>0){
        return false;
    }
    return true;
}
void swap(string &s1,string &s2){
    string temp=s1;
    s1=s2;
    s2=temp;
}//交换两个字符串
int main(){
    int n=0;
    string str;
    //memset(num,0,sizeof(num));不要初始化，具体是因为memset是按字节赋值，而string是按字符赋值，所以会出现问题
    //memset是c语言的函数，c++中string声明的字符串是c++的类，所以不要混用
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i].name;
    }
    for(int i=n;i>0;--i)
        for(int j=0;j<i-1;++j){
            if(judge(num[j].name+num[j+1].name,num[j+1].name+num[j].name)){
                swap(num[j].name,num[j+1].name);
            }
        }
    //冒泡排序，但不是只按照降序；来排列，要考虑s1+s2和s2+s1的大小,如果s1+s2<s2+s1,则交换，使排列后的字符串最大
    /*for(int i=0;i<n;++i){
        cout<<num[i].name<<endl;
    }*/
    for(int i=0;i<n;++i){
        str+=num[i].name;
    }
    cout<<str;   
    return 0;
}
//string s="123",s2="1";
//n=strcmp(s.c_str(),s2.c_str());3 3 37 34