class Solution {
public: 
    void rotate(vector<int>& nums, int k) {  //Example 1234567
        if(k%nums.size())
        {
            reverse(nums.begin(),nums.end());  //7654321 
            reverse(nums.begin(),nums.begin()+k%nums.size()); //5674321
            reverse(nums.begin()+k%nums.size(),nums.end()); //5671234
        }
    }
};






//Wrong answer

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