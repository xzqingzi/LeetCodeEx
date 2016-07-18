class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m+n-2, b = min(m,n)-1;
        long output =1;
        for(int i= 0; i<b; i++) {
            output *= (a-i);
            output /= i+1; 
            // Multiply and divide at the same time may cause rounding error, we can do each step in two loops, 
            //but this may also cause overflow in the first multiply loop.  
        } 
        return output;
    }
};