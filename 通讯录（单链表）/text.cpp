#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void menu() {
	printf("*****************ͨѶ¼***************\n");
	printf("*******1.�����ϵ��  2.ɾ����ϵ��*****\n");//ctrl+d
	printf("*******3.�鿴ͨѶ¼  4.������ϵ��*****\n");//ctrl+d
	printf("*******5.�޸���ϵ��  0.  �� ��  ******\n");//ctrl+d
	printf("**************************************\n");
}
int main() {
    contact* con; // ����ͨѶ¼����ͷָ��
    InitContact(&con); // ��ʼ��ͨѶ¼
    menu();
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            AddContact(&con); // �����ϵ��
            break;
        case 2:
            DelContact(&con); // ɾ����ϵ��
            break;
        case 3:
            ShowContact(&con); // չʾͨѶ¼
            break;
        case 4:
            FindContact(&con); // ������ϵ��
            break;
        case 5:
            ModifyContact(&con); // �޸���ϵ��
            break;
        case 0:
            DestroyContact(&con); // �˳�ϵͳʱ���ͨѶ¼
            printf("�˳�ϵͳ\n");
            break;
        default:
            printf("��Ч��ѡ��\n");
        }
    } while (choice != 0);

    return 0;
}