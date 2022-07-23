//
// Created by 十五哒哒哒 on 2022/5/6.
// 39:多项式输出
//

#include <iostream>

using namespace std;

//int main() {
//    int n;
//    int a[101] = {0};
//    while (cin >> n) {
//        for (int i = n; i >= 0; --i) {
//            cin >> a[i];
//        }
//
//        for (int i = n; i >= 0; --i) {
//
//            if (a[i] == 0) continue;
//
//            // 处理最高位的符号 保证最高位的系数不为0
//            if (i == n) {
//                if (a[i] < 0) {
//                    cout << "-";
//                }
//            } else { // 其他位
//                if (a[i] > 0) {
//                    cout << "+";
//                } else {
//                    cout << "-";
//                }
//            }
//
//            // 处理系数
//            if (i == 0) {
//                cout << abs(a[i]);
//                continue;
//            }
//            if (abs(a[i]) != 1) { // 绝对值等于1 就不输出
//                cout << abs(a[i]);
//            }
//
//            // 处理指数 当为最后一位的时候不需要输出x
//            cout << "x";
//            if (i != 1) { // 当x的指数为1时  不输出
//                cout << "^" << i;
//            }
//        }
//
//        cout << endl;
//    }
//    return 0;
//}
