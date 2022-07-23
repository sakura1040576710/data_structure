//
// Created by 十五哒哒哒 on 2022/5/8.
// 多项式加法——数组实现
//
#include <iostream>

using namespace std;

void print(int a[], int n) {
    for (int i = n; i >= 0; --i) {
        if (a[i] == 0) continue; // 等于0则跳过

        // 处理符号
        if (i == n) { // 最高位
            if (a[i] < 0) {
                cout << "-";
            }
        } else { // 其他位
            if (a[i] < 0) {
                cout << "-";
            } else if (a[i] > 0) {
                cout << "+";
            }
        }

        // 处理系数
        if (i == 0) {
            cout << abs(a[i]);
            continue;
        }
        if (abs(a[i]) != 1) { // 系数为1的绝对值的时候 不输出
            cout << abs(a[i]);
        }

        // 处理指数
        cout << "x";
        if (i != 1) { // 当指数不为1时 则输出
            cout << "^" << i;
        }
    }
    cout << endl;
}

//int main() {
//    int a[101] = {0}; // 存第一个多项式的系数，下标则为指数
////    int b[101] = {0}; // 存第二个多项式的系数，下标则为指数
//    int maxA = 0; // 第一个多项式的最高指数
////    int maxB  =0; // 第二个多项式的最高指数
//
//    cout << "请输入第一个多项式的系数和指数，以(0 0)结束，指数的范围在0~101之间" << endl;
//    while (true) {
//        cout << "请输入系数和指数：";
//        int co, index; // co系数 index指数
//        cin >> co >> index;
//        if (co == 0 && index == 0) {
//            break;
//        }
//        a[index] += co;
//        if (index >= maxA) {
//            maxA = index;
//        }
//    }
//    cout << "请输入第二个多项式的系数和指数，以(0 0)结束，指数的范围在0~101之间" << endl;
//    while (true) {
//        cout << "请输入系数和指数：";
//        int co, index; // co系数 index指数
//        cin >> co >> index;
//        if (co == 0 && index == 0) {
//            break;
//        }
//        a[index] += co;
//        if (index >= maxA) {
//            maxA = index;
//        }
//    }
//    print(a, maxA);
//    return 0;
//}

