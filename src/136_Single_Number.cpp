class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out=nums[0];  //initilized out can NOT be 0.
        for (int i =1; i<nums.size(); i++) {
            out ^= nums[i];  // XOR: AB'+A'B
        }
        return out;
    }
};