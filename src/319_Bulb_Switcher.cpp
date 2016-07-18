class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }

};
/*
1. start from off, toggle odd times make the bulb on, and even times off.
2. bulb n is toggled when i is equal to its factor
2. list all the factors of n, ONLY when n is the square of a integer, n has odd number factors.  
*/