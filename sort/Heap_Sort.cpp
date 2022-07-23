//
// Created by 十五哒哒哒 on 2022/7/20.
// 堆排序
//
#include <iostream>

using namespace std;

int arrHeap[101];

// 构建大根堆
// n : 调整的范围
// k : 开始调整的结点下标
void sift(int n, int k) {
    int i = k;
    int j = 2 * i; // 完全二叉树的性质 双亲结点i -> 左孩子结点2 * i;
    while (j <= n) { // 当前的孩子结点是否 <= 数组的大小
        if (j < n && arrHeap[j] < arrHeap[j + 1]) j++; // 当j < k时 表明当前的双亲结点有右孩子 就判断左孩子和右孩子哪个大 大的那个再去和双亲结点比较
        if (arrHeap[i] < arrHeap[j]) { // 当孩子结点比双亲结点大时 就需要进行交换
            int temp = arrHeap[i];
            arrHeap[i] = arrHeap[j];
            arrHeap[j] = temp;
        }
        // 交换完成后 还需要判断交换下来的双亲结点和接下来的孩子结点之间的大小关系  要是小于还需要继续调整
        i = j;
        j = 2 * i;
    }
}

// 堆排序
void heapSort(int n) {
    for (int i = n / 2; i >= 1; i--) { // 构建初始的大根堆 下标为n/2的数据就是最后一个拥有子结点的结点 依次构建所有有孩子结点的结点
        sift(n, i);
    }
    for (int i = 1; i < n; i++) {
        // 此时下标为1的数据是最大的数据 将它交换到数组的末尾
        // 每次交换完后 就要少判断一个结点 所以数组的末尾的下标一直在变化
        int temp = arrHeap[1];
        arrHeap[1] = arrHeap[n - i + 1];
        arrHeap[n - i + 1] = temp;
        // 交换完成后 调整堆
        sift(n - i, 1);
    }
}

// 输出
void printHeap(int n) {
    for (int i = 1; i <= n; i++) {
        cout << arrHeap[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { // 堆排下标最好从1开始
        cin >> arrHeap[i];
    }
    heapSort(n);
    printHeap(n);
    return 0;
}

