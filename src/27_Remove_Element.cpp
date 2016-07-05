class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 
        int j=0;
        for (int i=0; i<nums.size(); i++) {
            if(nums[i] != val) {
                nums[j] = nums[i];
                cout<<nums[j]<<endl;
                j++;
            }
            
        }
        return j;
    }
};


//Faster solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 
        int j=0, k=nums.size()-1;
        for (int i=0; i<nums.size(); i++) {
            if(nums[j] == val) {
                nums[j] = nums[k];  //The order of elements can be changed. 
                k--;
            }
            else {
                j++;
            }
            
        }
        return j; //return the new length 
    }
};