class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> list;
        helper(result, list, candidates, target, 0);
        return result;
    }
    
    void helper(vector<vector<int>>& result, vector<int>& list, vector<int>& C, int T, int begin) {
        if (T < 0 ) return;
        if (T == 0) result.push_back(list);
        for (int i=begin; i<C.size(); i++) {
            list.push_back(C[i]);
            helper(result, list, C, T-C[i], i);
            list.pop_back();
        }
    }
};