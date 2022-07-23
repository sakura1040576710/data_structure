//
// Created by 十五哒哒哒 on 2022/7/14.
// Dijkstra算法 —— 有向图
//

#include <iostream>
#include <stack>

using namespace std;

int s[101]; // 存放所有结点 0表示没有加入集合 1表示加入集合
int dist[101]; // 存放最短路径的长度 就是从起点开始到其他顶点的最短距离
int path[101]; // 存放最短路径 -1表示顶点不可达
int map_matrix[101][101]; // 邻接矩阵

// 全局参数的初始化
void initParam(int n) {
    for (int i = 0; i < n; i++) {
        s[i] = 0;
        dist[i] = 0x3f3f3f3f;
        path[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) map_matrix[i][j] = 0;
            else map_matrix[i][j] = 0x3f3f3f3f;
        }
    }
}

// 给邻接矩阵赋值
void updateMapMatrix(int vi, int vj, int weight) {
    map_matrix[vi][vj] = weight;
}

// 查找dist数组中的最短距离
// 不能包括已经处理过的结点
int getMinDistance(int n) {
    int minDis = 0x3f3f3f3f;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0 && dist[i] < minDis) {
            minDis = dist[i];
            index = i;
        }
    }
    return index;
}

// Dijkstra算法实现
// n : 顶点个数
// start : 起点下标
void dijkstra(int start, int n) {
    // 将下标加入到s数组中
    s[start] = 1;
    // 将dist数组和path数组更新
    for (int i = 0; i < n; i++) {
        dist[i] = map_matrix[start][i];
        if (dist[i] != 0x3f3f3f3f) { // dist为0x3f3f3f3f时 不可达
            path[i] = start;
        }
    }
    int num = 1; // 已处理的顶点数
    int index;
    while (num < n) {
        // 查找dist中最短的距离
        index = getMinDistance(n);
        cout << "从" << start << "顶点到" << index << "顶点的最短距离是" << dist[index] << endl;
        // 将该顶点加入已处理集合
        s[index] = 1;
        // 更新path数组和dist数组
        // 注意 也只更新没有处理过的集合
        for (int i = 0; i < n; i++) {
            if (s[i] == 0 && dist[i] > dist[index] + map_matrix[index][i]) {
                dist[i] = dist[index] + map_matrix[index][i];
                path[i] = index;
            }
        }
        num++;
    }
}

// 根据path数组中的内容输出从起点到每个点的最短距离的路径
void printInfoByPath(int start, int n) {
    for (int i = 0; i < n; i++) {
        if (start == i) continue;
        stack<int> s;
        s.push(i);
        int temp = i;
        while (path[temp] != 0) {
            temp = path[temp];
            s.push(temp);
        }
        s.push(0);
        cout << "从开始结点第" << i << "个结点的最短路径是 : ";
        while (!s.empty()) {
            cout << s.top() << " -> ";
            s.pop();
        }
        cout << endl;
    }
}

//int main() {
//    cout << "请输入顶点的个数 ： ";
//    int n;
//    cin >> n;
//    initParam(n);
//    cout << "请输入边的条数 : ";
//    int e;
//    cin >> e;
//    int vi, vj, weight;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入依次第" << i << "条边的起点和终点以及权值 : ";
//        cin >> vi >> vj >> weight;
//        updateMapMatrix(vi, vj, weight);
//    }
//    cout << "请输入起始结点 : ";
//    int begin;
//    cin >> begin;
//    dijkstra(begin, n);
////    for(int i = 0; i < n;i++){
////        cout << path[i] << " ";
////    }
//    printInfoByPath(begin,n);
//    return 0;
//}

