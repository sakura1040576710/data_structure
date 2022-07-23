//
// Created by 十五哒哒哒 on 2022/7/8.
// 汉诺塔问题
//
#include <iostream>

using namespace std;

void print(char x, char y) {
    cout << x << " -> " << y << endl;
}

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        print(x, z);
    } else {
        hanoi(n - 1, x, z, y); // 将n-1个碟子从x开始经过z到达y
        print(x, z); // 将x上的最后一个碟子直接移动到z上
        hanoi(n - 1, y, x, z); // 再将n-1个碟子从y开始经过x到达z
    }
}

//int main() {
//    cout << "请输入碟子的个数 :  ";
//    int n;
//    cin >> n;
//    hanoi(n, 'a', 'b', 'c');
//    return 0;
//}

