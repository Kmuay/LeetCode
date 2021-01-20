class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int result1 = nums[size-1] * nums[size-2] * nums[size-3];
        int result2 = nums[0] * nums[1] * nums[size-1];
        return result1 > result2 ? result1 : result2;
    }
};