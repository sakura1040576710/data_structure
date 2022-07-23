//
// Created by 十五哒哒哒 on 2022/7/11.
// 线索二叉树
//
#include <iostream>

using namespace std;

typedef struct node {
    char data;
    struct node *left, *right;
    int ltag = 0, rtag = 0;
} *Tree;

// 根据先序遍历的结果构建二叉树
Tree preCreateTree(Tree tree) {
    char ch;
    cin >> ch;
    if (ch == '#') return nullptr;
    tree = new struct node;
    tree->data = ch;
    tree->left = preCreateTree(tree->left);
    tree->right = preCreateTree(tree->right);
    return tree;
}

// 中序遍历构建线索二叉树
void inThreadTree(Tree &p) {
    static Tree pre = nullptr;
    if (p == nullptr) return;
    inThreadTree(p->left);
    if (p->left == nullptr) {
        p->ltag = 1;
        p->left = pre;
    }
    if (pre != nullptr && pre->right == nullptr) {
        pre->rtag = 1;
        pre->right = p;
    }
    pre = p;
    inThreadTree(p->right);
}

// 查找下一个结点
Tree getNextNode(Tree p) {
    if (p->rtag == 1) return p->right; // 右标志位为1 则表示右孩子结点存储的就是下一个结点的地址
    // 右标志位为0 则表示右孩子结点存储的就是右孩子 就需要找到右子树的最左下角的结点
    Tree q = p->right;
    while (q->ltag == 0) { // 左标志位为0 则表示左孩子节点存储的就是左孩子
        q = q->left;
    }
    return q;
}

// 通过构建的中序线索二叉树进行中序遍历输出
void getNodeByThreadTree(Tree tree) {
    if (tree == nullptr) return;
    Tree p = tree;
    // 找到中序遍历的第一个结点 第一个结点的ltag是1
    while (p->ltag == 0) {
        p = p->left;
    }
    cout << p->data;
    while (p->right != nullptr){ // 最后一个结点的右孩子指针为nullptr
        p = getNextNode(p); // 找下一个
        cout << p->data;
    }
}

//int main(){
//    Tree tree = nullptr;
//    cout << "输入先序遍历构建树 : " << endl;
//    tree = preCreateTree(tree);
//    cout << "---将树进行中序线索二叉树---" << endl;
//    inThreadTree(tree);
//    cout << "通过中序线索二叉树进行中序遍历 : " << endl;
//    getNodeByThreadTree(tree);
//    return 0;
//}