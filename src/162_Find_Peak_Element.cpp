class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1 || nums[0]>nums[1]) return 0;
        int i=1;
        while(i<nums.size()) {
            if (nums[i-1] > nums[i]) return i-1;
            i++;
        }
        return i-1;
        
        
    }
};

//Binary search, faster
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size()-1, mid, mid2;
        while(begin<end) {
            mid = (begin+end)/2;
            mid2 = mid+1;
            if (nums[mid]>nums[mid2]) {
                end = mid;
            }
            else {
                begin = mid2;
            }
            
        }
        return begin;
    }
};