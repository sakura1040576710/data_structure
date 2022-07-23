//
// Created by 十五哒哒哒 on 2022/7/13.
// 最小转机问题
//

#include <iostream>
#include <queue>

using namespace std;

// 边表
typedef struct arcNode {
    int adjvex; // 下标
    struct arcNode *next;
} *ArcNode;

// 顶点结点
typedef struct vertexNode {
    char vertex; // 值
    ArcNode firstEdge;
} VertexNode;

VertexNode vnode[101];
int visitedTurning[101];
char matrixTurning[101];

// 初始化全局变量
void init(char w[], int n) {
    for (int i = 0; i < n; i++) {
        vnode[i].vertex = w[i];
        vnode[i].firstEdge = new struct arcNode;
        vnode[i].firstEdge->next = nullptr;
        visitedTurning[i] = 0;
        matrixTurning[i] = w[i];
    }
}

// 插入边表
void createArcNode(int vi, int vj) {
    // 插入vi的边表
    VertexNode temp = vnode[vi];
    ArcNode tempArcNode = temp.firstEdge;
    auto an = new struct arcNode;
    an->adjvex = vj;
    an->next = tempArcNode->next;
    tempArcNode->next = an;
    // 插入vj的边表
    temp = vnode[vj];
    tempArcNode = temp.firstEdge;
    an = new struct arcNode;
    an->adjvex = vi;
    an->next = tempArcNode->next;
    tempArcNode->next = an;
}

// 输出顶点表及其边表信息
void printInfo(int n) {
    for (int i = 0; i < n; i++) {
        cout << "第 " << i << "个顶点的值为 " << vnode[i].vertex << endl;
        cout << "其边表的下标依次为 : ";
        ArcNode p = vnode[i].firstEdge->next;
        while (p != nullptr) {
            cout << p->adjvex << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// 找到转机次数最少的方案
void BFSSolution(int vi, int vj) {
    queue<VertexNode> q;
    visitedTurning[vi] = 1;
    q.push(vnode[vi]);
    cout << vnode[vi].vertex << " ";
    while (!q.empty()) {
        VertexNode temp = q.front();
        q.pop();
        ArcNode p = temp.firstEdge ->next;
        while (p != nullptr) {
            if (p->adjvex == vj) {
                cout << temp.vertex << " ";
                cout << vnode[p->adjvex].vertex << " ";
                return;
            }
            p = p->next;
        }
        p = temp.firstEdge -> next;
        while (p != nullptr) {
            if (visitedTurning[p->adjvex] == 0) {
                q.push(vnode[p->adjvex]);
                visitedTurning[p->adjvex] = 1;
//                cout << vnode[p->adjvex].vertex << " ";
            }
            p = p->next;
        }
    }
}

//int main() {
//    cout << "请输入城市的个数 : ";
//    int n;
//    cin >> n;
//    char w[101];
//    for (int i = 0; i < n; i++) {
//        cout << "请输入第 " << i << " 个城市的名字 : ";
//        cin >> w[i];
//    }
//    init(w, n);
//    cout << "请输入边的条数 : ";
//    int e;
//    cin >> e;
//    int vi, vj;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第 " << i << " 条边的起点和终点的下标(从0开始) : ";
//        cin >> vi >> vj;
//        createArcNode(vi, vj);
//    }
//    printInfo(n);
//    cout << "请输入城市的起点和终点下标 : ";
//    cin >> vi >> vj;
//    BFSSolution(vi, vj);
//    return 0;
//}

