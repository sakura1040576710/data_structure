//
// Created by 十五哒哒哒 on 2022/7/19.
// 冒泡排序
//
#include <iostream>

using namespace std;

int arrBubbleClassify[101];
int arrBubbleImprove[101];

// 经典冒泡排序
void bubbleSortClassify(int n) {
    for (int i = 0; i < n - 1; i++) { // i控制轮数
        for (int j = 0; j < n - i - 1; j++) { // j控制每趟排序的个数
            if (arrBubbleClassify[j] > arrBubbleClassify[j + 1]) {
                int temp = arrBubbleClassify[j];
                arrBubbleClassify[j] = arrBubbleClassify[j + 1];
                arrBubbleClassify[j + 1] = temp;
            }
        }
    }
}

// 冒泡排序改进
void bubbleSortImprove(int n) {
    int bound = 0; // 控制每次循环的边界
    int exchange = n - 1; // 记录上一次循环最后一次交换的位置 如果没有交换则说明数组已经有序了
    while(exchange > 0){
        bound = exchange;
        exchange = 0;
        for(int i = 0;i < bound;i++){
            if (arrBubbleImprove[i] > arrBubbleImprove[i + 1]){
                int temp = arrBubbleImprove[i];
                arrBubbleImprove[i] = arrBubbleImprove[i + 1];
                arrBubbleImprove[i + 1] = temp;
                exchange = i;
            }
        }
    }
}

// 输出
void printBubble(int n) {
    for (int i = 0; i < n; i++) {
        cout << arrBubbleClassify[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arrBubbleImprove[i] << " ";
    }
    cout << endl;
}

//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> arrBubbleClassify[i];
//        arrBubbleImprove[i] = arrBubbleClassify[i];
//    }
//    bubbleSortClassify(n);
//    bubbleSortImprove(n);
//    printBubble(n);
//    return 0;
//}

