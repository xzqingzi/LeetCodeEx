class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end = nums.size()-1;
        int begin = 0;
        int i=0;
        while (i<=end) {
            if (nums[i] ==2) {
                swap(nums[i], nums[end]);
                end--;
                i--;
            }
            else if (nums[i]==0) {
                swap(nums[i], nums[begin]);
                begin++;
            }
            i++;
        }
        
    }
};