class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> list;
        helper(k, n, 1, result, list);
        return result;
    }
    void helper(int k, int n, int start, vector<vector<int>>& result, vector<int>& list) {
        if (k == 0 && n == 0) result.push_back(list);
        if (n < 0) return;
        if (k == 0) return;
        for (int i=start; i<10; i++) {
            list.push_back(i);
            helper(k-1, n-i, i+1, result, list);
            list.pop_back();
        }
        return;
    }
};