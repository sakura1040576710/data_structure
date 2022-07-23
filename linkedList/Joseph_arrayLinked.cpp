//
// Created by 十五哒哒哒 on 2022/5/6.
// 数组链接方式——约瑟夫问题
//

#include <iostream>
using namespace std;

//int main(){
//    int n,m;
//    while(true){
//        cin >> n >> m;
//        if (n == 0 || m == 0){
//            return 0;
//        }
//        int arr[310] = {0}; // 该数组中存的内容是该位置上的元素指向的下一个元素的下标
//        for (int i = 0; i < n - 1; ++i) {
//            arr[i] = i + 1; // 存的是下一个元素的下标
//        }
//        arr[n - 1] = 0;
//        // 和链表一样 需要维护两个指针 一前一后
//        int pos = 0;
//        int prior = n - 1;
//        int num = n; // 用于计算还剩几个元素没被淘汰
//        int count = 1; // 用于计数
//        while (num > 1){
//            if (count != m){ // 没有到m的时候 则移动指针
//                prior = pos;
//                pos = arr[pos]; // 时刻记住arr存的是指向的下一个元素的下标
//                count++;
//            }else{
//                num--;
//                count = 1;
//                arr[prior] = arr[pos]; // 更改链接关系
//                arr[pos] = -1; // 淘汰的猴子置为-1
//                pos = arr[prior]; // pos指向下一个有效的位置
//            }
//        }
//        // 下面两种输出方法都可以
//        // 此时的pos（prior和pos是一样的）就存的是最后一个猴子的下标 因为编号从1开始 所以记得+1
//        cout << pos + 1 << endl;
////        for (int i = 0; i < n; ++i) {
////            if (arr[i] != -1){
////                cout << i + 1 << endl;
////                break;
////            }
////        }
//    }
//}

