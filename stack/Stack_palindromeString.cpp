//
// Created by 十五哒哒哒 on 2022/5/8.
// 判断回文串——栈
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//int main(){
//    string s;
//    while(cin >> s){
//        stack<char> stack;
//        int length = s.length();
//        for (int i = 0; i < length >> 1; ++i) {
//            stack.push(s[i]);
//        }
//        int n;
//        if (length % 2 == 0){
//            n = length / 2;
//        }else{
//            n = length / 2 + 1;
//        }
//        bool flag = true;
//        while (!stack.empty()){
//            if (stack.top() == s[n]){
//                n++;
//                stack.pop();
//            }else{
//                cout << "不是回文串！" << endl;
//                flag = false;
//                break;
//            }
//        }
//        if (flag){
//            cout << "是回文串！" <<endl;
//        }
//    }
//    return 0;
//}

