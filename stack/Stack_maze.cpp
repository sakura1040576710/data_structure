//
// Created by 十五哒哒哒 on 2022/5/24.
// 栈 —— 迷宫问题
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct node{
    int x; // 表示x
    int y; // 表示y
    int di; // 表示方向
}Box;

typedef struct dire{
    int x;
    int y;
}Direct;

/**
 * 找到出口的函数
 * map[][]的值为0表示没有走过且可以走 -1表示走过 1表示没有路可以走
 * @param map 地图
 * @param direct 方向
 * @param s 栈
 * @return
 */
bool findPath(int map[102][102],Direct direct[4],stack<Box> &s,int n,int m){
    Box temp; // 存储弹出/需要压栈的临时变量
    int x,y,di; // 存储当前位置的x、y、di
    int line,col; // 存储下一个位置的x、y
    temp.x = 1,temp.y = 1,temp.di = -1;
    s.push(temp); // 这里压栈是为了方便控制循环 因为循环每次都要弹出一个栈
    map[1][1] = -1; // -1表示已经走过
    while(!s.empty()){
        temp = s.top();
        s.pop();
        x = temp.x,y = temp.y,di = temp.di + 1; // +1是因为到这里来有两种情况：
        // 第一个情况是第一次进入该循环 此时的temp.di赋的值是-1 为了从右边开始走 需要对temp.di+1
        // 第二个情况是下一个点的四个方向都遍历完了都没有找到可以走的路 就需要在当前这个点换个方向 所以需要进行+1
        while(di < 4){
            // 计算出下一个点的x y坐标
            line = x + direct[di].x;
            col = y + direct[di].y;
            if (map[line][col] == 0){ // 表示没有走过且有路可以走
                // 就把当前停留的这个点压栈 然后走向下一个点
                temp.x = x,temp.y = y,temp.di = di;
                s.push(temp);
                x = line,y = col;
                map[line][col] = -1; // 表示该点已经走过
                if (x == n && y == m){
                    return true; // 走到终点
                }
                else di = 0; // 没有到终点 就从右开始走
            }else{ // 找下一个方向
                di++;
            }
        }
    }
    return false;
}

Direct direct[4] = {{0,1},{1,0},{0,-1},{-1,0}}; // 存储四个方向上x和y的增量 默认从向右开始走（即x不变 y++）
int map[102][102]; // 存储地图
vector<Box> v;

//int main(){
//    stack<Box> s;
//    int n,m; // 行和列
//    cin >> n >> m;
//    for (int i = 0; i < n + 2; ++i) { // 地图的下标从1开始 周围要加两行墙壁
//        for (int j = 0; j < m + 2; ++j) {
//            cin >> map[i][j];
//        }
//    }
//    if (findPath(map,direct,s,n,m)){
//        cout << "true!" << endl;
//        while(!s.empty()){
//            v.push_back(s.top());
//            s.pop();
//        }
//        for (int i = v.size() - 1; i >= 0; --i) {
//            cout << "x : " << v[i].x << "   y : " << v[i].y << "   di : " << v[i].di << endl;
//        }
//    }else{
//        cout << "No Path!" << endl;
//    }
//    return 0;
//}

