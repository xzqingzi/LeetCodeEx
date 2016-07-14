class Solution { //Dynamic programming 
public:
    int maxSubArray(vector<int>& nums) { 
        int temp=0, sum=nums[0];  
        // initialized sum can NOT be 0, if nums vecotr are all negative values,output should be the first value
        for (int i=0; i<nums.size(); i++) {
            temp = temp+nums[i]>nums[i]?temp+nums[i]:nums[i];
            sum = max(sum,temp);
        }
        return sum;
    }
};