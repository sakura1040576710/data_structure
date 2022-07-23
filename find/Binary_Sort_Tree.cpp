//
// Created by 十五哒哒哒 on 2022/7/18.
// 二叉排序树
//
#include <iostream>
#include <stack>

using namespace std;

typedef struct node {
    int val;
    struct node *left, *right;
} *Tree;


// 构建二叉排序树
void createBinarySortTree(Tree &t, int val) {
    if (t == nullptr) {
        t = new struct node;
        t->val = val;
        t->left = nullptr;
        t->right = nullptr;
    } else {
        if (val < t->val) createBinarySortTree(t->left, val);
        else createBinarySortTree(t->right, val);
    }
}

// 查找值
Tree searchVal(Tree t, int val) {
    if (t == nullptr) return nullptr;
    if (t->val == val) return t;
    if (t->val < val) return searchVal(t->right, val);
    else return searchVal(t->left, val);
}

// 非递归的中序遍历
void inPrintBinarySortTree(Tree t) {
    if (t == nullptr) return;
    stack<Tree> s;
    Tree tmp = t;
    while (tmp != nullptr || !s.empty()) {
        while (tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->left;
        }
        if (!s.empty()) {
            tmp = s.top();
            s.pop();
            cout << tmp->val << " -> ";
            tmp = tmp->right;
        }
    }
    cout << endl;
}

// 删除指定结点
void deleteNode(Tree &t) {
    Tree p;
    if (t->left == nullptr && t->right == nullptr) {
        p = t;
        t = nullptr;
        delete p;
    } else if (t->left == nullptr) {
        p = t;
        t = t->right; // 因为t是引用类型的 这里t的值发生了变化 会影响上面几层的t的值
        delete p;
    } else if (t->right == nullptr) {
        p = t;
        t = t->left;
        delete p;
    } else { // t的左右孩子都不为null
        Tree parent;
        parent = t;
        // 找到t左孩子里面最大的值
        Tree pre = parent->left;
        while (pre->right != nullptr) {
            parent = pre;
            pre = pre->right;
        }
        t->val = pre->val; // 将左孩子里最大值的放到根结点
        if (parent != t) {
            parent->right = pre->left; // 将要删除结点的左孩子赋给要删除结点的双亲结点的右孩子
        } else { // 等于t的话说明 t的左孩子中最大的就是t->left 也就是说t->left没有右孩子
            parent->left = pre->left;
        }
        delete pre;
    }
}

// 删除指定值
bool deleteBinarySortTree(Tree &t, int key) {
    if (t == nullptr) return false;
    if (t->val == key) deleteNode(t);
    else if (t->val < key) deleteBinarySortTree(t->right, key);
    else if (t->val > key) deleteBinarySortTree(t->left, key);
    return false;
}

//int main() {
//    Tree t = nullptr;
//    cout << "请输入结点的个数 : ";
//    int n;
//    cin >> n;
//    int val;
//    // 测试数据 : 38 12 34 56 13 6 98 40 3 17 78
//    for (int i = 0; i < n; i++) {
//        cout << "请输入结点的值 : ";
//        cin >> val;
//        createBinarySortTree(t, val);
//    }
//    inPrintBinarySortTree(t);
////    cout << searchVal(t, 10)->val << endl;
//    deleteBinarySortTree(t,40); // 删除叶子结点
//    inPrintBinarySortTree(t);
//    deleteBinarySortTree(t,34); // 删除只有左子树的结点
//    inPrintBinarySortTree(t);
//    deleteBinarySortTree(t,13); // 删除只有右子树的结点
//    inPrintBinarySortTree(t);
//    deleteBinarySortTree(t,38); // 删除有左右子树的结点
//    inPrintBinarySortTree(t);
//    return 0;
//}

