class Solution {
public:
    int numSquares(int n) {
        static vector<int> list({0}); //Why static here
        int k = 1;
        while(list.size()<=n) {  // can not use count k here?
            k = list.size();
            int minSquare = INT_MAX;
            for (int i=1; i*i<=k; i++) {
                minSquare = min(minSquare, list[k-i*i]+1);
            }
            list.push_back(minSquare);
        }
        return list[n];
    }
};