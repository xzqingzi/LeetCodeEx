class Solution {
public:
    int integerBreak(int n) {
        int prod=1;
        if(n==2) return 1;
        if(n==3) return 2;
        while(n>3) {
            if (n%3==0) {
                n=n-3;
                prod *=3;
            }
            else {
                n=n-2;
                prod *=2;
            }
        }
        return prod*n;
    }
};