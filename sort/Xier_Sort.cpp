//
// Created by 十五哒哒哒 on 2022/7/19.
// 希尔排序
//

#include <iostream>
using namespace std;

int arrXier[101];

// 希尔排序
void xierSort(int n){
    for(int d = n / 2;d >= 1;d /= 2){
        for(int i = d + 1;i <= n;i++){
            arrXier[0] = arrXier[i];
            int j = i - d;
            while(j >= 1 && arrXier[0] < arrXier[j]){
                arrXier[j + d] = arrXier[j];
                j -= d;
            }
            arrXier[j + d] = arrXier[0];
        }
    }
}

// 输出
void printXier(int n){
    for(int i = 1;i <= n ;i++){
        cout << arrXier[i] << " ";
    }
}

//int main(){
//    int n;
//    cin >> n;
//    for(int i = 1;i <= n;i++){
//        cin >> arrXier[i];
//    }
//    xierSort(n);
//    printXier(n);
//    return 0;
//}

