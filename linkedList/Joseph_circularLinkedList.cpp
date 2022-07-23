//
// Created by 十五哒哒哒 on 2022/5/6.
// 循环链表——约瑟夫问题
//
#include<iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} *Link, Node;

//int main() {
//    int n, m; // n是猴子个数 m是报数
//    Link head = (Link) malloc(sizeof(Node)); // sizeof()的参数应该是整个结构体 malloc()的结果是一个地址 可以强转成Link类型
//    head->next = nullptr;
//    while (true) {
//        cin >> n >> m;
//        if (n == 0 || m == 0) { // 当n或m为0时 则退出
//            free(head); // 释放head
//            break;
//        }
//        // 尾插法构建链表
//        Link tail = head;
//        for (int i = 1; i <= n; i++) {
//            Link q = (Link) malloc(sizeof(Node));
//            q->data = i;
//            tail->next = q;
//            // 形成循环链表
//            q->next = head->next;
//            tail = q;
//        }
//        // 维持p、q一前一后的关系 方便删除
//        Link q = tail;
//        Link p = head->next;
//        int i = 1; // 计数
//        while (p != q) { // 当p和q不重叠的时候就进行循环
//            if (i == m) { // 报数等于m时 删除节点
//                q->next = p->next;
//                free(p);
//                // 将p移动到下一个有效的节点上
//                p = q->next;
//                // 重新报数
//                i = 1;
//            } else {
//                i++;
//                q = p;
//                p = p->next;
//            }
//        }
//        cout << p->data << endl;
//        free(p); // 清除该节点
//        head->next = nullptr; // 头结点的next赋为空
//    }
//    return 0;
//}

