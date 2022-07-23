//
// Created by 十五哒哒哒 on 2022/7/13.
// Prim算法实现
//

#include <iostream>
using namespace std;

typedef struct node{
    int index; // 起始结点的下标
    int value; // 权值
}ShortEdge;

int matrix[101][101]; // 邻接矩阵
ShortEdge se[101]; // 存储信息

// 初始化邻接矩阵
void initMatrix(int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            matrix[i][j] = 0x3f3f3f3f;
        }
    }
}

// 给邻接矩阵赋值
void updateMatrix(int vi,int vj,int w){
    matrix[vi][vj] = w;
    matrix[vj][vi] = w;
}

// 找到权值最小的结点的下标
int selectMinWeight(int n){
    int min = 0x3f3f3f3f;
    int index;
    for(int i = 0;i < n;i++){
        if (se[i].value != 0 && se[i].value < min){ // value==0时表示加入了集合U
            index = i;
            min = se[i].value;
        }
    }
    return index;
}

// 输出每次加入集合U的结点及其信息
void printUInfo(int index){
    cout << "( " << se[index].index << " , " << index << " ) " << se[index].value << endl;
}

// Prim算法
void prim(int start,int n){
    // 初始化se数组
    for(int i = 0;i < n;i++){
        se[i].index = start;
        se[i].value = matrix[start][i];
    }
    // 将se数组中start对应的value设置为0 表示加入了集合U(此时是0x3f3f3f3f
    se[start].value = 0;
    int index;
    // 开始循环 每次循环就加入一个结点到集合U
    for(int i = 0;i < n - 1;i++){ // 因为已经有一个结点加入集合U了 所以一共是n-1个结点
        // 首先根据se数组 找到权值最小的结点
        index = selectMinWeight(n);
        // 找到后先输出
        printUInfo(index);
        // 将结点加入到集合U
        se[index].value = 0;
        // 修改se数组
        // 遍历matrix数组 在index结点所在的行找到比当前se小的数据进行替换
        for(int j = 0;j < n;j++){
            if (matrix[index][j] < se[j].value){
                se[j].value = matrix[index][j];
                se[j].index = index;
            }
        }
    }
}

//int main(){
//    cout << "请输入顶点个数和边的个数 : ";
//    int n,e;
//    cin >> n >> e;
//    initMatrix(n);
//    int vi,vj,w;
//    for(int i = 0;i < e;i++){
//        cout << "请输入边依附的两个顶点的编号(范围0-" << n - 1 << ")和权值 : ";
//        cin >> vi >> vj >> w;
//        updateMatrix(vi,vj,w);
//    }
//    cout << "请输入Prim算法的起点 : ";
//    int start;
//    cin >> start;
//    prim(start,n);
//    return 0;
//}




