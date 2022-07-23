//
// Created by 十五哒哒哒 on 2022/6/30.
// 模式匹配- KMP算法
// 暴力算法在不匹配的时候 都是将i++(子串对应的下标++) j=0(模式对应的下标) 这样回溯i和j指针并且没有利用失败的信息 是非常没有效率的
// KMP算法只回溯j 不回溯i
// 需要找到A子串(已经匹配了的子串)的后缀集合 和 B子串(已经匹配了的模式)的前缀集合 的交集里 最长的元素 -> 这个最长元素也就是j指针回溯的位置
//

#include <iostream>
#include <string>
using namespace std;


void genNext(string t,int next[1001]){
    int j = 0; // j表示前缀的末尾 从0开始
    int i = 1; // i表示后缀的末尾 从1开始
    next[0] = 0; // 因为第一个字符不存在前后缀 所以规定为0
    while(i < t.length()){
        if (t[i] == t[j]){
            next[i] = j + 1;
            i++,j++;
        }else{
            if (j == 0){
                next[i] = j;
                i++;
                continue;
            }else{
                j = next[j - 1];
            }
        }
    }
    // 错误写法： 因为要找的是相等的前后缀 不是对称的前后缀
//        int p = 0,q = i - 1; // p记录模式串的第一位 q记录模式串当前位次的前一位
//        while(true){
//            if (t[p] == t[q]){
//                p++,q--;
//            }else{
//                break;
//            }
//        }
//        next[i] = p;
//    }
}


//int main(){
//    string s; // 子串
//    string t; // 模式
//    cin >> s;
//    cin >> t;
//    int next[1001];
//    genNext(t,next);
//
//    int i = 0,j = 0; // i控制子串 j控制模式
//    while(i < s.length() && j < t.length()){
//        if (s[i] == t[j]) i++,j++;
//        else{
//            if (j == 0){
//                i++;
//                continue;
//            }
//            j = next[j - 1];
//        }
//    }
//    if (j >= t.length()) cout << i - t.length() << endl;
//    else cout << -1 << endl;
//    return 0;
//}
