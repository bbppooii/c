#define _CRT_SECURE_NO_WARNINGS 1
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    // ��ֹk�������鳤��
    k = k % numsSize;

    // ��ת��������
    reverse(nums, 0, numsSize - 1);

    // ��תǰk��Ԫ��
    reverse(nums, 0, k - 1);

    // ��תʣ�µĲ���
    reverse(nums, k, numsSize - 1);
}
