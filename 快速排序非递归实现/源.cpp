#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// ��ʼ��ջ
void STInit(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    ps->a = NULL;  // ��ʼ��ջ��ָ��Ϊ��
    ps->top = 0;  // ջ��������ʼ��Ϊ0
    ps->capacity = 0;  // ��ʼ����Ϊ0
}
// ��ջ
void STPush(Stack* ps, STDataType data) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    // ���ջ���ˣ�������
    if (ps->top == ps->capacity) {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;  // ��ʼ������Ϊ4��֮����������
        STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));  // ���·����ڴ�
        if (tmp == NULL) {
            perror("realloc fail");  // �ڴ����ʧ�ܣ���ӡ������Ϣ
        }
        ps->a = tmp;  // ����ջ��ָ��
        ps->capacity = newcapacity;  // ����ջ����
    }
    ps->a[ps->top] = data;  // ������ѹ��ջ��
    ps->top++;  // ջ��ָ���1
}
// ��ջ
void STPop(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    assert(!STEmpty(ps));  // ȷ��ջ��Ϊ��
    ps->top--;  // ջ��ָ���1
}
// ��ȡջ��Ԫ��
STDataType STTop(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    assert(!STEmpty(ps));  // ȷ��ջ��Ϊ��
    return ps->a[ps->top - 1];  // ����ջ��Ԫ��
}
// ��ȡջ����ЧԪ�ظ���
int STSize(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    return ps->top;  // ����ջ��ָ�룬��ջ����ЧԪ�ظ���
}
// ���ջ�Ƿ�Ϊ��
// ���Ϊ�շ��ط������������Ϊ�շ���0
bool STEmpty(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    return ps->top == 0;  // ջΪ��ʱ����1�����򷵻�0
}
// ����ջ
void STDestroy(Stack* ps) {
    assert(ps);  // ȷ��ջָ�벻Ϊ��
    free(ps->a);  // �ͷ�ջ��ָ����ڴ�
    ps->capacity = ps->top = 0;  // ����ջ������ջ��ָ��
}
// ������������
void Swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// ��ӡ����
void _printf(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);  // ��ӡ����Ԫ��
    }
}
// �ǵݹ��������
void QuickSortNonR(int* a, int left, int right) {
    ST st;
    STInit(&st);  // ��ʼ��ջ
    STPush(&st, right);  // ���ұ߽���ջ
    STPush(&st, left);  // ����߽���ջ
    // ѭ��ջ�е������������
    while (!STEmpty(&st)) {
        int begin = STTop(&st);  // ��ȡ��ǰ�������߽�
        STPop(&st);  // ������߽�
        int end = STTop(&st);  // ��ȡ��ǰ������ұ߽�
        STPop(&st);  // �����ұ߽�
        int keyi = begin;  // ѡ���׼Ԫ�صĳ�ʼλ��
        int cur = begin + 1;  // ��ǰԪ��ָ��
        int prev = begin;  // ��һ��С�ڻ�׼Ԫ�ص�λ��
        // �������ڵ�Ԫ�ؽ�������
        while (cur <= end) {
            if (a[cur] < a[keyi] && ++prev != cur)  // �����ǰԪ��С�ڻ�׼Ԫ�أ��򽻻�
                Swap(&a[prev], &a[cur]);
            ++cur;
        }
        // ����׼Ԫ�طŵ���ȷ��λ��
        Swap(&a[keyi], &a[prev]);
        keyi = prev;  // ���»�׼Ԫ��λ��
        // �����׼Ԫ���ұ߻���Ԫ�أ����������ұ�����
        if (keyi + 1 < end) {
            STPush(&st, end);
            STPush(&st, keyi + 1);
        }
        // �����׼Ԫ����߻���Ԫ�أ����������������
        if (keyi - 1 > begin) {
            STPush(&st, keyi - 1);
            STPush(&st, begin);
        }
    }
    STDestroy(&st);  // ����ջ
}
