class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        double n = matrix.size();
        for (int i=0; i<ceil(n/2); i++) {
            for (int j=0; j<floor(n/2); j++) {
                swap(matrix[i][j], matrix[j][n-i-1]);
                swap(matrix[i][j], matrix[n-i-1][n-j-1]);
                swap(matrix[i][j], matrix[n-j-1][i]);
            }
        }
        return;
    }
};