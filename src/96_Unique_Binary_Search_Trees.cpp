class Solution {
public:
    int numTrees(int n) {  
        vector<int> list(n+1,0); //remember to initialize
        list[0] = 1;
        list[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                list[i] += list[j]*list[i-j-1];
            }
        }
        return list[n];
    }
};