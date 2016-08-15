class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> list;
        helper(result, list , n, k, 1);
        return result;
    }
    
    void helper(vector<vector<int>>& result, vector<int>& list, int n, int k, int start) {
        if (k == 0) {
                result.push_back(list);
                return;
        }
        for (int i= start; i<=n; i++) {
            list.push_back(i);
            helper(result, list, n, k-1, i+1);
            list.pop_back();
        }
    }
};

//Connect to Q78, similar approach