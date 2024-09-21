#define _CRT_SECURE_NO_WARNINGS 1
#include"to.h"
//��ӡ
void SLTPrint(SLTNode* phead) {
	SLTNode* a = phead;
	while (a) {
		printf("%d->", a->data);
		a = a->next;
	}
	printf("NULL\n");
}
//����
SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
//ͷ������ɾ��/β������ɾ��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* New = SLTBuyNode(x);
	if (*pphead == NULL) {
		*pphead = New;
		return;
	}
	SLTNode *ttt = *pphead;
	while (ttt->next){
		ttt = ttt->next;
	}
	ttt->next = New;
}
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* New = SLTBuyNode(x);
	New->next = *pphead;
	*pphead = New;
}
void SLTPopBack(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* ttt = *pphead;
	SLTNode* prev = NULL;
	while (ttt->next) {
		prev = ttt;
		ttt = ttt->next;
	}
	prev->next = NULL;
	free(ttt);
	ttt = NULL;
}
void SLTPopFront(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//����
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* ttt = *pphead;
	while (ttt) {
		if (ttt->data == x) {
			return ttt;
		}
	}
	return NULL;
}
//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	assert(pos);
	if (*pphead == pos) {
		SLTPushFront(pphead,x);
		return;
	}
	SLTNode* New = SLTBuyNode(x);
	SLTNode* prev = *pphead;
	while (prev->next!=pos) {
		prev = prev->next;
	}
	prev->next = New;
	New->next = pos;
}
//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if (*pphead == pos) {
		SLTPopBack(pphead);
		return;
	}
	SLTNode* prev = *pphead;
	while (prev->next != pos) {
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* New = SLTBuyNode(x);
	New->next = pos->next;
	pos->next = New;
}
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos);
	SLTNode* q = pos->next;
	pos->next = pos->next->next;
	free(q);
	q = NULL;
}
//��������
void SListDesTroy(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);
	SLTNode* a = *pphead;
	while (a) {
		SLTNode* New = a->next;
		free(a);
		a = New;
	}
	*pphead = NULL;
}