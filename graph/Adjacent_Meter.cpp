//
// Created by 十五哒哒哒 on 2022/7/12.
// 邻接表的创建、输出、遍历
//
#include <iostream>
#include <queue>

using namespace std;

// 边表
typedef struct arcNode {
    int adjvex; // 顶点连接边的下标
    struct arcNode *next; // 下一条边
} *ArcNode;

// 顶点表
typedef struct vertexNode {
    int vertex; // 顶点的值
    ArcNode firstEdge; // 边表
} VertexNode;

VertexNode vn[101]; // 顶点表
int visitedMeter[101]; // 存储顶点是否被访问过
int matrixMeter[101]; // 存储顶点

// 初始化顶点表和visited数组
void initVertexNode(int n) {
    for (int i = 0; i < n; i++) {
        vn[i].vertex = i; // 顶点的值就为从0开始的数
        vn[i].firstEdge = nullptr;
    }
    for (int i = 0; i < n; i++) {
        visitedMeter[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        matrixMeter[i] = i;
    }
}

// 构建顶点表的边表
// vi表示起点 vj表示终点
void createFirstEdge(int vi, int vj) {
    auto an = new struct arcNode;
    an->next = nullptr;
    an->adjvex = vj;
    an->next = vn[vi].firstEdge;
    vn[vi].firstEdge = an;
    an = new struct arcNode;
    an->next = nullptr;
    an->adjvex = vi;
    an->next = vn[vj].firstEdge;
    vn[vj].firstEdge = an;
}

// 输出顶点表及其边表
void printMeter(int n) {
    for (int i = 0; i < n; i++) {
        cout << "第 " << i << " 个结点的值为" << vn[i].vertex << endl;
        cout << "其边表的下标为 : ";
        ArcNode an = vn[i].firstEdge;
        while (an != nullptr) {
            cout << an->adjvex << " ";
            an = an->next;
        }
        cout << endl;
    }
}

// DFS——递归
// 这个递归的结果和邻接矩阵的不太一样 因为边表的没有按顺序排列
void DFSMeter(int i, int n) {
    VertexNode node = vn[i];
    visitedMeter[i] = 1;
    cout << matrixMeter[i] << " -> ";
    ArcNode aNode = node.firstEdge;
    while (aNode != nullptr) {
        if (visitedMeter[aNode->adjvex] == 0) {
            DFSMeter(aNode->adjvex, n);
        }
        aNode = aNode->next;
    }
}

// BFS
void BFSMeter(int i, int n) {
    cout << i << " -> ";
    visitedMeter[i] = 1;
    queue<VertexNode> q;
    q.push(vn[i]);
    while (!q.empty()) {
        VertexNode tmp = q.front();
        q.pop();
        ArcNode aNode = tmp.firstEdge;
        while (aNode != nullptr) {
            if (visitedMeter[aNode->adjvex] == 0) {
                cout << aNode->adjvex << " -> "; // 访问顶点
                visitedMeter[aNode->adjvex] = 1; // 设置visited
                q.push(vn[aNode->adjvex]); // 入队
            }
            aNode = aNode->next;
        }
    }
}

//int main() {
//    cout << "请输入顶点的个数 : ";
//    int n;
//    cin >> n;
//    initVertexNode(n);
//    cout << "请输入边的条数 : ";
//    int e;
//    cin >> e;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i << "条边的起点和终点的下标 : ";
//        int vi, vj;
//        cin >> vi >> vj; // 此时顶点在顶点表的下标和值是一样的
//        createFirstEdge(vi, vj);
//    }
//    printMeter(n);
////    DFSMeter(0, n);
//    BFSMeter(0, n);
//    return 0;
//}

