class Solution {   // Time limit exceeded
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size(),l= n-k%n, j = l;
         for(int i=0; i< n-1; i++) {
             swap(nums[i], nums[j++]);
             if ( j>n-1 ) { j = l; }
         }
    }
};

// This Q unfinished