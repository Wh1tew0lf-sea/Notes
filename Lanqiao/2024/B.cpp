#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // �����εĳ��Ϳ�
    int length = 343720;
    int width = 233333;

    // ˮƽ�ʹ�ֱ�����ϵ��ٶȱ�
    double dx_dy_ratio = 15.0 / 17.0;

    // ��ʼ�ٶȷֽ�
    double dx = 15.0;
    double dy = 17.0;

    // ��ʼλ��
    double x = 0.0;
    double y = 0.0;

    // ��·��
    double total_distance = 0.0;

    // ��ǰ����
    enum Direction { RIGHT, LEFT, UP, DOWN };
    Direction direction = RIGHT;

    while (true) {
        // ����ˮƽ�ʹ�ֱ�����ϵĲ���
        double delta_x = dx;
        double delta_y = dy;

        // ����λ��
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

        // ������·��
        total_distance += delta_x + delta_y;

        // ����Ƿ������߽�
        if (x <= 0 || x >= length) {
            // �������ұ߽磬�ı�ˮƽ����
            direction = (direction == RIGHT) ? LEFT : RIGHT;
        }
        if (y <= 0 || y >= width) {
            // �������±߽磬�ı䴹ֱ����
            direction = (direction == UP) ? DOWN : UP;
        }

        // ���С��ص����ϽǶ��㣬����ѭ��
        if (x == 0 && y == 0) {
            break;
        }
    }

    // ������
    cout << "Total distance traveled by the ball: " << total_distance << " units" << endl;

    return 0;
}
