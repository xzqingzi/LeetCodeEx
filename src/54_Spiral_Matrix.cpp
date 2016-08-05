class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> list;
         if (matrix.size()==0 ||matrix[0].size()==0) return list;
         int rb = 0, cb = 0;
         int re = matrix.size()-1, ce = matrix[0].size()-1;
         while(rb<=re && cb<=ce) {
             if (rb==re && cb==ce) {
                 list.push_back(matrix[rb][cb]);
                 break;
             }
             for (int j = cb; j <= ce; j++) {
                 list.push_back(matrix[rb][j]);
             }
             rb++;
             for (int i = rb; i <= re; i++) {
                 list.push_back(matrix[i][ce]);
             }
             ce--;
             if (rb>re) break;
             for (int j = ce; j >= cb; j--) {
                 list.push_back(matrix[re][j]);
             }
             re--;
             if (cb>ce) break;
             for (int i = re; i>=rb; i--) {
                 list.push_back(matrix[i][cb]);
             }
             cb++;
         }
         return list;
        
    }
};