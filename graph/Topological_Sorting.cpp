//
// Created by 十五哒哒哒 on 2022/7/16.
// 拓扑排序
//

#include <iostream>
#include <stack>

using namespace std;

typedef struct node {
    int index; // 邻接顶点的下标
    struct node *next;
} *FirstEdge;

typedef struct peak {
    int in; // 入度的数量
    int val; // 顶点的值
    FirstEdge fe; // 邻接表
} Peak;

Peak p[101];

// 初始化
void initPeak(int n) {
    for (int i = 0; i < n; i++) {
        p[i].in = 0;
        p[i].val = i;
        p[i].fe = new struct node;
        p[i].fe->next = nullptr;
    }
}

// 赋值
// vi : 起点
// vj : 终点
void createPeak(int vi, int vj) {
    p[vj].in++;
    FirstEdge temp = new struct node;
    temp->index = vj;
    temp->next = p[vi].fe->next;
    p[vi].fe->next = temp;
}

// 拓扑排序
void topological(int n) {
    stack<int> s;
    // 将没有前驱的顶点加入栈中 加入的是顶点的下标
    for (int i = 0; i < n; i++) {
        if (p[i].in == 0) s.push(i);
    }
    int count = 0; // 判断是否有回路
    int temp;
    while (!s.empty()) {
        count++;
        temp = s.top();
        cout << temp << " -> ";
        s.pop();
        // 删除这个顶点 即将这个顶点的后继结点的入度都减一 并将入度为0的顶点加入栈中
        FirstEdge q = p[temp].fe->next;
        while (q != nullptr) {
            p[q->index].in--;
            if (p[q->index].in == 0) s.push(q->index);
            q = q->next;
        }
    }
    cout << endl;
    if (count < n) {
        cout << "输入的图中存在回路" << endl;
    }
}

//int main() {
//    cout << "请输入结点的个数 : ";
//    int n;
//    cin >> n;
//    initPeak(n);
//    cout << "请输入边的个数 : ";
//    int e;
//    cin >> e;
//    int vi, vj;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i << "条边的起点和终点 : ";
//        cin >> vi >> vj;
//        createPeak(vi, vj);
//    }
//    topological(n);
//    return 0;
//}

