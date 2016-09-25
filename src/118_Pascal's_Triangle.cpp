class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i=0; i<numRows; i++) {
            vector<int> list(i+1, 1);
            for (int j=1; j<i; j++) {
                list[j] = result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(list);
        }
        return result;
    }
};