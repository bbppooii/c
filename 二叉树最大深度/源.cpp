#define _CRT_SECURE_NO_WARNINGS 1
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    // �ݹ���������������
    int leftDepth = maxDepth(root->left);
    // �ݹ���������������
    int rightDepth = maxDepth(root->right);
    // ���ؽϴ����ȣ�����1��������ǰ�ڵ㣩
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
