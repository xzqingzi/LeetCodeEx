class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        int minpath = INT_MAX;
        for (int i=1; i<triangle.size(); i++) {
            for (int j=0; j<=i; j++) {
                if (j == 0 ) triangle[i][j] += triangle[i-1][0];
                else if  (j == i ) triangle[i][j] += triangle[i-1][i-1];
                else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
                if (i == triangle.size()-1) {
                    minpath = min(minpath, triangle[i][j]);
                }
            }
        }
        return minpath;
    }
};