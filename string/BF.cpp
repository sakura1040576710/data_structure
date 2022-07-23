//
// Created by 十五哒哒哒 on 2022/6/30.
// 模式匹配 - BF算法
//

#include <iostream>
#include <string>
using namespace std;

//int main(){
//    string s; // 主串
//    string t; // 模式
//    cin >> s;
//    cin >> t;
//    int s_l = s.length();
//    int t_l = t.length();
//    int i = 0,j = 0;
//    while(i <= s_l){
//        if (j == t_l) {// 返回主串中下标
//            cout << i - j << endl;
//            return 0;
//        }
//        if (s[i] == t[j]){
//            i++,j++;
//        }else{
//            i=i-j+1; // 当下标从0开始的时候 回溯为i-j+1
//            j=0;
//        }
//    }
//    cout << "-1" << endl;
//    return 0;
//}



