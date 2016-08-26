class Solution {
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, 0, 0) ;
    }
    bool helper(vector<int>& nums, int pos, int k) {
        if (k == nums.size()-1) return 1;
        pos = max(pos-1, nums[k]);
        if (pos == 0) return 0;
        return helper(nums, pos, k+1);
    }
};