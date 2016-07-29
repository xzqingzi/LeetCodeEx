class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int min = 0, max = n-1, i, j, num = 1;
        while(num<=n*n) {
            i = min;
            j = min;
            if (min == max) {
                result[i][j] = num;
                break;
            }
            while(j<max) {
                result[i][j++] = num++;
            }
            while(i<max) {
                result[i++][j] = num++;
            }
            while(j>min) {
                result[i][j--] = num++;
            }
            while(i>min) {
                result[i--][j] = num++;
            }
            min++;
            max--;
        }
        return result;

    }