class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int j = 1;
        for (int i=1; i<nums.size(); i++) {
            if (i<nums.size()-1 && nums[i-1]==nums[i] && nums[i]==nums[i+1]) continue;
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};

//Special Case: [0,0,0,0,0]


//Other's solution 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for (int n : nums) {
            if (i<2 ||n>nums[i-2]) nums[i++] = n;
        }
        return i;
    }
};