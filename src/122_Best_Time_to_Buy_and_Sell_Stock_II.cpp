class Solution { //Think it as sine wave, find the lowest and highest point, re-initialize when the wave decreases
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1) return 0;
        int min=prices[0], max=0, sum=0;
        for (int i=1; i<prices.size(); i++) {
            min = prices[i]< min? prices[i]:min;
            max = prices[i]-min>max? prices[i]-min:max;
            if (prices[i]<prices[i-1] || i== prices.size()-1) {
                 sum += max;
                 min=prices[i];
                 max=0;
             }
        }
        return sum;
    }
};

//Tricky Way
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1) return 0;
        int sum=0;
        for (int i=1; i<prices.size(); i++) {  //Assume buy and sell in the same day means doing nothing.
            if(prices[i]-prices[i-1]>=0) sum +=prices[i]-prices[i-1];
        }
        return sum;
    }
};


//Others solution
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    vector<int> dp(n,0);
    int minPrice = prices[0],res = 0;
    for (int i = 1;i < n;++i) {
        minPrice = min(minPrice,prices[i]);
        if (prices[i]-minPrice>=dp[i-1]) dp[i] = prices[i]-minPrice;
        else {
            minPrice = prices[i];
            res += dp[i-1];
        }
    }
    
    return res+dp[n-1];
}