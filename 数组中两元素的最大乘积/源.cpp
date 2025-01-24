#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 1, nums.end(), greater<>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};