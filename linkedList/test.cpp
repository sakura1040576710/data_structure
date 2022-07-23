#include<iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node, *Link;

Link createList(const int a[], int n) {
    // 创建头结点
    Link head = (Link) malloc(sizeof(Node));
    head->next = nullptr;
    Link rear = head;
    // 插入元素 尾插
    for (int i = 0; i < n; i++) {
        Link node = (Link) malloc(sizeof(Node));
        node->data = a[i];
        rear->next = node;
        rear = node;
    }
    rear->next = nullptr;
    return head;
}

void display(Link head) {
    if (head == nullptr){
        return ;
    }
    Link p = head->next;
    printf("List为：");
    while (p != nullptr) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void clearLink(Link head) {
    Link q;
    while (head != nullptr) {
        display(head); // 这个函数的调用不要在head=head->next后面，因为head=head->next可能使head为NULL，如果display()函数没有针对空链表判断的话，这里会报错
        q = head;
        head = head->next;
        free(q);
    }
}


//int main() {
//    int a[] = {1, 2, 3, 4, 5};
//    Link head = createList(a, 5);
//    clearLink(head);
//    return 0;
//}