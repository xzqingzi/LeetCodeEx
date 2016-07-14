class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while(left<=right) {
            mid = (left+right)/2;
            if (nums[mid]>=nums[right]) { // Do NOT miss '=', otherwise cause runetime error
                left = mid+1; // Do not miss '+1', o.w. cause runtime error
            }
            else {
                right = mid;
            }
        }
        return nums[mid];
    }
};