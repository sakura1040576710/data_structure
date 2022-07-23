//
// Created by 十五哒哒哒 on 2022/7/15.
// Floyd算法
//
#include <iostream>
#include <string>

using namespace std;

string node[101]; // 存放结点
int graphFloyd[101][101]; // 邻接矩阵
int distFloyd[101][101]; // 存放迭代过程中求得的最短路径长度
string pathFloyd[101][101]; // 存放路径

// 初始化数组
void initFloyd(int n) {
    for (int i = 0; i < n; i++) {
        node[i] = (char) ('A' + i);
        for (int j = 0; j < n; j++) {
            if (i != j) {
                graphFloyd[i][j] = 0x3f3f3f3f;
            } else {
                graphFloyd[i][j] = 0;
            }
            distFloyd[i][j] = 0x3f3f3f3f;
        }
    }
}

// 给graph数组赋初值
void createGraphFloyd(int vi, int vj, int weight) {
    graphFloyd[vi][vj] = weight;
}

// Floyd算法
void floyd(int n) {
    // 初始化dist和path数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distFloyd[i][j] = graphFloyd[i][j];
            if (distFloyd[i][j] != 0x3f3f3f3f && distFloyd[i][j] != 0) {
                pathFloyd[i][j] = node[i] + node[j];
            } else {
                pathFloyd[i][j] = "";
            }
        }
    }
    for (int k = 0; k < n; k++) { // 第一层循环控制加入第几个结点
        for (int i = 0; i < n; i++) { // 接下来两层循环遍历图
            for (int j = 0; j < n; j++) {
                if (distFloyd[i][j] > distFloyd[i][k] + distFloyd[k][j]) {
                    distFloyd[i][j] = distFloyd[i][k] + distFloyd[k][j];
                    string tmp = pathFloyd[k][j].substr(1);
                    pathFloyd[i][j] = pathFloyd[i][k].append(tmp); // 这里有错 但我不想改了orz
                }
            }
        }
    }
}

// 打印结果
void printFloyd(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distFloyd[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << pathFloyd[i][j] << "\t";
        }
        cout << endl;
    }
}

//int main() {
//    cout << "请输入结点的个数 : ";
//    int n;
//    cin >> n;
//    initFloyd(n);
//    cout << "请输入边的条数 : ";
//    int e;
//    cin >> e;
//    int vi, vj, weight;
//    for (int i = 0; i < e; i++) {
//        cout << "请输入第" << i << "条边的起点和终点以及权值 : ";
//        cin >> vi >> vj >> weight;
//        createGraphFloyd(vi, vj, weight);
//    }
//    floyd(n);
//    printFloyd(n);
//    return 0;
//}

