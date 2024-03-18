#include "iostream"
#include "cmath"
#include "fstream"
#include "cstring"
#include "locale"
using namespace std;
const int Num=5;
const int n=0xff;

fstream file;
fstream file2;

typedef struct Student{
    char id[n];
    string name;
    string gender;    
    int age;
}stu;
stu s[Num];

void init(){
    for(int i=0;i<Num;++i){
        s[i].age=0;
        strcpy(s[i].id,"");
        s[i].name.clear(); // Fix: Use the clear() function to assign an empty string
        s[i].gender.clear(); // Fix: Use the clear() function to assign an empty string
    }   
}

void chwrite(stu &s){
    //file.open(ty,ios::out|ios::binary|ios::app);
    file<<s.id<<" "<<s.name<<" "<<s.gender<<" "<<s.age<<endl;
    cout<<s.id<<" "<<s.name<<" "<<s.gender<<" "<<s.age<<endl;
}

void chwrite2(stu &s){
    file2<<s.id<<" "<<s.name<<" "<<s.gender<<" "<<s.age<<endl;
    //streambuf* old_buffer = cin.rdbuf(file.rdbuf());
    //cin.rdbuf(old_buffer);
    
}

void chfind(stu &s){
    //file.open(ty,ios::in|ios::binary);
    file>>s.id>>s.name>>s.gender>>s.age;
    /*streambuf* old_buffer = cin.rdbuf(file.rdbuf());
    string read;
    while(cin >> read) // 逐词读取方法一// 逐词读取方法二
    cin.rdbuf(old_buffer); // 修复buffer
    file>>s.gender>>s.age;*/
    cout<<s.id<<" "<<s.name<<" "<<s.gender<<" "<<s.age<<endl;
}

void chde(){
    ofstream clearerr("out.dat",ios::trunc);
    clearerr.close();
    ofstream clearerr2("in.dat",ios::trunc);
    clearerr2.close();
}
int main(){
    file.open("in.dat",ios::in|ios::out|ios::binary|ios::trunc);
    file2.open("out.dat",ios::in|ios::out|ios::trunc);
    if(!file.is_open()||!file2.is_open()){
        cout<<"File open error!"<<endl;
        return 0;
    }
    while(1){
        char n;
        cout<<"Please input the operation you want to do:"<<endl;
        cin>>n;
        if(n=='q'){
            break;
        }
        else if(n=='r'){
            printf("Please input the student's id, name and age:\n");
            for(int i=0;i<Num;++i){
                //printf("The %dth student:\n",i+1);
                cin>>s[i].id>>s[i].name>>s[i].gender>>s[i].age;
            }
            printf("Read successfully!\n");
        }
        else if(n=='w'){
            //file.open("in.dat",ios::out);
            file.seekp(0,ios::beg);
            for(int i=0;i<Num;++i){
                chwrite(s[i]);
            }
            printf("Write successfully!\n");
        }
        else if(n=='f'){
            //file2.open("out.dat",ios::out);  
            file.seekg(0,ios::beg);
            file2.seekp(0,ios::beg);
            for(int i=0;i<Num;++i){
                chfind(s[i]);
                chwrite2(s[i]);
            }
            printf("copy successfully!\n");
        }
        else if(n=='p'){
            for(int i=0;i<Num;++i){
                cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].gender<<" "<<s[i].age<<endl;
            }

        }
        else if(n=='d'){
            chde();
            printf("Delete successfully!\n");
        }
        else{
            printf("Invalid input!\n");
        }
    }
    file.flush();//将缓冲区的内容写入文件
    file2.flush();
    file.close();
    file2.close();
    return 0;
}
/*
2023 小王 m 20
2024 jack m 21
2025 lily f 22
2026 Oliv m 23
2027 Ruby f 24

*/