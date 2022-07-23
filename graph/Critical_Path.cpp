//
// Created by 十五哒哒哒 on 2022/7/17.
// 关键路径
//
#include <iostream>
#include<stack>

using namespace std;

// 边表
typedef struct arcNodePath {
    int index; // 下标
    int weight; // 权值
    struct arcNodePath *next;
} *ArcNodePath;

// 邻接表
typedef struct vertexNodePath {
    int value; // 值
    int in; // 入度
    ArcNodePath arcNode; // 边表
} VertexNodePath;

VertexNodePath vnp[101];
int resultTop[101]; // 拓扑排序后的下标
int ve[101]; // 事件的最早发生时间
int vl[101]; // 事件的最晚发生时间
int ee[101]; // 活动的最早发生时间
int el[101]; // 活动的最晚发生时间

// 初始化邻接表
void initVertexNodePath(int n) {
    for (int i = 0; i < n; i++) {
        vnp[i].value = i;
        vnp[i].in = 0;
        vnp[i].arcNode = new struct arcNodePath;
        vnp[i].arcNode->next = nullptr;
    }
}

// 给邻接表赋值
void createVertexNodePath(int vi, int vj, int weight) {
    ArcNodePath temp = vnp[vi].arcNode;
    auto p = new arcNodePath;
    p->index = vj;
    p->weight = weight;
    p->next = temp->next;
    temp->next = p;
    vnp[vj].in++;
}

// 拓扑排序
// 无环返回true
bool topologicalSort(int n) {
    int count = 0; // 控制处理了的结点个数
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (vnp[i].in == 0) s.push(i);
    }
    ArcNodePath tempArc;
    int tempIndex;
    while (!s.empty()) {
        tempIndex = s.top();
        cout << tempIndex << " ";
        resultTop[count++] = tempIndex; // 将顶点下标按处理的顺序存起来
        s.pop();
        tempArc = vnp[tempIndex].arcNode->next;
        while (tempArc != nullptr) {
            vnp[tempArc->index].in--;
            if (vnp[tempArc->index].in == 0) s.push(tempArc->index);
            // 修改事件最早发生时间 即求ve数组 取最大值
            // tempIndex : 当前处理的起始顶点
            // tempArc : 当前处理的结束顶点
            if (ve[tempIndex] + tempArc->weight > ve[tempArc->index]) {
                ve[tempArc->index] = ve[tempIndex] + tempArc->weight;
            }
            tempArc = tempArc->next;
        }
    }
    cout << endl;
    if (count < n) {
        cout << "拓扑排序存在环 , 不存在关键路径" << endl;
        return false;
    }
    return true;
}

// 输出ve数组
void printVe(int n) {
    cout << "ve数组的内容为 : ";
    for (int i = 0; i < n; i++) {
        cout << ve[i] << " ";
    }
    cout << endl;
}

// 输出vl数组
void printVl(int n) {
    cout << "vl数组的内容为 : ";
    for (int i = 0; i < n; i++) {
        cout << vl[i] << " ";
    }
    cout << endl;
}

// 设置vl数组的值
void createVl(int n) {
    // 求vl数组 从后往前倒推
    // 可以把ve数组看成一个堆栈
    int resultTopIndex = n - 1;
    int inVex = resultTop[resultTopIndex--]; // 获取最后一个被处理顶点的下标
    for (int i = 0; i < n; i++) {
        vl[i] = ve[inVex]; // 赋初值为结束时间
    }
    ArcNodePath p;
    int outVex;
    while (resultTopIndex != -1) {
        inVex = resultTop[resultTopIndex--];
        p = vnp[inVex].arcNode->next;
        while (p != nullptr) {
            outVex = p->index;
            if (vl[inVex] > vl[outVex] - p->weight) {
                vl[inVex] = vl[outVex] - p->weight;
            }
            p = p->next;
        }
    }
}

// 输出关键路径
void criticalPath(int n) {
    cout << "关键路径为 : ";
    ArcNodePath p;
    int outVex;
    int tempEe, tempEl;
    for (int inVex = 0; inVex < n; inVex++) {
        p = vnp[inVex].arcNode->next;
        while (p != nullptr) {
            outVex = p->index;
            tempEe = ve[inVex]; // ee活动的最早开始时间就是这条弧的起点的最早开始时间
            tempEl = vl[outVex] - p->weight; // el活动的最晚开始时间就是这条弧的终点的最晚开始时间减去弧的权值
            if (tempEe == tempEl) {
                cout << "< " << inVex << " , " << outVex << " >" << p->weight << " -> ";
            }
            p = p->next;
        }
    }
    cout << endl;
}

//int main() {
//    cout << "请输入顶点的个数 : ";
//    int n;
//    cin >> n;
//    initVertexNodePath(n);
//    cout << "请输入边的个数 : ";
//    int e;
//    cin >> e;
//    int vi, vj, w;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i << "条边的起点终点以及权值 : ";
//        cin >> vi >> vj >> w;
//        createVertexNodePath(vi, vj, w);
//    }
//    cout << "拓扑排序的结果是 : ";
//    bool hasCir = topologicalSort(n); // 拓扑序列不唯一
//    if (hasCir) {
//        printVe(n);
//        createVl(n);
//        printVl(n);
//        criticalPath(n);
//    }
//    return 0;
//}

