#define _CRT_SECURE_NO_WARNINGS 1
int preorder(struct TreeNode* root, int x) {
    if (root == NULL) {
        return 1; // �սڵ�Ĭ�Ϸ��� 1����Ӱ�쵥ֵ�ж�
    }
    if (x != root->val) {
        return -1;
    }
    if (preorder(root->left, x) == -1 || preorder(root->right, x) == -1) {
        return -1;
    }
    return 1;
}
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int x = root->val;
    return preorder(root, x) == 1;
}