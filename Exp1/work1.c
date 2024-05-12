#include <stdio.h>
#include <stdlib.h>

// 定义学生信息的结构体
typedef struct {
    int id;
    char name[50];
    int age;
} Student;

// 函数声明2
void inputStudents(Student students[], int count);
void saveToFile(const Student students[], int count, const char *filename);
void loadFromFile(Student students[], int count, const char *filename);
void reverseOutputToFile(const Student students[], int count, const char *inputFilename, const char *outputFilename);

int main() {
    Student students[5]; // 假设最多处理5个学生的信息
    int i = 0;

    // 功能项1：输入学生信息
    printf("请输入5名学生的信息(学号、姓名、年龄):\n");
    inputStudents(students, 5);

    // 功能项2：将学生信息保存到input.dat文件
    printf("正在将学生信息保存到input.dat文件...\n");
    saveToFile(students, 5, "input.dat");

    // 功能项3：从input.dat读取信息并反向输出到output.dat文件
    printf("正在从input.dat读取信息并反向输出到output.dat文件...\n");
    reverseOutputToFile(students, 5, "input.dat", "output.dat");

    return 0;
}

// 输入学生信息并存入结构数组
void inputStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("学生 %d 的信息：\n", i + 1);
        printf("学号：");
        scanf("%d", &students[i].id);
        printf("姓名：");
        scanf("%s", students[i].name);
        printf("年龄：");
        scanf("%d", &students[i].age);
        
        // 附加要求:处理到第5位学生信息时中断
        if (i == 4) {
            printf("已处理到第5位学生信息,程序中断。\n");
            exit(0); // 强制退出程序
        }
    }
}

// 将学生信息保存到文件（二进制存储）
void saveToFile(const Student students[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("无法打开文件");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

// 从文件读取学生信息到结构数组
void loadFromFile(Student students[], int count, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("无法打开文件");
        return;
    }
    fread(students, sizeof(Student), count, file);
    fclose(file);
}

// 从input.dat读取信息并反向输出到output.dat文件
void reverseOutputToFile(const Student students[], int count, const char *inputFilename, const char *outputFilename) {
    // 读取文件到临时数组
    Student tempStudents[count];
    loadFromFile(tempStudents, count, inputFilename);

    // 反向输出到文件
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("无法打开文件");
        return;
    }

    // 反向写入文件
    for (int i = count - 1; i >= 0; i--) {
        fwrite(&tempStudents[i], sizeof(Student), 1, outputFile);
    }

    fclose(outputFile);
}