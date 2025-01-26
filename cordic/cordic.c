#include <stdio.h>
#include <stdint.h>

#define ITERATIONS 16  // 迭代次数（影响精度）
#define K 0.607252935  // 预计算缩放因子
#define PI 3.14159265358979323846

// 角度查找表（弧度）
const double cordic_atan_table[ITERATIONS] = {
    0.785398163, 0.463647609, 0.244978663, 0.124354995,
    0.062418810, 0.031239833, 0.015623729, 0.007812341,
    0.003906230, 0.001953123, 0.000976562, 0.000488281,
    0.000244141, 0.000122070, 0.000061035, 0.000030518
};

// CORDIC 计算 atan2(y, x) 角度（单位：弧度）
double cordic_atan2(double y, double x) {
    double angle = 0.0;
    double x_new, y_new;

    // CORDIC 迭代
    for (int i = 0; i < ITERATIONS; i++) {
        if (y > 0) {
            x_new = x + (y / (1 << i));
            y_new = y - (x / (1 << i));
            angle += cordic_atan_table[i];
        } else {
            x_new = x - (y / (1 << i));
            y_new = y + (x / (1 << i));
            angle -= cordic_atan_table[i];
        }
        x = x_new;
        y = y_new;
    }
    return angle;  // 返回弧度
}

// 测试代码
int main() {
    double x = 1.0, y = 2.0;
    double angle = cordic_atan2(y, x);
    printf("atan2(%f, %f) = %f radians (%.2f degrees)\n", y, x, angle, angle * 180 / PI);
    return 0;
}
