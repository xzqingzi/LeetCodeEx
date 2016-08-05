class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int minres, maxres, result;
        minres = maxres = result = nums[0];
        for (int i =1; i<nums.size(); i++) {
            int temp = minres;
            minres = min(min(minres*nums[i], maxres*nums[i]), nums[i]);
            maxres = max(max(temp*nums[i], maxres*nums[i]), nums[i]);
            result = max(result, maxres);
        }
       return result; 
    }
};