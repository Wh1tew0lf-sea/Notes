#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 长方形的长和宽
    int length = 343720;
    int width = 233333;

    // 水平和垂直方向上的速度比
    double dx_dy_ratio = 15.0 / 17.0;

    // 初始速度分解
    double dx = 15.0;
    double dy = 17.0;

    // 初始位置
    double x = 0.0;
    double y = 0.0;

    // 总路程
    double total_distance = 0.0;

    // 当前方向
    enum Direction { RIGHT, LEFT, UP, DOWN };
    Direction direction = RIGHT;

    while (true) {
        // 计算水平和垂直方向上的步长
        double delta_x = dx;
        double delta_y = dy;

        // 更新位置
        switch (direction) {
            case RIGHT:
                x += delta_x;
                break;
            case LEFT:
                x -= delta_x;
                break;
            case UP:
                y += delta_y;
                break;
            case DOWN:
                y -= delta_y;
                break;
        }

        // 更新总路程
        total_distance += delta_x + delta_y;

        // 检查是否碰到边界
        if (x <= 0 || x >= length) {
            // 碰到左右边界，改变水平方向
            direction = (direction == RIGHT) ? LEFT : RIGHT;
        }
        if (y <= 0 || y >= width) {
            // 碰到上下边界，改变垂直方向
            direction = (direction == UP) ? DOWN : UP;
        }

        // 如果小球回到左上角顶点，结束循环
        if (x == 0 && y == 0) {
            break;
        }
    }

    // 输出结果
    cout << "Total distance traveled by the ball: " << total_distance << " units" << endl;

    return 0;
}
