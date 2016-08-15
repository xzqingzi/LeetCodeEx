class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        helper(result, list, nums, 0);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& list, vector<int>& nums, int start) {
        result.push_back(list);
        for (int i=start; i<nums.size(); i++) {
            list.push_back(nums[i]);
            helper(result, list, nums, i+1);
            list.pop_back();
        }
        return;
    }
};

//Connect ot Q77, similar approach