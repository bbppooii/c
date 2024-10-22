#define _CRT_SECURE_NO_WARNINGS 1
#include "s.h"
// ��ʼ��˫����������ͷ���ָ��
LTNode* LTInit() {
    LTNode* head = (LTNode*)malloc(sizeof(LTNode));
    if (head == NULL) {
        perror("malloc failed");
        exit(-1);
    }
    head->next = head;
    head->prev = head;
    return head;
}

// ����˫�������ͷ����нڵ�
void LTDestroy(LTNode* phead) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
}

// ��ӡ˫������
void LTPrint(LTNode* phead) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// �ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead) {
    return phead->next == phead;
}

// β��
void LTPushBack(LTNode* phead, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    // ���뵽β��
    new_node->prev = phead->prev;
    new_node->next = phead;
    phead->prev->next = new_node;
    phead->prev = new_node;
}

// βɾ
void LTPopBack(LTNode* phead) {
    if (LTEmpty(phead)) return;
    LTNode* tail = phead->prev;
    tail->prev->next = phead;
    phead->prev = tail->prev;
    free(tail);
}

// ͷ��
void LTPushFront(LTNode* phead, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    // ���뵽ͷ��
    new_node->next = phead->next;
    new_node->prev = phead;
    phead->next->prev = new_node;
    phead->next = new_node;
}

// ͷɾ
void LTPopFront(LTNode* phead) {
    if (LTEmpty(phead)) return;

    LTNode* first = phead->next;
    phead->next = first->next;
    first->next->prev = phead;
    free(first);
}

// �� pos λ��֮���������
void LTInsert(LTNode* pos, LTDataType x) {
    LTNode* new_node = (LTNode*)malloc(sizeof(LTNode));
    new_node->data = x;

    new_node->next = pos->next;
    new_node->prev = pos;
    pos->next->prev = new_node;
    pos->next = new_node;
}

// ɾ�� pos λ�õĽڵ�
void LTErase(LTNode* pos) {
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
}

// �������� x�����ض�Ӧ�ڵ��ָ��
LTNode* LTFind(LTNode* phead, LTDataType x) {
    LTNode* cur = phead->next;
    while (cur != phead) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
