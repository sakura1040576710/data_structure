//
// Created by 十五哒哒哒 on 2022/7/19.
// 插入排序
//
#include <iostream>
using namespace std;

int arr[101];

// 直接插入排序
void insertSort(int n){
    for(int i = 2;i <= n;i++){
        arr[0] = arr[i]; // i指向的内容为待排序的值
        int j = i - 1; // 从后往前遍历
        while (arr[j] > arr[0]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[0];
    }
}

// 使用二分查找改进直接插入排序
void improveInsertSort(int n){
    int low,high,mid;
    for(int i = 2;i <= n;i++){
        arr[0] = arr[i];
        low = 1,high = i - 1;
        while(low <= high){
            mid = low + ((high - low) >> 1);
            if (arr[mid] == arr[0]) break;
            if (arr[mid] < arr[0]) low = mid + 1;
            else high = mid - 1;
        }
        for(int j = i - 1;j >= mid;j--){
            arr[j + 1] = arr[j];
        }
        arr[mid] = arr[0];
    }
}

// 输出
void printArr(int n){
    for(int i = 1;i <= n;i++){
        cout << arr[i] << " -> ";
    }
}

//int main(){
//    int n;
//    cin >> n;
//    for(int i = 1;i <= n;i++){
//        cin >> arr[i];
//    }
////    insertSort(n);
//    improveInsertSort(n);
//    printArr(n);
//    return 0;
//}