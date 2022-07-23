//
// Created by 十五哒哒哒 on 2022/7/7.
// 稀疏矩阵加法和乘法
//

#include <iostream>
#include <algorithm>

#define MAX_SIZE 100
using namespace std;

typedef struct Triple {
    int row;
    int col;
    int item;
} triple;

typedef struct TripleMatrix {
    triple data[MAX_SIZE];
    int mu;
    int nu;
    int num;
} triple_matrix;

triple_matrix tm1;
triple_matrix tm2;
triple_matrix tm3;
triple_matrix tm4;

bool cmpA(triple t1, triple t2) {
    if (t1.row < t2.row) return true;
    if (t1.row == t2.row) {
        if (t1.col < t2.col) return true;
    }
    return false;
}

void printMatrixA(triple_matrix t, int row, int col, int num) {
    int index = 0;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (t.data[index].row == i && t.data[index].col == j) {
                cout << t.data[index].item << " ";
                index++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// 获取指定i j的元素值
int getItem(triple_matrix t, int i, int j) {
    for (int k = 0; k < t.num; ++k) {
        if (t.data[k].row == i && t.data[k].col == j) {
            return t.data[k].item;
        }
    }
    return 0;
}

// 加法
void addMatrix(triple_matrix t1, triple_matrix t2) {
    int index = 0;
    for (int i = 1; i <= t1.mu; ++i) {
        for (int j = 1; j <= t1.nu; ++j) {
            int result = getItem(t1, i, j) + getItem(t2, i, j);
            if (result != 0) { // 为0时不存储
                tm3.data[index].row = i, tm3.data[index].col = j;
                tm3.data[index++].item = result;
            } else {
                continue;
            }
        }
    }
    tm3.mu = t1.mu, tm3.nu = t1.nu, tm3.num = index;
}

// 乘法
// 前提是 a矩阵的列数 = b矩阵的行数
void multiMatrix(triple_matrix t1, triple_matrix t2) {
    if (t1.nu != t2.mu) return ;
    int index = 0;
    for (int i = 1; i <= t1.mu; ++i) { // a的行
        for (int j = 1; j <= t2.nu; ++j) { // b的列
            int sum = 0;
            for (int k = 1; k <= t1.nu; ++k) { // a的列/b的行
                sum += getItem(t1, i, k) * getItem(t2, k, j);
            }
            if (sum != 0) {
                tm4.data[index].row = i, tm4.data[index].col = j;
                tm4.data[index++].item = sum;
            }
        }
    }
    tm4.mu = t1.mu, tm4.nu = t2.nu, tm4.num = index;
}

//int main() {
//    int ir, ic, in;
//    int tr, tc, ti;
//    cout << "请输入稀疏矩阵的行和列:";
//    cin >> ir >> ic;
//
//    cout << "请输入第一个稀疏矩阵的非零元素个数:";
//    cin >> in;
//    tm1.mu = ir, tm1.nu = ic, tm1.num = in;
//    for (int i = 0; i < in; ++i) {
//        cout << "请依次第一个稀疏矩阵的输入行、列、非零元:";
//        cin >> tr >> tc >> ti;
//        tm1.data[i].row = tr, tm1.data[i].col = tc, tm1.data[i].item = ti;
//    }
//    sort(tm1.data, tm1.data + in, cmpA);
//
//    cout << "请输入第二个稀疏矩阵的非零元素个数:";
//    cin >> in;
//    tm2.mu = ir, tm2.nu = ic, tm2.num = in;
//    for (int i = 0; i < in; ++i) {
//        cout << "请依次第二个稀疏矩阵的输入行、列、非零元:";
//        cin >> tr >> tc >> ti;
//        tm2.data[i].row = tr, tm2.data[i].col = tc, tm2.data[i].item = ti;
//    }
//    sort(tm2.data, tm2.data + in, cmpA);
//
//    addMatrix(tm1, tm2); // 因为已经把两个相加的矩阵排过序了 得到的结果一定是有序的
//    cout << "相加的结果:" << endl;
//    printMatrixA(tm3, tm3.mu, tm3.nu, tm3.num);
//    cout << endl;
//    cout << endl;
//    multiMatrix(tm1, tm2);
//    cout << "乘法的结果:" << endl;
//    printMatrixA(tm4, tm4.mu, tm4.nu, tm4.num);
//    return 0;
//}

