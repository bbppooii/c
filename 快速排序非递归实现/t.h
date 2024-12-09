#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack,ST;
// ��ʼ��ջ 
void STInit(Stack* ps);
// ��ջ 
void STPush(Stack* ps, STDataType data);
// ��ջ 
void STPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType STTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int STSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool STEmpty(Stack* ps);
// ����ջ 
void STDestroy(Stack* ps);
//����
void Swap(int* p1, int* p2);
//��ӡ
void _printf(int* a, int n);
//����
void QuickSortNonR(int* a, int left, int right);