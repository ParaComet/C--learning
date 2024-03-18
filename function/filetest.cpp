#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 创建一个fstream对象，用于读写文件
    fstream file;

    // 以读写模式打开一个文本文件，如果不存在则创建
    file.open("text.txt", ios::in | ios::out | ios::trunc);

    // 判断文件是否打开成功
    if (!file.is_open())
    {
        cout << "打开文件失败" << endl;
        return -1;
    }

    // 向文件中写入一些内容
    file << "Hello, world!" << endl;
    file << "This is a text file." << endl;

    // 将文件指针移动到文件开头
    file.seekg(0, ios::beg);

    // 从文件中读取内容，并显示到屏幕上
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    // 关闭文件
    file.close();
    return 0;
}
