#include <iostream>
#include <cmath>
#include <processthreadsapi.h>
#include <string>
#include "fstream"
using namespace std;
int sub[0xffff]={0};
fstream file;
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
    while(1){    
        int max=0;
        int re=0;
        string fil;
        fil.clear();
        int n,ty=0;
        double begin=0,end=0;
        cout << "Please input the number of the array" << endl;
        cin>>n>>re;
        if (n == -1) {
            break;
        }
        cout << "Please input the type of the algorithm and the file name" << endl;
        scanf("%d", &ty);
        cin >> fil;
        if(n>0){
            file.open(fil,ios::in);
            for(int i=0;i<n;++i){
                file>>sub[i];
            }
            for(int i=0;i<re;++i){
                if(ty==3){
                    begin=get_cpu_time();
                    max=maxSumSub(sub,sub+n-1);
                    //printf("%d\n",maxSumSub(sub,sub+n-1));
                    end=get_cpu_time();
                }
                else if(ty==1){
                    begin=get_cpu_time();
                    sumsubn3(n,max);
                    end=get_cpu_time();
                }
                else if(ty==2){
                    begin=get_cpu_time();
                    sumsubn2(n,max);
                    end=get_cpu_time();
                }
                else if(ty==4){
                    begin=get_cpu_time();
                    sumsubn1(n,max);
                    end=get_cpu_time();
                }
                else{
                    printf("Wrong type!\n");
                }
            }
           
            printf("%d\n",max);
            printf("Time measured: %.6f seconds.\n", (end-begin)/re);
            cout<<endl;
            file.close();
        }
    } 
    return 0;
    //system("pause");
}
//10 34 -20 30 -50 60 -20 30 41 -30 -10