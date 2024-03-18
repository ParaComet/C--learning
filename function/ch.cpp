#include <fstream>
#include <string>
#include <iostream>
using namespace std;
 
int main()
{
    fstream ifs("hello.txt",ios::in|ios::out|ios::app); // 改成你要打开的文件
    streambuf* old_buffer = cin.rdbuf(ifs.rdbuf());
 
    string read;
    while(cin >> read) // 逐词读取方法一
        ifs<<read; // 逐词读取方法二
    cin.rdbuf(old_buffer); // 修复buffer
    ifs.close();
    return 0;
}