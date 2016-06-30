class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;//2147483647
        int max = INT_MIN; //-2147483648
        if(!prices.size()) {max = 0;}
        for (int i=0; i<prices.size(); i++) {
            if (min > prices[i]) { min = prices[i];}
            if (max < prices[i]-min) {max = prices[i]-min;}
        }
        return max;
    }
};