#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cmath>
#include <processthreadsapi.h>
#include <string>
#include "fstream"
using namespace std;
int sub[0xffff]={0};

fstream file;
fstream TestCmd;
fstream Result;

double get_cpu_time(){
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }else{
        //  Handle error
        return 0;
    }
}
int maxSumSub(int *l,int *r){
    if(l==r){
        return *l;
    }
    int maxlsub=0,maxrsub=0;
    int *mid=(r-l)/2+l;
    int lmax=0,rmax=0;
    int lsum=0,rsum=0;
    maxlsub=maxSumSub(l,mid);
    maxrsub=maxSumSub(mid+1,r);
    for(int *i=mid;i>=l;--i){
        lsum+=*i;
        if(lsum>lmax){
            lmax=lsum;
        }
    }
    for(int *i=mid+1;i<=r;++i){
        rsum+=*i;
        if(rsum>rmax){
            rmax=rsum;
        }
    }
    return max(max(maxlsub,maxrsub),lmax+rmax);
}
void sumsubn3(int n,int &max){
    int maxx=0;
    for(int i=0;i<n;++i)
        for(int j=i;j<n;++j){
            int sum=0;
            for(int k=i;k<=j;++k){
                sum+=sub[k];
            }
            if(sum>maxx){
                maxx=sum;
            }
        }
    max=maxx;
    //printf("%d\n",maxx);
}
void sumsubn2(int n,int &max){
    int maxx=0;
    for(int i=0;i<n;++i){
        int sum=0;
        for(int j=i;j<n;++j){
            sum+=sub[j];
            if(sum>maxx){
                maxx=sum;
            }
        }
    }
    max=maxx;
    //printf("%d\n",maxx);
}
void sumsubn1(int n,int &max){
    int maxx=0,sum=0;
    for(int i=0;i<n;++i){
        sum+=sub[i];
        if(sum>maxx){
            maxx=sum;
        }
        else if(sum<0){
            sum=0;
        }
    }
    max=maxx;
    //printf("%d\n",maxx);
}
int main(){
    TestCmd.open("TestCmd.txt",ios::in|ios::out);
    if(!TestCmd.is_open()){
        printf("Error:TestCmd.txt not found!\n");
        return 0;
    }
    Result.open("Result.txt",ios::out|ios::trunc);
    if(!Result.is_open()){
        printf("Error:Result.txt not found!\n");
        return 0;
    }
    while(1){    
        int max=0;
        int re=0;
        string fil;
        fil.clear();
        int n,ty=0;
        double begin=0,end=0;
        std::cout << "Please input the number of the array and the file name" << endl;
        TestCmd>>n>>fil;//n为数据规模fil为文件名
        std::cout<<n<<" "<<fil<<endl;
        if (n == -1) {
            break;
        }
        std::cout << "Please input the type of the algorithm " << endl;
        TestCmd>>ty>>re;//re为重复次数 ty为算法类型
        std::cout<<ty<<" "<<re<<endl;
        if(n>0){
            file.open(fil,ios::in);
            for(int i=0;i<n;++i){
                file>>sub[i];
            }
            begin=get_cpu_time();
            for(int i=0;i<re;++i){
                if(ty==3){
                    max=maxSumSub(sub,sub+n-1);
                    //printf("%d\n",maxSumSub(sub,sub+n-1));
                    
                }
                else if(ty==1){
                    sumsubn3(n,max);
                }
                else if(ty==2){
                    sumsubn2(n,max);
                }
                else if(ty==4){
                    sumsubn1(n,max);
                }
                else{
                    printf("Wrong type!\n");
                }
            }
            end=get_cpu_time();
            printf("%d\n",max);
            printf("Time measured: %.6f seconds.\n", (end-begin)/re);//输出运行时间
            Result<<"数据规模:"<<n<<" 重复次数:"<<re<<" 算法类型:"<<ty<<" 最大子序列和:"<<max<<"平均运行时间:"<< (end-begin)/re<<"s"<<endl;//输出到文件"Result.txt
            Result<<"------------"<<endl;
            std::cout<<endl;
            file.close();
        }
    } 
    return 0;
    //system("pause");
}
//10 34 -20 30 -50 60 -20 30 41 -30 -10