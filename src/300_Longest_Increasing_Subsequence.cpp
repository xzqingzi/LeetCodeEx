class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;
        for (int i=0; i<nums.size(); i++) {
            auto pos = lower_bound(list.begin(), list.end(), nums[i]);  //pos is a iterator 
            if (pos == list.end()) list.push_back(nums[i]);  //pos = list.end() means there is no value no less than num[i], list.end() represents NULL pointer
            else *pos = nums[i];  
        }
        return list.size();
    }
};

//DP, runtime O(n^2), Slow
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxlen = 1;
        vector<int> count(n, 1);
        for (int i=0; i<n; i++) {
            for (int j=i-1; j>=0; j--) {
                if (nums[i]>nums[j]) count[i] = max(count[i], count[j]+1);
                maxlen = max(maxlen, count[i]);
            }
        }
        return maxlen;
    }
};