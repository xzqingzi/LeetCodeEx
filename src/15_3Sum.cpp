class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int begin = i+1;
            int end = nums.size()-1;
            
            while (begin<end) {
                int sum = nums[begin] + nums[i] + nums[end];
                if (sum == 0) {
                    vector<int> temp(3);
                    temp[0] = nums[begin];
                    temp[1] = nums[i];
                    temp[2] = nums[end];
                    result.push_back(temp);
                    begin++;
                    end--;
                    while (nums[begin] == nums[begin-1]) begin++; //Important, jump the duplicate digit, here begin compare with begin-1
                    while (nums[end] == nums[end+1]) end--; // Important, here end compare with end+1
                }
                else if (sum >0) end--;
                else begin++;
            }
            
        }
        return result;
        
    }
};