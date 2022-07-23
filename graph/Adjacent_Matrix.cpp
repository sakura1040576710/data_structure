//
// Created by 十五哒哒哒 on 2022/7/12.
// 无向图的邻接矩阵的创建、输出、DFS遍历
//
#include <iostream>
#include <queue>

using namespace std;

int graph[101][101];
int visited[101];
int matrix[101];

// 打印矩阵
// n : 结点个数
void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// DFS遍历——递归
void DFS(int i, int n) {
    cout << matrix[i] << " -> ";
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (graph[i][j] == 1 && visited[j] == 0) { // i->j有通路 && 没有访问过j
            DFS(j, n);
        }
    }
}

// BFS遍历
void BFS(int i,int n){
    queue<int> q;
    visited[i] = 1;
    cout << i << " -> ";
    q.push(i);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int j = 0;j < n;j++){
            if (graph[tmp][j] == 1 && visited[j] == 0){
                q.push(j);
                visited[j] = 1;
                cout << j << " -> ";
            }
        }
    }
}

//int main() {
//    cout << "请输入结点的个数 : ";
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        matrix[i] = i;
//    }
//    cout << "请输入边的条数 : ";
//    int e;
//    cin >> e;
//    cout << "请依次输入哪些结点之间有边(下标从0开始) : " << endl;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i + 1 << "条边 : ";
//        int vi, vj;
//        cin >> vi >> vj;
//        graph[vi][vj] = 1;
//        graph[vj][vi] = 1;
//    }
//    printGraph(n);
////    DFS(0, n);
//    BFS(0,n);
//    return 0;
//}

