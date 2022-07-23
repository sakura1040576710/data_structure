//
// Created by 十五哒哒哒 on 2022/7/11.
// 哈夫曼树的创建
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef struct node {
    int weight; // 权值
    int left, right, parent; // 左孩子 右孩子 双亲结点
} HFNode;


int w[101];
HFNode huff[202];

//// 冒泡排序
//void bubbleSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] >= arr[j + 1]){
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}

// 找到最小的两个权值
void getTwoMin(HFNode huff[], int n, int &i1, int &i2) {
    map<int, int> m;
    m.clear();
    int arr[202];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (huff[i].parent == -1) {
            m.insert(pair<int, int>(i, huff[i].weight));
            arr[index++] = huff[i].weight;
        }
    }
    sort(arr, arr + index);
//    bubbleSort(arr, index);
    int min1 = arr[0];
    int min2 = arr[1];
    for (auto &iter : m) {
//        cout << iter.first << " --- " << iter.second << endl;
        if (iter.second == min1) {
            i1 = iter.first;
            break;
        }
    }
    for (auto &iter : m) {
        if (iter.second == min2  && iter.first != i1) {
            i2 = iter.first;
            break;
        }
    }
    cout << "最小下标 : " << i1 << "   次小下标 : " << i2 << endl;
}

// 创建哈夫曼树
// huff : 哈夫曼结点
// w : 权值
// n : 结点个数
void createHuffTree(HFNode huff[], int w[], int n) {
    // 初始化
    for (int i = 0; i < 2 * n - 1; ++i) { // 一共2n-1个长度
        huff[i].weight = -1;
        huff[i].left = -1;
        huff[i].right = -1;
        huff[i].parent = -1;
    }
    // 给前n个结点赋权值
    for (int i = 0; i < n; i++) {
        huff[i].weight = w[i];
    }
    // 构建哈夫曼树
    for (int i = n; i < 2 * n - 1; ++i) {
        int i1, i2;
        getTwoMin(huff, i, i1, i2);
        huff[i].weight = huff[i1].weight + huff[i2].weight;
        huff[i1].parent = i;
        huff[i2].parent = i;
        huff[i].left = i1;
        huff[i].right = i2;
    }
}

void printHuffTree(HFNode huff[], int n) {
    cout << "weight" << "\t" << "parent\t" << "lchild\t" << "rchild" << endl;
    for (int i = 0; i < 2 * n - 1; ++i) {
        cout << huff[i].weight << "\t" << huff[i].parent << "\t" << huff[i].left << "\t" << huff[i].right << endl;
    }
}

// 求哈夫曼编码
// huff : 哈夫曼结点
// huffCode : 存储每个结点的哈夫曼编码
// n : 结点个数
void getHuffCoding(HFNode huff[],char* huffCode[],int n){
    int start;
    int pos;
    int parent;
    char* temp = new char[n]; // 存储每次循环临时生成的哈夫曼编码
    temp[n - 1] = '\0';
    for(int i = 0;i < n ;i++){
        start = n - 1; // temp数组的下标索引
        pos = i; // 记录当前结点的下标
        parent = huff[i].parent; // 记录当前结点的双亲结点下标
        while (parent != -1){
            if (huff[parent].left == pos){ // 如果当前结点是该双亲结点的左孩子
                temp[--start] = '0'; // 填充0
            }else if (huff[parent].right == pos){ // 如果当前结点是该双亲结点的左孩子
                temp[--start] = '1'; // 填充1
            }
            pos = parent; // 当前结点移动到双亲结点
            parent = huff[pos].parent; // 更新双亲结点
        }
        huffCode[i] = new char[n - start]; // n - start表示哈夫曼编码实际需要的大小
        strcpy(huffCode[i],&temp[start]); // 将temp数组的值复制给huffCode
    }
    delete[] temp;
}

//int main() {
//    int n;
//    cout << "请输入结点个数 : ";
//    cin >> n;
//    cout << "请输入" << n << "个权值 : ";
//    for (int i = 0; i < n; ++i) {
//        cin >> w[i];
//    }
//    createHuffTree(huff, w, n);
//    printHuffTree(huff, n);
//
//    char **huffCode = new char*[n];
//    getHuffCoding(huff,huffCode,n);
//    for(int i = 0;i < n;i++){
//        cout << huff[i].weight << " : ";
//        for(int j = 0; j < strlen(huffCode[i]);j++){
//            cout << huffCode[i][j];
//        }
//        cout << endl;
//    }
//    return 0;
//}

