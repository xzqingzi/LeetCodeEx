class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix[0][0]>target || matrix[matrix.size()-1].back()<target ) return false;
        int begin = 0, end = matrix.size()-1, middle ;
        while(begin<end) {
            middle = (begin+end)/2;
            if (matrix[middle][0]>target) {
                end = middle-1;
            }
            else if (matrix[middle][0]<target) {
                begin = middle+1;
            }
            else return true;
        }
        int temp = 0;
        if(matrix[begin][0]>target) { temp = begin-1; }
        else { temp = begin; }
        
        begin = 0; end = matrix[temp].size()-1;
        while(begin<=end) {
            middle = (begin+end)/2;
            if (matrix[temp][middle]>target) {
                end = middle-1;
            }
            else if (matrix[temp][middle]<target) {
                begin = middle+1;
            }
            else return true;
        }
        return false;
    }
};