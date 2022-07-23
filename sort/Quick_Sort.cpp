//
// Created by 十五哒哒哒 on 2022/7/20.
// 快速排序
//
#include <iostream>

using namespace std;

int arrQuick[101];

// 获取哨兵的值
int partition(int begin, int end) {
    int i = begin, j = end; // 选取begin当哨兵 比哨兵小的都在哨兵的前面 比哨兵大的都在哨兵的后面
    int temp;
    while (i < j) { // 循环中被交换的一直都是哨兵
        while (i < j && arrQuick[i] <= arrQuick[j]) j--;
        if (i < j) {
            temp = arrQuick[j];
            arrQuick[j] = arrQuick[i];
            arrQuick[i] = temp;
            i++;
        }
        while (i < j && arrQuick[i] <= arrQuick[j]) i++;
        if (i < j) {
            temp = arrQuick[i];
            arrQuick[i] = arrQuick[j];
            arrQuick[j] = temp;
            j--;
        }
    }
    return i; // i == j时返回哨兵的下标
}

// 快速排序
void quickSort(int begin, int end) {
    if (begin < end) { // 递归的出口
        int index = partition(begin, end);
        quickSort(begin, index - 1);
        quickSort(index + 1, end);
    }
}

// 输出
void printQuickSort(int n){
    for(int i = 0;i < n;i++){
        cout << arrQuick[i] << " ";
    }
}

//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> arrQuick[i];
//    }
//    quickSort(0, n - 1);
//    printQuickSort(n);
//    return 0;
//}

