class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin=0, end=nums.size()-1,mid;
        while(begin<end) {
            mid=(begin+end)/2;
            if (target<nums[mid]) {
                end = mid-1;
            }
            else if (target>nums[mid]) {
                begin = mid+1;
            }
            else {
                return mid;
            }
        }
        if(nums[begin]<target) return begin+1;
        else return begin;
    }
};