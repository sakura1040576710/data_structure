//
// Created by 十五哒哒哒 on 2022/5/6.
// 数组标志位实现——约瑟夫问题
//
#include <iostream>
using namespace std;

//int main(){
//    int n,m; // n表示猴子个数 m表示报数
//    while(true){
//        cin >> n >> m;
//        if (n == 0 || m == 0){
//            return 0;
//        }
//        int arr[310] = {0};
//        // 赋初值
//        for (int i = 0; i < n; ++i) {
//            arr[i] = i + 1;
//        }
//        int num = n; // 防止修改n
//        int i = 0; // 用于遍历下标
//        int count = 1; // 用于计报数
//        while(num > 1){
//            if (arr[i] != 0){ // 该数组对应的位数不为0 报数
//                if (count == m){
//                    num--;
//                    arr[i] = 0; // 为0表示该处的猴子已经淘汰了
//                    i = (i + 1) % n;
//                    count = 1;
//                }else{
//                    i = (i + 1) % n;
//                    count++;
//                }
//            }else{ // 该数组对应的位数为0 就取下一个
//                i = (i + 1) % n;
//            }
//        }
//        for (int j = 0; j < n; ++j) {
//            if (arr[j] != 0){
//                cout << arr[j] << endl;
//            }
//        }
//    }
//}

