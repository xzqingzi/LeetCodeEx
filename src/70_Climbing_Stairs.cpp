class Solution {
public:
    int climbStairs(int n) {  //if using stack, time limit is exceeded. WHY?
        vector<int> step(n);
        step[0] = 1;
        step[1] = 2;
        for (int i=2; i<n; i++) {
            step[i] =  step[i-1] + step[i-2];
        }
        return step[n-1];
    }
};