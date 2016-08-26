class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int carry = 0, result = 0, min = 0;
        for (int i=0; i<gas.size(); i++) {
            carry += gas[i]-cost[i];
            if (carry < min) {
                min = carry;
                result = i+1;
            }
        }
        return carry >= 0? result : -1;
    }
};