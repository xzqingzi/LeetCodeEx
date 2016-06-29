class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int out;
        if (nums.size()) { out = nums[0];}
        sort(nums.begin(),nums.end());
        
        int count = 0;
        for (int i=0; i<nums.size()-1; i++) {
            int temp = nums[i+1] - nums[i];
            if (temp == 0) { count++; }
            else { count = 0;}
            if (count >= nums.size()/2) {
                out = nums[i];
                break;
            }
        }
        return out;
    }
};