//
// Created by 十五哒哒哒 on 2022/5/22.
// 栈 —— 表达式求值
// 开头和结尾都有#符号
//

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int calc(int a, int b, char c) {
    switch (c) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        default:
            return 0;
            break;
    }
}

/**
 * 判断符号间的优先关系
 * @return int
 */
int judge(char c1, char c2) { // c1是栈顶 c2是输入
    int a1 = -3;
    int a2 = -3;

    if (c1 == '+' || c1 == '-') a1 = 3;
    else if (c1 == '*' || c1 == '/') a1 = 5;
    else if (c1 == '(') a1 = 1;
    else if (c1 == ')') a1 = 7;
    else if (c1 == '#') a1 = 0;

    if (c2 == '+' || c2 == '-') a2 = 2;
    else if (c2 == '*' || c2 == '/') a2 = 4;
    else if (c2 == '(') a2 = 6;
    else if (c2 == ')') a2 = 1;
    else if (c2 == '#') a2 = 0;

    if (a1 > a2) return 1;
    else if(a1 == a2) return 0;
    else if(a1 < a2) return -1;
}

//int main() {
//    stack<char> optr; // 存符号
//    stack<int> opnd; // 存数字
//    char str; // 因为这里是char字符 所以只能读入[0,9]的数
//    optr.push('#');
//    cin >> str;
//    char sign;
//    int a, b;
//    do {
//        if (str == ' '){
//            cin >> str;
//        }
//        if (str >= '0' && str <= '9') { // 是数字
//            opnd.push((int) str - 48); // ascii -> int
//            cin >> str;
//        } else { // 是运算符
//            switch (judge(optr.top(), str)) { // 第一个参数是栈顶 第二个参数是输入
//                case 1: // 栈顶元素优先级高
//                    sign = optr.top();
//                    optr.pop();
//                    b = opnd.top();
//                    opnd.pop();
//                    a = opnd.top();
//                    opnd.pop();
//                    opnd.push(calc(a, b, sign));
//                    break;
//                case -1: // 栈顶元素优先级低
//                    optr.push(str);
//                    cin >> str;
//                    break;
//                case 0: // 优先级相等
//                    if (str == ')') { // ()的情况 直接弹出栈顶元素
//                        optr.pop();
//                    }
//                    cin >> str;
//                    break;
//            }
//        }
//    } while ((str != '#') || (optr.top() != '#'));
//    cout << opnd.top() << endl;
//    return 0;
//}
