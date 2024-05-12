#include "iostream"
#include "cmath"
#include "fstream"
#include "cstring"
#include "locale"
#include "stdlib.h"
using namespace std;
const int Num=5;
const int n=0xff;
//const char *ty="in.dat";
bool flag=true;

fstream file;
fstream file2;

typedef struct Student{
    char id[n];
    string name;
    string gender;    
    int age;
}stu;
stu s[Num];

void init();//初始化文件
void chwrite(stu s[],string ty,int n);//写入文件
void chfind(stu s[],string ty,int n);//读取文件
void chde();//删除文件
void Command(char n);//输入指令 r读取 w写入 f复制 p打印 d删除 q退出

int main(){
    init();
    while(flag){
        char n;
        cout<<"Please input the operation you want to do:"<<endl;
        cin>>n;
        Command(n);
        }
    file.flush();//将缓冲区的内容写入文件
    file2.flush();
    file.close();
    file2.close();
    return 0;
}

//根据输入的指令进行操作
void Command(char n){
    if(n=='q'){
        flag=false;
        printf("Quit successfully!\n");
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
        //file.seekp(0,ios::beg);
        chwrite(s,"in.dat", Num);
        printf("Write successfully!\n");
    }

    else if(n=='f'){
        //file2.open("out.dat",ios::out);  
        
        chfind(s,"in.dat", Num);
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

void init(){
    file.open("in.dat",ios::in|ios::out|ios::binary|ios::trunc);
    file2.open("out.dat",ios::in|ios::out|ios::trunc);
    if(!file.is_open()||!file2.is_open()){
        cout<<"File open error!"<<endl;
        flag=false;
    }
    for(int i=0;i<Num;++i){
        s[i].age=0;
        strcpy(s[i].id,"");
        s[i].name.clear(); 
        s[i].gender.clear(); 
    }   
}

void chwrite(stu s[],string ty,int n){
    if (ty=="in.dat"){
        file.seekp(0,ios::beg);
        for(int i=0;i<n;++i){
            file<<s[i].id<<" "<<s[i].name<<" "<<s[i].gender<<" "<<s[i].age<<endl;
            cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].gender<<" "<<s[i].age<<endl;
        }
    }
    else if(ty=="out.dat"){
        file2.seekp(0,ios::beg);
        for(int i=n-1;i>=0;--i){
            file2<<s[i].id<<" "<<s[i].name<<" "<<s[i].gender<<" "<<s[i].age<<endl;
            cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].gender<<" "<<s[i].age<<endl;
        }
    }

}

void chfind(stu s[],string ty,int n){
    file.seekg(0,ios::beg);
    file2.seekp(0,ios::beg);
    for(int i=0;i<n;++i){
        file>>s[i].id>>s[i].name>>s[i].gender>>s[i].age;
    }
    chwrite(s, "out.dat", Num);
    /*streambuf* old_buffer = cin.rdbuf(file.rdbuf());
    string read;
    while(cin >> read) // 逐词读取方法一// 逐词读取方法二
    cin.rdbuf(old_buffer); // 修复buffer
    file>>s.gender>>s.age;*/
    
}

void chde(){
    ofstream clearerr("out.dat",ios::trunc);
    clearerr.close();
    ofstream clearerr2("in.dat",ios::trunc);
    clearerr2.close();
}

/*
2023 小王 m 20
2024 jack m 21
2025 lily f 22
2026 Oliv m 23
2027 Ruby f 24

*/
//c语言文件读写
void FileRead(){
    FILE *f;
    f=fopen("in.dat","r");
    if(f==NULL){
        printf("Error:in.dat not found!\n");
        return;
    }
    char num[n];
    fread(&num,sizeof(char),n-1,f);
}
void FileWrite(){
    FILE *f;
    f=fopen("in.dat","w");
    if(f==NULL){
        printf("Error:in.dat not found!\n");
        return;
    }
    char num[n];
    fwrite(&num,sizeof(char),n-1,f);
}