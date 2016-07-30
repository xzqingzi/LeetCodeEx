class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (!nums.size()) return result;
        int i = 0, left = nums[0];
        while (i<nums.size()) {
            while (i< nums.size()-1 && nums[i]+1 == nums[i+1]) i++;
            if (nums[i] == left) {
                result.push_back(to_string(left));
            }
            else {
                result.push_back(to_string(left)+"->"+to_string(nums[i]));
            }
            i++;
            cout<<i<<endl;
            if (i<nums.size()) left = nums[i];
        }
        return result;
    }
};