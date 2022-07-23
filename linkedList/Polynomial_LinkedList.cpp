//
// Created by 十五哒哒哒 on 2022/5/8.
// 多项式加法——链表实现
//
#include <iostream>

using namespace std;

typedef struct node {
    int co; // 系数
    int index; // 指数
    struct node *next;
} Node, *Link;

// 打印链表
void print(Link head) {
    if (head->next == nullptr) {
        return;
    }
    Link p = head->next;
    // 先处理最高项
    if (p->co < 0) {
        cout << "-";
    }
    if (abs(p->co) != 1){
        cout << abs(p->co);
    }
    cout << "x";
    if (p->index != 1){
        cout << "^" << p->index;
    }
    p=p->next;
    // 处理其他项
    while (p != nullptr) {
        if (p->co == 0) continue;
        else if (p->co > 0) {
            cout << "+";
        } else if (p->co < 0) {
            cout << "-";
        }
        if (p->index == 0) { // 当前p指向指数为0的
            cout << abs(p->co) << endl;
            break;
        }
        if (abs(p->co) != 1) { // 系数的绝对值不等于1时 输出
            cout << abs(p->co);
        }
        cout << "x";
        if (p->index != 1) { // 指数不为1时
            cout << "^" << p->index;
        }
        p = p->next;
    }
    cout << endl;
}

// 构建/插入链表
void createList(Link head, Link num) {
    if (head->next == nullptr) {
        head->next = num;
        num->next = nullptr;
        return;
    }
    // 维护两个节点 一前一后的关系 以便插入
    Link p = head->next;
    Link q = head;
    // 构建链表 按指数从大到小排列
    while (p != nullptr) {
        if (num->index > p->index) { // 当要插入的节点的指数比p节点的指数大时 就该插在p前面q后面
            num->next = p;
            q->next = num;
            return;
        } else if (num->index == p->index) { // 当要插入的节点的指数和p节点的指数相等时 合并系数
            p->co += num->co;
            return;
        }
        q = p;
        p = p->next;
    }
    // 如果到末尾了 还未插入 则为最后一个节点
    q->next = num;
    num->next = nullptr;
}

// 释放函数
void destroy(Link head){

    // 维护p q一前一后的关系
    Link p = head->next;
    Link q = head;

    while(p != nullptr){
        q->next = p->next;
        free(p);
        p = q->next;
    }
    free(q);
}

//int main() {
//    Link head = (Link) malloc(sizeof(Node));
//    head->next = nullptr;
//    int a, b;
//    cout << "请输入第一个多项式的系数和指数，以(0 0)结束，指数的范围在0~101之间" << endl;
//    while (true) {
//        cin >> a >> b;
//        if (a == 0 && b == 0) {
//            break;
//        }
//        Link num = (Link) malloc(sizeof(Node));
//        num->next = nullptr;
//        num->co = a;
//        num->index = b;
//        createList(head, num);
//    }
//    cout << "第一个多项式为：";
//    print(head);
//    cout << "请输入第二个多项式的系数和指数，以(0 0)结束，指数的范围在0~101之间" << endl;
//    while (true) {
//        cin >> a >> b;
//        if (a == 0 && b == 0) {
//            break;
//        }
//        Link num = (Link) malloc(sizeof(Node));
//        num->next = nullptr;
//        num->co = a;
//        num->index = b;
//        createList(head, num);
//    }
//    cout << "合并后的多项式为：";
//    print(head);
//    destroy(head);
//    return 0;
//}

