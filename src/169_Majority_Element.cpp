class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int out;
        if (nums.size()) { out = nums[0];}
        sort(nums.begin(),nums.end());
        
        int count = 0;
        for (int i=0; i<nums.size()-1; i++) {
            int temp = nums[i+1] - nums[i];
            if (temp == 0) { count++; }
            else { count = 0;}
            if (count >= nums.size()/2) {
                out = nums[i];
                break;
            }
        }
        return out;
    }
};


// Better solution
class Solution { // majorrity count > n/2, not equal 
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];
        for (int i = 1; i<nums.size(); i++) { 
            if (nums[i] == maj) {
                count++;
            }
            else if (count == 0) { // only the digit with more # than previous majority could make count = 0
                maj = nums[i];
                count++;
            }
            else { 
                count--;
            } 
        }
        return maj;
    }
};

// Other
class Solution {
public:
int majorityElement(vector<int>& nums) {
    int size=nums.size();
    nth_element(nums.begin(),nums.begin()+size/2,nums.end());
    return nums[size/2];
}
};