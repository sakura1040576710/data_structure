//
// Created by 十五哒哒哒 on 2022/7/13.
// Kruskal算法
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node {
    int from, to; // 起点和终点下标
    int weight; // 权值
} Edge;

Edge edge[101]; // 存储结点之间边的信息
int index = 0; // 控制edge数组的下标
int node[101]; // 存储结点
int parent[101]; // 存储结点的根结点信息

// 自定义排序
bool cmp(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// 初始化node数组和parent数组
void initNode(int n) {
    for (int i = 0; i < n; i++) {
        node[i] = i;
        parent[i] = -1;
    }
}

// edge数组赋值
void initEdge(int vi, int vj, int weight) {
    edge[index].from = vi;
    edge[index].to = vj;
    edge[index].weight = weight;
    index++;
}

// 查找根结点
int getParent(int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

// 实现Kruskal算法
void kruskal(int n, int e) {
    int num = 0; // 判断合并了多少个结点
    Edge temp;
    int vi, vj;
    int pi, pj;
    for (int i = 0; i < e; i++) {
        // 根据edge数组 获取权值最小的一条边
        temp = edge[i];
        vi = temp.from;
        vj = temp.to;
        // 找到vi vj的根结点 判断这两个结点是不是同一个连通向量中的
        pi = getParent(vi);
        pj = getParent(vj);
        if (pi != pj) { // 不是同一个根结点才可以合并 合并是将根结点进行合并
            cout << "( " << vi << " , " << vj << " ) " << endl;
            // 合并生成树
            parent[pj] = pi;
            // 合并的顶点个数增加
            num++;
            if (num == n - 1) return;
        }
    }
}

//int main() {
//    cout << "请输入顶点的个数 : ";
//    int n;
//    cin >> n;
//    cout << "请输入边的个数 : ";
//    int e;
//    cin >> e;
//    initNode(n);
//    int vi, vj, weight;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i << "条边的起点、终点、权值 : ";
//        cin >> vi >> vj >> weight;
//        initEdge(vi, vj, weight);
//    }
//    // 对edge数组进行排序
//    sort(edge, edge + e, cmp);
////    for(int i = 0;i < e;i++){
////        cout << edge[i].from << " -> " << edge[i].to << " == " << edge[i].weight << endl;
////    }
//    // Kruskal算法
//    kruskal(n, e);
//    return 0;
//}

