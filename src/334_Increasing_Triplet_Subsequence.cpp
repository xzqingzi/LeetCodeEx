class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int min = nums[0], mid = INT_MAX;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] <= min) min = nums[i];
            else if (nums[i] <= mid) mid = nums[i];
            else return 1;
        }
        return 0;
    }
};