class Solution {  //O(2n) is also O(n) two loops one from beginning and the other from the end
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        for (int i=1; i<nums.size(); i++) {
            output[i] = output[i-1]*nums[i-1];
        }
        int temp=1;
        for (int i=nums.size()-2; i>=0; i--) {
            temp *= nums[i+1];
            output[i] = output[i]*temp;
        }
        return output;
    }
};