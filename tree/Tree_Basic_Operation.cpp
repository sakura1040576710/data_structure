//
// Created by 十五哒哒哒 on 2022/7/10.
// 树的基本操作
//
#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
    char data;
    struct node *left, *right;
} *Tree;


// 求二叉树的深度
int getTreeDepth(Tree tree) {
    if (tree == nullptr) return 0;
    int m = getTreeDepth(tree->left);
    int n = getTreeDepth(tree->right);
    return m > n ? m + 1 : n + 1; // +1是因为要包括本身
}

// 求二叉树中叶子结点个数
int getLeafNode(Tree tree) {
    if (tree == nullptr) return 0;
    if (tree->left == nullptr && tree->right == nullptr) return 1;
    int m = getLeafNode(tree->left);
    int n = getLeafNode(tree->right);
    return m + n;
}

// 将一棵以二叉链表存储的二叉树按照顺序方式存储到一维数组中
// 参考层序遍历的思路
struct node treeArr[101];

int inArray(Tree tree) {
    if (tree == nullptr) return 0;
    int num = 0;
    queue<struct node> q; // struct node类型存储的是数据 *struct node类型存储的是地址
    q.push(*tree);
    while (!q.empty()) {
        struct node tmp = q.front();
        q.pop();
        treeArr[num++] = tmp;
        if (tmp.left != nullptr) q.push(*tmp.left); // tmp.left中存的是地址
        if (tmp.right != nullptr) q.push(*tmp.right);
    }
    return num;
}

// 以二叉链表为存储结构 在二叉树中删除以值x为根结点的子树
void destroyTree(Tree tree) {
    if (tree != nullptr) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        free(tree);
    }
}

void findNode(Tree tree, int x) {
    if (tree == nullptr) return;
    if (tree->data == x) {
        destroyTree(tree);
        return;
    }
    findNode(tree->left, x);
    findNode(tree->right, x);
}

// 复制一棵二叉树
Tree copyTree(Tree tree, Tree c) {
    if (tree == nullptr){
        return nullptr;
    }
    c = new struct node;
    c->data = tree->data;
    c->left = copyTree(tree->left, c->left);
    c->right = copyTree(tree->right, c->right);
    return c;
}

// 判断一棵树是否为完全二叉树
bool  isCompleteTree(Tree tree){
    if (tree == nullptr) return false;
    queue<Tree> q;
    q.push(tree);
    while(!q.empty()){
        Tree tmp = q.front();
        q.pop();
        if (tmp != nullptr){
            if (tmp->left == nullptr && tmp->right != nullptr) return false; // 当左子树为空 && 右子树不为空的时候 不是完全二叉树
            q.push(tmp->left);
            q.push(tmp->right);
        }else{
            break; // 当存在nullptr时 退出
        }
    }
    while(!q.empty()){
        Tree tmp = q.front();
        q.pop();
        if (tmp != nullptr) return false; // 如果pop出的结点为nullptr 但现在队列里又存在不为nullptr的结点 则不是完全二叉树
    }
    return true;
}

// 根据前序遍历创建树
Tree createByPre(Tree tree){
    char ch;
    cin >> ch;
    if (ch == '#') return nullptr;
    else{
        tree = new struct node;
        tree->data = ch;
        tree->left = createByPre(tree->left);
        tree->right = createByPre(tree->right);
    }
    return tree;
}

// 前序遍历输出树
void prePrint(Tree tree){
    if (tree == nullptr) return ;
    cout << tree->data;
    prePrint(tree->left);
    prePrint(tree->right);
}

// 中序遍历输出树
void inPrint(Tree tree){
    if (tree == nullptr) return ;
    inPrint(tree->left);
    cout << tree->data;
    inPrint(tree->right);
}

void postPrint(Tree tree){
    if (tree == nullptr) return ;
    postPrint(tree->left);
    postPrint(tree->right);
    cout << tree->data;
}

//int main(){
//    Tree tree = nullptr;
//    cout << "现在开始创建树 : " << endl;
//    tree = createByPre(tree);
//    cout << "前序遍历的结果 : " << endl;
//    prePrint(tree);
//    cout << endl;
//    cout << "中序遍历的结果 : " << endl;
//    inPrint(tree);
//    cout << endl;
//    cout << "后序遍历的结果 : " << endl;
//    postPrint(tree);
//    cout << endl;
//    cout << "该二叉树的深度为 : " << getTreeDepth(tree) << endl;
//    cout << "该二叉树叶子节点的个数为 : " << getLeafNode(tree) << endl;
//    cout << "该二叉树存储到一维数组的结果为 : " << endl;
//    int num = inArray(tree);
//    for (int i = 0; i < num; ++i) {
//        cout << "index : " << i << "   ->  value : " << treeArr[i].data << endl;
//    }
//    bool result = isCompleteTree(tree);
//    cout << "该树是否为完全二叉树 : " << result;
//    Tree copy = nullptr;
//    copy = copyTree(tree, copy);
//    cout << "复制完后的树的前序遍历是 : "<< endl;
//    prePrint(tree);
//    return 0;
//}