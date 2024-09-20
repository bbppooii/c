#define _CRT_SECURE_NO_WARNINGS 1
int removeElement(int* nums, int numsSize, int val) {
    int a = 0, b = 0;
    while (b < numsSize) {
        if (nums[b] == val) {
            b++;
        }
        else {
            nums[a++] = nums[b++];
        }
    }
    return a;
}