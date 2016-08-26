class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2,-1);
        int low = BS(nums, target);
        int high = BS(nums, target+1);
        high = nums[high] == target? high: high-1; 
        //In case, the vector nums only contains target (Ex. [8,8,8], 8)
        //The output index of 9 is located at the rightmost of 8.
        if (nums[low] != target || nums[high] != target) return range;
        range[0] = low;
        range[1] = high;
        return range;

    }
    int BS(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<r) {
            int mid = (l+r)/2;
            if (nums[mid] < target) l = mid+1;
            else r = mid; //when nums[mid]>= target, r = mid, then the output index l==r is located at leftmost target number
        }
        return l;
    }
};