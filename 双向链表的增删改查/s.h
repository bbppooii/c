#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int LTDataType;
typedef struct ListNode {
    LTDataType data;
    struct ListNode* prev;
    struct ListNode* next;
} LTNode;
//void LTInit(LTNode** pphead);
// ��ʼ��˫����������ͷ���ָ��
LTNode* LTInit();
// ����˫�������ͷ����нڵ�
void LTDestroy(LTNode* phead);
// ��ӡ˫������
void LTPrint(LTNode* phead);
// �ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);
// β��
void LTPushBack(LTNode* phead, LTDataType x);
// βɾ
void LTPopBack(LTNode* phead);
// ͷ��
void LTPushFront(LTNode* phead, LTDataType x);
// ͷɾ
void LTPopFront(LTNode* phead);
//��posλ��֮���������
void LTInsert(LTNode* pos, LTDataType x);
// ɾ�� pos λ�õĽڵ�
void LTErase(LTNode* pos);
// �������� x�����ض�Ӧ�ڵ��ָ��
LTNode* LTFind(LTNode* phead, LTDataType x);