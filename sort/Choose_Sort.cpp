//
// Created by 十五哒哒哒 on 2022/7/20.
// 选择排序
//
#include <iostream>
using namespace std;

int arrChoose[101];

// 选择排序
void chooseSort(int n){
    for(int i = 0;i < n;i++){
        int min = i; // min存下标
        for(int j = i + 1;j < n;j++){
            if (arrChoose[j] < arrChoose[min]){ // 找到无序区中最小数的下标
                min = j;
            }
        }
        if (min != i){ // 无序区最小的记录作为有序区的第i个记录
            int temp = arrChoose[i];
            arrChoose[i] = arrChoose[min];
            arrChoose[min] = temp;
        }
    }
}

// 输出
void printChooseSort(int n){
    for(int i = 0;i < n;i++){
        cout << arrChoose[i] << " ";
    }
}

//int main(){
//    int n;
//    cin >> n;
//    for(int i = 0;i < n;i++){
//        cin >> arrChoose[i];
//    }
//    chooseSort(n);
//    printChooseSort(n);
//    return 0;
//}
