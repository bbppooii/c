#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
// �������㶨��
struct SListNode {
    PeoInfo data;         // �û�����
    struct SListNode* next; // ָ����һ������ָ��
};
// ��ʼ��ͨѶ¼
void InitContact(contact** con) {
    *con = NULL; // ��ʼ��Ϊ�ձ�
}
// ���ͨѶ¼����
void AddContact(contact** con) {
    contact* newNode = (contact*)malloc(sizeof(contact));
    if (!newNode) {
        printf("�ڴ����ʧ��\n");
        return;
    }
    printf("����������: ");
    scanf("%s", newNode->data.name);
    printf("�������Ա�: ");
    scanf("%s", newNode->data.sex);
    printf("����������: ");
    scanf("%d", &newNode->data.age);
    printf("������绰: ");
    scanf("%s", newNode->data.tel);
    printf("�������ַ: ");
    scanf("%s", newNode->data.addr);
    newNode->next = *con;  // ���½ڵ���뵽����ͷ��
    *con = newNode;
    printf("��ϵ����ӳɹ�!\n");
}
// ɾ��ͨѶ¼����
void DelContact(contact** con) {
    if (*con == NULL) {
        printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
        return;
    }
    char name[NAME_MAX];
    printf("������Ҫɾ��������: ");
    scanf("%s", name);
    contact* prev = NULL;
    contact* cur = *con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            if (prev == NULL) {
                *con = cur->next;  // ���ɾ������ͷ���
            }
            else {
                prev->next = cur->next;
            }
            free(cur);
            printf("��ϵ����ɾ��!\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("δ�ҵ�����ϵ��!\n");
}
// չʾͨѶ¼����
void ShowContact(contact** con) {
    if (*con == NULL) {
        printf("ͨѶ¼Ϊ��\n");
        return;
    }
    contact* cur = *con;
    while (cur != NULL) {
        printf("����: %s, �Ա�: %s, ����: %d, �绰: %s, ��ַ: %s\n",
            cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
        cur = cur->next;
    }
}
// ����ͨѶ¼����
void FindContact(contact* con) {
    if (con == NULL) {
        printf("ͨѶ¼Ϊ��\n");
        return;
    }
    char name[NAME_MAX];
    printf("������Ҫ���ҵ�����: ");
    scanf("%s", name);
    contact* cur = con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            printf("����: %s, �Ա�: %s, ����: %d, �绰: %s, ��ַ: %s\n",
                cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
            return;
        }
        cur = cur->next;
    }
    printf("δ�ҵ�����ϵ��!\n");
}
// �޸�ͨѶ¼����
void ModifyContact(contact** con) {
    if (*con == NULL) {
        printf("ͨѶ¼Ϊ��\n");
        return;
    }
    char name[NAME_MAX];
    printf("������Ҫ�޸ĵ�����: ");
    scanf("%s", name);
    contact* cur = *con;
    while (cur != NULL) {
        if (strcmp(cur->data.name, name) == 0) {
            printf("�������µ�����: ");
            scanf("%s", cur->data.name);
            printf("�������µ��Ա�: ");
            scanf("%s", cur->data.sex);
            printf("�������µ�����: ");
            scanf("%d", &cur->data.age);
            printf("�������µĵ绰: ");
            scanf("%s", cur->data.tel);
            printf("�������µĵ�ַ: ");
            scanf("%s", cur->data.addr);
            printf("��ϵ����Ϣ���޸�!\n");
            return;
        }
        cur = cur->next;
    }
    printf("δ�ҵ�����ϵ��!\n");
}
// ����ͨѶ¼����
void DestroyContact(contact** con) {
    contact* cur = *con;
    while (cur != NULL) {
        contact* next = cur->next;
        free(cur);
        cur = next;
    }
    *con = NULL;
    printf("ͨѶ¼�����!\n");
}
