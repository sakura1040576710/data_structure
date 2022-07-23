//
// Created by 十五哒哒哒 on 2022/7/11.
// 非递归遍历
//
#include <iostream>
#include <stack>

using namespace std;

typedef struct node {
    char data;
    struct node *left, *right;
} *Tree;

typedef struct element {
    Tree ptr;
    int flag = 0;
} Flag;

// 先序遍历构建树
Tree createTreeByPre(Tree tree) {
    char ch;
    cin >> ch;
    if (ch == '#') return nullptr;
    tree = new struct node;
    tree->data = ch;
    tree->left = createTreeByPre(tree->left);
    tree->right = createTreeByPre(tree->right);
    return tree;
}

// 先序遍历打印树
void printTreeByPre(Tree tree) {
    stack<Tree> s;
    Tree p = tree;
    while (p != nullptr || !s.empty()) { // 同时满足才退出循环
        while (p != nullptr) { // 循环遍历左子树
            cout << p->data;
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) { // 出栈 遍历右子树
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

// 中序遍历打印树
void printTreeByIn(Tree tree) {
    stack<Tree> s;
    Tree p = tree;
    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            cout << p->data;
            p = p->right;
        }
    }
}

// 后序遍历打印树
void printTreeByPost(Tree tree) {
    stack<Flag> s; // 存储结点和访问次数
    Tree p = tree;
    Flag elem;
    while (p != nullptr || !s.empty()) {
        if (p != nullptr) {
            elem.ptr = p;
            elem.flag = 1; // 表示第一次入栈
            s.push(elem);
            p = p->left;
        } else {
            elem = s.top();
            s.pop();
            p = elem.ptr;
            if (elem.flag == 1) { // 等于1表示只访问了左子树
                elem.flag = 2;
                s.push(elem);
                p = p->right;
            } else {
                cout << p->data;
                p = nullptr; // 走到这里表示该结点被访问了2次了 要直接退回到该结点的父节点执行 也就是stack的栈顶结点
            }
        }
    }
}

//int main() {
//    cout << "请输入前序输入的树 : " << endl;
//    Tree tree = nullptr;
//    tree = createTreeByPre(tree);
//    cout << "前序遍历的结果 : " << endl;
//    printTreeByPre(tree);
//    cout << endl;
//    cout << "中序遍历的结果 : " << endl;
//    printTreeByIn(tree);
//    cout << endl;
//    cout << "后序遍历的结果 : " << endl;
//    printTreeByPost(tree);
//    return 0;
//}