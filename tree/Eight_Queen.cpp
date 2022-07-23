//
// Created by 十五哒哒哒 on 2022/7/9.
// 八皇后问题
//
#include <iostream>

using namespace std;

int place[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; // 下标表示皇后的编号以及所在行数 值表示皇后所在列数
bool flag[8] = {true, true, true, true, true, true, true, true}; // 判断col是否可以可以放皇后
bool d1[16] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
               true}; // 判断上对角线是否可以放皇后 每条对角线的n-col+7是一样的（+7是因为有些n-col是负数 但是数组的下标没有负数 所以+7
bool d2[16] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
               true}; // 判断下对角线是否可以放皇后 每条对角线的n+col是一样的
int num = 0; // 计算一共有多少种方式

void printMap() {
    num++;
    cout << "No . " << num << endl;
    for (int i : place) {
        for (int j = 0; j < 8; ++j) {
            if (i == j) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void put(int n) { // n是行号
    for (int col = 0; col < 8; col++) { // 列
        if (flag[col] && d1[n - col + 7] && d2[n + col]) { // 列上没有 && 上对角线没有 && 下对角线没有
            place[n] = col; // 放置
            flag[col] = false;
            d1[n - col + 7] = false;
            d2[n + col] = false;
            if (n < 7) { // 如果当前行数小于7表示没有到最后 继续放置
                put(n + 1);
            } else { // 当前行数是第七行（从0开始计算） 则放置完成 -> 打印
                printMap();
            }
            // 回溯 取消占领 目的是为了找到所有的结果
            place[n] = -1;
            flag[col] = true;
            d1[n - col + 7] = true;
            d2[n + col] = true;
        }
    }
}

//int main() {
//    put(0);
//    return 0;
//}

