#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyBTNode(int val) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL) {
		perror("malloc error");
	}
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	n5->left = n7;

	return n1;
}
// ����������
void BinaryTreeDestory(BTNode** root) {

}
// �������ڵ����
int BinaryTreeSize(BTNode* root) {
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (NULL == root) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k) + BinaryTreeLevelKSize(root->right, k);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == x) {
		return root;
	}
	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1) {
		return ret1;
	}
	BTNode* ret2 = BinaryTreeFind(root->left, x);
	if (ret2) {
		return ret2;
	}
	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	printf("%d", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	printf("%d", root->val);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%d", root->val);
}
// �������
void BinaryTreeLevelOrder(BTNode* root) {

}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {

}