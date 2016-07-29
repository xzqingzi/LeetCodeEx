//O(m+n) 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return 0;
        int row = 0;
        int col = matrix[0].size()-1;
        while (row<matrix.size() && col>=0) {
            if (target == matrix[row][col]) return 1;
            else if (target > matrix[row][col]) row++;
            else col--;
        }
        return 0;
    }
};

//Other solution: Can also go thrhough all the possible lines using binary search.