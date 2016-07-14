class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mis= 0;
        for (int i=0; i< nums.size(); i++) { //from 0 to n 
            mis ^= nums[i];  //Using XOR
            mis ^= i+1;
        }
        return mis;
        
    }
};

//Similar as the signal number problem