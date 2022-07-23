//
// Created by 十五哒哒哒 on 2022/7/7.
//
#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

typedef struct Triple {
    int row; // 行
    int col; // 列
    int item; // 值
} triple;

typedef struct TripleMatrix {
    triple data[MAX_SIZE];
    int mu; // 行
    int nu; // 列
    int num; // 非零元素的个数
} triple_matrix;

triple_matrix tm;

bool cmp(triple t1, triple t2) {
    if (t1.row < t2.row) return true;
    if (t1.row == t2.row) {
        if (t1.col < t2.col) return true;
    }
    return false;
}

void printMatrix(triple_matrix t, int row, int col, int num) {
//    bool flag = true;
    int index = 0;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
//            for (int k = 0; k < num; ++k) {
//                flag = true;
//                if (t.data[k].row == i && t.data[k].col == j) {
//                    cout << t.data[k].item << " ";
//                    flag = false;
//                    break;
//                }
//                if (t.data[k].row > i || t.data[k].col > j) {
//                    break;
//                }
//            }
//            if (flag){
//                cout << "0 ";
//            }
            if (t.data[index].row == i && t.data[index].col == j){
                cout << t.data[index].item << " ";
                index++;
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

//int main() {
//    cout << "请输入矩阵的行和列：";
//    int row, col;
//    cin >> row >> col;
//    tm.mu = row;
//    tm.nu = col;
//    cout << "请输入非零元素的个数:";
//    int num;
//    cin >> num;
//    tm.num = num;
//    for (int i = 0; i < num; ++i) {
//        cout << "请依次输入行、列、非零元:";
//        int r, c, item;
//        cin >> r >> c >> item;
//        tm.data[i].row = r;
//        tm.data[i].col = c;
//        tm.data[i].item = item;
//    }
//    sort(tm.data, tm.data + num, cmp);
////    for (int i = 0; i < num; ++i) {
////        cout << tm.data[i].row << "  " << tm.data[i].col << "  " << tm.data[i].item << endl;
////    }
//    printMatrix(tm, row, col, num);
//    return 0;
//}

