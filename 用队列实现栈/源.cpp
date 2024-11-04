#define _CRT_SECURE_NO_WARNINGS 1
typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* q) {
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* Newnode = (QNode*)malloc(sizeof(QNode));
	if (Newnode == NULL) {
		perror("malloc fail");
		return;
	}
	Newnode->val = data;
	Newnode->next = NULL;
	if (q->ptail) {
		q->ptail->next = Newnode;
		q->ptail = Newnode;
	}
	else {
		q->phead = q->ptail = Newnode;
	}
	q->size++;
}
// ��ͷ������ 
void QueuePop(Queue* q) {
	assert(q);
	assert(q->phead != NULL); // ����Ϊ�����ܳ���
	QNode* next = q->phead->next;
	free(q->phead);          // �ͷ�ͷ�ڵ�
	q->phead = next;         // ���¶�ͷ
	if (q->phead == NULL) {  // ����Ϊ��ʱ������βָ��
		q->ptail = NULL;
	}
	q->size--;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->phead != NULL);
	return q->phead->val;
}
// ��ȡ���ж�βԪ��		
QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->ptail != NULL);
	return q->ptail->val;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	if (q->size == 0) {
		return 1;
	}
	return 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q) {
	assert(q);
	QNode* cur = q->phead;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->ptail = q->phead = NULL;
	q->size = 0;
}



typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1)) {
		QueuePush(&obj->q1, x);
	}
	else {
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* pEmptyQ = &obj->q1;
	Queue* pNonEmptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1)) {
		pEmptyQ = &obj->q2;
		pNonEmptyQ = &obj->q1;
	}
	while (QueueSize(pNonEmptyQ) > 1) {
		int front = QueueFront(pNonEmptyQ);
		QueuePush(pEmptyQ, front);
		QueuePop(pNonEmptyQ);
	}
	int front = QueueFront(pNonEmptyQ);
	QueuePop(pNonEmptyQ);
	return front;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1)) {
		return QueueBack(&obj->q1);
	}
	else {
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}