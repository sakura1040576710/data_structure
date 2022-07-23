//
// Created by ʮ�������� on 2022/4/26.
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
    cout << "------------��ӭ����ѧ������ϵͳ------------\n";
    cout << "----------------1.����ѧ��----------------\n";
    cout << "----------------2.��ѯѧ��----------------\n";
    cout << "----------------3.ɾ��ѧ��----------------\n";
    cout << "----------------4.�޸�ѧ��----------------\n";
    cout << "--------------5.��ӡȫ��ѧ��---------------\n";
    cout << "----------------6.���ѧ��----------------\n";
    cout << "��ѡ��(1-6):";
}

Student createStudent() {
    Student s;
    cout << "������ѧ��:";
    cin >> s.id;
    cout << "����������:";
    cin >> s.name;
    return s;
}

int inputId() {
    int id;
    cout << "������Ҫ��ѯ��ѧ����ѧ��:";
    cin >> id;
    return id;
}

int updateId() {
    int id;
    cout << "������Ҫ�޸ĵ�ѧ����ѧ��:";
    cin >> id;
    return id;
}

int deleteId() {
    int id;
    cout << "������Ҫɾ����ѧ����ѧ��:";
    cin >> id;
    return id;
}

char *inputName() {
    char name[10];
    memset(name, 0, sizeof(name));
    cout << "������Ҫ�޸ĵ�ѧ��������:";
    cin >> name;
    return name;
}

// ����ѧ�� ����֤ѧ�ŵ���
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
    // ����ĩβ
    node = (Link) malloc(sizeof(Node));
    node->data.id = st.id;
    for (int i = 0; i < strlen(st.name); ++i) {
        node->data.name[i] = st.name[i];
    }
    q->next = node; // p���ʱ����null q�����һ��Ԫ��
    node->next = nullptr;
    return true;
}

void selectStudent(int s_id, Link head) {
    Student s;
    Link p = head->next;
    while (p != nullptr) {
        if (p->data.id == s_id) {
            cout << "ѧ����ѧ��Ϊ:" << p->data.id << ",����Ϊ:" << p->data.name << endl;
            return;
        }
        p = p->next;
    }
    cout << "δ�ҵ���ѧ����";
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

// �޸�ѧ�� �������޸�ѧ��
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
        cout << "ѧ����ѧ��Ϊ:" << p->data.id << ",����Ϊ:" << p->data.name << endl;
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
//    // ����ͷ���
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
//                cout << "��������ȷ�����֣�";
//                break;
//        }
//        system("pause");
//        system("cls");
//    }
//}
