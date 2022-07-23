//
// Created by 十五哒哒哒 on 2022/4/26.
//

#include<iostream>
#include<string>

using namespace std;


typedef struct student {
    int id;
    char name[10];
} Student;

typedef struct node {
    struct student data;
    struct node *next;
} Node, *Link;

void showMenu() {
    cout << "------------欢迎来到学生管理系统------------\n";
    cout << "----------------1.新增学生----------------\n";
    cout << "----------------2.查询学生----------------\n";
    cout << "----------------3.删除学生----------------\n";
    cout << "----------------4.修改学生----------------\n";
    cout << "--------------5.打印全部学生---------------\n";
    cout << "----------------6.清空学生----------------\n";
    cout << "请选择(1-6):";
}

Student createStudent() {
    Student s;
    cout << "请输入学号:";
    cin >> s.id;
    cout << "请输入姓名:";
    cin >> s.name;
    return s;
}

int inputId() {
    int id;
    cout << "请输入要查询的学生的学号:";
    cin >> id;
    return id;
}

int updateId() {
    int id;
    cout << "请输入要修改的学生的学号:";
    cin >> id;
    return id;
}

int deleteId() {
    int id;
    cout << "请输入要删除的学生的学号:";
    cin >> id;
    return id;
}

char *inputName() {
    char name[10];
    memset(name, 0, sizeof(name));
    cout << "请输入要修改的学生的姓名:";
    cin >> name;
    return name;
}

// 插入学生 并保证学号递增
bool insertStudent(Link head, Student st) {
    Link node;
    Link p = head->next;
    Link q = head;
    while (p != nullptr) {
        if (p->data.id > st.id) {
            node = (Link) malloc(sizeof(Node));
            node->data.id = st.id;
            for (int i = 0; i < strlen(st.name); ++i) {
                node->data.name[i] = st.name[i];
            }
            node->next = p;
            q->next = node;
            return true;
        }
        q = p;
        p = p->next;
    }
    // 到了末尾
    node = (Link) malloc(sizeof(Node));
    node->data.id = st.id;
    for (int i = 0; i < strlen(st.name); ++i) {
        node->data.name[i] = st.name[i];
    }
    q->next = node; // p这个时候是null q是最后一个元素
    node->next = nullptr;
    return true;
}

void selectStudent(int s_id, Link head) {
    Student s;
    Link p = head->next;
    while (p != nullptr) {
        if (p->data.id == s_id) {
            cout << "学生的学号为:" << p->data.id << ",姓名为:" << p->data.name << endl;
            return;
        }
        p = p->next;
    }
    cout << "未找到该学生！";
}

bool deleteStudent(int s_id, Link head) {
    Link p = head->next;
    Link q = head;
    while (p != nullptr) {
        if (p->data.id == s_id) {
            q->next = p->next;
            free(p);
            return true;
        }
        p = p->next;
    }
    return false;
}

// 修改学生 不允许修改学号
bool updateStudent(char s_name[10], int s_id, Link head) {
    Link p = head->next;
    while (p != nullptr) {
        if (p->data.id == s_id) {
            for (int i = 0; i < strlen(s_name); ++i) {
                p->data.name[i] = s_name[i];
            }
            return true;
        }
        p = p->next;
    }
    return false;
}

void printAllStudent(Link head) {
    Link p = head->next;
    while (p != nullptr) {
        cout << "学生的学号为:" << p->data.id << ",姓名为:" << p->data.name << endl;
        p = p->next;
    }
}

bool clearAllStudent(Link head) {
    Link p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        free(p);
    }
    return true;
}

//int main() {
//    // 创建头结点
//    Link head = (Link) malloc(sizeof(Node));
//    head->next = nullptr;
//
//    int choose;
//    while (true) {
//        showMenu();
//        cin >> choose;
//        switch (choose) {
//            case 1:
//                insertStudent(head, createStudent());
//                break;
//            case 2:
//                selectStudent(inputId(), head);
//                break;
//            case 3:
//                deleteStudent(deleteId(), head);
//                break;
//            case 4:
//                updateStudent(inputName(), updateId(), head);
//                break;
//            case 5:
//                printAllStudent(head);
//                break;
//            case 6:
//                clearAllStudent(head);
//                return 0;
//            default:
//                cout << "请输入正确的数字！";
//                break;
//        }
//        system("pause");
//        system("cls");
//    }
//}
