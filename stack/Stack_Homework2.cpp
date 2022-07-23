//
// Created by 十五哒哒哒 on 2022/5/8.
// <表示退一格 @表示清除到行首 #表示结束
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<char> s){
    char arr[101];
    int count = 0;
    while(!s.empty()){
        arr[count++] = s.top();
        s.pop();
    }
    for (int i = count - 1; i >= 0 ; --i) {
        cout << arr[i];
    }
    cout << endl;
}

//int main(){
//    string s;
//    while(cin >> s){
//        stack<char> sta;
//        for (char i : s) {
//            if (i == '<'){
//                if (sta.empty()){
//                    cout << "栈为空";
//                    continue;
//                }
//                sta.pop();
//            }else if(i == '@'){
//                while(!sta.empty()){
//                    sta.pop();
//                }
//            }else if(i == '#'){
//                print(sta);
//                return 0;
//            }else{
//                sta.push(i);
//            }
//        }
//        print(sta);
//    }
//    return 0;
//}
